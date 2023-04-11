#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置标题
    this->setWindowTitle("UDP协议大文件传输: 客户端");
    //加载界面样式
    SetStyle(":/blue.css");
    //初始化配置
    InitConfig();
}


Widget::~Widget()
{
    delete ui;
}

/*
工程: UDP_Server
日期: 2021-04-22
作者: Leventure
环境: win10 QT5.12.6 MinGW32
功能: 加载界面样式
*/
void Widget::SetStyle(const QString &qssFile)
{
    QFile file(qssFile);
    if (file.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(file.readAll());
        qApp->setStyleSheet(qss);
        QString PaletteColor = qss.mid(20,7);
        qApp->setPalette(QPalette(QColor(PaletteColor)));
        file.close();
    }
    else
    {
        qApp->setStyleSheet("");
    }
}


/*
工程: UDP_Server
日期: 2021-04-22
作者: Leventure
环境: win10 QT5.12.6 MinGW32
功能: 界面初始化配置
*/
void Widget::InitConfig()
{
    //获取当前程序的路径
    QString app_path=QCoreApplication::applicationDirPath();

    //设置自动生成的文件保存路径
    QString file_save_path=QString("%1/%2").arg(app_path).arg(FILE_SAVE_DIR);
    QDir dir_file(file_save_path);
    if(!dir_file.exists())
    {
        qDebug()<<"文件保存目录不存在.创建目录:"<<file_save_path;
        dir_file.mkdir(file_save_path);
    }
    ui->lineEdit_auto_create_file_path->setText(file_save_path);

    //显示当前时间
    connect(&current_timer, SIGNAL(timeout()), this, SLOT(current_timer_update()));
    current_timer.start(1000);

    //关联线程的日志显示信号
    connect(&udp_file_send_thread, SIGNAL(LogSend(QString)), this, SLOT(Log_Text_Display(QString)));
    connect(&udp_file_send_thread, SIGNAL(ss_FileSendState(qint64,qint64)), this, SLOT(slots_FileSendState(qint64,qint64)));
    connect(&udp_file_send_thread, SIGNAL(ss_SendComplete()), this, SLOT(slots_SendComplete()));

}


/*
工程: UDP_Server
日期: 2021-04-22
作者: Leventure
环境: win10 QT5.12.6 MinGW32
功能: 显示当前时间
*/
void Widget::current_timer_update()
{
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz ddd");
    ui->label_current_time->setText(current_date);
}

/*
工程: UDP_Server
日期: 2021-04-22
作者: Leventure
环境: win10 QT5.12.6 MinGW32
功能: 窗口关闭事件
*/
void Widget::closeEvent(QCloseEvent *event)
{
    udp_file_send_thread.exit_thread();
    udp_file_send_thread.quit();
    udp_file_send_thread.wait();
    current_timer.stop();
    event->accept(); //接受事件
}


/*
工程: UDP_Server
日期: 2021-04-22
作者: Leventure
环境: win10 QT5.12.6 MinGW32
功能: 日志显示
*/
void Widget::Log_Text_Display(QString text)
{
    QPlainTextEdit *plainTextEdit_log=ui->plainTextEdit_log;
    //设置光标到文本末尾
    plainTextEdit_log->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
//    //当文本数量超出一定范围就清除
//    if(plainTextEdit_log->toPlainText().size()>1024*4)
//    {
//        plainTextEdit_log->clear();
//    }
    plainTextEdit_log->insertPlainText(text);
    //移动滚动条到底部
    QScrollBar *scrollbar = plainTextEdit_log->verticalScrollBar();
    if(scrollbar)
    {
        scrollbar->setSliderPosition(scrollbar->maximum());
    }
}

void Widget::on_pushButton_save_log_clicked()
{
    ui->plainTextEdit_log->clear();
}

/*
工程: UDP_Client
日期: 2021-04-22
作者: Leventure
环境: win10 QT5.12.6 MinGW32
功能: 文件发送的状态更新
*/
void Widget::slots_FileSendState(qint64 byte,qint64 TotalBytes)
{
    ui->label_recv_byte->setText(QString::number(byte));
    ui->label_Total_Byte->setText(QString::number(TotalBytes));

    double t=(byte*1.0/TotalBytes)*100;

    QString t_str=QString::number(t,'f',1);

    //更新状态显示
    Log_Text_Display(QString("总大小:%1,已发送:%2,百分比:%3%\n").arg(TotalBytes).arg(byte).arg(t_str));
}

/*
工程: UDP_Client
日期: 2021-04-22
作者: Leventure
环境: win10 QT5.12.6 MinGW32
功能: 开始发送
*/
void Widget::on_pushButton_start_udp_clicked()
{
    udp_file_send_thread.exit_thread();
    udp_file_send_thread.quit();
    udp_file_send_thread.wait();

    if(ui->pushButton_start_udp->text()=="开始发送")
    {
        ui->pushButton_start_udp->setText("停止发送");

        udp_file_send_thread.set_ServerIP(ui->comboBox_ip_addr->currentText());
        udp_file_send_thread.set_ServerPort(ui->spinBox_port->value());

        QString s_file=ui->lineEdit_send_file_save_path->text();
        QFileInfo file(s_file);

        QString Src_File=s_file;

        bool create_flag=true;
        //如果文件不存在
        if(file.exists()==false)
        {
            int value=ui->spinBox_auto_create_file_size->value();

            QDateTime current_date_time =QDateTime::currentDateTime();
            QString current_date =current_date_time.toString("yyyy-MM-dd-hh-mm-ss");
            Src_File=(QString("%1/%2.txt").arg(ui->lineEdit_auto_create_file_path->text()).arg(current_date));

            wchar_t *pWideChar = new wchar_t[Src_File.size()+1];

            int actualLen =Src_File.toWCharArray(pWideChar);
            pWideChar[actualLen]='\0';

            //如果大于4G
            if(value>4*1024)
            {
                //自动创建文件
                create_flag=CreateTempFile(value/(4*1024),value%(4*1024),pWideChar);
            }
            else
            {
                //自动创建文件
                create_flag=CreateTempFile(0,value*1024*1024,pWideChar);
            }

            //释放内存
            delete  [] pWideChar;
        }

        if(create_flag)
        {
             Log_Text_Display(QString("创建的文件路径:%1\n").arg(Src_File));
             ui->lineEdit_recv_file_name->setText(Src_File);
             udp_file_send_thread.set_send_file(Src_File);
             udp_file_send_thread.start();
        }
    }
    else if(ui->pushButton_start_udp->text()=="停止发送")
    {
        udp_file_send_thread.exit_thread();
        udp_file_send_thread.quit();
        udp_file_send_thread.wait();
        ui->pushButton_start_udp->setText("开始发送");
    }
}


/*
工程: UDP_Client
日期: 2021-04-22
作者: Leventure
环境: win10 QT5.12.6 MinGW32
功能: 创建一个指定大小的空文件

// 创建的文件总大小 = dwHigh * 4G + dwLow
// 当总大小小于4G时，dwHigh可以设置为0，dwLow数字最大为4G - 1

*/
BOOL Widget::CreateTempFile(DWORD dwHigh, DWORD dwLow, TCHAR* pFileName)
{
    HANDLE hFile;
    HANDLE hMapFile;

    hFile = CreateFile(
        pFileName,
        GENERIC_WRITE | GENERIC_READ,
        FILE_SHARE_READ,
                nullptr,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        nullptr
        );
    if( hFile == INVALID_HANDLE_VALUE )
    {
        Log_Text_Display("文件创建失败1.\n");
        return FALSE;
    }

    hMapFile = CreateFileMapping(
        hFile,
        nullptr,
        PAGE_READWRITE,
        dwHigh,
        dwLow,
        nullptr
        );
    if( hMapFile == nullptr )
    {
        Log_Text_Display("文件创建失败2.\n");
        CloseHandle( hFile );
        return FALSE;
    }

    CloseHandle( hMapFile );
    CloseHandle( hFile );

    Log_Text_Display("随机文件创建成功.\n");
    return TRUE;
}


/*
工程: UDP_Client
日期: 2021-04-22
作者: Leventure
环境: win10 QT5.12.6 MinGW32
功能: 选择发送的文件
*/
void Widget::on_pushButton_select_rx_file_path_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,"选择打开的文件","C:/",tr("*.*"));
    //filename==选择文件的绝对路径
    if(!filename.isEmpty())
    {
        ui->lineEdit_send_file_save_path->setText(filename);
    }
}

/*
工程: UDP_Client
日期: 2021-04-23
作者: Leventure
环境: win10 QT5.12.6 MinGW32
功能: 发送完毕
*/
void Widget::slots_SendComplete()
{
    udp_file_send_thread.exit_thread();
    udp_file_send_thread.quit();
    udp_file_send_thread.wait();
    ui->pushButton_start_udp->setText("开始发送");

    QString s_file=ui->lineEdit_send_file_save_path->text();
    QFileInfo file(s_file);

    //如果文件不存在
    if(file.exists()==false)
    {
        //如果是随机文件就要删除
        QFile del_file(ui->lineEdit_recv_file_name->text());
        del_file.remove();
    }
}


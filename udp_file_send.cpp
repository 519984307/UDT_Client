#include "udp_file_send.h"

#ifndef WIN32
void* sendfile(void*);
#else
DWORD WINAPI sendfile(LPVOID);
DWORD WINAPI monitor(LPVOID s);
#endif

UDP_FILE_SEND_THREAD::UDP_FILE_SEND_THREAD()
{
    qDebug()<<"startup---->";
    UDT::startup();
}

UDP_FILE_SEND_THREAD::~UDP_FILE_SEND_THREAD()
{

}


void UDP_FILE_SEND_THREAD::run()
{
    FileInfoSendSuccess=0;
    Send_TotalBytes=0;
    File_TotalBytes=0;
    qint64 send_len=0;

    qint64 time1;
    qint64 time2;

    LogSend(QString("UDP文件发送线程开始运行.\n"));

    //判断文件是否存在
    QFileInfo file(send_file);
    if(file.exists()==false)
    {
        LogSend(QString("%1 文件不存在.停止发送.\n").arg(send_file));
      //  mSocket->close();
       // delete mSocket;
        return;
    }

    //打开文件
    QFile SrcFile(send_file);
    if(!SrcFile.open(QIODevice::ReadOnly))
    {
        LogSend(QString("%1 文件打开失败.停止发送.\n").arg(send_file));
        return;
    }

    //得到文件大小信息
    File_TotalBytes=SrcFile.size();

    //判断端口号
    if(server_port<=0)
    {
        LogSend("没有填写端口号.暂停发送.\n");
        return;
    }

    //判断IP地址
    if(server_ip_addr.isEmpty())
    {
        LogSend("没有填写IP地址.暂停发送.\n");
        return;
    }

    struct addrinfo hints, *local, *peer;

    memset(&hints, 0, sizeof(struct addrinfo));

    hints.ai_flags = AI_PASSIVE;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (0 != getaddrinfo(nullptr,"9000", &hints, &local))
    {
        LogSend("非法端口号或端口正忙.\n");
        return;
    }

   client = UDT::socket(local->ai_family, local->ai_socktype, local->ai_protocol);
#ifdef WIN32
   UDT::setsockopt(client, 0, UDT_MSS, new int(1052), sizeof(int));
#endif
   freeaddrinfo(local);

     if (0 != getaddrinfo(QString("%1").arg(server_ip_addr).toStdString().c_str(),QString("%1").arg(server_port).toStdString().c_str(), &hints, &peer))
     {
        qDebug() << "incorrect server/peer address. " <<server_ip_addr << ":" << server_port << endl;
        return;
     }

     // 连接到服务器，隐式绑定
     if (UDT::ERROR == UDT::connect(client, peer->ai_addr, peer->ai_addrlen))
     {
        LogSend("连接到服务器，隐式绑定. ERROR\n");
        //qDebug()<< "connect: " << UDT::getlasterror().getErrorMessage() << endl;
        return;
     }

     freeaddrinfo(peer);
     int ssize = 0;
     int ss;

     QString str;
     QFileInfo send_file_info(send_file);
     str=QString("image#%1#%2").arg(send_file_info.fileName()).arg(send_file_info.size());
     LogSend(str+"\n");

     qDebug()<<"str.toStdString().c_str():"<<str.toStdString().c_str()<<",len:"<<str.size();

     if (UDT::ERROR == (ss = UDT::send(client, str.toStdString().c_str(),strlen(str.toStdString().c_str()), 0)))
     {
          // qDebug() << "send_error:" << UDT::getlasterror().getErrorMessage() << endl;
         LogSend("send_error\n");
         return;
     }

     //设置运行状态
     run_flag=true;

     LogSend(QString("准备发送%1文件.目的地:%2:%3\n").arg(send_file).arg(server_ip_addr).arg(server_port));

     //获取系统当前时间
     time1= QDateTime::currentMSecsSinceEpoch();

    //开始发送
    while(run_flag)
    {
        QByteArray byte;

        byte=SrcFile.read(MAX_READ_LEN);

        if (UDT::ERROR == (send_len = UDT::send(client,byte.data(),byte.size(), 0)))
        {
            LogSend("send_error....\n");
            break;
        }
        //记录发送的长度
         Send_TotalBytes+=send_len;

         //获取本地时间
         current_ms_time=QDateTime::currentMSecsSinceEpoch();

         //时间经过了1s
         if(current_ms_time-old_ms_time>1000)
         {
             old_ms_time=current_ms_time;

             //更新状态
             ss_FileSendState(Send_TotalBytes,File_TotalBytes);
         }

        if(Send_TotalBytes>=File_TotalBytes || (byte.size()<MAX_READ_LEN))
        {
            break;
        }

        QThread::msleep(1);
    }

    UDT::close(client);

    //获取系统当前时间
    time2= QDateTime::currentMSecsSinceEpoch();

    //消耗的时间
    time1=time2-time1;

    //更新状态
    ss_FileSendState(Send_TotalBytes,File_TotalBytes);

    LogSend(QString("UDP文件发送完成. 总大小:%1 Byte. 耗时:%2\n").arg(File_TotalBytes).arg(QTime(0, 0, 0,0).addMSecs(int(time1)).toString(QString::fromLatin1("HH:mm:ss:zzz"))));

    Send_TotalBytes=0;
    File_TotalBytes=0;

    //关闭文件
    SrcFile.close();

    //发送完毕
    emit ss_SendComplete();

    LogSend("发送线程已正常退出...\n");
}


void UDP_FILE_SEND_THREAD::exit_thread()
{
    run_flag=false;
    //退出事件循环
    this->exit();
}

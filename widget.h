#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QFileDialog>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QScrollBar>
#include <QTimer>
#include <QDateTime>
#include "udp_file_send.h"
#include <windows.h>
#include <QTextCodec>



QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

//文件保存目录
#define FILE_SAVE_DIR "file"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    /*页面样式表初始化*/
    void SetStyle(const QString &qssFile);

    //初始化配置
    void InitConfig();

    //创建文件
    BOOL CreateTempFile(DWORD dwHigh, DWORD dwLow, TCHAR* pFileName);
protected:
    void closeEvent(QCloseEvent *event);
public slots:
    //发送完毕
    void slots_SendComplete();
    void slots_FileSendState(qint64,qint64);
    //日志显示
    void Log_Text_Display(QString text);
private slots:

    void current_timer_update();
    void on_pushButton_save_log_clicked();

    void on_pushButton_start_udp_clicked();

    void on_pushButton_select_rx_file_path_clicked();

private:
    Ui::Widget *ui;
    QTimer current_timer; //当前时间
    UDP_FILE_SEND_THREAD udp_file_send_thread;
};
#endif // WIDGET_H

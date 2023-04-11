#ifndef UDP_FILE_SEND_H
#define UDP_FILE_SEND_H
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
#include <QThread>
#include <QUdpSocket>
#include <QFile>
#include <QEventLoop>

#ifndef WIN32
   #include <cstdlib>
   #include <netdb.h>
#else
   #include <winsock2.h>
   #include <ws2tcpip.h>
#endif
#include <fstream>
#include <iostream>
#include <cstring>
#include "udt_src/udt.h"

using namespace std;


//一次读取文件的字节数
#define MAX_READ_LEN 1024*200

//一次发送数据包的数量
#define MAX_TX_PACK_CNT 10
//#define MAX_TX_PACK_CNT 100


//包发送的间隔时间
#define DELAY_US_TIME 1000

//小文件限制
#define MIN_FILE_SIZE 1024*1024

class UDP_FILE_SEND_THREAD:public QThread
{
    Q_OBJECT
public:
    UDP_FILE_SEND_THREAD();
    ~UDP_FILE_SEND_THREAD();
    void set_ServerIP(QString ip){server_ip_addr=ip;Send_TotalBytes=0;}
    void set_ServerPort(qint16 port){server_port=port;}
    void exit_thread();
    void set_send_file(QString file){send_file=file;}
protected:
    void run();
public slots:
signals:
    void LogSend(QString text);
    //参数1: 当前已经发送的字节  参数2:总字节数
    void ss_FileSendState(qint64,qint64);
    //发送完毕通知
    void ss_SendComplete();
private:
    //私有变量
    QString server_ip_addr;
    qint16 server_port;
    QString send_file;
    bool run_flag=true;

    qint64 File_TotalBytes=0; //文件总字节数
    qint64 Send_TotalBytes=0; //总字节数

    QEventLoop loop; //事件循环
    bool FileInfoSendSuccess=0; //文件信息发送成功

    qint64 current_ms_time=0;  //当前时间
    qint64 old_ms_time=0;  //上次时间

    UDTSOCKET client;
};

#endif // UDP_FILE_SEND_H

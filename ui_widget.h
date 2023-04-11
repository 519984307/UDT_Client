/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_agreement_type;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_ip_addr;
    QComboBox *comboBox_ip_addr;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_port;
    QSpinBox *spinBox_port;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_select_rx_file_path;
    QLineEdit *lineEdit_send_file_save_path;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QSpinBox *spinBox_auto_create_file_size;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QLineEdit *lineEdit_auto_create_file_path;
    QPushButton *pushButton_save_log;
    QPushButton *pushButton_start_udp;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QLineEdit *lineEdit_recv_file_name;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QLabel *label_recv_byte;
    QLabel *label_9;
    QLabel *label_Total_Byte;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit_log;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_current_time;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1219, 552);
        verticalLayout_3 = new QVBoxLayout(Widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_agreement_type = new QLabel(groupBox);
        label_agreement_type->setObjectName(QString::fromUtf8("label_agreement_type"));

        horizontalLayout->addWidget(label_agreement_type);

        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_ip_addr = new QLabel(groupBox);
        label_ip_addr->setObjectName(QString::fromUtf8("label_ip_addr"));

        horizontalLayout_3->addWidget(label_ip_addr);

        comboBox_ip_addr = new QComboBox(groupBox);
        comboBox_ip_addr->addItem(QString());
        comboBox_ip_addr->setObjectName(QString::fromUtf8("comboBox_ip_addr"));
        comboBox_ip_addr->setEditable(true);

        horizontalLayout_3->addWidget(comboBox_ip_addr);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_port = new QLabel(groupBox);
        label_port->setObjectName(QString::fromUtf8("label_port"));

        horizontalLayout_2->addWidget(label_port);

        spinBox_port = new QSpinBox(groupBox);
        spinBox_port->setObjectName(QString::fromUtf8("spinBox_port"));
        spinBox_port->setMinimum(1024);
        spinBox_port->setMaximum(65535);
        spinBox_port->setValue(6666);

        horizontalLayout_2->addWidget(spinBox_port);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton_select_rx_file_path = new QPushButton(groupBox);
        pushButton_select_rx_file_path->setObjectName(QString::fromUtf8("pushButton_select_rx_file_path"));

        horizontalLayout_5->addWidget(pushButton_select_rx_file_path);

        lineEdit_send_file_save_path = new QLineEdit(groupBox);
        lineEdit_send_file_save_path->setObjectName(QString::fromUtf8("lineEdit_send_file_save_path"));

        horizontalLayout_5->addWidget(lineEdit_send_file_save_path);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        spinBox_auto_create_file_size = new QSpinBox(groupBox);
        spinBox_auto_create_file_size->setObjectName(QString::fromUtf8("spinBox_auto_create_file_size"));
        spinBox_auto_create_file_size->setMinimum(1);
        spinBox_auto_create_file_size->setMaximum(999999999);
        spinBox_auto_create_file_size->setValue(1024);

        horizontalLayout_4->addWidget(spinBox_auto_create_file_size);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_7->addWidget(label_2);

        lineEdit_auto_create_file_path = new QLineEdit(groupBox);
        lineEdit_auto_create_file_path->setObjectName(QString::fromUtf8("lineEdit_auto_create_file_path"));
        lineEdit_auto_create_file_path->setReadOnly(true);

        horizontalLayout_7->addWidget(lineEdit_auto_create_file_path);


        verticalLayout_2->addLayout(horizontalLayout_7);

        pushButton_save_log = new QPushButton(groupBox);
        pushButton_save_log->setObjectName(QString::fromUtf8("pushButton_save_log"));

        verticalLayout_2->addWidget(pushButton_save_log);

        pushButton_start_udp = new QPushButton(groupBox);
        pushButton_start_udp->setObjectName(QString::fromUtf8("pushButton_start_udp"));

        verticalLayout_2->addWidget(pushButton_start_udp);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_8->addWidget(label_5);

        lineEdit_recv_file_name = new QLineEdit(groupBox);
        lineEdit_recv_file_name->setObjectName(QString::fromUtf8("lineEdit_recv_file_name"));

        horizontalLayout_8->addWidget(lineEdit_recv_file_name);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(0);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_13->addWidget(label_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer);

        label_recv_byte = new QLabel(groupBox);
        label_recv_byte->setObjectName(QString::fromUtf8("label_recv_byte"));

        horizontalLayout_13->addWidget(label_recv_byte);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_13->addWidget(label_9);

        label_Total_Byte = new QLabel(groupBox);
        label_Total_Byte->setObjectName(QString::fromUtf8("label_Total_Byte"));

        horizontalLayout_13->addWidget(label_Total_Byte);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_13);


        horizontalLayout_6->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plainTextEdit_log = new QPlainTextEdit(groupBox_2);
        plainTextEdit_log->setObjectName(QString::fromUtf8("plainTextEdit_log"));
        plainTextEdit_log->setEnabled(true);
        plainTextEdit_log->setReadOnly(true);

        verticalLayout->addWidget(plainTextEdit_log);


        horizontalLayout_6->addWidget(groupBox_2);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_5);

        label_current_time = new QLabel(Widget);
        label_current_time->setObjectName(QString::fromUtf8("label_current_time"));

        horizontalLayout_11->addWidget(label_current_time);


        verticalLayout_3->addLayout(horizontalLayout_11);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_agreement_type->setText(QCoreApplication::translate("Widget", "\345\215\217\350\256\256\347\261\273\345\236\213:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Widget", "UDP", nullptr));

        label_ip_addr->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\346\234\215\345\212\241\345\231\250IP\345\234\260\345\235\200:", nullptr));
        comboBox_ip_addr->setItemText(0, QCoreApplication::translate("Widget", "127.0.0.1", nullptr));

        label_port->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\345\217\267:", nullptr));
        pushButton_select_rx_file_path->setText(QCoreApplication::translate("Widget", "\346\211\213\345\212\250\351\200\211\346\213\251\345\217\221\351\200\201\347\232\204\346\226\207\344\273\266:", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\350\207\252\345\212\250\347\224\237\346\210\220\347\232\204\346\226\207\344\273\266\345\244\247\345\260\217(MB):", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\350\207\252\345\212\250\347\224\237\346\210\220\347\232\204\346\226\207\344\273\266\345\255\230\345\202\250\350\267\257\345\276\204:", nullptr));
        pushButton_save_log->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272\346\227\245\345\277\227", nullptr));
        pushButton_start_udp->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213\345\217\221\351\200\201", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\345\275\223\345\211\215\346\255\243\345\234\250\345\217\221\351\200\201\347\232\204\346\226\207\344\273\266:", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\345\275\223\345\211\215\346\226\207\344\273\266\345\244\247\345\260\217\344\277\241\346\201\257:", nullptr));
        label_recv_byte->setText(QCoreApplication::translate("Widget", "0", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "/", nullptr));
        label_Total_Byte->setText(QCoreApplication::translate("Widget", "0", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\346\227\245\345\277\227\344\277\241\346\201\257", nullptr));
        plainTextEdit_log->setDocumentTitle(QString());
        label_current_time->setText(QCoreApplication::translate("Widget", "2021/04/22", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

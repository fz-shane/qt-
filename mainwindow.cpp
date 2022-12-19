//#include "mainwindow.h"
//#include "ui_mainwindow.h"

//MainWindow::MainWindow(QWidget *parent)
//    : QMainWindow(parent)
//    , ui(new Ui::MainWindow)
//{
//    ui->setupUi(this);
//}

//MainWindow::~MainWindow()
//{
//    delete ui;
//}
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "主线程对象地址:  " << QThread::currentThread();
    // 创建子线程
    MyThread* subThread = new MyThread;

    connect(subThread, &MyThread::curNumber, this, [=](int num)
    {
        ui->label->setNum(num);
    });

    connect(ui->startBtn, &QPushButton::clicked, this, [=]()
    {
        // 启动子线程
        subThread->start();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}




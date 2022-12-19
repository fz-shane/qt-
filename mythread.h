//#ifndef MYTHREAD_H
//#define MYTHREAD_H


//class MyThread : public QThread
//{
//public:
//    MyThread();
//};

//#endif // MYTHREAD_H
#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);

protected:
    void run();

signals:
    // 自定义信号, 传递数据
    void curNumber(int num);

public slots:
};

#endif // MYTHREAD_H


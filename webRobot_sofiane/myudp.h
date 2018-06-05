#ifndef MYUDP_H
#define MYUDP_H

#include <QObject>
#include <QUdpSocket>
#include <iostream>
#include <QString>

using std::string;

class MyUDP : public QObject
{
    Q_OBJECT
public:
    explicit MyUDP(QObject *parent = nullptr);
    void HelloUDP (char datai);

    //explicit MyUDP(QObject *parent = 0);
signals:

public slots:
    void readyRead();

private:
    QUdpSocket *socket;
};

#endif // MYUDP_H

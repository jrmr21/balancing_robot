#include "myudp.h"

MyUDP::MyUDP(QObject *parent) : QObject(parent)
{
    // create a QUDP socket
        socket = new QUdpSocket(this);

        //socket->bind(QHostAddress::LocalHost, 21000);
        socket->bind(QHostAddress("192.168.0.21"), 7978);

        connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    }

void MyUDP::HelloUDP(char datai)
{
    QByteArray Data;
    Data.append(datai);
    // 192.168.0.177
    //socket->writeDatagram(Data, QHostAddress::Broadcast , 2100);
    socket->writeDatagram(Data, QHostAddress("192.168.0.177"), 7979);
    //socket->writeDatagram(Data, QHostAddress("169.254.55.188"), 21000);
}

    void MyUDP::readyRead()
    {
        // when data comes in
        QByteArray buffer;
        buffer.resize(socket->pendingDatagramSize());

        QHostAddress sender;
        quint16 senderPort;

        socket->readDatagram(buffer.data(), buffer.size(),&sender, &senderPort);

        qDebug() << "Message port: " << senderPort;
        qDebug() << "Message: " << buffer;
}

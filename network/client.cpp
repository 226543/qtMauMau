#include "client.h"
#include <QHostAddress>
#include <settings.h>

Client::Client(QObject* parent)
    : QObject(parent)
{
}

void Client::setupConnection(QString _address, QString _port)
{
    QHostAddress address = QHostAddress(_address);
    qint16 port = _port.toInt();

    client->connectToHost(address, port);

    connect(client, SIGNAL(connected()), this, SLOT(write()));
    connect(client, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(OnError()));
    //connect(&client, SIGNAL(readyRead()), this, SLOT(read()));
}

void Client::write()
{

    //    if (client->error()) {
    //        qCritical() << client->error();
    //        qCritical() << client->errorString();
    //        qCritical() << client->state();

    //    }

    //write HelloWorld is just a dummy
    client->write("Hallo Piiiiiiiuuuuuuuuusssss", 50);
}

void Client::OnError()
{
  qDebug() << "error";
}

void Client::UIplaysCard(const Card &card)
{

}

void Client::UIdrawsCard()
{

}
/*
void Client::read(){

    if (client.error()) {
        qCritical() << client.error();
        qCritical() << client.errorString();
        qCritical() << client.state();

    }

    qDebug() << "start reading from Server";

    char buffer[1024] = { 0 };
    client.read(buffer, client.bytesAvailable());
    qDebug() << buffer;
}*/

Client::~Client()
{
    client->close();
}

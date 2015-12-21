#include <QCoreApplication>
#include <QtDBus/QtDBus>
#include <QtCore/QDebug>
#include "myserver.h"
#include "mytimer.h"
//#include <iostream>



void ListServices()
{
    QDBusReply<QStringList> reply = QDBusConnection::systemBus().interface()->registeredServiceNames();
    if (!reply.isValid()) {
        qDebug() << "Error:" << reply.error().message();
        return;
    }
    foreach (QString name, reply.value())
        qDebug() << name;

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyServer server;

    server.start();

    if (!QDBusConnection::systemBus().isConnected()) {
        qDebug() << "No dbus session bus!";
    }
    else {
        ListServices();
    }

    return a.exec();
}

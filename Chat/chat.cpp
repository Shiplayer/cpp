#include <QWidgetItem>
#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
}

void Chat::setName(QString nickname){
    name = nickname;
    socket = new QUdpSocket(this);
    ui->nicknameLable->setText(ui->nicknameLable->text().trimmed() + " " + name);
    socket->bind(QHostAddress::Any, PORT, QUdpSocket::ReuseAddressHint);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    QByteArray datagram;
    datagram.append(name + QString(":is online"));
    socket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, PORT);
}

Chat::~Chat()
{
    delete ui;
}

void Chat::on_sendButton_clicked()
{
    QString message = ui->messageEdit->text().trimmed();
    if(!message.isEmpty()) {
        QByteArray datagram;
        datagram.append(name + QString(":") + message);
        datagram.append("\n");
        socket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, PORT);
    }

    ui->messageEdit->clear();
    ui->messageEdit->setFocus();
}


void Chat::on_messageEdit_returnPressed()
{
    on_sendButton_clicked();
}

void Chat::readyRead() {
    while(socket->hasPendingDatagrams()) {
        QByteArray buffer;
        buffer.resize(socket->pendingDatagramSize());
        QHostAddress sender;
        quint16 port;
        socket->readDatagram(buffer.data(), buffer.size(), &sender, &port);
        QString line = QString::fromUtf8(buffer).trimmed();
        QRegExp messageRegex("^([^:]+):(.*)$");
        if (messageRegex.indexIn(line) != -1) {
            QString user = messageRegex.cap(1);
            QString message = messageRegex.cap(2);
            bool newbee = true;
                    int pos = -1;
                    for (int i = 0; i < ui->userList->count(); i++)
                        if (ui->userList->item(i)->text() == user) {
                            newbee = false;
                            pos = i;
                            break;
                        }
                    if (newbee){
                        ui->userList->addItem(user);
                        ui->allUserList->addItem(user);
                    }
                    if(message == "is online"){
                        ui->messageBox->append(user + " " + message);
                        QByteArray datagram;
                        datagram.append(name + " add");
                        socket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, PORT);
                    }
                    else if(message == "is offline"){
                        if(!newbee){
                            QListWidgetItem *item = ui->userList->item(pos);
                            delete item;
                        }
                        ui->messageBox->append(user + " " + message);
                    } else
                        ui->messageBox->append("<" + user + ">: " + message);
        } else if(line.contains("add")){
            QString user = line.mid(0,line.indexOf(" "));
            bool newbee = true;
            for (int i = 0; i < ui->userList->count(); i++)
                if (ui->userList->item(i)->text() == user) {
                    newbee = false;
                    break;
                }
            if(newbee && name != user){
                ui->userList->addItem(user);
                ui->allUserList->addItem(user);
            }
        }
    }
}

void Chat::on_ExitButton_clicked()
{
    QByteArray datagram;
    datagram.append(name + ":is offline");
    socket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, PORT);
    exit(0);
}

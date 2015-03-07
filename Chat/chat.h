#ifndef CHAT_H
#define CHAT_H

#include <QDialog>
#include <QUdpSocket>


namespace Ui {
class Chat;
}

class Chat : public QDialog
{
    Q_OBJECT

public:
    void setName(QString nickname);
    explicit Chat(QWidget *parent = 0);
    ~Chat();

private slots:
    void on_sendButton_clicked();

    void on_messageEdit_returnPressed();

    void readyRead();

    void on_ExitButton_clicked();

private:
    QUdpSocket *socket;  //socket with udp protocol
    QString name; //user nickname
    const int PORT=8080; //port
    Ui::Chat *ui;
};

#endif // CHAT_H

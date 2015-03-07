#include "login.h"
#include "ui_login.h"
#include "chat.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginButton_clicked()
{
    QString name = ui->nicknameEdit->text().trimmed();
    if(name != ""){
        this->hide();
        chat = new Chat();
        chat->setName(name);
        chat->setModal(true);
        chat->exec();
    }
}

void Login::on_exitButton_clicked()
{
    exit(0);
}

#ifndef CONNECTTOSERVER_H
#define CONNECTTOSERVER_H

#include <QtWidgets/QDialog>
#include <settings.h>

namespace Ui {
class ConnectToServer;
}

class ConnectToServer : public QDialog {
    Q_OBJECT

public:
    explicit ConnectToServer(QWidget* parent = 0);
    ~ConnectToServer();
public
slots:
    void clientGameStarted();
    void connectionRejected();
    void connectionAccepted();

signals:
    void connectToServer(QString adress, QString port);

private
slots:
    void on_connectbtn_clicked();

    void on_cancelbtn_clicked();

private:
    Ui::ConnectToServer* ui;
};

#endif // CONNECTTOSERVER_H

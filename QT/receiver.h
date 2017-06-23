#ifndef RECEIVER_H
#define RECEIVER_H

#include <QWidget>

class QLabel;
class QPushButton;
class QUdpSocket;
class QAction;

class Receiver : public QWidget
{
    Q_OBJECT

public:
    Receiver(QWidget *parent = 0);
    QByteArray datagram;


private slots:
    void processPendingDatagrams();

private:
    QLabel *statusLabel;
    QPushButton *quitButton;
    QUdpSocket *udpSocket;


};

#endif

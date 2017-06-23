#include "chart.h"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QTime>
#include <QtCore/QDebug>
#include <QtWidgets>
#include <QtNetwork>
#include <QString>
#include <QDebug>
#include <QFont>
#include "receiver.h"

Chart::Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags),
    m_series(0),
    m_axis(new QValueAxis),
    m_step(0),
    m_x(5),
    m_y(1)

{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(45454, QUdpSocket::ShareAddress);
    QObject::connect(udpSocket, SIGNAL(readyRead()),this, SLOT(processPendingDatagrams()));

    //QObject::connect(&m_timer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
    //m_timer.setInterval(1000);

    m_series = new QSplineSeries(this);
    QPen green(Qt::blue);
    QFont serifFont("Times", 10, QFont::Bold);
    green.setWidth(6);
    m_series->setPen(green);
    m_series->append(m_x, m_y);
    m_series->setPointLabelsVisible(true);
    m_series->setPointLabelsFormat("(@yPoint)");
    m_series->setPointLabelsFont(serifFont);

    addSeries(m_series);
    createDefaultAxes();
    setAxisX(m_axis, m_series);
    m_axis->setTickCount(10);
    axisX()->setRange(0,10);
    axisY()->setRange(-50, 50);


    m_timer.start();
}

Chart::~Chart()
{

}

void Chart::handleTimeout()
{
    qreal x = plotArea().width() / m_axis->tickCount();
    qreal y = (m_axis->max() - m_axis->min()) / m_axis->tickCount();
    m_x += y;
    m_y = qrand() % 5 - 2.5;
    m_series->append(m_x, m_y);
    scroll(x, 0);
    if (m_x == 100)
        m_timer.stop();
}

void Chart::processPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams()) {
        //QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        qDebug("%s",datagram.data());

        QString myString = datagram.data();
        //QStringList myStringList = myString.split(',');
        qDebug() << myString;

        qreal x = plotArea().width() / m_axis->tickCount();
        qreal y = (m_axis->max() - m_axis->min()) / m_axis->tickCount();
        m_x += y;
        m_y = qrand() % 5 - 2.5;
        m_series->append(m_x,myString.toInt());
        qDebug() << m_x << myString.toInt();
        scroll(x, 0);//x,0
        if (m_x == 100)
            m_timer.stop();

    }
}

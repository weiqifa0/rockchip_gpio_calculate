#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QCryptographicHash>

#include <QTimer>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //hid_device *m_handle  = nullptr;
    QThread UsbReadthread;
    QThread UsbWriteDataImgthread;
    QThread UsbWriteUbootImgthread;

    QByteArray usbRcvBuff;
    int usbRcvFlag;

    QString DataFilePath;
    QString UbootFilePath;
    QString BootFilePath;
    QString DataBuffer;
    QString UbootBuffer;
    QString BootBuffer;

    QString logTime();

private slots:
    void on_gpio_num3_editingFinished();

private:
    Ui::MainWindow *ui;
    int StringToHex(QString Input);
};
#endif // MAINWINDOW_H

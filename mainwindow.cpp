#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets/QMessageBox>
#include <wchar.h> // wchar_t

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());//静置调整ui大小
    this->setWindowFlags(Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);//取消最大化按钮
}

MainWindow::~MainWindow()
{
    UsbReadthread.quit();
    UsbReadthread.wait();
    delete ui;
}


void MainWindow::on_gpio_num3_editingFinished()
{
  int gpio_output;
  int gpio_num = StringToHex(ui->gpio_num->text());
  int gpio_x = StringToHex(ui->gpio_num2->text());
  int gpio_y = StringToHex(ui->gpio_num3->text());

  qDebug("gpio_num:%d", gpio_num);
  qDebug("gpio_x:%d", gpio_x);
  qDebug("gpio_y:%d", gpio_y);
  gpio_output = gpio_num * 32 + (gpio_x - 0xA)*8 + gpio_y;
  qDebug("gpio_output:%d", gpio_output);
  QString string_gpio_output = QString::number(gpio_output,10);
  ui->gpio_output->setText(string_gpio_output);
}

int MainWindow::StringToHex(QString Input)
{
  bool ok;
  int hex = Input.toInt(&ok, 16);
  if (ok) {
    return hex;
  }
  return (-1);
}

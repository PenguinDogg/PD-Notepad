#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget((ui->textEdit));
    file_path_ = new QString;
    QString *title = new QString{ "PD Notepad" };
    this->setWindowTitle(*title);
    delete title;

    bold = false;
    underlined = false;
    italics = false;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete file_path_;
}

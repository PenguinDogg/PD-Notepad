#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qFontComboBox = new QFontComboBox(this);
    qFontComboBox->setObjectName(QString::fromUtf8("qFontComboBox"));
    qFontComboBox->setEnabled(true);
    ui->setupUi(this);
    ui->toolBar->addWidget(qFontComboBox);
    this->setCentralWidget((ui->textEdit));
    file_path_ = new QString;

    bold = false;
    underlined = false;
    italics = false;


}

MainWindow::~MainWindow()
{
    delete ui;
    delete file_path_;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontComboBox>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qFontComboBox = new QFontComboBox(this);
    qFontComboBox->setObjectName(QString::fromUtf8("qFontComboBox"));
    qFontComboBox->setEnabled(true);

    fontSizeWidget = new QComboBox(this);
    fontSizeWidget->setObjectName(QString::fromUtf8("fontSizeWidget"));
    fontSizeWidget->setEnabled(true);

    QList<QString> fontSizes = { "6", "8", "9", "10", "12", "14", "16", "18", "24", "30", "36", "48", "60", "72", "84" };
    fontSizeWidget->addItems(fontSizes);
    fontSizeWidget->setCurrentIndex(3); // 10 pt

    ui->setupUi(this);

    ui->toolBar->addWidget(qFontComboBox);
    ui->toolBar->addWidget(fontSizeWidget);
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

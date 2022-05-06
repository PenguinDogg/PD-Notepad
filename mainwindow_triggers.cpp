#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

void MainWindow::on_actionOpen_triggered()
{
    QString *file_name = new QString
                        { QFileDialog::getOpenFileName(
                                this, "Open the file" /*next params: default location, filters*/)
                        };

    QFile *file = new QFile { *file_name };

    if(!file->open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "..", "File is not open");
        return;
    }

    QTextStream in(file);
    QString *text = new QString { in.readAll() };
    ui->textEdit->setText(*text);
    file->close();

    *file_path_ = *file_name;

    delete text;
    delete file_name;
    delete file;
}

void MainWindow::on_actionNew_triggered()
{
    *file_path_ = "";
    ui->textEdit->setText("");
}

void MainWindow::on_actionSave_triggered()
{
    QFile *file = new QFile { *file_path_ };

    if(!file->open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "..", "File failed to open");
        return;
    }

    QTextStream out(file);
    QString *text = new QString { ui->textEdit->toPlainText() };
    out << *text;

    file->flush();
    file->close();

    delete text;
    delete file;
}


void MainWindow::on_actionSave_As_triggered()
{
    QString *file_name = new QString
                        { QFileDialog::getSaveFileName(
                                this, "Save File As..." /*next params: default location, filters*/)
                        };

    QFile *file = new QFile { *file_name };

    if(!file->open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "..", "File failed to save");
        return;
    }

    QTextStream out(file);
    QString *text = new QString { ui->textEdit->toPlainText() };
    out << *text;

    file->flush();
    file->close();

    delete text;
    delete file_name;
    delete file;
}

// Built in methods within Qt
void MainWindow::on_actionCut_triggered()   {   ui->textEdit->cut();      }
void MainWindow::on_actionCopy_triggered()  {   ui->textEdit->copy();     }
void MainWindow::on_actionPaste_triggered() {   ui->textEdit->paste();    }
void MainWindow::on_actionRedo_triggered()  {   ui->textEdit->redo();     }
void MainWindow::on_actionUndo_triggered()  {   ui->textEdit->undo();     }

void MainWindow::on_actionAbout_Notepad_triggered() {
    QString *about = new QString[2] {
        "About PD Notepad",
        "A lightweight notepad program to help learn Qt\nPenguinDogg\nCreated under the MIT license"
    };

    QMessageBox::about(this, about[0], about[1]);

    delete[] about;
}

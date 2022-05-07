#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFontComboBox>
#include <QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QComboBox *fontSizeWidget;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionRedo_triggered();

    void on_actionUndo_triggered();

    void on_actionAbout_Notepad_triggered();;

    void on_actionBold_triggered();

    void on_actionItalics_triggered();

    void on_actionUnderline_triggered();

    void on_qFontComboBox_currentFontChanged(const QFont &f);

    void on_fontSizeWidget_currentIndexChanged(int index);

private:
    QFontComboBox *qFontComboBox;
    Ui::MainWindow *ui;
    QString *file_path_;
    bool bold, underlined, italics;
};
#endif // MAINWINDOW_H

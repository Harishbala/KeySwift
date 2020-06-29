#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtKeyToTamilKey.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QTextEdit;
class QHBoxLayout;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent(QKeyEvent* event);

private:
    QtKeyToTamilKey key_translator;
    QTextEdit *m_tamil_editor;
    QHBoxLayout *m_layout;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H

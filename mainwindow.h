#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QTextEdit>
#include <QtKeyToTamilKey.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QTextEdit;
class QHBoxLayout;

class TTWTextEdit : public QTextEdit
{
public:
    TTWTextEdit(QWidget *parent)
        : QTextEdit(parent)
    {}
protected:
    void keyPressEvent(QKeyEvent* event);

private:
    QtKeyToTamilKey key_translator;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void focusOutEvent(QFocusEvent* e);

private:
    QtKeyToTamilKey key_translator;
    TTWTextEdit *m_tamil_editor;
    QHBoxLayout *m_layout;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H

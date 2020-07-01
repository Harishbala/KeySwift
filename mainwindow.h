#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QTextEdit>
#include <QPushButton>
#include <QtKeyToTamilKey.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QTextEdit;
class QHBoxLayout;
class QPushButton;

class TTWTextEdit : public QTextEdit
{
public:
    TTWTextEdit(QWidget *parent)
        : QTextEdit(parent),
          m_english_toggle(false)
    {}

    void set_english_toggle(bool toggle);
    bool get_english_toggle() const;
protected:
    void keyPressEvent(QKeyEvent* event);

private:
    QtKeyToTamilKey m_key_translator;
    bool m_english_toggle;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void button_clicked();

private:    
    QtKeyToTamilKey key_translator;
    TTWTextEdit *m_tamil_editor;
    QHBoxLayout *m_layout;
    //QPushButton toggleButton;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H

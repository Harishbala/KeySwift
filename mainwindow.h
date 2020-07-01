#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtKeyToTamilKey.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void button_clicked();

protected:
    bool eventFilter(QObject* obj, QEvent* event);

private:
    bool textEditKeyPressed(QKeyEvent* event);

    QtKeyToTamilKey key_translator;
    QtKeyToTamilKey m_key_translator;
    bool m_english_toggle;

    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H

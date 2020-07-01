#include "mainwindow.h"
#include <QtWidgets/QTextEdit>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QClipboard>
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->installEventFilter(this);

    QObject::connect(ui->toggleButton, SIGNAL(clicked()), this, SLOT(button_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button_clicked()
{
    m_english_toggle = !m_english_toggle;
}

bool MainWindow::eventFilter(QObject* obj, QEvent* event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
        if(textEditKeyPressed(key_event))
            return true;
    }
    return QObject::eventFilter(obj, event);
}

bool MainWindow::textEditKeyPressed(QKeyEvent* event)
{
    if(m_english_toggle)
    {
        return false;
    }

    else if(event->key() == Qt::Key::Key_Control)
    {
        QString tamilText = ui->textEdit->toPlainText();
        QClipboard *clipboard = QApplication::clipboard();
        clipboard->setText(tamilText);
        return true;
    }
    else if(event->key() == Qt::Key::Key_Alt)
    {
        ui->textEdit->clear();
        return true;
    }
    else
    {
        QString tamilText = ui->textEdit->toPlainText();
        QString prevKey = "";
        const auto position = ui->textEdit->textCursor().position();
        if(position > 0)
        {
            prevKey = QString(tamilText[position - 1]);
        }
        QString tamilKey{""};
        if(m_key_translator.getTamilKey(event, prevKey, tamilKey))
        {
            ui->textEdit->textCursor().insertText(tamilKey);
            return true;
        }
    }

    return false;
}

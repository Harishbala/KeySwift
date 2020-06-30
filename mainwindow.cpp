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

    m_tamil_editor = new TTWTextEdit(parent);

    m_layout = new QHBoxLayout();
    m_layout->addWidget(m_tamil_editor);

    this->centralWidget()->setLayout(m_layout);

    //m_tamil_editor->setReadOnly(true);
    //this->setFocus();
}

MainWindow::~MainWindow()
{
    delete m_tamil_editor;
    delete m_layout;
    delete ui;
}

void TTWTextEdit::keyPressEvent(QKeyEvent* event)
{
    //QString tamilText = m_tamil_editor->toPlainText();

    if(event->key() == Qt::Key::Key_Backspace)
    {
        QTextEdit::keyPressEvent(event);
        return;
    }
    else if(event->key() == Qt::Key::Key_Control)
    {
        QString tamilText = this->toPlainText();
        QClipboard *clipboard = QApplication::clipboard();
        clipboard->setText(tamilText);
    }
    else if(event->key() == Qt::Key::Key_Alt)
    {
        this->clear();
    }
    else
    {
        QString tamilText = this->toPlainText();
        QString prevKey = "";
        if(tamilText.length() > 0)
        {
            auto lastIndex = tamilText.length() - 1;
            prevKey = QString(tamilText[lastIndex]);
        }
        auto tamilKey = key_translator.getTamilKey(event, prevKey);
        tamilText = tamilKey;
        this->textCursor().insertText(tamilText);
    }
}

void MainWindow::focusOutEvent(QFocusEvent* e)
{
    //If the focus is last from the mainwindow, the keyPressEvent is not fired for space charecter.
    //So always receive set the focus to mainwindow
    //this->setFocus();
}

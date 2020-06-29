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

    m_tamil_editor = new QTextEdit(parent);

    m_layout = new QHBoxLayout();
    m_layout->addWidget(m_tamil_editor);

    this->centralWidget()->setLayout(m_layout);

    m_tamil_editor->setReadOnly(true);
    this->setFocus();
}

MainWindow::~MainWindow()
{
    delete m_tamil_editor;
    delete m_layout;
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    QString tamilText = m_tamil_editor->toPlainText();

    if(event->key() == Qt::Key::Key_Backspace)
    {
        int lastIndex = tamilText.length() - 1;
        tamilText.remove(lastIndex, 1);
    }
    else if(event->key() == Qt::Key::Key_Control)
    {
        QClipboard *clipboard = QApplication::clipboard();
        clipboard->setText(tamilText);
    }
    else if(event->key() == Qt::Key::Key_Alt)
    {
        tamilText = "";
    }
    else
    {
        auto tamilKey = key_translator.getTamilKey(event);
        tamilText += tamilKey;
    }

    m_tamil_editor->setText(tamilText);
}

void MainWindow::focusOutEvent(QFocusEvent* e)
{
    //If the focus is last from the mainwindow, the keyPressEvent is not fired for space charecter.
    //So always receive set the focus to mainwindow
    this->setFocus();
}

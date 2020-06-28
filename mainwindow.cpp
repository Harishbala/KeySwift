#include "mainwindow.h"
#include <QtWidgets/QTextEdit>
#include <QHBoxLayout>
#include <QKeyEvent>
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_text_editor = new QTextEdit(parent);
    m_tamil_editor = new QTextEdit(parent);

    m_layout = new QHBoxLayout();

    m_text_editor->setGeometry(10, 10, 20, 20);
    m_tamil_editor->setGeometry(10, 30, 20, 20);

    m_layout->addWidget(m_text_editor);
    m_layout->addWidget(m_tamil_editor);

    this->centralWidget()->setLayout(m_layout);

    m_tamil_editor->setText("தமிழ்");
    m_tamil_editor->setReadOnly(true);
    this->setFocus();
    //m_text_editor->setFocus();
    //connect(m_text_editor, SIGNAL(textChanged()), this, SLOT(handleTextChange()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    using namespace Qt;
    QString tamilKey = "";
    switch(event->key())
    {
        case Key::Key_A:
            tamilKey = "அ"; break;
        case Key::Key_Q:
            tamilKey = "ஆ"; break;
        case Key::Key_S:
            tamilKey = "இ"; break;
        default:
            break;
    }
    QString tamilText = m_tamil_editor->toPlainText();
    tamilText += tamilKey;
    m_tamil_editor->setText(tamilText);
}
/*
void MainWindow::handleTextChange()
{
    QString englishText = m_text_editor->toPlainText();
    const auto lastCharIndex = englishText.length() - 1;
    if(englishText.at(lastCharIndex) == 'a')
    {
        QString tamilText = m_tamil_editor->toPlainText();
        tamilText += "அ";
        m_tamil_editor->setText(tamilText);
    }
}
*/

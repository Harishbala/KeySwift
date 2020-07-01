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
    m_layout->addWidget(ui->toggleButton);

    this->centralWidget()->setLayout(m_layout);


    QObject::connect(ui->toggleButton, SIGNAL(clicked()), this, SLOT(button_clicked()));
}

MainWindow::~MainWindow()
{
    delete m_tamil_editor;
    delete m_layout;
    delete ui;
}

void MainWindow::button_clicked()
{
    m_tamil_editor->set_english_toggle(!m_tamil_editor->get_english_toggle());
}

bool TTWTextEdit::get_english_toggle() const
{
    return m_english_toggle;
}

void TTWTextEdit::set_english_toggle(bool toggle)
{
    m_english_toggle = toggle;
}
void TTWTextEdit::keyPressEvent(QKeyEvent* event)
{
    if(get_english_toggle())
    {
        QTextEdit::keyPressEvent(event);
        return;
    }

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
        const auto position = this->textCursor().position();
        if(position > 0)
        {
            prevKey = QString(tamilText[position - 1]);
        }
        QString tamilKey{""};
        if(m_key_translator.getTamilKey(event, prevKey, tamilKey))
        {
            this->textCursor().insertText(tamilKey);
        }
        else
        {
            QTextEdit::keyPressEvent(event);
        }
    }
}

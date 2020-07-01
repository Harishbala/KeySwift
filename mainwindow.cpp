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
    m_tamil_editor->installEventFilter(this);

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

bool MainWindow::eventFilter(QObject* obj, QEvent* event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
        if(ownkeyPressEvent(key_event))
            return true;
    }
    return QObject::eventFilter(obj, event);
}

bool MainWindow::ownkeyPressEvent(QKeyEvent* event)
{
    if(m_tamil_editor->get_english_toggle())
    {
        return false;
    }

    else if(event->key() == Qt::Key::Key_Control)
    {
        QString tamilText = m_tamil_editor->toPlainText();
        QClipboard *clipboard = QApplication::clipboard();
        clipboard->setText(tamilText);
        return true;
    }
    else if(event->key() == Qt::Key::Key_Alt)
    {
        m_tamil_editor->clear();
        return true;
    }
    else
    {
        QString tamilText = m_tamil_editor->toPlainText();
        QString prevKey = "";
        const auto position = m_tamil_editor->textCursor().position();
        if(position > 0)
        {
            prevKey = QString(tamilText[position - 1]);
        }
        QString tamilKey{""};
        if(m_key_translator.getTamilKey(event, prevKey, tamilKey))
        {
            m_tamil_editor->textCursor().insertText(tamilKey);
            return true;
        }

    }

    return false;
}

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
    auto tamilKey = key_translator.getTamilKey(event->key());
    QString tamilText = m_tamil_editor->toPlainText();
    tamilText += tamilKey;
    m_tamil_editor->setText(tamilText);
}

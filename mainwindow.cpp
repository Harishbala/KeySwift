#include "mainwindow.h"
#include <QtWidgets/QTextEdit>
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_text_editor = new QTextEdit(parent);
    m_text_editor->setGeometry(10, 10, 80, 30);
    this->setCentralWidget(m_text_editor);
    connect(m_text_editor, SIGNAL(textChanged()), this, SLOT(handleTextChange()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleTextChange()
{
    m_text_editor->setText("Hello");
}

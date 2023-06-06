#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "book.h"
#include <QMessageBox>
#include <QDebug>
#include <QUrl>
#include <QDir>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Читательский дневник");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() // Кнопка ДОБАВИТЬ КНИГУ
{
    Book book;
   // hide();
    book.setModal(true);
    book.exec();
}



void MainWindow::on_pushButton_3_clicked() // Кнопка ВЫХОД
{
    QMessageBox::StandardButton Exit = QMessageBox::question(this, "Читательский дневник", "Хотите выйти?",QMessageBox::Yes | QMessageBox::No);

    if(Exit == QMessageBox::Yes){
        QApplication::quit();
    } else {
        qDebug() << "";
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    QUrl fileUrl = QUrl::fromLocalFile(QDir::currentPath() + "/books.txt");
    QDesktopServices::openUrl(fileUrl);
}


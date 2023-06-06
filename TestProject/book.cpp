#include "book.h"
#include "ui_book.h"
#include <QFile>
#include <QTextStream>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QDebug>
#include <QMessageBox>

Book::Book(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Book)
{

    ui->setupUi(this);
    this->setWindowTitle("Читательский дневник");

}

Book::~Book()
{
    delete ui;
}

void Book::on_checkBox_clicked()
{

}

void Book::on_pushButton_clicked()
{
    const QString bookTitle = ui->namebook->text();
    const QString authorName = ui->authorbook->text();
    const QString bookGradeString = ui->gradebook->text();

    // Проверяем корректность ввода данных
    bool isBookGradeValid = false;
    const int bookGrade = bookGradeString.toInt(&isBookGradeValid);
    if (!isBookGradeValid || bookGrade < 1 || bookGrade > 10) {
        QMessageBox::warning(this, "Ошибка", "Введите корректную оценку книги (число от 1 до 10)");
        return;
    }

    // Проверяем, что пользователь ввел Название и Автор книги
    if (bookTitle.isEmpty() || authorName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите название и автора книги");
        return;
    }

    QFile file("books.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "Ошибка", QString("Не удалось открыть файл %1 для записи").arg(file.fileName()));
        return;
    }

    QTextStream out(&file);
    out << "BOOK\n"
        << "Название: " << bookTitle << "\n"
        << "Автор: " << authorName << "\n"
        << "Оценка: " << bookGrade << "\n";

        if (!file.flush()) {
        QMessageBox::critical(this, "Ошибка", QString("Не удалось записать данные в файл %1").arg(file.fileName()));
    } else {
        hide();
    }
}



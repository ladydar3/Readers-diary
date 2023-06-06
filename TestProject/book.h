#ifndef BOOK_H
#define BOOK_H

#include <QDialog>

namespace Ui {
class Book;
}

class Book : public QDialog
{
    Q_OBJECT

public:
    explicit Book(QWidget *parent = nullptr);
    ~Book();

private slots:
    void on_checkBox_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_But_clicked();

private:
    Ui::Book *ui;
};

#endif // BOOK_H

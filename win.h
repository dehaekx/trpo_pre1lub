#ifndef win_h   // Директивы препроцессора для предотвращения многократного включения заголовочного файла
#define win_h

#include <QtWidgets>    // подключение библиотеки для всех объектов пользовательского интерфейса

class Win: public QWidget // класс окна, представляет пользовательское окно
{
    Q_OBJECT // макрос Qt, обеспечивающий корректное создание сигналов и слотов

protected:
    // Объявление указателей на различные виджеты, которые будут использоваться в пользовательском интерфейсе окна
    QFrame *frame; // рамка
    QLabel *inputLabel; // метка ввода
    QLineEdit *inputEdit; // строчный редактор ввода - куда вводим число
    QLabel *outputLabel; // метка вывода
    QLineEdit *outputEdit; // строчный редактор вывода
    QPushButton *nextButton; // кнопка Следующее - следующий пример
    QPushButton *exitButton; // кнопка Выход - завершение работы приложения

public:
    Win(QWidget *parent = 0); // конструктор класса, родитель по умолчанию 0
public slots:
    // методы класса
    void begin(); // метод начальной настройки интерфейса
    void calc(); // метод реализации вычислений
};

class StrValidator: public QValidator // класс компонента проверки ввода
{
public:
    StrValidator(QObject *parent):QValidator(parent){}
    State validate(QString &str,int &pos)const override // Зачем метод и const
    {
        auto msg = QMessageBox(
            QMessageBox::Information,
            "alert",
            "Вызван метод validate",
            QMessageBox::Ok
        );
        msg.exec();
        return Acceptable; // метод всегда принимает вводимую строку
    }
};
#endif

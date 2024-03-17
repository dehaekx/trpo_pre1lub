#include "win.h"

Win::Win(QWidget *parent): QWidget(parent) // конструктор, который создает объеты и строит пользовательское окно
{
    setWindowTitle(("Возведение в квадрат")); // Установливаем заголовок окна
    frame = new QFrame(this); // Создаем объекта QFrame
    frame->setFrameShadow(QFrame::Raised); // Установливаем стиль тени для рамки объекта QFrame
    frame->setFrameShape(QFrame::Panel); // Установливаем форму рамки объекта QFrame

    inputLabel = new QLabel(("Введите число:"), this); // Создаем объект QLabel с текстом "Введите число"
    inputEdit = new QLineEdit("", this); // Создаем объект QLineEdit для ввода текста
    StrValidator *v = new StrValidator(inputEdit); // Создаем объект валидатора для проверки вводимых данных
    inputEdit->setValidator(v);
    outputLabel = new QLabel(("Результат:"), this); // Созданем объект QLabel с текстом "Результат"
    outputEdit = new QLineEdit("", this); // Создаем объект QLineEdit для отображения результата вычислений
    nextButton = new QPushButton(("Следующее"), this); // Создаем кнопки "Следующее"
    exitButton = new QPushButton(("Выход"), this); // создаем кнопку выход

    // компоновка приложения выполняется согласно рисунку 2.
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame); // Создаем вертикальную компоновку для объекта frame
    vLayout1->addWidget(inputLabel); // Добавляем объект inputLabel в компоновку vLayout1
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch(); // Добавляем упругий интервал в компоновку vLayout1

    QVBoxLayout *vLayout2 = new QVBoxLayout(); // Создаем вертикальную компоновку vLayout2
    vLayout2->addWidget(nextButton); // Добавление кнопки nextButton в компоновку vLayout2
    vLayout2->addWidget(exitButton); // Добавление кнопки exitButton в компоновку vLayout2
    vLayout2->addStretch(); // Добавляем упругий интервал в компоновку vLayout2

    QHBoxLayout *hLayout = new QHBoxLayout(this); // Создание горизонтальной компоновки hLayout
    hLayout->addWidget(frame); // Добавление объекта frame в компоновку hLayout
    hLayout->addLayout(vLayout2); // Добавление компоновки vLayout2 в hLayout
    begin();
    // connect(exitButton,SIGNAL(clicked(bool)),
    //         this,SLOT(close()));
    // Установка соединения между событием "клик по кнопке exitButton" и методом close()
    connect(exitButton, &QPushButton::clicked, this, &Win::close);

    // connect(nextButton,SIGNAL(clicked(bool)),
    //         this,SLOT(begin()));
    // Установка соединения между событием "клик по кнопке nextButton" и методом begin()
    connect(nextButton, &QPushButton::clicked, this, &Win::begin);

    // connect(inputEdit,SIGNAL(returnPressed()),
    //         this,SLOT(calc()));
    // Установка соединения между событием "ввод текста и нажатие Enter в inputEdit" и методом calc()
    connect(inputEdit, &QLineEdit::returnPressed, this, &Win::calc);
}
void Win::begin()
{
    inputEdit->clear(); // очищает поле ввода
    nextButton->setEnabled(false); // недоступность nextButton
    nextButton->setDefault(false); // не выделяется кнопка nextButton изначально
    inputEdit->setEnabled(true); // поле ввода доступно
    outputLabel->setVisible(false); // label  "результат" не виден
    outputEdit->setVisible(false); // поле результата вычисления не виде
    outputEdit->setEnabled(false); // не дает редактировать поле с результатом
    inputEdit->setFocus(); // выделяется поле ввода после нажатия nextButton
}

void Win::calc()
{
    bool Ok=true;
    float r, a;
    QString str = inputEdit->text();
    a = str.toDouble(&Ok);
    if (Ok)
    {
        r=a*a;
        str.setNum(r);
        outputEdit->setText(str);
        inputEdit->setEnabled(false);
        outputLabel->setVisible(true);
        outputEdit->setVisible(true);
        nextButton->setDefault(true);
        nextButton->setEnabled(true);
        nextButton->setFocus();
    }
    else
        if (!str.isEmpty())
        {
            QMessageBox msgBox(QMessageBox::Information,
                               ("Возведение в квадрат."),
                               ("Введено неверное значение."),
                               QMessageBox::Ok);
            msgBox.exec();
        }
}

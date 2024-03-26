#include "area.h"

Area::Area(QWidget *parent):QWidget(parent)
{
    setFixedSize(QSize(300,200)); // ширина и высота // размер виджета 300x200 пикс
    myline=new MyLine(80,100,50); // наследник Figura(int X,int Y,int Halflen)
    myrect=new MyRect(220,100,50);
    alpha=0;
}

void Area::showEvent(QShowEvent *) //при создании окна showevent // вызыв при отображении окна
{
    myTimer=startTimer(50); // создать таймер для перемещения фигур
}

void Area::paintEvent(QPaintEvent *) // перерисовать окно
{
    QPainter painter(this); // рисование в текущем виджете
    painter.setPen(Qt::red); // устанавливает перо красный цвет
    myline->move(alpha,&painter); // перемещение на угол  alpha
    myrect->move(alpha*(-0.5),&painter); // перемещение на угол  alpha
}

void Area::timerEvent(QTimerEvent *event) // Обрабатывает события срабатывания таймера
{
    if (event->timerId() == myTimer) // если наш таймер
    {
        alpha=alpha+0.2;
        update(); // обновить внешний вид (перерисовка окна)
    }
    else
        QWidget::timerEvent(event); // иначе передать его класс-предку для стандартной обработки
}

void Area::hideEvent(QHideEvent *) // вызывается при скрытии окна
{
    killTimer(myTimer); // уничтожить таймер
}
Area::~Area()
{
    delete myline;
    delete myrect;
}

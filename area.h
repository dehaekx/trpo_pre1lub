#ifndef area_h
#define area_h
#include "figura.h"

#include <QtWidgets>

class Area : public QWidget
{
    int myTimer; // идентификатор таймера
    float alpha; // угол поворота
public:
    Area(QWidget *parent = 0);
    ~Area();
    MyLine *myline;
    MyRect *myrect;
protected:
    // обработчики событий
    void paintEvent(QPaintEvent *event); // Метод, который вызывается при необходимости перерисовки виджета, происходит рисование элементов
    void timerEvent(QTimerEvent *event); // Метод, который вызывается при срабатывании таймера, обрабатываются события таймера
    void showEvent(QShowEvent *event); // Показ виджета
    void hideEvent(QHideEvent *event); // скрытие виджета
};
#endif



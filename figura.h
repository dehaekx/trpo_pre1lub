#ifndef figura_h
#define figura_h
#include <QPainter> //объект этого класса получает доступ к фрагменту экрана,
                    //отведенном под окно, в котором выполняется рисование

class Figura
{
protected:
    int x,y,halflen,dx,dy,r;
    virtual void draw(QPainter *Painter)=0; // для отрисовки фигуры
public:
    Figura(int X,int Y,int Halflen):
        x(X),y(Y),halflen(Halflen){}
    void move(float Alpha,QPainter *Painter);
};

class MyLine:public Figura
{
protected:
    void draw(QPainter *Painter) override; // Переопределенный виртуальный метод draw from Figura
public:
    MyLine(int x,int y,int halflen):Figura(x,y,halflen){} // конструктор линии
};

class MyRect:public Figura
{
protected:
    void draw(QPainter *Painter) override; // также переопределнный виртуальный метод draw
public:
    MyRect(int x,int y,int halflen):Figura(x,y,halflen){} // конструктор прямоугольника
};
#endif

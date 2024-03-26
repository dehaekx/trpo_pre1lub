#include "win.h"
//#include <QVBoxLayout>

Window::Window()
{
    this->setWindowTitle("Обработка событий");
    area = new Area(this);
    btn = new QPushButton("Завершить", this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(area);
    layout->addWidget(btn);
    //connect(btn, SIGNAL(clicked(bool)),this,SLOT(close()));
    // Устанавливаем сигнала clicked кнопки btn и слотом close объекта qwidget(this)
    connect(btn, &QPushButton::clicked, this, &QWidget::close);
};

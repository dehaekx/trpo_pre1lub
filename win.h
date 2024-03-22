#ifndef win_h
#define win_h

#include <QtWidgets>

class Counter:public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString & contents, QWidget *parent=0):QLineEdit(contents,parent)
    {
        //setReadOnly(true);//не нужно редактирование поля
    }
signals: // раздел сигналов класса
    void tick_signal();
public slots:
    void add_one()
    {
        QString str=text();
        int r=str.toInt();
        if (r!=0 && r%5 ==0) emit tick_signal(); // отправляет сигнал в tick_signal если % 5 == 0
        r++;
        str.setNum(r);
        setText(str);
    }
};

class Win: public QWidget // базовый интерфейс приложения
{
    Q_OBJECT
protected:
    QLabel *label1,*label2;
    Counter *edit1,*edit2;
    QPushButton *calcbutton;
    QPushButton *exitbutton;
public:
    Win(QWidget *parent = 0);
};
#endif

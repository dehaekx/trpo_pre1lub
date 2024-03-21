#include "win.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv); // класс который запускает приложение
    Win win(0);
    win.show(); // отрисовка окна
    return app.exec();
}

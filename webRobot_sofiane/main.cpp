#include "widget.h"
#include "myudp.h"

#include <QCoreApplication>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MaFenetre w;
    w.show();

    return a.exec();
}

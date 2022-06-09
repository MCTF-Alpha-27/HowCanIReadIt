#include "howcanireadit.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HowCanIReadIt w;
    w.show();
    return a.exec();
}

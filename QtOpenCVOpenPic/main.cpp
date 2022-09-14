#include "QtOpenCVOpenPic.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtOpenCVOpenPic w;
    w.show();
    return a.exec();
}

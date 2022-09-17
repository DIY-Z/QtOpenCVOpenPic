#include "QtOpenCVOpenPic.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    //注意:使用 Qt 框架编写带界面的应用程序，main() 函数中必须包含第 7 行和第 11 行代码，否则程序无法正常运行。
    QApplication a(argc, argv);
    //QtOpenCVOpenPic继承自QMainWindow主窗口类,所以QtOpenCVOpenPic也是一个主窗口类,w是它实例化的一个对象,表示一个主窗口
    QtOpenCVOpenPic w;   
    w.show();
    return a.exec();
}

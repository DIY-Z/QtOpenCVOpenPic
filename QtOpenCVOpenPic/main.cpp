#include "QtOpenCVOpenPic.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    //ע��:ʹ�� Qt ��ܱ�д�������Ӧ�ó���main() �����б�������� 7 �к͵� 11 �д��룬��������޷��������С�
    QApplication a(argc, argv);
    //QtOpenCVOpenPic�̳���QMainWindow��������,����QtOpenCVOpenPicҲ��һ����������,w����ʵ������һ������,��ʾһ��������
    QtOpenCVOpenPic w;   
    w.show();
    return a.exec();
}

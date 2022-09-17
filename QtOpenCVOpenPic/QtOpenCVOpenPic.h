#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtOpenCVOpenPic.h"
#include <opencv2/opencv.hpp>
#include "ThreadGetCamPic.h"

//Q_OBJECT：本质是一个已定义好的宏，所有需要“信号和槽”功能的组件都必须将 Q_OBJECT 作为 private 属性成员引入到类中
class QtOpenCVOpenPic : public QMainWindow
{
    Q_OBJECT

public:
    QtOpenCVOpenPic(QWidget *parent = nullptr);
    ~QtOpenCVOpenPic();

    virtual void resizeEvent(QResizeEvent* event);


//槽函数,它是用于对所接收的信号做出响应动作。与信号函数相比,槽函数需要定义(实现),而信号函数只需要声明,不需要定义(实现)
//将某个信号函数和某个槽函数关联起来，需要借助 QObject 类提供的 connect() 函数。
//注意槽函数的参数要和信号函数一致,且参数个数只能比信号函数少或完全一样,而且返回类型必须和信号函数一致
public slots:
    void onOpenPic();
    void onFreshCurImg(const QImage& img);
    void onOpenCamera();

private:
    Ui::QtOpenCVOpenPicClass ui;

    QImage m_imgSrc;
    QImage m_img2Show;
    QPixmap m_pix2Show;
    cv::Mat m_matOpenImage;

    ThreadGetCamPic m_stThreadGetCamPic;
};

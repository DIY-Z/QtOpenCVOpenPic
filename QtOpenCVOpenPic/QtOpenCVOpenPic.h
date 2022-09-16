#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtOpenCVOpenPic.h"
#include <opencv2/opencv.hpp>
#include "ThreadGetCamPic.h"

class QtOpenCVOpenPic : public QMainWindow
{
    Q_OBJECT

public:
    QtOpenCVOpenPic(QWidget *parent = nullptr);
    ~QtOpenCVOpenPic();

    virtual void resizeEvent(QResizeEvent* event);

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

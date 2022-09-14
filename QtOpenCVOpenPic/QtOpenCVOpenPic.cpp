#include "QtOpenCVOpenPic.h"
#include <opencv2/opencv.hpp>
#include <QFileDialog>

QtOpenCVOpenPic::QtOpenCVOpenPic(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    

    //cv::Mat matOpenImage = cv::imread("D:\\ProjectDevelop\\F3Net_1\\F3Net-Learning\\dataset\\train\\fake\\FaceSwap\\209_016\\frame28.jpg");

    //cv::imshow("一张图像", matOpenImage);
    //cv::waitKey(0);

    bool bRet = (bool)connect(ui.pBtnOpenPic, &QPushButton::clicked, this, &QtOpenCVOpenPic::onOpenPic);
}

QtOpenCVOpenPic::~QtOpenCVOpenPic()
{}

void QtOpenCVOpenPic::resizeEvent(QResizeEvent * event)
{
    m_img2Show = m_imgSrc.scaled(ui.labelPicture->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    
    m_pix2Show = QPixmap::fromImage(m_img2Show);

    ui.labelPicture->setPixmap(m_pix2Show);
}



void QtOpenCVOpenPic::onOpenPic()
{
    QString strFileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/", tr("Image Files (*.png *.jpg *.bmp)"));

    if (strFileName.isEmpty()) {
        return;
    }

    //bool bRet = m_imgSrc.load(strFileName);   //使用qt加载图像

    cv::Mat matOpenImage = cv::imread(strFileName.toLocal8Bit().data());   //使用opencv加载图像
    if (matOpenImage.empty()) {
        return;
    }
    //BGR转为RGB
    cvtColor(matOpenImage, matOpenImage, cv::COLOR_BGR2RGB);

    //.copy()是深拷贝
    m_imgSrc = QImage(matOpenImage.data, matOpenImage.cols, matOpenImage.rows, matOpenImage.step, QImage::Format_RGB888).copy();


    m_img2Show = m_imgSrc.scaled(ui.labelPicture->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    m_pix2Show = QPixmap::fromImage(m_img2Show);

    ui.labelPicture->setPixmap(m_pix2Show);
}
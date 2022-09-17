#include "QtOpenCVOpenPic.h"
#include <opencv2/opencv.hpp>
#include <QFileDialog>

QtOpenCVOpenPic::QtOpenCVOpenPic(QWidget *parent)
    : QMainWindow(parent)
    , m_stThreadGetCamPic(this)
{
    ui.setupUi(this);

    

    //cv::Mat matOpenImage = cv::imread("D:\\ProjectDevelop\\F3Net_1\\F3Net-Learning\\dataset\\train\\fake\\FaceSwap\\209_016\\frame28.jpg");

    //cv::imshow("һ��ͼ��", matOpenImage);
    //cv::waitKey(0);

    //�����ֱ�Ϊ:������,�����ߵ�һ���źź���,������,�����ߵ�һ���ۺ���
    bool bRet = (bool)connect(ui.pBtnOpenPic, &QPushButton::clicked, this, &QtOpenCVOpenPic::onOpenPic);

    //��
    connect(&m_stThreadGetCamPic, &ThreadGetCamPic::sigSendCurImg, this, &QtOpenCVOpenPic::onFreshCurImg);
    connect(ui.pBtnOpenCamera, &QPushButton::clicked, this, &QtOpenCVOpenPic::onOpenCamera);

    /*
    cv::VideoCapture stVideoCapture("D:\\FaceForensics++\\original_sequences\\youtube\\c23\\videos\\000.mp4");
    cv::Mat matTemp;
    while (true) {
        stVideoCapture >> matTemp;
        if (matTemp.empty()) continue;

        cv::imshow("Hello", matTemp);
        cv::waitKey(30);
    }
    */
    
}

QtOpenCVOpenPic::~QtOpenCVOpenPic()
{}

void QtOpenCVOpenPic::resizeEvent(QResizeEvent * event)
{
    //FastTransformation��������Ƶ����ʾ��SmoothTransformation������ͼ�����ʾ
    m_img2Show = m_imgSrc.scaled(ui.labelPicture->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    
    m_pix2Show = QPixmap::fromImage(m_img2Show);

    ui.labelPicture->setPixmap(m_pix2Show);
}

void QtOpenCVOpenPic::onFreshCurImg(const QImage& img)
{
    m_imgSrc = img.copy();   //�������Ƶ�е�֡ͼ���������ͷ�ĵ�����Ƶ��ͼ��֡���ô��Ļ�,�����Ƚ����ݴ�

    m_img2Show = m_imgSrc.scaled(ui.labelPicture->size(), Qt::KeepAspectRatio, Qt::FastTransformation);

    m_pix2Show = QPixmap::fromImage(m_img2Show);

    ui.labelPicture->setPixmap(m_pix2Show);
}

void QtOpenCVOpenPic::onOpenCamera()
{
    //��������߳�
    m_stThreadGetCamPic.start();
}



void QtOpenCVOpenPic::onOpenPic()
{

    if (m_stThreadGetCamPic.isRunning())   //����ڵ��"open image"��ťǰ�Ѿ���������ͷ,��ʱ��Ҫ�ر��Ǹ��߳�
    {
        m_stThreadGetCamPic.terminate();
        m_stThreadGetCamPic.wait();
    }

    QString strFileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/", tr("Image Files (*.png *.jpg *.bmp)"));

    if (strFileName.isEmpty()) {
        return;
    }

    //bool bRet = m_imgSrc.load(strFileName);   //ʹ��qt����ͼ��

    m_matOpenImage = cv::imread(strFileName.toLocal8Bit().data());   //ʹ��opencv����ͼ��
    if (m_matOpenImage.empty()) {
        return;
    }
    //BGRתΪRGB
    cvtColor(m_matOpenImage, m_matOpenImage, cv::COLOR_BGR2RGB);

    //.copy()�����,���m_matOpenImage����ʱ����(��m_matOpenImage���������ڽ��������ڸú�����),����Ҫ�����������������.copy(),�����Ϳ��Ա�����ǳ�������µ��ú���ִ�����m_matOpenImage���ͷ�,��������m_imgSrc���õ��ǿ��ڴ�Ҳ���ͷ�
    m_imgSrc = QImage(m_matOpenImage.data, m_matOpenImage.cols, m_matOpenImage.rows, m_matOpenImage.step, QImage::Format_RGB888);


    m_img2Show = m_imgSrc.scaled(ui.labelPicture->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    m_pix2Show = QPixmap::fromImage(m_img2Show);

    ui.labelPicture->setPixmap(m_pix2Show);
}
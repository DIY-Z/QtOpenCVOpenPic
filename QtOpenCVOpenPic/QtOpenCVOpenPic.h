#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtOpenCVOpenPic.h"
#include <opencv2/opencv.hpp>
#include "ThreadGetCamPic.h"

//Q_OBJECT��������һ���Ѷ���õĺ꣬������Ҫ���źźͲۡ����ܵ���������뽫 Q_OBJECT ��Ϊ private ���Գ�Ա���뵽����
class QtOpenCVOpenPic : public QMainWindow
{
    Q_OBJECT

public:
    QtOpenCVOpenPic(QWidget *parent = nullptr);
    ~QtOpenCVOpenPic();

    virtual void resizeEvent(QResizeEvent* event);


//�ۺ���,�������ڶ������յ��ź�������Ӧ���������źź������,�ۺ�����Ҫ����(ʵ��),���źź���ֻ��Ҫ����,����Ҫ����(ʵ��)
//��ĳ���źź�����ĳ���ۺ���������������Ҫ���� QObject ���ṩ�� connect() ������
//ע��ۺ����Ĳ���Ҫ���źź���һ��,�Ҳ�������ֻ�ܱ��źź����ٻ���ȫһ��,���ҷ������ͱ�����źź���һ��
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

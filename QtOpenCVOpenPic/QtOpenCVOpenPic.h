#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtOpenCVOpenPic.h"

class QtOpenCVOpenPic : public QMainWindow
{
    Q_OBJECT

public:
    QtOpenCVOpenPic(QWidget *parent = nullptr);
    ~QtOpenCVOpenPic();

    virtual void resizeEvent(QResizeEvent* event);

public slots:
    void onOpenPic();

private:
    Ui::QtOpenCVOpenPicClass ui;

    QImage m_imgSrc;
    QImage m_img2Show;
    QPixmap m_pix2Show;
};

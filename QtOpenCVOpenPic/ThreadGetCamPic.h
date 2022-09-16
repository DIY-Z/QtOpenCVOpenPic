#pragma once

#include <QThread>
#include <opencv2/opencv.hpp>
#include <QMutex>

class ThreadGetCamPic  : public QThread
{
	Q_OBJECT

public:
	ThreadGetCamPic(QObject *parent);
	~ThreadGetCamPic();

	void run();

signals:
	void sigSendCurImg(const QImage& img);

private:
	bool m_bStop = true;
	QMutex m_mux;
};

#include "GObjectTester.h"
#include "GObject.h"
#include "GObjectFactory.h"
#include "QtPainter.h"
#include "QtGObjectFactory.h"

#include <qpainter.h>

GObjectTester::GObjectTester(QFrame *parent)
	: QFrame(parent)
{
	ui.setupUi(this);

	QRect frameRect = this->frameRect();

	this->painter = new QtPainter(frameRect.width(), frameRect.height());
}

void GObjectTester::closeEvent(QCloseEvent *event) {
	if (this->painter != NULL) {
		delete this->painter;
	}
}

void GObjectTester::paintEvent(QPaintEvent *event) {
	QPainter painter(this);

	this->painter->SetRenderHints(QPainter::Antialiasing);
	QtGObjectFactory factory;
	//=================�� ����================
	GObject *pen = factory.MakePen(QBrush(QColor(255, 0, 0)), 5, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin);
	GObject *oldPen = this->painter->SelectObject(*pen);
	this->painter->Update();
	//=================�� ����================

	//=================ȣ=====================
	QRectF rectF(10.0, 10.0, 100.0, 100.0);
	this->painter->DrawArc(rectF, 60, 180);
	
	QRect rect(10, 110, 100, 100);
	this->painter->DrawArc(rect, 30, 120);
	//=================ȣ=====================

	//=================�� ����================
	this->painter->SelectObject(*oldPen);
	this->painter->Update();
	if (pen != NULL) {
		delete pen;
	}
	//=================�� ����================

	//=================�귯�� ����================
	GObject *brush = factory.MakeBrush(QColor(255, 0, 0), Qt::SolidPattern);
	GObject *oldBrush = this->painter->SelectObject(*brush);
	this->painter->Update();
	//=================�귯�� ����================

	//=================��=====================
	rectF = QRectF(110.0, 10.0, 100.0, 100.0);
	this->painter->DrawChord(rectF, 60, 180);

	rect = QRect(110, 110, 100, 100);
	this->painter->DrawChord(rect, 30, 120);
	//=================��=====================

	//=================�귯�� ����================
	this->painter->SelectObject(*oldBrush);
	this->painter->Update();
	if (brush != NULL) {
		delete brush;
	}
	//=================�귯�� ����================

	//���ϴٰ���
	Long pointCount = 5;
	QPointF(*points) = new QPointF[pointCount];
	points[0] = QPointF(210.0, 10.0);
	points[1] = QPointF(310.0, 30.0);
	points[2] = QPointF(300.0, 100.0);
	points[3] = QPointF(250.0, 100.0);
	points[4] = QPointF(220.0, 70.0);
	this->painter->DrawConvexPolygon(points, pointCount);
	if (points != NULL) {
		delete points;
	}
	//Ÿ��
	//�̹���
	//��
	//������ ����
	//����
	//��
	//�ٰ���
	pointCount = 5;
	points = new QPointF[pointCount];
	points[0] = QPointF(330.0, 10.0);
	points[1] = QPointF(430.0, 30.0);
	points[2] = QPointF(420.0, 100.0);
	points[3] = QPointF(370.0, 100.0);
	points[4] = QPointF(340.0, 70.0);
	this->painter->DrawPolygon(points, pointCount);
	if (points != NULL) {
		delete points;
	}
	//��������
	//�簢��
	//�ձ� �簢��
	//�ؽ�Ʈ
	//���� �����
	//������ ���� ĥ�ϱ�
	//�簢�� ���� ĥ�ϱ�

	this->painter->Render(&painter, 0, 0);
}

void GObjectTester::resizeEvent(QResizeEvent *event) {
	QRect frameRect = this->frameRect();
	if (this->painter != NULL) {
		this->painter->Resize(frameRect.width(), frameRect.height());
	}
}
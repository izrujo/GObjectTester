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

	this->setWindowState(Qt::WindowMaximized);
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
	GObject *pen;
	GObject *oldPen;
	GObject *brush;
	GObject *oldBrush;
	GObject *font;
	GObject *oldFont;
	QRectF rectF;
	QRectF rectF2;
	QRect rect;
	QRect rect2;
	Long pointCount;
	QPointF(*pointsF);
	QPointF(*pointsF2);
	QPoint(*points);
	QPoint(*points2);
	QPointF pointF;
	QPointF pointF2;
	QPoint point;
	QPoint point2;
	Long lineCount;

	//=================�� ����================
	pen = factory.MakePen(QBrush(QColor(255, 0, 0)), 5, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin);
	oldPen = this->painter->SelectObject(*pen);
	this->painter->Update();
	//=================�� ����================

	//=================ȣ=====================
	rectF = QRectF(10.0, 10.0, 100.0, 100.0);
	this->painter->DrawArc(rectF, 60, 180);

	rect = QRect(10, 110, 100, 100);
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
	brush = factory.MakeBrush(QColor(255, 0, 0), Qt::SolidPattern);
	oldBrush = this->painter->SelectObject(*brush);
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

	//=================���ϴٰ���=================
	pointCount = 5;
	pointsF = new QPointF[pointCount];
	pointsF[0] = QPointF(210.0, 10.0);
	pointsF[1] = QPointF(310.0, 30.0);
	pointsF[2] = QPointF(300.0, 100.0);
	pointsF[3] = QPointF(250.0, 100.0);
	pointsF[4] = QPointF(220.0, 70.0);
	this->painter->DrawConvexPolygon(pointsF, pointCount);
	if (pointsF != NULL) {
		delete pointsF;
	}
	//=================���ϴٰ���=================

	//=================Ÿ��=======================
	rectF = QRectF(10.0, 210.0, 100.0, 100.0);
	this->painter->DrawEllipse(rectF);

	rect = QRect(110, 210, 100, 100);
	this->painter->DrawEllipse(rect);

	pointF = QPointF(260.0, 260.0);
	this->painter->DrawEllipse(pointF, 50.0, 50.0);

	point = QPoint(360, 260);
	this->painter->DrawEllipse(point, 50, 50);
	//=================Ÿ��=======================

	//=================�̹���=====================
	rectF = QRectF(10.0, 320.0, 300.0, 300.0);
	rectF2 = QRectF(0.0, 0.0, 300.0, 300.0);
	this->painter->DrawImage(rectF, QString::fromLocal8Bit("C:/Users/kch79/OneDrive/���� ȭ��/��Ÿ ���� �ڷ�/������/ver3/icon ver.3.bmp"), rectF2, Qt::AutoColor);

	rect = QRect(320, 320, 300, 300);
	rect2 = QRect(0, 0, 300, 300);
	this->painter->DrawImage(rect, QString::fromLocal8Bit("C:/Users/kch79/OneDrive/���� ȭ��/��Ÿ ���� �ڷ�/������/ver3/icon ver.3.bmp"), rect2, Qt::AutoColor);
	//=================�̹���=====================

	//=================�� ����================
	pen = factory.MakePen(QBrush(QColor(0, 0, 255)), 3, Qt::DashLine, Qt::RoundCap, Qt::BevelJoin);
	oldPen = this->painter->SelectObject(*pen);
	this->painter->Update();
	//=================�� ����================

	//=================��=========================
	pointF = QPointF(10.5, 400.5);
	pointF2 = QPointF(300.5, 450.5);
	this->painter->DrawLine(pointF, pointF2);

	point = QPoint(10, 410);
	point2 = QPoint(300, 460);
	this->painter->DrawLine(point, point2);

	lineCount = 3;
	pointsF = new QPointF[lineCount];
	pointsF[0] = QPointF(310.0, 400.0);
	pointsF[1] = QPointF(345.3553, 364.0);
	pointsF[2] = QPointF(380.0, 400.0);
	pointsF2 = new QPointF[lineCount];
	pointsF2[0] = QPointF(380.7106, 450.0);
	pointsF2[1] = QPointF(345.3553, 464.6447);
	pointsF2[2] = QPointF(310.0, 450.0);
	this->painter->DrawLines(pointsF, pointsF2, lineCount);
	if (pointsF != NULL) {
		delete pointsF;
	}
	if (pointsF2 != NULL) {
		delete pointsF2;
	}

	lineCount = 4;
	points = new QPoint[lineCount];
	points[0] = QPoint(400, 400);
	points[1] = QPoint(650, 350);
	points[2] = QPoint(700, 600);
	points[3] = QPoint(450, 650);
	points2 = new QPoint[lineCount];
	points2[0] = QPoint(650, 400);
	points2[1] = QPoint(650, 600);
	points2[2] = QPoint(450, 600);
	points2[3] = QPoint(450, 400);
	this->painter->DrawLines(points, points2, lineCount);

	if (points != NULL) {
		delete points;
	}
	if (points2 != NULL) {
		delete points2;
	}
	//=================��=========================

	//=================�� ����================
	this->painter->SelectObject(*oldPen);
	this->painter->Update();
	if (pen != NULL) {
		delete pen;
	}
	//=================�� ����================


	//********************������ - ��� ��ȣ �׸���***************************
	//////////////////////////////////////////////////////////////////////////

	//=================�귯�� ����================
	brush = factory.MakeBrush(QColor(255, 255, 0), Qt::SolidPattern);
	oldBrush = this->painter->SelectObject(*brush);
	this->painter->Update();
	//=================�귯�� ����================

	//=================�簢�� ���� ĥ�ϱ�=========
	rectF = QRectF(500.0, 10.0, 200.0, 100.0);
	this->painter->FillRect(rectF, *brush);
	//=================�簢�� ���� ĥ�ϱ�=========

	//=================��=========================
	lineCount = 3;
	pointsF = new QPointF[lineCount];
	pointsF[0] = QPointF(500.0, 10.0);
	pointsF[1] = QPointF(700.0, 10.0);
	pointsF[2] = QPointF(500.0, 10.0);
	pointsF2 = new QPointF[lineCount];
	pointsF2[0] = QPointF(700.0, 10.0);
	pointsF2[1] = QPointF(700.0, 110.0);
	pointsF2[2] = QPointF(500.0, 110.0);
	this->painter->DrawLines(pointsF, pointsF2, lineCount);
	if (pointsF != NULL) {
		delete pointsF;
	}
	if (pointsF2 != NULL) {
		delete pointsF2;
	}
	//=================��=========================

	//=================������ ����================
	QPointF start(500.0, 110.0);
	QPointF end(600.0, 110.0);
	QPointF c1(537.0, 130.0);
	QPointF c2(563.0, 130.0);
	this->painter->DrawPath(start, end, c1, c2);
	//=================������ ����================

	//=================�귯�� ����================
	this->painter->SelectObject(*oldBrush);
	this->painter->Update();
	if (brush != NULL) {
		delete brush;
	}
	//=================�귯�� ����================

	//=================�귯�� ����================
	brush = factory.MakeBrush(QColor(235, 235, 235), Qt::SolidPattern);
	oldBrush = this->painter->SelectObject(*brush);
	this->painter->Update();
	//=================�귯�� ����================

	//=================������ ����================
	start = QPointF(600.0, 110.0);
	end = QPointF(700.0, 110.0);
	c1 = QPointF(637.0, 90.0);
	c2 = QPointF(663.0, 90.0);
	this->painter->DrawPath(start, end, c1, c2);
	//=================������ ����================

	//=================�귯�� ����================
	this->painter->SelectObject(*oldBrush);
	this->painter->Update();
	if (brush != NULL) {
		delete brush;
	}
	//=================�귯�� ����================

	//////////////////////////////////////////////////////////////////////////
	//********************������ - ��� ��ȣ �׸���***************************

	//********************������ - �ܸ� ��ȣ �׸���***************************
	//////////////////////////////////////////////////////////////////////////

	//=================�� ����================
	pen = factory.MakePen(QBrush(QColor(0, 0, 0)), 5, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin);
	oldPen = this->painter->SelectObject(*pen);
	this->painter->Update();
	//=================�� ����================

	//=================�귯�� ����================
	brush = factory.MakeBrush(QColor(255, 153, 153), Qt::SolidPattern);
	oldBrush = this->painter->SelectObject(*brush);
	this->painter->Update();
	//=================�귯�� ����================

	//=================�ձ� �簢��================
	rectF = QRectF(800.0, 10.0, 300.0, 100.0);
	this->painter->DrawRoundedRect(rectF, 50.0, 50.0);
	//=================�ձ� �簢��================

	//=================�귯�� ����================
	this->painter->SelectObject(*oldBrush);
	this->painter->Update();
	if (brush != NULL) {
		delete brush;
	}
	//=================�귯�� ����================

	//=================�� ����================
	this->painter->SelectObject(*oldPen);
	this->painter->Update();
	if (pen != NULL) {
		delete pen;
	}
	//=================�� ����================

	//////////////////////////////////////////////////////////////////////////
	//********************������ - �ܸ� ��ȣ �׸���***************************

	//=================����=======================
	//=================����=======================

	//=================��=========================
	//=================��=========================

	//=================�귯�� ����================
	brush = factory.MakeBrush(QColor(0, 255, 0), Qt::SolidPattern);
	oldBrush = this->painter->SelectObject(*brush);
	this->painter->Update();
	//=================�귯�� ����================

	//=================�ٰ���=====================
	//ConvexPolygon�� ������ �ٸ��� �𸣰���.
	pointCount = 5;
	pointsF = new QPointF[pointCount];
	pointsF[0] = QPointF(330.0, 10.0);
	pointsF[1] = QPointF(430.0, 30.0);
	pointsF[2] = QPointF(420.0, 100.0);
	pointsF[3] = QPointF(370.0, 100.0);
	pointsF[4] = QPointF(340.0, 70.0);
	this->painter->DrawPolygon(pointsF, pointCount);
	if (pointsF != NULL) {
		delete pointsF;
	}
	//=================�ٰ���=====================

	//=================�귯�� ����================
	this->painter->SelectObject(*oldBrush);
	this->painter->Update();
	if (brush != NULL) {
		delete brush;
	}
	//=================�귯�� ����================

	//=================��������===================
	//=================��������===================

	//=================�簢��=====================
	//=================�簢��=====================

	//=================�ձ� �簢��================
	//=================�ձ� �簢��================

	//=================�ؽ�Ʈ=====================
	//=================�ؽ�Ʈ=====================

	//=================���� �����================
	//=================���� �����================

	//=================������ ���� ĥ�ϱ�=========
	//=================������ ���� ĥ�ϱ�=========	

	this->painter->Render(&painter, 0, 0);
}

void GObjectTester::resizeEvent(QResizeEvent *event) {
	QRect frameRect = this->frameRect();
	if (this->painter != NULL) {
		this->painter->Resize(frameRect.width(), frameRect.height());
	}
}
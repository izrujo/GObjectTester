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
	//=================펜 설정================
	GObject *pen = factory.MakePen(QBrush(QColor(255, 0, 0)), 5, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin);
	GObject *oldPen = this->painter->SelectObject(*pen);
	this->painter->Update();
	//=================펜 설정================

	//=================호=====================
	QRectF rectF(10.0, 10.0, 100.0, 100.0);
	this->painter->DrawArc(rectF, 60, 180);
	
	QRect rect(10, 110, 100, 100);
	this->painter->DrawArc(rect, 30, 120);
	//=================호=====================

	//=================펜 해제================
	this->painter->SelectObject(*oldPen);
	this->painter->Update();
	if (pen != NULL) {
		delete pen;
	}
	//=================펜 해제================

	//=================브러쉬 설정================
	GObject *brush = factory.MakeBrush(QColor(255, 0, 0), Qt::SolidPattern);
	GObject *oldBrush = this->painter->SelectObject(*brush);
	this->painter->Update();
	//=================브러쉬 설정================

	//=================현=====================
	rectF = QRectF(110.0, 10.0, 100.0, 100.0);
	this->painter->DrawChord(rectF, 60, 180);

	rect = QRect(110, 110, 100, 100);
	this->painter->DrawChord(rect, 30, 120);
	//=================현=====================

	//=================브러쉬 해제================
	this->painter->SelectObject(*oldBrush);
	this->painter->Update();
	if (brush != NULL) {
		delete brush;
	}
	//=================브러쉬 해제================

	//볼록다각형
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
	//타원
	//이미지
	//선
	//자유형 도형
	//파이
	//점
	//다각형
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
	//폴리라인
	//사각형
	//둥근 사각형
	//텍스트
	//범위 지우기
	//자유형 범위 칠하기
	//사각형 범위 칠하기

	this->painter->Render(&painter, 0, 0);
}

void GObjectTester::resizeEvent(QResizeEvent *event) {
	QRect frameRect = this->frameRect();
	if (this->painter != NULL) {
		this->painter->Resize(frameRect.width(), frameRect.height());
	}
}
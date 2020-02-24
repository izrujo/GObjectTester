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
	GObject *pen;
	GObject *oldPen;
	GObject *brush;
	GObject *oldBrush;
	GObject *font;
	GObject *oldFont;
	QRectF rectF;
	QRect rect;
	Long pointCount;
	QPointF(*pointsF);
	QPoint(*points);

	//=================펜 설정================
	pen = factory.MakePen(QBrush(QColor(255, 0, 0)), 5, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin);
	oldPen = this->painter->SelectObject(*pen);
	this->painter->Update();
	//=================펜 설정================

	//=================호=====================
	rectF = QRectF(10.0, 10.0, 100.0, 100.0);
	this->painter->DrawArc(rectF, 60, 180);
	
	rect = QRect(10, 110, 100, 100);
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
	brush = factory.MakeBrush(QColor(255, 0, 0), Qt::SolidPattern);
	oldBrush = this->painter->SelectObject(*brush);
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

	//=================볼록다각형=================
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
	//=================볼록다각형=================

	//=================타원=======================
	rectF = QRectF(10.0, 210.0, 100.0, 100.0);
	this->painter->DrawEllipse(rectF);

	rect = QRect(110, 210, 100, 100);
	this->painter->DrawEllipse(rect);

	QPointF centerF(260.0, 260.0);
	this->painter->DrawEllipse(centerF, 50.0, 50.0);

	QPoint center(360, 260);
	this->painter->DrawEllipse(center, 50, 50);
	//=================타원=======================

	//=================이미지=====================
	QRectF targetF(10.0, 320.0, 300.0, 300.0);
	QRectF sourceF(0.0, 0.0, 300.0, 300.0);
	this->painter->DrawImage(targetF, QString::fromLocal8Bit("C:/Users/kch79/OneDrive/바탕 화면/기타 개발 자료/아이콘/ver3/icon ver.3.bmp"), sourceF, Qt::AutoColor);

	QRect target(320, 320, 300, 300);
	QRectF source(0, 0, 300, 300);
	this->painter->DrawImage(target, QString::fromLocal8Bit("C:/Users/kch79/OneDrive/바탕 화면/기타 개발 자료/아이콘/ver3/icon ver.3.bmp"), source, Qt::AutoColor);
	//=================이미지=====================
	
	//=================펜 설정================
	pen = factory.MakePen(QBrush(QColor(0, 0, 255)), 5, Qt::DashLine, Qt::RoundCap, Qt::BevelJoin);
	oldPen = this->painter->SelectObject(*pen);
	this->painter->Update();
	//=================펜 설정================

	//=================선=========================

	//=================선=========================

	//=================펜 해제================
	this->painter->SelectObject(*oldPen);
	this->painter->Update();
	if (pen != NULL) {
		delete pen;
	}
	//=================펜 해제================

	//=================자유형 도형================
	//=================자유형 도형================
	
	//=================파이=======================
	//=================파이=======================
	
	//=================점=========================
	//=================점=========================

	//=================브러쉬 설정================
	brush = factory.MakeBrush(QColor(0, 255, 0), Qt::SolidPattern);
	oldBrush = this->painter->SelectObject(*brush);
	this->painter->Update();
	//=================브러쉬 설정================

	//=================다각형=====================
	//ConvexPolygon과 무엇이 다른지 모르겠음.
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
	//=================다각형=====================

	//=================브러쉬 해제================
	this->painter->SelectObject(*oldBrush);
	this->painter->Update();
	if (brush != NULL) {
		delete brush;
	}
	//=================브러쉬 해제================

	//=================폴리라인===================
	//=================폴리라인===================

	//=================사각형=====================
	//=================사각형=====================
	
	//=================둥근 사각형================
	//=================둥근 사각형================
	
	//=================텍스트=====================
	//=================텍스트=====================
	
	//=================범위 지우기================
	//=================범위 지우기================
	
	//=================자유형 범위 칠하기=========
	//=================자유형 범위 칠하기=========
	
	//=================사각형 범위 칠하기=========
	//=================사각형 범위 칠하기=========

	this->painter->Render(&painter, 0, 0);
}

void GObjectTester::resizeEvent(QResizeEvent *event) {
	QRect frameRect = this->frameRect();
	if (this->painter != NULL) {
		this->painter->Resize(frameRect.width(), frameRect.height());
	}
}
﻿#pragma once

#define _USE_MATH_DEFINES

#include <math.h>

#include <QtWidgets/QMainWindow>
#include <QgsMapCanvas.h>
#include <QgsProject.h>
#include <QgsAttributeTableView.h>
#include <QgsAttributeTableFilterModel.h>
#include <QTreeView>
#include <QModelIndex>
#include "GPSTreeModel.h"

#include "ui_SimpleGIS.h"

class SimpleGIS : public QMainWindow
{
	Q_OBJECT

public:
	SimpleGIS(QWidget* parent = Q_NULLPTR);

public slots:
	void addVectorLayer();			// 添加矢量图层
	void addRasterFile();
	void ZoomIn();					// 放大
	void ZoomOut();					// 缩小
	void Pan();						// 移动
	void FullExtent();				// 缩放到图层范围
	void Identify();
	void FlashFeature(QgsFeatureId);
	void ZoomToFeature();
	void OpenOverView();
	void CreateDoc();
	void SaveDoc();
	void SaveAsDoc();
	void OpenDoc();
	void LayerManage();
	void Catalog();
	void AttShow();
	void AttShowQGIS();
	void AttShowMy();

	void SpaQuery();
	void SpaPolygonQuery();
	void SpaFreeHandQuery();
	void SpaSimpleQuery();

	void LoadGPSData();
	void GPSCatalog();
	void TreeViewMenu(const QPoint& p);
	void RequestGPS();
	void ShowVelocity();


	void FeatureEdit();
	void AddFeature(const QgsFeature& f);

	void Help();

private:
	Ui::SimpleGISClass ui;

	QgsMapCanvas* mapCanvas;
	QgsProject* mapProject;

	QString currentFileName = NULL;
	int status = 1;	// 1、初始mapProject为空状态，2、被修改为保存，3、已保存

	QgsAttributeTableView* m_tv;
	QgsAttributeTableFilterModel* m_tfm = NULL;

	QTreeView* m_treeView;
	GPSTreeModel* m_treeModel;
	QModelIndex m_index;
};

#include "ui_AttQuery.h"
class MyAttQuery :public QWidget, public Ui::Form
{
	Q_OBJECT
public:
	MyAttQuery(QgsMapCanvas* mapCanvas) :mapCanvas(mapCanvas) {
		setupUi(this);
		connect(pushButton_2, &QPushButton::clicked, this, &MyAttQuery::DoQuery);
		connect(pushButton, &QPushButton::clicked, this, &MyAttQuery::BuildQuery);
	}

private slots:
	void DoQuery();
private slots:
	void BuildQuery();
private:
	QgsMapCanvas* mapCanvas;
public:
	QgsAttributeTableFilterModel* mFilterModel;
};

#pragma once
#include "Service.h"
#include <QAbstractListModel>

class QuestionModel:public QAbstractListModel
{
private:
	Service& service;
public:
	QuestionModel(Service& service);
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	void emitSigal();
};


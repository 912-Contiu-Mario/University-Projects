#include "ListModel.h"

QuestionModel::QuestionModel(Service& service):service{service}
{
}
int QuestionModel::rowCount(const QModelIndex& parent) const
{
    return this->service.getRepo().getQuestions().size();
}
QVariant QuestionModel::data(const QModelIndex& index, int role) const
{
    int index1 = index.row();
    Question question = this->service.getRepo().getQuestions()[index1];
    if (role == Qt::DisplayRole)
    {
        return QString::fromStdString(question.toString());
    }
    return QVariant();
}

void QuestionModel::emitSigal()
{
    emit dataChanged(this->index(0, 0), this->index(0,service.getRepo().getAnswers().size()));
}


#ifndef EXAMMODEL_H
#define EXAMMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QList>
#include <QuestionModel.h>

class ExamModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ExamModel(QObject *parent = nullptr);
    void init();
    int rowCount(const QModelIndex &index) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int,QByteArray> roleNames() const override;
    Q_INVOKABLE QuestionModel *getQues(int index);
private:
    QuestionModel *m_subject;
    QList<QuestionModel*> m_subjectList;
};

#endif // EXAMMODEL_H

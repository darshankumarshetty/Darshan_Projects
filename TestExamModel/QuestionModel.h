#ifndef QUESTIONMODEL_H
#define QUESTIONMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QList>
#include <QDebug>
#include <Question.h>
class QuestionModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit QuestionModel(QObject *parent = nullptr);
    void init();
    int rowCount(const QModelIndex &index) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int,QByteArray> roleNames() const;

    //    Q_INVOKABLE Question* getQuesn(int index);

    Q_INVOKABLE QString userAns(int index,QString str);
    Q_INVOKABLE int right() const;

    Q_INVOKABLE  int wrong() const;

    const QString &subName() const;
    void setSubName(const QString &newSubName);

private:
    QList<Question*> m_qun;
    int m_right,m_wrong;
    QString m_subName;
};

#endif // QUESTIONMODEL_H

#include "ExamModel.h"

ExamModel::ExamModel(QObject *parent)
    : QAbstractListModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    init();
}

void ExamModel::init()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    for(int i=0;i<6;i++){
        m_subject = new QuestionModel;
        if(i==0){
            m_subject->setSubName("Kannada");
        }else if(i==1){
            m_subject->setSubName("English");
        }
        else if(i==2){
            m_subject->setSubName("Hindi");
        }
        else if(i==3){
            m_subject->setSubName("Science");
        }
        else if(i==4){
            m_subject->setSubName("Mathematics");
        }
        else if(i==5){
            m_subject->setSubName("Social_Science");
        }
        m_subjectList.append(m_subject);
    }
}

int ExamModel::rowCount(const QModelIndex &index) const
{
    return m_subjectList.size();
}

QVariant ExamModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    QuestionModel *ti = m_subjectList.at(row);
    switch (role) {
    case 10:return ti->subName();break;
    }
}

QHash<int, QByteArray> ExamModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[10] = "subject";
    return roles;
}

QuestionModel *ExamModel::getQues(int index)
{
    QuestionModel *qm = m_subjectList.at(index);
    return qm;
}

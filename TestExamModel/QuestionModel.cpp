#include "QuestionModel.h"

QuestionModel::QuestionModel(QObject *parent)
    : QAbstractListModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    init();
}

void QuestionModel::init()
{
    m_right=0;
    m_wrong=0;
    for(int i=0;i<30;i++){
        Question *mt = new Question;
        mt->setQuestions("Question"+QString::number(i+1));
        if(i<10){
            mt->setAnswer("A");
        }
        else if(i<20&&i>10){
            mt->setAnswer("B");
        }
        else if(i<25&&i>20){
            mt->setAnswer("C");
        }
        else {
            mt->setAnswer("D");
        }
        mt->setOption1("A");
        mt->setOption2("B");
        mt->setOption3("C");
        mt->setOption4("D");
        this->m_qun.append(mt);
    }
}
int QuestionModel::rowCount(const QModelIndex &index) const
{
    return m_qun.size();
}

QVariant QuestionModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    Question *ti = m_qun.at(row);
    switch (role) {
    case 10:return ti->questions();break;
    case 12:return ti->answer();break;
    case 03:return ti->option1();break;
    case 01:return ti->option2();break;
    case 20:return ti->option3();break;
    case 18:return ti->option4();break;
    //    case 25:return ti->userSelected();break;
    }
}

QHash<int, QByteArray> QuestionModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[10] = "questions";
    roles[12] = "answer";
    roles[03] = "option1";
    roles[01] = "option2";
    roles[20] = "option3";
    roles[18] = "option4";
    roles[25] = "userSelected";
    return roles;
}

//Question *QuestionModel::getQuesn(int index)
//{
//    Question *qs = m_qun.at(index);
//    return qs;
//}

QString QuestionModel::userAns(int index, QString str)
{
    Question *qu = m_qun.at(index);
    qDebug()<<Q_FUNC_INFO<<qu->answer()<<Qt::endl;
    qu->setUserSelected(str);
    if(qu->answer().compare(str)==0){
        m_right++;
    }
    else{
        m_wrong++;
    }
    qDebug()<<index+1<<str<<Qt::endl;
    qDebug()<<"Correct Answer"<<qu->answer()<<Qt::endl;
    return str;
}

int QuestionModel::right() const
{
    return m_right;
}

int QuestionModel::wrong() const
{
    return m_wrong;
}

const QString &QuestionModel::subName() const
{
    return m_subName;
}

void QuestionModel::setSubName(const QString &newSubName)
{
    m_subName = newSubName;
}

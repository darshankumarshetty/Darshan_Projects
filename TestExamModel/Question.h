#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>

class Question : public QObject
{
    Q_OBJECT
public:
    explicit Question(QObject *parent = nullptr);

    const QString &questions() const;
    void setQuestions(const QString &newQuestions);

    const QString &answer() const;
    void setAnswer(const QString &newAnswer);

    const QString &option1() const;
    void setOption1(const QString &newOption1);

    const QString &option2() const;
    void setOption2(const QString &newOption2);

    const QString &option3() const;
    void setOption3(const QString &newOption3);

    const QString &option4() const;
    void setOption4(const QString &newOption4);

    const QString &userSelected() const;
    void setUserSelected(const QString &newUserSelected);

signals:

private:
    QString m_questions;
    QString m_answer;
    QString m_option1;
    QString m_option2;
    QString m_option3;
    QString m_option4;
    QString m_userSelected;

};

#endif // QUESTION_H

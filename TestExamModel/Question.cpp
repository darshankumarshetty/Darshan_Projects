#include "Question.h"

Question::Question(QObject *parent)
    : QObject{parent}
{

}

const QString &Question::questions() const
{
    return m_questions;
}

void Question::setQuestions(const QString &newQuestions)
{
    m_questions = newQuestions;
}

const QString &Question::answer() const
{
    return m_answer;
}

void Question::setAnswer(const QString &newAnswer)
{
    m_answer = newAnswer;
}

const QString &Question::option1() const
{
    return m_option1;
}

void Question::setOption1(const QString &newOption1)
{
    m_option1 = newOption1;
}

const QString &Question::option2() const
{
    return m_option2;
}

void Question::setOption2(const QString &newOption2)
{
    m_option2 = newOption2;
}

const QString &Question::option3() const
{
    return m_option3;
}

void Question::setOption3(const QString &newOption3)
{
    m_option3 = newOption3;
}

const QString &Question::option4() const
{
    return m_option4;
}

void Question::setOption4(const QString &newOption4)
{
    m_option4 = newOption4;
}

const QString &Question::userSelected() const
{
    return m_userSelected;
}

void Question::setUserSelected(const QString &newUserSelected)
{
    m_userSelected = newUserSelected;
}

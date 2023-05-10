#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;
#include <QString>
#include <QVector>
#include <QMap>
#include <algorithm>
#include "person.h"
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<QMessageBox>
#include<QComboBox>

class Class ;

class Student : public Person
{
private:
    QVector <Class*> studentClasses;
    QVector <QString> studentGrades;
   QMap <Class* , QString> studentClassesGrades;
public:
    Student();
    Student(QString n1, QString n2, QString a, QString e, QString m);
    void addClassToStudent (Class* c);
    QString getClassGrades (Class* c);
    QVector <Class*> getStudentClass (Student* s);
    QVector <QString> getStudentGrades (Student* s);

    void setGradeOfStudent (Class* c , QString g);

};

#endif // STUDENT_H

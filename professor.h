#ifndef PROFESSOR_H
#define PROFESSOR_H
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

class Professor : public Person
{
private:
    QString title;
    //QVector<QString> classesNames;
    QVector<Class*> professorClasses;

public:
    Professor();
    Professor(QString n1, QString n2, QString a, QString e, QString m, QString t);
    void setTitle(QString t);
    QString getTitle();
    void addClassToProfessor(Class* c);
    Class* getProfessorClass1 ();
    Class* getProfessorClass2 ();

    //void addClassName(QString c);
   // QString getClass1();
   // QString getClass2();
};

#endif // PROFESSOR_H

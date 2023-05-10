#ifndef CLASS_H
#define CLASS_H
#include <iostream>
using namespace std;
#include <QString>
#include <QVector>
#include <QMap>
#include <algorithm>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<QMessageBox>
#include<QComboBox>
class Student;
class Professor;
class Class {

private:
    QString ClassName;
    QString LectureHall;
    QString ClassCode;
    QString time;
    QMap<Student*,QString> assignedStudents;
    QVector<Professor*> assignedProfessors;



public:
    Class();
    Class(QString n,QString l,QString c,QString t);
    void setClassName(QString n);
    QString getClassname();
    void setLecHall(QString l);
    QString getLecHall();
    void setClassCode(QString c);
    QString getClassCode();
    void setClassTime(QString t);
    QString getClassTime();
    void addStudentToClass(Student* std , QString g);
    void addProfessor(Professor* pro);
    void setStudentGrade (Student* stud,QString g);
    QMap<Student*,QString> getMap();
    QVector<Professor*> getProf();

};

#endif // CLASS_H

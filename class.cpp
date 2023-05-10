#include "class.h"
#include<QString>
Class::Class() {
    ClassName="Unknown";
    LectureHall="Unknown";
    ClassCode="Unknown";
    time="Unknown";

}

Class::Class(QString n, QString l, QString c, QString t) {
    ClassName=n;
    LectureHall=l;
    ClassCode=c;
    time=t;
}

QString Class::getClassname() {
    return ClassName;
}

void Class::setLecHall(QString l) {
    LectureHall=l;

}

QString Class::getLecHall() {
    return LectureHall;
}

void Class::setClassCode(QString c) {
    ClassCode=c;

}

void Class::setClassName(QString n) {
ClassName = n;
}

QString Class::getClassCode() {
    return ClassCode;
}

void Class::setClassTime(QString t){
    time = t;
}
QString Class::getClassTime() {
    return time;
}
void Class::addStudentToClass(Student* std , QString g) {
    assignedStudents.insert(std , g);

}

void Class::addProfessor(Professor *pro) {
    assignedProfessors.push_back(pro);

}
void Class ::setStudentGrade (Student* stud,QString g)
{
    assignedStudents[stud]=g;
}

QMap<Student*, QString> Class:: getMap()
{
    return assignedStudents;
}

QVector<Professor*> Class:: getProf()
{
    return assignedProfessors;
}



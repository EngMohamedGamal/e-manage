#include "professor.h"
#include <iostream>
using namespace std;
#include<QString>

Professor::Professor()
{}

Professor::Professor(QString n1, QString n2, QString a, QString e, QString m, QString t) : Person(n1, n2, a, e, m)
{
    title = t ;
}

void Professor::setTitle(QString t)
{
    title = t;
}

QString Professor::getTitle()
{
    return title;
}

void Professor::addClassToProfessor(Class *c) {
    professorClasses.push_back(c);
}

Class* Professor :: getProfessorClass1 (){
    return professorClasses[0];
}
Class* Professor :: getProfessorClass2 (){
    return professorClasses[1];
}

/*void Professor::addClassName(QString c){
    classesNames.push_back(c);
}

QString Professor::getClass1(){
    return classesNames[0];
}

QString Professor::getClass2(){
    return classesNames[1];
}*/

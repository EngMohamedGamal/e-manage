#include <iostream>
using namespace std;
#include<QString>
#include"student.h"
#include<QChar>
Student::Student()
{}

Student::Student(QString n1, QString n2, QString a, QString e, QString m) : Person(n1,n2,a,e,m)
{
}

void Student::addClassToStudent(Class* c) {
    studentClassesGrades.insert(c,"unknown");
   // studentClasses.push_back(c);
}
QString Student::getClassGrades (Class* c){

    return studentClassesGrades[c];
}

QVector<Class *> Student::getStudentClass(Student *s)
  {

      QMap<Class*,QString>::Iterator it2 ;
        for (it2=studentClassesGrades.begin();it2!=studentClassesGrades.end();it2++)
            studentClasses.push_back(it2.key());
        return studentClasses;
  }

QVector <QString>Student:: getStudentGrades (Student* s)
  {
      QMap<Class*,QString>::Iterator it2 ;
        for (it2=studentClassesGrades.begin();it2!=studentClassesGrades.end();it2++)
            studentGrades.push_back(it2.value());
        return studentGrades;
  }

void Student:: setGradeOfStudent (Class* c , QString g)
  {
         studentClassesGrades[c]=g;


      /* QMap<Class*,QString>::Iterator it2 ;
        for (it2=studentClassesGrades.begin();it2!=studentClassesGrades.end();it2++)
            if (it2.key()==c)
            {
                studentClassesGrades[c]=g;
            } */

  }

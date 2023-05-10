#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <iostream>
using namespace std;
#include <QString>
#include <QVector>
#include <QMap>
#include <algorithm>
#include "student.h"
#include "professor.h"
#include "class.h"
#include<QMessageBox>
#include<QComboBox>
class Database {
public:
    QVector <Student*> allStudents ;
    QVector <Professor*> allProfessors ;
    QVector <Class*> allClasses ;
    QMap <QString , QString> allStudentsGrades;

    Database(){
        Class* c1=new Class("Math","3201","MTH123","8:30");
        Class* c2=new Class("Biology","3001","SBE1210","9:30");
        Class* c3=new Class("Biochemistry","3201","SBE1250","10:30");
        Class* c4=new Class("Medical Physics","19002","SBE1230","11:30");
        Class* c5=new Class("Data Structures","3101","CMP1010","12:30");
        Class* c6=new Class("Electronics","3101","ELC1210","13:30");
        Class* c7=new Class("Society Problems","20001","GEN001","14:30");
        allClasses.push_back(c1);
        allClasses.push_back(c2);
        allClasses.push_back(c3);
        allClasses.push_back(c4);
        allClasses.push_back(c5);
        allClasses.push_back(c6);
        allClasses.push_back(c7);


        Student* s1=new Student("Ali","Maged","20","email1@aykalam.com","01066022051");
        s1->addClassToStudent(c1);
        s1->addClassToStudent(c2);
        s1->addClassToStudent(c3);
        s1->addClassToStudent(c4);
        s1->addClassToStudent(c5);
        s1->addClassToStudent(c6);
        c1->addStudentToClass(s1,"Unknown");
        c2->addStudentToClass(s1,"Unknown");
        c3->addStudentToClass(s1,"Unknown");
        c4->addStudentToClass(s1,"Unknown");
        c5->addStudentToClass(s1,"Unknown");
        c6->addStudentToClass(s1,"Unknown");
        s1->getStudentClass(s1);

        allStudents.push_back(s1);

      /*  QString Class1
        Class* c1 = myDatabase.findClass(Class1);
        ui->lineEdit_sg_c1->setText(c1->getClassname());

        QString Class2=ui->comboBox_2->currentText();
        Class* c2 = myDatabase.findClass(Class2);
        ui->lineEdit_sg_c2->setText(c2->getClassname());

        QString Class3=ui->comboBox_3->currentText();
        Class* c3 = myDatabase.findClass(Class3);
        ui->lineEdit_sg_c3->setText(c3->getClassname());

        QString Class4=ui->comboBox_4->currentText();
        Class* c4 = myDatabase.findClass(Class4);
        ui->lineEdit_sg_c4->setText(c4->getClassname());

        QString Class5=ui->comboBox_5->currentText();
        Class* c5 = myDatabase.findClass(Class5);
        ui->lineEdit_sg_c5->setText(c5->getClassname());

        QString Class6=ui->comboBox_6->currentText();
        Class* c6 = myDatabase.findClass(Class6);
        ui->lineEdit_sg_c6->setText(c6->getClassname());

        Student* st=new Student(fn,ln,age,email,number);

        st->addClassToStudent(c1);
        c1->addStudentToClass(st,"Unknown");
        st->addClassToStudent(c2);
         c2->addStudentToClass(st,"Unknown");
        st->addClassToStudent(c3);
         c3->addStudentToClass(st,"Unknown");
        st->addClassToStudent(c4);
         c4->addStudentToClass(st,"Unknown");
        st->addClassToStudent(c5);
         c5->addStudentToClass(st,"Unknown");
        st->addClassToStudent(c6);
         c6->addStudentToClass(st,"Unknown");

        ui->lineEdit_sg_c1g->setText(st->getClassGrades(c1));
        ui->lineEdit_sg_c2g->setText(st->getClassGrades(c2));
        ui->lineEdit_sg_c3g->setText(st->getClassGrades(c3));
        ui->lineEdit_sg_c4g->setText(st->getClassGrades(c4));
        ui->lineEdit_sg_c5_2->setText(st->getClassGrades(c5));
        ui->lineEdit_sg_c6_2->setText(st->getClassGrades(c6)); */

        Student* s2=new Student("Abdallah","Ahmed","21","email2@aykalam.com","01066022052");
        s2->addClassToStudent(c1);
        s2->addClassToStudent(c2);
        s2->addClassToStudent(c3);
        s2->addClassToStudent(c5);
        s2->addClassToStudent(c6);
        s2->addClassToStudent(c7);
        c1->addStudentToClass(s2,"Unknown");
        c2->addStudentToClass(s2,"Unknown");
        c3->addStudentToClass(s2,"Unknown");
        c5->addStudentToClass(s2,"Unknown");
        c6->addStudentToClass(s2,"Unknown");
        c7->addStudentToClass(s2,"Unknown");

         allStudents.push_back(s2);

        Student* s3=new Student("Mayar","Ahmed","15","email3@aykalam.com","01066022053");
        s3->addClassToStudent(c1);
        s3->addClassToStudent(c2);
        s3->addClassToStudent(c3);
        s3->addClassToStudent(c4);
        s3->addClassToStudent(c6);
        s3->addClassToStudent(c7);
        c1->addStudentToClass(s3,"Unknown");
        c2->addStudentToClass(s3,"Unknown");
        c3->addStudentToClass(s3,"Unknown");
        c4->addStudentToClass(s3,"Unknown");
        c6->addStudentToClass(s3,"Unknown");
        c7->addStudentToClass(s3,"Unknown");

        allStudents.push_back(s3);

        Professor* p1=new Professor("Mohamed","Mostafa","27","email1@7abibyyahandasa.com","01158339611","Teaching Assistant");\
        p1->addClassToProfessor(c1);
        p1->addClassToProfessor(c2);
        c1->addProfessor(p1);
        c2->addProfessor(p1);
        allProfessors.push_back(p1);

        Professor* p2=new Professor("Ahmed","Hesham","35","email2@a7sandrfeldonya.com","01158339612","Professor");
        p2->addClassToProfessor(c3);
        p2->addClassToProfessor(c4);
        c3->addProfessor(p2);
        c4->addProfessor(p2);
         allProfessors.push_back(p2);

        Professor* p3=new Professor("Mariam","Hany","13","email3@aykalam.com","01158339612","bel 7ob");
        p3->addClassToProfessor(c5);
        p3->addClassToProfessor(c6);
        c5->addProfessor(p3);
        c6->addProfessor(p3);
        allProfessors.push_back(p3);

       }

    void addStudent (Student* s){
        allStudents.push_back(s);
    };
    void addProfessor (Professor* p) {
        allProfessors.push_back(p);
    };
    void addClass (Class* c){
        allClasses.push_back(c);
    } ;
    Student* findStudent(QString f, QString l){
        for(long long i=0; i<allStudents.size(); i++ )
        {
            if (allStudents[i]->getFirstName() == f && allStudents[i]->getLastName() == l)
                return allStudents[i];
        }
        return nullptr;
    };
    Professor* findProfessor(QString F, QString L){
        for(long long i=0; i<allProfessors.size(); i++ )
        {
            if (allProfessors[i]->getFirstName() == F && allProfessors[i]->getLastName() == L)
                return allProfessors[i];
        }
        return nullptr;
    };
    Class* findClass(QString name){
        for(long long i = 0 ; i<allClasses.size() ; i++)
        {
            if(allClasses[i]->getClassname()==name)
                return allClasses[i];
        }
        return nullptr;
    };
  /*  void assignClassToStdAndProfessor(Class* cls, Student* std, QString grade, Professor* prof){

        std->addClassToStudent(cls,grade); // adding a class with its grade to a student
        prof->addClassToProfessor(cls);// adding a class to a professor
        cls->addProfessor( prof); // adding a class with its grade to a student
        cls->addStudentGrade(std,grade);// adding a student with its grade to a class
    }; */

    };



#endif // DATABASE_H

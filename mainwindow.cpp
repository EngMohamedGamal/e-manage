#include "mainwindow.h"
#include "QMainWindow"
#include "ui_mainwindow.h"
#include<QPixmap>
#include <QIcon>
#include <QFontDatabase>
#include<QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi (this);

    //Login Image Delcration
    QPixmap pix (":/resources/img/user.png/");
    int w = ui->label_7->width();
    int h = ui->label_7->height ();
    ui->label_7->setPixmap (pix.scaled (w, h, Qt:: KeepAspectRatio));

    //WindowIcon Declaration
    this->setWindowIcon(QIcon(":/resources/img/icon.png/"));

    //Font Declaration
    QFontDatabase::addApplicationFont(":/resources/materials/Helvetica-Bold.tttf");

    //Default Font
    QFont font("AirArabia");
    font.setStyleHint(QFont::Monospace);
    QApplication::setFont(font);

    for (int i =0 ; i<myDatabase.allClasses.size(); i++)
    {
        ui->comboBox->addItem(myDatabase.allClasses[i]->getClassname());
        ui->comboBox_2->addItem(myDatabase.allClasses[i]->getClassname());
        ui->comboBox_3->addItem(myDatabase.allClasses[i]->getClassname());
        ui->comboBox_4->addItem(myDatabase.allClasses[i]->getClassname());
        ui->comboBox_5->addItem(myDatabase.allClasses[i]->getClassname());
        ui->comboBox_6->addItem(myDatabase.allClasses[i]->getClassname());
        ui->comboBox_7->addItem(myDatabase.allClasses[i]->getClassname());
        ui->comboBox_8->addItem(myDatabase.allClasses[i]->getClassname());

    }
    ui->comboBox_8->addItem("Null");



}

MainWindow::~MainWindow()
{
    delete ui;
}

bool isNum(QString s){
    string a = s.toStdString();
    for(auto i:a){
           if (isdigit(i)){

              return 1;
           }
        }
    return 0;
}

bool isString(QString s){
    string a = s.toStdString();
    for(auto i:a){
           if (!isdigit(i)){

              return 1;
           }
        }
    return 0;
}


void MainWindow::on_pushButton_logout_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_3_clicked()
{
        QString username = ui->lineEdit_username->text();
        QString password = ui->lineEdit_password->text();

        if(username == "123" && password == "123")
        {
            ui->stackedWidget->setCurrentIndex(1);
        }
        else
        {
            QMessageBox::warning(this,"Login","invalid username or password");
        }
}


void MainWindow::on_pushButton_student_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_student_search_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

    QString f=ui->stackedWidget->findChild<QLineEdit*>("lineEdit_ss_fn")->text();
    QString l=ui->stackedWidget->findChild<QLineEdit*>("lineEdit_ss_ln")->text();
    if(isNum(ui->lineEdit_ss_fn->text())){
        QMessageBox::warning(this, "ERROR", "Invalid data type, try codin");

    }

    Student* stdPtr = myDatabase.findStudent(f, l);
    if (stdPtr){
        QString a = stdPtr->getAge();
        QString email = stdPtr->getEmail();
        QString number = stdPtr->getMobile();

        ui->stackedWidget->setCurrentIndex(3);


        ui->lineEdit_sp_fn->setText(f);
        ui->lineEdit_sp_ln->setText(l);
        ui->lineEdit_sp_age->setText(a);
        ui->lineEdit_email->setText(email);
        ui->lineEdit_sp_number->setText(number);

        QVector<Class*> courses=stdPtr->getStudentClass(stdPtr);

        ui->lineEdit_sg_c1->setText(courses[0]->getClassname());
        ui->lineEdit_sg_c2->setText(courses[1]->getClassname());
        ui->lineEdit_sg_c3->setText(courses[2]->getClassname());
        ui->lineEdit_sg_c4->setText(courses[3]->getClassname());
        ui->lineEdit_sg_c5->setText(courses[4]->getClassname());
        ui->lineEdit_sg_c6->setText(courses[5]->getClassname());

        QVector<QString> coursesGrades=stdPtr->getStudentGrades(stdPtr);

        ui->lineEdit_sg_c1g->setText(coursesGrades[0]);
        ui->lineEdit_sg_c2g->setText(coursesGrades[1]);
        ui->lineEdit_sg_c3g->setText(coursesGrades[2]);
        ui->lineEdit_sg_c4g->setText(coursesGrades[3]);
        ui->lineEdit_sg_c5_2->setText(coursesGrades[4]);
        ui->lineEdit_sg_c6_2->setText(coursesGrades[5]);

    }
    else
        QMessageBox::information(this,"Error","Student not found");

    ui->lineEdit_sp_fn->setEnabled(false);
    ui->lineEdit_sp_ln->setEnabled(false);
    ui->lineEdit_sp_age->setEnabled(false);
    ui->lineEdit_email->setEnabled(false);
    ui->lineEdit_sp_number->setEnabled(false);


}


void MainWindow::on_pushButton_add_student_clicked()
{

    ui->stackedWidget->setCurrentIndex(8);


}


void MainWindow::on_pushButton_student_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_professor_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_classes_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_Back_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_professor_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_professor_search_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
        QString f1 = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_ps_fn")->text();
        QString f2 = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_ps_ln")->text();

        if(isNum(ui->lineEdit_ps_fn->text())){
            QMessageBox::warning(this, "ERROR", "Invalid data type, try codin");

        }
        if(isNum(ui->lineEdit_ss_ln->text())){
            QMessageBox::warning(this, "ERROR", "Invalid data type, try codin");

        }
        else{

            Professor* p = myDatabase.findProfessor(f1, f2);
                    if(p){
                    QString age = p->getAge();
                    QString mail = p->getEmail();
                    QString num = p->getMobile();
                    QString title = p->getTitle();

                    Class* class1 = p->getProfessorClass1();
                    Class* class2 = p->getProfessorClass2();


                    ui->stackedWidget->setCurrentIndex(5);
                    ui->lineEdit_pp_fn->setText(f1);
                    ui->lineEdit_pp_ln->setText(f2);
                    ui->lineEdit_pp_age->setText(age);
                    ui->lineEdit_pp_email->setText(mail);
                    ui->lineEdit_pp_number->setText(num);
                    ui->lineEdit_pp_title->setText(title);
                    ui->lineEdit_ap_c1->setText(class1->getClassname());
                    if(class2 == nullptr)
                        ui->lineEdit_ap_c2->setText("No Course");

                    else
                        ui->lineEdit_ap_c2->setText(class2->getClassname());
                    }
                    else
                    {
                        QMessageBox::information(this,"Error","Professor not found");
                    }


                    ui->lineEdit_pp_fn->setEnabled(false);
                    ui->lineEdit_pp_ln->setEnabled(false);
                    ui->lineEdit_pp_age->setEnabled(false);
                    ui->lineEdit_pp_email->setEnabled(false);
                    ui->lineEdit_pp_number->setEnabled(false);
                    ui->lineEdit_pp_title->setEnabled(false);
                    ui->lineEdit_ap_c1->setEnabled(false);
                    ui->lineEdit_ap_c2->setEnabled(false);
        }

}


void MainWindow::on_pushButton_add_professor_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->comboBox_9->clear();
}


void MainWindow::on_pushButton_class_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_class_search_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    QString name=ui->stackedWidget->findChild<QLineEdit*>("lineEdit_cs_id")->text();

    if(isNum(ui->lineEdit_cs_id->text())){
        QMessageBox::warning(this, "ERROR", "Invalid data type, try codin");

    }
    else{


    Class* clsPtr = myDatabase.findClass(name);
    if (clsPtr){
        QString code = clsPtr->getClassCode();
        QString hall = clsPtr->getLecHall();
        QString time = clsPtr->getClassTime();

        ui->stackedWidget->setCurrentIndex(7);


        ui->lineEdit_cp_name->setText(name);
        ui->lineEdit_cp_id->setText(code);
        ui->lineEdit_cp_lecturehall->setText(hall);
        ui->lineEdit_cp_time->setText(time);

    }


    else
       { QMessageBox::information(this,"Error","Class not found");
    }

    ui->lineEdit_cp_name->setEnabled(false);
    ui->lineEdit_cp_id->setEnabled(false);
    ui->lineEdit_cp_lecturehall->setEnabled(false);
    ui->lineEdit_cp_time->setEnabled(false);

    QMap<Student*,QString> m = clsPtr->getMap();
    QMap<Student*,QString>::Iterator it ;
    for (it=m.begin();it!=m.end();it++)
    {
        Student* s = it.key();
        ui->comboBox_9->addItem(s->getFirstName()+" "+s->getLastName());
    }


}
}




void MainWindow::on_pushButton_Back_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);


    QString fn=ui->stackedWidget->findChild<QLineEdit*>("lineEdit_as_fn")->text();// get fn
    QString ln=ui->stackedWidget->findChild<QLineEdit*>("lineEdit_as_ln")->text();//get ln
    QString age=ui->stackedWidget->findChild<QLineEdit*>("lineEdit_as_age")->text();//get age
    QString number=ui->stackedWidget->findChild<QLineEdit*>("lineEdit_as_number")->text();//get number
    QString email=ui->stackedWidget->findChild<QLineEdit*>("lineEdit_as_email")->text();// get email

    int a=age.toInt();

    if(isNum(ui->lineEdit_as_fn->text())){
        QMessageBox::warning(this, "ERROR", "Invalid data type, try codin");

    }
    else if(isNum(ui->lineEdit_as_ln->text())){
        QMessageBox::warning(this, "ERROR", "Invalid data type, try codin");

    }

    else if(isString(ui->lineEdit_as_age->text())){
        QMessageBox::warning(this, "ERROR", "Invalid data type, try codin");

    }
    else if(a<15 && a>40){
        QMessageBox::warning(this, "ERROR", "incorrect age");

    }
    else if(isString(ui->lineEdit_as_number->text())){
        QMessageBox::warning(this, "ERROR", "Invalid data type, try codin");

    }
    else{

    Student* st=new Student(fn,ln,age,email,number);

    QString Class1=ui->comboBox->currentText();
        Class* c1 = myDatabase.findClass(Class1);
        QString grade1=ui->stackedWidget->findChild<QLineEdit*>("lineEdit_as_g1")->text();
        st->setGradeOfStudent(c1,grade1);
        c1->setStudentGrade(st,grade1);
        ui->lineEdit_sg_c1g->setText(grade1);
        ui->lineEdit_sg_c1->setText(c1->getClassname());

        QString Class2=ui->comboBox_2->currentText();
        bool check = true;
        if(Class2 == Class1)
        {
         check = false;
        }

        else{
        Class* c2 = myDatabase.findClass(Class2);
        QString grade2=ui->stackedWidget->findChild<QLineEdit*>("lineEdit_as_g2")->text();
        st->setGradeOfStudent(c2,grade2);
        c2->setStudentGrade(st,grade2);
        ui->lineEdit_sg_c2g->setText(grade2);
        ui->lineEdit_sg_c2->setText(c2->getClassname());
        }


        QString Class3=ui->comboBox_3->currentText();
        if(Class3 == Class2 || Class3 == Class1)
        {
           check = false;
        }
        else{
        Class* c3 = myDatabase.findClass(Class3);
        QString grade3=ui->stackedWidget->findChild<QLineEdit*>("lineEdit_as_g3")->text();
        st->setGradeOfStudent(c3,grade3);
        c3->setStudentGrade(st,grade3);
        ui->lineEdit_sg_c3g->setText(grade3);
        ui->lineEdit_sg_c3->setText(c3->getClassname());

        }


        QString Class4=ui->comboBox_4->currentText();
        if(Class4 == Class3 || Class4 == Class2 || Class4 == Class1)
        {
            check = false;
        }
        else{
        Class* c4 = myDatabase.findClass(Class4);
        QString grade4=ui->stackedWidget->findChild<QLineEdit*>("lineEdit_as_g4")->text();
        st->setGradeOfStudent(c4,grade4);
        c4->setStudentGrade(st,grade4);
        ui->lineEdit_sg_c4g->setText(grade4);
        ui->lineEdit_sg_c4->setText(c4->getClassname());
        }


        QString Class5=ui->comboBox_5->currentText();
        if(Class5 == Class4 || Class5 == Class3 || Class5 == Class2 || Class5 == Class1)
        {
            check = false;
        }
        else{
        Class* c5 = myDatabase.findClass(Class5);
        QString grade5=ui->stackedWidget->findChild<QLineEdit*>("lineEdit_as_g5")->text();
        st->setGradeOfStudent(c5,grade5);
        c5->setStudentGrade(st,grade5);
        ui->lineEdit_sg_c5_2->setText(grade5);
        ui->lineEdit_sg_c5->setText(c5->getClassname());
        }


        QString Class6=ui->comboBox_6->currentText();
        if(Class6 == Class5 || Class6 == Class4 || Class6 == Class3 || Class6 == Class2 || Class6 == Class1)
        {
            check = false;
        }
        else{
        Class* c6 = myDatabase.findClass(Class6);
        QString grade6=ui->stackedWidget->findChild<QLineEdit*>("lineEdit_as_g6")->text();
        st->setGradeOfStudent(c6,grade6);
        c1->setStudentGrade(st,grade6);
        ui->lineEdit_sg_c5_2->setText(grade6);
        ui->lineEdit_sg_c6->setText(c6->getClassname());
        }
        if(check)
        {myDatabase.addStudent(st);

        QMessageBox::information(this,"Pass","Student added successfully");

        ui->lineEdit_as_fn->setText("");
        ui->lineEdit_as_ln->setText("");
        ui->lineEdit_as_age->setText("");
        ui->lineEdit_as_number->setText("");
        ui->lineEdit_as_email->setText("");

        ui->stackedWidget->setCurrentIndex(2);
        }
        else{
            QMessageBox::information(this,"Error","Can't add same courses");
            ui->stackedWidget->setCurrentIndex(8);
        }





}


}


void MainWindow::on_pushButton_Back_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_Back_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}


void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

        QString fn = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_ap_fn")->text();
        QString ln = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_ap_ln")->text();
        QString a = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_ap_age")->text();
        QString num = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_ap_number")->text();
        QString e = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_ap_email")->text();
        QString t = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_ap_title")->text();

        //int a=age.toInt();

        if(isNum(ui->lineEdit_ap_fn->text())){
            QMessageBox::warning(this, "ERROR", "Invalid data type, try codin");

        }
        else if(isNum(ui->lineEdit_ap_ln->text())){
            QMessageBox::warning(this, "ERROR", "Invalid data type, try codin");

        }
        else if(isString(ui->lineEdit_ap_age->text())){
            QMessageBox::warning(this, "ERROR", "Invalid data type, try codin");

        }

        else if(isString(ui->lineEdit_sp_number->text())){
            QMessageBox::warning(this, "ERROR", "Invalid data type, try codin");

        }
        else if(isNum(ui->lineEdit_ap_title->text())){
            QMessageBox::warning(this, "ERROR", "Invalid data type, try codin");

        }
        else{

        Professor *p1 = new Professor(fn,ln,a,e,num,t);

        QString Class1=ui->comboBox_7->currentText();
                Class* c1 = myDatabase.findClass(Class1);
                p1->addClassToProfessor(c1);
                c1->addProfessor(p1);

                QString Class2=ui->comboBox_8->currentText();
                if (Class2 != "Null")
                {
                Class* c2 = myDatabase.findClass(Class2);
                p1->addClassToProfessor(c2);
                c2->addProfessor(p1);
                }
                else
                {
                    Class* c2 = nullptr;
                    p1->addClassToProfessor(c2);
                }

                if(Class1 == Class2)
                {
                    QMessageBox::information(this,"Error","Can't add same courses");
                    ui->stackedWidget->setCurrentIndex(10);

                }
                else
                {
                    myDatabase.addProfessor(p1);
                QMessageBox::information(this,"Pass","Professor added successfully");
                ui->lineEdit_ap_fn->setText("");
                ui->lineEdit_ap_ln->setText("");
                ui->lineEdit_ap_age->setText("");
                ui->lineEdit_ap_number->setText("");
                ui->lineEdit_ap_email->setText("");
                ui->lineEdit_ap_title->setText("");
                ui->lineEdit_ap_c1->setText("");
                ui->lineEdit_ap_c2->setText("");
                }
        }
}


void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_pushButton_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
    QString cn = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_cs_id")->text();
    Class* c = myDatabase.findClass(cn);
    QVector<Professor*> p = c->getProf();
    for(int i = 0;i<p.size();i++)
    {
        Professor* prof = p[i];
        QTableWidgetItem* prof_name = new QTableWidgetItem(prof->getFirstName()+" "+prof->getLastName());
        ui->tableWidget->setItem(i,0,prof_name);
    }

}


void MainWindow::on_pushButton_22_clicked()
{
     ui->stackedWidget->setCurrentIndex(13);
     QString cn = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_cs_id")->text();
     Class* c = myDatabase.findClass(cn);
     QMap<Student*, QString> m = c->getMap();
     QMap<Student*,QString>::Iterator it ;
     int i = 0;
       for (it=m.begin();it!=m.end();it++)
       {
           Student* s = it.key();
           QTableWidgetItem* student_name = new QTableWidgetItem(s->getFirstName()+" "+s->getLastName());
           ui->tableWidget_2->setItem(i,0,student_name);
           QString g = it.value();
           QTableWidgetItem* student_grade = new QTableWidgetItem(g);
           ui->tableWidget_2->setItem(i,1,student_grade);
           i++;
       }


}

void MainWindow::on_pushButton_back_from_addclass_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_add_newclass_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_tableWidget_2_cellDoubleClicked(int row, int column)
{
    ui->stackedWidget->setCurrentIndex(3);
        QString n = ui->tableWidget_2->item(row, 0)->text();
        QStringList list_str = n.split(" ");
        QString first = list_str.first();
        QString last = list_str.back();
        Student* stdPtr = myDatabase.findStudent(first,last);

            QString a = stdPtr->getAge();
            QString email = stdPtr->getEmail();
            QString number = stdPtr->getMobile();

            ui->stackedWidget->setCurrentIndex(3);


            ui->lineEdit_sp_fn->setText(first);
            ui->lineEdit_sp_ln->setText(last);
            ui->lineEdit_sp_age->setText(a);
            ui->lineEdit_email->setText(email);
            ui->lineEdit_sp_number->setText(number);

            QVector<Class*> courses=stdPtr->getStudentClass(stdPtr);

            ui->lineEdit_sg_c1->setText(courses[0]->getClassname());
            ui->lineEdit_sg_c2->setText(courses[1]->getClassname());
            ui->lineEdit_sg_c3->setText(courses[2]->getClassname());
            ui->lineEdit_sg_c4->setText(courses[3]->getClassname());
            ui->lineEdit_sg_c5->setText(courses[4]->getClassname());
            ui->lineEdit_sg_c6->setText(courses[5]->getClassname());

            QVector<QString> coursesGrades=stdPtr->getStudentGrades(stdPtr);

            ui->lineEdit_sg_c1g->setText(coursesGrades[0]);
            ui->lineEdit_sg_c2g->setText(coursesGrades[1]);
            ui->lineEdit_sg_c3g->setText(coursesGrades[2]);
            ui->lineEdit_sg_c4g->setText(coursesGrades[3]);
            ui->lineEdit_sg_c5_2->setText(coursesGrades[4]);
            ui->lineEdit_sg_c6_2->setText(coursesGrades[5]);
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_pushButton_add_student_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
    for(int i=0;i<myDatabase.allStudents.size();i++)
    {
        QTableWidgetItem* student_name = new QTableWidgetItem(myDatabase.allStudents[i]->getFirstName()+" "+myDatabase.allStudents[i]->getLastName());
        ui->tableWidget_3->setItem(i,0,student_name);
    }

}


void MainWindow::on_pushButton_add_professor_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
    for(int i =0; i<myDatabase.allProfessors.size();i++)
    {
        QTableWidgetItem* prof_name = new QTableWidgetItem(myDatabase.allProfessors[i]->getFirstName()+" "+myDatabase.allProfessors[i]->getLastName());
        ui->tableWidget_4->setItem(i,0,prof_name);
    }
}


void MainWindow::on_pushButton_add_newclass_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
    for(int i=0;i<myDatabase.allClasses.size();i++)
    {
        QTableWidgetItem* class_name = new QTableWidgetItem(myDatabase.allClasses[i]->getClassname());
        ui->tableWidget_5->setItem(i,0,class_name);
        QTableWidgetItem* class_id = new QTableWidgetItem(myDatabase.allClasses[i]->getClassCode());
        ui->tableWidget_5->setItem(i,1,class_id);
    }

}


void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_23_clicked()
{
    QString c = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_cs_id")->text();
    QString n =ui->comboBox_9->currentText();
    QString g = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_cp_grade")->text();

    Class* cls = myDatabase.findClass(c);
    QStringList list_str = n.split(" ");
    QString first = list_str.first();
    QString last = list_str.back();
    Student* st = myDatabase.findStudent(first,last);
    cls->setStudentGrade(st,g);
    st->setGradeOfStudent(cls,g);
    QMap<Student*, QString> m = cls->getMap();
    QMap<Student*,QString>::Iterator it ;
    int i = 0;
      for (it=m.begin();it!=m.end();it++)
      {
          Student* s = it.key();
          QTableWidgetItem* student_name = new QTableWidgetItem(s->getFirstName()+" "+s->getLastName());
          ui->tableWidget_2->setItem(i,0,student_name);
          QString g = it.value();
          QTableWidgetItem* student_grade = new QTableWidgetItem(g);
          ui->tableWidget_2->setItem(i,1,student_grade);
          i++;
      }

      QVector<QString> coursesGrades=st->getStudentGrades(st);

      ui->lineEdit_sg_c1g->setText(coursesGrades[0]);
      ui->lineEdit_sg_c2g->setText(coursesGrades[1]);
      ui->lineEdit_sg_c3g->setText(coursesGrades[2]);
      ui->lineEdit_sg_c4g->setText(coursesGrades[3]);
      ui->lineEdit_sg_c5_2->setText(coursesGrades[4]);
      ui->lineEdit_sg_c6_2->setText(coursesGrades[5]);


}


void MainWindow::on_pushButton_13_clicked()
{
    string g = QCoreApplication::applicationDirPath().toStdString()+"/Classes.csv";
        fstream fout;
        fout.open(g,ios::out | ios::trunc);
        fout<<"Courses"<<","<<"name"<<","
           <<"hall"<<","
           <<"time"<<","
           <<"code"<<",";
          fout<<endl;

        for(int i = 0; i< myDatabase.allClasses.size(); i++){
            fout<<i+1<<","<<myDatabase.allClasses[i]->getClassname().toStdString()<<","
               <<myDatabase.allClasses[i]->getLecHall().toStdString()<<","
               <<myDatabase.allClasses[i]->getClassTime().toStdString()<<","
               <<myDatabase.allClasses[i]->getClassCode().toStdString()<<",";
    fout<<endl;
        }
        fout<<endl;
        fout.close();
        QMessageBox::information(this,"Confirm","Classes CSV added successfully");
}

void MainWindow::on_pushButton_8_clicked()
{
    string g = QCoreApplication::applicationDirPath().toStdString() + "/Professors.csv";
        fstream fout;
        fout.open(g, ios::out | ios::trunc);
        fout<<"Students"<<","<<"firstname"<<","
           <<"lastname"<<","
           <<"age"<<","
           <<"email"<<","
           <<"mobile"<<","
           <<"title"<<","<<endl;

        for(int i = 0; i< myDatabase.allProfessors.size(); i++){
            fout<<i+1<<","<<myDatabase.allProfessors[i]->getFirstName().toStdString()<<","
               <<myDatabase.allProfessors[i]->getLastName().toStdString()<<","
               <<myDatabase.allProfessors[i]->getAge().toStdString()<<","
               <<myDatabase.allProfessors[i]->getEmail().toStdString()<<","
               <<myDatabase.allProfessors[i]->getMobile().toStdString()<<","
                 <<myDatabase.allProfessors[i]->getTitle().toStdString()<<",";

            fout<<endl;
        }
        fout<<endl;
        fout.close();
        QMessageBox::information(this,"confirm","Professor CSV added successfully");
}


void MainWindow::on_pushButton_6_clicked()
{
    string g = QCoreApplication::applicationDirPath().toStdString() + "/Students.csv";
        fstream fout;
        fout.open(g, ios::out | ios::trunc);
        fout<<"Students"<<","<<"firstname"<<","
           <<"lastname"<<","
           <<"age"<<","
           <<"email"<<","
           <<"mobile"<<","<<endl;

        for(int i = 0; i< myDatabase.allStudents.size(); i++){
            fout<<i+1<<","<<myDatabase.allStudents[i]->getFirstName().toStdString()<<","
               <<myDatabase.allStudents[i]->getLastName().toStdString()<<","
               <<myDatabase.allStudents[i]->getAge().toStdString()<<","
               <<myDatabase.allStudents[i]->getEmail().toStdString()<<","
               <<myDatabase.allStudents[i]->getMobile().toStdString()<<",";

            fout<<endl;
        }
        fout<<endl;
        fout.close();
        QMessageBox::information(this,"confirm","Student CSV added successfully");
}


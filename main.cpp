#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

//CSV EXPORTING CODE (Not Accurate, needs editing)

//for(auto p :allClasses){
//    Class *course=p.second;
//    QString temp QString::fromStdString(course->getName);
//    out<<p.first<<","<<temp<<","<<course->gettime()<<","<<course->gethall()<<","<<
//         QString::fromStdString(course->getcourseklne())
//}


// out << "studentID,studentFisrtName,studentLastName,studentEmail,studentPhone,studentAge,stude....
// for (auto p : students) {
    //student *student =p.second;
    //out <<p.first<<","<<QString::XXXXString(student->getFirstName()) << "," << QString:XXXStr....
    //<< QString::fromStdString(student->getEmail()) << "," <<
    //QString::fromStdString(student->getMobile()) <<"," <<QString::fromStdString(student->getGrade())<<","
    //QString::fromStdString(student->getDepartment())<<",";
    //for (auto p : student->getCourses())
        //if (c.first != X)
            //cout << c.first <<"," <<c.second << ",";

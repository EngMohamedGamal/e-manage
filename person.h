#ifndef PERSON_H
#define PERSON_H

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
class Person
{
private:
    QString FirstName;
    QString LastName;
    QString Age;
    QString Email;
    QString Mobile;
public:
    Person();
       Person(QString n1,QString n2,QString a,QString e,QString m);
       void setFirstName(QString n1);
       QString getFirstName();
       void setLastName(QString n2);
       QString getLastName();
       void setAge(QString a);
       QString getAge();
       void setMobile(QString m);
       QString getMobile();
       void setEmail(QString e);
       QString getEmail();
};

#endif // PERSON_H

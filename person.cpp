#include <iostream>
using namespace std;
#include<QString>
#include "person.h"

Person::Person()
{
    FirstName="Unknown";
    LastName="Unknown";
    Age="0";
    Email="Unknown";
    Mobile="Unknown";
}

Person::Person(QString n1, QString n2, QString a, QString e, QString m)
{
    FirstName=n1;
    LastName=n2;
    Age=a;
    Email=e;
    Mobile=m;
}

void Person::setFirstName(QString n1) {
    FirstName = n1;
}

QString Person::getFirstName() {
    return FirstName;
}

void Person::setLastName(QString n2) {
    LastName = n2;
}

QString Person::getLastName() {
    return LastName;
}

void Person::setAge(QString a) {
    Age = a;
}

QString Person::getAge() {
    return Age;
}

void Person::setMobile(QString m) {
    Mobile = m;

}

QString Person::getMobile() {
    return Mobile;
}

void Person::setEmail(QString e) {
    Email = e;
}

QString Person::getEmail() {
    return Email;
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
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
#include"database.h"
#include<QComboBox>
#include<QTableWidget>
#include<fstream>
#include<QCoreApplication>
QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    Database myDatabase ;
    ~MainWindow();

private slots:

    void on_pushButton_logout_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_student_back_clicked();

    void on_pushButton_student_search_clicked();

    void on_pushButton_add_student_clicked();

    void on_pushButton_student_clicked();

    void on_pushButton_professor_clicked();

    void on_pushButton_classes_clicked();

    void on_pushButton_Back_clicked();

    void on_pushButton_professor_back_clicked();

    void on_pushButton_professor_search_clicked();

    void on_pushButton_add_professor_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_class_back_clicked();

    void on_pushButton_class_search_clicked();

  //  void on_pushButton_add_class_clicked();

    void on_pushButton_Back_4_clicked();

    void on_pushButton_Back_5_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_Back_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_add_newclass_clicked();

    void on_pushButton_back_from_addclass_clicked();

    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_tableWidget_2_cellDoubleClicked(int row, int column);

   // void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_add_student_2_clicked();

    void on_pushButton_add_professor_2_clicked();

    void on_pushButton_add_newclass_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H

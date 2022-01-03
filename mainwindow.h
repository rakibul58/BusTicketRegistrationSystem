#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QString>
#include <QPixmap>
#include <QtCore>
#include <QtGui>
#include <QStringList>
#include <QCalendarWidget>
#include <QDateEdit>
#include <QTimeEdit>
#include <QDateTimeEdit>
#include <QVBoxLayout>
#include <QLayoutItem>
#include <QCalendar>
#include <QPushButton>
#include <QDesktopServices>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_about_pushButton_clicked();

    void on_about_back_pushButton_clicked();

    void on_about_cancel_pushButton_clicked();

    void on_admin_pushButton_clicked();

    void on_admin_login_pushButton_clicked();

    void on_admin_back_pushButton_clicked();

    void on_admin_close_pushButton_clicked();

    void on_register_pushbutton_clicked();

    void on_register_back_pushButton_clicked();

    void on_register_Button_clicked();


    void on_admin_logout_button_clicked();

    void on_employee_pushButton_clicked();


    void on_empa_backbutton_clicked();

    void on_user_login_backbutton_clicked();

    void on_login_pushButton_clicked();

    void on_user_login_Button_clicked();

    void on_adpa_employee_tablebutton_clicked();

    void on_adpa_customer_tablebutton_clicked();





    void on_confirm_clicked();

    void on_A1_clicked();

    void on_A2_clicked();

    void on_A3_clicked();

    void on_B1_clicked();

    void on_B2_clicked();

    void on_B3_clicked();

    void on_C1_clicked();

    void on_C2_clicked();

    void on_C3_clicked();

    void on_D1_clicked();

    void on_D2_clicked();

    void on_D3_clicked();

    void on_E1_clicked();

    void on_E2_clicked();

    void on_E3_clicked();

    void on_delete_emp_record_clicked();

    void on_tutorial_clicked();

    void on_Purchase_history_clicked();

    void on_add_emp_clicked();

    void on_add_customer_clicked();

    void on_cancel_registration_clicked();

    void on_cancel_ticket_clicked();

    void on_userlogout1_clicked();

    void on_userlogout2_clicked();

    void on_donebutton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;///For Database Connection
    QString admin_email , admin_password ,admn_pic;///admin page
    QString reg_f_name , reg_l_name , reg_email , reg_pass , reg_contact ;///registration page
    QString user_email , user_password ; /// For User Login Page
    QSqlQueryModel *model1 ; ///for employee page
    QSqlTableModel *model2 ; /// for admin page employee table
    QSqlTableModel *model3 ; /// for admin page customer table
    QSqlTableModel *model4 ; /// for admin page ticket table

    QString type_input , to_input , from_input , date_input , time_input ; ///get shedule and journey details
};
#endif // MAINWINDOW_H

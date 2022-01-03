#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    //Database Connection
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("F:/Gamma Project/Database.db");

    if(db.open())
        qDebug()<<"Database Connected";
    else
        qDebug()<<"Database not Connected";

}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}


void MainWindow::on_about_pushButton_clicked()///For About Page
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->about_textbrowser->setText("This Application was build for online ticket booking of Gamma Travels bus service. This Application was build in December 2020 during the Pandemic to enable the users to\nbook ticket from the comfort of their house and keep a safe distance.\n\nThis Application is the brainchild of Muhammed Rakibul Hasan , Tanvir Hasan Sohan , Md Muhtakim Safat Mishon , Shajibul Alam Shihab , Marwan Ibna Alam , Md Nurul Absar Remon.They are trying their heart and soul to make this Application a better experience for the users.\n\nUser can Register their profile in the Appliction . User can register by giving the following informations - Name , Username , E-mail , psssword , contact number . User can Simply Login if the user is registered to our Databse . User can Select the destination , time , date , number of seats , seats type , Bus type (AC / Non - AC) .\n\nIf user have any problem booking a ticket user can contact our Admins at\nc193058@ugrad.iiuc.ac.bd or\nc193069@ugrad.iiuc.ac.bd or\nc193071@ugrad.iiuc.ac.bd or\nc193042@ugrad.iiuc.ac.bd or\nc193062@ugrad.iiuc.ac.bd or\nc193050@ugrad.iiuc.ac.bd .\n\nThey can register your acount from their panel and Book ticket for user.\n\nPayment options would be E-mailed to the user and Seat plans would be sent by Gamma travels one day before the journey.\n\nThank You For Using our services.");
}

void MainWindow::on_about_back_pushButton_clicked()///For About Page
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_about_cancel_pushButton_clicked()///For About Page
{
    this->close();
}

void MainWindow::on_admin_pushButton_clicked()///Goes to Admin Login Page
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_admin_login_pushButton_clicked() /// Admin Logins and Goes Amin Page
{
    admin_email = ui->adminlogin_lineEdit->text();
    admin_password = ui->adminpassword_lineEdit->text();

    QSqlQuery qry;
    ///Checks if their is similar admin email or password
    qry.exec("SELECT * FROM Admins WHERE mail = '"+admin_email+"' AND password = '"+admin_password+"'");
    if(qry.next())
    {

        ui->stackedWidget->setCurrentIndex(3);
        ui->adpa_name_text->setText(qry.value(0).toString());
        ui->Adpa_email_text->setText(qry.value(3).toString());
        ui->adpa_contact_text->setText(qry.value(2).toString());
        QPixmap pix(qry.value(5).toString());
        ui->adpa_picture_label->setPixmap(pix);

        ///qDebug()<<"Login Succesful";
    }
    else
    {
        QMessageBox::warning(this,"Admin","Wrong E-mail and Password");
    }

    ui->adminlogin_lineEdit->clear();
    ui->adminpassword_lineEdit->clear();

}

void MainWindow::on_admin_back_pushButton_clicked() ///Goes from Admin Page to Home Page
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->adminlogin_lineEdit->clear();
    ui->adminpassword_lineEdit->clear();
}

void MainWindow::on_admin_close_pushButton_clicked()
{
    this->close();
}

void MainWindow::on_register_pushbutton_clicked()///Goes to Register Page from Home Page
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_register_back_pushButton_clicked() /// When Back Button clicked clears the line edits and goes to Home page
{
    ui->reg_fsname_input->clear();
    ui->reg_lastname_input->clear();
    ui->reg_email_input->clear();
    ui->reg_pass_input->clear();
    ui->reg_contact_input->clear();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_register_Button_clicked()  ///Puts registeration Information to Database with Sql query
{
    ///Takes information from line edits to Qstrings
    reg_f_name = ui->reg_fsname_input->text();
    reg_l_name = ui->reg_lastname_input->text();
    reg_email = ui->reg_email_input->text();
    reg_pass = ui->reg_pass_input->text();
    reg_contact = ui->reg_contact_input->text();
    ///Checks if every option is filled
    if(reg_email.size() <=0 || reg_pass.size()<=0 || reg_f_name.size()<=0 || reg_l_name.size()<=0 || reg_contact.size()<=0)///Checks if there is any unfilled box
    {
       QMessageBox::warning(this,"Register","Register Failed\nIncomplete Data");
    }

    else{

        QMessageBox::StandardButton reply = QMessageBox::question(this , "Registration" , "Confirm Registration", ///Confirms Dicision
                                                                  QMessageBox::Yes | QMessageBox::No );
        if(reply == QMessageBox::Yes){
        QSqlQuery qry2 ;

        qry2.exec("INSERT INTO customer (first_name , last_name , email , password , contact ) VALUES ('"+reg_f_name+"' , '"+reg_l_name+"' , '"+reg_email+"'  , '"+reg_pass+"'  , '"+reg_contact+"' )");

        ui->stackedWidget->setCurrentIndex(6);
        qDebug()<<"Register Succesful";
        ui->reg_fsname_input->clear();
        ui->reg_lastname_input->clear();
        ui->reg_email_input->clear();
        ui->reg_pass_input->clear();
        ui->reg_contact_input->clear();
        }

        else{
            ui->reg_fsname_input->clear();
            ui->reg_lastname_input->clear();
            ui->reg_email_input->clear();
            ui->reg_pass_input->clear();
            ui->reg_contact_input->clear();

        }
    }

    ui->reg_fsname_input->clear();
    ui->reg_lastname_input->clear();
    ui->reg_email_input->clear();
    ui->reg_pass_input->clear();
    ui->reg_contact_input->clear();
}

void MainWindow::on_admin_logout_button_clicked() ///Logout button clicke goes to Home Page
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->admin_tableview->setModel(0);
}

void MainWindow::on_employee_pushButton_clicked()  /// Goes to Employee from home page connects to employee table which is not editable for users
{
    ui->stackedWidget->setCurrentIndex(5);
    this->model1 = new QSqlQueryModel();
    model1->setQuery("SELECT id , name , phone , work , experience FROM employee");
    ui->employee_list->setModel(model1);

}



void MainWindow::on_empa_backbutton_clicked() ////employee page back button
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_user_login_backbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->useremailinput->clear();
    ui->userpassinput->clear();
}

void MainWindow::on_login_pushButton_clicked() /// Goes to User login Page from home page
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_user_login_Button_clicked()///User Login Button Clicked
{
    user_email = ui->useremailinput->text();
    user_password = ui->userpassinput->text();

    QSqlQuery qry3 ;
    ///Checks username or password is correct
    qry3.exec("SELECT * FROM customer WHERE email ='"+user_email+"' AND password = '"+user_password+"'");
    if(qry3.next())
    {
        ui->stackedWidget->setCurrentIndex(7);
        ui->useremailinput->clear();
        ui->userpassinput->clear();
        ///Date Shedule Page index (7)
        ui->user_name1->setText(qry3.value(0).toString());
        ui->user_email1->setText(qry3.value(2).toString());
        ui->usercontact1->setText(qry3.value(4).toString());
        ui->user_name2->setText(qry3.value(0).toString());
        ui->user_email2->setText(qry3.value(2).toString());
        ui->usercontact2->setText(qry3.value(4).toString());

    }
    else{
        QMessageBox::warning( this , "Login" , "Invalid E-mail and Password");
        ui->useremailinput->clear();
        ui->userpassinput->clear();
    }





}

void MainWindow::on_adpa_employee_tablebutton_clicked() ///will show a editable employee table and more information which is not available for users
{

    model2 = new QSqlTableModel(this);
    model2->setTable("employee");
    model2->select();

    ui->admin_tableview->setModel(model2);
}

void MainWindow::on_adpa_customer_tablebutton_clicked() /// Will show registered customers table which is editadle
{

    model3 = new QSqlTableModel(this);
    model3->setTable("customer");
    model3->select();

    ui->admin_tableview->setModel(model3);

}


void MainWindow::on_Purchase_history_clicked() ///will show purchased ticket table which is editable
{
    model4 = new QSqlTableModel(this);
    model4->setTable("Seats");
    model4->select();

    ui->admin_tableview->setModel(model4);
}




void MainWindow::on_confirm_clicked()  /// Enters Shedule and Locations in Database
{
    type_input = ui->ac_op->currentText();
    to_input = ui->to_op->currentText();
    from_input = ui->from_op->currentText();
    date_input = ui->dateinput->text();
    time_input = ui->timeinput->text();

    QSqlQuery qry5;


    if(qry5.exec("SELECT seatplan  FROM Seats  WHERE j_date = '"+date_input+"' AND j_time = '"+time_input+"' AND j_to = '"+to_input+"' AND j_from = '"+ from_input+"'"))
        ui->stackedWidget->setCurrentIndex(8);
    ///Checks for previous query if any seats exists it will be disabled
    while (qry5.next()) {

        if(qry5.value(0)=="A1")
            ui->A1->setEnabled(false);
        if(qry5.value(0)=="A2")
            ui->A2->setEnabled(false);
        if(qry5.value(0)=="A3")
            ui->A3->setEnabled(false);
        if(qry5.value(0)=="B1")
            ui->B1->setEnabled(false);
        if(qry5.value(0)=="B2")
            ui->B2->setEnabled(false);
        if(qry5.value(0)=="B3")
            ui->B3->setEnabled(false);
        if(qry5.value(0)=="C1")
            ui->C1->setEnabled(false);
        if(qry5.value(0)=="C2")
            ui->C2->setEnabled(false);
        if(qry5.value(0)=="C3")
            ui->C3->setEnabled(false);
        if(qry5.value(0)=="D1")
            ui->D1->setEnabled(false);
        if(qry5.value(0)=="D2")
            ui->D2->setEnabled(false);
        if(qry5.value(0)=="D3")
            ui->D3->setEnabled(false);
        if(qry5.value(0)=="E1")
            ui->E1->setEnabled(false);
        if(qry5.value(0)=="E2")
            ui->E2->setEnabled(false);
        if(qry5.value(0)=="E3")
            ui->E3->setEnabled(false);

    }

}

//////If one of any available button clicked a seat with customer name,to,from,date and time will be inserted into database as a record

void MainWindow::on_A1_clicked()
{
    QSqlQuery qry6;

    QString str = "A1" ;
     qry6.exec("INSERT INTO Seats (Customer_id , j_date , j_time , seatplan , j_from , j_to , ac_type ) VALUES ('"+user_email+"','"+date_input+"','"+time_input+"','"+str+"' ,'"+ from_input+"','"+to_input+"','"+type_input+"')");
    ui->A1->setEnabled(false);
}



void MainWindow::on_A2_clicked()
{
    QSqlQuery qry7;

    QString str = "A2" ;
     qry7.exec("INSERT INTO Seats (Customer_id , j_date , j_time , seatplan , j_from , j_to , ac_type ) VALUES ('"+user_email+"','"+date_input+"','"+time_input+"','"+str+"' ,'"+ from_input+"','"+to_input+"','"+type_input+"')");
    ui->A2->setEnabled(false);
}

void MainWindow::on_A3_clicked()
{
    QSqlQuery qry8;

    QString str = "A3" ;
    qry8.exec("INSERT INTO Seats (Customer_id , j_date , j_time , seatplan , j_from , j_to , ac_type ) VALUES ('"+user_email+"','"+date_input+"','"+time_input+"','"+str+"' ,'"+ from_input+"','"+to_input+"','"+type_input+"')");
    ui->A3->setEnabled(false);
}

void MainWindow::on_B1_clicked()
{
    QSqlQuery qry9;

    QString str = "B1" ;
    qry9.exec("INSERT INTO Seats (Customer_id , j_date , j_time , seatplan , j_from , j_to , ac_type ) VALUES ('"+user_email+"','"+date_input+"','"+time_input+"','"+str+"' ,'"+ from_input+"','"+to_input+"','"+type_input+"')");
    ui->B1->setEnabled(false);
}

void MainWindow::on_B2_clicked()
{
    QSqlQuery qry10;

    QString str = "B2" ;
    qry10.exec("INSERT INTO Seats (Customer_id , j_date , j_time , seatplan , j_from , j_to , ac_type ) VALUES ('"+user_email+"','"+date_input+"','"+time_input+"','"+str+"' ,'"+ from_input+"','"+to_input+"','"+type_input+"')");
    ui->B2->setEnabled(false);
}

void MainWindow::on_B3_clicked()
{
    QSqlQuery qry11;

    QString str = "B3" ;
    qry11.exec("INSERT INTO Seats (Customer_id , j_date , j_time , seatplan , j_from , j_to , ac_type ) VALUES ('"+user_email+"','"+date_input+"','"+time_input+"','"+str+"' ,'"+ from_input+"','"+to_input+"','"+type_input+"')");
    ui->B3->setEnabled(false);
}

void MainWindow::on_C1_clicked()
{
    QSqlQuery qry12;

    QString str = "C1" ;
    qry12.exec("INSERT INTO Seats (Customer_id , j_date , j_time , seatplan , j_from , j_to , ac_type ) VALUES ('"+user_email+"','"+date_input+"','"+time_input+"','"+str+"' ,'"+ from_input+"','"+to_input+"','"+type_input+"')");
    ui->C1->setEnabled(false);
}

void MainWindow::on_C2_clicked()
{
    QSqlQuery qry13;

    QString str = "C2" ;
    qry13.exec("INSERT INTO Seats (Customer_id , j_date , j_time , seatplan , j_from , j_to , ac_type ) VALUES ('"+user_email+"','"+date_input+"','"+time_input+"','"+str+"' ,'"+ from_input+"','"+to_input+"','"+type_input+"')");
    ui->C2->setEnabled(false);
}

void MainWindow::on_C3_clicked()
{
    QSqlQuery qry14;

    QString str = "C3" ;
    qry14.exec("INSERT INTO Seats (Customer_id , j_date , j_time , seatplan , j_from , j_to , ac_type ) VALUES ('"+user_email+"','"+date_input+"','"+time_input+"','"+str+"' ,'"+ from_input+"','"+to_input+"','"+type_input+"')");
    ui->C3->setEnabled(false);
}

void MainWindow::on_D1_clicked()
{
    QSqlQuery qry15;

    QString str = "D1" ;
    qry15.exec("INSERT INTO Seats (Customer_id , j_date , j_time , seatplan , j_from , j_to , ac_type ) VALUES ('"+user_email+"','"+date_input+"','"+time_input+"','"+str+"' ,'"+ from_input+"','"+to_input+"','"+type_input+"')");
    ui->D1->setEnabled(false);
}

void MainWindow::on_D2_clicked()
{
    QSqlQuery qry16;

    QString str = "D2" ;
    qry16.exec("INSERT INTO Seats (Customer_id , j_date , j_time , seatplan , j_from , j_to , ac_type ) VALUES ('"+user_email+"','"+date_input+"','"+time_input+"','"+str+"' ,'"+ from_input+"','"+to_input+"','"+type_input+"')");
    ui->D2->setEnabled(false);
}

void MainWindow::on_D3_clicked()
{
    QSqlQuery qry17;

    QString str = "D3" ;
    qry17.exec("INSERT INTO Seats (Customer_id , j_date , j_time , seatplan , j_from , j_to , ac_type ) VALUES ('"+user_email+"','"+date_input+"','"+time_input+"','"+str+"' ,'"+ from_input+"','"+to_input+"','"+type_input+"')");
    ui->D3->setEnabled(false);
}

void MainWindow::on_E1_clicked()
{
    QSqlQuery qry18;

    QString str = "E1" ;
    qry18.exec("INSERT INTO Seats (Customer_id , j_date , j_time , seatplan , j_from , j_to , ac_type ) VALUES ('"+user_email+"','"+date_input+"','"+time_input+"','"+str+"' ,'"+ from_input+"','"+to_input+"','"+type_input+"')");
    ui->E1->setEnabled(false);
}

void MainWindow::on_E2_clicked()
{
    QSqlQuery qry19;

    QString str = "E2" ;
    qry19.exec("INSERT INTO Seats (Customer_id , j_date , j_time , seatplan , j_from , j_to , ac_type ) VALUES ('"+user_email+"','"+date_input+"','"+time_input+"','"+str+"' ,'"+ from_input+"','"+to_input+"','"+type_input+"')");
    ui->E2->setEnabled(false);
}

void MainWindow::on_E3_clicked()
{
    QSqlQuery qry20;

    QString str = "E3" ;
    qry20.exec("INSERT INTO Seats (Customer_id , j_date , j_time , seatplan , j_from , j_to , ac_type ) VALUES ('"+user_email+"','"+date_input+"','"+time_input+"','"+str+"' ,'"+ from_input+"','"+to_input+"','"+type_input+"')");
    ui->E3->setEnabled(false);
}


///Will delete a selected record from employee table

void MainWindow::on_delete_emp_record_clicked()
{
   model2->removeRows(ui->admin_tableview->currentIndex().row(), 1);
   model2 = new QSqlTableModel(this);
   model2->setTable("employee");
   model2->select();

   ui->admin_tableview->setModel(model2);
}
///will go to the page and start the video
void MainWindow::on_tutorial_clicked()
{
    QString tutorial = "https://www.youtube.com/watch?v=Cf4RJZyhW-I";
    QDesktopServices::openUrl(QUrl(tutorial));
}

///will be able to insert record in employee table

void MainWindow::on_add_emp_clicked()
{
    int row = model2->rowCount ();
    model2->insertRows(row,1);
}
///will be able to insert record in customer table
void MainWindow::on_add_customer_clicked()
{
    int row = model3->rowCount ();
    model3->insertRows(row,1);
}
///Will delete a selected record from customer table
void MainWindow::on_cancel_registration_clicked()
{
    model3->removeRows(ui->admin_tableview->currentIndex().row(), 1);
    model3 = new QSqlTableModel(this);
    model3->setTable("customer");
    model3->select();

    ui->admin_tableview->setModel(model3);
}
///Will delete a selected record from seats table
void MainWindow::on_cancel_ticket_clicked()
{
    model4->removeRows(ui->admin_tableview->currentIndex().row(), 1);
    model4 = new QSqlTableModel(this);
    model4->setTable("Seats");
    model4->select();

    ui->admin_tableview->setModel(model4);
}

void MainWindow::on_userlogout1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_userlogout2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_donebutton_clicked()
{
    QMessageBox::information(this,"Booking","Seat is Booked . You Will receive a massage soon with payment details");
    ui->stackedWidget->setCurrentIndex(0);
}

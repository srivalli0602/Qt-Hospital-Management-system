#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <filemanager.h>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList headers;

    headers << "Patient ID"
            << "Name"
            << "Age"
            << "Gender"
            << "Blood"
            << "Doctor"
            << "Disease"
            << "Room"
            << "Bill";

    ui->tableWidget->setColumnCount(9);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->comboxBoxblood->addItems({"A+","A-","B+","B-", "AB+","AB-","O+","O-"});
    ui->comboBoxDoctor->addItems({"Dr.Satish","Dr.Srinu","Dr.Ravi","Dr.Madhu","Dr.Indhu"});


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addPatient_clicked()
{
    patient p;
    p.patientId = ui->lineEditpatientID->text();
    p.name = ui->lineEditname->text();
    p.age = ui->spinBoxAge->value();
    if(ui->radioButton->isChecked())
    {
        p.gender="Male";
    }
    else
    {
        p.gender="Female";
    }
    p.contact = ui->lineEditContact->text();
    p.Address=ui->lineEditAddress->text();
    p.bloodGroup=ui->comboxBoxblood->currentText();
    p.doctorName=ui->comboBoxDoctor->currentText();
    p.disease =ui->lineEditDisease->text();
    p.billAmount =ui->lineEdit_bill->text().toDouble();
    p.remarks =ui->lineEditremarks->text();
    p.roomNumber = QString::number(ui->spinBox_Room->value());
    patients.push_back(p);
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row,0, new QTableWidgetItem(p.patientId));
    ui->tableWidget->setItem(row,1,  new QTableWidgetItem(p.name));
    ui->tableWidget->setItem(row,2, new QTableWidgetItem(QString::number(p.age)));
    ui->tableWidget->setItem(row,3,new QTableWidgetItem(p.gender));
    ui->tableWidget->setItem(row,4,new QTableWidgetItem(p.bloodGroup));
    ui->tableWidget->setItem(row,5, new QTableWidgetItem(p.doctorName));
    ui->tableWidget->setItem(row,6, new QTableWidgetItem(p.disease));
    ui->tableWidget->setItem(row,7,new QTableWidgetItem(p.roomNumber));
    ui->tableWidget->setItem(row,8,new QTableWidgetItem(QString::number(p.billAmount)));
    clearFields();
}
void MainWindow::clearFields()
{
    //clear after each add
    ui->lineEditpatientID->clear();
    ui->lineEditname->clear();
    ui->spinBoxAge->setValue(0);
    ui->radioButton->setChecked(false);      // Male
    ui->radioButton_2->setChecked(false);    // Female
    ui->lineEditContact->clear();
    ui->lineEditAddress->clear();
    ui->comboBoxDoctor->setCurrentIndex(0);
    ui->comboxBoxblood->setCurrentIndex(0);
    ui->lineEditDisease->clear();
    ui->spinBox_Room->setValue(0);
    ui->lineEdit_bill->clear();
    ui->lineEditremarks->clear();
}


void MainWindow::on_searchPatient_clicked()
{
    QString id = ui->lineEditpatientID->text();
    for(const patient &p : patients)
    {
        if(p.patientId == id)
        {
            ui->lineEditname->setText(p.name);
            ui->spinBoxAge->setValue(p.age);
            QMessageBox::information(this, "Found", "Patient Found");
            clearFields();
            return;
        }
    }

    QMessageBox::warning(this,"Not Found","Patient Not Found");

}


void MainWindow::on_modifyPatient_clicked()
{
    QString id = ui->lineEditpatientID->text();

    for(int i = 0; i < patients.size(); i++)
    {
        if(patients[i].patientId == id)
        {
            patients[i].name = ui->lineEditname->text();
            patients[i].age = ui->spinBoxAge->value();

            if(ui->radioButton->isChecked())
                patients[i].gender = "Male";
            else
                patients[i].gender = "Female";

            patients[i].contact = ui->lineEditContact->text();
            patients[i].Address = ui->lineEditAddress->text();
            patients[i].bloodGroup = ui->comboxBoxblood->currentText();
            patients[i].doctorName = ui->comboBoxDoctor->currentText();
            patients[i].disease = ui->lineEditDisease->text();
            patients[i].billAmount = ui->lineEdit_bill->text().toDouble();
            patients[i].remarks = ui->lineEditremarks->text();
            patients[i].roomNumber =QString::number(ui->spinBox_Room->value());
            // Update table row
            ui->tableWidget->item(i,0)->setText(patients[i].patientId);
            ui->tableWidget->item(i,1)->setText(patients[i].name);
            ui->tableWidget->item(i,2)->setText(QString::number(patients[i].age));
            ui->tableWidget->item(i,3)->setText(patients[i].gender);
            ui->tableWidget->item(i,4)->setText(patients[i].bloodGroup);
            ui->tableWidget->item(i,5)->setText(patients[i].doctorName);
            ui->tableWidget->item(i,6)->setText(patients[i].disease);
            ui->tableWidget->item(i,7)->setText(patients[i].roomNumber);
            ui->tableWidget->item(i,8)->setText(QString::number(patients[i].billAmount));
            QMessageBox::information(this,"Success","Patient Modified Successfully");
            clearFields();
            return;
        }
    }
    QMessageBox::warning(this,"Error","Patient ID Not Found");

}

void MainWindow::on_deletepatient_clicked()
{
    QString id = ui->lineEditpatientID->text();
    for(int i = 0; i < patients.size(); i++)
    {
        if(patients[i].patientId == id)
        {
            patients.remove(i);
            ui->tableWidget->removeRow(i);
            QMessageBox::information(this,"Success","Patient Deleted Successfully");
            clearFields();
            return;
        }
    }
    QMessageBox::warning(this,"Error","Patient ID Not Found");


}

void MainWindow::on_Savedata_clicked()
{
    filemanager fm;
    fm.savePatients(patients);
    QMessageBox::information(this,"Success","Data Saved Successfully");
}

void MainWindow::on_LoadData_clicked()
{
    filemanager fm;
    patients = fm.loadPatients();
     ui->tableWidget->setRowCount(0);
    for(const patient &p : patients)
    {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(p.patientId));
        ui->tableWidget->setItem(row,1, new QTableWidgetItem(p.name));
        ui->tableWidget->setItem(row,2, new QTableWidgetItem(QString::number(p.age)));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(p.gender));
        ui->tableWidget->setItem(row,4,new QTableWidgetItem(p.bloodGroup));
        ui->tableWidget->setItem(row,5,new QTableWidgetItem(p.doctorName));
        ui->tableWidget->setItem(row,6,new QTableWidgetItem(p.disease));
        ui->tableWidget->setItem(row,7, new QTableWidgetItem(p.roomNumber));
        ui->tableWidget->setItem(row,8,new QTableWidgetItem(QString::number(p.billAmount)));
    }
    QMessageBox::information(this,"Success","Data Loaded Successfully");
    clearFields();

}

void MainWindow::on_Billgenerate_clicked()
{
    if(ui->lineEdit_bill->text().isEmpty())
    {
        QMessageBox::warning(this,"Error","Please Enter Bill Amount");
        return;
    }
    QMessageBox::information(this, "Bill Generated","Bill Amount: Rs. " + ui->lineEdit_bill->text());

}


void MainWindow::on_bookappointment_clicked()
{
    QString id = ui->lineEditpatientID->text();
    for(int i = 0; i < patients.size(); i++)
    {
        if(patients[i].patientId == id)
        {
            patients[i].appointmentDate =
                ui->dateEditappointdate->date().toString("dd-MM-yyyy");
            QMessageBox::information(this,"Success", "Appointment Booked Successfully");
            return;
        }
    }
    QMessageBox::warning(this,"Error","Patient ID Not Found");
}


void MainWindow::on_alloctaeRoom_clicked()
{
    QString id = ui->lineEditpatientID->text();
    for(int i = 0; i < patients.size(); i++)
    {
        if(patients[i].patientId == id)
        {
            patients[i].roomNumber =QString::number(ui->spinBox_Room->value());
            // Update table if room column is visible
            ui->tableWidget->item(i,6)->setText(patients[i].roomNumber);
            QMessageBox::information(this,"Success","Room Allocated Successfully");
            return;
        }
    }
    QMessageBox::warning(this, "Error", "Patient ID Not Found");

}


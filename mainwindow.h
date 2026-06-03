#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <patient.h>
#include <QVector>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:

    void on_addPatient_clicked();

    void on_searchPatient_clicked();

    void on_modifyPatient_clicked();
    void clearFields();

    void on_deletepatient_clicked();

    void on_Savedata_clicked();

    void on_LoadData_clicked();

    void on_Billgenerate_clicked();

    void on_bookappointment_clicked();

    void on_alloctaeRoom_clicked();

private:
    Ui::MainWindow *ui;
     QVector<patient> patients;
};
#endif // MAINWINDOW_H

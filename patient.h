#ifndef PATIENT_H
#define PATIENT_H
#include <QString>
class patient
{
public:
    patient();
    QString patientId;
    QString name;
    int age;
    QString gender;
    QString contact;
    QString Address;
    QString bloodGroup;
    QString doctorName;
    QString disease;
    QString roomNumber;
    QString admissionStatus;
    QString appointmentDate;
    QString joiningDate;
    QString dischargeDate;
    double billAmount;
    QString emergencyContact;
    QString remarks;
};

#endif // PATIENT_H

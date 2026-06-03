#include "filemanager.h"
#include <QFile>
#include <QTextStream>
filemanager::filemanager() {}
void filemanager::savePatients(const QVector<patient>& patients)
{
    QFile file("patients.txt");

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);

        for(const patient &p : patients)
        {
            out << p.patientId << ","
                << p.name << ","
                << p.age << ","
                << p.gender << ","
                << p.contact << ","
                << p.Address << ","
                << p.doctorName << ","
                << p.disease << ","
                << p.roomNumber << ","
                << p.billAmount << ","
                << p.remarks
                << "\n";
        }

        file.close();
    }
}
QVector<patient> filemanager::loadPatients()
{
    QVector<patient> patients;
    QFile file("patients.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            QStringList data = line.split(",");
            if(data.size() >= 11)
            {
                patient p;
                p.patientId = data[0];
                p.name = data[1];
                p.age = data[2].toInt();
                p.gender = data[3];
                p.contact = data[4];
                p.Address = data[5];
                p.doctorName = data[6];
                p.disease = data[7];
                p.roomNumber = data[8];
                p.billAmount = data[9].toDouble();
                p.remarks = data[10];
                patients.push_back(p);
            }
        }

        file.close();
    }
    return patients;
}
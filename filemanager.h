#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QVector>
#include <patient.h>

class filemanager
{
public:
    filemanager();
    void savePatients(const QVector<patient>& patients);
    QVector<patient> loadPatients();
};

#endif // FILEMANAGER_H

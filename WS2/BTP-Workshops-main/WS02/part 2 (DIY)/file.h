#ifndef SENECA_FILE_H
#define SENECA_FILE_H
namespace seneca {
    bool openFile(const char filename[]);
    void closeFile();
    char* read(char d);
    int getRecordsCount();
    bool read(int& refff, char d);
}
#endif
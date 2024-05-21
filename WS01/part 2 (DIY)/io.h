// - Alikhan Ongdassyn,
// - aongdassyn@myseneca.ca,
// - 158486225,
// - 01/23/24.

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef IO_H
#define IO_H

namespace seneca {
    const int MAX_NO_OF_SAMPLES = 20;
    const int GRAPH_WIDTH = 65;

    void drawLine(int length);
    int intDigits(int value);
    void printInt(int value, int fieldWidth);
    void moveCursorBack(int n);
    void drawLineWithLabel(int length, const char* text);
    int getInt(int min, int max);
    void printMsg(const char* msg);
    void printErrorMsg(const char* msg);
    int menu(int noOfSamples);
}
#endif


// void drawLine(int length);
// int intDigits(int value);
// void printInt(int value, int fieldWidth);
// void moveCursorBack(int n);
// void drawLineWithLabel(int length, const char* text);
// int getInt(int min, int max);
// void printMsg(const char* msg);
// void printErrorMsg(const char* msg);
// int menu(int noOfSamples);

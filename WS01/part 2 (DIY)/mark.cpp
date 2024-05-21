// - Alikhan Ongdassyn,
// - aongdassyn@myseneca.ca,
// - 158486225,
// - 01/23/24.

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "mark.h"
#include "file.h"
#include "graph.h"


using namespace std;
using namespace seneca;
namespace seneca {
   
    void bubbleSort(Mark arr[], int n) {
        int i, j;
        for (i = 0; i < n-1; i++) {
            for (j = 0; j < n-i-1; j++) {
                if (arr[j].m_mark < arr[j+1].m_mark) {
                    Mark temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    bool printReport(const char* filename) {
        bool open_file = openFile(filename);
        if(open_file) {
            Mark newArr[MAX_NO_RECS]; 

            int numberOfMarks = readAllMarks(newArr);
            int no_marks[10];

            for(int i = 0; i < numberOfMarks; i++){
                if(newArr[i].m_mark <= 10){
                    no_marks[9]++;
                }
                else if(newArr[i].m_mark >= 11 && newArr[i].m_mark <= 20){
                    no_marks[8]++;
                }
                else if(newArr[i].m_mark >= 21 && newArr[i].m_mark <= 30){
                    no_marks[7]++;
                }
                else if(newArr[i].m_mark >= 31 && newArr[i].m_mark <= 40){
                    no_marks[6]++;
                }
                else if(newArr[i].m_mark >= 41 && newArr[i].m_mark <= 50){
                    no_marks[5]++;
                }
                else if(newArr[i].m_mark >= 51 && newArr[i].m_mark <= 60){
                    no_marks[4]++;
                }
                else if(newArr[i].m_mark >= 61 && newArr[i].m_mark <= 70){
                    no_marks[3]++;
                }
                else if(newArr[i].m_mark >= 71 && newArr[i].m_mark <= 80){
                    no_marks[2]++;
                }
                else if(newArr[i].m_mark >= 81 && newArr[i].m_mark <= 90){
                    no_marks[1]++;
                }
                else if(newArr[i].m_mark >= 91 && newArr[i].m_mark <= 100){
                    no_marks[0]++;
                }
            }
            
            printGraph(no_marks, sizeof(no_marks)/sizeof(no_marks[0]), "Students' Mark Distribution");
            
            bubbleSort(newArr, numberOfMarks);
        
            for(int i = 0; i < numberOfMarks; i++){
                cout << i + 1 << ": " << '[' << newArr[i].m_mark << "] " << newArr[i].m_firstName << " " << newArr[i].m_lastName << endl;
            }
         closeFile();
    }
    else {
        return false;
   }
    return true;
    }
}

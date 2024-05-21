#include <iostream>
using namespace std;

//     void swap(int* xp, int* yp)
// {
//     int temp = *xp;
//     *xp = *yp;
//     *yp = temp;
// }
 
// // An optimized version of Bubble Sort
// void bubbleSort(int arr[], int n)
// {
//     int i, j;
//     bool swapped;
//     for (i = 0; i < n - 1; i++) {
//         swapped = false;
//         for (j = 0; j < n - i - 1; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 swap(&arr[j], &arr[j + 1]);
//                 swapped = true;
//             }
//         }
 
//         // If no two elements were swapped by inner loop,
//         // then break
//         if (swapped == false)
//             break;
//     }
// }

int main()  
{
    // Entering size and scope to be processed
    int SIZE, x, y;
    cout << "Enter the size of array: ";
    cin >> SIZE;
    cout << "Enter the first scope number: ";
    cin >> x;
    cout << "Enter the second scope number: ";
    cin >> y;
    cout << endl;

    // Entering numbers
    int arrOfNum[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        cout << "Enter the number " << i + 1 << ": ";
        cin >> arrOfNum[i];
    }
    cout << endl;

    // The "bubble sort" algorithm
    for (int i = x - 1; i < y; ++i) {
        for (int j = i + 1; j < y; ++j) {
            if (arrOfNum[i] > arrOfNum[j]) {
                int temp = arrOfNum[i];
                arrOfNum[i] = arrOfNum[j];
                arrOfNum[j] = temp;
            }
        }
    }

    // The final result
    cout << "Result: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << arrOfNum[i] << ' ';
    }

/*

    int SIZE; // your array size
    int MAX; // the number could be up to 100

    cout << "Please enter the size: ";
    cin >> SIZE;

    cout << "Please enter the maximum number per element: ";
    cin >> MAX;
    // int arr[SIZE] = {0, 9, 3, 2, 7, 8};
    int arr[SIZE];
    int counts[MAX] = {0};
    int cntPairs = 0;
    for(int i = 0; i < SIZE; ++i){
        cout << i + 1 << ": ";
        cin >> arr[i];
    }

    for(int i = 0; i < SIZE; ++i){
        counts[arr[i]]++;
    }

    for(int i = 0; i < MAX; ++i){
        if(counts[i] > 1){
            cntPairs += (int)(counts[i] / 2); 
        }
    }
    cout << cntPairs << endl;
    */

 // вводим массивы
 /*
    int n, pairs = 0;
    // юзер вводит цифру
    std::cin >> n;
    // ограничение 
    int arr[10];
    //цикл повторяется определлоное количество раз и сохраняеи в массиве
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] == arr[j]) {
                ++pairs;
            }
        }
    }
    // вывод
    std::cout << pairs;
    */
    return 0; 
}
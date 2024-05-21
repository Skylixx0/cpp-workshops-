#include <iostream>
#include <cstring>
#include "hotel.h"
#include "file.h"

using namespace std;
namespace seneca{



void setGuest(Guest& theGuest, const char* fName, const char* lName){
    strcpy(theGuest.m_firstName, fName);
    strcpy(theGuest.m_lastName, lName);
}

void loadData(Room& theRoom){
    char* roomChar = read(',');

    theRoom.m_roomNumber = roomChar;
    read(theRoom.m_maxCntGuests, '\n');

    // cout << theRoom.m_roomNumber[0] << endl;
    // cout << theRoom.m_roomNumber << ' ' << theRoom.m/_maxCntGuests << endl;
}

void loadData(const char* fileName, Hotel& theHotel){
    openFile(fileName);

    int size = getRecordsCount();

    Room* newArr = new Room[size + 1];
    for(int i = 0; i < size; i++){
        loadData(newArr[i]);
        theHotel.m_cntRooms++;
    }
    theHotel.m_rooms = newArr;

    // cout << theHotel.m_rooms << endl;
    closeFile();
};

void display(const Hotel& theHotel){
    int cnt = 0;
    cout << "Standart Rooms:" << endl;
    for(auto i = 0; i < theHotel.m_cntRooms; i++){
        if(theHotel.m_rooms[i].m_roomNumber[0] == 'A'){
            cnt++;
            cout << cnt << '.' << ' ' << theHotel.m_rooms[i].m_roomNumber << ' ' <<'(' << theHotel.m_rooms[i].m_cntGuests 
            << '/' << theHotel.m_rooms[i].m_maxCntGuests << ')' << endl; 
        }
    }
    
    cnt = 0;
    cout << "Family Rooms" << endl;
    for(auto i = 0; i < theHotel.m_cntRooms; i++){
        if(theHotel.m_rooms[i].m_roomNumber[0] == 'B'){
            cnt++;
            cout << cnt << '.' << ' ' << theHotel.m_rooms[i].m_roomNumber << ' ' << '(' << theHotel.m_rooms[i].m_cntGuests 
            << '/' << theHotel.m_rooms[i].m_maxCntGuests << ')' << endl; 
        }
    }
    
    cnt = 0;
    cout << "Suites" << endl;
    for(auto i = 0; i < theHotel.m_cntRooms; i++){
        if(theHotel.m_rooms[i].m_roomNumber[0] == 'C'){
            cnt++;
            cout << cnt << '.' << ' ' << theHotel.m_rooms[i].m_roomNumber << ' ' << '(' << theHotel.m_rooms[i].m_cntGuests 
            << '/' << theHotel.m_rooms[i].m_maxCntGuests << ')' << endl; 
        }
    }
}

void display(const Room& theRoom){
    if(theRoom.m_cntGuests == 0){
        cout << theRoom.m_roomNumber << ' ' << '(' << theRoom.m_cntGuests 
        << '/' << theRoom.m_maxCntGuests << ')' << endl;
    }
    else{
        cout << theRoom.m_roomNumber << ' ' << '(' << theRoom.m_cntGuests 
        << '/' << theRoom.m_maxCntGuests << ')' << ':' << ' ';
        for(auto i = 0; i < theRoom.m_cntGuests; i++){
            cout << theRoom.m_guests[i].m_firstName << theRoom.m_guests[i].m_lastName << endl;
        }
    }
}




void deallocate(const Room& theHotel){
    delete[] theHotel.m_roomNumber;
    // for(auto i = 0; i < theHotel.m_guests){

    // }
    delete[] theHotel.m_guests;
    // delete[] theHotel.
    
}

}
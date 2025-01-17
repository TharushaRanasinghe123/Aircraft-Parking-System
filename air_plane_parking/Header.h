#pragma once
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
using namespace std;


class AIR {
private:
    string air_Line;
    string reg_no;
    string time_entry;
    string time_departure;
    string date_entry;
    string date_departure;
    string cell;
    int ID;
    string status;
public:
    AIR() : air_Line(""), reg_no(""), time_entry(""), time_departure(""), date_entry(""), date_departure(""), ID(0), cell("") {}

    AIR(string n, string a, string ag, string h,string d1,string d2) {
        air_Line = n;
        reg_no = a;
        time_entry = ag;
        time_departure = h;
        date_entry = d1;
        date_departure = d2;

    }

    string getair_lineName()  {
        return air_Line;
    }
    void setair_lineName(string n) {
        air_Line = n;
    }

    string getreg_no()  {
        return reg_no;
    }
    void setreg_no(string a) {
        reg_no = a;
    }

    string getTimeEntry()  {
        return time_entry;
    }
    void setTimeEntry(string ag) {
        time_entry = ag;
    }

    string getdep_time()  {
        return time_departure;
    }
    void setdep_time(string h) {
        time_departure = h;
    }

    string get_date_entry()  {
        return date_entry;
    }
    void set_date_entry(string d1) {
        date_entry = d1;
    }

    string get_date_departure()  {
        return date_departure;
    }
    void set_date_departure(string d2) {
        date_departure = d2;
    }

    void setcell(string celll) {
        cell = celll;
    }
    string getCell() {
        return cell;
    }

    void setID(int userID) {
        ID = userID;
    }
    int getID() {
        return ID;
    }

    void printAIR() {
        cout << "\n\t\tAir Line           \t:\t" << air_Line << endl;
        cout << "\n\t\tRegistration Number\t:\t" << reg_no << endl;
        cout << "\n\t\tTime of Entry      \t:\t" << time_entry << endl;
        cout << "\n\t\tDate of Entry      \t:\t" << date_entry << endl;
        cout << "\n\t\tTime of Departure  \t:\t" << time_departure << endl;
        cout << "\n\t\tDate of Departure  \t:\t" << date_departure << endl;
    }


};

class Node {
public:
    AIR data;
    Node* next;
    Node* prev;

    Node(AIR u) {
        data = u;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void setID() {
        Node* current = head;
        for (int i = 0; i < size; i++) {
            current->data.setID(i + 1);
            current = current->next;
        }
    }

    void setcell() {
        Node* current = head;

        for (int i = 0; i < size && i < 11 && current != nullptr; i++) {
            std::string cellNumber1 = "A-" + std::to_string(i) + "1";
            std::string cellNumber2 = "A-" + std::to_string(i) + "2";

            current->data.setcell(cellNumber1);
            current = current->next;

            if (current != nullptr) {
                current->data.setcell(cellNumber2);
                current = current->next;
            }
        }
    }


    void insertLast(AIR u) {
        Node* newNode = new Node(u);
        if (tail == NULL) {
            head = newNode;
            tail = newNode;
            newNode->prev = NULL;
            newNode->next = NULL;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            newNode->next = NULL;
        }

        size++;
        setID();
        setcell();
    }

    void insertAt(int index, AIR u) {
        if (index < 0) return;
        Node* newNode = new Node(u);
        Node* current = head;
        for (int i = 0; i < index - 1 && current != NULL; i++) {
            current = current->next;
        }
        if (current == NULL) return;
        if (current->prev == NULL) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            newNode->prev = NULL;
        }
        else if (current->next == NULL) {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            newNode->next = NULL;
        }
        else {
            newNode->prev = current;
            newNode->next = current->next;
            current->next->prev = newNode;
            current->next = newNode;
        }
        setID();
        setcell();
        size++;
    }

    void deleteFirst() {
        if (head == NULL) return;
        if (head->next == NULL) {
            head = NULL;
            tail = NULL;
        }
        else {
            head = head->next;
            head->prev = NULL;
        }
        setID();
        setcell();
        size--;
    }

    void deleteLast() {
        if (tail == NULL) return;
        if (tail->prev == NULL) {
            head = NULL;
            tail = NULL;
        }
        else {
            tail = tail->prev;
            tail->next = NULL;
        }
        setID();
        setcell();
        size--;
    }

    void deleteAt(int index) {
        if (index < 0) return;
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        Node* temp = current;
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        delete current;
        size--;
    }

    void printAllAIR() {
        Node* current = head;
        while (current != NULL) {
            AIR u = current->data;
            cout << u.getID() << "\t|air_Line: " << u.getair_lineName() << "\t\t\t|Registration number: " << u.getreg_no() << endl;
            current = current->next;
        }
    }

    void printAlltime() {
        Node* current = head;
        cout << "\tRegistration number|  " << " Time of entry| " << " Date of entry| " << "\t Time of departure|" << "  Date of departure" << endl;
        while (current != NULL) {
            AIR u = current->data;
            cout << u.getCell() << "\t" << u.getreg_no() << "\t\t\t" << u.getTimeEntry() << "\t\t" << u.get_date_entry() << "\t\t" << u.getdep_time() << "\t\t" << u.get_date_departure() << endl;
            current = current->next;
        }
    }


    void current_parking() {
        Node* current = head;
        cout << "\tName of Air Line  " << "\t\tRegistration Number" << "\t\tParking Slot\n"<<endl;
        while (current != NULL) {
            AIR u = current->data;
            std::string inputDate1 = u.get_date_entry();
            std::string inputDate2 = u.get_date_departure();
            std::string inputTime1 = u.getTimeEntry();
            std::string inputTime2 = u.getdep_time();

            string unix_time1 = inputDate1 + " " + inputTime1;
            string unix_time2 = inputDate2 + " " + inputTime2;
           
            // Create a stringstream to parse the first input time
            std::istringstream ss1(unix_time1);
            std::tm parsedTime1 = {};
            ss1 >> std::get_time(&parsedTime1, "%Y-%m-%d %H:%M:%S");
            auto time_entry1 = std::chrono::system_clock::from_time_t(std::mktime(&parsedTime1));

            // Create a stringstream to parse the second input time
            std::istringstream ss2(unix_time2);
            std::tm parsedTime2 = {};
            ss2 >> std::get_time(&parsedTime2, "%Y-%m-%d %H:%M:%S");
            auto time_departure2 = std::chrono::system_clock::from_time_t(std::mktime(&parsedTime2));

            // Get the current time_point
            auto currentTimePoint = std::chrono::system_clock::now();

            // Convert the time_point to a duration since the epoch
            auto durationSinceEpoch = currentTimePoint.time_since_epoch();

            // Convert the duration to seconds (Unix timestamp)
            std::time_t unixTimestamp = std::chrono::duration_cast<std::chrono::seconds>(durationSinceEpoch).count();

            
            if (unixTimestamp >= std::chrono::system_clock::to_time_t(time_entry1) && unixTimestamp <= std::chrono::system_clock::to_time_t(time_departure2)) {

                cout <<"\t"<< u.getair_lineName() << "\t\t\t" << u.getreg_no() <<"\t\t\t\t"<<u.getCell()<< endl;

            }

            current = current->next;
        }

    }

    Node* getAt(int index) {
        if (index < 0 || index >= size) return NULL;
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }
};

DoublyLinkedList air_plane_list()
{

    DoublyLinkedList reservation;

    AIR newAIR1("Emirates", "JA8089", "10:21", "15:21","2023-12-03","2023-12-04");
    AIR newAIR2("Delta", "G-EUDU", "13:20", "14:30", "2023-12-04", "2023-12-05");
    AIR newAIR3("Emerald", "G-KELS", "18:30", "10:20", "2023-12-04", "2023-12-05");
    AIR newAIR4("Dalarte", "F-WWCX", "17:40", "09:40", "2023-12-03", "2023-12-06");
    AIR newAIR5("Croatia", "HL7784", "13:40", "09:50", "2023-12-03", "2023-12-15");
    AIR newAIR6("Qantas", "F2432", "12:00", "19:40", "2023-12-03", "2023-12-04");
    AIR newAIR7("Evaair", "H3244", "17:45", "20:30", "2023-12-04", "2023-12-05");
    AIR newAIR8("Qater", "K43-52", "22:20", "15:40", "2023-12-05", "2023-12-06");
    AIR newAIR9("Alaska", "LI233", "13:50", "17:50", "2023-12-03", "2023-12-04");
    AIR newAIR10("Pacific", "KH-5326", "18:55", "17:30", "2023-12-04", "2023-12-05");


    reservation.insertLast(newAIR1);
    reservation.insertLast(newAIR2);
    reservation.insertLast(newAIR3);
    reservation.insertLast(newAIR4);
    reservation.insertLast(newAIR5);
    reservation.insertLast(newAIR6);
    reservation.insertLast(newAIR7);
    reservation.insertLast(newAIR8);
    reservation.insertLast(newAIR9);
    reservation.insertLast(newAIR10);

    return reservation;
}


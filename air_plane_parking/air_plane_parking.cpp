#include "Header.h"
#include <regex>
using namespace std;

bool isValidTime(string str)
{

    // Regex to check valid time in 24-hour format
    const regex pattern("^([01][0-9]|2[0-3]):[0-5][0-9]$|^[0-9]{4}$");

    // If the time in 24-hour format
    // is empty return false
    if (str.empty())
    {
        return false;
    }

    // Return true if the time in 24-hour format
    // matched the ReGex
    if (regex_match(str, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isValidDate(string str)
{

    // Regex to check valid date in unix format
    const  std::regex pattern("^\\d{4}-\\d{2}-(0[1-9]|1[0-9]|2[0-9]|3[01])$");

    // is empty return false
    if (str.empty())
    {
        return false;
    }

    // Return true if the date in unix format
    // matched the ReGex
    if (regex_match(str, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    DoublyLinkedList Airplane;
    Airplane = air_plane_list();
    bool running = true;
    while (running)
    {
        int option;
        system("CLS");
        cout << "\n\n\n" << endl;
        cout << "\t\t\t===========================================================\n";
        cout << "\t\t\t" << "|                                                         |" << endl;
        cout << "\t\t\t" << "|" << "\tWelcome to Ruhuna 47 International Airport        | \n" ;
        cout << "\t\t\t" << "|                                                         |" << endl;
        cout << "\t\t\t" << "|" << "\t\tPlease select an option: " << "                 |"<< endl;
        cout << "\t\t\t" << "|" << "\t\t\t1. New entry" << "                      |" << endl; 
        cout << "\t\t\t" << "|" << "\t\t\t2. Modify time table" << "              |" << endl;
        cout << "\t\t\t" << "|" << "\t\t\t3. Display the schedule" << "           |" << endl;
        cout << "\t\t\t" << "|" << "\t\t\t4. Get details of an airplane " << "    |" << endl;
        cout << "\t\t\t" << "|" << "\t\t\t5. Schedule of current parking " << "   |" << endl;
        cout << "\t\t\t" << "|" << "\t\t\t6. Delete entry" << "                   |" << endl;
        cout << "\t\t\t" << "|" << "\t\t\t7. Quit " << "                          |" << endl;;
        cout << "\t\t\t" << "|                                                         |" << endl;
        cout << "\t\t\t===========================================================" << endl;


        cout << "input option :";
        cin >> option;



        if (option == 1)
        {
            system("CLS");
            string  air_Line, reg_no;
            string time_entry, time_departure,date_entry,date_departure;

            cout << "\n\n\t\tEnter Name of Air_line: ";
            getline(cin >> ws, air_Line);
            
            cout << "\n\t\tEnter Registration No: ";
            getline(cin >> ws, reg_no);

            cout << "\n\t\tEnter Date of Entry(ex :- yy-mm-dd): ";
            cin >> date_entry;

            cout << "\n\t\tEnter Time of Entry(ex :- hh:mm): ";
            cin >> time_entry;

            cout << "\n\t\tEnter Date of Depature(ex :- yy-mm-dd): ";
            cin >> date_departure;

            cout << "\n\t\tEnter Time of departure(ex :- hh:mm): ";
            cin >> time_departure;



            if (isValidTime(time_entry) && isValidTime(time_departure) && isValidDate(date_entry) && isValidDate(date_departure))
            {
                AIR U(air_Line, reg_no, time_entry, time_departure,date_entry,date_departure);
                Airplane.insertLast(U);
                system("PAUSE");
            }
            else {
                cout << "\n\n\t\t\tInvalid time format or date format\n\t\t\tCannot be entered\n ";
                system("PAUSE");
            }
        }
        else if (option == 2)
        {
            system("CLS");
            int id;
            Airplane.printAllAIR();
            cout << "\n\n\t\tEnter user ID to modify: ";
            cin >> id;

            Node* ptr = Airplane.getAt(id - 1);
            string newtime_entry, newdate_entry;
            string newtime_departure, newdate_departure;

            cout << "\n\t\tEnter new Time of Entry: ";
            cin >> newtime_entry;
            
            cout << "\n\t\tEnter New Date of Entry(ex :- yy-mm-dd): ";
            cin >> newdate_entry;

            cout << "\n\t\tEnter New Time of departure(ex :- hh:mm): ";
            cin >> newtime_departure;

            cout << "\n\t\tEnter New Date of Departure(ex :- yy-mm-dd): ";
            cin >> newdate_departure;


            if (isValidTime(newtime_entry) && isValidTime(newtime_departure) && isValidDate(newdate_departure) && isValidDate(newdate_entry))
            {
                ptr->data.setTimeEntry(newtime_entry);
                ptr->data.set_date_entry(newdate_entry);
                ptr->data.setdep_time(newtime_departure);
                ptr->data.set_date_departure(newdate_departure);
            }
            else {
                cout << "Invalid time format\n Cannot be entered\n ";
                system("PAUSE");
            }
            system("CLS");
            Airplane.printAlltime();
            system("PAUSE");
        }

        else if (option == 3)
        {
            system("CLS");
            Airplane.printAlltime();
            system("PAUSE");
        }
        else if (option == 4)
        {
            system("CLS");
            Airplane.printAllAIR();
            cout << "\nEnter the index of the User ";
            int ind;
            cin >> ind;
            Node* u = Airplane.getAt(ind - 1);


            system("CLS");
            u->data.printAIR();
            system("PAUSE");

        }
        else if (option == 5)
        {
            system("CLS");
            Airplane.current_parking();

            system("PAUSE");
        }

        else if (option == 6)
        {
            system("CLS");
            Airplane.printAllAIR();

            int id;
            cout << "\nEnter user ID to delete: ";
            cin >> id;
            Airplane.deleteAt(id - 1);

        }

        else if (option == 7) {
            running = false;
        }
        else
        {
            cout << "Invalid option\n";
           system("PAUSE");
        }
    }
    return 0;
}

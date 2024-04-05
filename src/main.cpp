#include "DataManip.h"
#include "iostream"
#include "Menu.h"
#include <chrono>
#include <thread>

using namespace std;

int main(){
    char option;
    cout << "Loading program...";
    cout << endl << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│        Choose the data set         │" << endl
         << "├────────────────────────────────────┤" << endl
         << "│  1 - Small set                     │" << endl
         << "│  2 - Large set                     │" << endl
         << "│                                    │" << endl
         << "│  e - Exit                          │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl;

    DataManip data;


    cout << "Choose an option: ";
    cin >> option;


    switch (option) {
        case '1':
            //Smal data set
            data.readStations();
            data.readReservoirs();
            data.readCities();
            data.readPipes();

            break;

        case '2':
            //Large data set
            data.readStationsL();
            data.readReservoirsL();
            data.readCitiesL();
            data.readPipesL();

            break;

        case 'e':
            cout << endl << endl << "Exiting program..." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            return 0;
        default:
            cout << endl << "Not a valid option!" << endl;
    }

    Menu menu = Menu(data);
    menu.MainMenu();

    cout << endl << endl << "Exiting program..." << endl;
    this_thread::sleep_for(chrono::seconds(2));


    return 0;

}
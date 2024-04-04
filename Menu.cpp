#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(DataManip data) {
    data_ = data;
}

void Menu::MainMenu() {
    char option;
    cout << endl << endl;
    cout << endl << "┌───────────────────────────────────┐" << endl
                 << "│             Main Menu             │" << endl
                 << "├───────────────────────────────────┤" << endl
                 << "│  1 - Get Max Amount of Water      │" << endl
                 << "│  2 - Deficit per City             │" << endl
                 << "│  3 - Balance Flow                 │" << endl
                 << "│  4 - Reservoirs Out of Comission  │" << endl
                 << "│  5 - Pumping Station Removed      │" << endl
                 << "│  6 - Pipeline Rupture             │" << endl
                 << "│  e - Exit                         │" << endl
                 << "└───────────────────────────────────┘" << endl
                 << endl
                 << "What would you like to do next? ";

    while(true) {
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case ('1'):
                maxWater();
                return MainMenu();
            case ('2'):
                deficitPerCity();
                return MainMenu();
            case ('3'):
                balanceFlow();
                return MainMenu();
            case ('4'):
                otherInfo();
                return MainMenu();

            case ('5'):
                otherInfo();
                return MainMenu();

            case ('6'):
                otherInfo();
                return MainMenu();

            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}


void Menu::maxWater() {
    char inputTypeO;
    cout << endl << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│      Get Max Amount of Water       │" << endl
         << "├────────────────────────────────────┤" << endl
         << "│  1 - From all Cities               │" << endl
         << "│  2 - By a Specific City            │" << endl
         << "│  b - Go Back                       │" << endl
         << "│  e - Exit                          │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl
         << "What would you like to do next? ";

    int flag = 1;
    string inputOrigin;
    int inputRadiusO = 0;

    while (flag) {
        cout << "Choose an option: ";
        cin >> inputTypeO;

        switch (inputTypeO) {
            case ('1'):
                data_.maxFLowTotalCity(0, "");

                flag = 0;
                break;

            case ('2'):
                cout << endl << "Insert city: [Format: city or code]" << endl;
                getline(cin >> ws, inputOrigin);
                if ((data_.getCitiesC()[inputOrigin] == nullptr) && (data_.getCitiesN()[inputOrigin] == nullptr)) {
                    cout << "\nNot a valid city...\nTry again!\n\n";
                    maxWater();
                }
                data_.maxFLowTotalCity(1, inputOrigin);
                flag = 0;
                break;

            case ('b'):
                return;
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}
/*
    cout << endl;
    cout << "Choose the type of destination:" << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│  1 - By Airport                    │" << endl
         << "│  2 - By City                       │" << endl
         << "│  3 - By Coordinates                │" << endl
         << "│  4 - By Coordinates & Radius       │" << endl
         << "│  b - Go Back                       │" << endl
         << "│  e - Exit                          │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl
         << "What would you like to do next? ";

    char inputTypeD;
    string inputDestination;
    int inputRadiusD = 0;
    int flag2 = 1;
    while (flag2){
        cout << "Choose option: ";
        cin >> inputTypeD;
        switch (inputTypeD) {
            case ('1'):
                cout << endl << "Insert destination airport: " << endl;
                cin >> inputDestination;
                if (data_.getAirports().find(inputDestination) == data_.getAirports().end()){
                    cout << "\nNot a valid airport...\nTry again!\n\n";
                    findFlights();
                }
                flag2 = 0;
                break;

            case ('2'):
                cout << endl << "Insert destination city: [Format: <city>,<country> (because of repeated city names)]" << endl;
                getline(cin >>ws, inputDestination);
                if (data_.getCities().find(inputDestination) == data_.getCities().end()){
                    cout << "\nNot a valid city...\nTry again!\n\n";
                    findFlights();
                }
                flag2 = 0;
                break;
            case ('3'):
                cout << endl << "Insert destination coordinates: [Format: x.(...),y.(...)]" << endl;
                cin >> inputDestination;
                flag2 = 0;
                break;
            case ('4'):
                cout << endl << "Insert destination coordinates: [Format: x.(...),y.(...)]" << endl;
                cin >> inputDestination;
                flag2 = 0;
                cout << endl << "Insert radius: " << endl;
                cin >> inputRadiusD;
                break;
            case ('b'):
                return;

            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }

    //filters

    cout << "Do you want an airline filter?" << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│  y - Yes                           │" << endl
         << "│  n - No                            │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl
         << "What would you like to do next? ";
    char yn;
    vector<string> filters = {};
    bool flag3 = true;
    while(flag3) {
        cout << "Choose option: ";
        cin >> yn;
        switch (yn) {
            case ('y'):
                filters = createVec();
                flag3 = 0;
                break;
            case ('n'):
                flag3 = 0;
                break;
            default:
                cout << "Not a valid option!" << endl;
        }
    }

    data_.getFlights(inputOrigin, inputDestination, inputTypeO-48, inputTypeD-48, filters,inputRadiusO ,inputRadiusD);
    back();
    return MainMenu();
}

*/

void Menu::deficitPerCity() {
    char option1;
    cout << endl << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│          Deficit per City          │" << endl
         << "├────────────────────────────────────┤" << endl
         << "│  1 - From all cities               │" << endl
         << "│  b - Go Back                       │" << endl
         << "│  e - Exit                          │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl
         << "What would you like to do next? ";

    while(true) {
        cout << "Choose an option: ";
        cin >> option1;

        switch(option1) {
            case ('1'):
                data_.getDeficit();
                return deficitPerCity();
            case ('b'):
                return MainMenu();
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}

/*
void Menu::globalStatistics() {
    char option;
    cout << endl << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│          Global Statistics         │" << endl
         << "├────────────────────────────────────┤" << endl
         << "│  1 - Total Airports                │" << endl
         << "│  2 - Total Airlines                │" << endl
         << "│  3 - Total Flights                 │" << endl
         << "│  b - Go Back                       │" << endl
         << "│  e - Exit                          │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl
         << "What would you like to do next? ";


    while(true) {
        cout << "Choose an option: ";
        cin >> option;

        switch(option) {
            case ('1'):
                cout << "Number of airports: " << data_.nrAirports() << endl;
                back();
                return getStatistics();
            case ('2'):
                cout << "Number of airlines: " << data_.nrAirlines() << endl;
                back();
                return getStatistics();
            case ('3'):
                cout << "Number of flights: " << data_.nrFlights() << endl;
                back();
                return getStatistics();
            case ('b'):
                return;
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}



*/


void Menu::balanceFlow() {
    char ip;
    //string ap;

    cout << "┌─────────────────────────────────────────────────────────────────┐" << endl
         << "│                          Balance Flow                           │" << endl
         << "├─────────────────────────────────────────────────────────────────┤" << endl
         << "│  1 - Balance Flow of Water across Network                       │" << endl
         << "│  b - Go Back                                                    │" << endl
         << "│  e - Exit                                                       │" << endl
         << "└─────────────────────────────────────────────────────────────────┘" << endl
         << endl
         << "What would you like to do next? ";

    while(true) {
        cout << "Choose an option: ";
        cin >> ip;

        switch (ip) {
            case ('1'):
                //cout << "Please insert the origin airport code: " << endl;
                //cin >> ap;

                //if (data_.getAirports().find(ap) == data_.getAirports().end()){
                //    cout << "\nNot a valid airport...\nTry again!\n\n";
                //    balanceFlow();
                //}


                data_.getAverageDifference();
                data_.BalanceFlow();
                data_.getAverageDifference();
                back();
                return balanceFlow();
            case ('b'):
                return;

            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}



void Menu::otherInfo() {
    char option;
    int k;
    cout << endl << endl;
    cout << "┌────────────────────────────────────────────────┐" << endl
         << "│                   Other Info                   │" << endl
         << "├────────────────────────────────────────────────┤" << endl
         << "│  1 - Airport with top-K number of flights      │" << endl
         << "│  2 - Articulation Points                       │" << endl
         << "│  3 - Maximum Trip                              │" << endl
         << "│  b - Go Back                                   │" << endl
         << "│  e - Exit                                      │" << endl
         << "└────────────────────────────────────────────────┘" << endl
         << endl
         << "What would you like to do next? ";


    while(true) {
        cout << "Choose an option: ";
        cin >> option;

        switch(option) {
            case ('1') : {
                cout << "Top-K airport with most flights? ";
                cin >> k;
                //data_.maxKAirport(k);
                back();
                return otherInfo();
            }
            case ('2'):
                //data_.essentialAirports();
                back();
                return otherInfo();

            case('3'):
                //data_.MaximumTrip();
                back();
                return otherInfo();
            case ('b'):
                return;
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}


/*
vector<string> Menu::createVec() {
    bool flag = true;
    vector<string> v = {};
    cout << "Type airlines to filter and hit Enter and 'd' when done.\n\n";

    while(flag){
        string inp = "";
        cin >> inp;
        if ( inp == "d") flag = false;
        else{
            if (data_.getAirlines().find(inp) != data_.getAirlines().end())
                v.push_back(inp);
            else cout << "Not a valid airline."<< endl;
        }
    }
    cout << "Filters applied." << endl;
    return v;
}

*/


void Menu::back() const {
    char input;
    cout << endl << endl;
    cout << "b - Back" << endl
         << "e - Exit" << endl;

    while (true){
        cout << "Choose option: ";
        cin >> input;
        switch (input) {
            case ('b'):
                return;
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}

void Menu::exitProgram() const {
    cout << endl << "Exiting program..." << endl;
    exit(0);
}
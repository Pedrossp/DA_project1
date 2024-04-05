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
                 << "│  4 - Failures on Network          │" << endl
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
                networkFailures();
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



void Menu::networkFailures() {
    char option;
    cout << endl << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│        Failures on Network         │" << endl
         << "├────────────────────────────────────┤" << endl
         << "│  1 - Reservoirs Out of Comission   │" << endl
         << "│  2 - Pumping Stations Removed      │" << endl
         << "│  3 - Pipeline Rupture              │" << endl
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
                removedReservoir();
                back();
                return networkFailures();
            case ('2'):
                removedStation();
                back();
                return networkFailures();
            case ('3'):
                removedPipe();
                back();
                return networkFailures();
            case ('b'):
                return;
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}

void Menu::removedReservoir() {
    char option;
    vector<string> a;

    cout << endl << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│     Reservoirs Out of Comission    │" << endl
         << "├────────────────────────────────────┤" << endl
         << "│  1 - See Affected Cities           │" << endl
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
                a = createVecR();

                if(a.empty()){
                    cout << "No values selected." << endl;
                    return;
                }

                data_.reservoirOutOfCommission(a);

                back();
                return removedReservoir();

            case ('b'):
                return;
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}




void Menu::removedStation() {
    char option;
    vector<string> sC;

    cout << endl << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│      Pumping Stations Removed      │" << endl
         << "├────────────────────────────────────┤" << endl
         << "│  1 - See Affected Cities           │" << endl
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

                sC = createVecS();

                if(sC.empty()){
                    cout << "No values selected." << endl;
                    return;
                }


                data_.stationRemoved(sC);

                back();
                return removedStation();

            case ('b'):
                return;
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}




void Menu::removedPipe() {
    char option;

    vector<pair<string, string>> pC;

    cout << endl << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│          Pipeline Rupture          │" << endl
         << "├────────────────────────────────────┤" << endl
         << "│  1 - See Affected Cities           │" << endl
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

                pC = createVecPipe();

                if(pC.empty()){
                    cout << "No valid values selected." << endl;
                    return;
                }

                data_.pipelineRemoved(pC);

                back();
                return removedPipe();

            case ('b'):
                return;
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}




vector<string> Menu::createVecR() {
    bool flag = true;
    vector<string> v = {};

    cout << "Type Reservoir Codes/Names to remove and hit Enter and 'd' when done.\n\n";

    while(flag){
        string inp = "";
        cin >> inp;

        if ( inp == "d") flag = false;
        else{
            auto it = data_.getReservoirs().find(inp);

            if (it != data_.getReservoirs().end()){
                v.push_back(inp);

            }

            else {
                cout << "Not a valid Reservoir."<< endl;
            }
        }
    }

    if(!v.empty()) cout << "List done." << endl << endl;

    return v;
}



vector<string> Menu::createVecS() {
    bool flag = true;
    vector<string> v = {};

    cout << "Type Station Codes to remove and hit Enter and 'd' when done.\n\n";

    while(flag){
        string inp = "";
        cin >> inp;
        if ( inp == "d") flag = false;
        else{
            auto it = data_.getStations().find(inp);

            if (it != data_.getStations().end())
                v.push_back(inp);

            else cout << "Not a valid Station."<< endl;
        }
    }

    if(!v.empty()) cout << "List done." << endl << endl;

    return v;
}



vector<pair<string, string>> Menu::createVecPipe() {
    bool flag = true;
    vector<pair<string, string>> v = {};
    cout << "Type Origin code and Destiny Code to remove and hit Enter and 'd' when done.\n\n";
    cout << "Insert a pair (One Code per line): " << endl;

    while(flag){
        string pipe1 = "";
        string pipe2 = "";

        cin >> pipe1;

        if ( pipe1 == "d") break;
        cin >> pipe2;
        if (pipe2 == "d") break;

        if((pipe1 != "d") && (pipe2 != "d")){

            if((data_.getGraph().findVertex(pipe1) != nullptr) && (data_.getGraph().findVertex(pipe2) != nullptr)){
                v.push_back({pipe1, pipe2});
                cout << "Insert another pair (One Code per line) or type 'd' if done:" << endl;
            }

            else cout << "Invalid values."<< endl;
        }
    }

    if(!v.empty()) cout << "List done." << endl << endl;

    return v;
}




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
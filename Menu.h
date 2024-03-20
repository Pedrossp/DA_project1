//
// Created by sofia on 20-03-2024.
//

#ifndef DA_PROJECT1_MENU_H
#define DA_PROJECT1_MENU_H

#include "DataManip.h"

class Menu {

private:
    DataManip data_;


public:
    Menu(DataManip data);

    void MainMenu();

    void otherInfo();

    void back() const;
    void exitProgram() const;
};


#endif //DA_PROJECT1_MENU_H

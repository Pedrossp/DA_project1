#ifndef DA_PROJECT1_MENU_H
#define DA_PROJECT1_MENU_H

#include "DataManip.h"

class Menu {

private:
    DataManip data_;


public:
    Menu(DataManip data);

    void MainMenu();

    void maxWater();
    void deficitPerCity();
    void balanceFlow();

    void otherInfo();

    void back() const;
    void exitProgram() const;
};


#endif //DA_PROJECT1_MENU_H

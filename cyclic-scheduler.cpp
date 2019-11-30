/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Red Hat, Inc. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <iostream>
#define ever (;;)

using std::cout;
using std::endl;

void runMD() {
    cout << "Running Multiple Card Dispenser Task" << endl;
}

void runSD() {
    cout << "Running Singular Card Dispenser Task" << endl;
}

bool checkCardPlaced() {
    cout << "Checking if Card is Placed" << endl;
    return false;
}

int getCardPlacement() {
    cout << "Getting card Placement from PI" << endl;
    return 1;
}

void pushPiston(){
    cout << "Pushed the Piston" << endl;
}

void positionCardCollector(int placement) {
    cout << "Position the Card Collector..." << endl;
    pushPiston();
}


int main()
{
    for ever {
        runMD();
        runSD();
        if (checkCardPlaced()){
            positionCardCollector(getCardPlacement());
        }
    }
    return 0;
}

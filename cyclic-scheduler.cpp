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
    ev3_motor_config(EV3_PORT_A, LARGE_MOTOR);
    int32_t motorCount = ev3_motor_get_counts(EV3_PORT_A);
    while(motorCount >= -360)
    {
        ev3_motor_set_power(EV3_PORT_A, (int)-20);
        motorCount = ev3_motor_get_counts(EV3_PORT_A);
	    ev3_motor_set_power(EV3_PORT_A, (int)0);
    }
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

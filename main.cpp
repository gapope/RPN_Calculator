/*****************************************************************************
 *	Name: Greg Pope                                                          *
 *	Course: ICS4U                                                            *
 *	Date: Oct. 24, 2017                                                      *
 *	                                                                         *
 *	Purpose:                                                                 *
 *	    A calculator which uses reverse-polish notation                      *
 *	Usage:                                                                   *
 *	                                                                         *
 *	Revision History:                                                        *
 *	                                                                         *
 *	Known Issues:                                                            *
 *	                                                                         *
 *****************************************************************************/

#include <iostream>
#include "Calculator.h"

using namespace std;

int intakeNum(Calculator &myCalc);

int main()
{
    Calculator myCalc;

    bool running = true;

    int nums = 0;

    while (running) {
        char inputC = 'a';

        if (nums < 2) {
            nums += intakeNum(myCalc);
        } else {
            cout << "Please enter an operator (+, -, *, /): ";
            cin >> inputC;

            if (!myCalc.PushOp(inputC)) {
                cout << "That is not a valid operator" << endl;
            }

            cout << myCalc.Pop()<< endl;

            cout << "This equals: ";
            cout << myCalc.Operate() << endl;

            nums--;
        }

        if (inputC == 'q' || inputC == 'Q') {
            running = false;
        }
    }

    return 0;
}

int intakeNum(Calculator &myCalc) {
    float input = 0;

    cout << "Please enter a number: ";
    if (!(cin >> input)) {
        cerr << "That was not a valid number" << endl;
        cin.clear();
        return 0;
    }

    myCalc.Push(input);

    return 1;
}

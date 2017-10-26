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
#include <cstring>
#include "Calculator.h"
#include <windows.h>
#include <ctime>

using namespace std;

int intakeNum(Calculator &myCalc);
void buildScreen(short width);
void buildSides(short width);
void buildTop(short width);
void buildBottom(short width);


//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


int main()
{
    buildScreen(25);
    int intake;
    cin >> intake;

    /*
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
    }*/

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

void buildScreen(short width) {
    buildTop(width);
    buildSides(width);
    buildBottom(width);

}

void buildSides(short width) {
    char  vert = (char) (179);

    cout << vert;

    gotoxy(width + 1, 1);

    cout << vert << endl;
}

void buildTop(short width) {
    char topLeft = (218), hor = (196), topRight = (191);

    cout << topLeft;

    for (int i = 0; i < width; i++) {
        cout << hor;
    }

    cout << topRight << endl;
}

void buildBottom(short width) {
    char bottomLeft = (192), hor = (196), bottomRight = (217);

    cout << bottomLeft;

    for (int i = 0; i < width; i++) {
        cout << hor;
    }

    cout << bottomRight << endl;
}

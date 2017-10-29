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

void buildScreen(short width, const string error, Calculator &myCalc);
void buildBox(short width, short height, short x, short y);

//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
    string intake, error = "";

    Calculator myCalc;

    short nums;

    while (true) { //Infite running loop until break

        //Making things look nice
        system("cls");
        buildScreen(25, error, myCalc);

        gotoxy(5, 2);
        cin >> intake;

        //Registering number if present
        for (unsigned int i = 0; i < intake.length(); i++) {
            if (intake.c_str()[i] < 48 || intake.c_str()[i] > 57) {
                error = true;
                break;
            } else if (i == intake.length() - 1) {
                myCalc.Push(stof(intake));
                error = "";
                nums++;
            }
        }

        //Quit program
        if (intake.compare("quit") == 0 || intake.compare("Quit") == 0) {
            gotoxy(0, 20);
            break;
        }
        //Standard operations
        else if (intake.c_str()[0] == '+' || intake.c_str()[0] == '-' || intake.c_str()[0] == '*' || intake.c_str()[0] == '/') {
            if (nums > 1) {
                myCalc.Operate(intake.c_str()[0]);

                nums--;

                error = "";
            } else {
                error = "Not enough numbers for this operation";
            }
        }
        //Swap
        else if (intake.compare("swap") == 0 || intake.compare("Quit")) {
            if (nums > 1) {
                myCalc.Swap();

                error = "";
            } else {
                error = "Not enough numbers for this operation";
            }
        }
        //Clear
        else if (intake.compare("clear") == 0 || intake.compare("Clear") == 0) {
            myCalc.Empty();
        }

    }

    return 0;
}

void buildScreen(short width, const string error, Calculator &myCalc) {

    buildBox(width, 3, 3, 0); //Typing box

    buildBox(width, 10, 3, 6); //Command list

    buildBox(5, 5, 35, 0); //Stack contents box

    float temp[20] = {};

    short nums = 0;

    //Showing stack contents
    while (myCalc.Valid()) {
        temp[nums] = myCalc.Pop();

        gotoxy(36, nums + 1);
        cout << temp[nums];

        nums++;
    }

    //Refilling stack
    for (int i = nums - 1; i >= 0; i--) {
        myCalc.Push(temp[i]);
    }

    //Displaying error message
    if (error.compare("") != 0) {
        gotoxy(25,25);
        cout << error;
    }

}

//Draws a box of specified size at a specified point
void buildBox (short width, short height, short x, short y) {
    gotoxy(x, y); //Inital point setting

    //Drawing top of box
    char topLeft = (218), hor = (196), topRight = (191);

    cout << topLeft;

    for (int i = 0; i < width; i++) {
        cout << hor;
    }

    cout << topRight << endl;

    //Drawing sides of box
    char  vert = (char) (179);

    for (int i = 0; i < height; i++) {
        gotoxy(x, y + i + 1);
        cout << vert;

        gotoxy(x + width + 1, y + i + 1);

        cout << vert << endl;
    }

    //Drawing bottom of box
    char bottomLeft = (192), bottomRight = (217);

    gotoxy(x, y + height);

    cout << bottomLeft;

    for (int i = 0; i < width; i++) {
        cout << hor;
    }

    cout << bottomRight << endl;
}

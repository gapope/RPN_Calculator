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

void buildScreen(short width, const string &error, Calculator &myCalc);
void buildBox(short width, short height, short x, short y);

//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
    string intake, error;

    Calculator myCalc;

    short nums = 0;

    while (true) { //Infinite running loop until break

        //Making things look nice
        system("cls");
        buildScreen(25, error, myCalc);

        error.clear();

        gotoxy(5, 2);
        cin >> intake;

        //Quit program
        if (intake.compare("quit") == 0 || intake.compare("Quit") == 0) {
            gotoxy(0, 20);
            break;
        }
        //Swap
        else if (intake.compare("swap") == 0 || intake.compare("Swap") == 0) {
            if (nums > 1) {
                myCalc.Swap();
            } else {
                error = "Not enough numbers for this operation";
            }
        }
        //Clears entire list of numbers
        else if (intake.compare("clear") == 0 || intake.compare("Clear") == 0) {
            myCalc.Empty();
            nums = 0;
        }
        //Remove top number
        else if (intake.compare("remove") == 0 || intake.compare("Remove") == 0) {
            myCalc.Pop();
            nums--;
        }
        //Standard operations
        else if (intake.at(0) == '+' || intake.at(0) == '-' || intake.at(0) == '*' || intake.at(0) == '/') {
            if (nums > 1) {
                myCalc.Operate(intake.at(0));

                nums--;
            } else {
                error = "Not enough numbers for this operation";
            }
        }
        //second last input to the power of last input
        else if (intake.compare("pow") == 0 || intake.compare("Pow") == 0 || intake.compare("^") == 0) {
            if (nums > 1) {
                myCalc.Exp();
                nums--;
            } else {
                error = "Not enough numbers for this operation";
            }
        }
        //Square rooting
        else if (intake.compare("sqrt") == 0) {
            if (nums > 0) {
                myCalc.Root();
            } else {
                error = "Not enough numbers for this operation";
            }
        }
        //Pi Constant
        else if (intake.compare("pi") == 0 || intake.compare("Pi") == 0) {
            myCalc.Pi();
            nums++;
        }
        //e constant
        else if (intake.compare("e") == 0) {
            myCalc.e();
            nums++;
        }
        //General error fail
        else {
            error = "Invalid number or command";
        }

        //Registering number if present
        for (unsigned int i = 0; i < intake.length(); i++) {
            if (intake.at(i) < 48 || intake.at(i) > 57) {
                break;
            } else if (i == intake.length() - 1) {
                myCalc.Push(stof(intake));
                nums++;
                error.clear();
            }
        }

    }

    return 0;
}

void buildScreen(short width, const string &error, Calculator &myCalc) {
    buildBox(width, 3, 3, 0); //Typing box

    buildBox(width, 10, 3, 5); //Command list

    gotoxy(5, 6);

    cout << "+    -    *    /  clear";

    gotoxy(5, 8);

    cout << "pow  sqrt  swap  remove";

    gotoxy(5, 10);

    cout << "pi e   quit";

    buildBox(10, 3, 35, 0); //Stack contents box

    //Showing stack contents
    if (myCalc.Valid()) {
        gotoxy(36, 1);
        cout << myCalc.Head()->Value();

        if (myCalc.Head()->Next() != nullptr) {
            gotoxy(36, 2);
            cout << myCalc.Head()->Next()->Value();
        }
    } else { //No values in stack
        gotoxy(36, 1);
        cout << "empty";
    }

    //Displaying error message
    if (!error.empty()) {
        gotoxy(4, 4);
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

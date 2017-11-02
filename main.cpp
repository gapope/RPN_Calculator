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

bool commandCheck(Calculator &myCalc, short &nums, const string &intake, string &error);
void numCheck(Calculator &myCalc, short &nums, const string &intake, string &error);
void buildScreen(Calculator &myCalc, const string &error);
void buildBox(short width, short height, short x, short y);

//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() {
    string intake, message;

    Calculator myCalc(false);
    message = "The calculator uses degrees by default";

    short nums = 0;

    //Infinite running loop until break
    while (true) {

        //Making things look nice
        system("cls");
        buildScreen(myCalc, message);

        message.clear();

        gotoxy(5, 2);
        cin >> intake;

        if (intake.compare("quit") == 0 || intake.compare("Quit") == 0) { //Does the user want to quit
            break;
        } else if (!commandCheck(myCalc, nums, intake, message)) { //Did they enter a command?
            numCheck(myCalc, nums, intake, message); //If not, was it a number
        }
    }

    gotoxy(3, 20);
    cout << "Thanks for using this RPN calculator" << endl;

    return 0;
}

//Function to analyse put string and see if it is a valid function
bool commandCheck(Calculator &myCalc, short &nums, const string &intake, string &error) {
    //Swap
    if (intake.compare("swap") == 0 || intake.compare("Swap") == 0) {
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
            myCalc.Power();
            nums--;
        } else {
            error = "Not enough numbers for this operation";
        }
    }
    //Square rooting
    else if (intake.compare("sqrt") == 0 || intake.compare("") == 0) {
        if (nums > 0) {
            myCalc.Root();
        } else {
            error = "Not enough numbers for this operation";
        }
    }
    //Setting calc to degrees
    else if (intake.compare("deg") == 0 || intake.compare("Deg") == 0) {
        myCalc.SetRad(false);
        error = "The calculator now uses degrees";
    }
    //Setting calc to radians
    else if (intake.compare("rad") == 0 || intake.compare("Rad") == 0) {
        myCalc.SetRad(true);
        error = "The calculator now uses radians";
    }
    //Finding sine
    else if (intake.compare("sin") == 0 || intake.compare("Sin") == 0) {
        if (nums > 0) {
            myCalc.Sine();
        } else {
            error = "Not enough numbers for this operation";
        }
    }
    //Finding sine
    else if (intake.compare("cos") == 0 || intake.compare("Cos") == 0) {
        if (nums > 0) {
            myCalc.Cosine();
        } else {
            error = "Not enough numbers for this operation";
        }
    }
    //Finding sine
    else if (intake.compare("tan") == 0 || intake.compare("Tan") == 0) {
        if (nums > 0) {
            myCalc.Tangent();
        } else {
            error = "Not enough numbers for this operation";
        }
    }
    //Logarithm
    else if (intake.compare("log") == 0 || intake.compare("Log") == 0) {
        if (nums > 0) {
            myCalc.Logarithm();
        } else {
            error = "Not enough numbers for this operation";
        }
    }
    //natural logarithm
    else if (intake.compare("ln") == 0 || intake.compare("Ln") == 0) {
        if (nums > 0) {
            myCalc.Ln();
        } else {
            error = "Not enough numbers for this operation";
        }
    }
    //Pi Constant
    else if (intake.compare("pi") == 0 || intake.compare("Pi") == 0) {
        myCalc.Pi();
        nums++;
    }
    //euler's constant
    else if (intake.compare("e") == 0 || intake.compare("E") == 0) {
        myCalc.E();
        nums++;
    }
    //General error fail
    else {
        error = "Invalid number or command";
        return false;
    }

    return true;
}

//Function to analyse input string and see if it is a valid number
void numCheck(Calculator &myCalc, short &nums, const string &intake, string &error) {
    //Registering number if present
    for (unsigned int i = 0; i < intake.length(); i++) {
        if (intake.at(i) < '0' || intake.at(i) > '9') {
            break;
        } else if (i == intake.length() - 1) {
            myCalc.Push(stof(intake));
            nums++;
            error.clear();
        }
    }
}

//Function to build calculator interface including take and display boxes as well and command/operator lists
void buildScreen(Calculator &myCalc, const string &message) {
    //Typing box
    buildBox(25, 3, 3, 0);

    //Operation list
    buildBox(25, 10, 3, 5);

    gotoxy(5, 6);
    cout << "+    -    *    /";

    gotoxy(5, 8);
    cout << "pow  sqrt";

    gotoxy(5, 10);
    cout << "sin cos tan  deg  rad";

    gotoxy(5, 12);
    cout << "log  ln";

    gotoxy(5, 14);
    cout << "pi e";

    //Command list
    buildBox(7, 8, 35, 5);

    gotoxy(36, 6);
    cout << "clear";

    gotoxy(36, 8);
    cout << "remove";

    gotoxy(36, 10);
    cout << "swap";

    gotoxy(36, 12);
    cout << "quit";

    //Stack contents box
    buildBox(10, 3, 35, 0);

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

    //Displaying info message
    if (!message.empty()) {
        gotoxy(4, 4);
        cout << message;
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

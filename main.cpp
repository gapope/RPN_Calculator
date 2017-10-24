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
#include "Stack.h"

using namespace std;

int main()
{
    //Node head('a');

    Stack myStack;

    myStack.Push('a');
    myStack.Push('e');
    myStack.Push('f');
    myStack.Push('5');


    //char hold = head.pop();

    //cout << head.Value() << endl;

    cout << myStack.Pop() << endl;
    cout << myStack.Pop() << endl;
    cout << myStack.Pop() << endl;
    cout << myStack.Pop() << endl;
    return 0;
}

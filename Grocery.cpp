/**
 * 
 * Interactive program that will display a menu of options for a user to 
 * view the items that have been purchased in store for a given day
 * 
 * The program uses a text list of items - Grocery.txt
 * 
 * Author: Sean Reid
 * Date: 8/14/2021
 * 
 * **/

#include <Python.h>
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <iomanip> // std::setw

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
    char *procname = new char[pName.length() + 1];
    strcpy(procname, pName.c_str());

    Py_Initialize();

    cout << "2\n";
    PyObject *my_module = PyImport_ImportModule("Grocery");
    PyErr_Print();
    PyObject *my_function = PyObject_GetAttrString(my_module, procname);
    PyObject *my_result = PyObject_CallObject(my_function, NULL);
    Py_Finalize();

    delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen: 
		You sent me: Test
Return:
	100 is returned to the C++	
*/
int callIntFunc(string proc, string param)
{
    char *procname = new char[proc.length() + 1];
    strcpy(procname, proc.c_str());

    char *paramval = new char[param.length() + 1];
    strcpy(paramval, param.c_str());

    PyObject *pName, *pModule, *pDict, *pFunc, *pValue = nullptr, *presult = nullptr;
    // Initialize the Python Interpreter
    Py_Initialize();
    // Build the name object
    pName = PyUnicode_FromString((char *)"Grocery");
    // Load the module object
    pModule = PyImport_Import(pName);
    // pDict is a borrowed reference
    pDict = PyModule_GetDict(pModule);
    // pFunc is also a borrowed reference
    pFunc = PyDict_GetItemString(pDict, procname);
    if (PyCallable_Check(pFunc))
    {
        pValue = Py_BuildValue("(z)", paramval);
        PyErr_Print();
        presult = PyObject_CallObject(pFunc, pValue);
        PyErr_Print();
    }
    else
    {
        PyErr_Print();
    }
    //printf("Result is %d\n", _PyLong_AsInt(presult));
    Py_DECREF(pValue);
    // Clean up
    Py_DECREF(pModule);
    Py_DECREF(pName);
    // Finish the Python Interpreter
    Py_Finalize();

    // clean
    delete[] procname;
    delete[] paramval;

    return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
    char *procname = new char[proc.length() + 1];
    strcpy(procname, proc.c_str());

    PyObject *pName, *pModule, *pDict, *pFunc, *pValue = nullptr, *presult = nullptr;
    // Initialize the Python Interpreter
    Py_Initialize();
    // Build the name object
    pName = PyUnicode_FromString((char *)"Grocery");
    // Load the module object
    pModule = PyImport_Import(pName);
    // pDict is a borrowed reference
    pDict = PyModule_GetDict(pModule);
    // pFunc is also a borrowed reference
    pFunc = PyDict_GetItemString(pDict, procname);
    if (PyCallable_Check(pFunc))
    {
        pValue = Py_BuildValue("(i)", param);
        PyErr_Print();
        presult = PyObject_CallObject(pFunc, pValue);
        PyErr_Print();
    }
    else
    {
        PyErr_Print();
    }
    //printf("Result is %d\n", _PyLong_AsInt(presult));
    Py_DECREF(pValue);
    // Clean up
    Py_DECREF(pModule);
    Py_DECREF(pName);
    // Finish the Python Interpreter
    Py_Finalize();

    // clean
    delete[] procname;

    return _PyLong_AsInt(presult);
}

/**
 * Helper function to pad the menu
 * Takes the string of the menu line
*/
void PrintPaddedLine(string line)
{
    cout << setw(42);
    cout << line << endl;
}

/**
 * Displays the menu
*/
void displayMenu()
{
    cout << endl;
    PrintPaddedLine("*************************************");
    PrintPaddedLine("* 1 - List of Purchased Items       *");
    PrintPaddedLine("* 2 - Count an Item                 *");
    PrintPaddedLine("* 3 - Display Chart of Items        *");
    PrintPaddedLine("* 4 - Exit Program                  *");
    PrintPaddedLine("************************************");
}

void countItem()
{
    string item;
    cout << "Enter item to count:" << endl;
    cin >> item;
    cout << "Found " << callIntFunc("counter", item) << " " << item << endl;
}

int main()
{
    setenv("PYTHONPATH", ".", 1);
    int selection = 0;
    while (selection != 4)
    {
        if (selection > 4 || selection < 1)
        {
            cout << " -----------------   !!!!!!!!!!!   ---------------------" << endl;
            cout << "Please choose a number from 1 to 4 as shown in the menu." << endl;
        }
        if (selection == 1)
        {
            CallProcedure("printItems");
        }
        if (selection == 2)
        {
            countItem();
        }
        if (selection == 3)
        {
            CallProcedure("histogram");
        }
        displayMenu();
        cin >> selection;
    }
    return 0;
}
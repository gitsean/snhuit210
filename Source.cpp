#include <Python.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    cout << "Start 1 \n";
    setenv("PYTHONPATH", ".", 1);
    Py_Initialize();
    cout << "2\n";
    PyObject *my_module = PyImport_ImportModule("sample");
    cerr << my_module << "\n";
    PyErr_Print();
    cerr << "3\n";
    PyObject *my_function = PyObject_GetAttrString(my_module, "printsomething");
    cout << "4 / n";
    PyObject *my_result = PyObject_CallObject(my_function, NULL);
    Py_Finalize();
    return 0;
}
#include <iostream>
#include <fstream>
using namespace std;

/**
 * This program reads a properly formatted file of cities and Fahrenheit temps
 * and creates a separate file listing all citie and the temperature in Celsius.
 * 
 * Author: Sean Reid
 * Date: 7/26/2021
 * 
*/

int main()
{
    ifstream inFS;     // Input file stream
    ofstream outFS;    // Output file stream
    int fileNum;       // Data value from file
    string fileString; // Data from file in string format

    inFS.open("FahrenheitTemperature.txt");
    if (!inFS.is_open())
    {
        cout << "Could not open file FahrenheitTemperature.txt." << endl;
        return 1; // 1 indicates error
    }

    outFS.open("CelsiusTemperature.txt");
    if (!outFS.is_open())
    {
        cout << "Could not open file CelsiusTemperature.txt." << endl;
        return 1; // 1 indicates error
    }

    while (!inFS.eof())
    {
        inFS >> fileString;
        inFS >> fileNum;
        fileNum = (fileNum - 32) * 5;
        fileNum = fileNum / 9;
        outFS << fileString << " " << fileNum << endl;
    }
    if (!inFS.eof())
    {
        cout << "Input failure before reaching end of file." << endl;
    }

    inFS.close();
    outFS.close();

    return 0;
}
/**
 * 
 * This program puts out two clocks that show the same time 
 * One will show the time in a 12 hour format, the other
 * will show in a 24 hour format.
 * 
 * Author: Sean Reid
 * Date: 7/13/2021
 * 
 **/

#include <iostream>
#include <iomanip> // std::setw
#include <ctime>   //time, localtime

using namespace std;

/**
 * 
 * Display the clocks
 * Takes hour, minute, second
 * Hours should be 0-23
 * 
 */
void DisplayClocks(int hour, int minute, int second)
{

    int smallHour = hour;
    string ampm = "AM";

    if (hour > 11)
    {
        smallHour = hour - 12;
        ampm = "PM";
    }
    if (smallHour < 1)
    {
        smallHour = 12;
    }

    cout << endl;
    printf("**************************      **************************\n");
    printf("*     12-Hour Clock      *      *      24-Hour Clock     *\n");
    printf("*     ");
    printf("%02d:%02d:%02d", smallHour, minute, second);
    printf("  %s       *      *      ", ampm.c_str());
    printf("  %02d:%02d:%02d        *\n", hour, minute, second);
    printf("**************************      **************************\n");
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
void DisplayMenu()
{
    cout << endl;
    PrintPaddedLine("**************************");
    PrintPaddedLine("* 1 - Add One Hour       *");
    PrintPaddedLine("* 2 - Add One Minute     *");
    PrintPaddedLine("* 3 - Add One Second     *");
    PrintPaddedLine("* 4 - Exit Program       *");
    PrintPaddedLine("**************************");
}

/**
 * Get the time from the processor
 * Updates the variables passed by reference
*/
void GetTime(int &hour, int &min, int &sec)
{
    // current date/time based on current system
    time_t now = time(0);
    tm *ltm = localtime(&now);

    hour = ltm->tm_hour;
    min = ltm->tm_min;
    sec = ltm->tm_sec;
}

/**
 * Add one hour, minute or second to set
 * of hour, minute, second integers
*/
void addOne(int &hour, int &min, int &sec, string type)
{
    if (type == "second")
    {
        ++sec;
    }
    else if (type == "minute")
    {
        ++min;
    }
    else
    {
        ++hour;
    }
    if (sec > 59)
    {
        sec = 0;
        ++min;
    }
    if (min > 59)
    {
        min = 0;
        ++hour;
    }
    if (hour > 23)
    {
        hour = 0;
    }
}

int main()
{
    int selection = 0;
    int hour;
    int minute;
    int second;

    GetTime(hour, minute, second); // Get the initial time
    while (selection != 4)
    {

        if (selection == 1)
        {
            addOne(hour, minute, second, "hour");
        }
        if (selection == 2)
        {
            addOne(hour, minute, second, "minute");
        }
        if (selection == 3)
        {
            addOne(hour, minute, second, "second");
        }
        cout << "\033[2J\033[1;1H"; // Clear screen
        DisplayClocks(hour, minute, second);
        DisplayMenu();
        cin >> selection;
    }
    return 0;
}
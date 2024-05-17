#include <iostream>
#include <ctime>
#include <iomanip>
#include "Markup.h"

using namespace std;

int main()
{
    time_t currentTime = time(nullptr);

    tm* localTime = localtime(&currentTime);

    int year = localTime -> tm_year + 1900;
    int month = localTime -> tm_mon + 1;
    int day = localTime -> tm_mday;

    cout << "Current date: "  << year << '-'
         << setw(2) << setfill('0') << month << '-'
         << setw(2) << setfill('0') << day << endl;

    CMarkup xml;

    xml.AddElem("data");

    xml.IntoElem();
    xml.AddElem("year", year);
    xml.AddElem("month", month);
    xml.AddElem("day", day);
    xml.OutOfElem();

    xml.Save("users.xml");

    return 0;
}


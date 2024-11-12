#include <iostream>
#include "DataHandler.h"

using namespace std;

int main()
{
    int movieNumber;
    DataHandler DataHandler;

    cout << "Choose movie number (1-110): ";
    cin >> movieNumber;
    cout << "You chose movie number: " << movieNumber << "\n\n";

    string fileName = "../movie_database.csv";
    DataHandler.ReadData(fileName);

    return 0;
}

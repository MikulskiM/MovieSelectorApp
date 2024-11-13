#include <iostream>
#include "DataHandler.h"

using namespace std;

int main()
{
    int movieNumber;
    DataHandler DataHandler;
    string fileName = "../movie_database.csv";

    cout << "Choose movie number (1-110): ";
    cin >> movieNumber;
    cout << "You chose movie number: " << movieNumber << "\n\n";

    DataHandler.LoadMovies(fileName);
    DataHandler.ReadMovies();

    return 0;
}

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

    DataHandler.ReadData(fileName);
    DataHandler.LoadMovies(fileName);
    DataHandler.ReadMovies();

    DataHandler.AddMovie("Deadpool & Wolverine", 2024, "Action", "Comedy");
    DataHandler.SaveData(fileName);
    DataHandler.DisplayScoring();

    return 0;
}

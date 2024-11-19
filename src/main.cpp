#include <iostream>
#include "DataHandler.h"
#include "MovieSelector.h"

using namespace std;

int main()
{
    DataHandler DataHandler;
    MovieSelector MovieSelector;
    string fileName = "../movie_database.csv";

    DataHandler.ReadData(fileName);
    DataHandler.LoadMovies(fileName);
    DataHandler.ReadMovies();

    MovieSelector.askQuestions(DataHandler.movies);

    // DataHandler.AddMovie("Deadpool & Wolverine", 2024, "Action", "Comedy");
    // DataHandler.SaveData(fileName);
    DataHandler.DisplayScoring();

    MovieSelector.proposeMovies(DataHandler.movies);

    return 0;
}

#include <iostream>
#include "DataHandler.h"
#include "Questionaire.h"

using namespace std;

int main()
{
    DataHandler DataHandler;
    string fileName = "../movie_database.csv";

    DataHandler.ReadData(fileName);
    DataHandler.LoadMovies(fileName);
    DataHandler.ReadMovies();

    askQuestions(DataHandler.movies);

    // DataHandler.AddMovie("Deadpool & Wolverine", 2024, "Action", "Comedy");
    // DataHandler.SaveData(fileName);
    DataHandler.DisplayScoring();

    return 0;
}

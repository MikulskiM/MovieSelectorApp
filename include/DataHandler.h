#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <string>
#include <vector>
#include <sstream>
#include "Movie.h"

using namespace std;

/*
 * @class DataHandler
 * @brief Handles all data functionalities like loading, saving, reading...
 */
class DataHandler
{
public:
    vector<Movie> movies;

    int ReadData(string fileName);
    int LoadMovies(string fileName);
    int ReadMovies();
    int AddMovie(string title, int year, string genre1, string genre2);
    int SaveData(string fileName);
    int DisplayScoring();
};

#endif

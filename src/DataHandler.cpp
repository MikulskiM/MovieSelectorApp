#include <fstream>
#include <iostream>
#include "DataHandler.h"

using namespace std;

int OpenFile(ifstream &inputFile, string fileName)
{
    inputFile.open(fileName);

    // Check if inputFile function worked
    if (!inputFile)
    {
        cerr << "ERROR while opening the " << fileName << " file\n";
        return 1;
    }
    return 0;
}

int DataHandler::ReadData(string fileName)
{
    ifstream inputFile;
    string singleLine;

    OpenFile(inputFile, fileName);

    // Read line by line
    while(getline(inputFile, singleLine))
    {
        cout << singleLine << "\n";
    }

    inputFile.close();
    return 0;
}

int DataHandler::LoadMovies(string fileName)
{
    ifstream inputFile;
    string singleLine;
    string title, genre1, genre2;
    int year;

    cout << "\nLoading movies from the database...\n";

    OpenFile(inputFile, fileName);

    while(getline(inputFile, singleLine))
    {
        istringstream singleLineAsStream(singleLine);

        if(getline(singleLineAsStream, title, ',') &&   // title until ,
           singleLineAsStream >> year &&    // put next thing into 'year'
           singleLineAsStream.ignore() &&   // ignore the ,
           getline(singleLineAsStream, genre1, ',') &&  // genre1 until ,
           getline(singleLineAsStream, genre2, ','))    // genre2 until ,
           {
                Movie movie(title, year, genre1, genre2);
                movies.push_back(movie);
           }
    }

    return 0;
}

int DataHandler::ReadMovies()
{
    if(movies.empty())
    {
        cerr << "ERROR: 'movies' vector is empty\n";
        return 1;
    }

    cout << "\nReading movies...\n";

    // for(int i = 0; i < movies.size(); i++)
    // {
    //     cout << i+1 << ". ";
    //     movies[i].print();
    // }

    int index = 1;
    for(auto &movie : movies)
    {
        cout << index << ". ";
        movie.print();
        index++;
    }

    return 0;
}

int DataHandler::AddMovie(string title, int year, string genre1, string genre2)
{
    cout << "\nAdding a movie...\n";
    Movie movie(title, year, genre1, genre2);
    movies.push_back(movie);

    return 0;
}

int DataHandler::SaveData(string fileName)
{
    ofstream file(fileName);
    string singleLine;
    string title, genre1, genre2;
    int year;

    if(movies.empty())
    {
        cerr << "ERROR: 'movies' vector is empty\n";
        return 1;
    }

    cout << "\nSaving data...\n";

    for(auto &movie : movies)
    {
        singleLine = movie.title + "," + to_string(movie.year) + "," +
                     movie.genre1 + "," + movie.genre2;
        file << singleLine << "\n";
    }

    file.close();
    cout << "\nData saved!\n";

    return 0;
}

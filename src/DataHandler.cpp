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
        cerr << "ERROR: 'movies' vector is empty";
        return 1;
    }

    for(int i = 0; i < movies.size(); i++)
    {
        cout << i << ". ";
        movies[i].print();
    }

    return 0;
}

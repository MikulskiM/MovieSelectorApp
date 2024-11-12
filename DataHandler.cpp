#include <fstream>
#include <iostream>
#include "DataHandler.h"

using namespace std;

int DataHandler::ReadData(string fileName)
{
    ifstream inputFile(fileName);

    // Check if inputFile function worked
    if (!inputFile)
    {
        cerr << "ERROR while opening the " << fileName << " file\n";
        return 1;
    }

    // Read line by line
    string singleLine;
    while(getline(inputFile, singleLine))
    {
        cout << singleLine << "\n";
    }

    inputFile.close();
    return 0;
}

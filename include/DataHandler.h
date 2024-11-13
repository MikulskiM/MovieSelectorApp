#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <string>
#include "Movie.h"

using namespace std;

/*
 * @class DataHandler
 * @brief Handles all data functionalities like loading, saving, reading...
 */
class DataHandler
{
public:
    int ReadData(string filename);
};

#endif

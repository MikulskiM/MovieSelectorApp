#ifndef MOVIE_H
#define MOVIE_H

#include <string>

using namespace std;

struct Movie
{
    string title;
    int year;
    string genre1;
    string genre2;
    int scoring = 0;    // score based on user's choices

    void print()
    {
        cout << title << " - " << year << " - "
             << genre1 << " - " << genre2 << "\n";
    }
};

#endif

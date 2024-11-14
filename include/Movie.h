#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iomanip>  // setw, left

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
        cout << title << " - "
             << year << " - "
             << genre1 << " - "
             << genre2 << "\n";
    }

    void printWithScoring()
    {
        cout << setw(4) << right << scoring << " - "
             << setw(14) << left << title.substr(0,14) << " - "
             << setw(5) << year << " - "
             << setw(8) << genre1.substr(0,8) << " - "
             << setw(8) << genre2.substr(0,8) << "\n";
    }
};

#endif

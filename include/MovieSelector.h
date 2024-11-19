#ifndef MOVIE_SELECTOR_H
#define MOVIE_SELECTOR_H

#include <vector>
#include "Movie.h"

/*
 * @class MovieSelector
 * @brief Handles all functionalities needed for movie slection (quiz, scoring, sorting, etc.)
 */
class MovieSelector
{
public:
    void askQuestions(vector<Movie> &movies);

private:
    char askQuestion(string questionWithAnswers, string possibleAnswers);
    void addPoint(string genre, vector<Movie> &movies);
};

#endif
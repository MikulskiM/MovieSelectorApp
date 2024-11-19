#include <iostream>
#include <limits>
#include <algorithm>    // sort
#include "MovieSelector.h"

using namespace std;

char MovieSelector::askQuestion(string questionWithAnswers, string possibleAnswers)
{
    char answer;

    cout << questionWithAnswers << "\n";

    while(true)
    {
        cin >> answer;
        if(possibleAnswers.find(answer) != string::npos)
        {
            break;  // we got the correct answer
        }
        else
        {
            cout << "ERROR: Invalid input!\n" << "pick one of those options: " << possibleAnswers << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return answer;
}

void MovieSelector::addPoint(string genre, vector<Movie> &movies)
{
    cout << genre << "+\n";
    for(auto &movie : movies)
    {
        if((movie.genre1  == genre) || (movie.genre2 == genre))
        {
            movie.scoring++;
        }
    }
}

void MovieSelector::askQuestions(vector<Movie> &movies)
{
    // Pytanie 1
    char answer = askQuestion("\nWould you like to watch a movie with a complex plot or something simple and straightforward?\n"
                              "a) Complex\n"
                              "b) Simple", "ab");
    if(answer == 'a')
    {
        addPoint("Thriller", movies);
        addPoint("Mystery", movies);
        addPoint("Drama", movies);
    }
    else
    {
        addPoint("Comedy", movies);
        addPoint("Teen", movies);
        addPoint("Musical", movies);
        addPoint("Family", movies);
    }

    // Pytanie 2
    answer = askQuestion("\nDo you want an action-packed movie or something more relaxing?\n"
                         "a) Action\n"
                         "b) Relaxing", "ab");
    if(answer == 'a')
    {
        addPoint("Action", movies);
        addPoint("Adventure", movies);
        addPoint("Thriller", movies);
    }
    else
    {
        addPoint("Biography", movies);
        addPoint("Comedy", movies);
        addPoint("Drama", movies);
        addPoint("Romance", movies);
    }

    // Pytanie 3
    answer = askQuestion("\nDo you enjoy humorous or family-friendly movies?\n"
                          "a) Humorous\n"
                          "b) Not humorous", "ab");
    if(answer == 'a')
    {
        addPoint("Comedy", movies);
        addPoint("Family", movies);
    }
    else
    {
        addPoint("Crime", movies);
        addPoint("Horror", movies);
    }

    // Pytanie 4
    answer = askQuestion("\nWould you prefer exploring imaginative worlds or realistic stories?\n"
                          "a) Imaginative\n"
                          "b) Realistic", "ab");
    if(answer == 'a')
    {
        addPoint("Sci-Fi", movies);
        addPoint("Animation", movies);
    }
    else
    {
        addPoint("Biography", movies);
        addPoint("Crime", movies);
    }

    // Pytanie 5
    answer = askQuestion("\nDo you like suspense and mystery, or epic adventures?\n"
                          "a) Suspense and mystery\n"
                          "b) Epic adventures", "ab");
    if(answer == 'a')
    {
        addPoint("Mystery", movies);
        addPoint("Thriller", movies);
    }
    else
    {
        addPoint("Adventure", movies);
        addPoint("Sci-Fi", movies);
    }
}

void MovieSelector::proposeMovies(vector<Movie> &movies)
{
    vector<Movie> sortedMovies = movies;
    int topScore = 0;

    sort(sortedMovies.begin(), sortedMovies.end(), [](Movie &movie1, Movie &movie2)
    {
        return movie1.scoring < movie2.scoring;
    });

    topScore = sortedMovies.back().scoring;
    cout << "TOP SCORING = " << topScore << "\n";
    cout << "\n\tTop movies based on your answers:\n";
    for(auto &movie : movies)
    {
        if(movie.scoring == topScore)
        {
            movie.printWithScoring();
        }
    }
    cout << "\n\tSecond place movies you might be interested in:\n";
    for(auto &movie : movies)
    {
        if(movie.scoring == topScore-1)
        {
            movie.printWithScoring();
        }
    }
}

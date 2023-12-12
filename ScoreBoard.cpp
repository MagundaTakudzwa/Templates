#ifndef SCOREBOARD_CPP
#define SCOREBOARD_CPP
#include <string>
#include <iostream>
#include "ScoreBoard.h"
#include <cstddef>

#include "Dictionary.h"
#include "Dictionary.cpp"
#include "Tuple.h"
#include "Tuple.cpp"
using namespace std;

template <typename T>
ScoreBoard<T>::ScoreBoard() {}

template <typename T>
ScoreBoard<T>::~ScoreBoard() {}

template <typename T>
void ScoreBoard<T>::addScore(std::string user, T score) {
    T currentScore = scores.at(user);
    if (currentScore < score) {
        scores.set(user, score);
    }
}

template <typename T>
void ScoreBoard<T>::removeScore(std::string user) {
    scores.removeAt(user);
}

template <typename T>
T ScoreBoard<T>::getScore(std::string user) {
    return scores.at(user);
}

template <typename T>
T ScoreBoard<T>::getHighScore() {
    T highScore = T();

    for (int i = 0; i < scores.size(); i++) {
        std::string user = scores.getKeys()[i]; 
        T currentScore = scores.at(user);  

        if (currentScore > highScore) {
            highScore = currentScore;
        }
    }

    return highScore;
}


template <typename T>
Tuple<int, std::string*> ScoreBoard<T>::getHighScoreUser() {
    T highScore = getHighScore();
    Tuple<int, std::string*> result = scores.keysWithValue(highScore);
    return result;
}

#endif

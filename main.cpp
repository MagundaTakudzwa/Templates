#include <iostream>
#include <string>
#include "Dictionary.h"
#include "Dictionary.cpp"
#include "Tuple.h"
#include "Tuple.cpp"
#include "ScoreBoard.h"
#include "ScoreBoard.cpp"
#include <cstddef>
using namespace std;

int main()
{
     // Testing Tuple
    std::cout << "Testing Tuple:" << std::endl;
    Tuple<int, int> t1(1, 2);
    Tuple<int, std::string> t2(3, "hello");
    std::cout << t1.getSecond() << std::endl;  // Should output 2
    std::cout << t2.getFirst() << std::endl;   // Should output 3
    std::cout << (t1 == t1) << std::endl;       // Should output 1 (true)

    // Testing Dictionary with int
    std::cout << "\nTesting Dictionary<int, int>:" << std::endl;
    Dictionary<int, int> intDict;
    intDict.set(1, 54);
    intDict.set(2, 43);
    intDict.set(3, 32);

    std::cout << intDict.at(2) << std::endl;  // Should output 43
    std::cout << intDict.at(4) << std::endl;  // Should output 0 (default int value)

    // Testing Dictionary with double
    std::cout << "\nTesting Dictionary<int, double>:" << std::endl;
    Dictionary<int, double> doubleDict;
    doubleDict.set(1, 54.5);
    doubleDict.set(2, 43.2);
    doubleDict.set(3, 32.7);

    std::cout << doubleDict.at(2) << std::endl;  // Should output 43.2
    std::cout << doubleDict.at(4) << std::endl;  // Should output 0 (default double value)

    // Testing ScoreBoard with int
    std::cout << "\nTesting ScoreBoard<int>:" << std::endl;
    ScoreBoard<int> scores;
    scores.addScore("Alice", 100);
    scores.addScore("Bob", 75);
    scores.addScore("Charlie", 120);

    std::cout << "High Score: " << scores.getHighScore() << std::endl;  // Should output 120

    // Testing ScoreBoard with double
    std::cout << "\nTesting ScoreBoard<double>:" << std::endl;
    ScoreBoard<double> doubleScores;
    doubleScores.addScore("David", 105.5);
    doubleScores.addScore("Eve", 120.7);
    doubleScores.addScore("Frank", 99.3);

    std::cout << "High Score: " << doubleScores.getHighScore() << std::endl;  // Should output 120.7


    return 0;
}

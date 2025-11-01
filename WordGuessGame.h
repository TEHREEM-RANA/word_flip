#ifndef WORD_GUESS_GAME_H
#define WORD_GUESS_GAME_H

#include <string>
#include <vector>
using namespace std;

class WordGuessGame {
private:
    string secretWord;
    string displayWord;
    int maxAttempts;
    int wrongAttempts;
    vector<char> guessedLetters;

public:
    WordGuessGame(string word = "apple", int attempts = 6);

    // 🧠 Game Logic
    bool guessLetter(char letter);
    bool isGameOver() const;
    bool isWordGuessed() const;
    string getDisplayWord() const;
    int getRemainingAttempts() const;
    vector<char> getGuessedLetters() const;
    void reset(string newWord);

    // 💾 File Handling Functions
    bool saveGame(string filename) const; // Save progress
    bool loadGame(string filename);       // Load progress

private:
    bool isAlreadyGuessed(char letter) const;
};

string getRandomWord();

#endif

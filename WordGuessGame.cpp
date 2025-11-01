#include "WordGuessGame.h"
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <fstream> // for file handling

WordGuessGame::WordGuessGame(string word, int attempts) {
    secretWord = word;
    maxAttempts = attempts;
    wrongAttempts = 0;
    displayWord = string(word.length(), '_');
}

// 🔹 Guessing logic
bool WordGuessGame::guessLetter(char letter) {
    letter = tolower(letter);
    if (isAlreadyGuessed(letter)) {
        return false;
    }

    guessedLetters.push_back(letter);
    bool correct = false;

    for (int i = 0; i < secretWord.length(); i++) {
        if (tolower(secretWord[i]) == letter) {
            displayWord[i] = secretWord[i];
            correct = true;
        }
    }

    if (!correct)
        wrongAttempts++;

    return correct;
}

bool WordGuessGame::isGameOver() const {
    return (wrongAttempts >= maxAttempts || isWordGuessed());
}

bool WordGuessGame::isWordGuessed() const {
    return (displayWord == secretWord);
}

string WordGuessGame::getDisplayWord() const {
    return displayWord;
}

int WordGuessGame::getRemainingAttempts() const {
    return maxAttempts - wrongAttempts;
}

vector<char> WordGuessGame::getGuessedLetters() const {
    return guessedLetters;
}

void WordGuessGame::reset(string newWord) {
    secretWord = newWord;
    displayWord = string(newWord.length(), '_');
    wrongAttempts = 0;
    guessedLetters.clear();
}

bool WordGuessGame::isAlreadyGuessed(char letter) const {
    for (char c : guessedLetters)
        if (c == letter)
            return true;
    return false;
}

// 💾 Save game progress
bool WordGuessGame::saveGame(string filename) const {
    ofstream file(filename);
    if (!file.is_open()) return false;

    file << secretWord << endl;
    file << displayWord << endl;
    file << maxAttempts << endl;
    file << wrongAttempts << endl;

    // save guessed letters
    for (char c : guessedLetters)
        file << c << ' ';
    file << endl;

    file.close();
    return true;
}

// 💾 Load game progress
bool WordGuessGame::loadGame(string filename) {
    ifstream file(filename);
    if (!file.is_open()) return false;

    guessedLetters.clear();

    getline(file, secretWord);
    getline(file, displayWord);
    file >> maxAttempts;
    file >> wrongAttempts;
    file.ignore(); // skip newline

    char letter;
    while (file >> letter)
        guessedLetters.push_back(letter);

    file.close();
    return true;
}

string getRandomWord() {
    vector<string> words = {"apple", "banana", "orange", "laptop", "puzzle", "rocket"};
    srand(time(0));
    int index = rand() % words.size();
    return words[index];
}


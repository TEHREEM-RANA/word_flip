#include <iostream>
#include "WordGuessGame.h"
using namespace std;

int main() {
    WordGuessGame game(getRandomWord());
    string filename = "savegame.txt";

    cout << "🎮 Word Guess Game (with Save/Load)\n";

    while (!game.isGameOver()) {
        cout << "\nWord: " << game.getDisplayWord();
        cout << "\nAttempts left: " << game.getRemainingAttempts() << endl;

        cout << "\nEnter command (g=guess, s=save, l=load, q=quit): ";
        char command;
        cin >> command;

        if (command == 'g') {
            cout << "Enter a letter: ";
            char letter;
            cin >> letter;
            bool correct = game.guessLetter(letter);
            cout << (correct ? "✅ Correct!\n" : "❌ Wrong!\n");
        }
        else if (command == 's') {
            if (game.saveGame(filename))
                cout << "💾 Game saved successfully!\n";
            else
                cout << "⚠️ Failed to save game!\n";
        }
        else if (command == 'l') {
            if (game.loadGame(filename))
                cout << "📂 Game loaded successfully!\n";
            else
                cout << "⚠️ Failed to load game!\n";
        }
        else if (command == 'q') {
            break;
        }
    }

    if (game.isWordGuessed())
        cout << "\n🎉 You guessed the word: " << game.getDisplayWord() << endl;
    else
        cout << "\n💀 Game Over! Better luck next time.\n";

    return 0;
}


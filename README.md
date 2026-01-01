# 🎮 Word Guessing Game (C++)

A logic-based word game implemented in C++. Players attempt to guess a hidden word one letter at a time within a limited number of attempts.

## ✨ Features
* **Core Game Logic:** Dynamic word display and letter tracking.
* **Save/Load System:** Persistent gameplay using file handling (`.txt`).
* **Randomized Words:** Automatic selection of secret words from a predefined list.
* **Case Sensitivity:** Efficiently handles input regardless of uppercase or lowercase.

## 🧠 OOP Implementation
The project follows clean Object-Oriented principles:
* **Encapsulation:** All game states (secret word, attempts, guessed letters) are managed within the `WordGuessGame` class.
* **Persistence:** Methods `saveGame()` and `loadGame()` handle state recovery using `fstream`.

## 🛠️ Tech Stack
* **Language:** C++
* **Standard Libraries:** `vector`, `string`, `fstream`, `ctime`

---

### 🕹️ Quick Start
1. Include `WordGuessGame.h` in your project.
2. Initialize with a word: `WordGuessGame game("coding", 6);`
3. Use `game.guessLetter('c');` to play!

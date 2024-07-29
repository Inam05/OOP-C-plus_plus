#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

class WordGuessingGame
{
private:
    vector<string> wordList = {"programming", "cplusplus", "hangman", "developer", "computer"};
    string secretWord;
    string guessedWord;
    vector<char> incorrectLetters;
    int maxAttempts;

public:
    WordGuessingGame(int maxAttempts = 6) : maxAttempts(maxAttempts)
    {
        srand(static_cast<unsigned int>(time(0))); // Use time(0) as the seed
        secretWord = getRandomWord();
        guessedWord = string(secretWord.length(), '_');
    }

    string getRandomWord() const
    {
        return wordList[rand() % wordList.size()];
    }

    void displayHangman() const
    {
        cout << "Incorrect Attempts: " << incorrectLetters.size() << "/" << maxAttempts << endl;

        for (char letter : incorrectLetters)
        {
            cout << letter << " ";
        }
        cout << endl;

        cout << "Guessed Word: " << guessedWord << endl;
    }

    void guessLetter(char letter)
    {
        letter = tolower(letter);

        if (!isalpha(letter))
        {
            cout << "Please enter a valid alphabetical letter." << endl;
            return;
        }

        if (secretWord.find(letter) != string::npos)
        {
            for (size_t i = 0; i < secretWord.length(); ++i)
            {
                if (secretWord[i] == letter)
                {
                    guessedWord[i] = letter;
                }
            }
        }
        else
        {
            incorrectLetters.push_back(letter);
        }
    }

    bool isGameOver() const
    {
        return (incorrectLetters.size() == maxAttempts) || (guessedWord == secretWord);
    }

    bool isGameWon() const
    {
        return guessedWord == secretWord;
    }
};

int main()
{
    WordGuessingGame wordGame;

    cout << "Welcome to Word Guessing Game (Hangman Variation)!" << endl;

    while (!wordGame.isGameOver())
    {
        wordGame.displayHangman();

        char guess;
        cout << "Enter a letter: ";
        cin >> guess;

        wordGame.guessLetter(guess);

        if (wordGame.isGameWon())
        {
            cout << "Congratulations! You've guessed the word: " << wordGame.getRandomWord() << endl;
        }
    }

    if (!wordGame.isGameWon())
    {
        wordGame.displayHangman();
        cout << "Game over! The correct word was: " << wordGame.getRandomWord() << endl;
    }

    return 0;
}

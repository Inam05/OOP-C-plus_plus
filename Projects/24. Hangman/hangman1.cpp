#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cctype>

using namespace std;

class HangmanGame
{
private:
    vector<string> wordList = {"cplusplus", "programming", "hangman", "developer", "computer"};
    string secretWord;
    string guessedWord;
    int incorrectAttempts;
    vector<char> incorrectLetters;

public:
    HangmanGame()
    {
        srand(static_cast<unsigned int>(time(nullptr)));
        secretWord = getRandomWord();
        guessedWord = string(secretWord.length(), '_');
        incorrectAttempts = 0;
    }

    string getRandomWord() const
    {
        return wordList[rand() % wordList.size()];
    }

    void displayHangman() const
    {
        cout << "Incorrect Attempts: " << incorrectAttempts << endl;

        switch (incorrectAttempts)
        {
        case 0:
            break;
        case 1:
            cout << "   O" << endl;
            break;
        case 2:
            cout << "   O" << endl;
            cout << "   |" << endl;
            break;
        case 3:
            cout << "   O" << endl;
            cout << "  /|" << endl;
            break;
        case 4:
            cout << "   O" << endl;
            cout << "  /|\\ " << endl;
            break;
        case 5:
            cout << "   O" << endl;
            cout << "  /|\\ " << endl;
            cout << "  /  " << endl;
            break;
        case 6:
            cout << "   O" << endl;
            cout << "  /|\\ " << endl;
            cout << "  / \\" << endl;
            break;
        }

        cout << "Guessed Word: " << guessedWord << endl;
        cout << "Incorrect Letters: ";
        for (char letter : incorrectLetters)
        {
            cout << letter << " ";
        }
        cout << endl;
    }

    void guessLetter(char letter)
    {
        letter = tolower(letter);

        if (isalpha(letter))
        {
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
                ++incorrectAttempts;
            }
        }
        else
        {
            cout << "Please enter a valid alphabetical letter." << endl;
        }
    }

    bool isGameOver() const
    {
        return (incorrectAttempts == 6) || (guessedWord == secretWord);
    }

    bool isGameWon() const
    {
        return guessedWord == secretWord;
    }
};

int main()
{
    HangmanGame hangman;

    cout << "Welcome to Hangman!" << endl;

    while (!hangman.isGameOver())
    {
        hangman.displayHangman();

        char guess;
        cout << "Enter a letter: ";
        cin >> guess;

        hangman.guessLetter(guess);

        if (hangman.isGameWon())
        {
            cout << "Congratulations! You've guessed the word: " << hangman.getRandomWord() << endl;
        }
    }

    if (!hangman.isGameWon())
    {
        hangman.displayHangman();
        cout << "Game over! The correct word was: " << hangman.getRandomWord() << endl;
    }

    return 0;
}

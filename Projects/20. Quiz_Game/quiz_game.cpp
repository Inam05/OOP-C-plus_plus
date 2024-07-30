#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct QuizQuestion
{
    string question;
    vector<string> options;
    int correctOption;
};

void askQuestion(const QuizQuestion & question, int &score);
void displayResults(int score, int totalQuestions);

int main()
{
    vector<QuizQuestion> quiz; 
    quiz.push_back({"What is the capital of France?", {"A. Berlin", "B. Madrid", "C. Paris", "D. Rome"}, 2});
    quiz.push_back({"Which planet is known as the Red Planet?", {"A. Mars", "B. Venus", "C. Jupiter", "D. Saturn"}, 1});
    quiz.push_back({"Who wrote 'Romeo and Juliet'?", {"A. Charles Dickens", "B. Jane Austen", "C. William Shakespeare", "D. Mark Twain"}, 3});

    int score = 0;
    for (const auto &question : quiz)
    {
        askQuestion(question, score);
    }

    displayResults(score, quiz.size());

    return 0;
}

void askQuestion(const QuizQuestion &question, int &score)
{
    cout << question.question << endl;

    for (const auto &option : question.options)
    {
        cout << option << endl;
    }

    cout << "Enter your answer (A, B, C, or D): ";
    char userAnswer;
    cin >> userAnswer;

    int userOption = toupper(userAnswer) - 'A' + 1;

    if (userOption == question.correctOption)
    {
        cout << "Correct!" << endl;
        score++;
    }
    else
    {
        cout << "Incorrect. The correct answer was: " << static_cast<char>('A' + question.correctOption - 1) << endl;
    }

    cout << endl;
}

void displayResults(int score, int totalQuestions)
{
    cout << "Quiz Results:" << endl;
    cout << "Score: " << score << "/" << totalQuestions << endl;

    if (score == totalQuestions)
    {
        cout << "Congratulations! You answered all questions correctly." << endl;
    }
    else
    {
        cout << "Better luck next time." << endl;
    }
}

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

const int WIDTH = 50;
const int HEIGHT = 20;
const int MAX_TAIL = 100;

enum Direction
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

// Utility function to clear the screen
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

class Snake
{
private:
    int x, y;
    int fx, fy;
    int score;
    vector<int> tx, ty;
    int nt;
    Direction dir;

public:
    Snake() : x(WIDTH / 2), y(HEIGHT / 2), fx(rand() % WIDTH), fy(rand() % HEIGHT), score(0), nt(0), dir(STOP) {}

    void init()
    {
        x = WIDTH / 2;
        y = HEIGHT / 2;
        fx = rand() % WIDTH;
        fy = rand() % HEIGHT;
        score = 0;
        nt = 0;
        dir = STOP;
        tx.clear();
        ty.clear();
    }

    void setDirection(Direction newDir)
    {
        dir = newDir;
    }

    void update()
    {
        int prevx = tx.empty() ? x : tx[0];
        int prevy = ty.empty() ? y : ty[0];
        int prev2x, prev2y;

        if (!tx.empty())
        {
            tx[0] = x;
            ty[0] = y;
        }

        for (int i = 1; i < nt; i++)
        {
            prev2x = tx[i];
            prev2y = ty[i];
            tx[i] = prevx;
            ty[i] = prevy;
            prevx = prev2x;
            prevy = prev2y;
        }

        switch (dir)
        {
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        default:
            break;
        }

        if (x >= WIDTH)
            x = 0;
        else if (x < 0)
            x = WIDTH - 1;
        if (y >= HEIGHT)
            y = 0;
        else if (y < 0)
            y = HEIGHT - 1;

        for (int i = 0; i < nt; i++)
        {
            if (tx[i] == x && ty[i] == y)
            {
                throw runtime_error("Game Over: Snake collided with itself.");
            }
        }

        if (x == fx && y == fy)
        {
            score++;
            nt++;
            if (nt > MAX_TAIL)
                nt = MAX_TAIL; // Prevent excessive tail length
            fx = rand() % WIDTH;
            fy = rand() % HEIGHT;
        }
    }

    void render() const
    {
        clearScreen();
        SetConsoleTextAttribute(hConsole, 180);

        for (int i = 0; i < WIDTH + 2; i++)
            cout << "#";
        cout << endl;

        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                if (j == 0)
                    cout << "#";
                if (i == y && j == x)
                    cout << "O";
                else if (i == fy && j == fx)
                    cout << "X";
                else
                {
                    bool print = false;
                    for (int k = 0; k < nt; k++)
                    {
                        if (tx[k] == j && ty[k] == i)
                        {
                            cout << "o";
                            print = true;
                            break;
                        }
                    }
                    if (!print)
                        cout << " ";
                }
                if (j == WIDTH - 1)
                    cout << "#";
            }
            cout << endl;
        }

        for (int i = 0; i < WIDTH + 2; i++)
            cout << "#";
        cout << endl;
        cout << "Score is " << score << endl;
    }

    int getScore() const
    {
        return score;
    }
};

class GameManager
{
private:
    Snake snake;
    bool isRunning;

public:
    GameManager() : isRunning(false) {}

    void startGame()
    {
        snake.init();
        isRunning = true;
        while (isRunning)
        {
            snake.render();
            handleInput();
            try
            {
                snake.update();
            }
            catch (const runtime_error &e)
            {
                gameOver();
                break;
            }
            if (snake.getScore() == 100)
            {
                win();
                break;
            }
            Sleep(100); // Adjust speed here
        }
    }

    void handleInput()
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'a':
                snake.setDirection(LEFT);
                break;
            case 'd':
                snake.setDirection(RIGHT);
                break;
            case 'w':
                snake.setDirection(UP);
                break;
            case 's':
                snake.setDirection(DOWN);
                break;
            case 'x':
                isRunning = false;
                break;
            case 'r':
                snake.init();
                startGame();
                break; // Restart game
            default:
                break;
            }
        }
    }

    void gameOver()
    {
        clearScreen();
        cout << "Sorry you lost the game" << endl;
        cout << "Your score was " << snake.getScore() << endl;
        cout << "Press any key to return to the main menu..." << endl;
        _getch(); // Wait for user input
    }

    void win()
    {
        clearScreen();
        cout << "Congratulations, you won the game!" << endl;
        cout << "Press any key to return to the main menu..." << endl;
        _getch(); // Wait for user input
    }

    void showWelcome()
    {
        clearScreen();
        cout << "Welcome to the Snake Game!" << endl;
        cout << "1. Start Game" << endl;
        cout << "2. Instructions" << endl;
        cout << "3. Current Record" << endl;
        cout << "4. Exit" << endl;
        char choice;
        cin >> choice;
        switch (choice)
        {
        case '1':
            startGame();
            break;
        case '2':
            showInstructions();
            break;
        case '3':
            showRecord();
            break;
        case '4':
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    void showInstructions()
    {
        clearScreen();
        cout << "Snake Game Instructions:" << endl;
        cout << "1. Use WASD to control the snake." << endl;
        cout << "2. Eat the 'X' to grow and increase your score." << endl;
        cout << "3. Avoid colliding with yourself." << endl;
        cout << "4. Reach a score of 100 to win." << endl;
        cout << "Press any key to return to the main menu..." << endl;
        _getch(); // Wait for user input
    }

    void showRecord()
    {
        clearScreen();
        cout << "Current record is 100." << endl;
        cout << "Reach this score to win the game." << endl;
        cout << "Press any key to return to the main menu..." << endl;
        _getch(); // Wait for user input
    }
};

int main()
{
    SetConsoleTextAttribute(hConsole, 116);
    GameManager gameManager;
    while (true)
    {
        gameManager.showWelcome();
    }
    return 0;
}

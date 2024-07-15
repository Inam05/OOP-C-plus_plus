#include <iostream>
#include <conio.h>
#include <time.h>
#include <Windows.h> 
using namespace std;

// Enumeration for ball movement directions
enum eDirection
{
    STOP,
    RIGHT,
    UPRIGHT,
    DOWNRIGHT,
    LEFT,
    UPLEFT,
    DOWNLEFT
};

// Enumeration for paddle control directions
enum eControler
{
    PAUSE,
    UP,
    DOWN
};

// Base class for game objects with position handling
class cGameObject
{
protected:
    int x, y;                 // Current coordinates
    int originalX, originalY; // Initial coordinates

public:
    cGameObject(int posX, int posY)
    {
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
    }

    virtual ~cGameObject() {} // virtual distructor used

    virtual void reset() = 0; // Pure virtual function for resetting object state

    inline int getX() const // Get current X coordinate
    {
        return x;
    }

    inline int getY() const // Get current Y coordinate
    {
        return y;
    }

    void resetPosition() // Reset object to its original position
    {
        x = originalX;
        y = originalY;
    }
};

// Class for the ball object, inheriting from cGameObject
class cBall : public cGameObject
{
private:
    eDirection dir; // Current direction of ball movement

public:
    // Initialize ball direction as stationary
    cBall(int posX, int posY) : cGameObject(posX, posY)
    {
        dir = STOP; 
    }

    // Reset ball position and direction
    void reset() override 
    {
        resetPosition();
        dir = STOP;
    }

    // Change ball direction
    void changeDirection(eDirection direction) 
    {
        dir = direction;
    }

    // Set ball to move in a random direction
    void randomDirection() 
    {
        srand(time(0));
        dir = static_cast<eDirection>((rand() % 6) + 1);
    }

    // Get current ball direction
    inline eDirection getDir() const 
    {
        return dir;
    }

     // Move ball according to its current direction
    void move()
    {
        switch (dir)
        {
        case STOP:
            break;
        case RIGHT:
            x++;
            break;
        case UPRIGHT:
            x++;
            y--;
            break;
        case DOWNRIGHT:
            x++;
            y++;
            break;
        case LEFT:
            x--;
            break;
        case UPLEFT:
            x--;
            y--;
            break;
        case DOWNLEFT:
            x--;
            y++;
            break;
        default:
            break;
        }
    }
};

// Class for paddle objects, inheriting from cGameObject
class cPaddle : public cGameObject
{
private:
    eControler joyStick;

public:
    cPaddle(int posX, int posY) : cGameObject(posX, posY) // Initialize paddle as paused
    {
        joyStick = PAUSE; 
    }

    void reset() override // Reset paddle position and state
    {
        resetPosition();
        joyStick = PAUSE;
    }

    void changeDirection(eControler dir) // Change paddle control direction
    {
        joyStick = dir;
    }

    void move() // Move paddle according to current control direction
    {
        switch (joyStick)
        {
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case PAUSE:
            break;
        default:
            break;
        }
    }
};

// Class managing the game state and interactions
class cGameManager
{
private:
    int width, height; 
    int score1, score2; 
    bool quit;       
    cBall *ball;        
    cPaddle *player1;
    cPaddle *player2; 

public:
    cGameManager()
    {
        quit = false;
        height = 15;
        width = 50;
        score1 = score2 = 0;
        ball = new cBall(width / 2, height / 2);
        player1 = new cPaddle(1, height / 2); 
        player2 = new cPaddle(width - 2, height / 2);
    }

    ~cGameManager()
    {
        delete ball;
        delete player1;
        delete player2;
    }

    void ScoreUp(cPaddle *player) // Update score and reset game state after scoring
    {
        if (player == player1)
        {
            score1++;
        }
        else if (player == player2)
        {
            score2++;
        }
        ball->reset();
        player1->reset();
        player2->reset(); 
    }

    void Draw() // Draw the game screen
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0}); // Move cursor to top-left corner of console

        // Draw top border of game area
        for (int i = 0; i < width + 2; i++)
        {
            cout << "\xB2";
        }
        cout << endl;

        // Draw middle section of game area
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int ballX = ball->getX();
                int ballY = ball->getY();
                int player1x = player1->getX();
                int player1y = player1->getY();
                int player2x = player2->getX();
                int player2y = player2->getY();

                // Draw left border of game area
                if (j == 0)
                {
                    cout << "\xB2";
                }

                // Draw ball, Player 1's paddle, or Player 2's paddle
                if (ballX == j && ballY == i)
                {
                    cout << "o"; 
                }
                else if (player1x == j && (player1y >= i && player1y < i + 4))
                {
                    cout << "\xDB"; // Draw Player 1's paddle
                }
                else if (player2x == j && (player2y >= i && player2y < i + 4))
                {
                    cout << "\xDB"; // Draw Player 2's paddle
                }
                else
                {
                    cout << " "; // Empty space
                    // Draw right border of game area
                    if (j == width - 1)
                    {
                        cout << "\xB2";
                    }
                }
            }
            cout << endl;
        }

        // Draw bottom border of game area
        for (int i = 0; i < width + 2; i++)
        {
            cout << "\xB2";
        }
        cout << endl;

        // Display scores of Player 1 and Player 2
        for (int i = 0; i < width / 2 - 10; i++)
        {
            cout << " ";
        }
        cout << "Player 1 : Player 2" << endl;
        for (int i = 0; i < width / 2 - 3; i++)
        {
            cout << " ";
        }
        cout << score1 << " : " << score2 << endl;
    }

    void Input() // Handle user input
    {
        int player1y = player1->getY();
        int player2y = player2->getY();

        if (_kbhit()) // Check if a key has been pressed
        {
            if (ball->getDir() == STOP) // If ball is stationary, start movement
            {
                ball->randomDirection(); // Set random initial direction for the ball
            }
            switch (_getch()) // Get the pressed key
            {
            case 'w': // Player 1 moves paddle up
                if (player1y - 3 > 0)
                {
                    player1->changeDirection(UP);
                }
                break;
            case 's': // Player 1 moves paddle down
                if (player1y + 1 < height)
                {
                    player1->changeDirection(DOWN);
                }
                break;
            case 'i': // Player 2 moves paddle up
                if (player2y - 3 > 0)
                {
                    player2->changeDirection(UP);
                }
                break;
            case 'j': // Player 2 moves paddle down
                if (player2y + 1 < height)
                {
                    player2->changeDirection(DOWN);
                }
                break;
            case 'q': // Quit game
                quit = true;
                break;
            default:
                break;
            }
        }
    }

    void Logic() // Implement game logic
    {
        ball->move();
        player1->move();
        player2->move();

        int ballX = ball->getX();
        int ballY = ball->getY();
        int player1x = player1->getX();
        int player1y = player1->getY();
        int player2x = player2->getX();
        int player2y = player2->getY();

        // Check collision and scoring conditions
        if (ballX == player1x + 1) // Ball hits Player 1's paddle
        {
            if (ballY == player1y - 3)
            {
                ball->changeDirection(UPRIGHT); // Ball bounces up-right
            }
            else if (ballY == player1y - 2 || ballY == player1y - 1)
            {
                ball->changeDirection((eDirection)(rand() % 3 + 1)); // Randomly change direction
            }
            else if (ballY == player1y)
            {
                ball->changeDirection(DOWNRIGHT); // Ball bounces down-right
            }
        }
        else if (ballX == player2x - 1) // Ball hits Player 2's paddle
        {
            if (ballY == player2y - 3)
            {
                ball->changeDirection(UPLEFT); // Ball bounces up-left
            }
            else if (ballY == player2y - 2 || ballY == player2y - 1)
            {
                ball->changeDirection((eDirection)(rand() % 3 + 4)); // Randomly change direction
            }
            else if (ballY == player2y)
            {
                ball->changeDirection(DOWNLEFT); // Ball bounces down-left
            }
        }

        // Handle ball bouncing off top and bottom edges of game area
        if (ballY == height - 1)
        {
            ball->changeDirection(ball->getDir() == DOWNRIGHT ? UPRIGHT : UPLEFT); // Ball bounces off bottom edge
        }
        else if (ballY == 0)
        {
            ball->changeDirection(ball->getDir() == UPRIGHT ? DOWNRIGHT : DOWNLEFT); // Ball bounces off top edge
        }

        // Handle scoring conditions
        if (ballX == width - 1) // Player 1 scores
        {
            ScoreUp(player1);
        }
        else if (ballX == 0) // Player 2 scores
        {
            ScoreUp(player2);
        }

        // Prevent paddles from moving out of game area bounds
        if (player1y - 4 < 0 || player1y + 2 > height)
        {
            player1->changeDirection(PAUSE); // Pause Player 1's paddle if out of bounds
        }
        if (player2y - 4 < 0 || player2y + 2 > height)
        {
            player2->changeDirection(PAUSE); // Pause Player 2's paddle if out of bounds
        }

        // End game if either player reaches 5 points
        if (score1 == 3 || score2 == 3)
        {
            quit = true;
        }
    }

    void Game() // Main game loop
    {
        string p1, p2;

        // Display game instructions and get player names
        cout << "Welcome to the Pong Game!" << endl;
        cout << "Game Rules:" << endl;
        cout << "1. Player 1 controls the paddle with 'w' (up) and 's' (down)." << endl;
        cout << "2. Player 2 controls the paddle with 'i' (up) and 'j' (down)." << endl;
        cout << "3. Press 'q' at any point to quit the game." << endl;
        cout << "4. The first player to score 3 points wins the game." << endl;
        cout << "Good luck and have fun!" << endl << endl;
        cout << "Please enter the name of Player 1: ";
        cin >> p1;
        cout << "Please enter the name of Player 2: ";
        cin >> p2;

        // Game loop
        while (!quit)
        {
            Draw();
            Input();
            Logic();
        }

        // Display winner or tie message
        if (score1 != score2)
        {
            score1 > score2 ? cout << p1 << " Won!" << endl : cout << p2 << " Won!" << endl;
        }
        else
        {
            cout << "It's a Tie!" << endl; 
        }
    }
};

// Main function, entry point of the program
int main()
{
    cGameManager c;
    c.Game();      
    return 0;
}

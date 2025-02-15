#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Direction
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

class SnakeGame
{
private:
    bool gameOver;
    int width, height;
    int x, y, foodX, foodY, score;
    int speed;
    int level;
    char foodType;
    Direction dir;
    vector<pair<int, int>> snake;
    vector<pair<int, int>> obstacles;

public:
    SnakeGame() : gameOver(false), score(0), dir(STOP) {}

    void setupGame()
    {
        cout << "Enter Grid Height: ";
        cin >> height;
        cout << "Enter Grid Width: ";
        cin >> width;

        cout << "Choose difficulty level:\n";
        cout << "1 - NOOB (Slow)\n2 - PRO (Medium)\n3 - LEGEND (Fast)\n";
        cout << "Enter level: ";
        cin >> level;

        if (level == 1)
            speed = 105;
        else if (level == 2)
            speed = 60;
        else if (level == 3)
            speed = 40;
        else
            speed = 90;

        resetGame();
    }

    void resetGame()
    {
        system("cls");
        gameOver = false;
        score = 0;
        dir = STOP;
        x = width / 2;
        y = height / 2;
        snake.clear();
        snake.push_back({x, y});
        snake.push_back({x - 1, y});

        obstacles.clear();
        generateObstacles();
        spawnFood();
    }

    void generateObstacles()
    {
        int numObstacles = (width * height) / (level == 1 ? 80 : (level == 2 ? 60 : 40));

        for (int i = 0; i < numObstacles; i++)
        {
            int obsX, obsY;
            do
            {
                obsX = rand() % width;
                obsY = rand() % height;
            } while ((obsX == x && obsY == y) || (obsX == foodX && obsY == foodY));

            obstacles.push_back({obsX, obsY});
        }
    }

    void spawnFood()
    {
        do
        {
            foodX = rand() % width;
            foodY = rand() % height;
        } while (foodCollides());

        int foodChance = rand() % 100;
        foodType = (foodChance < 60) ? 'F' : (foodChance < 90) ? 'S' : 'M';
    }

    bool foodCollides()
    {
        for (auto part : snake)
        {
            if (foodX == part.first && foodY == part.second)
                return true;
        }
        for (auto obs : obstacles)
        {
            if (foodX == obs.first && foodY == obs.second)
                return true;
        }
        return false;
    }

    void gotoxy(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    void hideCursor()
    {
        CONSOLE_CURSOR_INFO cursorInfo;
        cursorInfo.dwSize = 100;
        cursorInfo.bVisible = FALSE;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    }

    void draw()
    {
        gotoxy(0, 0); // Move cursor to the top-left corner instead of clearing the screen

        vector<string> buffer(height + 2, string(width + 2, ' '));

        for (int i = 0; i < width + 2; i++)
        {
            buffer[0][i] = '#';
            buffer[height + 1][i] = '#';
        }

        for (int i = 1; i <= height; i++)
        {
            buffer[i][0] = '#';
            buffer[i][width + 1] = '#';
        }

        for (auto part : snake)
        {
            buffer[part.second + 1][part.first + 1] = 'o';
        }

        buffer[y + 1][x + 1] = 'O';
        buffer[foodY + 1][foodX + 1] = foodType;

        for (auto obs : obstacles)
        {
            buffer[obs.second + 1][obs.first + 1] = 'X';
        }

        for (const auto &line : buffer)
        {
            cout << line << endl;
        }

        cout << "Score: " << score << "  (F = +10, S = +30, M = +50)" << endl;
    }

    void input()
    {
        if (_kbhit())
        {
            char key = _getch();

            if (key == -32)
            {
                key = _getch();
                switch (key)
                {
                case 72:
                    if (dir != DOWN)
                        dir = UP;
                    break;
                case 80:
                    if (dir != UP)
                        dir = DOWN;
                    break;
                case 75:
                    if (dir != RIGHT)
                        dir = LEFT;
                    break;
                case 77:
                    if (dir != LEFT)
                        dir = RIGHT;
                    break;
                }
            }
            else
            {
                switch (key)
                {
                case 'a':
                    if (dir != RIGHT)
                        dir = LEFT;
                    break;
                case 'd':
                    if (dir != LEFT)
                        dir = RIGHT;
                    break;
                case 'w':
                    if (dir != DOWN)
                        dir = UP;
                    break;
                case 's':
                    if (dir != UP)
                        dir = DOWN;
                    break;
                case 'x':
                    gameOver = true;
                    break;
                }
            }
        }
    }

    void logic()
    {
        if (dir == STOP)
            return;

        snake.insert(snake.begin(), {x, y});

        if (x == foodX && y == foodY)
        {
            int growth = 1; // Default growth

            if (foodType == 'F')
            {
                score += 10;
                growth = 1;
            }
            else if (foodType == 'S')
            {
                score += 30;
                growth = 3;
            }
            else if (foodType == 'M')
            {
                score += 50;
                growth = 5;
            }

            // Grow the snake by the required amount
            for (int i = 0; i < growth - 1; i++)
            {
                snake.push_back(snake.back());
            }

            spawnFood(); // Spawn new food
        }
        else
        {
            snake.pop_back(); // Normal movement, remove tail
        }

        switch (dir)
        {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
        }

        if (x < 0 || x >= width || y < 0 || y >= height)
            gameOver = true;

        for (size_t i = 1; i < snake.size(); i++)
        {
            if (snake[i].first == x && snake[i].second == y)
            {
                gameOver = true;
                break;
            }
        }

        for (auto obs : obstacles)
        {
            if (x == obs.first && y == obs.second)
            {
                gameOver = true;
                break;
            }
        }
    }

    void run()
    {
        int maxx = 0;
        setupGame();
        while (true)
        {
            while (!gameOver)
            {
                draw();
                input();
                logic();
                Sleep(speed);
            }
            maxx = max(maxx, score);
            Beep(523, 500);

            cout << "Close But, No Cigar!!!\nYour score: " << score << "\nMax Score: " << maxx << endl;
            string choice;
            cout << "Press 'R'/'r' to restart or any other key to exit: ";
            cin >> choice;

            if (choice == "r" || choice == "R")
            {
                setupGame();
            }
            else
            {
                cout << "  #####    ###    ##     ## ########     #######  ##     ## ######## ########  \n";
                cout << " ##   ##  ## ##   ###   ### ##          ##     ## ##     ## ##       ##     ## \n";
                cout << "##       ##   ##  #### #### ##          ##     ## ##     ## ##       ##     ## \n";
                cout << "##  #### #######  ## ### ## ######      ##     ## ##     ## ######   ########  \n";
                cout << "##   ##  ##   ##  ##     ## ##          ##     ##  ##   ##  ##       ##   ##   \n";
                cout << " ##   ## ##   ##  ##     ## ##          ##     ##   ## ##   ##       ##    ##  \n";
                cout << "  #####  ##   ##  ##     ## ########     #######     ###    ######## ##     ## \n";
                break;
            }
        }
    }
};

int main()
{
    srand(static_cast<unsigned>(time(0)));
    SnakeGame game;
    game.run();
    return 0;
}

# Snake Game Project

Made using C++ with OOPs Concepts

## Description
This is a **classic Snake Game** implemented in **C++** using **Object-Oriented 
Programming concepts**. The game is played in the console and features smooth gameplay with **real-time movement**, **multiple difficulty levels**, **obstacles**, and **special food types**.

This project was built to **demonstrate fundamental C++ programming concepts**, including the use of **vectors, enums, and structured game loops**. The game logic is efficiently designed to prevent flickering and ensures a smooth playing experience. Players can control the snake using `WASD` or arrow keys, navigate through obstacles, and aim for the highest score.

The project is designed to be **modular and extendable**, making it an excellent foundation for learning **game development in C++**.

## Table of Contents
- [Introduction](#introduction)
- [Installation](#installation)
- [Features](#features)
- [Data Structures Used](#data-structures-used)
- [How the Game Works](#how-the-game-works)
- [How to Play](#how-to-play)
- [Compilation and Execution](#compilation-and-execution)
- [Future Improvements](#future-improvements)
- [Creators](#creators)

---

## Introduction
This is **Snake Game** implemented using **C++** for rendering in a console and to control the snake, keyboard input. The game includes obstacles and different levels of difficulty, together with **special kinds of food**.

---

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/PrinceGadara1/OOPS_Project1.git
   ```
2. Navigate to the project directory:
   ```bash
   cd OOPS_Project1
   ```
3. Compile using g++:
   ```bash
   g++ snakegame.cpp -o snakegame.exe
   ```
4. Run the game:
   ```bash
   ./snakegame.exe
   ```

## Features
- **Grid-based movement**: The snake moves within a defined grid.
- **Difficulty Levels**: Choose from Noob (Slow), Pro (Medium), or Legend (Fast).
- **Food Types**:
  - `F (Food)`: +10 points, grows snake by 1.
  - `S (Super Food)`: +30 points, grows snake by 3.
  - `M (Monster Food)`: +50 points, grows snake by 5.
- **Obstacles**: Random obstacles appear on the board, increasing the challenge.
- **Game Over Conditions**:
  - Snake collides with walls.
  - Snake collides with itself.
  - Snake collides with an obstacle.
- **Real-time Movement Control**: Using `WASD` or arrow keys.
- **Max Score**: Displays the highest score after the game ends.
- **Buffer Rendering**: Prevents screen flickering for a smooth experience.
- **Restart Option**: Allows restarting the game after a loss.

---

## Data Structures Used
The game uses the following **data structures**:

1. **Vector (`vector<pair<int, int>> snake`)**:
   - Stores the coordinates of the snake's body.
   - The **first element** is the snake's head.
   - New positions are inserted at the front, and the tail is removed when moving.

2. **Vector (`vector<pair<int, int>> obstacles`)**:
   - Stores randomly generated obstacles that the snake must avoid.

3. **Enumeration (`enum Direction`)**:
   - Represents the movement direction: `STOP`, `LEFT`, `RIGHT`, `UP`, `DOWN`.

---

## How the Game Works

1. **Game Setup (`setupGame()`)**:
   - Initializes the grid size, difficulty level, and speed.

2. **Reset Game (`resetGame()`)**:
   - It clear screen of previous game.
   - Places the snake at the center.
   - Generates obstacles and food.

4. **Rendering (`draw()`)**:
   - The game screen is drawn using a **buffer technique** (vector of strings) to reduce flickering.
   - The **snake head** is `'O'`.
   - The rest of **body part of snake** is represented by `'o'`.
   - **Food types** are `'F'`, `'S'`, `'M'`.
   - **Obstacles** are `'X'`.

5. **Handling Input (`input()`)**:
   - Reads keyboard input using `_kbhit()` and `_getch()`.
   - Prevents reversing direction instantly (e.g., moving left then right).

6. **Game Logic (`logic()`)**:
   - Moves the snake based on direction.
   - Checks if the snake **eats food** and grows accordingly.
   - Checks for **collisions** with walls, itself, or obstacles.

7. **Game Loop (`run()`)**:
   - Continuously updates the game until `gameOver == true`.
   - Handles restarting or exiting the game after losing.

---

## How to Play
1. Run the compiled program.
2. Enter the grid size and difficulty level.
3. Use `WASD` or arrow keys to control the snake.
4. Avoid obstacles (`X`), eat food (`F`, `S`, `M`) to grow.
5. The game ends if the snake collides with itself, walls, or obstacles.

---

## Compilation and Execution
To compile and run the game in **Windows**:
```sh
 g++ snake_game.cpp -o snake_game.exe
 ./snake_game.exe
```

---

## Future Improvements
- Implement a **pause feature**.
- Add a **scoreboard** to save high scores.
- Introduce **power-ups** (e.g., temporary invincibility).
- For now, this game will run in **Windows OS**, but we ensure that it will be **OS Independent** in future. 

---

## Creators
- [Prince Gadara](https://github.com/PrinceGadara1)
- [Jay Vaghela](https://github.com/202401237)
- [Kush Gandhi](https://github.com/kushgandhi123) 
- [Shubh Goyani](https://github.com/Shubh-Goyani)
- **For Contributing in This Game**:
   1. Fork the repository.
   2. Create a new branch: `git checkout -b feature-name`.
   3. Make your changes.
   4. Push your branch: `git push origin feature-name`.
   5. Create a pull request.

---

#### Hope is what makes us strong. It is why we are here. 🐍🎮
### - **Binary Brains**

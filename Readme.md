# Sudoku Solver in C++

A command-line C++ application to solve and validate Sudoku puzzles. This project lets users interactively input their custom Sudoku puzzles, check validity, and solve them automatically.

---

## Features

- **Interactive Input:** Allows users to provide Sudoku values at specified positions.
- **Sudoku Validation:** Ensures the entered grid follows Sudoku rules.
- **Automatic Solver:** Implements backtracking to find a solution for the given Sudoku.
- **Display Grid:** Displays the Sudoku grid at every step.

---

## How to Run

1. **Clone the Repository**
   ```bash
   git clone https://github.com/SameerVohra/Sudoku_Solver_CPP.git
   cd Sudoku_Solver_CPP
   ```

2. **Compile the Code**
   Ensure you have a C++ compiler (e.g., `g++`) installed on your system.
   ```bash
   g++ -std=c++17 SudokuSolver.cpp -o SudokuSolver
   ```

3. **Run the Program**
   ```bash
   ./SudokuSolver
   ```

---

## Usage

### Input
- Enter a custom Sudoku grid interactively by specifying:
  - Row and column (0-based indexing).
  - The number to be inserted.
- Enter `-1` for both row and column to stop inputting numbers.

### Output
- The program validates the Sudoku grid.
- If valid, it solves the Sudoku and displays the solution.
- If not solvable, it notifies the user.

---

## Example

### Initial Grid
```
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9
```

### Steps
1. Enter row and column (0-based indexing).
2. Insert values into the Sudoku grid interactively.
3. Solve the Sudoku.

### Solved Sudoku
```
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
```

---

## Tech Stack

- **Language:** C++
- **Algorithm:** Backtracking

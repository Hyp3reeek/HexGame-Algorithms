# Hex Strategy & Logic Engine (C++)

A low-level C++ implementation of the classic board game **Hex**. This project was developed as part of the Algorithms and Data Structures course at the Gdansk University of Technology. It focuses on board state analysis, pathfinding, and winning strategy evaluation.

## 🕹️ About the Game
Hex is a strategy game played on a diamond-shaped grid (traditionally 11x11). Two players (Red and Blue) take turns placing pieces. The goal is to form an uninterrupted path connecting the two sides of the board designated for their color.

## 🚀 Key Features
- **Visual ASCII Parser:** Includes a custom-built parser to read and interpret complex hexagonal board representations directly from standard input.
- **Game State Validation:**
  - `IS_BOARD_CORRECT`: Verifies pawn count ratios and turn order logic.
  - `IS_BOARD_POSSIBLE`: Checks for illegal board states (e.g., a player winning earlier without the game ending).
- **Advanced Pathfinding:** Implements **Depth First Search (DFS)** to detect winning connections across the hexagonal grid.
- **Winning Strategy Analysis:** - Simulates game states up to 2 moves ahead.
  - Analyzes winning conditions against both **Naive** and **Perfect** opponents using state-space search principles.

## 🛠️ Technical Highlights
- **No STL Core Logic:** Optimized for performance and low-level understanding by avoiding standard library containers (like `std::vector` or `std::list`) in the core engine.
- **Manual Memory Management:** Uses raw pointers and dynamic 2D arrays with strict `new` and `delete[]` cycles to ensure a zero-leak footprint.

## ⚙️ Compilation & Usage
This project is designed to run in a Linux environment.

### Prerequisites
- GCC / G++ compiler
- Make (optional)

### Building
Compile the project using the following command:
```bash
g++ main.cpp Hex.cpp -o hex
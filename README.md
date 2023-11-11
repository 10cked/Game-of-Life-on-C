**Conway's Game of Life in C**

This repository contains a simple implementation of Conway's Game of Life in C. The Game of Life is a cellular automaton devised by mathematician John Conway, where each cell in a grid evolves based on a set of rules.

### How to Run
1. Clone the repository to your local machine.
2. Compile the C program using a C compiler (e.g., `gcc -o game_of_life game_of_life.c`).
3. Run the compiled executable (`./game_of_life`).

### Rules
The rules of the Game of Life are straightforward:
- Any live cell with fewer than two live neighbors dies (underpopulation).
- Any live cell with two or three live neighbors survives.
- Any live cell with more than three live neighbors dies (overpopulation).
- Any dead cell with exactly three live neighbors becomes a live cell (reproduction).

### Customization
You can customize the size of the grid by modifying the `ROWS` and `COLS` constants. The initial generation is randomly generated, providing a dynamic starting point for the simulation.

### Visualization
The program uses the terminal to display each generation, with live cells represented by "*" and dead cells by empty spaces. The simulation automatically progresses through generations, and the terminal is cleared to provide a smooth visualization.

Feel free to explore, modify, and experiment with the code to enhance your understanding of cellular automata and Conway's Game of Life.

**Note:** Ensure your terminal supports ANSI escape codes for proper visualization. The `usleep` function introduces a delay between generations, providing a visually appealing animation.

*Happy coding!*

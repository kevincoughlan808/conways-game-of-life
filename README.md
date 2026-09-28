# conways-game-of-life
Capstone project of my C++ 100 Days of Code: A cellular automata or Conway's game of life simulation. 


What it is?
A cellular automota or Conway's Game of Life implemented in C++ with SFML rendering.

The rules:
1) Any live cell with 2 or 3 live neighbours survives
2) Any dead cells with exactly 3 live neighbours becomes alive
3) All other cells die or stay dead


Component diagram:

┌─────────────────────────────────────────┐
│              GameOfLife                 │
│                                         │
│  ┌──────────┐     ┌──────────────────┐  │
│  │   Grid   │────▶│  UpdateSystem    │  │
│  │ 2D vector│     │ (apply rules)    │  │
│  └──────────┘     └──────────────────┘  │
│       │                                  │
│       ▼                                  │
│  ┌──────────┐     ┌──────────────────┐  │
│  │ Renderer │     │   InputHandler   │  │
│  │  (SFML)  │     │ (pause/step/draw)│  │
│  └──────────┘     └──────────────────┘  │
└─────────────────────────────────────────┘

- Grid: a 2D vector
- UpdateSystem: applies the rules of the game to the grid
- SFML Renderer: Renders live cells as white rectangles on a black background
- InputHandler: Handles Space to pause/resume and left click to toggle cells



Dependencies:
SFML 3
Cmake 3.14+
C++17


How to build:
```
git clone <https://github.com/kevincoughlan808/conways-game-of-life>
cmake -S . -B build
cmake --build build
```


How to run:
```
./build/game
```


How to run tests: 
```
./build/tests
```


Controls:
- Pause: Space
- click: Left click to toggle a cell alive/dead (pause first to draw patterns)


# conways-game-of-life
Capstone project of my C++ 100 Days of Code: A cellular automata or Conway's game of life simulation. 

What I'm building:
A cellular automoton or Conway's game of life

The rules:
1) Any live cell with 2 or 3 live neighbours survives
2) Any dead cells with exactly 3 live neighbours becomes alive
3) All other cells die or stay dead

Planned Features:
- Grid with live/dead cells
- Correct rule application each generation
- SFML rendering (each cell = a rectangle)
- Pause/resume with Space
- Click to toggle cells alive/dead
- Speed control
- GTest coverage, Doxygen, README

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

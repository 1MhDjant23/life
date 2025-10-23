# 🧬 Life — Conway’s Game of Life (C Implementation)

[![Language](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)](#)
[![License](https://img.shields.io/badge/license-MIT-lightgrey.svg)](LICENSE)
[![Game of Life](https://img.shields.io/badge/Conway-Game%20of%20Life-blueviolet.svg)](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

## 📚 Table of Contents
- [📖 Overview](#overview)
- [⚙️ Compilation](#compilation)
- [🚀 Usage](#usage)
- [✏️ Input Commands](#input-commands)
- [🧠 Game of Life Rules](#game-of-life-rules)
- [🧩 Output Format](#output-format)
---

## 📖 Overview

**Life** is a minimalist **C implementation** of [Conway’s Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).

The program reads a **sequence of drawing commands** from `stdin` to create an initial configuration on a 2D grid,  
then simulates a given number of Game of Life iterations and prints the final board to `stdout`.

It uses only a handful of standard C library functions — no external dependencies.

---

## ⚙️ Compilation

Compile using `gcc`:

```bash
gcc -Wall -Wextra -Werror *.c -o life
```

## 🚀 Usage
./life <width> <height> <iterations>
----------------------------------------------------------------
| Argument     | Description                                    |
| ------------ | ---------------------------------------------- |
| `width`      | Number of columns of the board                 |
| `height`     | Number of rows of the board                    |
| `iterations` | Number of Game of Life generations to simulate |
----------------------------------------------------------------

## ✏️ Input Commands
You control a pen that starts at the top-left corner (0, 0).
-----------------------------------------------------------
| Command | Action                                         |
| ------- | ---------------------------------------------- |
| `w`     | Move the pen **up**                            |
| `a`     | Move the pen **left**                          |
| `s`     | Move the pen **down**                          |
| `d`     | Move the pen **right**                         |
| `x`     | Toggle **pen ON/OFF** (start or stop drawing)  |
-----------------------------------------------------------
  - When the pen is down, it marks the current cell as alive ('O').
  - When the pen is up, it moves without modifying cells.
  - Cells outside the board are always considered dead.
Once all input is read, the simulation begins.

## 🧠 Game of Life Rules

At each iteration:

 1. Underpopulation → A live cell with fewer than 2 live neighbors dies.

 2. Survival → A live cell with 2 or 3 live neighbors lives on.

 3. Overpopulation → A live cell with more than 3 neighbors dies.

 4. Reproduction → A dead cell with exactly 3 live neighbors becomes alive.

## 🧩 Output Format:

Alive cell → 'O'

Dead cell → ' ' (space)

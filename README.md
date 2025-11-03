# 🎮 Indie Studio

> **“Time to go cross-platform.”**
> Create a fully playable **3D Bomberman-like video game** using real-world tools and professional development practices.

---

## 🧩 Overview

**Indie Studio** is the **year-end project** of Epitech’s **B4 - Year-End Programming (B-YEP-400)** module.
The goal is to design and develop a **cross-platform 3D video game** using **C++**, **CMake**, and **raylib**, with an emphasis on **fun, polish, and technical excellence**.

This project simulates real-world video game production. The game must be both **technically robust** and **enjoyable to play** — a working but boring game won’t cut it.

---

## 🛠️ Compilation

Your project must use **CMake 3.17+** as a cross-platform build system.

### 🐧 On Linux

CMake must generate a **Makefile**:

```bash
mkdir build && cd build
cmake ..
make
```

### 🪟 On Windows

CMake must generate a **Visual Studio Solution (.sln)** compatible with **Visual Studio 2022**:

```bash
mkdir build && cd build
cmake -G "Visual Studio 17 2022" ..
```

The final binary is named:

```
bomberman
```

---

## 🧰 Libraries & Dependencies

Your game must use **[raylib](https://www.raylib.com)** — a simple, open-source C library for **2D/3D graphics**.

---

## 🕹️ The Game — *Bomberman-like Experience*

![kisspng-artist-rayman-2-the-great-escape-super-bomberman-markproductions-ampquota-c-5c0f9c36d1b742 515216611544526902859](https://user-images.githubusercontent.com/72005841/167417681-839c7a4a-bcd0-4d58-a07e-3825af436864.png)
The game you must implement is a Bomberman-like game.<br/>
**Bomberman** is one of the most famous video games of all time.<br/>
With over 70 franchises, ranging from the first version on MSX, ZX Spectrum and Sharp MZ-700 in 1983<br/>
to the lastest versions on modern consoles, over 10 million units have been sold.<br/><br/>
Our gameplay reference is Neo Bomberman, released on the Neo Geo and MVS systems in 1997.<br/><br/>

### 🎯 Core Features

| Feature                         | Description                                                      |
| ------------------------------- | ---------------------------------------------------------------- |
| **Multiplayer**                 | Local multiplayer (2 players) with additional AI-controlled bots |
| **Main Menu**                   | Start new game, load existing game                               |
| **3D Graphics / 2D Gameplay**   | 3D-rendered environment with 2D grid movement                    |
| **Procedurally Generated Maps** | Random obstacles, bonuses, and map layout                        |
| **Save & Load System**          | Store and restore game progress                                  |
| **Animation & Sound**           | Dynamic interactions — explosions, walking, music, etc.          |
| **Power-ups**                   | Enhance gameplay with collectible bonuses                        |

---

## 💥 Power-ups

Power-ups modify player abilities dynamically during gameplay.

| Power-Up      | Description                                          |
| ------------- | ---------------------------------------------------- |
| **Bomb Up**   | Increases number of bombs a player can place         |
| **Speed Up**  | Increases player movement speed                      |
| **Fire Up**   | Extends bomb explosion range                         |
| **Wall Pass** | Allows the player to walk through destructible walls |

> 🧩 Source references:
> [Bomb Up](http://bomberman.wikia.com/wiki/Bomb_Up) · [Speed Up](http://bomberman.wikia.com/wiki/Speed_Up) · [Fire Up](http://bomberman.wikia.com/wiki/Fire_Up) · [Wall Pass](http://bomberman.wikia.com/wiki/Wall_Pass)

---

## ⚙️ Technical Specifications

| Requirement        | Description                                                     |
| ------------------ | --------------------------------------------------------------- |
| **Language**       | C++                                                             |
| **Build System**   | CMake 3.17+                                                     |
| **Binary Name**    | `bomberman`                                                     |
| **Libraries**      | raylib (mandatory), Boost (optional)                            |
| **Error Handling** | Write to stderr, exit with code `84` on failure, `0` on success |
| **Cross-Platform** | Must compile on both Linux and Windows                          |

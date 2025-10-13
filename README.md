# Indie Studio
The aim of the Indie Studio is to implement a cross-platform 3D video game with real-world tools.
Making an enjoyable game is just as important as writing clean code.
A working game which is no fun to play is pointless!
<br/><br/>
*Let’s be honest. Implementing a video game is generally not fun (at least not all the
time).
But it can be, and having someone else enjoy a game you made is an amazing feeling.
The result will be worth the effort, so do your best! And most importantly, have fun.*

# Compilation 
You MUST use CMake as a cross-platform build system:
- Linux: it must generates a Makefile to be able to build the project
- Windows: it must generates a Visual Studio solution .sln (will be tested with Visual Studio 2022).

# Library
You must use raylib, a very simple C library for 2D/3D graphics. As of today, 3D animation for .gltf models
files is badly handled. We advised you to use multiple .obj files to animate your assets.
<br/><br/>
*raylib is a C library, ever heard of encapsulation ?*
A CMakes module is provided for raylib, you must use it to generate your project. You mays use Boost to
help you with some aspects of the project (or for bonuses).
<br/><br/>
*There are plenty of free assets on the Internet. Creating your own should be far from
being a priority. . . Do not waste time.*
<br/>

# The Game

![kisspng-artist-rayman-2-the-great-escape-super-bomberman-markproductions-ampquota-c-5c0f9c36d1b742 515216611544526902859](https://user-images.githubusercontent.com/72005841/167417681-839c7a4a-bcd0-4d58-a07e-3825af436864.png)
The game you must implement is a Bomberman-like game.<br/>
**Bomberman** is one of the most famous video games of all time.<br/>
With over 70 franchises, ranging from the first version on MSX, ZX Spectrum and Sharp MZ-700 in 1983<br/>
to the lastest versions on modern consoles, over 10 million units have been sold.<br/><br/>
Our gameplay reference is Neo Bomberman, released on the Neo Geo and MVS systems in 1997.<br/><br/>
Here’s the required features :
- Local multi-player with the possibility to play with a friend + AI’s controlled bots.
- A main game menu (to start a new game or load an existing one).
- Your game must feature 3D graphics but a 2D gameplay.
- Your game must feature procedurally generated maps (random obstacles, random bonus. . . ).
- Save/Load a game
- Animation and sounds to give life to the game (especially during various interactions)
- Think about bomb explosion, player walking, background music, . . .
- Some Power-ups
- Bomb Up
- Speed Up
- Fire Up
- Wall Pass

The goal of this project is not only to code a video game, but it’s to code a fully finished video game. This means that the efforts you make to polish your game will count as much as the technical aspect. <br/>
Do your best to avoid clunky animations or graphical glitches, manage your camera in a way that the “outside” of the game is never visible, pay attention to game design, level design and sound design, add variations in ennemies and environnements, etc.

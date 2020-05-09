# Documentation

### 1. Graphics

#### SDL or SFML?
SDL 
- is procedural and completely based on C
- developed in C, but has native C++ support, easy to setup

SFML 
- is Object Oriented
- developed in C++, easy to setup

[SFML Website](https://www.sfml-dev.org/)

[GitHub SFML Community FAQ](https://github.com/SFML/SFML/wiki/Community-FAQ#libraries-gui-package)

 
 ## Overview about implementing a simple SFML game framework in C++
 
 [Coding a Simple SFML Game Framework in C++/ SFML](https://www.youtube.com/watch?v=J_ZnUpXGMmg)\
 [Source Code](https://github.com/Hopson97/SFML-Game-Framework)
 
 Game Engine/ Game Framework - common for every game
 
 - Game states
 - Resource Management
 - Animation
 - GUI Stuff
 - Utilities
 
 
 1. Game State
 First thing! Create the main game loop (what actually controls the game - basically an infinite loop that only ends when the game is closed - this loop has 3 main functions: 1.handling player input, 2.updating the game, 3.rendering) and the game state system (organize the code of the different stages of the game into their own classes).
 
 The different game state classes inherit from the base game state class & implement the **virtual functions** and then the main game loop simply causes functions in the currenttly active game state over and over again **polymorphically** until the game is closed
 
 
 Fixed update --- fixed time between updating --- tick rate
 
 2. Utilities: Pseudo-random number generator (pseudo because it's not actually possible for computers to create a truly random number)
 
 3. Resource Management System
 Resources (e.g. textures, sounds and fonts) will only ever be loaded just once.
 -- saves time beacause loading from files is a rather slow thing to do.
 
 4. Animation System
 SFML - function Sprite::setTextureRect
 
 5. GUI System
 Create the menu (stack menu)
 Widgets
 
 
 
 
 [Managing Game States in C++](http://gamedevgeek.com/tutorials/managing-game-states-in-c/)
 
 
 
_Note:_
**Finite State Machines** are a way of expressing the flow from one game State to another game State in a succinct graphical representation.
 
 
 
 
 
 
 



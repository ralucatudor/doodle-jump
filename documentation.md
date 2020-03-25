# Documentation

The project must include:
1. Graphical Interface (SDL, SFML, Qt, etc.) - C++ API 
2. RTTI (Run-time type information)
3. Abstract Classes
4. Overloading Operators
5. Heap Memory Allocation
6. Exceptions
7. STL
8. Lambda expressions
9. Templates
10. Smart pointers
11. Design patterns (minimum 2)
12. Features of C++17/20 (constexpr, consteval, constinit, fold expressions, init statement for if/switch, etc.)

The project might include:
- Move semantics


### 1. Graphics

#### SDL or SFML?

SDL 
- is procedural and completely based on C
- developed in C, but has native C++ support, easy to setup

SFML 
- is Object Oriented
- developed in C++, easy to setup

[SFML Website](https://www.sfml-dev.org/)

[configuring SFML in VS](https://www.sfml-dev.org/tutorials/2.5/start-vc.php)

[GitHub SFML Community FAQ](https://github.com/SFML/SFML/wiki/Community-FAQ#libraries-gui-package)

 C++ GUI (Graphical User Interface) 
  
 ### What IDE? CodeBlocks/ Visual Studio?
 
 ## Overview about Graphical User Interface Implementations
 
 [Coding a Simple SFML Game Framework in C++/ SFML](https://www.youtube.com/watch?v=J_ZnUpXGMmg)\
 [source code](https://github.com/Hopson97/SFML-Game-Framework)
 
 Game Engine/ Game Framework - ofc, common for every game
 
 - Game states
 - Resource Management
 - Animation
 - GUI Stuff
 - Utilities
 
 
 1. Game State
 First thing! Create the main game loop (what actually controls the game - basically an infinete loop that only ends when the game is closed - this loop has 3 main functions: 1.handling player input, 2.updating the game, 3.rendering) and the game state system (organize the code of the different stages of the game into their own classes).
 
 The different game state classes inherit from the base game state class & implement the **virtual functions** (?will see) and then the main game loop simply causes functions in the currenttly active game state over and over again **polymorphically** until the game is closed
 
 
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 



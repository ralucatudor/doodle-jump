# doodle-jump
![GitHub last commit](https://img.shields.io/github/last-commit/ralucatudor/doodle-jump.svg)
![GitHub top language](https://img.shields.io/github/languages/top/ralucatudor/doodle-jump.svg)
![TLOC](https://tokei.rs/b1/github/ralucatudor/doodle-jump)
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/ralucatudor/doodle-jump.svg)

Object Oriented Programming Project - Doodle Jump Game :computer:

The project must include:
- [x] **Graphical Interface (SDL, SFML, Qt, etc.) - C++ API** - used SFML
- [x] **RTTI (Run-time type information)**: GameLoop.cpp (line 91), GameEngine.cpp (lines 23, 38, 40) - [dynamic_pointer_cast](http://www.cplusplus.com/reference/memory/dynamic_pointer_cast/). Also used [static_cast](https://en.cppreference.com/w/cpp/language/static_cast)
- [x] **Abstract Classes**: BaseEntity and Platform
- [x] **Overloading Operators**: << Logger class; += and -= Keyboard class; = and + Score class (and some more assignment operators)
- [x] **Heap Memory Allocation**: shared_ptr
- [x] **Exceptions**: see Exception.hpp
- [x] **STL**: std::vector - for platforms; std::map for keyboard input (see Keyboard class)
- [x] **Lambda expressions**: GameEngine.hpp (starting at lines 15, 19), GameLoop.cpp (starting at lines 53, 90)
- [x] **Templates**: Score is a template class; also used a template for 'lambda' (see DEFINITIONS.hpp)
- [x] **Smart pointers**: [shared_ptr](https://en.cppreference.com/w/cpp/memory/shared_ptr)
- [x] **Design patterns (minimum 2)**: Singleton (Logger) & Factory (PlatformCreator)
- [x] **Features of C++17/20 _(constexpr, consteval, constinit, fold expressions, init statement for if/switch, etc.)_**: [init statement for if](https://en.cppreference.com/w/cpp/language/if) and [std::filesystem::exists](https://en.cppreference.com/w/cpp/filesystem/exists) (both since C++17)

The project might include:
- [ ] Move semantics
- [ ] Multithreading
- [ ] Computer Network / Socket Programming
- [ ] Databases

## Demo :computer:

<p>
<img src="res/screencast/demo.gif" width=30%>
<img src="res/screencast/final_demo.gif" width=30%>
</p>

The second demo is the ***final version***! If the doodler jumps on the red platfom, that platform disappears. Note that each type of platform _(green - which is the regular one and appears twice as much as the others; red - slow platfom; light blue - fast platform)_ makes the doodler jump a different distance.

Memory leaks have been checked with valgrind and there are no leaks.
<!-- valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt -->

## Documentation

See [documentation](documentation.md).

See [resources](resources.md).

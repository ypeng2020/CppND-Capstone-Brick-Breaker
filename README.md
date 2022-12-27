# CPPND: Capstone Stone - Brick Breaker

<img src="brick_breaker.gif"/>

## Overview
This is the Capstone project for the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.
The Capstone Project integrates a wide range of C++ features and the built game offers essential function of a brick breaker.  

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## File Structure
* src/ : source files
* assets/ : image resources for the game 
* cmake/ : configuration file for cmake
* CMakeLists.txt  
* README.md 

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./BrickBreaker`.


## Rubric Points Addressed
1. The README file is included with the project and has instructions for building/running the project.  
2. The README decribes the project, indeicates the file structure, and indicates which rubric points are addressed.
3. The project pass the compile without errors. 
4. The project code is clearly organized into functions. 
5. The project accepts keybord inputs (left : move paddle to left, right : move paddle to right, up : stop the paddle) as necessary operation of the program.
6. The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.
7. All class data members are explicitly specified as public, protected or private.
8. Appropriate data and functions are grouped into classes.
9. At leaset two variables are defined as reference, or two functions use pass-by-reference in the project code.
10. The project uses destructors appropriately.





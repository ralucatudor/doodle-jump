#pragma once

#include <string>

// Window
static const unsigned int WINDOW_WIDTH = 400;
static const unsigned int WINDOW_HEIGHT = 600;
static const std::string WINDOW_TITLE = "Doodle Jump";
static const unsigned int MAX_FPS = 60; // frame limit


/// Game
static const float STANDARD_GRAVITY = 9.8; //g0 = 9.8 m/s^2
static const float TIME_ACCELERATOR = 12;
static const float MOVE_SPEED = 300;    // for left-right movement
static const size_t PLATFORM_COUNT = 15;

//doodler
const int DOODLER_LEFT_BOUNDING_BOX = 30;
const int DOODLER_RIGHT_BOUNDING_BOX = 50;
const int DOODLER_BOTTOM_BOUNDING_BOX = 70;
const int DOODLER_HEIGHT = 150;

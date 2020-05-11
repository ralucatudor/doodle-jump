// DEFINITIONS AND CONSTANTS
#pragma once

#include <string>

// Window
const unsigned int WINDOW_WIDTH = 400;
const unsigned int WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "Doodle Jump";
const unsigned int MAX_FPS = 60; // frame limit

// Game
const float MOVE_SPEED = 300;    // for left-right movement
const size_t PLATFORM_COUNT = 15;

// Doodler
const int DOODLER_LEFT_BOUNDING_BOX = 30;
const int DOODLER_RIGHT_BOUNDING_BOX = 50;
const int DOODLER_BOTTOM_BOUNDING_BOX = 70;
const int DOODLER_HEIGHT = 150;

// FILE PATHS
const std::string FONT_FILEPATH = "res/font/arial.ttf";
const std::string DOODLER_FILEPATH = "res/img/doodle.png";
const std::string PLATFORM_FILEPATH = "res/img/platform.png";
const std::string BACKGROUND_FILEPATH = "res/img/background.png";
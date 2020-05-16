// DEFINITIONS AND CONSTANTS
#pragma once

#include <memory>
#include <vector>
#include <string>

class Platform; // (Note that "DEFINITIONS.hpp" is already included in "Platform.hpp",
                // therefore I'm not including "Platform.hpp" in "DEFINITIONS.hpp", too)

// Window/ Game Constants
const unsigned int WINDOW_WIDTH = 400;
const unsigned int WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "Doodle Jump";
const unsigned int MAX_FPS = 60;    // frame limit (FPS stands for "Frames Per Second")

// Platform Constants
const size_t PLATFORM_COUNT = 15;
typedef std::vector<std::shared_ptr<Platform>> Platforms;

// Doodler Constants
const int DOODLER_LEFT_BOUNDING_BOX = 30;
const int DOODLER_RIGHT_BOUNDING_BOX = 50;
const int DOODLER_BOTTOM_BOUNDING_BOX = 70;
const int DOODLER_HEIGHT = 150;

const float MOVE_SPEED = 300;    // for doodler's left-right movement

// These shows how far up the doodler will jump after collision with that plaform:
const unsigned REGULAR_PLATFORM_DISTANCE = 10;        
const unsigned SLOW_PLATFORM_DISTANCE = 7;
const unsigned FAST_PLATFORM_DISTANCE = 15;

// File Paths
const std::string FONT_FILEPATH = "res/font/arial.ttf";
const std::string DOODLER_FILEPATH = "res/img/doodle.png";
const std::string PLATFORM_FILEPATH = "res/img/platform.png";
const std::string FAST_PLATFORM_FILEPATH = "res/img/fast_platform.png";
const std::string SLOW_PLATFORM_FILEPATH = "res/img/slow_platform.png";
const std::string BACKGROUND_FILEPATH = "res/img/background.png";
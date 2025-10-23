cmake_minimum_required(VERSION 3.15)
project(PiRacer-cpp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find lgpio library
find_library(LGPIO_LIB lgpio REQUIRED)
if(NOT LGPIO_LIB)
    message(FATAL_ERROR "lgpio library not found")
endif()

include_directories(
    ./Adafruit_INA219
    ./Adafruit_PCA9685
    ./Gamepad
    ./PiRacer
    /usr/include/lgpio   # typical lgpio include path, adjust if needed
)

set(PIRACER_SRC
    ./Adafruit_INA219/Adafruit_INA219.cpp
    ./Adafruit_PCA9685/Adafruit_PCA9685.cpp
    ./PiRacer/PiRacer.cpp
)

set(GAMEPAD_SRC
    ./Gamepad/Joystick.cpp
    ./Gamepad/ShanwanGamepad.cpp
)

add_executable(forward_backward_left_right
    ./examples/forward_backward_left_right.cpp
    ${PIRACER_SRC}
)
target_link_libraries(forward_backward_left_right ${LGPIO_LIB})

add_executable(gamepad_control
    ./examples/gamepad_control.cpp
    ${PIRACER_SRC}
    ${GAMEPAD_SRC}
)
target_link_libraries(gamepad_control ${LGPIO_LIB})

add_executable(read_battery
    ./examples/read_battery.cpp
    ${PIRACER_SRC}
)
target_link_libraries(read_battery ${LGPIO_LIB})

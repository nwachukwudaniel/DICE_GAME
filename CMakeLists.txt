cmake_minimum_required(VERSION 4.1)
project(DICE_GAME)

set(CMAKE_CXX_STANDARD 20)

add_executable(DICE_GAME
        Eng_nwachukwu_HA_Client.cpp
        Dice.cpp
        Dice.hpp
        Player.cpp
        Player.hpp
        )

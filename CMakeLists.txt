cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SDL2Test)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

add_executable(SnakeGame 
src/City_Grid.cpp
src/CityFactory_Grid.cpp
src/CityMaker_CMDLine.cpp 
src/controller.cpp 
src/Coordinate.cpp
src/game.cpp
src/HappinessFunc_Falling.cpp
src/HappinessFunc_Flat.cpp
src/HappinessFunc_Rising.cpp
src/HappinessFunc_StepDown.cpp
src/HappinessFunc_StepUp.cpp
src/main.cpp
src/Printer_CMDLine.cpp
src/Printer_Graphic.cpp
src/Question_Double.cpp
src/Question_Int.cpp
src/Question_YN.cpp
src/renderer.cpp 
src/Resident_Flat.cpp
src/Resident_StepDown.cpp
src/Resident.cpp
src/ResidentsFactory_Flat.cpp
src/ResidentsFactory_StepDown.cpp
src/ResidentsMaker_CMDLine.cpp
src/snake.cpp 
src/UI_CMDLine.cpp)

string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(SnakeGame ${SDL2_LIBRARIES})

file(GLOB test_SRCS tests/*.cpp
src/City_Grid.cpp
src/CityFactory_Grid.cpp
src/Converter.cpp
src/Coordinate.cpp
src/HappinessFunc_Falling.cpp
src/HappinessFunc_Flat.cpp
src/HappinessFunc_Rising.cpp
src/HappinessFunc_StepDown.cpp
src/HappinessFunc_StepUp.cpp
src/Manager.cpp
src/Question_Int.cpp
src/Question_Double.cpp
src/Question.cpp
src/Resident_Flat.cpp
src/Resident_StepDown.cpp
src/Resident.cpp
src/UI_CMDLine.cpp 
)

add_executable(RunTests ${test_SRCS})
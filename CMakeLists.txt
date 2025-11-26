cmake_minimum_required(VERSION 4.0)
project(CIE)

set(CMAKE_CXX_STANDARD 23)

add_executable(Test Blueprint/TESTs.cpp)

add_executable(Intro
        "Intro/Ex 1/Ex1_own.cpp"
        "Intro/Ex 1/Ex1_sol.cpp"
        "Intro/Ex 2/Ex2_own.cpp"
        "Intro/Ex 2/Ex2_sol.cpp"
        "Intro/Ex 3/Ex3_own.cpp"
        "Intro/Ex 4/Ex4_own.cpp"
        "Intro/Ex 4/Ex4_sol.cpp"
        "Intro/Ex 5/Ex5_own.cpp"
)

add_executable(Blueprint
        Blueprint/main.cpp
        Blueprint/implementation.cpp)

add_executable(Exercise01
        Exercise/01_BitRepresentation.cpp
)

add_executable(Exercise01_1
        Exercise/01_print_numbers.cpp
)

add_executable(Exercise02
        Exercise/02_VectorComputations.cpp
        Exercise/02_vectorfunctions.cpp
)


add_executable(Exercise5
        Exercise/05_FirstClassMain.cpp
)
add_executable(BlueprintClass 
        Blueprint/DemoClass.h
        Blueprint/DemoClassProgram.cpp
        Blueprint/DemoClass.cpp)

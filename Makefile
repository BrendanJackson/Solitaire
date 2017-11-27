# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# ****************************************************
# Compiles all of the .cpp files, joins them with Declarations.h, and executes the program
Declarations.h: Definitions.cpp Driver.cpp
	g++ -std=c++11 -c *.cpp
	g++ -std=c++11 *.o -o a.out
	./a.out

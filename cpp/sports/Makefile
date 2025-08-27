#compiler for sports.cpp
#variables
CXX=g++
CXXFLAGS=-Wall -g
#targets
play: sports.o
	$(CXX) $(CXXFLAGS) -o play play.cpp sports.o
sports.o: sports.cpp sports.h
	$(CXX) $(CXXFLAGS) -c sports.cpp
clean:
	rm -f sports.o play

#makefile 
#variables
CXX=g++
CXXFLAGS= -Wall -g
#targets
all: hello questions_3

hello: hello.o
	$(CXX) $(CXXFLAGS) $^ -o $@
questions_3: user_io.o controllers.o questions_3.o
	$(CXX) $(CXXFLAGS) $^ -o $@
%.o: %.cpp image_menu.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
#clean utility
clean:
	rm -f *.o hello questions_3

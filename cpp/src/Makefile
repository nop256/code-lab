#makefile 
#variables
CXX=g++
CXXFLAGS= -Wall -g
#CXXFLAGS= -g -Wall -std=c++17 =Wpedantic -Wextra -Werror
#targets
all: hello questions_3 ascii_image

hello: hello.o
	$(CXX) $(CXXFLAGS) $^ -o $@

questions_3: user_io.o controllers.o questions_3.o image_drawing.o image_output.o Image.o
	$(CXX) $(CXXFLAGS) $^ -o $@

ascii_image: ascii_image.o controllers.o Image.o image_drawing.o image_output.o user_io.o
	$(CXX) $(CXXFLAGS) $^ -o $@

image_file: image_file.o PPM.o Image.o controllers.o user_io.o image_drawing.o image_output.o
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp image_menu.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

#clean utility
clean:
	rm -f *.o hello questions_3 ascii_image image_file

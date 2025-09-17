# src/Makefile

CXX=g++
CXXFLAGS= -Wall -g

PROGS := questions_3 ascii_image image_file inquisitor simple_squares_ascii
DOT_O := PPM.o Image.o controllers.o user_io.o image_drawing.o image_output.o

all: hello questions_3 ascii_image image_file inquisitor simple_squares_ascii

$(PROGS): %: %.o $(DOT_O)
	$(CXX) $(CXXFLAGS) $< $(DOT_O) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(PROGS) 

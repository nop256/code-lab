#build file for cars
#variables
CXX=g++
CXXFLAGS=-Wall -g
#targets
car: body.o engine.o wheels.o car.o factory.o
	$(CXX) $(CXXFLAGS) $^ -o $@
%.o: %.cpp body.h
	$(CXX)$(CXXFLAGS) $< -c 
run:
	./car
clean:
	rm -f *.o car

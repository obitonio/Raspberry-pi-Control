CXX_COMPILER=g++
CXX_FLAGS=-I/usr/local/include -I/home/pi/Desktop/PrgmC/_lib/SFML/include
LD_FLAGS=-L/usr/local/lib -L/home/pi/Desktop/PrgmC/_lib/SFML/build/lib -lwiringPi -lsfml-network -lsfml-system

CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

all: moove

moove: $(OBJ_FILES)
	g++ $(LD_FLAGS) -o $@ $^

obj/%.o: src/%.cpp
	g++ $(CXX_FLAGS) -c -o $@ $<

clean:
	rm moove $(OBJ_FILES)

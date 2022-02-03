OBJS	= vector3.o main.o particle.o
SOURCE	= vector3.cpp main.cpp particle.cpp
HEADER	= 
OUT	= main
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

vector3.o: src/vector3.cpp
	$(CC) $(FLAGS) src/vector3.cpp 

main.o: src/main.cpp
	$(CC) $(FLAGS) src/main.cpp 

particle.o: src/particle.cpp
	$(CC) $(FLAGS) src/particle.cpp 
clean:
	rm -f $(OBJS) $(OUT)
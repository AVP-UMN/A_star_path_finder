path_find: main.cpp data.o
	g++ -g -o path_find main.cpp data.o -std=c++11

data.o: data.cpp data.h
	g++ -g -c data.cpp -std=c++11

clean:
	rm *.o path_find *.swp -rf

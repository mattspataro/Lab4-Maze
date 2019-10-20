all:
	g++ -std=c++11 main.cpp Pathfinder.cpp -o ex

clean:
	rm -f ex
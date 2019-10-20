#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "PathfinderInterface.h"
using namespace std;

class Pathfinder : public PathfinderInterface{
public:
	Pathfinder();
	~Pathfinder();
    string toString() const;
    void createRandomMaze();
	bool importMaze(string file_name);
	vector<string> solveMaze();
private:
    const int SIZE = 5;
    vector<string> path;
    int maze[5][5][5];
    bool isValidMaze(int token, int num);
    bool findPath(int x, int y, int z);
    void copyArray(int array1[5][5][5], int array2[5][5][5]);
};

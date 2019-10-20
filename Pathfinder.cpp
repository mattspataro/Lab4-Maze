#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Pathfinder.h"
using namespace std;

Pathfinder::Pathfinder() {
    
    //Set the default maze to a matrix of all 1's
    for(int z = 0; z < SIZE; z++){
        for(int y = 0; y < SIZE; y++){
            for(int x = 0; x < SIZE; x++){
                maze[x][y][z] = 1;
            }
        }
    }
}
Pathfinder::~Pathfinder() {}

bool isValid(int token, int num){
    if(num == 1 && token != 1) return false; //first
    if(num == 125 && token != 1) return false; //last
    if(token != 0 && token != 1) return false;
    return true;
}
void Pathfinder::copyArray(int a1[5][5][5], int a2[5][5][5]) {
    //a1 copies to a2
    for(int z = 0; z < SIZE; z++){
        for(int y = 0; y < SIZE; y++){
            for(int x = 0; x < SIZE; x++){
                a2[x][y][z] = a1[x][y][z];
            }
        }
    }
    return;
}
string Pathfinder::toString() const{

    ostringstream output;
    for(int z = 0; z < SIZE; z++){
        for(int y = 0; y < SIZE; y++){
            for(int x = 0; x < SIZE; x++){
                output << maze[x][y][z];
                if(x < SIZE-1){
                    output << " ";
                }
            }
            output << endl;
        }
        if(z < SIZE-1){
            output << endl;
        }
    }
    return output.str();
}
void Pathfinder::createRandomMaze(){
    return;
}
bool Pathfinder::importMaze(string file_name){
    ifstream import(file_name);
    int newMaze[5][5][5];
    int num = 1; //intialize at 1 for the first token
    int token;
    cout << file_name << ": " << endl;
    if(import){
        for(int z = 0; z < SIZE; z++){
            for(int y = 0; y < SIZE; y++){
                for(int x = 0; x < SIZE; x++){
                    if(import >> token){
                        if(isValid(token,num)){
                            newMaze[x][y][z] = token;
                            num++; //keep track of what number of token we're parsing
                        }else{
                            //the token failed the valid input tests
                            cout << "INVALID TOKEN" << endl;
                            return false;
                        }
                    } else {
                        //reached the end of the file before finishing the loops
                        cout << "INCOMPLETE FILE" << endl;
                        return false;
                    }
                }
            }
        }       
    } else {
        //invalid file
        cout << "INVALID FILE" << endl;
        return false;
    }
    if(import >> token){
        //too long of a file
        cout << "FILE TOO LONG" << endl;
        return false;
    }
    
    copyArray(newMaze, maze);
    return true;
}
bool Pathfinder::findPath(int x, int y, int z){
    return false;
}
vector<string> Pathfinder::solveMaze(){
    vector<string> test;
    return test;
}

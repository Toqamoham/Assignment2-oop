//
// Created by DreamOnline on 11/16/2022.
//

#include <iostream>
#include<fstream>

using namespace std;

#ifndef UNTITLED45_UNIVERSE_H
#define UNTITLED45_UNIVERSE_H

#define SIZE 20



class Universe {

    char arr[SIZE+2][SIZE+2];

public:

    void reset();
    void initialize();
    int count_neighbors(int x , int y);
    void nextGeneration();
    void disPlay();
    void run(int num);


};


#endif //UNTITLED45_UNIVERSE_H

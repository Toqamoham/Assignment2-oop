//
// Created by DreamOnline on 11/16/2022.
//



#include "Universe.h"

void Universe::reset() {

    for(int i = 0 ; i <= SIZE+2 ; i++){

        for(int j = 0 ; j <= SIZE+2 ; j++){

            arr[i][j] = '0';
        }
    }

}

void Universe::initialize() {

    reset();

    fstream File("GameOfLife.txt");

    string line;

    int j = 1;

    while (File >> line){

        for(int i = 1 ; i <= SIZE ; ++i ){

            arr[j][i] = line[i - 1];
        }

        j++;
    }
}

int Universe::count_neighbors(int x, int y) {

    int result = 0;

    if(arr[x][y] == '1'){

        result = -1;
    }

    for(int i = x-1 ; i <= x+1 ; i++){

        for(int j = y-1 ; j <= y+1 ; j++){

            if( arr[i][j] == '1'){

                result++;
            }
        }

    }

    return result;

}

void Universe::nextGeneration() {

    char arr2[SIZE+2][SIZE+2] = {{'0'}};

    for(int i = 1 ; i <= SIZE ; i++){

        for(int j = 1 ; j <= SIZE ; j++){

            int neighbors = count_neighbors(i ,j);

            if(arr[i][j] == '1' && (neighbors == 2 || neighbors == 3) ){

                arr2[i][j] = '1';
            }

            else if(arr[i][j] == '0' && neighbors == 3){

                arr2[i][j] = '1';
            }

            else{

                arr2[i][j] = '0';
            }


        }
    }

    for(int i = 1 ; i <= SIZE ; i++){

        for(int j = 1 ; j <= SIZE ; j++ ){

            arr[i][j] = arr2[i][j];
        }
    }

}

void Universe::disPlay() {

    for(int i = 1 ; i <= SIZE ; i++) {

        for (int j = 1; j <= SIZE; j++) {

            cout << arr[i][j];
        }

        cout << endl;

    }

}

void Universe::run(int num) {

    reset();
    initialize();

    for(int i = 0 ; i < num ; i++){

        cout << "\n-------------------------- ( " << i+1
             << " \\ " << num << " ) --------------------------\n" ;


        nextGeneration();

        disPlay();

        system("pause");


    }

}



//
// Created by klusukas on 09.03.18.
//

#include "Array2D.h"


int **NewArray2D(int n_rows, int n_columns){
    if(n_rows <= 0 || n_columns <= 0)return nullptr;
    int** array = new int*[n_rows];
    for(int i=0;i<n_rows;i++){
        array[i] = new int[n_columns];
    }
    int d = 1;
    for(int i=0;i<n_rows;i++){
        for(int j=0;j<n_columns;j++){
            array[i][j] = d++;
        }
    }
    return array;
}


void DeleteArray2D(int **array, int n_rows, int n_columns){
    for(int i=0;i<n_rows;i++){
        delete [] array[i];
    }
    delete [] array;
}
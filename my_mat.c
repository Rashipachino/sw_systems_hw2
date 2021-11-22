#include <stdio.h>
#include "my_mat.h"

#define N 10

void optionA(int mat[N][N]) {
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void optionB(int mat[N][N]) {

}

void optionC(int mat[N][N]) {

}
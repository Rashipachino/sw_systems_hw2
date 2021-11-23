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
    int a, b;
    scanf("%d %d", &a, &b);
    if(optionBHelper(mat, a, b,)) {
        printf("True");
    }
    else {
        printf("False");
    }
}

int optionBHelper(int mat[N][N], int a, int b) {  // not done
    if(mat[a][b] != 0) {
        return 1;
    }
    for (int i = 0; i < N; i++) {
        if(mat[a][i] && optionBHelper(mat, i, b)) {
            return 1;
        }
    }
}

void optionC(int mat[N][N]) { // not done

}
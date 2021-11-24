// Noah Weiss 326876786
// Rashi Pachino 345174478

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

int optionB(int mat[N][N], int a, int b) {
    if(a == b) {
        return 0;
    }
    int been_there[N] = {0};
    return optionBHelper(mat, a, b, been_there);
}

int optionBHelper(int mat[N][N], int a, int b, int been_there[N]) {
    if(mat[a][b] != 0) {
        return 1;
    }
    been_there[a] = 1;
    for (int i = 0; i < N; i++) {
        if(mat[a][i] && been_there[i] == 0) {
            return optionBHelper(mat, i, b, been_there);
        }
    }
    return 0;
}

int optionC(int mat[N][N], int a, int b) {
    if(a == b) {
        return -1;
    }
    int A[N][N] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(i != j) {
                if(mat[i][j] == 0) {
                    A[i][j] = -1;
                }
                else {
                    A[i][j] = mat[i][j];
                }
            }
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(i != j && i != k && j != k) {
                    A[i][j] = min(A[i][j], A[i][k], A[k][j]);
                }
            }
        }
    }
//    printf("\n\nC (%d, %d)\n", a, b);
//    for (int i = 0; i < N; i++) {
//        printf("%d  ", i);
//        for (int j = 0; j < N; j++) {
//            printf("%d ", A[i][j]);
//        }
//        printf("\n");
//    }
    return A[a][b];
}

int min(int a, int b, int c) {
    if(b == -1 || c == -1) {
        if(a == -1) {
            return -1;
        }
        return a;
    }
    if(a == -1) {
        return b+c;
    }
    return a < b+c ? a : b+c;
}
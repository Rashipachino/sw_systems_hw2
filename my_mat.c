#include <stdio.h>
#include "my_mat.h"

#define N 10

int main() {
    int arr[N][N];
    optionA(arr);
    optionB(arr);
}

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
    int been_there[N] = {0};
    if(optionBHelper(mat, a, b, been_there)) {
        printf("True");
    }
    else {
        printf("False");
    }
}

int optionBHelper(int mat[N][N], int a, int b, int been_there[N]) {
    if(mat[a][b] != 0) {
        return 1;
    }
    been_there[a] = 1;
    for (int i = 0; i < N; i++) {
        if(mat[a][i] && been_there[i] == 0 && optionBHelper(mat, i, b, been_there)) {
            return 1;
        }
    }
    return 0;
}

void optionC(int mat[N][N]) { // not done

}
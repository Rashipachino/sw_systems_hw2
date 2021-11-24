// Noah Weiss 326876786
// Rashi Pachino 345174478

#include <stdio.h>
#include "my_mat.h"

#define N 10

void optionA(int mat[N][N]) {  // fills the matrix with the inputted ints
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &mat[i][j]);  // input the next int
        }
    }
}

int optionB(int mat[N][N], int a, int b) {  // returns 1 if there is a path between a and b otherwise returns 0
    if(a == b) {
        return 0;
    }
    int been_there[N] = {0};  // to keep track of the nodes that i have already been to
    return optionBHelper(mat, a, b, been_there);
}

int optionBHelper(int mat[N][N], int a, int b, int been_there[N]) {  // recursive function that travels through the paths that start from node a and returns 1 if it gets to node b otherwise returns 0
    if(mat[a][b] != 0) {  // if there is a path between a and b
        return 1;
    }
    been_there[a] = 1; // update been_there that ive been to this node
    for (int i = 0; i < N; i++) {
        if(mat[a][i] && been_there[i] == 0) {  // if there is a path and if I haven't been to that node yet
            return optionBHelper(mat, i, b, been_there);  // recursively calls itself as the node i
        }
    }
    return 0; // if there is no path to b
}

void optionC(int mat[N][N], int shortest_paths[N][N]) {  // this function is based off the Floyd–Warshall algorithm. it crates a new matrix that will hold all of the values of the shortest path between two nodes and then copies it to shortest_paths
    int A[N][N] = {0};  // creates a matrix that will keep track of the values of the shortest path from one node to another
    for (int i = 0; i < N; i++) {  // these fors are for copying the original matrix to a new one with modifications so that it will work with the Floyd–Warshall algorithm
        for (int j = 0; j < N; j++) {
            if(i != j) {
                if(mat[i][j] == 0) {  // if the value is 0 then there is no path between the two nodes so set it to be -1 in A
                    A[i][j] = -1;
                }
                else {
                    A[i][j] = mat[i][j];  // otherwise copy the value
                }
            }
        }
    }
    for (int k = 0; k < N; k++) {  // implementation of the Floyd–Warshall algorithm
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(i != j && i != k && j != k) {
                    A[i][j] = min(A[i][j], A[i][k], A[k][j]);
                }
            }
        }
    }
    for (int i = 0; i < N; i++) { // copies the values of A in to shortest_paths which will be used in the main function
        for (int j = 0; j < N; j++) {
            shortest_paths[i][j] = A[i][j];
        }
    }
}

int min(int a, int b, int c) {  // checks what the minimum of a and b+c
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
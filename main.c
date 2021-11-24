// Noah Weiss 326876786
// Rashi Pachino 345174478

#include <stdio.h>
#include "my_mat.h"

#define N 10

int main() {
    int mat[N][N], a, b, shortest_paths[N][N] = {0};  // create a matrix to store the values of the graph
    char chosen_option;  // stores choice A/B/C/D
    int flag = 0;  // indicator if there are new values in mat
    scanf("%c", &chosen_option);

    while (chosen_option != 'D') {  // while D isn't inputted
        if(chosen_option == 'A') {
            optionA(mat); // sets the values of the matrix from the input
            flag = 1;  // set to 1 because there are new values in mat
        }
        else if(chosen_option == 'B') {
            scanf("%d %d", &a, &b);
            if(optionB(mat, a, b)) {  // checks if there is a path between the two nodes
                printf("True\n");
            }
            else {
                printf("False\n");
            }
        }
        else if(chosen_option == 'C') {
            scanf("%d %d", &a, &b);
            if(a == b) {  // if the nodes are the same
                printf("-1\n");
            }
            else {
                if(flag) {  // if the matrix has been updated since the last time it was here
                    optionC(mat, shortest_paths);  // put the values of all of the shortest paths in shortest_paths
                    printf("%d\n", shortest_paths[a][b]);
                    flag = 0; // set to 0 because the shortest paths won't change until there is a new matrix
                }
                else {
                    printf("%d\n", shortest_paths[a][b]);
                }
            }
        }
        scanf("%c", &chosen_option);
    }
    return 0;
}
// Noah Weiss 326876786
// Rashi Pachino 345174478

#include <stdio.h>
#include "my_mat.h"

#define N 10

int main() {
    int mat[N][N], a, b;
    char chosen_option;
    scanf("%c", &chosen_option);

    while (chosen_option != 'D') {
        if(chosen_option == 'A'){
            optionA(mat);
        }
        else if(chosen_option == 'B') {
            scanf("%d %d", &a, &b);
            if(optionB(mat, a, b)) {
                printf("True\n");
            }
            else {
                printf("False\n");
            }
        }
        else if(chosen_option == 'C') {
            scanf("%d %d", &a, &b);
            printf("%d\n", optionC(mat, a, b));
        }
        scanf("%c", &chosen_option);
    }
    return 0;
}
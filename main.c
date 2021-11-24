#include <stdio.h>
#include <string.h>
#include "my_mat.h"

#define N 10

int main() {
//    int mat[N][N];
    char chosen_option;
    scanf("%c", &chosen_option);

    while (chosen_option != 'D') {
        if(chosen_option == 'A'){
            optionA(mat);
        }
        else if(chosen_option == 'B') {
            optionB(mat);
        }
        else if(chosen_option == 'C'){
            optionC(mat);
        }
        scanf("%c", &chosen_option);
    }
    return 0;
}



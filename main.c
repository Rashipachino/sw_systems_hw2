#include <stdio.h>
#includ <stdlib.h>
#include "my_mat.h"

#define N 10

int main() {
    enum option { A, B, C, D};

    enum option chosen_option;

    int mat[N][N];

    /* asks user to choose an option*/
    printf("Please choose which function you'd like to activate: A. function 1, B. function 2, C. function 3, D. exit ");
    scanf("%d", &chosen_option);

    while(chosen_option != null) {
        /*activate the correct function*/
        switch (chosen_option) {
            case A:
                printf("You have chosen function 1!");
                optionA(mat);
                break;

            case B:
                printf("You have chosen function 2!");
                optionB(mat);
                break;

            case C:
                printf("You have chosen function 3!");
                optionC(mat);
                break;

            case D:
                printf("You've chosen to exit the program!");
                break;
        }

        printf("Please enter the next function you'd like to activate: A. function 1, B. function 2, C. function 3, D. exit");
        scanf("%d", &chosen_option);
    }
    }

}

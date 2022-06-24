#include<stdio.h>

#include<stdlib.h>

#include<time.h>

#define ROW 15
#define COLUMN 30

void fill_Array(int array_game[ROW][COLUMN]); /* I create my function for clear code to firstly fill the array with roads of gamer */
int move_gamer(int array_game[ROW][COLUMN], int player_1, int player_2);  /* I create my function for clear code to move of gamer */

void print_Map(int array_game[ROW][COLUMN]);	/* print map of game */
int dice();		/* returns dice range pf [1,6] */
int start_Game();		/* start game, Players should dice and decide who is going to start first according to it */

int main() {
    int array_game[ROW][COLUMN], player_1, player_2, result, flag = 0;

    fill_Array(array_game); /* I create my function for clear code to firstly fill the array with roads of gamer */
    print_Map(array_game); /* print game are ı use parameter to print 2d  array  */
    result = start_Game(); 		/* decides according to dice numbers and return the number of player who will start */
    if (result == 1) {
        printf("\e[33m***PLAYER 1 will start the game..***\e[0m\n");  
        do {
            printf("\e[33mPLAYER 1... press ENTER to dice\e[0m");
            getchar();
            player_1 = dice();		/* return the number of integer to player 1 */
            printf("\e[33mDİCE: %d\e[0m\n", player_1);
            printf("\e[34mPLAYER 2... press ENTER to dice\e[0m");
            getchar();
            player_2 = dice();					/* return the number of integer to player 2 */
            printf("\e[34mDİCE: %d\e[0m\n", player_2);
            flag = move_gamer(array_game, player_1, player_2); 	 /* to move of gamer player 1 and player 2 */
            print_Map(array_game);
        } while (flag == 0); 						/* while a player won the game it continou */
    } else if (result == 2) {
        printf("\e[34m***PLAYER 2 will start the game..***\e[0m\n");

        do {
            printf("\e[34mPLAYER 2... press ENTER to dice\e[0m");
            getchar();
            player_2 = dice();
            printf("\e[33mDİCE: %d\e[0m\n", player_2);
            printf("\e[33mPLAYER 1... press ENTER to dice\e[0m");
            getchar();
            player_1 = dice();
            printf("\e[33mDİCE: %d\e[0m\n", player_1);
            flag = move_gamer(array_game, player_1, player_2);
            print_Map(array_game);
        } while (flag == 0);						/* while a player won the game it continou */
    }
}

int move_gamer(int array_game[ROW][COLUMN], int player_1, int player_2) {	/* to move of gamer player 1 and player 2 */
    int player_1i, player_1k, player_2i, player_2k;

    for (int i = 0; i < ROW; i++) {			/* remove player 1 and player 2 to reset the them game area */
        for (int k = 0; k < COLUMN; k++) {
            if (array_game[i][k] == '1') {		
                player_1i = i;
                player_1k = k;
                array_game[i][k] = ' ';
            }
            if (array_game[i][k] == '2') {
                player_2i = i;
                player_2k = k;
                array_game[i][k] = ' ';
            }
        }

    }

    while (player_1 > 0) {
        if (array_game[player_1i - 1][player_1k] != '.' && player_1k == 1) {		/* move the player 1 according to return value of dice function*/
            player_1i--;
            player_1--;
            if (array_game[player_1i][player_1k] == '_') {			/* if player 1 crosses the line , player win */
                printf("\e[33m\n\n*** PLAYER 1 WON THE GAME ***\n\n\e[0m");
                return 1;
            }
        } else if (array_game[player_1i][player_1k + 1] != ':' && player_1i == 1) {
            player_1k++;
            player_1--;
        } else if (array_game[player_1i + 1][player_1k] != '.' && player_1k > 20) {
            player_1i++;
            player_1--;
        } else if (array_game[player_1i][player_1k - 1] != ':' && player_1i > 10) {
            player_1k--;
            player_1--;
        }

    }
    if (array_game[player_1i][player_1k] == 'X') {			/* if player 1 comes to penalty spot ,it comes back 2 step */
        printf("\e[33mPenalty for player 1...\e[0m\n");
        if (player_1i == 1 && player_1k == 14) {
            array_game[player_1i][player_1k - 2] = '1';

        } else if (player_1i == 13 && player_1k == 14) {
            array_game[player_1i][player_1k + 2] = '1';

        } else if (player_1i == 7 && player_1k == 28) {
            array_game[player_1i - 2][player_1k] = '1';

        }

    } else {
        array_game[player_1i][player_1k] = '1';
    }
    while (player_2 > 0) {				/* move the player 2 according to return value of dice function */
        if (array_game[player_2i - 1][player_2k] != '.' && player_2k < 5) {
            player_2i--;
            player_2--;
            if (array_game[player_2i][player_2k] == '_') {				/* if player 1 crosses the line , player win */
                printf("\n\n\e[34m*** PLAYER 2 WON THE GAME ***\e[0m\n\n");
                return 2;
            }
        } else if (array_game[player_2i][player_2k + 1] != ':' && player_2i < 5) {
            player_2k++;
            player_2--;
        } else if (array_game[player_2i + 1][player_2k] != '.' && player_2k > 20) {
            player_2i++;
            player_2--;
        } else if (array_game[player_2i][player_2k - 1] != ':' && player_2i > 6) {
            player_2k--;
            player_2--;
        }
    }
    if (array_game[player_2i][player_2k] == 'X') { 		/* if player 2 comes to penalty spot ,it comes back 2 step */
        printf("\e[34mPenalty for player 2...\e[0m\n");
        if (player_2i == 3) {
            array_game[player_2i][player_2k - 2] = '2';

        } else if (player_2k == 26) {
            array_game[player_2i - 2][player_2k] = '2';

        } else if (player_2i == 11) {
            array_game[player_2i][player_2k + 2] = '2';
        }
    } else {
        array_game[player_2i][player_2k] = '2';
    }
    return 0;

}
void print_Map(int array_game[ROW][COLUMN]) {		/* print the game area */
    int k, i;
    for (i = 0; i < ROW; i++) {
        for (k = 0; k < COLUMN; k++) {
			if(array_game[i][k]=='X'){
			 printf("\e[31m%c\e[0m",array_game[i][k]);
            }else if(array_game[i][k]=='_'){
			 printf("\e[32m%c\e[0m",array_game[i][k]);
            }else if(array_game[i][k]=='1'){
			 printf("\e[33m%c\e[0m",array_game[i][k]);
             }else if(array_game[i][k]=='2'){
			 printf("\e[34m%c\e[0m",array_game[i][k]);
             }else{
             printf("%c", array_game[i][k]);
             }
             
        }
        printf("\n");
    }
}

int dice() {		/* returns a random integer in a range of [1,6] */
    int value;
    srand(time(NULL));
    value = rand() % 6 + 1;
    return value;
}

int start_Game() { 		/* start game, Players should dice and decide who is going to start first according to it */
    int player_1, player_2, same = 1;
    printf("\n\nTo start game, Players should dice and decide who is going to start first according to it...\n\n");
    while (same == 1) {
        printf("\e[33mPLAYER 1... press ENTER to dice\e[0m");
        getchar();
        player_1 = dice();
        printf("\e[33mDİCE: %d\e[0m\n", player_1);
        printf("\e[34mPLAYER 2... press ENTER to dice\e[0m");
        getchar();
        player_2 = dice();
        printf("\e[34mDİCE: %d\e[0m\n", player_2);
        if (player_1 == player_2) {
            same = 1;
            printf("Same dice value... Please try again.\n");
        } else {
            same = 0;
            break;
        }
    }
    if (player_1 > player_2)
        return 1;
    if (player_2 > player_1)
        return 2;

}

/* I create my function for clear code to firstly fill the array with roads of gamer */
void fill_Array(int array_game[ROW][COLUMN]) {		
    int i, k, flag = 0, player_1i = 1, player_1k = 1, player_2i = 3, player_2k = 3, player_1, player_2,
        finish = 0, same = 1, result, right = 1, upper = 1, lower = 1, left = 1;

    for (i = 0; i < ROW; i++) {
        for (k = 0; k < COLUMN; k++) {
            if (i == 0 || i == ROW - 1) {
                array_game[i][k] = '.';

            } else if (k == 0 || k == COLUMN - 1) {		/* determines the path and boundaries of the game area and penalty points  */
                array_game[i][k] = ':';
            } else if ((k == 2 && i > 2 && i < ROW - 3) || (k == COLUMN - 3 && i > 2 && i < ROW - 3)) {
                array_game[i][k] = ':';
            } else if ((k == 4 && i > 4 && i < ROW - 5) || (k == COLUMN - 5 && i > 4 && i < ROW - 5)) {
                array_game[i][k] = ':';
            } else if ((i == 2 && k >= 2 && k <= COLUMN - 3) || (i == ROW - 3 && k >= 2 && k <= COLUMN - 3)) {
                array_game[i][k] = '.';
            } else if ((i == 4 && k >= 4 && k <= COLUMN - 5) || (i == ROW - 5 && k >= 4 && k <= COLUMN - 5)) {
                array_game[i][k] = '.';
            } else if (i == 2 && k == 1) {
                array_game[i][k] = '_';  
            } else if (i == 4 && k == 3) {
                array_game[i][k] = '_';
            } else if ((i == 1 && k == 14) || (i == 13 && k == 14) || (i == 7 && k == 28)) {
                array_game[i][k] = 'X';
            } else if ((i == 3 && k == 10) || (i == 3 && k == 18) || (i == 5 && k == 26) || (i == 10 && k == 26) || (i == 11 && k == 10) || (i == 11 && k == 18)) {
                array_game[i][k] = 'X';
            } else if (player_1i == i && player_1k == k) {
                array_game[i][k] = '1';
            } else if (player_2i == i && player_2k == k) {
                array_game[i][k] = '2';
            } else {
                array_game[i][k] = ' ';
            }

        }
    }
}

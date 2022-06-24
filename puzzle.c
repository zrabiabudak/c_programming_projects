#include<stdio.h>

#include<stdlib.h>

#define N 10				/* N*N game  */


enum direction {
    leftdir,
    rightdir,
    updir,
    downdir,
    break_up
};

void get_randomNum(int puzzle[][N]); /* get the random number */
void print_game(int puzzle[][N]); /* print the GAME on console */
void move_left(int puzzle[][N], int row, int column);  /* shift the left number */
void move_right(int puzzle[][N], int row, int  column); /* shift the rigth number */
void move_up(int puzzle[][N], int  row, int  column);		/* shift the up number */
void move_down(int puzzle[][N], int row, int column);		/* shift the down number */
int check_game_finish(int puzzle[][N]);			/*chek the game whether finish or not*/

int main() {

    int row, column;

    enum direction direct;
    int puzzle[N][N];
    get_randomNum(puzzle); 		/*full the array with random number*/
    printf("***YOU ARE WELCOME TO THE GAME***\n\n");
    while ((check_game_finish(puzzle) != 0) && direct!= break_up) {
        print_game(puzzle);
	   printf("\n0:left direction  \n1:right direction \n2:up direction \n3:down direction \n4:break up\n");
	  printf("Please enter the move diretion or break up ");
        scanf("%u", & direct);
       switch (direct) {
        case leftdir:		/* if the user enter 0 */
		printf("Please enter the location start row and column to left movement"); 
		scanf("%d %d",&row,&column);
            move_left(puzzle, row,  column);
            break;
        case rightdir:		/* if the user enter 1 */
		printf("Please enter the location start row and column to right movement"); 
		scanf("%d %d",&row,&column);
            move_right(puzzle, row,  column);
            break;
        case updir:			/* if the user enter 2 */
		printf("Please enter the location start row and column to up movement"); 
		scanf("%d %d",&row,&column);
            move_up(puzzle, row,  column);
            break;
        case downdir:				/* if the user enter 3 */
			printf("Please enter the location start row and column to down movement"); 
		scanf("%d %d",&row,&column);
            move_down(puzzle, row,  column);
            break;
		case break_up:				/* if the user enter 4 */
		printf("Good by\n");
		break;
        default:
            break;
        }
    }
}
int check_game_finish(int puzzle[N][N]) {		/*Checking if array elements are sequenced or not*/
    int control = 0, temp, i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
				
            if (puzzle[i][j] != puzzle[i][j++]-1) {
                control = 1;
            }
        }

    }
    return control;
}

void move_down(int puzzle[N][N], int row, int column) {
    int flag = 0, i, j, counter = 0, temp = 0;
    if ( column < 0 || row < 0 || row >= N || column > N) {
        printf("error.. please enter new row and column\n");
    } else {
        /*check the game of row and column whether is there 0 this row the down  */
        for (i =row; i <N; i++) {
            if (puzzle[i][ column] == 0) {
                flag = 1;
                break;
            }
            counter++;
        }

        if (flag == 1) {
            i = row;
            while (counter != 0) {

                puzzle[i + counter][ column] = puzzle[i + counter - 1][column];

                counter--;
            }
            puzzle[ row][ column] = 0;
        }

    }
}

void move_up(int puzzle[N][N], int row, int column) {
    int flag = 0, i, j, counter = 0, temp = 0;
    if (  column < 0 || row <= 0 ||  row > N ||  column > N) {
        printf("error.. please enter new row and column\n");
    } else {
        /*check the game of row and column whether is there 0 this row the up  */
        for (i =row; i >= 0; i--) {
            if (puzzle[i][column] == 0) {
                flag = 1;
                break;
            }
            counter++;
        }

        if (flag==1) {   /*this flag means that there is 0 this column*/
            i=row;
            while (counter!=0) {

                puzzle[i-counter][column]=puzzle[i-counter+1][column];

                counter--;
            }
            puzzle[row][column]=0;
        }

    }
}

void move_right(int puzzle[N][N], int row, int column) {
    int flag = 0, i, j, counter = 0, temp = 0;
    if ( column < 0 || row < 0 || row > N || column >= N) { /* to burder of game */
        printf("error.. please enter new row and column\n");
    } else {
        /*check the game of row and column whether is there 0 this row on the right  */
        for (i = column; i < N; i++) {
            if (puzzle[row][i] == 0) {
                flag = 1;
                break;
            }
            counter++;
        }

        if (flag == 1) {				/*this flag means that there is 0 this row*/
            i = column;
            while (counter != 0) {

                puzzle[row][i+counter] = puzzle[row][i+counter-1];

                counter--;
            }
            puzzle[row][column]=0;
        }

    }
}

void move_left(int puzzle[N][N], int row, int column) {
    int flag =0,i,j,new_space,counter=0,temp=0;
    if ( column <= 0 ||  row < 0 ||  row > N || column > N) {
        printf("error.. please enter new row and column\n");
    } else {
        /*check the game of row and column whether is there 0 this row on the left  */
        for (i = column; i >= 0; i--) {
            if (puzzle[ row][i] == 0) {
                flag = 1;
                break;
            }
            counter++;
        }

        if (flag == 1) {				/*this flag means that there is 0 this row*/
            i = column;
            while (counter != 0) {

                puzzle[row][i-counter] = puzzle[row][i-(counter-1)];

                counter--;
            }
            puzzle[row][column] = 0;
        }

    }

}

void get_randomNum(int puzzle[][N]) {

    int num = 0, i = 0, j = 0, space, temp, randRow, randColumn,k = 0;

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {   /*fill the array number one by one*/
            puzzle[i][j] = k;
            k++;
        }

    }

    for (i = 0; i < N; i++) { 	/* to mixer the array */
        for (j = 0; j < N; j++) {
            randRow = rand() % (N); /* row of game */
            randColumn = rand() % (N);/* column of game */
            temp = puzzle[i][j];

            puzzle[i][j] = puzzle[randRow][randColumn];

            puzzle[randRow][randColumn] = temp;

        }

    }

}
void print_game(int puzzle[N][N]) {

    for (int i = 0; i < N; i++) { /* ROW of game */
			for(int j=0;j<5*N+1;j++){
				printf("*");
			}
		printf("\n");
        for (int j = 0; j < N; j++) { /*COLUMN of game */
			
		if(puzzle[i][j]<0){  /* for  beauty display of the numbers on the screen */
		  //printf("*");
            printf( "%2d  ",puzzle[i][j]);
		
		}else if(puzzle[i][j]==0){
				printf("*    ");	
		}else{
			 printf("*");
		  printf("%3d ",puzzle[i][j]);
			
		}
        }
        printf("*\n");
		
    }
	for(int j=0;j<5*N+1;j++){
	printf("*");
	}
   printf("\n\n\n");
}



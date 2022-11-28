#include<stdio.h>

#define MAX 512		/* Maximum size of matrix 512 X 512 */
#define Water -1	/* i assigned -1 to the underwater places */

void Fill_in_Matrix(FILE * fp1, int Matrix[MAX][MAX], int * Water_Level);  /*  read all of integers in input file and create a 512x512 matrix. Integers are listed in row-order.*/ 
void Find_Water(int Matrix[MAX][MAX], int Water_Level);		/* if points in array  smaller than water level i assigned -1 this points */
int Find_Island(int Matrix[MAX][MAX], int Water_Level);		/* to identify island is the collection of terrain points,above water*/
void coordinate_islands(FILE * fp2,int Matrix[MAX][MAX],int number_island ); /* write in output file coordinate of islands */

int main() {
    FILE * fp1, * fp2;
    int Water_Level = 0,island=-2,number_island=0,result;
    int Matrix[MAX][MAX];

    fp1 = fopen("input.txt", "r");	/*creates input file */ 
    fp2 = fopen("output.txt", "w+"); /*creates output file */ 

    Fill_in_Matrix(fp1, Matrix, & Water_Level);  /* fill the matrix */
    Find_Water(Matrix, Water_Level);	/* determine the water points */
    result=Find_Island(Matrix, island); /* return value of function last islands values */
    number_island=(-1*result)-2;/* i have assigned the value -1 to the points that are underwater in the matrix. then i assigned the -2 value to the points that are islands, and i continued by reducing this value to the other islands. so to find number of island i multiplied the value of the last island by -1 and then reduced it by 2.*/
  coordinate_islands(fp2,Matrix,number_island );	
    fclose(fp1);		/* close the input file */
    fclose(fp2);		/* close the output file */
}

void coordinate_islands(FILE *fp2,int Matrix[MAX][MAX],int number_island ){ /* read output file from every island 1 points. */
int island=-2;
  while(number_island>0){
	 for(int i=0;i<MAX;i++){   

		 for(int j=0;j<MAX;j++){
	 		if(Matrix[i][j]==island){	/* check the matrix value */
				fprintf(fp2,"%d %d",i,j);
				island--;   /* reducing value of island by 1 */
				number_island--; /* count of number island  */
				fprintf(fp2,"\n");   /* write coordinate of island  output file*/
			}
		 }
	  }
    }
 }



int Find_Island(int Matrix[MAX][MAX], int island) {
int  flag = 0,temp=0,flag2=0,check=1;

for (int i = 0; i <MAX ; i++) {			/* I assigned the value of the island (first island -2 and then reducing by 1)to a place higher than the water level (water level and smaller than water level points that i assign -1 in the matrix). and then i assigned the value to the new island after checking it each time. */
        for (int j = 0; j <= MAX - 1; j++) {
           if( Matrix[i][j]>=0 ){
			flag=1;
			Matrix[i][j]=island;   
			break;
		  }
	  }
if(flag==1)
break;
}
  while(check!=0){
   check=1;

   for(int i = 0; i <MAX ; i++) {   /* to check coordinate of matrix */
        for (int j = 0; j < MAX ; j++) {
            if( j<MAX-1 && Matrix[i][j]==island && Matrix[i][j+1]!=island && Matrix[i][j+1]!=Water ){ /* check right */
			Matrix[i][j+1]=island;
			check=2;
		   }if( i<MAX-1 && Matrix[i][j]==island && Matrix[i+1][j]!=island && Matrix[i+1][j]!=Water ){ /* check down */
			Matrix[i+1][j]=island;
			check=2;
		   }if( i>0 && Matrix[i][j]==island && Matrix[i-1][j]!=island && Matrix[i-1][j]!=Water ){ /* check up */
			Matrix[i-1][j]=island;			
			check=2;
		   }if( j>0 && Matrix[i][j]==island && Matrix[i][j-1]!=island && Matrix[i][j-1]!=Water ){ /* check left */
			Matrix[i][j-1]=island;
			check=2;
		   }

	   }
   if(check==2)
   break;
   }
   if(check==1)
	check=0;
}

		if(flag==0) /* If I have determined all the island points in the matrix, I finish the function. and return the last value of islands */
			return island;

		return(Find_Island(Matrix, island-1)); /* After determining all the points above the water and giving the island value, I decreased the island by 1 with recursion function. */
}

void Find_Water(int Matrix[MAX][MAX], int Water_Level) {  /* It assigns -1 to places that are smaller than the water levels in the array. */
    int flag = 1, flag_2 = 0, counter_X = 0, counter_Y = 0;

    while (flag) {

        if (counter_Y == MAX - 1 && counter_X == MAX - 1) /* If the matrix has reached the end of the array*/
            flag = 0;					/* If the matrix has reached the end of the array, flag = 0 so  do not continue. */

        if (Matrix[counter_Y][counter_X] < Water_Level) /* it compare water level and points of matrix if points smaller than water level it water  */
            Matrix[counter_Y][counter_X] = Water;
        

        if (counter_X == MAX-1 && counter_Y < MAX-1) {  /* if coordinate of x equal to MAX then it reset to 0 and Increase the y coordinate by 1. */
            counter_X = 0;
            counter_Y = counter_Y + 1;
            flag_2 = 1;
        }
        if (counter_X < MAX - 1 && flag_2 == 0)	/* if coordinate of x smaller than  MAX -1 it Increase the x coordinate by 1. */
            counter_X = counter_X + 1;

        flag_2 = 0;   /* to check coordinate of x reached maximum or not  */
    }

}

void Fill_in_Matrix(FILE *fp1, int Matrix[MAX][MAX], int *Water_Level) { /* reads the integer data from the file and fill in the array.  */
    int point;
    fscanf(fp1, "%d", &point);
    *Water_Level = point;  /* (The L value) Reads the first integer for water level and assigns it to the water_level. */
    for (int i = 0; i <=MAX-1; i++) {
        for (int j = 0; j <=MAX-1; j++) {
            fscanf(fp1,"%d",&point); 	/* read integer in file and  the array  */
            Matrix[i][j] = point;
        }
    }
}

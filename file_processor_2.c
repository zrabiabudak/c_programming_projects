
/* *********maybe my code isn't efficient enough because i didn't use a function right now 
i thought it was too early to use a function. 
But I think my algorithm is fine.*************** */



#include<stdio.h>

#define MAX 100

#define REPEAT_NUM 2

int main() {
        FILE * fp;
	   FILE * fp1;
        fp = fopen("input.txt", "r+");
	   fp1 = fopen("output.txt", "r+");
        int numbers_file1, numbers_file2;
        int numbers_array[MAX][REPEAT_NUM];
        int counter1 = 1, /* calculate  how many numbers read from the file */
        flag = 0, /* to check if number is in array */
        count = 1, /* to calculate how many times the number is repeated */
        k = 0, /* to check if repeat number is in array  */
        i=1,r=0,
	   temp;   /* to keep numbers in temporary variable */
		
        while (fscanf(fp, "%d", & numbers_file1) != EOF){
                while (fscanf(fp, "%d", & numbers_file2) != EOF) {
                        if (numbers_file1 == numbers_file2) {   /* to calculate the number is repeated */
                                count++;
                        }
                }

                counter1++;
                if(i>1){
                    while ( k < i ) {
                            if (numbers_array[k][0] == numbers_file1) { /* to check if number is in array  */
                                flag = 1;
                            
                             }
				    	k++;  /* to read to the end of the array  */
                    }    
                }
			k=0;
                if (flag != 1) {          /* if number is not in array write it to array */
                        numbers_array[i][0] = numbers_file1;
                        numbers_array[i][1] = count;
				        
						i++;
						
                }

             count=1;
			    flag=0;
                fseek(fp, 0, SEEK_SET);  /* again to go to the next number in the file  */
                
                for (int m = 0; m < counter1-1; m++) {
                        fscanf(fp, "%d", & numbers_file2); 
                }
			
        }
		for (int s = 0; s < i; s++) {    
             for (int f = 0; f < i - s - 1; f++) {  
                if (numbers_array[f][1] > numbers_array[f+1][1]){ /* sort repeat numbers from smallest to largest  */
                   temp = numbers_array[f][1];                   /* sorting repeat number in array  */
                   numbers_array[f][1] = numbers_array[f+1][1];
                   numbers_array[f+1][1] = temp;
			
                   temp = numbers_array[f][0];                         /* sort number with repeat number */
                   numbers_array[f][0] = numbers_array[f+1][0];
                   numbers_array[f+1][0] = temp;
                }
                else if (numbers_array[f][1] == numbers_array[f+1][1] &&  numbers_array[f][0]> numbers_array[f+1][0]){/* if the number of repetitions is the same, write the smaller number */
		         	 temp = numbers_array[f+1][1];
                     numbers_array[f+1][1] = numbers_array[f][1];
                     numbers_array[f][1] = temp;
	     	
                 	 temp = numbers_array[f+1][0];
                     numbers_array[f+1][0] = numbers_array[f][0];
                     numbers_array[f][0] = temp;
		        }
			
           }
        }
			for(r=0;r<i-1;r++){     /* write the file numbers in array  */
			    fprintf(fp1,"%d",numbers_array[r][0]);
			    fputs(":",fp1);
			    fprintf(fp1,"%d",numbers_array[r][1]);
			    fputs("\n",fp1);
			}
  	    	      	fclose(fp);   /* close the file */
		          fclose(fp1);	
}




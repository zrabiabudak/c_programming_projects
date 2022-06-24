#include<stdio.h>
#include<string.h>

#define CHARACTER 250  		/* maximum number of character in file  */
 
  int func_recurs( char object_str[CHARACTER], FILE *fp_2  , int counter ,int count );
  
  int main(){

    int counter=0,     /*  to keep the counter of brackets */
		count=0 ;   /* to keep the array's counter */
    FILE *fp_1 , *fp_2;
    fp_1=fopen("input.txt","r");  /* open the input file */
    fp_2=fopen("output.txt","w+"); /* open output file and send it function */
    char character_in_file[CHARACTER];
	 
    fgets(character_in_file,CHARACTER,fp_1);  /* read characters a line  in file  */
    fclose(fp_1);						/* close the file   */
    func_recurs(character_in_file,fp_2, counter,count );  /* read line and write output file in this function  */
    fclose(fp_2);  /*close output file*/
  }
	  int func_recurs( char character_in_file[CHARACTER] , FILE *fp_2 , int counter, int count ){
	 

        if( character_in_file[count] != ','  && character_in_file[count]!= '('  && character_in_file[count]!=')' && character_in_file[count]!= '\0' && character_in_file[count] != ' ' ){ /* read characters one by one from array and check caharacter   */
		  if(counter>0){  					/* if counter grater than 0 write slash in file */
            	  for(int m=counter;m>0;m--){
                    fprintf(fp_2,"-" ); 		/* write slash in output file */
            	  }
		  }
            fprintf(fp_2,"%c",character_in_file[count]);  /* write character in file */
		  fprintf(fp_2,"\n");   /* write newline */
            
		   
        }
        if(character_in_file[count]=='(')   /* check character in array if character is comma then counter plus one */
           counter++;

        if(character_in_file[count]==')')  /* check character in line if character is comma then counter minus one */
           counter--;
       
        if(character_in_file[count]== '\0' )  /* if it reaches the end of the array, recursion stops */
		 return 1;

	    count++; 						/* to move through the array one by one */
        return(func_recurs(character_in_file,fp_2, counter,count));			/* recursion function   */
	
}


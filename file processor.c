#include<stdio.h>


/*When I entered 500 or 1000 inputs in my file, I could not observe the difference , but when I entered more numbers  and complex numbers like 100.000 numbers, it was a little slow running time. Then ı observe that running time depends on input but my algotihm is fine */


/*
In the code I wrote, I keep the number and I read from the file and check whether it is same to the end of the file. Then I continue from the first number after the number I kept.*/



int main() {
   FILE * fp;      
   fp = fopen("file.txt", "r+");  /* open the file for read and write */

   int num1,		/* number in file to comparison */
	end_num, 
	for_digit,    /* for digit divisor 10 by one by*/
	count=0, 			
	to_find,	      	 /*looks for the first number in the file.*/
	counter = 0, 			/*to calculate how many numbers it reads from the file*/
	flag = 0, 			/* to exit loop and finish the program */
	num_digit = 0;			/* digit of number */

   while (flag == 0) {
		counter++;
      if (fscanf(fp, "%d", &to_find) == EOF) {
         flag = 1;			
      }

      while (fscanf(fp, "%d", & num1) != EOF) {

         if (num1 ==to_find) {             /* If it is the number I am looking for  */
            for_digit = to_find;
            while (for_digit != 0) { 		/* I  find the number of digits with this loop */
               for_digit =for_digit / 10;
               num_digit++;
            }
		if (num1 < 0) {
               num_digit++;
            }
		if(num1==0){				/* num is equal to zero so  i directly change it spaces  */
			fseek(fp, -1, SEEK_CUR);
			fputs(" ", fp);
		  }
            fseek(fp, -num_digit, SEEK_CUR);         /* When I found the same number, I went back as many digits and put a space. */
            while (num_digit > 0) {
               fputs(" ", fp);				/* write the space characters as the find number of digits */
               num_digit--;
            }
         }

      }
      fseek(fp,0, SEEK_SET); 		/* to return to the starting point of file */
			count=counter;      /* I assigned the counter to another variable so I wouldn't lose totally how number  I read. */
		while(count>0){          
fscanf(fp, "%d", & end_num);   /* come to last read number and then go on  */
count--;
}	

   }

   fclose(fp);		/* when ı finish read file then ı closed the file */

}

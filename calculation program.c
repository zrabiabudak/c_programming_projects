#include<stdio.h>

void calculate_fibonacci_sequence();
void decide_perfect_harmonic_number();
void difference_max_min();
void bmi_calculation();

int main() {
	printf("******PART 1*********\n");
    calculate_fibonacci_sequence();
	printf("******PART 2*********\n");
    decide_perfect_harmonic_number();
	printf("******PART 3*********\n");
    difference_max_min();
	printf("******PART 4*********\n");
    bmi_calculation();
}

void calculate_fibonacci_sequence() {

    int is_num, 		/* it take input from user */
        sum = 0, 			/* sum two number for fibonacci */
        num1 = 0,		 /* first variable */
        num2 = 1, 		/* second variable */
        counter = 1,		 /* to keep the counter */
        flag = 0, 			/* it is to stop the loop */
        rtrn;		 /* return value of scanf */
    char c;
	printf("Please enter term(s) number :");
    while (flag == 0) {
        /* it continues until the flag value is 1 */
        rtrn = scanf("%d", & is_num); /* check the return value of scanf and If the return value is 1, it is a number, otherwise it is not number */
        if (c = getchar() == '*') {
            flag = 1; /* if user enter '*' the program stops */
            break;
        }
        if (rtrn == 1) {
            /* if user enter the number */
            if (is_num > 0) {
			printf("Fibonacci Sequence: \n");
                /* check the number pozitif or negatif */
                printf("%d\n", num2);
                while (counter < is_num) {
                    /* continue until the counter is equal to the number  */
                    sum = num1 + num2;
                    printf("%d\n", sum);
                    num1 = num2; /* num2 to num1 */
                    num2 = sum; /* sum to num2 */
                    counter++;
                } /* variables value returns to the beginning when the loop ends */
                counter = 1;
                sum = 0;
                num1 = 0;
                num2 = 1;
			 printf("Please enter term(s) number :");
            } else {
                printf("Please enter “positive” term(s) number: ");
            }
        } else {
            printf("Please enter “numeric” term(s) number: ");
        }

    }
}

void decide_perfect_harmonic_number() {

   float sum_p = 0.0, 		/* sum of divisors for perfect */
	counter = 1.0,           /*I assign 1 to this variable to divide the divisors by 1 */
	harmonic, 			/* result of finding harmonic number this variable */
	sum_h = 0.0, 			/* sum of variable to divide the divisors by 1 */
	check_harmon;			/* check if it is integer */
   long int i, 			/* to find divisor */
	num, 				/* input number */
	cont = 0;	
	int flag=0;
	char c;
			/* to number of divisor */
while(flag==0){
    printf("please enter input number ");
    scanf("%ld", & num);
if (c = getchar() == '*') {
            flag = 1; /* if user enter '*' the program stops */
            break;
        }
	printf("Natural Number Divisors: ");
    for (i = 1; i < num; i++) {
        if (num % i == 0) {
            printf("%ld", i);
            printf(", ");
            sum_p += i;  /* sum of divisor */
            sum_h += counter / (float) i;  /*  Dividing 1 by its divisors  */
            cont++;
        }
    }
    printf("%ld\n", num);  
    sum_h += counter / (float) num;  /* Dividing 1 by input num  */
    cont++;   
    harmonic = (float) cont / sum_h;  /* result of number for check harmonic or not */
    printf("is perfect number?:  ");
    if (sum_p == num) {   /* check perfect or not */
        printf(" Yes\n");
    } else {
        printf("No\n");
    }
    check_harmon = harmonic - (int) harmonic; /* check harmonic or not */
    printf("Is Harmonic Divisor Number?: ");

    if (check_harmon == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }   /* variables value returns to the beginning when the loop ends */
sum_p = 0.0;
cont = 0;	
sum_h = 0.0;
}

} 
void difference_max_min() {

    float input_nums = 5, 
	max, /* variable of max number */
	min, /* variable of min number */
	first_num;  /* first input  to compare */ 

    printf("Please enter 5 numbers:"); 
    scanf("%f",&first_num);
    max = first_num;
    min = first_num;
    for (int i = 1; i < input_nums; i++) {
        scanf("%f", & first_num);
        if (first_num < min) {	/* compare input to find minimum number */
            min = first_num;
        }
        if (max < first_num) {     	/* compare input to find maximum number */
            max = first_num;
        }
    }
    printf("Maximum number is:  %.2f\n", max);
    printf("Minimum number is:  %.2f\n", min);
    printf("Difference between maximum and minimum is %.2f\n", max - min);  /* to find maximum minimum difference */

}

void bmi_calculation() {

    float bmi_calc,			/* variable  to calculate BMİ  */
	weight, 				/* variable of weight of user */
	height;				/* variable of height of user */
    printf("Please enter weight(kg) : ");
    scanf("%f", & weight);
    printf("Please enter height(m): ");
    scanf("%f", & height);

    bmi_calc = weight / (height * height);  /* to calculate the body mass index */
    printf("Your category: ");

    if (bmi_calc < 16.0) {
        printf(" Severely Underweight \n");
    } else if (bmi_calc >= 16.0 && bmi_calc <= 18.4) {
        printf("Underweight\n");
    } else if (bmi_calc >= 18.5 && bmi_calc <= 24.9) {
        printf("Normal\n");
    } else if (bmi_calc >= 25.0 && bmi_calc <= 29.9) {
        printf(" Owerweight\n");
    } else if (bmi_calc >= 30.0) {
        printf(" Obese\n");
    }

}

#include<stdio.h>

void My_func_1();	/* enter the coefficient in this function  */
void My_func_2();	/* draw the graph in terminal */
void My_func_3();	/* print the graph into a. file */
void red ();		/* red color */
void yellow();		/* yellow color */
void reset ();		/* reset color */


int main(){
int select=0;  	/* select of user */

 while(select!=4){
  printf("Select an operation...\n");
  scanf("%d",&select);
   switch (select){
   case 1:
   My_func_1();
   break;
   case 2:
   My_func_2(); 
   break;
   case 3:
   My_func_3();
   break;
   } 

  }
}
void red () {  	/* red color code */
  printf("\033[1;31m");
}
void yellow() {	/* yellow color code */
  printf("\033[1;33m");
}
void reset () {	/* reset color code */
  printf("\033[0m");
}

void My_func_3(){	/* print the graph into a. file */
int a,b,c;
FILE *fp;
FILE *fp_2;
fp=fopen("coefficients.txt","r+");
fp_2=fopen("graph.txt","a");

fscanf(fp,"%d",&a);
fscanf(fp,"%d",&b);
fscanf(fp,"%d",&c);

  for(int i=26;i>=-25;i--){	/* k=x axis i=y axis */
	for(int k=-51;k<=50;k++){
		if(i==26 && k==0){
			fprintf(fp_2,"^");
		} if(i==-26 && k==0){
			fprintf(fp_2,"v");
		} if(k==51 && i==0){
			fprintf(fp_2,">");
		}if(k==-51 && i==0){
			fprintf(fp_2,"<");
		}
	
		if(k==a*i*i+b*i+c){
			fprintf(fp_2,"#");
		}else if(k==0 && i!=0 && i!=26 && i!=-26){
		fprintf(fp_2,"|");
		}else if(i==0  ){
		fprintf(fp_2,"-");
		}else{
		fprintf(fp_2," ");
		}
	}
	fprintf(fp_2,"\n");
  }
  fclose(fp);
  fclose(fp_2);
}

void My_func_2(){	/* draw the graph in terminal */
int a,b,c;
FILE *fp;
fp=fopen("coefficients.txt","r+");
fscanf(fp,"%d",&a);
fscanf(fp,"%d",&b);
fscanf(fp,"%d",&c);

for(int y=25;y>=-25;y--){	/* x axis and y axis*/
	for(int x=-50;x<=50;x++){
		
		if(y==25 && x==0){
			printf("\b^");
		} if(y==-25 && x==0){
			printf("\bv");
		} if(x==50 && y==0){
			printf("\b>");
		}if(x==-50 && y==0){
			printf("\b<");
		}	
		if(x==(a*y*y+b*y+c) ){
			
			if(x<0 && y<0){
				  printf("\b#");
				
				
			}if(x<0 && y>0){
				if(y<5){
				printf("\b#");
				}else if(y>5){
				printf("\b#");
				}else if(y==5){
				printf("\b#");
				}
			}if(x>=0 && y>=0){
				printf("#");
			}else if(x>=0 && y<=0){
			printf("#");
			}else if(x==0 && y==0){
			printf("#");
			}
			
		}else if(x==-1 && y%5==0 &&  y!=0){
			yellow();
			if(y<-9)
			printf("\b\b\b%d",y);
			if(y==-5)
			printf("\b\b%d",y);
			else if(y>5)
			printf("\b\b%d",y);
			else if(y==5)
			printf("\b%d",y);
			reset();
		}else if(y==-1 && x%10==0 && x!=0){
		yellow();
		printf("\b\b\b\b%d",x);
		reset();
		}else if(y==-1 && x==-1){
		yellow();
		printf("0");
		reset();
		}if(x==0 && y>-5 && y!=25 ){
		
		printf("\b|");
		
		} else if(x==0 && y<=-5 &&  y!=-25 ){
		
		printf("\b|");
		
		} else if(y==0 ){
		 printf("-");
		}else{
		printf(" ");
		}
		
	}
	printf("\n");
}

fclose(fp);
}



void My_func_1(){
int a,b,c;
FILE *fp;
fp=fopen("coefficients.txt","w+");

printf("please enter the coefficient for the following equation: x=a*(y*y) + b*y + c\n");
printf("a: ");
scanf("%d",&a);
printf("b: ");
scanf("%d",&b);
printf("c: ");
scanf("%d",&c);
fprintf(fp,"%d\n",a);
fprintf(fp,"%d\n",b);
fprintf(fp,"%d\n",c);
fclose(fp);
}

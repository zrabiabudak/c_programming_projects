#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct {
        char gats[10]; /* gate adı yani and mi or mu flipflop */
        char name1[10]; /* 1. input ismi */
        char name2[10]; /* 2.input ismi */
        char new_name[10]; /* and ya da or ladıktan sonra sonucu attığımız yeni isim */
        int new_value; /* and ya da or ladıktan sonraki yeni isimin değeri  */
}gate;

void number_of_line_in_file(FILE * fp2, int * temp);  /*calculate number ıf circuit file*/
void number_of_line_in_file1(FILE * fp2, int * inputs_line );/*calculate number ıf input file*/
void read_Input_file(FILE * fp1, int * inputt_name_value); /*read input file value*/
void Read_first_line(FILE *fp2,char ** add_input_name);   /* read first line of file */
void And_Or_func(FILE * fp2, gate ** , char ** ,int * inputt_name_value, int *,int,int *);  /* TO AND or OR GATE */
void NOT_Flipflop_func(FILE * fp2, gate ** , char **,int * inputt_name_value, int *,int,int *); /*to NOT and FLIPFLOP*/


int main() {

        FILE * fp1, * fp2;
        int count =-1, Sum_size,  * inputt_name_value, i=1, t = 4, inmp = 4, inputs_line = 1,q,temp;
        char ** add_input_name = NULL;

        fp1 = fopen("input.txt", "r+"); /* fp1 open input file */
        fp2 = fopen("circuit.txt", "r+");
        
        number_of_line_in_file(fp2, &count); /* to calculate number of gates */
        
        number_of_line_in_file1(fp1, &inputs_line); /* to calculate line of input  */
            
                 inputs_line--;
        inputt_name_value = (int * ) malloc(sizeof(int) * count);
        fseek(fp1, 0, SEEK_SET);        /*to go to the beginning of the file again */
        fseek(fp2, 0, SEEK_SET); /* to go to the beginning of the file again  */

        
        
        gate ** gates = (gate ** ) malloc(sizeof(gate * ) * count); /*memory allocation for gates */
        add_input_name = (char ** ) malloc(sizeof(char * ) * count); /* memory allocation for all gates and compare string  */
        Read_first_line(fp2,add_input_name);
        
            temp=inputs_line;
       
               read_Input_file(fp1, inputt_name_value);
      new:    for(i=1;  i <=count ;i++) {                       /* read to end of circuit file */
                         gates[i] = malloc(sizeof(gate));
                        fscanf(fp2, "%s", (gates)[i] -> gats); /* satırdaki gates in ismini dosyadan alıyor */  
                        if(strcmp(gates[i] -> gats, "AND")== 0 ||strcmp(gates[i] -> gats, "OR")== 0 )
                         And_Or_func(fp2, gates, add_input_name, inputt_name_value, & inmp,i,&t);

                         if(strcmp(gates[i] -> gats, "NOT")== 0 ||strcmp(gates[i] -> gats, "FLIPFLOP")== 0 )  /* they have one input so sent function one input  */
                         NOT_Flipflop_func(fp2, gates, add_input_name, inputt_name_value, & inmp,i,&t);
                         
                }
                printf("%d\n",inputt_name_value[t]);

              for(int a=1;a<count;a++){  /*ı emptied the memory to use it again */
                
                (gates)[a]=0;
                *(add_input_name)[a]=0;
                inputt_name_value[a]=0;
                }
               
 t = 4;                         /* reset  variable */
 inmp = 4;
inputs_line = 1;
fseek(fp2, 0, SEEK_SET);
read_Input_file(fp1, inputt_name_value);
Read_first_line(fp2,add_input_name);
temp--;
if(temp>0)
 goto new;

fclose(fp1);
fclose(fp2);
}

 

void Read_first_line(FILE *fp2,char ** add_input_name){
char  ch_input;

        ch_input = getc(fp2);
    while (ch_input != ' ') /* İNPUT stringini geçmek için  */
                ch_input = getc(fp2);

        for (int f = 1; f <= 4; f++) {
                /* ilk 4 input isimlerini almak için  */
                add_input_name[f] = malloc(sizeof(char));
                fscanf(fp2, "\n\n%s\n\n", (add_input_name)[f]);

        }
}

void And_Or_func(FILE * fp2, gate ** gates, char ** add_input_name,int * inputt_name_value, int * inmp,int i,int *t) {
        int  k,s,gate_name = 0;
      
                fscanf(fp2, "%s""%s""%s", (gates)[i] -> new_name, (gates)[i] -> name1, (gates)[i] -> name2);
                * inmp = * inmp + 1;
                add_input_name[ * inmp] = malloc(sizeof(char)); /*input _name yeni gates eklemek  için */
                strcpy(add_input_name[ * inmp], (gates)[i] -> new_name);
                
                for (k = 1; k <= *inmp; k++) {          /*after adding the gates names, I compare them from the press of the array*/
                        if (strcmp(gates[i] -> name1, add_input_name[k]) == 0) {

                                break;
                        }
                }
                for (s = 1; s <= *inmp; s++) {
                        if (strcmp(gates[i] -> name2, add_input_name[s]) == 0) {/*after adding the gates names, I compare them from the press of the array*/

                                break;
                        }
                }
                if (strcmp(gates[i] -> gats, "AND") == 0)
                gate_name = 1;

        if (strcmp(gates[i] -> gats, "OR") == 0)
                gate_name = 2;

                 if (gate_name == 1 && inputt_name_value[s] == 1 && inputt_name_value[k] == 1) {
                gates[i] -> new_value = 1;
                *t=*t+1;
                inputt_name_value[*t] = gates[i] -> new_value;
               
        } else if (gate_name == 1 && (inputt_name_value[s] == 0 || inputt_name_value[k] == 0)) {
                gates[i] -> new_value = 0;
                *t=*t+1;
                inputt_name_value[*t] = gates[i] -> new_value;
                 }
        if (gate_name == 2 && inputt_name_value[s] == 0 && inputt_name_value[k] == 0) {
                gates[i] -> new_value = 0;
                 *t=*t+1;
                inputt_name_value[*t] = gates[i] -> new_value;
        }
        if (gate_name == 2 && (inputt_name_value[s] != 0 || inputt_name_value[k] != 0)) {
                gates[i] -> new_value = 1;
                *t=*t+1;
                inputt_name_value[*t] = gates[i] -> new_value;
        }
        

}  

void NOT_Flipflop_func(FILE * fp2, gate ** gates, char ** add_input_name,int * inputt_name_value, int * inmp,int i,int *t){

                int k,s,gate_name;
                
               fscanf(fp2, "%s"
                        "%s", (gates)[i] -> new_name, (gates)[i] -> name1); /* read gates in file that FLIPFLOP or NOT */
                * inmp = * inmp + 1;
                add_input_name[ * inmp] = malloc(sizeof(char));
                strcpy(add_input_name[ * inmp], (gates)[i] -> new_name);
 
                for (k = 1; k <= *inmp; k++) {
                        if (strcmp(gates[i] -> name1, add_input_name[k]) == 0) {

                                break;
                        }
                }
 
                
        if (strcmp(gates[i] -> gats, "NOT") == 0)
                gate_name = 3;

        if (strcmp(gates[i] -> gats, "FLIPFLOP") == 0)
                gate_name = 4;

         
       
        if (gate_name == 3 && inputt_name_value[k] == 0) {              /* to check if gates is NOT then write the result input name value of array */
                gates[i] -> new_value = 1;
                 *t=*t+1;
                inputt_name_value[*t] = gates[i] -> new_value;
        } else if (gate_name == 3 && inputt_name_value[k] == 1) {
                gates[i] -> new_value = 0;
                 *t=*t+1;
                inputt_name_value[*t] = gates[i] -> new_value;
        }

        if (gate_name == 4 && inputt_name_value[k] == 0) {  /* to check if gates is FLIPFLOP then write the result input name value of array */
                gates[i] -> new_value = 0;
                *t=*t+1;
                inputt_name_value[*t] = gates[i] -> new_value;
                    }
       else if (gate_name == 4 && inputt_name_value[k] == 1) {  
                gates[i] -> new_value = 1;
                *t=*t+1;
                inputt_name_value[*t] = gates[i] -> new_value;
               
        }

}

void read_Input_file(FILE * fp1, int * inputt_name_value) {  /* read first line of input file and keep array */
        int t = 1;
        while (t <= 4) {
                fscanf(fp1, "%d", & inputt_name_value[t]);
                t=t+1;

        }

}

void number_of_line_in_file(FILE * fp2, int * temp) {           /* calculate number of line in circuit file */
        char ch;
        while (ch != EOF) {
                ch = getc(fp2);
                if (ch == '\n')
                        *temp = * temp + 1;
        }

}




void number_of_line_in_file1(FILE * fp1, int * inputs_line) {  /* calculate number of line in input file */
        char ch;
                ch = getc(fp1);
        while (ch != EOF) {
                ch = getc(fp1);
                if (ch == '\n')
                        *inputs_line = * inputs_line + 1;
        }

}





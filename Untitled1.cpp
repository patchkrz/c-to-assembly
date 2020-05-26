/* Efe Kiraz 2016502071 Microproccessor Term Homework
 * Last modification 26/05/2020
 *
 * This code reads previosly user defined .c file. Then it translates 
 * the .c syntax code into .asm syntax. 
 *
 */


#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void search_block(FILE* );
void operator_type(const char* );
void add_assembly(void);
void sub_assembly(void);
void mult_assembly(void);

int main (){
	
   // reads the file name and stores in pointer   
   char *cfile_name = (char*)malloc(sizeof(char) * 255);
   printf("Write down the file name with its extension\n");
   scanf("%[^\n]s",cfile_name);        
   
   
   //opens the user defined file
   FILE *fp = NULL;	
   if(fp=fopen(cfile_name,"r")){
   	   
       search_block(fp);
      
   }
   
   else
      printf("dosya acilamadi");
    
    
   free(cfile_name);
   getch();
   return 0;
	
}

/*
 * Function "search_block" takes file pointer then by using the  
 * the pointer, it detects the code blocks nested inside the function, 
 * which is previously written inside the file.
 */
void search_block(FILE* fp){
   
   char line[100] = {0};
   
   const char end_of_block[1] = {'}'};
   
   const char* func = NULL;
   
   while(fgets ( line, sizeof ( line), fp)){
   	  
   	  if((strchr((const char*)(&line), '{') == NULL)){
		 
   	     func = strtok((char*)(&line), &end_of_block[0]); 
   	     operator_type(func);
		 // "func" is the remaining part of the block after removing curly brackets.
      }
      
   }
   return ;
}

/* 
 * "operator_type" takes the part which contains numbers and symbol of operation as an input.
 * By detecting the symbol of operation, function call is done to write assembly equivalent.
 *
 */
void operator_type(const char* operation){
   
   char* temp = NULL;
   
   temp = strchr (operation, '+');
   if (temp!=NULL)
      add_assembly();
   
   temp = strchr (operation, '-');
   if (temp!=NULL)
      sub_assembly();
   
   temp = strchr (operation, '*');
   if (temp!=NULL)
      mult_assembly();
   
   //printf("%s",operation);
   //printf("%s\n\n",temp);
   return ;
}

void add_assembly(void){
	printf("sum:\n\tSUB.W   #4, R1\n\tMOV.W   R12, 2(R1)\n\tMOV.W   R13, @R1\n\tMOV.W   2(R1), R12\n\tADD.W   @R1, R12\n\tADD.W   #4, R1\n\tRET\n\n\n");
	return ;
}


void sub_assembly(void){
	printf("sub:\n\tSUB.W   #4, R1\n\tMOV.W   R12, 2(R1)\n\tMOV.W   R13, @R1\n\tMOV.W   2(R1), R12\n\tSUB.W   @R1, R12\n\tADD.W   #4, R1\n\tRET\n\n\n");
	return ;
}

void mult_assembly(void){
	printf("mult:\n\tSUB.W   #4, R1\n\tMOV.W   R12, 2(R1)\n\tMOV.W   R13, @R1\n\tMOV.W   @R1, R13\n\tMOV.W   2(R1), R12\n\tCALL    #__mspabi_mpyi\n\tADD.W   #4, R1\n\tRET\n\n\n");
	return ;
}






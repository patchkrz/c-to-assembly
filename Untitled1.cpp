/* 
 *Efe Kiraz 2016502071 Microproccessor Term Homework
 * Last modification 26/05/2020
 *
 * This code reads previosly user defined .c file. Then it translates 
 * the .c syntax code into .asm syntax. 
 *
 */

// header files

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


// function prototypes

void search_block(FILE* );
void operator_type(const char* );
void sum_assembly(FILE*);
void sub_assembly(FILE*);
void mult_assembly(FILE*);



extern char cfile_name[100] = {0};   //  In order to call .c file name from other functions

int main (){
	
   printf("Write down the file name with its extension\n");
   scanf("%[^\n]s",cfile_name);        
   
   
   FILE *fp = NULL;  //opens the user defined file
   
   if(fp=fopen(cfile_name,"r")){
       search_block(fp);
   }
   
   else
      printf(".c file cannot be opened.");
    
   getch();
   
   return 0;
	
}

/*
 *
 * Function "search_block" takes file pointer then by using the  
 * the pointer, it detects the code blocks nested inside the function, 
 * which is previously written inside the file.
 *
 */
void search_block(FILE* fp){
   
   char line[100] = {0};
   
   const char end_of_block[2] = {'}','\n'};
   
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
 *
 * "operator_type" takes the part which contains numbers and symbol of operation as an input.
 * By detecting the symbol of operation, function call is done to write assembly equivalent.
 *
 */
void operator_type(const char* operation){
   FILE* fp_assembly_output = NULL; 
   
   char* temp = NULL;
   
   temp = strchr (operation, '+');
   if (temp!=NULL)
      sum_assembly(fp_assembly_output);
   
   temp = strchr (operation, '-');
   if (temp!=NULL)
      sub_assembly(fp_assembly_output);
   
   temp = strchr (operation, '*');
   if (temp!=NULL)
      mult_assembly(fp_assembly_output);
   
   
   return ;
}


void sum_assembly(FILE* fp_assembly_output){
   	
   const char new_extension[5] = {".asm"};
   
   char token[100] = {0};   
   
   for(int i=0; cfile_name[i] != '.'; i++){  
      
      token[i] = cfile_name[i];
      
   }// used to delete .c extension
   
   char* output_file_name = strcat(token, new_extension); // used to create a file name concateneted with .asm 
   
   fp_assembly_output = fopen(output_file_name, "w");
   
   if(fp_assembly_output==NULL){
      printf("Assembly file cannot be created.");
      exit(1);
   }
   
   else{
      printf("Assembly file is being created.");
	  fprintf(fp_assembly_output,"sum:\n\tSUB.W   #4, R1\n\tMOV.W   R12, 2(R1)\n\tMOV.W   R13, @R1\n\tMOV.W   2(R1), R12\n\tADD.W   @R1, R12\n\tADD.W   #4, R1\n\tRET\n\n\n");
   }
   
   fclose(fp_assembly_output);
   
   return ;
}


void sub_assembly(FILE* fp_assembly_output){
	
   const char new_extension[5] = {".asm"};
   
   char token[100] = {0};
   
   for(int i=0; cfile_name[i] != '.'; i++){  
      
      token[i] = cfile_name[i];
      
   }// used to delete .c extension
   
   char* output_file_name = strcat(token, new_extension); // used to create a file name concateneted with .asm 
   
   fp_assembly_output = fopen(output_file_name, "w"); 
   
   if(fp_assembly_output==NULL){
      printf("Assembly file cannot be created.");
      exit(1);
   }
   
   else{
      printf("Assembly file is being created.");
      fprintf(fp_assembly_output,"sub:\n\tSUB.W   #4, R1\n\tMOV.W   R12, 2(R1)\n\tMOV.W   R13, @R1\n\tMOV.W   2(R1), R12\n\tSUB.W   @R1, R12\n\tADD.W   #4, R1\n\tRET\n\n\n");
   }
   
   fclose(fp_assembly_output);
   
   return ;
}


void mult_assembly(FILE* fp_assembly_output){
   
   const char new_extension[5] = {".asm"};
   
   char token[100] = {0};
   
   for(int i=0; cfile_name[i] != '.'; i++){  
      
      token[i] = cfile_name[i];
      
   } // used to delete .c extension
   
   char* output_file_name = strcat(token, new_extension); // used to create a file name concateneted with .asm 
   
   fp_assembly_output = fopen(output_file_name, "w"); 
   
   if(fp_assembly_output==NULL){
      printf("Assembly file cannot be created.");
      exit(1);
   }
   
   else{
      printf("Assembly file is being created.");
      fprintf(fp_assembly_output,"mult:\n\tSUB.W   #4, R1\n\tMOV.W   R12, 2(R1)\n\tMOV.W   R13, @R1\n\tMOV.W   @R1, R13\n\tMOV.W   2(R1), R12\n\tCALL    #__mspabi_mpyi\n\tADD.W   #4, R1\n\tRET\n\n\n");
   }
   
   fclose(fp_assembly_output);
   
   return ;
}

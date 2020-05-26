#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void search_func(FILE* );

int main (){
   // reads the file name and stores in pointer
   
   char *cfile_name = (char*)malloc(sizeof(char) * 255);
   printf("Write down the file name with its extension\n");
   scanf("%[^\n]s",cfile_name);        
   
   //opens the user defined file
   FILE *fp = NULL;	
   if(fp=fopen(cfile_name,"r")){
   	   
       search_func(fp);
      
   }
   
   else
      printf("dosya acilamadi");
    
    
   free(cfile_name);
   getch();
   return 0;
	
}


void search_func(FILE* fp){
   
   char line[100] = {0};
   
   const char end_of_block[1] = {'}'};
   
   const char* func = NULL;
   
   while(fgets ( line, sizeof ( line), fp)){
   	  
   	  if((strchr((const char*)(&line), '{') == NULL))
   	     func = strtok((char*)(&line), &end_of_block[0]); 
   	    printf("%s\n",func);
      
      
   }
   //printf("%d",i);
    
      
   
   
   
   /*for(int i = 0 ; ; i++ ){
      
      
      
      if(*(temp+i) == '{'){
         
		 *func = *(temp+i);
		 	
	  }  
         
         *(func+i) = *(temp+i);
          printf("%s\n",func);
      
      if(*(temp+i) == '}'){
	  
         break;
    }
   }
   */
   
   
   return ;
}




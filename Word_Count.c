#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *file;
int main()
{
   int character=0, word=0,sentence=0;
   char filename[1000];
   char c;
   char wordtag=1;
   printf("Please enter the file name of the target text (Note: full path should be included)£º\n");
   scanf("%s",filename);
   if((file=fopen(filename,"r"))==NULL)
   { 
    printf("Target file does not exist£¡\n");
    exit(0);
   }
   while((c=fgetc(file))!=EOF)
    {
       if(c>=' '&& c<='~')
          {    
           character++;
          }
       if(c>=91 && c<=96 ||c<=40 || c>=123)
          {      
           wordtag=0;
          }
       else if(wordtag==0)
          { 
           wordtag=1;
           word++;
          }

       if(c=='!' && c==',' &&c =='.'&& c=='?')
          {
           sentence++;
          }
       putchar(c);
     }
    fclose(file); 
    printf("\n\nThe number of characters in the text£º%d\n",character);
    printf("\nThe number of words in the text£º%d\n",word);
    printf("\nThe number of sentences in the text£º%d\n",sentence);
}

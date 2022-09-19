#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *textfile;
   char *text;
   long numbytes;

   textfile = fopen("./pali_vocab.txt", "r");
   if(textfile == NULL)
        return 1;

    fseek(textfile, 0L, SEEK_END);
    numbytes = ftell(textfile);
    fseek(textfile, 0L, SEEK_SET);

    text = (char*)calloc(numbytes, sizeof(char));
    if(text == NULL)
        return 1;
    
    fread(text, sizeof(char), numbytes, textfile);
    fclose(textfile);

    printf("%s", text);
   return 0;
}
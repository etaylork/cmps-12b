#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void extract_chars(char* s, char* a, char* d, char* p, char* w);
void freeMemory(char* arr);

int main(int argc, char* argv[]){
FILE* in;
FILE* out;
char* a;

if(argc != 3){
    printf("ERROR: charType.c <input> <output>\n");
    exit(EXIT_FAILURE);
}

in = fopen(argv[1], "r");
if(in == NULL){
    printf("ERROR: unable to read from %s file\n", argv[1]);
    exit(EXIT_FAILURE);
}

out = fopen(argv[2], "w");
if(out == NULL){
    printf("ERROR: unable to write to %s file\n", argv[2]);
    exit(EXIT_FAILURE);
}

//allocate arrays
char* line = calloc(MAX_LENGTH, sizeof(char));
assert(line != NULL);
char* A = calloc(MAX_LENGTH, sizeof(char));
assert(A != NULL);
char* D = calloc(MAX_LENGTH, sizeof(char));
assert(D != NULL);
char* P = calloc(MAX_LENGTH, sizeof(char));
assert(P != NULL);
char* W = calloc(MAX_LENGTH, sizeof(char));
assert(W != NULL);

int counter = 0;

while( fgets(line , MAX_LENGTH, in) != NULL ){
    
    extract_chars(line, A, D, P, W);
    fprintf(out, "\nline %d contains:\n", ++counter);
    fprintf(out, "%ld alphabetic characters: %s\n", (strlen(A)), A);
    fprintf(out, "%ld numeric characters: %s\n", (strlen(D)), D);
    fprintf(out, "%ld punctuation characters: %s\n", (strlen(P)), P);
    fprintf(out, "%ld whitespace characters:\n", (strlen(W)));

 }


freeMemory(line);
freeMemory(A);
freeMemory(D);
freeMemory(P);
freeMemory(W);

//close open files
fclose(in);
fclose(out);
return 0;

}

void freeMemory(char* arr) {
    free(arr);
    arr = NULL;
}

void extract_chars(char* s, char* a, char* d, char* p, char* w){
    int i = 0, j = 0, x = 0, y = 0, z = 0;
    while(s[i] != '\0'){
        if(isalpha(s[i])) a[j++] = s[i];
        else if(isdigit(s[i])) d[x++] = s[i];
        else if(ispunct(s[i])) p[y++] = s[i];
        else if(isspace(s[i])) w[z++] = s[i];
        i++;
    }

    a[j] = '\0';
    d[x] = '\0';
    p[y] = '\0';
    w[z] = '\0';
}
#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZ 1000
#define MAX_LINES_IN_PAGE 20
void printfile(const char* file){
    FILE* fin;
    int page = 1;
    int lineo = 0;
    char buf[BUFFSIZ];

    fin = fopen(file, "r");
    if (fin == NULL){
        fprintf(stderr, "cannot open files.");
        return;
    }
    printf("\n==============New File====================\n");
    printf("Title: %s\n", file);
    while(fgets(buf, BUFFSIZ, fin)){
        if((lineo % MAX_LINES_IN_PAGE) == 0){
            printf("Pages: %d\n", page);
            ++page;
        }
        printf("%s",buf);
        ++lineo;
    }
}

int main(int argc, const char* argv[]){
    if(argc == 1){
        fprintf(stderr, "no files specified.");
        return 1;
    }
    int i = argc -1;
    while(i >0){
        printfile(argv[i]);
        i--;
    }
    return 0;
}


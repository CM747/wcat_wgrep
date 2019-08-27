#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    if(argc==1){
        return 0;
    }
    FILE* fp;
    char* buffer = (char*) malloc(50*sizeof(char));
    for(int i=1; i<argc; i++){
        fp = fopen(argv[i], "r");
        if(fp==NULL){
            printf("wcat: cannot open file\n");
            return 1;
        }
        printf("---------------Filename: %s----------------------------------------\n", argv[i]);
        while(fgets(buffer, 50, fp)!=NULL){
            printf("%s",buffer);
        }
        printf("\n\n");
        fclose(fp);
    }
    return 0;
}
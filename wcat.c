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
        while(fgets(buffer, 50, fp)!=NULL){
            printf("%s",buffer);
        }
        fclose(fp);
    }
    return 0;
}
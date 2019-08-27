#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    if(argc==1){
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }
    FILE* fp;
    char* searchitem = argv[1];
    char* buffer = NULL;
    size_t size = 0;
    if(argc==2){
        while(getline(&buffer, &size, stdin)!=-1){
            if(strstr(buffer, searchitem)!=NULL){
                printf("%s", buffer);
            }
        }
    }
    for(int i=2; i<argc; i++){
        fp = fopen(argv[i],"r");
        if(fp==NULL){
            printf("wgrep: cannot open file\n");
            return 1;
        }
        while(getline(&buffer, &size, fp)!=-1){
            if(strstr(buffer, searchitem)!=NULL){
                printf("%s", buffer);
            }
        }
        fclose(fp);
    }
    return 0;
}
// includeasfda

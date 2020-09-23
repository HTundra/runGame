#include <stdio.h>
#include <string.h>

int main(void){
    char kent[10] = "Kent";
    printf("%d", (strcmp("Kent", kent) && strcmp("Kent", kent)));
}
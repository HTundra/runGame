#include <stdio.h>
#include <string.h>

typedef struct credentials{
    char usrName[20];
    char passWord[64];
} credentials;

void consoleSim(void);
void login(void);
int validateCredentials(credentials A);
void initScrn(void);
void clrScrn(void);
void echoOff(void);
void boot(credentials usr);

int main(void){
    consoleSim();
    getchar();
}

void consoleSim(void){
    initScrn();
    printf("SigmaTEC Operating System\nRobCO Industries\nAll Rights Reserved 2077.\n\nPress Enter to login.\n");
    getchar();
    login();
}

void login(){
    credentials loginCred = {"********************", "****************************************************************************************************************************"};
    printf("Username: ");
    fgets(loginCred.usrName,20,stdin);
    printf("Password: ");
    fgets(loginCred.passWord,64,stdin);
    if(validateCredentials(loginCred) == 1){
        boot(loginCred);
    }
    else{
        printf("\nInvalid Credentials! Please try again.\n");
        login();
    }
    
}

int validateCredentials(credentials A){
    credentials secure = {"Tundra\n","1234567\n"};
    int disc=0;
    int ctr=0;
    printf("Validating");
    for(ctr=0; ctr!=3; ctr++){
        system("timeout /t 1 >nul");
        printf(".");
    }
    if( (strcmp(secure.passWord, A.passWord) == 0 && strcmp(secure.usrName, A.usrName) == 0) ){
        disc=1;
    }
    return disc;
}
void boot(credentials A){
    initScrn();
    printf("Welcome, ");
    fputs(A.usrName, stdout);
}

void initScrn(void){
    clrScrn();
    echoOff();
}

void clrScrn(void){
    system("cls");
}

void echoOff(void){
    system("echo off");
}
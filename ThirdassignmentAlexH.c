#include "stdio.h"
#include "string.h"

int main(){

    char fName[5];       //alex
    char lName[10];     //holloway
    char Greets[8]={'W','e','l','c','o','m','e'};

    int alNumber =0;

    int fNumb =0;
    int sNumb =0;

    printf("Enter the number of alphabet for your first name : ");
    scanf(" %d",&fNumb);


    printf("Please enter  %d alphabet for your first name : ",fNumb);

    for(int x=0 ; x<fNumb ; x++){
            scanf(" %c", &fName[x]);

    }
    printf("Your first name is : %s\n",fName);

    printf("Enter the number of alphabet for your last name : ");
    scanf(" %d",&sNumb);

    printf("Please enter %d alphabet for your last name : ",sNumb);

    for(int y=0 ; y<sNumb ; y++){
        scanf(" %c", &lName[y]);
    }
    printf("Your last name is : %s\n",lName);


    strcat(fName,lName);

    printf("Your full name is : %s\n",fName);

    printf("%s %s!\n",Greets,fName);


    alNumber = fNumb+sNumb;

    printf("The number of alphabet on yor full name is : %d\n",alNumber);


    char*ptr;
    ptr = &fName[1];

    printf("memory address of alphabet(l) in your full name is : %d\n",ptr);

    printf("The 2nd alphabet on your name is : %c",*ptr);





}

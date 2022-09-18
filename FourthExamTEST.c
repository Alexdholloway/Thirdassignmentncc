#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
#define HOLD_SIZE 1000

int main(){

    int number;
    int uid;
    char username[20];
    int password;
    int amount;
    int age;
    char address[30];

    FILE *fptr;
    fptr =fopen("FourthExamTest.txt" , "a");
    if(fptr == NULL){
        printf("File cannot open!");
        exit(1);
    }
    puts("Press 1 to insert data , Press 2 to find data , Press 3 to update : ");
    scanf("%d",&number);

    if(number==1){

        puts("Enter user id,user name,password,amount,age,location");
        puts("Enter  CTRL+Z to end input");
        printf(">:");


        scanf("%d %s %d %d %d %s",&uid ,username ,&password ,&amount ,&age ,address);

        while (! feof(stdin)){
            fprintf(fptr , "%d %5s %5d %5d %5d %5s %5c",uid ,username ,password ,amount ,age ,address , '\n');
            printf(">:");
            scanf("%d %s %d %d %d %s",&uid ,username ,&password ,&amount ,&age ,address);


        }
        fclose(fptr);
}
    if(number==2){

        FILE*fptr = fopen("FourthExamTest.txt" , "r");
        if(fptr == NULL){
            printf("data not found in file!");
            exit(2);
        }
        char uname[20];
        char info[60];
        char userid[20];
        char p_info;
        printf("Please enter the user name to find Info : ");
        scanf("%s",uname);
        do{

        p_info = fscanf(fptr,"%s%s",userid,info);
        if(strcmp(info,uname) ==0){

        if(fgets(info,60,fptr)!= NULL){
                printf("user id,password,amount,age,location of %s is:> %s%s",uname,userid,info);


        }}

        }while(p_info != EOF);



        fclose(fptr);
}

 if(number == 3){


        FILE * fptr;
        FILE * Tempf;

        char holding[HOLD_SIZE];
        char newinfo[HOLD_SIZE];
        int line;
        int count;


        printf("Enter the line number of the info you want to update :  ");
        scanf("%d",&line);

        fflush(stdin);

        printf("Please Enter the info u want to update line %d with: ",line);
        fgets(newinfo,HOLD_SIZE,stdin);

        char path[100]="FourthExamTest.txt";

        fptr = fopen(path,"r");
        Tempf = fopen("FourthExam.txt","w");

        if(fptr == NULL || Tempf == NULL){

            printf("File cannot be open.");
            printf("Please check file");
            exit(3);

        }
        count = 0;
        while((fgets(holding,HOLD_SIZE,fptr)) != NULL){

            count++;

            if(count == line )
                fputs(newinfo, Tempf);
            else
                fputs(holding, Tempf);
        }

        fclose(fptr);
        fclose(Tempf);

        remove(path);

        rename("FourthExam.txt", path);

        printf("Updated line %d with new Info %s",line,newinfo);





 }


        return 0;



}


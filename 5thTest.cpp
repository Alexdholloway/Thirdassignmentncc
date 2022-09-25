#include "iostream"
#include "fstream"
#include "cstring"
#define HOLD_SIZE 100
using namespace std;

class PersonInfo{
public:
    int user_id = 0;
    string user_name;
    int passcode = 0;
    int amount = 0;
    int age = 0;
    string address;

    void Info() {
        cout << "Enter Data for the person User ID,User Name,Password,Amount,Age,Address :" << endl;
        cout << ">:";
        cin >> user_id >> user_name >> passcode >> amount >> age >> address;

    }

};

int main() {
    PersonInfo person1;
    PersonInfo person2;
    PersonInfo person3;
    PersonInfo person4;
    PersonInfo person5;
    PersonInfo person6;
    PersonInfo person7;
    PersonInfo person8;
    PersonInfo person9;
    PersonInfo person10;
    int number;
    fstream f;
    ofstream fout;
    ifstream fin;
    fin.open("5thTest.txt");
    fout.open("5thTest.txt", ios::app);

    if (fin.is_open())
        cout
                << "Press 1 to insert data for 10 People <or> Press 2 to Find data of a person <or> Press 3 to update data of a person :"
                << endl;
    cout << ">:";
    cin >> number;
    if (number == 1) {
        person1.Info();
        fout << person1.user_id << ' ' << person1.user_name << ' ' << person1.passcode << ' ' << person1.amount
             << ' ' << person1.age << ' ' << person1.address << endl;
        person2.Info();
        fout << person2.user_id << ' ' << person2.user_name << ' ' << person2.passcode << ' ' << person2.amount
             << ' ' << person2.age << ' ' << person2.address << endl;
        person3.Info();
        fout << person3.user_id << ' ' << person3.user_name << ' ' << person3.passcode << ' ' << person3.amount
             << ' ' << person3.age << ' ' << person3.address << endl;
        person4.Info();
        fout << person4.user_id << ' ' << person4.user_name << ' ' << person4.passcode << ' ' << person4.amount
             << ' ' << person4.age << ' ' << person4.address << endl;
        person5.Info();
        fout << person5.user_id << ' ' << person5.user_name << ' ' << person5.passcode << ' ' << person5.amount
             << ' ' << person5.age << ' ' << person5.address << endl;
        person6.Info();
        fout << person6.user_id << ' ' << person6.user_name << ' ' << person6.passcode << ' ' << person6.amount
             << ' ' << person6.age << ' ' << person6.address << endl;
        person7.Info();
        fout << person7.user_id << ' ' << person7.user_name << ' ' << person7.passcode << ' ' << person7.amount
             << ' ' << person7.age << ' ' << person7.address << endl;
        person8.Info();
        fout << person8.user_id << ' ' << person8.user_name << ' ' << person8.passcode << ' ' << person8.amount
             << ' ' << person8.age << ' ' << person8.address << endl;
        person9.Info();
        fout << person9.user_id << ' ' << person9.user_name << ' ' << person9.passcode << ' ' << person9.amount
             << ' ' << person9.age << ' ' << person9.address << endl;
        person10.Info();
        fout << person10.user_id << ' ' << person10.user_name << ' ' << person10.passcode << ' ' << person10.amount
             << ' ' << person10.age << ' ' << person10.address << endl;
        fin.close();
        fout.close();
        exit(1);
    }
    if (number == 2){
        FILE*fptr = fopen("5thTest.txt" , "r");
        if(fptr == nullptr){
            cout <<"data not found in file!";
            exit(2);
        }
        char uname[20];
        char info[60];
        char userid[20];
        char p_info;
        cout <<"Please enter the user name to find Info : ";
        cin >> uname;
        do{

            p_info = fscanf(fptr,"%s%s",userid,info);
            if(strcmp(info,uname) ==0){

                if(fgets(info,60,fptr)!= nullptr){
                    cout<<"user id,password,amount,age,location of "<<uname<<" is:>"<<userid<<info;


                }}

        }while(p_info != EOF);



        fclose(fptr);
    }
    if (number == 3) {
        FILE * fptr;
        FILE * Tempf;

        char holding[HOLD_SIZE];
        char newinfo[HOLD_SIZE];
        int line;
        int count;


        cout<<"Enter the line number of the info you want to update :  ";
        cin>>line;

        fflush(stdin);

        cout<<"Please Enter the info u want to update line "<<line<< "with:";
        fgets(newinfo,HOLD_SIZE,stdin);

        char path[100]="5thTest.txt";

        fptr = fopen(path,"r");
        Tempf = fopen("5thTestTemp.txt","w");

        if(fptr == nullptr || Tempf == nullptr){

            cout<<"File cannot be open.";
            cout<<"Please check file";
            exit(3);

        }
        count = 0;
        while((fgets(holding,HOLD_SIZE,fptr)) != nullptr){

            count++;

            if(count == line )
                fputs(newinfo, Tempf);
            else
                fputs(holding, Tempf);
        }

        fclose(fptr);
        fclose(Tempf);

        remove(path);

        rename("5thTest.txt", path);

        cout<<"Updated line "<<line<<" with new Info "<<newinfo;





    }
    return 0;
}
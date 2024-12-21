#include <iostream>
#include <windows.h>// for system command 
#include <conio.h>// for getch()
#include <fstream>
#include<unistd.h>// sleep function
#include <stdio.h>  
using namespace std;
class bank {
    private:
    double balance ;
    string id,name,fname,address,pass,mob_no,pin;

    public:
       void menu();
       void bank_managment ();
       void new_user();
       void deposit();
       void withdraw();
       void search();
       void edit();
       void del();
       void showall();
};
 
void bank::menu(){
    p:
    system("cls");
    int choise;
    char ch1;
    char ch2;
    string email;

    string pass;
    cout<<"\n\n\t\tControl panel";
    cout<<"\n\n 1. Bank management" ;
    cout<<"\n 2. Exit ";
    cout<<"\n\n Enter your choise : ";
    cin>>choise;
    switch(choise){
        case 1:
            cout<<"\nplease wait while redirecting you to bank managment system ";
            for (int i=0;i<5;i++){
                cout<<".";
                sleep(1);
            }
            bank_managment();
            break;

        case 2:
            exit(0);
            break;
        default:
        cout<<"\ninvalid value .... \t please try again "<<endl; 
    }
    cout<<"\n\tpress any key to continue \n";
    getch();
    goto p;
}

void bank::bank_managment(){
    p:    
system("cls");
int choise;
cout<<"\n\t\t Bank Management ";
cout<<"\n 1.  New user ";
cout<<"\n 2.  deposite  ";
cout<<"\n 3.  withdraw  ";
cout<<"\n 4.  search user record  ";
cout<<"\n 5.  Edit user record  ";
cout<<"\n 6.  Delete user record  ";
cout<<"\n 7.  Show all records   ";
cout<<"\n 8. Go back to main menu ";
cout<<"\n\n\t\t\t Enter Your choise : ";
cin >> choise ;
switch (choise){
    case 1:
        new_user();
        break;
    case 2:
        deposit();
        break;
    case 3:
        withdraw();
        break;
    case 4:
        search();
        break;
    case 5:
        edit();
        break;
    case 6:
        del();
        break;
    case 7:
        showall();
        break;
    case 8:
        cout<<"\tplease wait while redirecting you to main menu";
        for (int i=0;i<5;i++){
            cout<<".";
            sleep(1);
        }
        menu();
        break;
    default :
        cout<<"\n\n Invalid value ... please try Again ";  
}
cout<<"\n\t press any any key to continue \n";
getch();
goto p;
}
void bank :: new_user(){
    
    system("cls");
    fstream file ;
    double b;
    string i,n,f,a,pass,ph,p;
    cout<<"\n\n\t\t Add New User";
    cout<<"\n\t User id : ";
    cin>>id;
    cout<<"\n\t Name : ";
    cin.ignore();
    getline(cin,name);
    cout<<"\n\t Father name : ";
    getline(cin,fname);
    cout<<"\n\t Address : ";
    getline(cin,address);
    cout<<"\n\t password : ";
    cin>>pass;
    cout<<"\n\t pin : ";
    cin>>pin;
    cout<<"\n\t Phone no. : ";
    cin>>mob_no;
    cout<<"\n\t current balance  : ";
    cin>>balance;
    cin.clear();
    file.open("bank.txt",ios::in);
    if (!file){
       file.open("bank.txt",ios::app|ios::in);
       file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<mob_no<<" "<<balance<<" "<<"\n";
       file.close();
    }
    else{
       
        while( file>>i>>n>>f>>a>>p>>pass>>ph>>b){
            if (i==id){
                cout<<"\n\tUser id" <<id<<" Already exist";
                getch();
            }
        }
        file.close();
        file.open("bank.txt",ios::app|ios::in);
        file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<mob_no<<" "<<balance<<"\n";
        file.close();
    }
    cout<<"\n\t wait while your account is creating ";
    for (int i = 0; i<5;i++){
        cout<<".";
        sleep(1);
    }
    cout<< endl<<"\n\t\t" <<name <<" Account is successfully created" ;
    cout<<"\n\t\t Thank you for choosing us ";
}

void bank::deposit(){
    string tempid;
    float amount;
    fstream file,newfile;
    int found=0;
    system("cls");
    cout<<"\n\n\t\t DEPOSITE AMOUNT OPTION ";
    file.open("bank.txt",ios::in);
    if (!file){
        cout<<"\n\nNo data exist for this user ";
    }
    else{
    cout<<"\nEnter your user id :";
    cin>>tempid;
    newfile.open("bank1.txt",ios::app|ios::out);
    file>>id>>name>>fname>>address>>pin>>pass>>mob_no>>balance;
    }
    while(!file.eof()){
        if (id==tempid){
            cout<<"\nEnter Amount for Deposite : ";
            cin>>amount; 
            balance+=amount;
            newfile<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<mob_no<<" "<<balance<<" "<<"\n";
            found++;
            cout<<"\n\n\t......successfully Rs. " <<amount<<" deposited .... ";
            cout<<"\n\n Balance after deposit :"<<balance;

        }
        else{
            newfile<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<mob_no<<" "<<balance<<" "<<"\n";
        }
        file>>id>>name>>fname>>address>>pin>>pass>>mob_no>>balance;
    }
    if (found==0){
        cout<<"\n\n\tid not found .....";
    }
    file.close();
    newfile.close();
    remove("bank.txt");
    rename("bank1.txt","bank.txt");
    }


void bank::withdraw(){
    string tempid;
    float amount;
    fstream file,newfile;
    int found=0;
    system("cls");
    cout<<"\n\n\t\t WITHDRAW AMOUNT OPTION ";
    file.open("bank.txt",ios::in);
    if (!file){
        cout<<"\nNo data exist for this user ";
    }
    else{
    cout<<"\n Enter your user id :";
    cin>>tempid;
    newfile.open("bank1.txt",ios::app|ios::out);
    file>>id>>name>>fname>>address>>pin>>pass>>mob_no>>balance;
    while(!file.eof()){
        if (id==tempid){
            cout<<"\n\nEnter Amount for withdraw : ";
            cin>>amount; 
            if ( amount<=balance){
                 balance-=amount;
                 newfile<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<mob_no<<" "<<balance<<" "<<"\n";
                 cout<<"\n\n\t successfully Rs." <<amount<<" withdrawn .... ";
                 cout<<"\n\n\t Amount after withdraw :"<<balance ;
            }
            else{
                cout<<"\n\n\t Insufficient balance ";
                newfile<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<mob_no<<" "<<balance<<" "<<"\n";
            }
            found++;
        }
        else{
            newfile<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<mob_no<<" "<<balance<<" "<<"\n";
        }
        file>>id>>name>>fname>>address>>pin>>pass>>mob_no>>balance;
    }
    file.close();
    newfile.close();
    remove("bank.txt");
    rename("bank1.txt","bank.txt");
    }
}

void bank::search(){
    system("cls");
    string t_id,t_p;
    int found=0;
    fstream file;
    cout<<"\n\n\t\tSearch User Record ";
    file.open("bank.txt",ios::in);
    if (!file){
        cout<<"\n\n NO DATA FOUND ";
    }
    else{
        cout<<"\n\nEnter user id:";
        cin>>t_id;
        cout<<"\nEnter pin or password :";
        cin>>t_p;
        file>>id>>name>>fname>>address>>pin>>pass>>mob_no>>balance;
        while (!file.eof()){
            if (id==t_id && (t_p==pass || t_p==pin)){
                system("cls");
                cout<<"\n\n\t\tSearch User Record";
                cout<<"\n\nUser Id : "<<id<<"\nName : "<<name<<"\nFather name : "<<fname<<"\nAddress : "<<address<<"\nphone number : "<<mob_no<<"\nCurrent balance : "<<balance;
                cout<<"\n\nPin : "<<id<<"\nPassword : "<<pass;
                found++;
            }
                file>>id>>name>>fname>>address>>pin>>pass>>mob_no>>balance;
        }
        file.close();
        if (found==0){
                cout<<" User Record Does Not Match With Bank Record ";
        }
    }
}
 void bank:: edit(){
    system("cls");
    string n,f,a,p,ph,pin;
    string t_id,t_p;
    int found=0;
    fstream file,file1;
    cout<<"\n\n\t\tEdit User Record ";
    file.open("bank.txt",ios::in);
    if (!file){
        cout<<"\n\n ....... NO DATA EXIST ........ ";
    }
    else{
        cout<<"\n\nEnter user id:";
        cin>>t_id;
        cout<<"\nEnter pin or password :";
        cin>>t_p;
        file1.open("bank1.txt",ios::out);
        file>>id>>name>>fname>>address>>pin>>pass>>mob_no>>balance;
        while (!file.eof()){
            if (id==t_id && (t_p==pass || t_p==pin)){
                system("cls");
                cout<<"\n\n\t\tEdit User Record";
                cout<<"\n\tNew Name : ";
                cin.ignore();
                getline(cin,n);
                cout<<"\n\t Father name : ";
                getline(cin,f);
                cout<<"\n\tNew Address : ";
                getline(cin,a);
                cout<<"\n\tNew password : ";
                cin>>p;
                cout<<"\n\tNew pin : ";
                cin>>pin;
                cout<<"\n\tNew Phone no. : ";
                cin>>ph;
                file1<<" "<<id<<" "<<n<<" "<<f<<" "<<a<<" "<<pin<<" "<<p<<" "<<ph<<" "<<balance<<" "<<"\n";
                cout<<".........RECORD SUCCESSFULLY UPDATED.........";
                found++;
            }
            else{
                 file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<mob_no<<" "<<balance<<" "<<"\n";
            }
                file>>id>>name>>fname>>address>>pin>>pass>>mob_no>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if (found==0){
                cout<<" User Record Does Not Match With Bank Record ";
             }
        }
 }

 void bank:: del(){
    system("cls");
    string t_id,t_p;
    int found=0;
    fstream file,file1;
    cout<<"\n\n\t\tDelete User Record ";
    file.open("bank.txt",ios::in);
    if (!file){
        cout<<"\n\n ....... NO DATA EXIST ........ ";
    }
    else{
        cout<<"\n\nEnter user id:";
        cin>>t_id;
        cout<<"\nEnter pin or password :";
        cin>>t_p;
        file1.open("bank1.txt",ios::out);
        file>>id>>name>>fname>>address>>pin>>pass>>mob_no>>balance;
        while (!file.eof()){
            if (id==t_id && (t_p==pass || t_p==pin)){
                system("cls");
                cout<<".........RECORD DELETED SUCCESSFULLY .........";
                found++;
            }
            else{
                 file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<mob_no<<" "<<balance<<" "<<"\n";
            }
                file>>id>>name>>fname>>address>>pin>>pass>>mob_no>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if (found==0){
                cout<<" User Record Does Not Match With Bank Record ";
             }
        }
 }

void bank::showall(){
    system ("cls");
    int found=0;
    cout<<"\n\n\t\tShow All Users Records";
    fstream file ;
    file.open("bank.txt",ios::in);
    if (!file){
        cout<<"\n!!!!!!! ERROR IN OPENING FILE !!!!!!!";
    }
    else{
        file>>id>>name>>fname>>address>>pin>>pass>>mob_no>>balance;
        while (!file.eof()){
            cout<<"\n\n User ID : "<<id;
            cout<<"\n Name : "<<name;
            cout<<"\n Father name : "<<fname;
            cout<<"\n Address : "<<address;
            cout<<"\n pin : "<<pin;
            cout<<"\n password : "<<pass;
            cout<<"\n mobile no. : "<<mob_no;
            cout<<"\n current balance : "<<balance;
            cout<<"\n\n=============================================================================";
            file>>id>>name>>fname>>address>>pin>>pass>>mob_no>>balance;
            found++;
            }
        }
        file.close();
        if (found==0){
            cout<<"\n\n\t......file is empty .........";
        }

    }


int main()
{
    class  bank obj;
    obj.menu();
    return 0;
}

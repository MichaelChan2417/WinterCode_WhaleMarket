#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "../../include/tools/color.h"
#include "../../include/tools/login.h"

#define FILEPATH "User.txt"

static const char* MODES = "\
\t   ======================================================\n\
\t   1. Login || 2. Register || 3. Admin Mode || 4. Quit   \n\
\t            ||             ||               ||           \n\
\t   ======================================================\n\
";

// this is the function where when entering 1 need userName and
// password
void Login_Enter(){

}


// Find whether the user exist in history;
// if find return the password; else return -1;
string FindUser(string user_name){
    string cont;

    string usname;
    string uspass;
    string uskind;

    ifstream fin(FILEPATH);
    while(getline(fin,cont)){
        string temp;
        int N = cont.size();
        cout<<"testign"<<cont<<" "<< N <<endl;
    }
    return "X";
}


void LoginPage(){
    string mode_choose;
    string UserName;
    string password;
    ofstream fout(FILEPATH);
    ifstream fin(FILEPATH);
    
    printf("\n%s%sWelcome to%s %s%sShengjian Market%s\n",BOLD,FRONT_RED,RESET,BOLD,FRONT_BLUE,RESET);
    printf("%s%s%s%s\n", FRONT_BLUE,BOLD,MODES,RESET);
    while(1){
        
        cout<<"Mode Choose: ";
        cin>>mode_choose;

        if(mode_choose == "1"){
            // 
            FindUser("X");
            Login_Enter();
        }
        else if(mode_choose == "2"){
            cout<<"Please Enter Your User Name: ";
            cin>>UserName;

            cout<<"Please Enter Your Password: ";
            cin>>password;
            fout<<UserName<<" "<<password<<endl;
        }
        else if(mode_choose =="4"){
            break;
        }
        else{
            printf("%s%sERROR INPUT! PLEASE RE-ENTER%s\n",BOLD,FRONT_RED,RESET);
        }
    }
    fout.close();
    fin.close();
}
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "../../include/tools/color.h"
#include "../../include/login/login.h"

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
    printf("%s%sLogin Successfully!%s\n",BOLD,FRONT_GREEN,RESET);
}


// this is the function when successfully entering the admin mode
void Admin_Enter(){

}

// Find whether the user exist in history;
// if find return state+password; else return NOFIND;
string FindUser(string user_name){
    string cont;

    string usname;
    string uspass;
    string uskind;

    ifstream fin(FILEPATH,ios_base::in);
    while(getline(fin,cont)){
        string temp;
        int N = cont.size();
        for(int i=0;i<N;i++){
            // if ptr is not "space", add to temp to form the name
            if(cont[i] != ' '){
                temp = temp+cont[i];
                continue;
            }
            // now temp should hold a name and prepare to compare with input
            if(temp == user_name){
                string rest;
                for(;i<N;i++){
                    if(cont[i]!=' '){
                        rest = rest + cont[i];
                    }
                }
                return rest;
            }
            // we should reset the temp
            else{
                temp = "";
            }
            
        }
    }
    return "NOFIND";
}


void LoginPage(){
    string mode_choose;
    string UserName;
    string password;
    ofstream fout(FILEPATH,ios_base::app|ios_base::out);
    ifstream fin(FILEPATH,ios_base::in);
    
    
    printf("\n%s%sWelcome to%s %s%sShengjian Market%s\n",BOLD,FRONT_RED,RESET,BOLD,FRONT_BLUE,RESET);
    printf("%s%s%s%s\n", FRONT_BLUE,BOLD,MODES,RESET);
    while(1){
        
        cout<<"Mode Choose: ";
        cin>>mode_choose;

        // Login Page
        if(mode_choose == "1"){
            cout<<"Please Enter Your User Name: ";
            cin>>UserName;
            string SandP;
            SandP = FindUser(UserName);
            
            if(SandP=="NOFIND"){
                printf("Could not find your account, if you are a new user, please take %sREGISTER MODE%s.\n",FRONT_RED,RESET);
                continue;
            }
            password = SandP.substr(3);
            string temp_pass;
            cout<<"Please Enter Your password: ";
            cin>>temp_pass;
            if (temp_pass != password){
                printf("%s%sPassword invalid!%s Please re-enter!\n",FRONT_RED,BOLD,RESET);
                continue;
            }
            else{
                Login_Enter();
                break;
            }
        }
        // Register Page
        else if(mode_choose == "2"){
            cout<<"Please Enter Your User Name: ";
            cin>>UserName;
            string SandP;
            SandP = FindUser(UserName);
            while(SandP!="NOFIND"){
                printf("%s%sName Was Taken!%s\n",BOLD,FRONT_RED,RESET);
                printf("Please %s%sRE-%sEnter Your User Name: ",BOLD,FRONT_RED,RESET);
                cin>>UserName;
                SandP = FindUser(UserName);
            }
            
            cout<<"Please Enter Your PassWord: ";
            cin>>password;
            
            fout<<UserName<<" Usr "<<password<<endl;
            Login_Enter();
            break;
        }
        // Admin Page
        else if(mode_choose == "3"){
            printf("%s%sPlease Enter Your Name%s: ",BOLD,FRONT_PURPLR,RESET);
            cin>>UserName;
            string SandP;
            SandP = FindUser(UserName);

            if(SandP=="NOFIND"){
                printf("Could not find your account, if you are a new user, please take %sREGISTER MODE%s.\n",FRONT_RED,RESET);
                continue;
            }
            string temp_state = SandP.substr(0,3);
            if(temp_state != "Adm"){
                printf("You are not an administrator, please re-enter the system!\n");
                continue;
            }
            string temp_pass;
            printf("%s%sPlease Enter Your Password%s: ",BOLD,FRONT_PURPLR,RESET);
            cin>>temp_pass;
            password = SandP.substr(3);
            if (temp_pass != password){
                printf("%s%sPassword invalid!%s Please re-enter!\n",FRONT_RED,BOLD,RESET);
                continue;
            }

            // now admin mode successful!
            printf("\t\t\t   %s%sYou Are Entering Admin Mode%s\n",BOLD,FRONT_PURPLR,RESET);
            Admin_Enter();
            
            break;
        }
        else if(mode_choose == "4"){
            break;
        }
        else{
            printf("%s%sERROR INPUT! PLEASE RE-ENTER%s\n",BOLD,FRONT_RED,RESET);
        }
    }
    fout.close();
    fin.close();
}
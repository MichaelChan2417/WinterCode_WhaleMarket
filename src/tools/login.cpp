#include <iostream>
#include <string>
using namespace std;
#include "../../include/tools/color.h"
#include "../../include/tools/login.h"

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



void LoginPage(){
    int mode_choose;
    string UserName;
    string password;
    printf("\n%s%sWelcome to%s %s%sShengjian Market%s\n",BOLD,FRONT_RED,RESET,BOLD,FRONT_BLUE,RESET);
    printf("%s%s%s%s\n", FRONT_BLUE,BOLD,MODES,RESET);

    while(1){
        cout<<"Mode Choose:";
        cin>>mode_choose;

        if(mode_choose == 1){
            // 
            Login_Enter();
        }
        else if(mode_choose == 2){
            
        }
        else if(mode_choose == 4){
            break;
        }
    }
}
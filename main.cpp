#include <iostream>
#include "page.hpp"

using namespace std;

int main(){
    
    while (!loginpage()) {
        system ("cls");
        cout << "Username/password salah." << endl;
    }
    system("cls");
    mainmenu();



    return 0;
}

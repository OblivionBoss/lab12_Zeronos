#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int i = 1,r;
    string txt,grade[] = {"A","B+","B","C+","C","D+","D","F","W"};
    cout << "Press Enter 3 times to reveal your future.";
    getline(cin,txt);
    while(i<3 && getline(cin,txt)){
       i++;
    }
    srand(time(0));
    r = rand()%9;
    cout << "You will get " << grade[r] << " in this 261102.";
    return 0;
}
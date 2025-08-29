#include <iostream>
using namespace std;

int main(){
    system("clear");
    
    string food = "Nasgor"; //A food variable
    string* ptr = &food;    //A pointer variable, with the name ptr, stores data the address of food

    //Output food
    cout << food << endl;

    //Output the memory address of food
    cout << &food << endl;

    cout << ptr << endl;

    cout << *ptr << endl;




    return 0;
}
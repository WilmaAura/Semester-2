#include <iostream>
#include <string>
using namespace std;


class object{
    public:

    int id; 
    string name; 
    int test(){
        return 1;
    }
};


int main (){
    object obj;

    obj.id = 1;
    obj.name = "Example Object";
    obj.test();

    cout << "Object Details" <<  endl;
    cout << "ID: " << obj.id << endl;
    cout << "Name: " << obj.name << endl;
    return 0;
}
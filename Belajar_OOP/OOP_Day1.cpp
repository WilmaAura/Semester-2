#include <iostream>

using namespace std;

/* Syntax oop
class name{ //The class
    public:     //Acces specifier    
    int num;    //Attribute (int variable)
   string a;   /n/Attribute (int variable)
};

classes is like car, there is object which is car itself and theres attributes such as weight and color, and methods, such as drive and brake.

Attributes and methods are assiociated with variables and funcitons that belongs to class.

*/
//class itu adalah blueprintnya
class randomClass
{
    public:
    int x = 10;
    int y = 20;

    void plus(){
        int sum;
        sum = x + y;
        cout << sum;
    }

};



int main (){
    randomClass obj;
    int x, y;
    obj.plus ();    
    return 0;
}
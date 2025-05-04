#include <iostream>
using namespace std;

//ketika derived class mempunyai derived class yang lain
//inheritence multilevel is suitable when we need some kind of hierarchy

    class me{
        public:
        void myFunction(){
            cout << "loremipsumbro";
        }

    };
    class child : public me{
        
    };

    class grandchild : public child{

    };

int main (){
    grandchild obj;
    obj.myFunction();

    return 0;
}
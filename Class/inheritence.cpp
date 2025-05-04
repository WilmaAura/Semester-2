#include <iostream>
//Inheritence
// class inherit itself to derived class for example
//inheritence is used to when there is 
using namespace std;
    class vehicle{
        public :
        string type = "plane";
        void fuel (){
            cout << "aviation fuel" << endl;
        }
    };

class brand: public vehicle{
    public:
    string branded = "Garuda Pancasila";
};
int main (){
    brand br;
    br.type;
    br.fuel(); 
    cout << "The brand: " + br.branded;
    return 0;
}
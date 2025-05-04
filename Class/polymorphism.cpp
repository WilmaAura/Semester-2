#include <iostream>
using namespace std;
//Polymorphism is actually like inheritence but it related to each other  
/* For example there is a class named animal that has a method called animalsounds() 
    the derived class has to be some kind of animal: pig, dog, cat, etc.
    and polymorphism uses those methods to perform different tasks.
    */

    class animal{
        public :
        void animalSounds(){
            cout << "Animal sounds :" << endl;
        }
    };

    class cat : public  animal{
        public:
        void animalSounds(){
            cout << "Cat sounds = meow meow" << endl;
        }
    };
    class cow : public animal{
        public:
        void animalSounds(){
            cout << "Cow sounds = mooo" << endl;
        }
    };
int main (){
    animal theAnimal;
    cat theCat;
    cow theCow;

    theAnimal.animalSounds();
    theCat.animalSounds();
    theCow.animalSounds();
    return 0;
}
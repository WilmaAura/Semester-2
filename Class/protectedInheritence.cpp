#include <iostream>
//pakai encapsulation untuk menjaga data salary
//buat class employee dan derived class programmer
//salary 50.000
//bonus si programer 15000
using namespace std;
    class employee{
        protected: 
        int salary;
    };

    class programmer : public employee{
        public:
        int bonus;
        void setSalary (int s){
            salary = s;
        }
        int getSalary(){
            return salary;
        }
    };

int main(){
    programmer pro;
    pro.setSalary(50000);
    pro.bonus = 15000;

    cout << "Salary = " << pro.getSalary() << endl;
    cout << "Bonus = " << pro.bonus; 
    return 0;
}
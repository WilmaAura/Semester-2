#include <iostream>
using namespace std;
    class salary{
        private:
        int salary;
        
        public:
        void setSalary(int s){
            salary = s;
        }

        int getSalary(){
            return salary;
        }


    };
    
int main (){
    system ("clear");
    salary sal;
    sal.setSalary(100000);
    cout << sal.getSalary() << endl;
    return 0;
}
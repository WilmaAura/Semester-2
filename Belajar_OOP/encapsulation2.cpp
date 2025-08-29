#include <iostream>
using namespace std;

class employee{
    private:
    int salary;
    public:

    void setSalary (int s){
        salary = s;
    }

    int getSalary (){
        return salary;

    }

};

int main (){
    employee em;
    em.setSalary (100000);
    cout << em.getSalary();

    return 0 ;  
}
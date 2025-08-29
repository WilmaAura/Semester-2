#include <iostream>
#include <fstream> //A class that can read and write files (notepad, etc)

using namespace std;
    struct dataAll {
        string email, password;
    };

class signup{
    public:
    void tampilan (){
        cout << "-----------------------------" << endl;
        cout << "|           signup          |" <<endl;
        cout << "-----------------------------" <<endl;
        cout << "Tekan enter";
        cin.get();
    }

    void inputAcc(dataAll &input){
        ofstream fileoutput("data_email.txt"); //ofstream fileoutput adalah objek dari fstream dan berfungsi untuk menulis/mengisi ke dalam file
        
        if (!fileoutput){
            cout << "Error: file tidak bisa dibuka";
            return;
        }
        cout << "-------------------------------------" << endl;
        cout << "|           create account          |" <<endl;
        cout << "-------------------------------------" << endl<< endl;

        cout << "Email" << endl;
        cout << "--------------------------------------------" << endl;
        cin >> input.email;
        cout << "--------------------------------------------" << endl;
        cout << "Password" << endl;
        cout << "--------------------------------------------" << endl;
        cin >> input.password;
        cout << "--------------------------------------------" << endl;
        //simpan data ke file
        fileoutput << "Email = " <<  endl <<input.email << endl;
        fileoutput << "Password = " << endl <<input.password << endl;

        fileoutput.close(); //supaya file tertutup setelah diiisi
    }
    
};

class login{
    public:

    bool inputLogin(dataAll &login){
        ifstream fileinput("data_email.txt"); //membaca data dari file

        if (!fileinput){
            cout << "Error: file tidak bisa dibuka";
        }
        cout << "------------------------------------" << endl;
        cout << "|              Login     z          |" <<endl;
        cout << "------------------------------------" << endl<< endl;

        cout << "Email" << endl;
        cout << "--------------------------------------------" << endl;
        cin >> login.email;
        cout << "--------------------------------------------" << endl;
        cout << "Password" << endl;
        cout << "--------------------------------------------" << endl;
        cin >> login.password;
        cout << "--------------------------------------------" << endl;
        fileinput.close(); //supaya file tertutup setelah diiisi
    }
};

int main () {
    dataAll input;
    signup obj;
    obj.tampilan();
    obj.inputAcc(input);
    return 0;
}

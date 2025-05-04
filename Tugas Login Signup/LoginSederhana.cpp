#include <iostream>
#include <fstream>
#include <string>

using namespace std;

    bool loogedIn(){
        string username, password;
        string usn, pw;

        cout << "Enter username: "; cin >> username;
        cout << "Enter password: "; cin >> password;

        ifstream read(username + ".txt"); //ifstream membaca file
        getline (read, usn); //read username
        getline (read, pw); //read password

        if (usn == username && pw == password){
            return true;
        }
        else {
            return false;
        }

    }

    void regist (){
        string username, password;

        cout << "Regstration: " << endl << endl;
        cout << "Buat username: "; cin >> username;
        cout << endl;
        cout << "Buat Password: "; cin >> password;
        
        ofstream file;
        file.open(username + ".txt");
        file << username << endl << password;
        file.close();
        cout << "welcome" << username << "!!!" << endl;
    }
int main (){
    system ("clear");
    
    
    int pilihan;
    cout << "Main menu" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl << endl;

    cout << "pilih: "; cin >>pilihan;
    
        if (pilihan == 1){
            regist();
        }
        
        else if (pilihan == 2){
            bool status = loogedIn();

            if (!status) { //status false
                system ("clear");
                cout << endl;
                cout <<"Invalid login" << endl;
                main ();
                return 0;
            }
            else{
                cout << "Succesfully logged in" << endl;
                cout << endl;

            }         

        }
    return 0;
}   
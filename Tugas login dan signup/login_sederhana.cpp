    #include <iostream>

    using namespace std;

    class signup{
        private:
        string email, password;
        
        public:
        void tampilan (){
            cout << "-----------------------------" << endl;
            cout << "|           signup          |" <<endl;
            cout << "-----------------------------" <<endl;
            cout << "Tekan enter";
            cin.get();
        }

        void inputAcc(){
            
            cout << "-------------------------------------" << endl;
            cout << "|           create account          |" <<endl;
            cout << "-------------------------------------" << endl<< endl;

            cout << "Email" << endl;
            cout << "--------------------------------------------" << endl;
            cin >> email;
            cout << "--------------------------------------------" << endl;
            cout << "Password" << endl;
            cout << "--------------------------------------------" << endl;
            cin >> password;
            cout << "--------------------------------------------" << endl;
                    
        }
        
    };

    class login{
        private:
        string email, password;
        
        public:

        void inputLogin(){
            cout << "------------------------------------" << endl;
            cout << "|              Login               |" <<endl;
            cout << "------------------------------------" << endl<< endl;

            cout << "Email" << endl;
            cout << "--------------------------------------------" << endl;
            cin >> email;
            cout << "--------------------------------------------" << endl;
            cout << "Password" << endl;
            cout << "--------------------------------------------" << endl;
            cin >> password;
            cout << "--------------------------------------------" << endl;

        }
            
    };

    int main (){
        login loginUser;
        signup signupUser;

        signupUser.tampilan();
        signupUser.inputAcc();
        loginUser.inputLogin();

        return 0;
    }
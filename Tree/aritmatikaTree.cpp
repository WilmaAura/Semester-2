#include <iostream>
using namespace std;
    class nodeAritmatika{
        public:
        char data;
        nodeAritmatika *left, * right;

        nodeAritmatika() : data(' '), left (nullptr), right(nullptr){}
        nodeAritmatika (char data)  {
            this->data = data;
            left= right= nullptr;
        }

        void inOrderArit(nodeAritmatika* root){
            if (root != NULL){
                    if (root->left != nullptr || root->right != nullptr){
                        cout << "(";
                        }
                    inOrderArit(root->left);
                    cout << root->data << " ";
                    inOrderArit(root->right);
                    if (root->left != nullptr || root->right != nullptr){
                        cout << ")";
                    }
                
            }
        }
        int heightNodeArit(nodeAritmatika* root){
            if (root == nullptr){
                return 0;
            }
            else{
                int leftH = heightNodeArit(root->left);
                int rightH = heightNodeArit(root->right);
                return 1+ max(leftH, rightH); //perintah max dari cppnya
            }
        }
        bool isPerfectBinaryArit(nodeAritmatika* root, int tinggi, int level){
            if  (root == nullptr){
                return true;
            }
            if (root->left == nullptr && root->right == nullptr){
                return tinggi == level+1;
            }
            if(root->left == nullptr || root->right == nullptr){
                return false;
            }
            return isPerfectBinaryArit(root->left, tinggi, level+1) && isPerfectBinaryArit(root->right, tinggi, level+1);
        }
    };

int main (){
    nodeAritmatika n;
    nodeAritmatika* root = new nodeAritmatika('+');
    root->left = new nodeAritmatika('*'); 
    root->right = new nodeAritmatika('-');
    root->left->left = new nodeAritmatika('9');
    root->left->right = new nodeAritmatika('6');
    root->right->left = new nodeAritmatika('8');
    root->right->right = new nodeAritmatika('5');
    int tinggi = n.heightNodeArit(root);
    
    cout << "In order: "; n.inOrderArit(root);
    cout << endl;
    cout << "Tinggi tree (mulai dari 1): " << tinggi << endl;

    cout << "Apakah tree ini termaksud perfect binary? " << n.isPerfectBinaryArit(root, tinggi, 0);
    cout << endl;
    return 0;   
}
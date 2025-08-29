#include <iostream>
using namespace std;
    class Node{
        public:
            int data;
            Node *left;
            Node *right;
            Node(int data){
                this->data = data;
                left = right = NULL;
            }
    };
    class tree{
        //Banyak menggunakan rekursif
        public:
            Node* root;

            Node* insertBinaryRoot(Node* root, int nilai);
            void preOrder(Node* root){
                if (root!= nullptr){
                    cout << root->data << " ";
                    preOrder(root->left);
                    preOrder(root->right);
                }
            }
            void inOrder(Node* root){
                if (root!=nullptr){
                    inOrder(root->left);
                    cout << root->data << " ";
                    inOrder(root->right);
                }
            }

            void postOrder(Node* root){
                if (root != nullptr){
                    postOrder(root->left);
                    postOrder(root->right);
                    cout << root->data << " ";
                }
            }
            int heightNode(Node* root){
                if (root == nullptr){
                    return 0;
                }else{
                    int l = heightNode(root->left);
                    int r = heightNode(root->right);
                    return 1+max(l, r);
                }
            }
            void printLevel(Node* root, int lvl){
                if (root != nullptr){
                    if (lvl == 0){
                        cout << root->data << " ";
                    }
                    else if(lvl > 0){
                        printLevel(root->left, lvl-1);
                        printLevel(root->right, lvl-1);
                    }
                }
            }
            void lvlOrder(Node* root){
                int h = heightNode(root);
                for (int i = 0; i <h; i++){
                    printLevel(root, i);
                }
            }
    };

int main(){
    Node* root = new Node(7);
    root->left = new Node(5);
    root->left->left = new Node (3);
    root->left->right= new Node (6);
    root->left->left->left= new Node (1);
    root->left->left->right= new Node (4);
    root->right = new Node (12);
    root->right->left = new Node (9);
    
    tree t;
    cout << "PreOrder: ";t.preOrder(root);
    cout << endl;
    cout << "InOrder: "; t.inOrder(root);
    cout << endl;
    cout << "PostOrder: "; t.postOrder(root);
    cout << endl; 

    int tinggi = t.heightNode(root);
    cout << "Tinggi Tree (mulai dari 1): " << tinggi << endl; 
    cout << "Level Order: " ;t.lvlOrder(root);
    return 0;
}
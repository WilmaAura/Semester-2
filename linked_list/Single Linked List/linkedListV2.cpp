#include <iostream>
using namespace std;

const int maksimum = 4;  // variabel global, batas maksimum antrian

typedef struct Node {
    char data;
    Node* next;
} Node;

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    int jumlahData() {
        int total = 0;
        Node* temp = head;
        while (temp != nullptr) {
            total++;
            temp = temp->next;
        }
        return total;
    }

    void insertFirst(char data) {
        if (jumlahData() >= maksimum) {
            cout << "Antrian penuh! Maksimal " << maksimum << " data.\n";
            return;
        }
        Node* newNode = new Node{data, head};
        head = newNode;
    }

    void insertLast(char data) {
        if (jumlahData() >= maksimum) {
            cout << "Antrian penuh! Maksimal " << maksimum << " data.\n";
            return;
        }
        Node* newNode = new Node{data, nullptr};
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAfter(char target, char data) {
        if (jumlahData() >= maksimum) {
            cout << "Antrian penuh! Maksimal " << maksimum << " data.\n";
            return;
        }
        Node* current = head;
        while (current != nullptr && current->data != target) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Data '" << target << "' tidak ditemukan.\n";
            return;
        }
        Node* newNode = new Node{data, current->next};
        current->next = newNode;
    }

    void insertBefore(char target, char data) {
        if (jumlahData() >= maksimum) {
            cout << "Antrian penuh! Maksimal " << maksimum << " data.\n";
            return;
        }
        if (head == nullptr) {
            cout << "Antrian kosong.\n";
            return;
        }
         if (head->data == target) {
            insertFirst(data);
            return;
        }
        Node* prev = nullptr;
        Node* current = head;
        while (current != nullptr && current->data != target) {
            prev = current;
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Data '" << target << "' tidak ditemukan.\n";
            return;
        }
        Node* newNode = new Node{data, current};
        prev->next = newNode;
    }

    void deleteFirst() {
        if (head == nullptr) {
            cout << "Antrian kosong, tidak bisa menghapus.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteLast() {
        if (head == nullptr) {
            cout << "Antrian kosong, tidak bisa menghapus.\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
    }

    void deleteAfter(char target) {
        if (head == nullptr) {
            cout << "Antrian kosong, tidak bisa menghapus.\n";
            return;
        }
        Node* current = head;
        while (current != nullptr && current->data != target) {
            current = current->next;
        }
        if (current == nullptr || current->next == nullptr) {
            cout << "Tidak bisa menghapus setelah '" << target << "'.\n";
            return;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    void deleteBefore(char target) {
        if (jumlahData() < 2) {
            cout << "Tidak cukup data untuk menghapus sebelum.\n";
            return;
        }
        if (head->data == target) {
            cout << "Tidak ada node sebelum '" << target << "'.\n";
            return;
        }
        Node* prevPrev = nullptr;
        Node* prev = head;
        Node* current = head->next;
        while (current != nullptr && current->data != target) {
            prevPrev = prev;
            prev = current;
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Data '" << target << "' tidak ditemukan.\n";
            return;
        }
        if (prevPrev == nullptr) {
            head = current;
            delete prev;
        } else {
            prevPrev->next = current;
            delete prev;
        }
    }

    void print() {
        cout << "Isi antrian: ";
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            if (current->next != nullptr) cout << "-> ";
            current = current->next;
        }
        cout << "\nTotal data: " << jumlahData() << "/" << maksimum << endl;
    }
};

int main() {
    LinkedList queue;
    char pilihan;

    do {
        cout << "\n=== MENU ANTRIAN (maks " << maksimum << " data) ===\n";
        cout << ">>> OPERASI INSERT <<<\n";
        cout << "1. Tambah data di akhir (enqueue)\n";
        cout << "2. Tambah data di awal\n";
        cout << "3. Tambah setelah data tertentu\n";
        cout << "4. Tambah sebelum data tertentu\n";

        cout << "\n>>> OPERASI DELETE <<<\n";
        cout << "5. Hapus data pertama (dequeue)\n";
        cout << "6. Hapus data terakhir\n";
        cout << "7. Hapus setelah data tertentu\n";
        cout << "8. Hapus sebelum data tertentu\n";

        cout << "\n>>> CETAK & KELUAR <<<\n";
        cout << "9. Tampilkan antrian\n";
        cout << "0. Keluar\n";

        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == '1') {
            char data;
            cout << "Masukkan data (char): ";
            cin >> data;
            queue.insertLast(data);
        } else if (pilihan == '2') {
            char data;
            cout << "Masukkan data (char): ";
            cin >> data;
            queue.insertFirst(data);
        } else if (pilihan == '3') {
            char target, data;
            cout << "Data yang ingin disisipkan setelah apa? ";
            cin >> target;
            cout << "Masukkan data baru: ";
            cin >> data;
            queue.insertAfter(target, data);
        } else if (pilihan == '4') {
            char target, data;
            cout << "Sisipkan sebelum data apa? ";
            cin >> target;
            cout << "Masukkan data baru: ";
            cin >> data;
            queue.insertBefore(target, data);
        } else if (pilihan == '5') {
            queue.deleteFirst();
        } else if (pilihan == '6') {
            queue.deleteLast();
        } else if (pilihan == '7') {
            char target;
            cout << "Hapus data setelah? ";
            cin >> target;
            queue.deleteAfter(target);
        } else if (pilihan == '8') {
            char target;
            cout << "Hapus data sebelum? ";
            cin >> target;
            queue.deleteBefore(target);
        } else if (pilihan == '9') {
            queue.print();
        }

    } while (pilihan != '0');

    cout << "Program selesai.\n";
    return 0;
}
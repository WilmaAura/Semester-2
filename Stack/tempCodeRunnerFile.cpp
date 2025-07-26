if (IsEmpty()) {
        cout << "Queue kosong, tidak ada yang di-dequeue" << endl;
        return;
    }


    if (queue.head->next == nullptr) { // Jika hanya ada satu elemen di queue
        cout << "Dequeued 1: " << queue.rear->data << endl;
        Qnode* temp = queue.head;
        queue.head = nullptr;
        queue.rear = nullptr;
        queue.front = nullptr;
    }
    else {
        Qnode* current = queue.head;
        while (current->next != nullptr) {
            queue.front = current;
            current = current->next;
        }
        Qnode* temp = current;
        cout << "Dequeued 2: " << current->data << endl;
        queue.front->next = nullptr;
        delete temp;
        queue.count--;
    }
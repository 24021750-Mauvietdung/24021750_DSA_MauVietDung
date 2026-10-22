#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct QueueLinkedList {
    Node *head = NULL; // Đầu queue (lấy ra)
    Node *tail = NULL; // Cuối queue (thêm vào)
    int sz = 0;

    bool empty() {
        return head == NULL;
    }

    // Thêm vào CUỐI Queue - O(1)
    void push(int x) {
        Node *newNode = new Node(x);
        if (empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        sz++;
    }

    // Xóa ở ĐẦU Queue - O(1)
    void pop() {
        if (empty()) return;
        Node *tmp = head;
        head = head->next;
        if (head == NULL) { // Nếu xóa xong mà queue rỗng
            tail = NULL;
        }
        delete tmp;
        sz--;
    }

    // Lấy giá trị ở ĐẦU Queue - O(1)
    int front() {
        if (empty()) return -1;
        return head->data;
    }

    int size() {
        return sz;
    }
};

int main() {
    QueueLinkedList q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Kich thuoc: " << q.size() << endl; // 3
    cout << "Phan tu dau (front): " << q.front() << endl; // 10 (vào đầu tiên -> ra đầu tiên)

    cout << "Cac phan tu trong Queue: ";
    while (!q.empty()) {
        cout << q.front() << " "; // In ra: 10 20 30
        q.pop();
    }
    cout << endl;

    return 0;
}
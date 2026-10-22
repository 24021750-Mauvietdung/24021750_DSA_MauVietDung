#include <iostream>
using namespace std;

const int MAX = 100;

struct QueueList {
    int data[MAX];
    int front_idx = 0; // Vị trí đầu
    int rear_idx = 0;  // Vị trí thêm tiếp theo
    int sz = 0;

    bool empty() {
        return sz == 0;
    }

    // Thêm vào CUỐI Queue - O(1)
    void push(int x) {
        if (sz == MAX) {
            cout << "Queue da day!\n";
            return;
        }
        data[rear_idx] = x;
        rear_idx = (rear_idx + 1) % MAX; // Xoay vòng chỉ số
        sz++;
    }

    // Xóa ở ĐẦU Queue - O(1)
    void pop() {
        if (empty()) return;
        front_idx = (front_idx + 1) % MAX; // Tăng chỉ số đầu, không dồn mảng
        sz--;
    }

    // Lấy giá trị ở ĐẦU Queue - O(1)
    int front() {
        if (empty()) return -1;
        return data[front_idx];
    }

    int size() {
        return sz;
    }
};

int main() {
    QueueList q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Kich thuoc: " << q.size() << endl; // 3
    cout << "Phan tu dau (front): " << q.front() << endl; // 10

    cout << "Cac phan tu trong Queue: ";
    while (!q.empty()) {
        cout << q.front() << " "; // In ra: 10 20 30
        q.pop();
    }
    cout << endl;

    return 0;
}
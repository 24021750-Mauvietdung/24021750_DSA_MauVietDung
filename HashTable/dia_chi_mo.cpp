#include <iostream>

using namespace std;

const int SIZE = 7;
const int EMPTY = -1;
const int DELETED = -2;

int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

int hashFunc(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunc(key);
    for (int i = 0; i < SIZE; i++) {
        int curr = (index + i) % SIZE;
        if (hashTable[curr] == EMPTY || hashTable[curr] == DELETED) {
            hashTable[curr] = key;
            return;
        }
    }
    cout << "Bang bam da day!" << endl;
}

bool search(int key) {
    int index = hashFunc(key);
    for (int i = 0; i < SIZE; i++) {
        int curr = (index + i) % SIZE;
        if (hashTable[curr] == EMPTY) return false;
        if (hashTable[curr] == key) return true;
    }
    return false;
}

void removeKey(int key) {
    int index = hashFunc(key);
    for (int i = 0; i < SIZE; i++) {
        int curr = (index + i) % SIZE;
        if (hashTable[curr] == EMPTY) return;
        if (hashTable[curr] == key) {
            hashTable[curr] = DELETED;
            return;
        }
    }
}

int main() {
    init();
    insert(10);
    insert(17); // Trùng vị trí băm với 10, tự động nhảy sang ô trống kế tiếp

    cout << "Tim 17: " << (search(17) ? "Co" : "Khong") << endl;

    removeKey(17);
    cout << "Tim 17 sau khi xoa: " << (search(17) ? "Co" : "Khong") << endl;

    return 0;
}
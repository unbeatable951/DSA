class MyCircularQueue {

    int* arr;
    int capacity;
    int front;
    int rear;
    int size;

public:

    MyCircularQueue(int k) {

        capacity = k;

        arr = new int[k];

        front = 0;
        rear = 0;
        size = 0;
    }

    bool enQueue(int value) {

        if (isFull())
            return false;

        arr[rear] = value;

        rear = (rear + 1) % capacity;

        size++;

        return true;
    }

    bool deQueue() {

        if (isEmpty())
            return false;

        front = (front + 1) % capacity;

        size--;

        return true;
    }

    int Front() {

        if (isEmpty())
            return -1;

        return arr[front];
    }

    int Rear() {

        if (isEmpty())
            return -1;

        return arr[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() {

        return size == 0;
    }

    bool isFull() {

        return size == capacity;
    }
};
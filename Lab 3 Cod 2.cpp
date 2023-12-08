#include <iostream>

class Queue {
private:
    int* elements;
    int front;
    int rear;
    int size;
    int capacity;

public:

    Queue(int capacity = 10) : elements(new int[capacity]), front(-1), rear(-1), size(0), capacity(capacity) {}


    ~Queue() {
        delete[] elements;
    }


    Queue operator+(const Queue& other) const;


    void operator=(const Queue& other);


    friend bool operator==(const Queue& q1, const Queue& q2);


    friend bool operator!=(const Queue& q1, const Queue& q2);


    friend bool operator<(const Queue& q1, const Queue& q2);


    friend bool operator>(const Queue& q1, const Queue& q2);


    static int calculateNorm(const Queue& q);


    friend std::ostream& operator<<(std::ostream& os, const Queue& q);


    friend std::istream& operator>>(std::istream& is, Queue& q);

    void enqueue(int value);


    int dequeue();


    bool isEmpty() const {
        return size == 0;
    }


    int getSize() const {
        return size;
    }
};

Queue Queue::operator+(const Queue& other) const {
    Queue result(size + other.size);

    for (int i = 0; i < size; ++i) {
        result.enqueue(elements[(front + i) % capacity]);
    }

    for (int i = 0; i < other.size; ++i) {
        result.enqueue(other.elements[(other.front + i) % other.capacity]);
    }

    return result;
}

void Queue::operator=(const Queue& other) {
    if (this != &other) {
        delete[] elements;

        elements = new int[other.capacity];
        front = other.front;
        rear = other.rear;
        size = other.size;
        capacity = other.capacity;

        for (int i = 0; i < capacity; ++i) {
            elements[i] = other.elements[i];
        }
    }
}

bool operator==(const Queue& q1, const Queue& q2) {
    if (q1.size != q2.size) {
        return false;
    }

    for (int i = 0; i < q1.size; ++i) {
        if (q1.elements[(q1.front + i) % q1.capacity] != q2.elements[(q2.front + i) % q2.capacity]) {
            return false;
        }
    }

    return true;
}

bool operator!=(const Queue& q1, const Queue& q2) {
    return !(q1 == q2);
}

bool operator<(const Queue& q1, const Queue& q2) {
    return Queue::calculateNorm(q1) < Queue::calculateNorm(q2);
}

bool operator>(const Queue& q1, const Queue& q2) {
    return Queue::calculateNorm(q1) > Queue::calculateNorm(q2);
}

int Queue::calculateNorm(const Queue& q) {
    int norm = 0;

    for (int i = 0; i < q.size; ++i) {
        norm += q.elements[(q.front + i) % q.capacity];
    }

    return norm;
}

std::ostream& operator<<(std::ostream& os, const Queue& q) {
    for (int i = 0; i < q.size; ++i) {
        os << q.elements[(q.front + i) % q.capacity] << " ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Queue& q) {
    int value;
    is >> value;
    q.enqueue(value);
    return is;
}

void Queue::enqueue(int value) {
    if (size == capacity) {
        int* newElements = new int[2 * capacity];

        for (int i = 0; i < capacity; ++i) {
            newElements[i] = elements[(front + i) % capacity];
        }

        delete[] elements;
        elements = newElements;
        front = 0;
        rear = capacity - 1;
        capacity *= 2;
    }

    rear = (rear + 1) % capacity;
    elements[rear] = value;
    size++;
}

int Queue::dequeue() {
    if (isEmpty()) {
        std::cerr << "Error: Queue is empty.\n";
        return -1; // Or throw an exception
    }

    int value = elements[front];
    front = (front + 1) % capacity;
    size--;

    return value;
}

int main() {
    Queue q1;
    Queue q2;

    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);

    q2.enqueue(4);
    q2.enqueue(5);
    q2.enqueue(6);


    Queue sum = q1 + q2;
    std::cout << "Suma: " << sum << "\n";


    Queue q3;
    q3 = q1;
    std::cout << "Coda q1 dupa atribuire: " << q1 << "\n";
    std::cout << "Coda q3: " << q3 << "\n";


    std::cout << "q1 " << (q1 < q2 ? "<" : ">") << " q2\n";

    // Testare operatori <<, >>
    Queue q4;
    std::cout << "Introduceti elemente pentru q4 (terminati cu -1):\n";
    int value;
    while (true) {
        std::cin >> value;
        if (value == -1) {
            break;
        }
        q4.enqueue(value);
    }
    std::cout << "Coda q4: " << q4 << "\n";

    return 0;
}


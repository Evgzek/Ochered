// ConsoleApplication6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Queue {
private:
    int size;           // размер очереди
    int* data;          // указатель на массив данных
    int front, rear;    // индексы первого и последнего элементов очереди

public:
    Queue() {           // конструктор по умолчанию
        size = 0;
        data = NULL;
        front = rear = -1;
    }

    void add(int value) {   // добавление элемента в конец очереди
        if (isEmpty()) {    // если очередь пуста, создаем массив размера 1
            size = 1;
            data = new int[size];
            front = rear = 0;
        }
        else if (rear == size - 1) {  // если массив заполнен, увеличиваем его размер вдвое
            int* temp = new int[size * 2];
            for (int i = 0; i < size; i++) {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            size *= 2;
        }
        data[rear++] = value;   // добавляем элемент в конец очереди
    }

    int remove() {  // удаление первого элемента очереди
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        else {
            int value = data[front++];
            if (front > rear) {   // если очередь пуста, восстанавливаем начальное состояние
                front = rear = -1;
                size = 0;
                delete[] data;
                data = NULL;
            }
            else if (front == size / 4 && size > 1) {  // если массив заполнен менее чем на четверть, уменьшаем его размер вдвое
                int* temp = new int[size / 2];
                for (int i = 0; i < size / 2; i++) {
                    temp[i] = data[i + front];
                }
                rear -= front;
                front = 0;
                delete[] data;
                data = temp;
                size /= 2;
            }
            return value;
        }
    }

    void print() {   // вывод очереди
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        }
        else {
            cout << "Queue: ";
            for (int i = front; i < rear; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
    }

    bool isEmpty() {    // проверка, пуста ли очередь
        return front == -1;
    }
};
int main() {
    Queue q;
    q.add(5);
    q.add(7);
    q.add(2);
    q.print();      // Queue: 5 7 2
    q.remove();
    q.print();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

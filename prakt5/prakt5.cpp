#include <iostream>
#include <locale>
using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int value) : data(value), next(nullptr), prev(nullptr) {}

    };
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_front(int value)
    {
        Node* add = new Node(value);
        if (head == nullptr)
        {
            head = tail = add;
        }
        else {
            add->next = head;
            head->prev = add;
            head = add;
        }

    }
    void push_back(int value) {
        Node* add = new Node(value);
        if (head == nullptr)
        {
            head = tail = add;
        }
        else {
            add->prev = tail;
            tail->next = add;
            tail = add;
        }
    }

    void pop_front() {
        Node* del = head;
        
        if (head == nullptr)
        {
            std::cout << "Список пуст";
        }
        else {
            head = head->next;
            delete del;
        }
    }

    void pop_back() {
        Node* del = tail;
        tail = tail->prev;
        tail->next = nullptr;
        if (del == nullptr)
        {
            head = nullptr;
        }
        delete del;
    }

    void sort() {
        bool isStop = true;
        Node* tmp = nullptr;
        while (isStop == true)
        {
            isStop = false;
            Node* ptr = head;
            while (ptr->next != tmp)
            {
                if (ptr->data > ptr->next->data) {
                    int digit = ptr->data;
                    ptr->data = ptr->next->data;
                    ptr->next->data = digit;
                    isStop = true;
                }
                ptr = ptr->next;
            }
            tmp = ptr;
        }
    }





    void outPut()
    {
        if (head == nullptr) {
            std::cout << "Pusto";
            return;
        }
        Node* digit = head;
        while (digit != nullptr)
        {
            std::cout << digit->data << " ";
            digit = digit->next;
        }

    }

    void remove_duplicates() {
        if (head == nullptr)
        {
            return;
        }
        Node* current = head;

        while (current != nullptr) {
            Node* slide = current->next;
            while (slide != nullptr) {
                Node* next_slide = slide->next;  
                if (slide->data == current->data) {
                    if (slide->prev != nullptr) {
                        slide->prev->next = slide->next;
                    }
                    if (slide->next != nullptr) {
                        slide->next->prev = slide->prev;
                    }
                    delete slide; 
                }
                slide = next_slide;
            }
            current = current->next;
        }
    }
};
    



int main()
{
    setlocale(LC_ALL, "Russian");
    DoublyLinkedList l;
    
    int choose, element;
    choose = 0;
    while (choose != 8)
    {
        cout << "\n=== Меню двусвязного списка ===\n";
        cout << "1. Добавить элемент в начало\n";
        cout << "2. Добавить элемент в конец\n";
        cout << "3. Удалить элемент с начала\n";
        cout << "4. Удалить элемент с конца\n";
        cout << "5. Отобразить список\n";
        cout << "6. Сортировать список\n";
        cout << "7. Удалить дубликаты\n";
        cout << "8. Выйти\n";
        cout << "Выберите действие: ";
        cin >> choose;
        switch (choose) {
        case 1:
            cout << "Введите значение: ";
            cin >> element;
            l.push_front(element);
            break;
        case 2:
            cout << "Введите значение: ";
            cin >> element;
            l.push_back(element);
            break;
        case 3:
            l.pop_front();
            break;
        case 4:
            l.pop_back();
            break;
        case 5:
            cout << "Список: ";
            l.outPut();
            break;
        case 6:
            l.sort();
            break;
        case 7:
            l.remove_duplicates();
            break;
        case 8:
            cout << "Выход.\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }
}

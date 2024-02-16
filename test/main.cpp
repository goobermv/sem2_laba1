#include <iostream>

struct Node { //создание структуры односвязанного списка
    int data;
    struct Node* next;
    
};


void push(int val,Node** top) { //функция push в которой содаются новые узлы односвязанного списка 
    Node* newnode = new Node;
    newnode->data = val;
    newnode->next = *top;
    *top = newnode;
};

void deleteAllNodes(Node* top) { //удаление динамической памяти
    while (top != NULL) {
        Node* temp = top;
        top = top->next;
        delete(temp);
    }
}

int main() {
    int val;
    struct Node* top = NULL;
    std::cout << "Enter values into the stack (type 0 to exit):\n";
    while (true) { //ввод чисел в стек, 0 это точка окончания ввода чисел + проверка на правильность ввода с клавиатуры
        std::cin >> val;
        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(1000,'\n');
            std::cout << "Wrong input, enter an integer.\n";
            continue;
        }
        if (val == 0)break;
        push(val, &top);
    }

    std::cout << "\nValues in the stack:\n";
    while (top) { //цикл while в котором находятся действия функции pop 
            if (top->data > 0)
                std::cout << top->data << " ";
            top = top->next;
    }
    deleteAllNodes(top);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

template <typename T>
struct Node {
    T val;
    Node *next;
};

template <typename T>
class LinkedList {
    private:
        Node<T> *head;
    public:
        LinkedList(T value) {
            Node<T> *tmp = (Node<T>*) malloc(sizeof (Node<T>));
            tmp->val = value;
            tmp->next = NULL;
            head = tmp;
        }

        void append(T value) {
            Node<T> *tmp = (Node<T>*) malloc(sizeof(Node<T>));
            Node<T> *curr = head;
            tmp->val = value;
            tmp->next = NULL;

            while ( curr->next ) {
                curr = curr->next;
            }
            curr->next = tmp;
        }

        void traverse() {
            Node<T> *tmp = head;
            while ( tmp ) {
                std::cout << tmp->val << std::endl;
                tmp = tmp->next;
            }
        }
};

int main()
{
    auto linker = LinkedList<int>(32);
    linker.append(2);
    linker.append(89);

    linker.traverse();

    return 0;
}

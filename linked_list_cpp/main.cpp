#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T val;
    Node *next;
};

template <typename T>
class LinkedList {
    public:

        Node<T> *head;

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

        void debug() {
            Node<T> *tmp = head;

            printf("[");
            while ( tmp ) {

                if (tmp->next) {
                    std::cout << tmp->val << ", ";
                } else if ( !tmp->val ){
                    std::cout << "";
                } else {
                    std::cout << tmp->val;
                }

                tmp = tmp->next;
            }
            printf("]\n");
        }

        void push(T value) {
            Node<T> *tmp = (Node<T>*) malloc(sizeof(Node<T>));
            tmp->val = value;
            tmp->next = head;
            head = tmp;
        }

        void clear() {
            head = (Node<T>*) malloc(sizeof(Node<T>));
            head->next = NULL;
        }
};

int main()
{
    auto linker = LinkedList<int>(32);
    linker.append(2);
    linker.append(89);
    linker.push(10);

    linker.debug();

    linker.clear();
    linker.debug();

    return 0;
}

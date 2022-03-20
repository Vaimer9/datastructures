#include <cstddef>
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

        LinkedList()
        {
            Node<T> *tmp = (Node<T>*) malloc(sizeof (Node<T>));
            tmp->next = NULL;
            head = tmp;
        }

        void append(T value)
        {
            if ( !head->val ) {
                head->val = value;
            } else {
                Node<T> *tmp = (Node<T>*) malloc(sizeof(Node<T>));
                Node<T> *curr = head;
                tmp->val = value;
                tmp->next = NULL;

                while ( curr->next ) {
                    curr = curr->next;
                }
                curr->next = tmp;
            }
        }

        void debug()
        {
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

        void push(T value)
        {
            if ( !head->val ) {
                head->val = value;
            } else {
                Node<T> *tmp = (Node<T>*) malloc(sizeof(Node<T>));
                tmp->val = value;
                tmp->next = head;
                head = tmp;
            }
        }

        // Time Complexity : O(n)
        void clear()
        {
            Node<T> *tmp;

            while (head)
            {
                tmp = head;
                head = head->next;
                free(tmp);
            }
            head = NULL;
        }
};

int main()
{
    LinkedList<int> linker;

    linker.append(2);
    linker.append(89);
    linker.push(10);

    linker.debug();

    linker.clear();
    linker.debug();

    return 0;
}

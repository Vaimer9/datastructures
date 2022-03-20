#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define NEWNODE (Node<T>*) malloc(sizeof (Node<T>));

using namespace std;

template <typename T>
struct Node {
    T val;
    Node *next;
};

template <typename T>
class LinkedList {

    private:

    void clear_elements()
    {
        Node<T> *tmp;

        while (head)
        {
            tmp = head;
            head = head->next;
            free(tmp);
        }
    }
    public:

    Node<T> *head;

    LinkedList()
    {
        Node<T> *tmp = NEWNODE;
        tmp->next = NULL;
        head = tmp;
    }

    ~LinkedList()
    {
        clear_elements();
    }


    void append(T value)
    {
        if ( !head->val ) {
            head->val = value;
        } else {
            Node<T> *tmp = NEWNODE;
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
                continue;
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
            Node<T> *tmp = NEWNODE;
            tmp->val = value;
            tmp->next = head;
            head = tmp;
        }
    }
    
    void clear() {
        clear_elements();
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

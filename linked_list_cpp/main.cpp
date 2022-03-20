/* 
 * Singly Linked list implemented by @vaimer9
 * github: vaimer9
 * email: vaim3r9@gmail.com
 *
 * Just one more thing I spend my time on 
 * 
 * All the code here is written by me, when I look for solutions I try looking for the broad problem
 * rather than the specific solution in context of a linked list
 */

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
        if ( !head ) {
            head = NEWNODE;
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
        if ( !head ) {
            head = NEWNODE;
            head->val = value;
        } else {
            Node<T> *tmp = NEWNODE;
            tmp->val = value;
            tmp->next = head;
            head = tmp;
        }
    }
    
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

    T *get_nth(int index)
    {
        int i = 1;
        Node<T> *curr = head;

        while ( curr ) {
            if ( i == index )
                return &curr->val;

            curr = curr->next;
            i++;
        }

        return NULL;
    }

    int set_nth(int index, T value)
    {
        int i = 1;
        Node<T> *curr = head;

        while ( curr ) {
            if ( i == index ) {
                curr->val = value;
                return 0;

            } else if ( !curr->next )
                return 0;

            curr = curr->next;
            i++;
        }

        return 1;
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

    linker.append(3);
    linker.push(32);
    /* linker.append(881); */
    linker.debug();

    int *myint = linker.get_nth(1);
    printf("%d\n", *myint );

    linker.set_nth(2, 23);
    linker.debug();

    return 0;
}

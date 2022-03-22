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

using namespace std;

template <typename T>
struct Node {
    T val;
    Node *next;
};

template <typename T>
class LinkedList {

    Node<T> *head;

    private:

    void clear_elements()
    {
        Node<T> *tmp;

        while (head)
        {
            tmp = head;
            head = head->next;
            delete(tmp);
        }
    }
    public:


    LinkedList()
    {
        head = NULL; 
    }

    ~LinkedList()
    {
        clear_elements();
    }


    void append(T value)
    {
        if ( !head ) {
            head = new Node<T>;
            head->val = value;
        } else {
            Node<T> *tmp = new Node<T>;
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
            head = new Node<T>;
            head->val = value;
        } else {
            Node<T> *tmp = new Node<T>;
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
            delete tmp;
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

    int set_nth(T value, int index)
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

    int pop()
    {
        if ( !head ) 
            return 0;
        else if ( !head->next )
            head = NULL;

        Node<T> *curr = head;
        Node<T> *tmp = new Node<T>;

        while( curr ) {

            if ( !curr->next->next ) {
                tmp = curr->next;
                curr->next = NULL;
                
                delete tmp;

                break;
            } else {
                curr = curr->next;
            }
        }
        return 1;
    }

    unsigned long length()
    {
        unsigned long count = 0;
        Node<T> *curr = head;

        while ( curr )
        {
            count++;
            curr = curr->next;
        }

        return count;
    }

    int insert(T value, unsigned long index)
    {
        Node<T> *curr = head;
        Node<T> *newnode = new Node<T>;

        newnode->val = value;
        unsigned long i = 1;

        while ( curr )
        {
            ++i;
            if ( i == index ) {
                newnode->next = curr->next;
                curr->next = newnode;

                return 1;
            } else {
                curr = curr->next;
            }
        }

        return 0;
    }

    int remove(unsigned long index)
    {
        Node<T> *curr = head;
        Node<T> *tmp = new Node<T>;
        unsigned long i = 0;

        while (curr)
        {
            i++;
            if ( i + 1 == index ) {
                tmp = curr->next;
                if (tmp)
                    curr->next = tmp->next;
                else
                    curr->next = NULL;

                delete tmp;
                return 0;
            }

            curr = curr->next;
        }
        return 1;
    }

    unsigned long *index(T value)
    {
        Node<T> *curr = head;
        unsigned long *i = new unsigned long;
        *i = 0;

        while (curr)
        {
            (*i)++;
            if ( curr->val == value )
                return i;

            curr = curr->next;
        }

        return NULL;
    }

    // Where's the internship FAANG?
    // I must confess this code is from geeksforgeeks
    void reverse()
    {
        Node<T> *curr = head;
        Node<T> *prev = NULL, *next = NULL;

        while ( curr )
        {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        head = prev;
    }

    constexpr T& operator[](std::size_t x)
    {
        unsigned long i = 0;
        Node<T> *curr = head;

        while ( curr )
        {
            if (i == x)
                return curr->val;

            i++;
            curr = curr->next;
        }
        cout << "Index out of bounds, exiting...";
        exit(0);
    }
};

int main()
{
    LinkedList<int> linker;

    linker.append(21);
    linker.append(74);
    linker.append(31);
    linker.append(90);
    linker.debug();

    linker.reverse();
    linker.append(23);

    linker.debug();
    return 0;
}

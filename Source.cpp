#include <iostream>
#include <iomanip>
using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

void Insert(Elem*& L, Info value, Elem* tail = NULL)
{
    if (!tail)
        tail = L;

    Elem* tmp = new Elem;
    tmp->info = value;

    if (L == NULL)
    {
        L = tmp;
        L->link = L;
        return;
    }

    if (tail->link == L)
    {
        tail->link = tmp;
        tmp->link = L;
        return;
    }

    Insert(L, value, tail->link);
}


void Remove(Elem*& first, Info value)
{
    if (first == NULL) {
        return;
    }

    Elem* current = first;
    Elem* previous = NULL;

    do {
        if (current->link->info == value) {
            if (previous != NULL) {
                Elem* temp = previous->link;
                previous->link = current->link;
                delete temp;
                return;
            }
            else {
                Elem* last = first;
                while (last->link != first) {
                    last = last->link;
                }
                first = first->link;
                last->link = first;
                delete current;
                return;
            }
        }
        else {
            previous = current;
            current = current->link;
        }
    } while (current != first);
}

void print(Elem* L, Elem* first = NULL) {
    if (L == NULL) {
        return;
    }

    if (first == NULL) {
        first = L;
    }

    cout << setw(4) << L->info;

    if (L->link != first) {
        print(L->link, first);
    }
    else {
        cout << endl;
    }
}


int main()
{

    Elem* L = NULL;
    Elem* first = L;

    for (int i = 0; i < 10; i++)
        Insert(L, i);
    print(L);

    int value;
    cout << "Enter a value: ";
    cin >> value;

    Remove(L, value);
    print(L);
    return 0;
}
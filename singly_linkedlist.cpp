#include <iostream>
using namespace std;

class Node
{
    public:
    int noMhs;
    Node *next;
};

// Class Linkedlist
class Linkedlist
{
    Node *START;

    public:
    Linkedlist()
    {
        START = NULL;
    }

    //void node
    void addNode()
    {
        int nim;
        cout << "\nMasukkan Nomor Mahasiswa: ";
        cin >> nim;

        Node *nodeBaru = new Node;
        nodeBaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if ((START != NULL) && (nim == START->noMhs))
            {
                cout << "\nDuplikasi noMhs tidak diijikankan\n";
                return;
            }

            Node *previous = START;
            Node *current = START;
        }
    }
}
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

            while ((current != NULL) && (nim >= current->noMhs))
            {
                if (nim == current->noMhs)
                {
                    cout << "\nDuplikasi noMhs tidak diijinkan\n";
                    return;
                }
                previous = current;
                current = current->next;
            }

            nodeBaru->next = current;
            previous->next = nodeBaru;
        }

        bool ListEmpty()
        {
            return (START == NULL);
        }

        bool Search(int nim, Node **previous, Node **current)
        {
            *previous = START;
            *current = START;

            while ((*current != NULL) && (nim != (*current)->noMhs))
            {
                *previous = *current;
                *current = (*current)->next;
            }

            return (*current != NULL);
        }

        bool delNode(int nim)
        {
            Node *current, *previous;
            if (!Search(nim, &previous, &current))
            return false;

            if (current == START)
            START = START->next;
            else
            previous->next = current->next;

            delete current;
            return true;
        }

        void traverse()
        {
            if (listEmpty())
            {
                cout << "\nList Kosong\n";
            }
            else
            {
                cout << "\nData didalam list adalah:\n";
                Node *currentNode = START;
                while (currentNode != NULL)
                {
                    cout << currentNode->noMhs << endl;
                    currentNode = currentNode->next;
                }
                cout << endl;
            }
        }
    }
};

int main()
{
    Linkedlist Mhs;
    int nim;
    char ch;
    do
    {
        cout << endl;
        cout << "menu";
        cout << endl;
        cout << "1. menambah data kedalam list" << endl;
        cout << "2. menghapus data dari dalam list" << endl;
        cout << "3. menampilkan semua data dari dalam list" << endl;
        cout << "4. menampilkan semua data didalam list secara terbalik" << endl;
        cout << "5. mencari data dalam list" << endl;
        cout << "6. keluar" << endl;
        cout << endl
        << "Masukkan pilihan (1-5): ";
        cin >> ch;
        switch (ch)
        {
            case '1':
            {
                Mhs.addNode();
            }
            break;

            case '2':
            {
                if (Mhs.ListEmpty())
                {
                    cout << endl;
                   cout << "List kosong" << endl;
                    break;
                }
                cout << endl;
                cout << "\nMasukkan no mahasiswa yang akan dihapus : ";
                cin >> nim;
                if (Mhs.delNode(nim) == false)
                cout << endl;
                cout << "Data tidak ditemukan" << nim 
                << " berhasil dihapus " << endl;
            }
            break;
            case '3':
            {
                Mhs.traverse();
            }
            break;
            case '4':
            {
                if (Mhs.ListEmpty() == true)
                {
                    cout << "\nList kosong\n";
                    break;
                }
            }
        }
    } while ();
    
}
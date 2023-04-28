#include<iostream>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    Node* parent;

    int numberUDK;
    string authorName;
    string bookName;
    int year;
    int countBook;
};

class Tree
{
public:
    Node* head, * temp;
    Tree();
    ~Tree();
    Node* Insert(int year);//добавление элемента
    void TravelTree(Node* x);//обход дерева
    Node* SearchNameTree(string bookName, int year);//поиск листа ниже листа x
    void DeleteTree(string bookName, int year);
    Node* SearchMinElemTree(Node *x);
    void AddBook(int numberUDK, string authorName, string bookName, int year, int countBook);
    void AddBook(int countAdd);
    int count = 0;
private:

};

Tree::Tree()
{
}

Tree::~Tree()
{
}

void Tree::AddBook(int numberUDK, string authorName, string bookName, int year, int countBook) {
    Node* x = Insert(year);
    x->numberUDK = numberUDK;
    x->authorName = authorName;
    x->bookName = bookName;
    x->countBook = countBook;
}

void Tree::AddBook(int countAdd) {
    for (int i = 0; i < countAdd; i++) {
        cout << "Введите год : " << endl;
        int year;
        cin >> year;
        Node* x = Insert(year);
        cout << "Введите название: " << endl;
        cin >> x->bookName;
        cout << "Автор: " << endl;
        cin >> x->authorName;
        cout << "Количество экземпляров: " << endl;
        cin >> x->countBook;
        cout << "Номер УДК: " << endl;
        cin >> x->numberUDK;
    }
}

Node* Tree::Insert(int year) {
    if (!head) {
        Node* temp = new Node;
        temp->year = year;
        temp->left = temp->right = NULL;
        cout << year << endl;
        head = temp;
        //delete temp;
        return head;
    }

    Node* x = head;
    do {
        if (year > (x->year)){
            if ((x->right) == NULL) {
                Node* temp = new Node;
                temp->year = year;
                temp->left = temp->right = NULL;
                temp->parent = x;
                x->right = temp;
                //delete temp;
                //cout << year << endl;
                return x->right;
            }
            x = x->right;
        } else {
            if ((x->left) == NULL) {
                Node* temp = new Node;
                temp->year = year;
                temp->left = temp->right = NULL;
                temp->parent = x;
                x->left = temp;
                //delete temp;
                //cout << year << endl;
                return x->left;
            }
            x = x->left;
        }
    }
        while (1);
}

void Tree::TravelTree(Node* x) {
    if (!head) {
        cout << "Дерево пустое" << endl;
        return;
    }
    if (x->left != NULL)
        TravelTree(x->left);
    cout << "Номер книги: " << (++count) << endl;
    cout << "Название: " << x->bookName << endl;
    cout << "Автор: " << x->authorName << endl;
    cout << "Год : " << x->year << endl;
    cout << "Количество экземпляров: " << x->countBook << endl;
    cout << "Номер УДК: " << x->numberUDK << endl << endl;
    if (x->right != NULL)
        TravelTree(x->right);
}

Node* Tree::SearchNameTree(string bookName, int year) {
    if (!head) {
        cout << "Дерево пустое" << endl;
        return head;
    }
    
    Node* x = head;
    do{
        if ((x->bookName) == bookName) {
            return x;
        }
        if (year > (x->year)) {
            x = x->right;
        }
        else {
            x = x->left;
        }
    } while (x != NULL);
}

Node* Tree::SearchMinElemTree(Node* x) {
    while (x->left != NULL) {
        x = x->left;
    };
    return x;
};

void Tree::DeleteTree(string bookName, int year) {
    if (head == NULL) {
        cout << "Дерево пустое" << endl;
        return;
    }
    Node * y, * z;
    Node* x = SearchNameTree(bookName, year);
    if ((x->left != NULL) && (x->right != NULL)) {
        y = SearchMinElemTree(x->right);
        z = y->parent;
        y->parent == NULL;
        if (z->right == y) {
            z->right = NULL;
        }
        if (z->left == y) {
            z->left = NULL;
        }

        y->parent = x->parent;

        y->left = x->left;
        z = x->left;
        z->parent = y;
        x->left = NULL;

        if (x != head) {
            z = x->parent;
            x->parent = NULL;

            if (z->right == x) {
                z->right = y;
            }
            if (z->left == x) {
                z->left = y;
            }
        }
        else {
            head = y;
        }
        return;
    };

    if ((x->left == NULL) && (x->right == NULL)) {
        if (x != head) {
            z = x->parent;
            if (z->left == x) {
                z->left = NULL;
            }
            if (z->right == x) {
                z->right = NULL;
            }
            x->parent = NULL;
        }
        else {
            head = NULL;
        }
    }
    else {
        if (x->left == NULL) {
            y = x->right;
           
            if (x != head) {
                y->parent = x->parent;
                z = x->parent;
                if (z->left == x) {
                    z->left = NULL;
                }
                if (z->right == x) {
                    z->right = NULL;
                }
                x->parent = NULL;
            }
            else {
                head = y;
                head->parent = NULL;
            }

            x->right == NULL;
        }

        if (x->right == NULL) {
            y = x->left;
            if (x != head) {
                y->parent = x->parent;
                z = x->parent;
                if (z->left == x) {
                    z->left = NULL;
                }
                if (z->right == x) {
                    z->right = NULL;
                }
                x->parent = NULL;
            }
            else {
                head = y;
                head->parent = NULL;
            }
            x->left == NULL;
        }
    }
}

void main() {
    setlocale(LC_ALL, "rus");
    system("chcp 1251 > NULL");
    Tree obj;
    obj.AddBook(65007, "Иванов_И.И.", "Чёрный пёс", 1953, 4);
    obj.AddBook(65008, "Петров_П.П.", "Белый снег", 1951, 2);
    obj.AddBook(65009, "Сидоров_С.С.", "Дорога", 1957, 15);
    obj.AddBook(65001, "Васильев_В.В.", "Город", 1955, 4);
    obj.AddBook(65002, "Николаев_Н.Н.", "Отцы и матери", 1958, 7);
    cout << "Изначальный список книг: " << endl;
    obj.TravelTree(obj.head);
    obj.count = 0;
    cout << "Список книг после добавления: " << endl;
    obj.AddBook(2);
    obj.TravelTree(obj.head);
    obj.count = 0;
    obj.DeleteTree("Дорога", 1957);
    obj.DeleteTree("Город", 1955);
    cout << "Список книг после удаления: " << endl;
    obj.TravelTree(obj.head);
    obj.count = 0;
 
    cout << "Mission Completed" << endl;
}



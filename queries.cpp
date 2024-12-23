#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_head(Node *&head, int val)
{
    Node *newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void delete_at_head(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;
}

void delete_at_any_pos(Node *head, int idx)
{
    Node *tmp = head;
    for (int i = 1; i < idx; i++)
    {
        if (tmp->next == NULL)
        {
            return;
        }

        tmp = tmp->next;
    }
    Node *deleteNode = tmp->next;
    if (deleteNode != NULL)
    {
        tmp->next = deleteNode->next;
        delete deleteNode;
    }
}

void delete_at_tail(Node *head, Node *&tail, int idx)
{
    Node *tmp = head;
    for (int i = 1; i < idx; i++)
    {
        if (tmp->next == NULL)
        {
            return;
        }

        tmp = tmp->next;
    }
    Node *deleteNode = tmp->next;
    if (deleteNode != NULL)
    {
        tmp->next = deleteNode->next;
        delete deleteNode;
        tail = tmp;
    }
}

void delete_at_index(Node *&head, Node *&tail, int index)
{
    if (index < 0 || head == NULL)
    {
        return;
    }
    if (index == 0)
    {
        delete_at_head(head);
        if (head == NULL)
        {
            tail = NULL;
        }
        return;
    }

    Node *tmp = head;
    int size = 0;
    while (tmp != NULL)
    {
        tmp = tmp->next;
        size++;
    }
    tmp = head;
    if (index == size - 1)
    {
        delete_at_tail(head, tail, index);
        return;
    }
    delete_at_any_pos(head, index);
}

void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int Q;
    cin >> Q;

    while (Q--)
    {
        int X, V;
        cin >> X >> V;

        if (X == 0)
        {
            insert_at_head(head, V);
            if (tail == NULL)
            {
                tail = head;
            }
        }
        else if (X == 1)
        {
            insert_at_tail(head, tail, V);
        }
        else if (X == 2)
        {
            delete_at_index(head, tail, V);
        }

        print_linked_list(head);
    }

    return 0;
}

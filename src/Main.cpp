#include <iostream>

struct Node
{
    int data;
    Node* next;
};

Node * CreateNode(int data)
{
    Node* n = new Node();
    n->data = data;
    n->next = nullptr;
    return n;
}

Node * PushNode(Node * current, int data)
{
    if (current == nullptr)
    {
        return nullptr;
    }

    Node * n = CreateNode(data);
    current->next = n;

    return n;
}

Node * CreateList(size_t size)
{
    if (size == 0) {
        return nullptr;
    }

    Node * head = CreateNode(0);
    Node * curr = head;

    for (size_t i = 1; i < size; i++)
    {
        curr = PushNode(curr, i);
    }

    return head;
}

void ReverseList(Node ** head)
{
    Node * current = *head;
    Node * next = nullptr;
    Node * prev = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void PrintList(Node * head)
{
    Node * current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    Node * list = CreateList(10);

    std::cout << "Normal list:\n";
    PrintList(list);

    std::cout << "Reversed list:\n";
    ReverseList(&list);
    PrintList(list);

    std::cin.get();
    return 0;
}
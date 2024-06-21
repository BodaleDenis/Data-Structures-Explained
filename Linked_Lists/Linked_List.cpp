#include <iostream>
#include "Linked_List.hpp"

Node::Node(int value)
{
    this->value = value;
    next = nullptr;
}

LinkedList::LinkedList(int value)
{
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
}

LinkedList::~LinkedList()
{
    Node* temp = head;
    while (head)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}

void LinkedList::printLinkedList()
{
    Node* temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->value << std::endl;
        temp = temp->next;
    }
}

void LinkedList::getHeadOrTail(HeadOrTail headortail, Node* node)
{
    std::string headOrTailStr = (HEAD == headortail) ? "head" : "tail";
    node = (HEAD == headortail) ? node = head : node = tail;

    if (node == nullptr)
    {
        std::cout << headOrTailStr << " is nullptr!" << std::endl;
    }
    else
    {
        std::cout << headOrTailStr << " value is " << node->value << std::endl;
    }
}

void LinkedList::append(int value)
{
    Node* newNode = new Node(value);
    if (length == 0)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

void LinkedList::deleteLast()
{
    if (length == 0) return;
    Node* temp = head;
    if (length == 1)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        Node* pre = head;
        while (temp->next)
        {
            pre = temp;
            temp = temp->next;
        }
        tail = pre;
        tail->next = nullptr;
    }
    delete temp;
    length--;
}

void LinkedList::prepend(int value)
{
    Node* newNode = new Node(value);
    if (length == 0)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    length++;
}

void LinkedList::deleteFirst()
{
    if (length == 0) return;
    Node* temp = head;
    if (length == 1)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = head->next;
    }
    delete temp;
    length--;

}

Node* LinkedList::get(int index)
{
    if (index < 0 || index >= length) return nullptr;
    Node* temp = head;
    for (int i=0; i<index; ++i)
    {
        temp = temp->next;
    }
    return temp;
}

bool LinkedList::set(int index, int value) 
{
    Node* temp = get(index);
    if (temp)
    {
        temp->value = value;
        return true;
    } 
    return false;
}

bool LinkedList::insert(int index, int value) 
{
    if (index < 0 || index > length) return false;
    if (index == 0 || index == length)
    {
        prepend(value);
        return true;
    }
    Node* newNode = new Node(value);
    Node* temp = get(index - 1);
    newNode->next = temp->next;
    temp->next = newNode;
    length++;
    return true;
}

void LinkedList::deleteNode(int index)
{
    if (index < 0 || index >= length) return;
    if (index == 0) return deleteFirst();
    if (index == length - 1) return deleteLast();

    Node* prev = get(index - 1);
    Node* temp = prev->next;
    prev->next = temp->next;
    delete temp;
    length--;
}

void LinkedList::reverse() 
{
    Node* temp = head;
    head = tail;
    tail = temp;
    Node* after = temp->next;
    Node* before = nullptr;
    for (auto i=0; i<length; ++i)
    {
        after = temp->next;
        temp->next = before;
        before = temp;
        temp = after;
    }
}

int main()
{
    LinkedList* someLL = new LinkedList(2);
    someLL->append(4);
    someLL->append(6);
    someLL->append(8);
    someLL->append(10);
    someLL->printLinkedList();
    someLL->reverse();
    someLL->printLinkedList();
    return 0;
}
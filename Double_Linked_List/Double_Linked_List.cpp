#include <iostream>
#include "Double_Linked_List.hpp"

Node::Node(int value)
{
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
}

DoubleLinkedList::DoubleLinkedList(int value)
{
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
}

DoubleLinkedList::~DoubleLinkedList()
{
    Node* temp = head;
    while(head)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}

void DoubleLinkedList::printList()
{
    Node* temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->value << std::endl;
        temp = temp->next;
    }
}

void DoubleLinkedList::getHeadOrTail(HeadOrTail headortail, Node* node)
{
    std::string headOrTailStr = (HEAD == headortail) ? "head" : "tail";
    node = (HEAD == headortail) ? node = head : node = tail;
    int value = node->value;
    if (node == nullptr)
    {
        std::cout << headOrTailStr << " is nullptr!" << std::endl;
    }
    else
    {
        std::cout << headOrTailStr << " value is " << value << std::endl;
    }
}

void DoubleLinkedList::getLength()
{
    std::cout << "Length= " << length << std::endl;
}

void DoubleLinkedList::append(int value)
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
        newNode->prev = tail;
        tail = newNode;
    }
    length++;
}

void DoubleLinkedList::deleteLast()
{
    if (length == 0) return;

    Node* temp = tail;

    if (length == 1)
    {
        head = tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    length--;
}

void DoubleLinkedList::prepend(int value)
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
        head->prev = newNode;
        head = newNode;
    }
    length++;
}

void DoubleLinkedList::deleteFirst()
{
    if (length == 0) return;

    Node* temp = head;

    if (length == 1)
    {
        head = tail = nullptr;
    }
    else
    {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    length--;
}

Node* DoubleLinkedList::get(int index)
{
    if (index<0 || index>=length) return nullptr;
    Node* temp = head;
    if (index < length/2)
    {
        for (auto i=0; i<index; ++i)
        {
            temp = temp->next;
        }
    }
    else
    {
        temp = tail;
        for (auto i=length-1; i>index; --i)
        {
            temp = temp->prev;
        }
    }
    return temp;
}

bool DoubleLinkedList::set(int index, int value)
{
    Node* temp = get(index);
    if (temp)
    {
        temp->value = value;
        return true;
    }
    return false;
}

bool DoubleLinkedList::insert(int index, int value)
{
    if (index<0 || index>length) return false;
    if (index == 0 || index == length)
    {
        prepend(value);
        return true;
    }

    Node* newNode = new Node(value);
    Node* before = get(index-1);
    Node* after = before->next;
    newNode->prev = before;
    newNode->next = after;
    before->next = newNode;
    after->prev = newNode;
    length++;
    return true;
}

void DoubleLinkedList::deleteNode(int index)
{
    if (index<0 || index>=length) return;
    if (index == 0) return deleteFirst();
    if (index == length-1) return deleteLast();

    Node* temp = get(index);

    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;
    length--;
}

int main()
{
    DoubleLinkedList* dll = new DoubleLinkedList(2);
    dll->append(4);
    dll->append(6);
    dll->append(8);
    dll->append(10);

    dll->printList();
    dll->deleteNode(2);
    dll->printList();
}
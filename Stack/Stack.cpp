#include "Stack.hpp"
#include <iostream>

Node::Node(int value)
{
    this->value = value;
    next = nullptr;
}
Stack::Stack(int value)
{
    Node* newNode = new Node(value);
    top = newNode;
    height = 1;
}

Stack::~Stack()
{
    Node* temp = top;
    while (top)
    {
        top = top->next;
        delete temp;
        temp =  top;
    }
}

void Stack::print()
{
    Node* temp = top;
    while (temp)
    {
        std::cout << temp->value << std::endl;
        temp = temp->next;
    }
}

void Stack::getTop()
{
    if (top == nullptr)
    {
        std::cout << "Top is null" << std::endl;
    }
    else
    {
        std::cout << "Top is " << top->value << std::endl;
    }
}

void Stack::getHeight()
{
    std::cout << "Height is " << height << std::endl;
}

bool Stack::isEmpty()
{
    if (height == 0) return true;
    return false;
}

void Stack::push(int value)
{
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    height++;
}

int Stack::topValue()
{
    if (top) return top->value;
    return INT_MIN;
}

int Stack::pop()
{
    if (height == 0) return INT_MIN;

    Node* temp = top;
    int poppedValue = top->value;
    top = top->next;
    delete temp;
    height--;

    return poppedValue;
}

int main()
{
    while (true)
    {
        Stack* stack = new Stack(2);
        stack->push(4);
        stack->getTop();
        stack->push(6);
        stack->getTop();
        stack->pop();
        stack->getTop();
    }
}
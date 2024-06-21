
class Node
{
    public:
        int value;
        Node* next;

        Node (int value);
};

class Stack
{
private:
    Node* top;
    int height;
public:
    Stack(int value);
    ~Stack();
    void print();
    void getTop();
    void getHeight();
    bool isEmpty();
    void push(int value);
    int topValue();
    int pop();

};
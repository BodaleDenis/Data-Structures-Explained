
class Node
{
public:
    int value;
    Node* next;
    Node(int value);
    ~Node() = default;

private: 
};

class LinkedList
{
public:
    LinkedList(int value);
    ~LinkedList();
    enum HeadOrTail {HEAD, TAIL};
    void printLinkedList();
    void getHeadOrTail(HeadOrTail headortail, Node* node);
    void getLength();
    void append(int value);
    void deleteLast();
    void prepend(int value);
    void deleteFirst();
    Node* get(int index);
    bool set(int index, int value);
    bool insert(int index, int value);
    void deleteNode(int index);
    void reverse();

private:
    Node* head;
    Node* tail;
    int length;
    
};
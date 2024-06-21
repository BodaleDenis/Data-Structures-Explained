
class Node
{
    public:
        int value;
        Node* next;
        Node* prev;
        Node(int value);
};

class DoubleLinkedList
{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        DoubleLinkedList(int value);
        ~DoubleLinkedList();
        enum HeadOrTail {HEAD, TAIL};
        void printList();
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
};

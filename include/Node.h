#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node();
        Node(int val) {value = val;}
        virtual ~Node();

        char Value() { return value; }
        void Setvalue(int val) { value = val; }
        Node* Next() { return next; }
        void Setnext(Node* val) { next = val; }

    protected:

    private:
        int value;
        Node* next;
};

#endif // NODE_H

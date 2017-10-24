#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node();
        Node(char val) {value = val;}
        virtual ~Node();

        char Value() { return value; }
        void Setvalue(char val) { value = val; }
        Node* Next() { return next; }
        void Setnext(Node* val) { next = val; }

    protected:

    private:
        char value;
        Node* next;
};

#endif // NODE_H

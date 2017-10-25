#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node();
        Node(float val) {value = val;}
        virtual ~Node();

        char Value() { return value; }
        void Setvalue(float val) { value = val; }
        Node* Next() { return next; }
        void Setnext(Node* val) { next = val; }

    protected:

    private:
        float value;
        Node* next;
};

#endif // NODE_H

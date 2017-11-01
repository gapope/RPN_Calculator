#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node();
        Node(float val) {value = val;}
        virtual ~Node();

        //get and set for each value
        float Value() {return value;}
        void Setvalue(float val) {value = val;}
        Node* Next() { return next; }
        void Setnext(Node* val) {next = val;}

    private:
        float value;
        Node* next;
};

#endif // NODE_H

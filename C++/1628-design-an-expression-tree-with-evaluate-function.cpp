// Tags: Tree Design Amazon Premium OOP
// Time: O(n)
// Space: O(n)
/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */
// abstract class, cannot be instantiated
class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
    // define your fields here
};

class numNode : public Node {
protected:
    int _val;
public:
    numNode(int val): _val(val) {
        
    }
    int evaluate() const {
        return _val;
    }
};

class opNode : public Node {
protected:
    char _op;
    Node* _left;
    Node* _right;
public:
    opNode(char op, Node* left, Node* right): _op(op), _left(left), _right(right) {
        
    }
    int evaluate() const;
    // to avoid memory leak
    ~opNode() {
        delete _left;
        delete _right;
    }
};

int opNode::evaluate() const {
    switch(_op) {
        case '+':
            return _left->evaluate() + _right->evaluate();
        case '-':
            return _left->evaluate() - _right->evaluate();
        case '/':
            return _left->evaluate() / _right->evaluate();
        case '*':
            return _left->evaluate() * _right->evaluate();
        default:
            return 0;
    }
}



/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */
class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        // abstract base pointer for all derived classes
        stack<Node*> st;
        for (auto s : postfix) {
            if (isdigit(s[0])) {
                st.push(new numNode(stoi(s)));
            } else {
                auto r = st.top(); st.pop();
                auto l = st.top();
                st.top() = new opNode(s[0], l, r);
            }
        }
        return st.top();
    }
};

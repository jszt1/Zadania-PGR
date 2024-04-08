#include <initializer_list>
class Node {
private:
  Node *previous;
  Node *prevMinItem;
  int data;

protected:
  Node();
  Node(int &&d, Node *prev = nullptr, Node *minItem = nullptr);
  Node(const int &, Node *prev = nullptr, Node *minItem = nullptr);
  void setData(int &&);
  void setData(const int &);
  void setPrevious(Node *prev);
  Node *getPrevious() const;
  int getData() const;
  Node *getPrevMinItem() const;
  ~Node();

  friend class MinStack;
};

class MinStack {
  Node *lastItem;
  Node *minItem;
  std::size_t sz;

public:
  MinStack();
  MinStack(std::initializer_list<int>);
  void push(int &&);
  void push(const int &);
  int pop();
  int top() const;
  int getMin() const;
  std::size_t size() const;
  bool empty() const;
  void print() const;
  ~MinStack();
};

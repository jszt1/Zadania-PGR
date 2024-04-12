#include "MinStack.h"

#include <iostream>

Node::Node() : previous(nullptr) {}
Node::Node(int &&d, Node *prev, Node *minItem)
    : previous(prev), data(d), prevMinItem(minItem) {}
Node::Node(const int &d, Node *prev, Node *minItem)
    : previous(prev), data(d), prevMinItem(minItem) {}
void Node::setData(int &&d) { data = d; }
void Node::setData(const int &d) { this->data = d; }
void Node::setPrevious(Node *prev) { previous = prev; }
Node *Node::getPrevious() const { return previous; }
int Node::getData() const { return data; }
Node *Node::getPrevMinItem() const { return prevMinItem; }
Node::~Node() {}

MinStack::MinStack() : lastItem(nullptr), sz(0), minItem(nullptr) {}
MinStack::MinStack(std::initializer_list<int> list) {
  sz = 0;
  lastItem = minItem = nullptr;
  for (auto i : list) {
    this->push(i);
    if (minItem == nullptr) {
      minItem = lastItem;
    } else if (lastItem->getData() < minItem->getData()) {
      minItem = lastItem;
    }
  }
}
void MinStack::push(int &&d) {
  lastItem = new Node(d, lastItem, minItem);
  if (minItem == nullptr) {
    minItem = lastItem;
  } else {
    if (d < minItem->getData()) {
      minItem = lastItem;
    }
  }
  sz++;
}
void MinStack::push(const int &d) {
  lastItem = new Node(d, lastItem, minItem);
  if (minItem == nullptr) {
    minItem = lastItem;
  } else {
    if (d < minItem->getData()) {
      minItem = lastItem;
    }
  }
  sz++;
}

int MinStack::pop() {
  if (sz > 0) {
    Node *tempItem = lastItem->getPrevious();
    if (lastItem == minItem) {
      minItem = lastItem->getPrevMinItem();
    }
    int returnData = lastItem->getData();
    delete lastItem;
    lastItem = tempItem;
    sz--;
    return returnData;
  } else {
    std::cout << "Stack is empty!" << std::endl;
    return 0;
  }
}
int MinStack::top() const {
  if (sz > 0)
    return lastItem->getData();
  else {
    std::cout << "Stack is empty!" << std::endl;
    return 0;
  }
}
int MinStack::getMin() const {
  if (sz > 0) {
    return minItem->getData();
  } else {
    std::cout << "Stack is empty!" << std::endl;
    return 0;
  }
}

std::size_t MinStack::size() const { return sz; }
bool MinStack::empty() const { return lastItem == nullptr ? 1 : 0; }

MinStack::~MinStack() {
  while (this->empty()) {
    this->pop();
    sz--;
  }
}

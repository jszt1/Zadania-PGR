#include <iostream>

#include "MinStack.h"
int main() {
  MinStack *StackMin = new MinStack();
  StackMin->push(10);
  StackMin->push(-12);
  StackMin->push(22);
  std::cout << StackMin->getMin() << std::endl; // pokaże -12
  StackMin->pop();
  std::cout << StackMin->top() << std::endl;    // pokaże -12
  std::cout << StackMin->getMin() << std::endl; // pokaże -12

  delete StackMin;

  MinStack s1({1, 2, 3, 4, 5, 7, 10, -14, -28});
  std::cout << s1.size() << std::endl;
  std::cout << s1.getMin() << std::endl;

  return 0;
}

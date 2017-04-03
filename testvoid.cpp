#include <iostream>
#include <functional>
int main() {
  std::function<void(int)> f = [](int a) {
    printf("RES: %d\n", a * a);
  };

  std::function<void(int)>* g = &f;

//  (void)f(2);
//  (*g)(2);

}
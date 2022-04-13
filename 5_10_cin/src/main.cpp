#include <iostream>

int getInt() {
  int input;

  while (1) {
    std::cout << "Enter Int Number : ";
    std::cin >> input;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(32767, '\n');
      std::cout << "Invalid Number, Try again" << std::endl;
    } else {
      std::cin.ignore(32767, '\n');
      return input;
    }
  }
}

char getOperator() {
  char op;

  while (1) {
    std::cout << "Enter an Operator (+,-,*,/) : ";
    std::cin >> op;

    std::cin.ignore(32767, '\n');

    if (op == '+' || op == '-' || op == '*' || op == '/') {
      return op;
    } else {
      std::cout << "Invalid Operator!!" << std::endl;
    }
  }

  return op;
}

int printResult(int x, int y, char op) {
  std::cout << "result : ";

  switch (op) {
  case '+':
    std::cout << x + y << std::endl;
    break;
  case '-':
    std::cout << x - y << std::endl;
    break;
  case '*':
    std::cout << x * y << std::endl;
    break;
  case '/':
    std::cout << x / y << std::endl;
    break;
  default:
    break;
  }
}

int main() {

  while (1) {
    std::cout << "======= Calculator Start ======= " << std::endl;
    std::cout << "type ctrl + c to Exit" << std::endl;
    int x = getInt();
    char ch = getOperator();
    int y = getInt();

    printResult(x, y, ch);
  }

  return 0;
}

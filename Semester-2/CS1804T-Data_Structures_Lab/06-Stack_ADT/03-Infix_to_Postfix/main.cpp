#include "LLStack.cpp"
#include <iostream>

// Function to check if a character is an operand
bool isOperand(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
         (c >= '0' && c <= '9');
}

// Function to get precedence of operators
int precedence(char op) {
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  if (op == '^')
    return 3;
  return -1;
}

// Function to convert infix expression to postfix
void infixToPostfix(const char *infix, char *postfix) {
  LLStack stack;
  int k = 0;

  for (int i = 0; infix[i] != '\0'; i++) {
    char c = infix[i];

    // If character is operand, add to output
    if (isOperand(c)) {
      postfix[k++] = c;
    }
    // If character is an opening bracket, push to stack
    else if (c == '(') {
      stack.push(c);
    }
    // If character is a closing bracket, pop until opening bracket
    else if (c == ')') {
      while (!stack.isEmpty() && stack.peek() != '(') {
        postfix[k++] = stack.pop();
      }
      if (!stack.isEmpty() && stack.peek() == '(') {
        stack.pop(); // Discard opening bracket
      }
    }
    // If character is an operator
    else {
      while (!stack.isEmpty() && stack.peek() != '(' &&
             precedence(c) <= precedence(stack.peek())) {
        postfix[k++] = stack.pop();
      }
      stack.push(c);
    }
  }

  // Pop remaining operators from stack
  while (!stack.isEmpty()) {
    postfix[k++] = stack.pop();
  }

  postfix[k] = '\0'; // Null-terminate the postfix expression
}

// Function to evaluate a postfix expression
int evaluatePostfix(const char *postfix) {
  LLStack stack;

  for (int i = 0; postfix[i] != '\0'; i++) {
    char c = postfix[i];

    // If character is operand, push to stack
    if (c >= '0' && c <= '9') {
      stack.push(c - '0'); // Convert char to int
    }
    // If character is an operator, pop two elements and apply operator
    else {
      int val2 = stack.pop();
      int val1 = stack.pop();

      switch (c) {
      case '+':
        stack.push(val1 + val2);
        break;
      case '-':
        stack.push(val1 - val2);
        break;
      case '*':
        stack.push(val1 * val2);
        break;
      case '/':
        stack.push(val1 / val2);
        break;
      case '^': {
        int result = 1;
        for (int j = 0; j < val2; j++) {
          result *= val1;
        }
        stack.push(result);
        break;
      }
      }
    }
  }

  return stack.pop(); // Result of the postfix expression
}

int main(int argc, char *argv[]) {
  LLStack stack;

  // Take input from user
  char infix[100];
  std::cout << "Enter an infix expression: ";
  std::cin >> infix;

  char postfix[100];

  infixToPostfix(infix, postfix);

  std::cout << "Infix: " << infix << std::endl;
  std::cout << "Postfix: " << postfix << std::endl;

  int result = evaluatePostfix(postfix);
  std::cout << "Result: " << result << std::endl;

  return 0;
}

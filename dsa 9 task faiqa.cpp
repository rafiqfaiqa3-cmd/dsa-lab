
#include <iostream>
#include <string>
using namespace std;

#define MAX 5

// ================= STACK PROGRAM =================

int stackArr[MAX];
int top = -1;

// Push function
void push(int x) {
    if (top == MAX - 1) {
        cout << "Stack overflow!" << endl;
    }
    else {
        stackArr[++top] = x;
        cout << x << " pushed into stack." << endl;
    }
}

// Pop function
int pop() {
    if (top == -1) {
        cout << "Stack underflow!" << endl;
        return -1;
    }
    else {
        return stackArr[top--];
    }
}

// Search function
int search(int x) {
    int steps = 1;

    for (int i = top; i >= 0; i--) {
        if (stackArr[i] == x) {
            return steps;
        }
        steps++;
    }

    return -1;
}

// ================= INFIX TO POSTFIX =================

int precedence(char op) {
    if (op == '*' || op == '/') {
        return 2;
    }
    else if (op == '+' || op == '-') {
        return 1;
    }
    return 0;
}

void infixToPostfix(string infix) {
    char operators[100];
    int t = -1;
    string postfix = "";

    cout << "\nInfix Expression: " << infix << endl;

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (ch >= 'A' && ch <= 'Z') {
            postfix += ch;
        }
        else if (ch == '(') {
            operators[++t] = ch;
        }
        else if (ch == ')') {
            while (t != -1 && operators[t] != '(') {
                postfix += operators[t--];
            }
            if (t != -1) {
                t--; // Remove opening bracket
            }
        }
        else {
            while (t != -1 && operators[t] != '(' &&
                   precedence(operators[t]) >= precedence(ch)) {
                postfix += operators[t--];
            }

            operators[++t] = ch;
        }

        cout << "Scanned: " << ch
             << " | Stack: ";

        for (int j = 0; j <= t; j++) {
            cout << operators[j];
        }

        cout << " | Postfix: " << postfix << endl;
    }

    // Empty remaining stack
    while (t != -1) {
        postfix += operators[t--];
    }

    cout << "Final Postfix: " << postfix << endl;
}

// ================= MAIN FUNCTION =================

int main() {

    // TASK 1: Conversion
    cout << "===== TASK 1: INFIX TO POSTFIX =====" << endl;

    infixToPostfix("A+B*C");
    infixToPostfix("(A-B)*C");
    infixToPostfix("A*B+C/D");

    // TASK 2: Dry Run
    cout << "\n===== TASK 2: DRY RUN =====" << endl;

    infixToPostfix("(A+B)*C");

    // TASK 3: Array Stack
    cout << "\n===== TASK 3: STACK PROGRAM =====" << endl;

    int value;

    cout << "\nEnter five integers:" << endl;

    for (int i = 0; i < MAX; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        push(value);
    }

    // Try sixth push
    cout << "\nTrying to push sixth value..." << endl;
    push(100);

    // Search while stack contains values
    cout << "\n===== SEARCH =====" << endl;

    int present, absent;

    cout << "Enter a value to search (present): ";
    cin >> present;

    int result = search(present);

    if (result != -1) {
        cout << "Found at " << result
             << " step(s) from the top." << endl;
    }
    else {
        cout << "Value not found." << endl;
    }

    cout << "Enter a value to search (absent): ";
    cin >> absent;

    result = search(absent);

    if (result != -1) {
        cout << "Found at " << result
             << " step(s) from the top." << endl;
    }
    else {
        cout << "Value not found." << endl;
    }

    // Pop all items
    cout << "\n===== POP OPERATIONS =====" << endl;

    while (top != -1) {
        cout << "Popped: " << pop() << endl;
    }

    // Try another pop
    cout << "\nTrying to pop from empty stack:" << endl;
    pop();

    return 0;
}

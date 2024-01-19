#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

char peek() {
    return stack[top];
}

void push(char op) {
    stack[++top] = op;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void infixToPostfix(char *infix, char *postfix) {
    int i, j;
    char ch, popped;

    push('(');
    strcat(infix, ")");

    i = 0;
    j = 0;
    ch = infix[i];

    while (ch != '\0') {
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (isOperator(ch)) {
            popped = pop();
            while (precedence(popped) >= precedence(ch)) {
                postfix[j++] = popped;
                popped = pop();
            }
            push(popped);
            push(ch);
        } else if (ch == ')') {
            popped = pop();
            while (popped != '(') {
                postfix[j++] = popped;
                popped = pop();
            }
        } else {
            printf("Invalid infix Expression.\n");
            exit(1);
        }
        i++;
        ch = infix[i];
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter the infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s", postfix);

    return 0;
}

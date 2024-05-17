#include <stdio.h>
#include "Stack.h"

void createStack(Stack *stack) {
//    (*STACK).DATA=-1
    stack->top = -1;
}

int isStackEmpty(Stack stack) {
    return stack.top == -1;
}

int isStackFull(Stack stack) {
    return stack.top == MAX_STACK_SIZE - 1;
}

void push(Stack *stack, Type value) {
    if (isStackFull(*stack)) {
        printf("Stack overflow. Cannot push.\n");
        return;
    }
    stack->data[++stack->top] = value;
}

Type pop(Stack *stack) {
    if (isStackEmpty(*stack)) {
        printf("Stack underflow. Cannot pop.\n");
        return -1;
    }

    Type value = stack->data[stack->top--];
    return value;
}

Type peek(Stack stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }

    return stack.data[stack.top];
}

void displayStack(Stack stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack contents:\n");
    for (int i = stack.top; i >= 0; i--) {
        printf("%d\n", stack.data[i]);
    }
}
/*int evaluatePostfix(char expression[])
{
    Stack myStack;
    createStack(&myStack);
    for (int p=0; expression[p]!='\0'; p++)
    {
        if (isdigit(expression[p]))
        {
            push(&myStack,(int)expression[p]-'0');
        }
        else
        {
            int operand2 = pop(&myStack);
            int operand1 = pop(&myStack);
            switch (expression[p])
            {
            case '+':
                push(&myStack, operand1 + operand2);
                break;
            case '-':
                push(&myStack, operand1 - operand2);
                break;
            case '*':
                push(&myStack, operand1 * operand2);
                break;
            case '/':
                push(&myStack, operand1 / operand2);
                break;
            case '^':
                push(&myStack, pow(operand1,operand2));
                break;
            default:
                printf("Invalid operator: %c\n", expression[p]);
                exit();
            }
        }
    }
    return pop(&myStack);
}
*/
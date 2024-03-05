#include <iostream>
using namespace std;
/*#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define size 10
int stack[size], top;
void push(int[], int);
void pop(int[]);
void peek(int[]);
void display(int[]);
struct Stack
{
    int top;
    int maxsize;
    int *arr;
};
struct Stack *create(int num)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->maxsize = num;
    stack->arr = (int *)malloc(stack->maxsize * sizeof(int));
    return stack;
}
int isfull(struct Stack *s)
{
    if (s->top == s->maxsize - 1)
    {
        printf("Stack Overflow");
    }
    return s->top == s->maxsize - 1;
}
int isemp(struct Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow");
    }
    return s->top == -1;
}
void push(struct Stack *s, int item)
{
    if (isfull(s))
    {
        return;
    }
    s->arr[++s->top] = item;
    printf("%d is pushed in stack\n", item);
}
int pop(struct Stack *s)
{
    if (isemp(s))
    {
        return INT_MIN;
    }
    printf("%d is popped from stack\n", s->arr[s->top]);
    return s->arr[s->top--];
}
int peek(struct Stack *s)
{
    if (isemp(s))
    {
        return INT_MIN;
    }
    return s->arr[s->top];
}
int size(struct Stack *s)
{
    return s->top + 1;
}
int main()
{
    struct Stack *s = create(10);
    push(s, 5);
    push(s, 10);
    push(s, 15);
    printf("%d\n", peek(s));
    printf("%d\n", size(s));
    printf("%d\n", pop(s));
    printf("%d\n", size(s));
    printf("%d\n", isfull(s));
    printf("%d\n", isemp(s));

    return 0;
}

int main()
{
    top = -1;
    int option = 0;
    int num = 0;
    while (1)
    {
        printf("\n1: Push \n2: Pop \n3: Display \n4: Peek \n5: Exit\n Enter one of your choices:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter num to push:");
            scanf("%d", &num);
            push(stack, num);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            display(stack);
            break;
        case 4:
            peek(stack);
            break;
        case 5:
            exit(0);

        default:
            printf("Enter valid option.");
            break;
        }
    }
}
void push(int stack[], int n)
{
    if (top == size - 1)
    {
        printf("Stack Overflow");
        return;
    }
    top++;
    stack[top] = n;
    printf("%d is pushed in stack", n);
}
void pop(int stack[])
{
    if (top == -1)
    {
        printf("Stack Underflow");
        return;
    }
    int del;
    del = stack[top--];
    printf("%d is popped from stack", del);
}
void peek(int stack[])
{
    if (top == -1)
    {
        printf("Empty Stack.\n");
        return;
    }
    printf("Top of stack is: \n%d ", stack[top]);
}
void display(int stack[])
{
    int i = 0;
    if (top == -1)
    {
        printf("Empty Stack .\n");
        return;
    }
    for (i = top; i >= 0; i--)
    {
        printf("%d", stack[i]);
    }
    printf("\n\n");
}*/
class stack
{
    int top;
    int maxsize;
    int *arr;

public:
    stack(int m)
    {
        top = -1;
        maxsize = m;
        arr = new int[maxsize];
    }
    void push(int x);
    void pop();
    void display();
    int peek();
    int getmin();
};
void stack::push(int x)
{
    if (top >= maxsize)
    {
        printf("Stack Overflow\n");
        return;
    }
    arr[++top] = x;
    printf("%d is pushed in stack\n", x);
}
void stack::pop()
{
    if (top == -1)
    {
        printf("Stack Underflow");
        return;
    }
    int x = arr[top--];
    printf("%d is popped from stack\n", x);
}
int stack::peek()
{
    return arr[top];
}
void stack::display()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n\n");
}
int stack::getmin()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    int m = arr[top];
    for (int i = top - 1; i >= 0; i--)
    {
        if (m > arr[i])
        {
            m = arr[i];
        }
    }
    cout << " Min Element: " << m << endl;
    return 0;
}
int main()
{
    stack s(5);
    s.push(23);
    s.push(24);
    s.push(12);
    s.push(27);
    s.push(76);
    s.getmin();
    s.pop();
    s.display();

    return 0;
}
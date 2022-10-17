#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#define MAX 100

// A structure to represent a stack 
struct Stack { 
    int top; 
    int maxSize; 
    char* array; 
}; 

struct Stack* create(char max) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->maxSize = max; 
    stack->top = -1; 
    stack->array = (char*)malloc(stack->maxSize * sizeof(char));
    // here above memory for array is being created
    // size would be 10*4 = 40
    return stack; 
}

// Checking with this function is stack is full or not
// Will return true is stack is full else false 
//Stack is full when top is equal to the last index 
int isFull(struct Stack* stack) 
{ 
    if(stack->top == stack->maxSize - 1){
        printf("Will not be able to push maxSize reached\n");
    }
    // Since array starts from 0, and maxSize starts from 1
    return stack->top == stack->maxSize - 1; 
}

// By definition the Stack is empty when top is equal to -1 
// Will return true if top is -1
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
}

// Push function here, inserts value in stack and increments stack top by 1
void push(struct Stack* stack, char item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
}

// Function to remove an item from stack.  It decreases top by 1 
void pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return; 
    
    stack->array[stack->top--]; 
} 

// Function to return the top from stack without removing it 
int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
} 

bool checkPair(char val1,char val2){
    return (( val1=='(' && val2==')' )||( val1=='[' && val2==']' )||( val1=='{' && val2=='}' ));
}

bool checkBalanced(struct Stack* stack, char expr[], int len){
      
    for (int i = 0; i < len; i++)  
    { 
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')  
        {  
          push(stack, expr[i]); 
        } 
        else
        {
            // exp = {{}}}
            // if you look closely above {{}} will be matched with pair, Thus, stack "Empty"
            //but an extra closing parenthesis like '}' will never be matched
            //so there is no point looking forward
        if (isEmpty(stack)) 
            return false;
        else if(checkPair(peek(stack),expr[i]))
        {
            pop(stack);
            continue;
        }
        // will only come here if stack is not empty
        // pair wasn't found and it's some closing parenthesis
        //Example : {{}}(]
        return false;
        }
    }    
    return true; 
}
int main() {
  char exp[MAX];

  printf("Enter the expression : "); scanf("%s",exp);

  int len = strlen(exp);
  struct Stack* stack = create(len); 
  checkBalanced(stack, exp, len)?printf("Balanced"): printf("Not Balanced"); 

  return 0;
}
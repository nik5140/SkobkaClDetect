#ifndef STACK2ARRAY_H_INCLUDED
#define STACK2ARRAY_H_INCLUDED

struct stack_structure
{
    char *elements;
    int last_filled;
} stack_structure;


struct stack_structure Create_stack(int n)
{
    struct stack_structure stack1;
    stack1.last_filled=-1;
    stack1.elements = (char*)malloc(sizeof(char)*n);
    return stack1;
}

void Push_stack(struct stack_structure *stack1, char element)
{
    stack1->elements[stack1->last_filled+1] = element;
    stack1->last_filled++;
}

float Top_stack(struct stack_structure *stack1)
{
   return stack1->elements[stack1->last_filled];
}

int Pop_stack(struct stack_structure *stack1)
{
   if (stack1->last_filled>=0)
   {char popped;
   popped = stack1->elements[stack1->last_filled];
   stack1->elements[stack1->last_filled] = 0;
   stack1->last_filled--;
   return popped;}
   else
   {
        printf("Nothing to return\n");
        return 0;
   }

}

int IsEmpty(struct stack_structure stack1)
{
    if (stack1.last_filled>=0)
        return 0;
    else
        return 1;
}


void ShowStack(struct stack_structure stack1)
{
int n = 0;
printf("[");
while(n<=stack1.last_filled)
{
if (n<stack1.last_filled)
    printf("%c, ", stack1.elements[n]);
else
    printf("%c", stack1.elements[n]);


n++;

}
printf("]");

}

#endif // STACK2ARRAY_H_INCLUDED
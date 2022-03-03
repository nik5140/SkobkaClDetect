#include <stdio.h>
#include <stdlib.h>
#include "stack2Array.h"


int main()
{



    printf("Hello. Char stack here\n");
    int n = 30;
    char c1;
    struct stack_structure S0 = Create_stack(n); // for ()
    struct stack_structure S1 = Create_stack(n); // for []
    struct stack_structure S2 = Create_stack(n); // for {}
    struct stack_structure S3 = Create_stack(n); // for everything


    while(1)
    {
    //printf("enter char\n");
    c1 = getchar();
    Push_stack(&S3,c1);


    if (c1=='(')
        {
        Push_stack(&S0,c1);
        fflush(stdin);
        }
    else if (c1==')'&&IsEmpty(S0)==0)
    {
        if (S0.elements[S0.last_filled]!=')')
            Pop_stack(&S0);
        fflush(stdin);
    }

    else if (c1==')'&&IsEmpty(S0)!=0)
    {
        Push_stack(&S0,c1);
        fflush(stdin);
    }


    if (c1=='[')
        {
        Push_stack(&S1,c1);
        fflush(stdin);
        }
    else if (c1==']'&&IsEmpty(S1)==0)
    {
        if (S1.elements[S1.last_filled]!=']')
                Pop_stack(&S1);
        fflush(stdin);
    }
    else if (c1==']'&&IsEmpty(S1)!=0)
    {
        Push_stack(&S1,c1);
        fflush(stdin);
    }


    if (c1=='{')
        {
        Push_stack(&S2,c1);
        fflush(stdin);
        }
    else if (c1=='}'&&IsEmpty(S2)==0)
    {

        if (S2.elements[S2.last_filled]!='}')
                Pop_stack(&S2);
        fflush(stdin);
    }
    else if (c1=='}'&&IsEmpty(S2)!=0)
    {
        Push_stack(&S2,c1);
        fflush(stdin);
    }


    else if (c1=='0')
        break;

    }

 //   Push_stack(&S,'(');
 //   Push_stack(&S,')');
    printf("\nIf we are talking of all string:\n");
    ShowStack(S3);
    printf("\nIf we are talking of ():\n");
    ShowStack(S0);
    if (IsEmpty(S0))
        printf("all () are closed\n");
    else
        printf("talking of () - not closed\n");

    printf("\nIf we are talking of []:\n");
    ShowStack(S1);
    if (IsEmpty(S1))
        printf("all [] are closed\n");
    else
        printf("talking of [] - not closed\n");

    printf("\nIf we are talking of {}:\n");
    ShowStack(S2);
    if (IsEmpty(S2))
        printf("all {} are closed\n");
    else
        printf("talking of {} - not closed\n");

return 0;
}

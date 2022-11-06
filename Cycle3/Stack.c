// Implement a stack using an array.

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int num;
}element;

element* stack;  
int top=-1,size; // size of stack is the global variable 

void Push(){              //Funnction to Push
    if (top==size-1){
        printf("\n!Stack Overflow!\n");
        return;
    }
    else{
        int item;
        printf("Enter the Element: ");
        scanf("%d",&item);
        stack[++top].num=item;
        printf("\n%d added to the stack\n",item);
        return;
    }
}

void Pop(){                //Function to Pop
    if (top==-1){
        printf("\n!Stack Underflow!\n");
        return;
    }
    else{
        printf("\n%d removed from the stack\n",stack[top].num);
        top=top-1;
        return;
    }
}

void Top(){             //Function to Display top Element
    if (top==-1){
        printf("\nThe Stack is Empty\n");
        return;
    }
    else{
        printf("\nTop Element : %d\n",stack[top].num);
        return;
    }  
}

void main(){

    int option;
    printf("Enter the Size of the Stack : ");
    scanf("%d",&size);
    printf("Size of Stack=%d\n",size);

    // dynamic memory allocation using malloc
    stack=(element*)malloc(size*sizeof(element));    //datatype=element

    //Continuous For loop
    while (1){
        printf("\n-------------------------------------------------\n");
        printf("1 : push\n");
        printf("2 : pop\n");
        printf("3 : top\n");
        printf("4 : exit\n");
        printf("\n-------------------------------------------------\n");

        printf("Enter Your Option: ");
        scanf("%d",&option);

        switch (option){
        case 1:
            Push();
            break;
        case 2:
            Pop();
            break;
        case 3:
            Top();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("!!Enter a Valid Option!!\n");
            break;
        }
    }
}

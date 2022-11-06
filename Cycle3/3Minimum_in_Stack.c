//Find the minimum element in a stack in O(1) time using an auxiliary stack
//which keeps track of the minimum element.

#include<stdio.h>
#include<stdlib.h>
#define Max_Size 5

typedef struct{
    int num;
}stack;

//Declaring Stack and Auxilary Stack.
stack s[Max_Size],aux[Max_Size]; 
int Top=-1;
int auxTop=-1;


//Function to Push
void push(int element){

    if (Top==Max_Size-1){
        printf("\nStack is Full\n");
    }
    else{
        s[++Top].num=element;
        printf("\n%d added to Stack\n",s[Top].num);

        if (auxTop==-1){
            //if the Auxilary Stack is empty then push the element into it
            //First element in aux is minimum by default.
            aux[++auxTop].num=element;
        }
        else{
            //push the element into the Auxilary Stack
            //if it is less than or equal to the current minimum.
            if (element<=aux[auxTop].num){
                aux[++auxTop].num=element;
            }   
        }
    }
}

//Function to Pop
void pop(){

    if (Top==-1){
        printf("\nStack is Empty\n");
    }
    else{
        int del=s[Top].num;         //Deleted element
        Top=Top-1;                  // Decrementing Top

        if (del==aux[auxTop].num){
            auxTop--;
        }
        printf("\n%d Deleted from the Stack\n",del);
    } 
}

//Function to Display Stack
void display(){

    if (Top==-1){
        printf("\nStack is Empty\n");
    }
    else{
        printf("Stack: ");
        for (int i = 0; i <= Top; i++){
            printf("%d ",s[i].num);
        }
    }
}

//Function to Display Minimum
void min(){
    if (auxTop==-1){
        printf("\nStack is Empty\n");
    }
    else{
        printf("\nThe Minimum Element in the Stack: %d\n",aux[auxTop].num);
    }   
}


void main(){

    int option;
    //Continuous For loop
    while (1){
        printf("\n+-------------------------------------------------+\n");
        printf("|    1 : push                                       |\n");
        printf("|    2 : pop                                        |\n");
        printf("|    3 : Find Minimum Element                       |\n");
        printf("|    4 : Display Stack                              |\n");
        printf("|    5 : exit                                       |\n");
        printf("\n+--------------------------------------------------+\n");

        printf("Enter Your Option: ");
        scanf("%d",&option);

        switch (option){
        case 1:
            int element;
            printf("\nEnter Element: ");
            scanf("%d",&element);
            push(element);
            break;
        case 2:
            pop();
            break;
        case 3:
            min();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        
        default:
            printf("\n!!Enter a Valid Option!!\n");
            break;
        }
    }
}

//implement a sorted push so that stack is always maintained in sorted order.

#include<stdio.h>
#include<stdlib.h>


#define Max_Size 50
int stack[Max_Size];
int top=-1;

// Temporary Stack
int tempstack[Max_Size];
int temptop=-1;

// Function to Pop elements from the stack
int pop(){
    if (top==-1){
        printf("Stack Underflow\n");
    }
    else{
        int del=stack[top];
        top--;
        return del;
    }
}

// Function to do a Sorted Push into the stack
void push(int element){
    if (top==Max_Size-1){
        printf("Stack Overflow");
    }
    else{
         //Sorting stack in descending order
        while (element>stack[top] && top!=-1){
            tempstack[++temptop]=pop();
        }
        stack[++top]=element;

        while (temptop>-1){
            stack[++top]=tempstack[temptop--];
        }    
    }
}



// Function to Display The Stack
void display(){
    if (top==-1){
        printf("Stack Underflow\n");
    }
    else{
        for (int i = 0; i <= top; i++){
            printf("%d ",stack[i]);
        }
    }
}


//Main Function

int main(){

    int option;
    //Continuous while loop
    while (1){
        printf("\n-------------------------------------------------\n");
        printf("1 : push\n");
        printf("2 : pop\n");
        printf("3 : display\n");
        printf("4 : exit\n");
        printf("\n-------------------------------------------------\n");

        printf("Enter Your Option: ");
        scanf("%d",&option);

        switch (option){
        case 1:
            int num;
            printf("Enter the Element to Push: ");
            scanf("%d",&num);
            push(num);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("Stack : ");
            display();
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

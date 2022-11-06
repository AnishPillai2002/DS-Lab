//Convert a given decimal number into binary and hex.
 
#include<stdio.h>
#define Max_Size 100

int stack[Max_Size];
int top=-1;

// Push Function
void push(int item){
    if (top==Max_Size-1){
        printf("\nStack is Full\n");
    }
    else{
        stack[++top]=item;
    }
}

// Pop Function
int pop(){
    if (top==-1){
        printf("\nStack is Empty\n");
    }
    else{
        int del=stack[top];
        top--;
        return del;                 //returns the deleted element
    } 
}

// Converting the Number to Binary using Stack
void toBinary(int num){
    while (num){                    //Adding remainders into the stack
        push(num%2);
        num=num/2;
    }
    printf("\nBinary : ");
    while(top!=-1){
        printf("%d",pop());         //Printing the remainders in reverse order using pop() 
    }
    printf("\n");  
}

//Converting the Number to Hexadecimal using Stack
void toHex(int num){
    while (num!=0){
        push(num%16);
        num=num/16;
    }
    printf("Hexadecimal: ");
    while (top!=-1){
        int h=pop();
        switch (h){
        case 10:
            printf("A");
            break;
        case 11:
            printf("B");
            break;
        case 12:
            printf("C");
            break;
        case 13:
            printf("D");
            break;
        case 14:
            printf("E");
            break;
        case 15:
            printf("F");
            break;

        default:
            printf("%d",h);
            break;
        }
    }
    printf("\n"); 
}

void main(){
    int num;
    printf("Enter the Number: ");
    scanf("%d",&num);
    toBinary(num);
    toHex(num);
}

// Check whether the parenthesis are balanced in an expression.


#include<stdio.h>
#include<string.h>
#define Max_Size 50

char stack[Max_Size];
int top=-1;

// Function to Push
void Push(char element){
    if (top==Max_Size){
        printf("\nStack is Full\n");
    }
    else{
        stack[++top]=element;
    }
}

// Function to Pop
char Pop(){
    if (top==-1){
        printf("\nStack is Empty\n");
    }
    else{
        char del=stack[top];
        top--;
        return del;
    }
}


int isOpening(char element){
    if (element=='('){
        return 1;
    }
    else{
        return 0;
    }
}

int isClosing(char element){
    if (element==')'){
        return 1;
    }
    else{
        return 0;
    }
}

int isMatching(char e1,char e2 ){
    if (e1=='(' && e2==')'){
        return 1;
    }
    else{
        return 0;
    }
}


int isBalanced(char expr[]){
    int i;
    while (expr[i]!='\0'){
        
        // Checking whether expr[i] is an Opening Paranthesis 
        if (isOpening(expr[i])){  // Pushes the Opening Paranthesis into stack[]
            Push(expr[i]);
        }

        // Checking whether expr[i] is a Closing Paranthesis 
        else if (isClosing){     
            
            // Checking Unbalanced Condition
            if (top==-1){          // if the stack[] is empty and we find closing bracket then return 0
                return 0;
            }
            else{

                if (isMatching(Pop(),expr[i])){
                    // Pop()==stack[top]
                    // if the opening bracket matches with closing bracket continue the process.
                    // Pop() removes the opening Paranthesis from the stack
                }
                else{
                    // if the opening bracket dosent match with closing bracket
                    return 0;
                }  
            }
        }
        i++;
    }

    // if Stack is Empty on reaching expression end return 1
    if (top==-1){
        return 1;
    }
    else{
        // Stack not empty eg: (
        return 0;
    }
}



void main(){
    char expr[Max_Size];
    printf("Enter the Expression: ");
    scanf("%s",expr);
    if (isBalanced(expr)){
        printf("\nParanthesis are Balanced \n");
    }
    else{
        printf("\nParanthesis are not Balanced\n");
    }
}

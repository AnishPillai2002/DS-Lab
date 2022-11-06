// Convert a given infix expression to postfix/prefix

#include<stdio.h>
#include<string.h>
#include<ctype.h> //ctype.h provides isalnum() function

// Stack is Global character array
#define Max_Size 100
char stack[Max_Size];  
int top=-1;

// Function to Push into stack
void push(char element){
    if (top==Max_Size){
        printf("Stack is Full\n");
    }
    else{
        stack[++top]=element;
    }
}

//Function to Pop from stack
int pop(){
    if (top==-1){
        printf("Stack is Empty\n");
    }
    else{
        int del=stack[top];
        top--;
        return del;
    }  
}


//Function to decide the Precedence of an Operator
int operatorPrec(char op){
   
    if (op=='+'||op=='-'){
        return 1;
    }
    else if (op=='*' || op=='/'){
        return 2;
    }
    else if (op=='^'){
        return 3;
    }
    else{
        return 0;
    }
}


// Function to convert Infix to Postfix
void InfixtoPostfix(char expression[]){

    push('#');
    int i=0;    //counter for Infix Expression
    int j=0;    //counter for Postfix Expression

    while (expression[i]!='\0'){

        // op represent each character in the Infix Expression
        char op=expression[i];

        // Checking op is alphanumeric or not
        if (isalnum(op)){
            printf("%c",op);
            
        }
        // Checking op is Opening Paranthesis or not
        else if (op=='('){
            push(op);
        }
        // Checking op is Closing Paranthesis or not
        else if (op==')'){
            
            char op_inside_paranthesis;
            // Poping all operators inside a paranthesis
            while ((op_inside_paranthesis=pop())!='('){
                printf("%c",op_inside_paranthesis);
                
            }
        }

        else{

            //If the priority of op is less than the top of stack then
            // all the elements in stack is poped into postfix array
            while (operatorPrec(stack[top])>=operatorPrec(op)){
              printf("%c",pop());
            }
            push(op);
        }
        i++;
    }

    // Pushing all remaining elements in stack into the postfix array
    while (stack[top]!='#'){
        
        printf("%c",pop());
    }      
}     
        

// Main function
int main(){
    char postfix[Max_Size];
    char expression[Max_Size];

    printf("Enter the Infix Expression : ");
    scanf("%s",expression);
    printf("The Postfix Expression: ");
    InfixtoPostfix(expression);
    
}

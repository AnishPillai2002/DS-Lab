// Evaluate a postfix/prefix expression.

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define Max_Size 50
int stack[Max_Size];
int top=-1;

//Function to Push into stack
void push(int element){
    if (top==Max_Size-1){
        printf("Stack Overflow\n");
    }
    else{
        stack[++top]=element;
    }
}

//Function to Pop from stack
int pop(){
    if (top==-1){
        printf("Stack Under Flow\n");
    }
    else{
        int del= stack[top];
        top--;
        return del;
    }
}

// Function to evaluate a Postfix Expression
int PostfixEval(char expression[]){

    int n1,n2,num;
    char ch;             //each character in Postfix expression

    int i=0;
    while (expression[i]!='\0'){

        ch=expression[i]; // Assigning value to ch

        if (isdigit(ch)){ 
            //converting char type digit(ch) into integer
            // Difference form ASCII value of 0 gives the ASCII value of ch
            num=ch-'0';   
            push(num);
        }

        else{
            n1=pop();
            n2=pop();

            switch (ch){
            case '+':
                num=n1+n2;
                break;
            case '-':
                num=n2-n1;    // ** n2-n1
                break;
            case '*':
                num=n1*n2; 
                break;
            case '/':
                num=n2/n1;    // ** n2/n1
                break;
            case '^':
                num=n2^n1;    // **n2^n1
                break;
            }
            push(num);
        }
        i++;
    }

    // At the end the result of the Postfix Expression will be 
    // remaining in the stack, so we pop it to get the result
    return pop();
}

// Main Function
int main(){
    
    char expression[Max_Size];
    printf("Enter the Postfix Expression: ");
    scanf("%s",expression);
    printf("The Result of the expression %s = ",expression);
    int x=PostfixEval(expression);
    printf("%d",x);
}

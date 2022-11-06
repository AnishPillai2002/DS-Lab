//Check whether a string is palindrome.

#include<stdio.h>
#include<string.h>
#define Max_Size 50

char stack[Max_Size];
int top=-1;

void Push(char element){
    if (top==Max_Size-1){
        printf("\nStack is Full\n");
    }
    else{
        stack[++top]=element;
    }
}

char Pop(){
    if (top==-1){
        printf("\nStack is Empty\n");
    }
    else{
        char del=stack[top];
        top=top-1;
        return del;
    }
}

int isPalindrome(char str[]){

    int l=strlen(str);
    int mid=l/2;
    int i;
    for (i = 0; i < mid; i++){
        Push(str[i]);
    }
    if (l%2!=0){
        i++;
    }
    
    while (str[i]!='\0'){
        
        if (str[i]!=Pop()){
            return 0;
        }
        i++;
    }
    return 1;
}




int main(){
    char str[Max_Size];
    printf("Enter the String: ");
    scanf("%[^\n]",str);
    
    if(isPalindrome(str)){
        printf("String is a Palindrome\n");
    }
    else{
        printf("String is not a Palindrome\n");
    }

}

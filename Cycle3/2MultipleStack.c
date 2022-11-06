//Implement multiple stacks(2 stacks) using an array. Consider memory
//efficient implementation

#include<stdio.h>
#include<stdlib.h>
#define Max_Size 10

int Stack[Max_Size];  // Declaring single array for Stack1 and Stack2

int top1=-1;
int top2=Max_Size;

// Function to Push
void Push(int stack_number,int item){
    
    if (stack_number==1){  //for Stack1     
        if (top1==top2-1){
            printf("\nStack 1 is Full\n");
        }
        else{
            Stack[++top1]=item;
            printf("%d added to Stack1",item);
        }
    }

    else if (stack_number==2){ //for Stack2
        if (top2==top1+1){
            printf("\nStack 2 is Full\n");
        }
        else{
            Stack[--top2]=item;
            printf("%d added to Stack2",item);
        }   
    }
}

// Function to Pop
void Pop(int stack_number){
    if (stack_number==1){
        if (top1==-1){        // Stack1 empty condition
            printf("\nStack1 is Empty\n");
        }
        else{
            printf("\n%d removed from Stack1\n",Stack[top1]);
            top1=top1-1;
        }     
    }

    else if (stack_number==2){
        if (top2==Max_Size){  // Stack2 empty condition
            printf("\nStack2 is Empty\n");
        }
        else{
            printf("\n%d removed from Stack2\n",Stack[top2]);
            top2=top2+1;
        }    
    }
}

// Function to Display Stack
void display(int stack_number){

    if (stack_number==1){                     //for Stack1
        if (top1==-1){                        //Stack1 empty condition
            printf("\nStack1 is Empty\n");
            return;                           // use return since there is no else part.
        }
        printf("Stack1: ");
        for (int i=0; i<=top1; i++){
            printf("%d ",Stack[i]);
        }
        printf("\n");
    }

    else if (stack_number==2){                //for Stack2
        if (top2==Max_Size){                  //Stack2 empty condition
            printf("\nStack2 is Empty\n");
            return;
        }
        printf("Stack2: ");
        for (int i=Max_Size-1; i>=top2; i--){
            printf("%d ",Stack[i]);
        }
        printf("\n");
    }   
}

int main(){

    int stack_number=1; // by default Stack1 is selected
    int option,item;

    //Non terminating loop
    while (1){
        printf("\n+------------------------------------------------+\n");
          printf("|  1: Select/Change Stack                        |\n");
          printf("|  2: Push                                       |\n");
          printf("|  3: Pop                                        |\n");
          printf("|  4: Display                                    |\n");
          printf("|  5: Exit                                       |\n");
        printf("\n+------------------------------------------------+\n");
        printf("Choose Option: ");
        scanf("%d",&option);

        switch (option){
        
        case 1:
            printf("\n+------------------------------------------------+\n");
            printf("\n|           1 : Stack1  | 2 : Stack2             |\n");
            printf("\n+------------------------------------------------+\n");
            printf("Select the Stack: ");
            scanf("%d",&stack_number);
            break;
        case 2:
            printf("\nEnter the Element: ");
            scanf("%d",&item);
            Push(stack_number,item);
            break;
        case 3:
            Pop(stack_number);
            break;
        case 4:
            display(stack_number);
            break;
        case 5:
            exit(0);
        
        default:
            printf("\n!!Enter a Valid Option!!\n");
            break;
        }
    }
    
}

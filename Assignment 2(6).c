/*
Check whether the given matrix is sparse symmetric using the
representation given
*/


#include<stdio.h>

typedef struct {
    int row;
    int col;
    int value;
}sparse;

int readsparse(sparse s[]){         // Reading a Sparse Matrix

    int r,c,element;
    printf("Enter the Number of ROWS of Matrix : ");
    scanf("%d",&r);
    printf("Enter the Number of COLUMNS Matrix : ");
    scanf("%d",&c);

    s[0].row=r;
    s[0].col=c;
    
    int k=1;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            printf("Enter Element A%d%d: ",i+1,j+1);
            scanf("%d",&element);

            if (element != 0){
                
                s[k].row=i;
                s[k].col=j;
                s[k].value=element;
                k++;
            }   
        }     
    }
    s[0].value=k-1;

}

void printsparse(sparse s[]){               // Function to print sparse matrix representation   
         printf("ROW  COLUMNS  VALUE\n");   // total = total no. of elements in sparse s[]

        int total=s[0].value+1;
        for (int i = 0; i < total; i++){
            printf(" %d      %d        %d\n",s[i].row,s[i].col,s[i].value);
        }
}

void printmatrix(sparse s[]){
    int k=1;
    for (int i = 0; i < s[0].row; i++){     // row=s[0].row
        for (int j = 0; j < s[0].col; j++){  // col=s[0].col

            if (s[k].row==i && s[k].col==j){
                printf("%d  ",s[k].value);
                k++;
            }
            else{
                printf("%d  ",0);
            }    
        }
        printf("\n");
    }
}

int sparSymmetric(sparse s[]){

    int flag;
    int count=s[0].value;

    for (int i = 0; i <= count; i++){ 
        flag=0;
        for (int j = 0; j <= count; j++){    // In 1 iteration itself we can find out if its not symmetric 
            if (s[i].row==s[j].col && s[i].col==s[j].row && s[i].value==s[j].value){
                flag=1;
                break;
            }    
        }
        if (flag==0){
            printf("Not Sparse Symmetric\n");
            return 0;
        }    
    }
    printf("Sparse Symmetric");
    return 1;
    
}

int main(){

    sparse s[100];     

    printf("Enter the Matrix Details : \n");
    readsparse(s);          
    printf("\nThe Matrix is: \n");
    printmatrix(s);
    printf("The Sparse Matrix Representation is: \n");
    printsparse(s);
    printf("\n");
    sparSymmetric(s);
}

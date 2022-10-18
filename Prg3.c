/*
Given a sparse matrix. Represent and store it using an efficient
method. Also find the sparsity (The sparsity of a matrix can be
quantified with a score, which is the number of zero values in the
matrix divided by the total number of elements in the matrix.)
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

void printsparse(sparse s[]){                // Function to print sparse matrix representation   
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

int main(){

    sparse s[30];

    printf("Enter the Matrix: \n");
    readsparse(s);
    printf("The Matrix is:\n");
    printmatrix(s);

    printf("The sparse representation is\n");
    printsparse(s);


    // SPARSITY
    float total=s[0].row*s[0].col;
    float zeros=total-s[0].value;
    float sparsity=zeros/total;
    printf("\nSparsity =  %f",sparsity);
}


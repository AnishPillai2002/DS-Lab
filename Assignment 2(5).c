/*.Input the representation of a sparse matrix. Find the representation
of its transpose.*/

#include<stdio.h>

typedef struct {
    int row;
    int col;
    int value;
}sparse;

int readsparse(sparse s[]){         // Reading a Sparse Matrix

    int row,col,element;
    printf("Enter the Number of ROWS of Matrix : ");
    scanf("%d",&row);
    printf("Enter the Number of COLUMNS Matrix : ");
    scanf("%d",&col);

    s[0].row=row;
    s[0].col=col;

    int k=1,spar;
    for (int i=0; i<row; i++){
        for (int j=0; i<col; j++){
            printf("Enter Element A%d%d: ",i+1,j+1);
            scanf("%d",&element);

            if (element != 0){
                spar++;
                s[k].row=i;
                s[k].col=j;
                s[k].value=element;
                k++;
            }   
        }     
    }
    s[0].value=k-1;

}

void printsparse(sparse s[]){    // Function to print sparse matrix representation   
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

// Algorithm to sort sparse Matrix Representation
void sparseTranspose(sparse s[],sparse t[]){  // t is the transpose representation of s[]

    int n=s[0].value;
    t[0].row=s[0].col;
    t[0].col=s[0].row;
    t[0].value=s[0].value;

    int current_t=1;
    if (n>0){
        for (int i = 0; i < s[0].col; i++){
            for (int j = 0; j<=n; j++){
                if (s[j].col==i){
                    t[current_t].row=s[j].row;
                    t[current_t].col=s[j].col;
                    t[current_t].value=s[j].value;
                    current_t++;
                }    
            }
        }    
    }
}

int main(){
    sparse s[100],t[100];     
    printf("Enter the Matrix Details : \n");
    readsparse(s);          // returns total no. of elements in sparse s[100]
    printf("\nThe Matrix is: \n");
    printmatrix(s);
    printf("The Sparse Matrix Representation is: \n");
    printsparse(s);
    printf("\n");
}

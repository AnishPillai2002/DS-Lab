/*.Input the representation of a sparse matrix. Find the representation
of its transpose.*/

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



// Fast Transpose Algorithm
void fastTranspose(sparse s[],sparse t[]){

    int start_pos[30], row_terms[30];
    int i,j,k;
    
    int num_terms=s[0].value;
    int num_cols=s[0].col;

    t[0].row=s[0].col;
    t[0].col=s[0].row;
    t[0].value=s[0].value;

    if (num_terms>0){
        
        for (i=0; i < num_cols; i++){
            row_terms[i]=0;            // for making all index of row_terms 0
        }
        for (i=1; i <=num_terms; i++){
            row_terms[s[i].col]++;     // incrementing each index if that element is present
        }

        start_pos[0]=1;

        for (i=1; i < num_cols; i++){
            start_pos[i]=start_pos[i-1]+row_terms[i-1];
        }

        //Creating Transpose Matrix
        for (i = 1; i <= num_terms; i++){
            
            j=start_pos[s[i].col]++;

            t[j].row=s[i].col;
            t[j].col=s[i].row;
            t[j].value=s[i].value;
        }
    }
}

int main(){

    sparse s[100],t[100];     

    printf("Enter the Matrix Details : \n");
    readsparse(s);          
    printf("\nThe Matrix is: \n");
    printmatrix(s);
    printf("The Sparse Matrix Representation is: \n");
    printsparse(s);
    printf("\n");
    printf("The Transpose of Sparse Matrix Representation is: \n");
    fastTranspose(s,t);
    printsparse(t);  
}

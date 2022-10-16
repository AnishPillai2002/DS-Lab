/*.
Input the representation of two sparse matrices. Obtain the
representation of their sum.*/


#include<stdio.h>

// Creating a STRUCTURE to store a sparse matrix
struct sparse{
    int row;
    int col;
    int value;
};

// Declaring structure variables
struct sparse s1[100],s2[100],s3[100];

int size1,size2;  // global size variable of sparse array 
int r1,c1;  // Matrix order is kept constant and global

// Function to DISPLAY MATRIX
void displaymatrix(int arr[][10],int m,int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
}

int sumsparse(){

    s3[0].row=r1;
    s3[0].col=c1;
    int k=1,i=1,j=1;
    while (i<size1 && j<size2){

        if (s1[i].row==s2[j].row && s1[i].col==s2[j].col){
            s3[k].row=s1[i].row;
            s3[k].col=s1[i].col;
            s3[k].value=s1[i].value+s2[j].value;
            i++;
            j++;
            k++;
        }
        else if (s1[i].row==s2[j].row){

            s3[k].row=s1[i].row;
            if (s1[i].col<s2[j].col){
                s3[k].col=s1[i].col;
                s3[k].value=s1[i].value;
                k++;
                i++;   
            }
            else{
                s3[k].col=s2[j].col;
                s3[k].value=s2[j].value;
                k++;
                j++;

            }    
        }

        else{

            if (s1[i].row<s2[j].row){
                s3[k].row=s1[i].row;
                s3[k].col=s1[i].col;
                s3[k].value=s1[i].value;
                k++;
                i++;
            }
            else{
                s3[k].row=s2[j].row;
                s3[k].col=s2[j].col;
                s3[k].value=s2[j].value;
                k++;
                j++;
            }
            
        }
    }

    while (i<size1){
        s3[k].row=s1[i].row;
        s3[k].col=s1[i].col;
        s3[k].value=s1[i].value;
        k++;
        i++;
    }

    while (j<size2){
        s3[k].row=s2[j].row;
        s3[k].col=s2[j].col;
        s3[k].value=s2[j].value;
        k++;
        j++;
    }
    s3[0].value=k-1;
    return k;

}
    
int main(){
    // Matrix 1
    int matrix1[10][10];
    printf("Matrix A: \n");
    printf("Enter the Number of ROWS    : ");
    scanf("%d",&r1);
    printf("Enter the Number of COlUMNS : ");
    scanf("%d",&c1);

    printf("\nEnter the Matrix A :\n");
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c1; j++){
            printf("Enter Element A%d%d : ",i+1,j+1);
            scanf("%d",&matrix1[i][j]);
        }
        printf("\n");  
    }
    printf("\n");

    // Matrix 2
    int matrix2[10][10],r2,c2;
    printf("Matrix B: \n");
    printf("Enter the Number of ROWS    : ");
    scanf("%d",&r2);
    printf("Enter the Number of COlUMNS : ");
    scanf("%d",&c2);

    if (r1!=r2||c1!=c2){
        printf("The Matrix are not compactable for addition\n");
        return 0;
    }

    printf("\nEnter the MatrixB  :\n");
    for (int i = 0; i < r2; i++){
        for (int j = 0; j < c2; j++){
            printf("Enter Element B%d%d: ",i+1,j+1);
            scanf("%d",&matrix2[i][j]);
        }
        printf("\n");
    }

    //Printing the Matrix
    printf("MATRIX A:\n");
    displaymatrix(matrix1,r1,c1);
    printf("\n");

    printf("MATRIX B:\n");
    displaymatrix(matrix2,r2,c2);

    printf("\n\n");

    // Printing  Sparse MatrixA Representation 
    s1[0].row=r1;
    s1[0].col=c1;
    int k1=1;
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c1 ; j++){
            if (matrix1[i][j]!=0){
                s1[k1].row=i;
                s1[k1].col=j;
                s1[k1].value=matrix1[i][j];
                k1++;                
            }
        }
    }
    s1[0].value=k1-1;

    printf("Sparse Matrix Representation of MATRIX A: \n");
    for (int i=0; i<k1; i++){
        printf("%d  %d  %d\n",s1[i].row,s1[i].col,s1[i].value);      
    }

    // Printing  Sparse MatrixB Representation 
    s2[0].row=r1;
    s2[0].col=c1;
    int k2=1;
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c1 ; j++){
            if (matrix2[i][j]!=0){
                s2[k2].row=i;
                s2[k2].col=j;
                s2[k2].value=matrix2[i][j];
                k2++;                
            }        
        }
    }
    s2[0].value=k2-1;
    
    printf("Sparse Matrix Representation of MATRIX B: \n");
    for (int i = 0; i <k2; i++){
        printf("%d  %d  %d\n",s2[i].row,s2[i].col,s2[i].value);      
    }

    size1=k1;
    size2=k2;

    printf("The Sum of Sparse Matrix Representation is: \n");

    int limit=sumsparse();
    for (int i = 0; i < limit; i++){
         printf("%d  %d  %d\n",s3[i].row,s3[i].col,s3[i].value);
        
    }
}


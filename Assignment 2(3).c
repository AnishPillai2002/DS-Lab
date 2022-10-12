/*
Given a sparse matrix. Represent and store it using an efficient
method. Also find the sparsity (The sparsity of a matrix can be
quantified with a score, which is the number of zero values in the
matrix divided by the total number of elements in the matrix.)
*/


#include<stdio.h>

struct sparse{
    int row;
    int col;
    int value;
};

void displaymatrix(int arr[][10],int m,int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
}



int main(){

    struct sparse s[10];

    // Reading and Printing the Matrix
    int r,c,a[10][10];
    printf("Enter the Number of ROWS: ");
    scanf("%d",&r);
    printf("Enter the Number of COLUMNS: ");
    scanf("%d",&c);

    printf("Enter the Matrix Elements: \n");
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            printf("Enter Element A%d%d : ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
        printf("\n");
    }

    printf("The Matrix is: \n");
    displaymatrix(a,r,c);
    printf("\n");

    // Finding Representation of SPARSE Matrix
    int k=0;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            
            if (a[i][j]!=0){
                s[k].row=i;
                s[k].col=j;
                s[k].value=a[i][j];
                k++;
            } 
        }
    }

    // Printing the new representation
    printf("The New Representation is: \n");
    printf("%d  %d  %d\n",r,c,k);
    for (int i = 0; i < k; i++){
        printf("%d  %d  %d\n",s[i].row,s[i].col,s[i].value);      
    }

    // Finding SPARSITY
   
    float total=r*c;     // total no. of elements in a[][]
    float zeros=total-k; // total no.of zeros

    float sparsity= zeros/total;

    printf("SPARSITY = %f",sparsity);

}

/*.
Input the representation of two sparse matrices. Obtain the
representation of their sum.*/

#include<stdio.h>
#include<stdlib.h>

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

int sumsparse(sparse s1[],sparse s2[],sparse s3[]){

    int size1=s1[0].value+1;
    int size2=s2[0].value+1;

    s3[0].row=s1[0].row;
    s3[0].col=s1[0].col;
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

    sparse s1[30],s2[30],s3[60];

    printf("Enter Matrix A: \n");
    readsparse(s1);
    printf("\n");
    printf("Enter Matrix B: \n");
    readsparse(s2);
    printf("\n");

    printf("\nMatrix A:\n");
    printmatrix(s1);
    printf("\nMatrix B:\n");
    printmatrix(s2);

    printf("\nSparse Representation of Matrix A: \n");
    printsparse(s1);
    printf("\nSparse Representation of Matrix B: \n");
    printsparse(s2);

    // Handling possible error
    if (s1[0].row!=s2[0].row || s1[0].col!=s2[0].col){
        printf("Addition Not possible!!\n");
        exit(0);
    }
    
    printf("\n\nRepresentation of Sum of both Matrix: \n ");
    sumsparse(s1,s2,s3);
    printsparse(s3);
}
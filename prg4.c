#include<stdio.h>

//Bubble Sorting
int sort(int arr[],int n){

    int temp,i,j;
    for (i=0;i<n-1;i++){
        
        for ( j=0;j<n-1-i;j++){

            if (arr[j]>arr[j+1]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }  
        }  
    } 
}


// Function to print intersection
int printIntersection(int arr1[],int arr2[],int n,int m){
// This Function can be used for sorted array only

    int i=0,j=0;
    while (i<m && j<n){

        if (arr1[i]<arr2[j]){
            i++;
        }
        else if (arr1[i]>arr2[j]){
            j++;
        }
        else{
            printf("%d ",arr1[i]);
            i++;
            j++;
        }    
    }
}





int main(){

    // Details of Set1
    int n,set1[100];
    printf("Enter the total number of elements in Set1: ");
    scanf("%d",&n);

    printf("Enter the Elements \n");
    for (int i=0;i<n;i++){
        scanf("%d",&set1[i]);
    }
    
    printf("\n");

    //Details of Set2
    int m,set2[100];
    printf("Enter the total number of elements in Set2: ");
    scanf("%d",&m);

    printf("Enter the Elements \n");
    for (int i=0;i<m;i++){
        scanf("%d",&set2[i]);
    } 

    // Sorting arrays
    sort(set1,n);
    sort(set2,m);
    
    printIntersection(set1,set2,n,m);

}
#include <stdio.h> 

void selection_sort(int *A,int n){
	int temp;
	for (int i=0; i<n-1; ++i){
		for (int j=i+1; j<n; ++j){
			if (A[j]<A[i]){
				temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}
		}
	}
}

     
int main() {    
    int A[] = {5, 2, 6, 7, 2, 1, 0, 3}, n = 8;    
        
    selection_sort(A, n);    
        
    for(int i = 0; i < n; ++i)    
        printf("%d ", A[i]);  
    return 0;    
}
	

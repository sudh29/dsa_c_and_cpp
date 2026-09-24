#include <stdio.h> 

void insertion_sort(int *A,int n){
	int temp;
	for (int i=1; i<n; ++i){
		int value =A[i];
		int hole=i;
		while (hole>0 && A[hole-1]> value){
			A[hole]=A[hole-1];
			hole=hole-1;
		}
		A[hole]=value;
	}
}

     
int main() {    
    int A[] = {5, 2, 6, 7, 2, 1, 0, 3}, n = 8;    
        
    insertion_sort(A, n);    
        
    for(int i = 0; i < n; ++i)    
        printf("%d ", A[i]);  
    return 0;    
}
	

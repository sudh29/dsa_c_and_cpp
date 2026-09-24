#include <stdio.h> 

void bubble_sort(int *A,int n){
	int temp;
	for (int k=1; k<n; ++k){
		int flag=0;
		for (int i=0; i<n-k; ++i){
			if (A[i]>A[i+1]){
				temp=A[i];
				A[i]=A[i+1];
				A[i+1]=temp;
				flag=1;
				//printf("yes");
			}
		}
	if (flag==0) break;
	}
}

     
int main() {    
    int A[] = {8, 2, 6, 7, 2, 1, 0, 3}, n = 8;    
        
    bubble_sort(A, n);    
        
    for(int i = 0; i < n; ++i)    
        printf("%d ", A[i]);  
    return 0;    
}
	

#include <stdio.h> 

void merge(int *L, int *R, int *A, int nL, int nR){
	int i=0;
	int j=0;
	int k=0;
	while(i < nL && j < nR){
		if (L[i] <= R[j]){
			A[k]=L[i];
			i+=1;
		}
		else {
			A[k]= R[j];
			j+=1;		
		}
		k+=1;
	}
	while(i < nL){
		A[k]=L[i];
		i+=1;
		k+=1;
	}
	while(j < nR){
		A[k]=R[j];
		j+=1;
		k+=1;
	}
}


void merge_sort(int *a, int n){
	if (n< 2) 
	{return;}
	int mid = n/2;
	int left[mid];
	int right[n - mid];
	for (int i=0 ; i<mid; i++){
		left[i]= a[i];
	}
	for (int j=mid ; j<n; j++){
		right[j-mid]= a[j];
	}
	merge_sort(left,mid);
	merge_sort(right, n-mid);
	merge(left,right,a,mid,n-mid);
}

     
int main() {    
    int A[] = {5, 2, 6, 7, 2, 1, 0, 3}, n = 8;    
        
    merge_sort(A, n);    
        
    for(int i = 0; i < n; ++i)    
        printf("%d ", A[i]);  
    return 0;    
}
	

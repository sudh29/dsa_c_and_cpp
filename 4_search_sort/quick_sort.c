#include <stdio.h> 
#include <stdlib.h>
#include <time.h>


int partition(int *A, int start, int end){

	int temp;

	srand(time(NULL));
	int r = ( rand() % (end-start +1) )+start ;
	//printf("\n%d\n",r);
	temp= A[r];
	A[r]= A[end];
	A[end] = temp; 

	int pivot= A[end];
	int pindex=start;


	for(int i = start ; i < end; i++){
		if (A[i] <= pivot){
			temp=A[i];
			A[i]=A[pindex];
			A[pindex]=temp;
			pindex += 1;	
		}
	}
	temp= A[pindex];
	A[pindex]= A[end];
	A[end] = temp;
	return pindex;
}


void quick_sort(int *A, int start, int end){
	if (start < end) {
	int pindex = partition(A, start, end);
	quick_sort(A,start,pindex-1);
	quick_sort(A,pindex+1, end);
	}		
}

     
int main() {    
	int temp;
	int A[] = {5, 222, -6, 7, 2, 1, 0, 3}, n = 8;
        
	quick_sort(A, 0, 7);    
        
    for(int i = 0; i < n; ++i)    
      printf("%d ", A[i]);  
    return 0;
   
}
	

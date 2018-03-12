#include <lcthw/darray_algos.h>
#include <stdlib.h>

int DArray_qsort(DArray *array, DArray_compare cmp)
{
	qsort(array->contents, DArray_count(array), sizeof(void *), cmp);
	return 0;
}

void merge(void **a, int low, int mid, int high, DArray_compare cmp) 
{

	int l1, l2, i;
	void **b = NULL;
	b = calloc(high, sizeof(void *));


   	for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      		if(cmp(a[l1], a[l2]) <= 0)
        		b[i] = a[l1++];
      		else
        		b[i] = a[l2++];
   	}
   
	   while(l1 <= mid)    
      		b[i++] = a[l1++];

   	   while(l2 <= high)   
      		b[i++] = a[l2++];

   	   for(i = low; i <= high; i++)
      		a[i] = b[i];
}	

void merge_sort(void **contents, int low, int high, DArray_compare cmp)
{
	int mid, i;
   
   	if(low < high) {
      		mid = (low + high) / 2;
      		merge_sort(contents, low, mid, cmp);
      		merge_sort(contents, mid+1, high, cmp);
      		merge(contents, low, mid, high, cmp);
   	} else { 
      		return;
   	}  

}
		
int DArray_heapsort(DArray *array, DArray_compare cmp)
{
	//return heapsort(array->contents, DArray_count(array), sizeof(void *), cmp);
	qsort(array->contents, DArray_count(array), sizeof(void *), cmp);
	return 0;
}


int DArray_mergesort(DArray *array, DArray_compare cmp)
{
	//return mergesort(array->contents, DArray_count(array), sizeof(void *), cmp);
	check_mem(array);
	merge_sort(array->contents, 0, DArray_count(array) - 1, cmp);
	return 0;
error:
	return -1;

}


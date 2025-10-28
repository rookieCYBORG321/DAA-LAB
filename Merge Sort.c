#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high){
	int n1 = mid - low + 1;
	int n2 = high - mid;

	int *a1 = (int *)malloc(n1 * sizeof(int));
	int *a2 = (int *)malloc(n2 * sizeof(int));

	for (int i=0; i<n1; i++){
		a1[i] = arr[low + i];
	}for (int j=0; j<n2; j++){
		a2[j] = arr[mid + 1 + j];
	}
	int i=0, j=0, k=low;
	while (i<n1 && j<n2){
		if (a1[i] <= a2[j]){
			arr[k] = a1[i];
			i++;
		}else{
			arr[k] = a2[j];
			j++;
		}k++;
	}while (i<n1){
		arr[k] = a1[i];
		i++;
		k++;
	}while (j<n2){
		arr[k] = a2[j];
		j++;
		k++;
	}
	free(a1);
	free(a2);
}

void printPass(int arr[], int low, int high){
	printf("Pass: ");
	for (int i=low; i<=high; i++){
		printf("%d ",arr[i]);
	}printf("\n");
}

void splitAndMerge(int arr[], int low, int high){
	if (low < high){
		int mid = low + (high - low)/2;
		splitAndMerge(arr, low, mid);
		splitAndMerge(arr, mid + 1, high);
		merge(arr, low, mid, high);
		printPass(arr, low, high);
	}
}

void display(int arr[], int n){
	for (int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}printf("\n");
}

void main(){
	int i,n;
	printf("no of elements: ");
	scanf("%d", &n);
	int arr[n];
	printf("elements: ");
	for (i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	printf("Given array:\n");
	display(arr,n);
	splitAndMerge(arr, 0, n-1);
	printf("Sorted array:\n");
	display(arr,n);
}

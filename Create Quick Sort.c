#include <stdio.h>

void swap(int arr[], int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int left = low;
	int right = high - 1;

	while(1){
		while(left <= right && arr[left] <= pivot){
			left++;
		}

		while (right >= left && arr[right] > pivot){
			right--;
		}
		if (left > right){
			break;
		}swap(arr, left, right);
	}swap(arr, left, high);
	return left;
}

void printPass(int arr[], int low, int high){
	printf("Pass: ");
	for (int i=low; i<=high; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void quickSort(int arr[], int low, int high){
	if (low < high){
		int pivotIndex = partition(arr, low, high);
		printPass(arr, low, high);
		quickSort(arr,low,pivotIndex-1);
		quickSort(arr,pivotIndex+1, high);
	}
}

void printArray(int arr[], int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);
	}printf("\n");
}

int main(){
	int n;

	printf("number of elements: ");
	scanf("%d", &n);

	int arr[n];

	printf("elements: ");
	for (int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	printf("Original array: ");
	printArray(arr, n);

	quickSort(arr, 0, n-1);

	printf("Sorted array: ");
	printArray(arr, n);
	return 0;
}

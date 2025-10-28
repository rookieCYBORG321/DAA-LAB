#include <stdio.h>

int read1(int a[], int n){
	printf("Enter %d elements : ",n);
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	return 0;
}

int linearSearch(int a[], int low, int high, int key){
	if (low <= high){
		if (key == a[low]){
			return low;
		}else{
			return linearSearch(a, low + 1, high, key);
		}
	}
	return -1;
}

void main() {
	int a[20], n, pos, key;
	printf("Enter n value : ");
	scanf("%d", &n);
	read1(a, n);
	printf("Enter a key element : ");
	scanf("%d", &key);
	pos = linearSearch(a, 0, n - 1, key);
	if (pos == -1) {
		printf("The key element %d is not found\n", key);
	} else {
		printf("The key element %d is found at position : %d\n", key, pos);
	}
}

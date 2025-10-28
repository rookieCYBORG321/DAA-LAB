#include <stdio.h>
int knapsack(int n, int w, int val[], int wt[]){
	int dp[w+1];
	for (int i=0; i<=w;i++){
		dp[i] = 0;
	}for (int i=0; i<n; i++){
		for (int j=w; j>=wt[i]; j--){
			dp[j] = (dp[j] > dp[j - wt[i]] + val[i]) ? dp[j] : dp[j-wt[i]] + val[i];
		}
	}return dp[w];
}

int main(){
	int n,w;
	scanf("%d", &n);
	int val[n], wt[n];
	for (int i=0; i<n; i++){
		scanf("%d", &val[i]);
	}
	for (int i=0; i<n; i++){
		scanf("%d", &wt[i]);
	}scanf("%d", &w);
	int result = knapsack(n, w, val, wt);
	printf("%d\n", result);
}

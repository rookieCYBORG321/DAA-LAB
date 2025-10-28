#include <limits.h> 
#include <stdio.h>
#define MAX 20
int V, E;
int graph[MAX][MAX];
#define INFINITY 99999

void dijkstra(int G[MAX][MAX], int n, int startnode) {
	
	// write your code here
	int cost[MAX][MAX], dist[MAX], pred[MAX];
	int visited[MAX], count, min_dist, nxtnode;

	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			if(G[i][j] == 0 && i!=j){
				cost[i][j] = INFINITY;
			}else{
				cost[i][j] = G[i][j];
			}
		}
	}
	for (int i=1; i<=n; i++){
		dist[i] = cost[startnode][i];
		pred[i] = startnode;
		visited[i] = 0;
	}
	dist[startnode] = 0;
	visited[startnode] = 1;
	count = 1;

	while (count < n-1){
		min_dist = INFINITY;

		for(int i=1; i<=n; i++){
			if (dist[i] < min_dist && !visited[i]){
				min_dist = dist[i];
				nxtnode = i;
			}
		}
		visited[nxtnode] = 1;
		for (int i=1; i<=n; i++){
			if (!visited[i] && min_dist + cost[nxtnode][i] < dist[i]){
				dist[i] = min_dist + cost[nxtnode][i];
				pred[i] = nxtnode;
			}
		}
		count++;
	}
		printf("Node\tDistance\tPath\n");
		for (int i=1; i<=n; i++){
			if(i != startnode){
				printf("%4d\t",i);
				if (dist[i] == INFINITY){
					printf("     INF\tNO PATH\n");
				}
				else{
					printf("%8d\t",dist[i]);
					printf("%d",i);
					int j=i;
					do{
						j=pred[j];
						printf("<-%d",j);
					}while(j!=startnode);
					printf("\n");
				}
			}
		}
}
int main() { 
	int s, d, w, i, j;
	printf("Enter the number of vertices : ");
	scanf("%d", &V);
	printf("Enter the number of edges : ");
	scanf("%d", &E);
	for(i = 1 ; i <= V; i++) {
		for(j = 1; j <= V; j++) {
			graph[i][i] = 0;
		}
	}
	for(i = 1; i <= E; i++) {
		printf("Enter source : ");
		scanf("%d", &s);
		printf("Enter destination : ");
		scanf("%d", &d);
		printf("Enter weight : ");
		scanf("%d", &w);
		if(s > V || d > V || s <= 0 || d <= 0) {
			printf("Invalid index. Try again.\n");
			i--;
			continue;
		} else {
			graph[s][d] = w;
		}
	}
	printf("Enter the source :");
	scanf("%d", &s);
	dijkstra(graph, V, s); 
	return 0; 
} 

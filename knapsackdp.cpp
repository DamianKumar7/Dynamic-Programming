#include<stdio.h>
#include<stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }
int knapsack(int *,int *,int,int);
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
int main(){
	int n,W;
	int A[4][2] = {0};
	printf("%d",sizeof(A));
	printf("Enter the Capacity of the knapsack : ");
	scanf("%d",&W );
	printf("Enter the Number of elements in the knapsack");
	scanf("%d",&n);
	int *wt;
	wt = (int*)malloc((n)*sizeof(int));
	int *val;
	val = (int*)malloc((n)*sizeof(int));
	int i;
	printf("Enter the weights of the items and their corresponding values\n");
	for (i = 0; i <= n-1;i++ ){
		printf("weight:");
		scanf("%d",&wt[i]);
		printf("\n");
		printf("value");
		scanf("%d",&val[i]);
		printf("\n");
	}
	int profit = knapsack(wt,val,n,W);
	printf("The Profit is : %d ",profit);
}
int knapsack(int *wt,int *val,int n,int W){
	int i,j;
	int **dp = (int**)malloc((n+1)*sizeof(int*));
	for(i = 0 ; i <= n;i++){
		dp[i] = (int*)malloc((W+1)*sizeof(int));
	}
	
	for (i = 0 ; i <= n; i++){
		for(j = 0; j<= W; j ++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}
			
			
		}
	}
	for(i = 1; i <= n;i++){
		for ( j = 1;j <= W;j++){
			if (wt[i-1] <= j){
				dp[i][j] = max(val[i-1]+ dp[i-1][j-wt[i-1]],dp[i-1][j]);
				
			}
			else if (wt[i-1] >j){
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	return dp[n][W];
}

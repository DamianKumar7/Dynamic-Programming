#include<stdio.h>
#include<stdlib.h>


int max(int a, int b) { return (a > b) ? a : b; }
int knapsack(int *,int *,int);
int main(){
	int l;
	printf("Enter the length of the rod : ");
	scanf("%d",&l);
	int *wt;
	wt = (int*)malloc((l)*sizeof(int));
	int *val;
	val = (int*)malloc((l)*sizeof(int));
	int i;
	printf("Enter the lengths of the items and their corresponding values\n");
	for (i = 0; i <= l-1;i++ ){
		printf("weight:");
		scanf("%d",&wt[i]);
		printf("\n");
		printf("value");
		scanf("%d",&val[i]);
		printf("\n");
	}
	int profit = knapsack(wt,val,l);
	printf("The Profit is : %d ",profit);
}

int knapsack(int *wt,int *val,int l){
	int **dp = (int**)malloc((l+1)*sizeof(int));
	int i; 
	for(i = 0; i <= l;i++){
		dp[i] = (int*)malloc((l+1)*sizeof(int));
		
	}
	
	int j;
	for(i = 0; i <= l; i++){
		for(j =0; j <= l;j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}
				
		}
	}
	
	for(i = 1; i <= l; i++){
		for (j = 1; j<= l; j++){
			if(wt[i-1] <= j ){
				dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	//printf("%d",dp[n][W]);
	return dp[l][l];
}

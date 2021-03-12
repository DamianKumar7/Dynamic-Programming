#include<stdio.h>
#include<stdlib.h>

int main(){
	printf("Enter the number of coins\n");
	int n;
	scanf("%d",&n);
	printf("\nEnter the sum to be found\n");
	int S;
	scanf("%d",&S);
	int *arr = (int *)malloc(n*sizeof(int));
	printf("enter the array elements");
	int i;
	for (i = 0; i <= n-1;i++){
		scanf("%d",&arr[i]);
	}
	printf("\n");
	int **dp = (int**)malloc((n+1)*sizeof(int*));
	for ( i = 0; i <= n;i++){
		dp[i] = (int*)malloc((S+1)*sizeof(int));
	}
	int j;
	for ( i = 0; i <= n; i++){
		for (j = 0; j <= S; j++){
			if (j == 0){
				dp[i][j] = 1;
			}
			if (i == 0 && j >= 1){
				dp[i][j] = 0;
			}
		}
	}
	
	for ( i = 1; i <= n; i++){
		for( j = 1; j <= S; j ++){
			if (arr[i-1] <= j){
				dp[i][j] = (dp[i][j-arr[i-1]]   +    dp[i-1][j]);
			}
			
			else if (arr[i-1] >j){
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	printf("%d",dp[n][S] );
	
}

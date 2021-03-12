#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int max(int num1, int num2);
int min(int num1, int num2);


int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}
int min(int num1, int num2) 
{
    return (num1 > num2 ) ? num2 : num1;
}

int main(){
	printf("Enter the length of the array\n");
	int n;
	scanf("%d",&n);
	int *arr = (int *)malloc(n*sizeof(int));
	printf("enter the array elements");
	int i;
	for (i = 0; i <= n-1;i++){
		scanf("%d",&arr[i]);
	}
	printf("\n");
	
	int sum = 0;
	for(i = 0; i <= n-1; i++){
		sum += arr[i];
	}
	int diff = sum;
	int range;
	for( range = 0; range <= sum;range++ ){
		int **dp = (int**)malloc((n+1)*sizeof(int*));
		for ( i = 0; i <= n;i++){
			dp[i] = (int*)malloc((range+1)*sizeof(int));
		}
		
		int j;
		for ( i = 0; i <= n; i++){
			for (j = 0; j <= range; j++){
				if (j == 0){
					dp[i][j] = 1;
				}
				if (i == 0 && j >= 1){
					dp[i][j] = 0;
				}
			}
		}
		
		for ( i = 1; i <= n; i++){
			for( j = 1; j <= range; j ++){
				if (arr[i-1] <= j){
					dp[i][j] = (dp[i-1][j-arr[i-1]]  ||  dp[i-1][j]);
				}
				
				else if (arr[i-1] >j){
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		
		
		if(dp[n][range] == 1){
			diff = min(diff,abs(sum-(2*range)));
		}
	
		
	}
	
	printf("%d",diff);
	
	

}

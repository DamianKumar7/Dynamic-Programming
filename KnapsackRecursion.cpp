#include<stdio.h>
#include<stdlib.h>

int knapsack(int *,int *,int,int);

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
 
int max(int a, int b) { return (a > b) ? a : b; }
int main(){
	printf("Enter the capacity of the bag");
	int W;
	scanf("%d",&W);
	printf("Enter the number of elements");
	int n;
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
	int j; 
   for (i = 0; i < n-1; i++)  {
   	 for (j = 0; j < n-i-1; j++) {
   	 	if (wt[j] > wt[j+1]){
   	 		swap(&wt[j], &wt[j+1]); 
   	 		swap(&val[j],&val[j+1]);
			} 
              
		}
	}
	for (i = 0; i <= n-1;i++ ){
		printf("%d ",wt[i]);
		/*printf("%d",val[i]);*/
		printf("\n");
		
	}
	for (i = 0; i <= n-1;i++ ){
		printf("%d ",val[i]);
	}
	int profit = knapsack(wt,val,n,W);
	printf("\n The Profit Is : %d",profit);
	
	
}
int knapsack (int *wt,int *val,int n,int W){
	if (W==0 || n == 0){
		return 0;
	}
	if (wt[n-1] <= W){
		return max(val[n-1]+knapsack(wt,val,n-1,W-wt[n-1]),knapsack(wt,val,n-1,W));
	}
	else if (wt[n-1] > W){
		return knapsack(wt,val,n-1,W);
	}
}



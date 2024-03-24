// Problem: Sum of n elements

int sumOfN(int n){
	int dp[n + 1];
	dp[0] = 0;
	for(int i = 1; i < n + 1; i++){
		dp[i] = dp[i-1] + i;
	}
	return dp[n];
}
// Problem: Climbing stair with K steps

int climbingStairK(int n, int k){
	int dp[n + 1] = {0};
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= k; j++){
			if(j <= i){
				dp[i] += dp[i - j];
			}
		}
	}
	return dp[n];
}
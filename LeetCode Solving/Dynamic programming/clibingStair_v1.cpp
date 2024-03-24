// Climbing stair

int climbingStair(int n){
	// Base case n = 0 && n = 1 => 1
	int dp[n + 1];
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i < n + 1; i++){
		dp[i] = d[i - 1] + dp[i - 2];
	}
	return dp[n];
}
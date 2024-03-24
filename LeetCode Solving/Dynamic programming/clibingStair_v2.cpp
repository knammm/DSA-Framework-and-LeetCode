// Problem Climbing Stair but need less space complexity
// Idea: due to the fact that we only need 3 variables to compute

int climbingStair(int n){
	if(n == 0 || n == 1) return 1;
	int a = 1;
	int b = 1;
	int c = 0;
	for(int i = 2; i <= n; i++){
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}
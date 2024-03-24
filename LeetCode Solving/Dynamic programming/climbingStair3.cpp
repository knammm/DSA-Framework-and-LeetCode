// Problem: Climbing stair with 3 steps

int climbingStair3(int n){
	if(n == 0 || n == 1) return 1;
	if(n == 2) return 2;
	int a = 1;
	int b = 1;
	int c = 2;
	int d = 0;
	for(int i = 3; i <= n ; i++){
		d = a + b + c
		a = b;
		b = c;
		c = d;
	}
	return d;
}
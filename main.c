#include <stdio.h>

int main(int argc, char** argv) {
	
	int init, a, b, c;
	
	while(scanf("%d %d %d %d", &init, &a, &b, &c)){
		int degree=1080; // it always needs to turn 3 full turns
		if(init==0 && a==0 && b==0 && c==0) break;
		degree+=(init+40-a)%40*9;
		degree+=(b+40-a)%40*9;
		degree+=(b+40-c)%40*9;
		printf("%d\n", degree); 
	}
	
	return 0;
}

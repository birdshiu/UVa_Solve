#include <stdio.h>
#include <string.h>
int table[100005];

int main() {
	int t,n;
		for(int i=1;i<=100000;i++){
			int x=i, y=i;
			while(x>0){
				y+=x%10;
				x/=10;
			}
			if(table[y]==0 || table[y]>i) table[y]=i;
		}
		scanf("%d", &t);
		while(t--){
			scanf("%d", &n);
			printf("%d\n", table[n]);
		}
	
}

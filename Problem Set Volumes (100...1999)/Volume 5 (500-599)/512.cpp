#include <iostream>
#include <string.h>

struct command{
	char c[10];
	int r1, r2, c1, c2;
	int a, n[20];
} com[1000];

int r, c, n, kase=0, q;

int simulate(int* r0, int* c0){
	for(int i=0; i<n; i++){
		if(com[i].c[0]=='E'){
			if(com[i].r1==*r0 && com[i].c1==*c0){
				*r0=com[i].r2;
				*c0=com[i].c2;
			}
			else if(com[i].r2==*r0 && com[i].c2==*c0){
				*r0=com[i].r1;
				*c0=com[i].c1;
			}
		}
		else{
			int dr=0, dc=0;
			for(int j=0; j<com[i].a;j++){
				if(com[i].c[0]=='I'){
					if(com[i].c[1]=='R' && com[i].n[j]<=*r0) dr++;
					if(com[i].c[1]=='C' && com[i].n[j]<=*c0) dc++;
				}
				else{
					if(com[i].c[1]=='R' && com[i].n[j]==*r0) return 0;
					if(com[i].c[1]=='C' && com[i].n[j]==*c0) return 0;
					if(com[i].c[1]=='R' && com[i].n[j]<*r0) dr--;
					if(com[i].c[1]=='C' && com[i].n[j]<*c0) dc--;
				}
			}
			*r0+=dr; *c0+=dc;
		}
	}
	return 1;
}



int main(int argc, char** argv) {
	while(scanf("%d%d%d", &r, &c, &n)==3 && r){
		for(int i=0;i<n;i++){
			scanf("%s", com[i].c);
			if(com[i].c[0]=='E'){
				scanf("%d%d%d%d", &com[i].r1, &com[i].c1, &com[i].r2, &com[i].c2);
			}
			else{
				scanf("%d", &com[i].a);
				for(int j=0;j<com[i].a;j++) scanf("%d", &com[i].n[j]);
			}
		}
		
		if(kase>0) printf("\n");
		printf("Spreadsheet #%d\n", ++kase);
		scanf("%d", &q);
		int r0, c0;
		while(q--){
			scanf("%d%d", &r0, &c0);
			printf("Cell data in (%d,%d) ", r0, c0);
			if(!simulate(&r0, &c0)) printf("GONE\n");
			else printf("moved to (%d,%d)\n", r0, c0);
		}
		
	}
	return 0;
}

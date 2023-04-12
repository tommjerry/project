#include<stdio.h>
#include<math.h>

void main(){
	int p,g,x,y,a,b,ka,kb;
	printf("public keys:");
	scanf("%d %d",&p,&g);
	printf("Private Keys:");
	scanf("%d %d",&a,&b);
	x=(int)pow(g,a)%p;
	y=(int)pow(g,b)%p;
	ka=(int)pow(y,a)%p;
	kb=((int)pow(x,b))%p;
	printf("%d %d\n",ka,kb);
}

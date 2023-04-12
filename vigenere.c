#include<stdio.h>
#include<string.h>

void main(){
	char test[30],key[30];
	scanf("%s",test);
	scanf("%s",key);
	int ms=strlen(test),ks=strlen(key),i,j;
	char nmsg[ms],encrypt[ms];
	for(i=0,j=0;i<ms;i++,j++){
		if(j==ks) j=0;
		nmsg[i]=key[j];
	}
	//encrypt
	nmsg[i]='\0';
	for(i=0;i<ms;i++){
		encrypt[i]=(test[i]+nmsg[i])%26+'A';
	}
	encrypt[i]='\0';
	printf("%s",encrypt);
}

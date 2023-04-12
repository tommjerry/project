#include<stdio.h>
#include<string.h>

void main(){
	int i,j,s,t=0;
	char text[300],key[300];
	scanf("%s",text);
	scanf("%s",key);
	s=strlen(text);
	int km[s][s],msg[s];
	char enc[s];
	for(i=0;i<s;i++){
		for(j=0;j<s;j++){
			km[i][j]=key[t++]-65;
		}
	}
	for(i=0;i<s;i++) msg[i]=text[i]-65;
	for(i=0;i<s;i++){
		t=0;
		for(j=0;j<s;j++){
			t+=km[i][j]*msg[j];
		}
		enc[i]=(t%26)+65;
	}
	enc[i]='\0';
	printf("%s",enc);
	//for(i=0;i<s;i++) printf("%c",enc[i]);
}

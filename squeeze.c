#include <stdio.h>
void squeeze(char *, char);

void squee(char *, char *);

void nog(char *);

int main(){
	char s[100] = "hello";
	squeeze(s, 'l');
	printf("hello, l %s \n", s);
	squeeze(s, 'l');
	//nog("asfdtfasgdfxshadgfdsakd");
	char n[] = "h1el2l3o41";
	char m[] = "h1el2l3o41";
	//nog("daddyispotty");
	char d[] = "ehehehheall";
	//nog("laalaalalaplopplopplop!!:D");
	squee(n, d);
	printf("%s, %s is %s\n", m, d, n);
}

void squeeze(char s[], char c){
	int i, j;
	for(j = i = 0; s[i] != '\0'; i++)
		if(s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}

void squee(char s[], char d[]){
	int j;
	for(j = 0; d[j]; j++)
		squeeze(s, d[j]);
}

void nog(char msg[]){
	printf("%s\n", msg);
}

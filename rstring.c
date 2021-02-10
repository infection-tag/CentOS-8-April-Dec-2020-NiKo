#include <stdio.h>

#include <string.h>

void rstr(char[]);

void nswap(char[], int, int);

int main(){
	char s[] = "supercalifragilisticexpialodociousifyousayitloudenoughyoumightsoundquiteorecocious";
//	nswap(s, 0, 1);
//	printf("%s\n", s);
	rstr(s);
	printf("%s\n", s);
}

void rstr(char s[]){
	const int total = strlen(s);
	int i;
	for(i = 0; i != (total / 2); i++){
		nswap(s, i, total - (i + 1));
	}
}

void nswap(char s[], int i, int j){
	char tmp;
	tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}

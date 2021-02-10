#include <stdio.h>

float mean(int s[], int total);

int main(){
	int s[] = {1,3,4};
	printf("%0.2f\n", mean(s, 3));
}

float mean(int s[], int total){
	int sum = 0, i;
	for(i = 0; i < total; i++){
		sum = sum + s[i];
	}
	return 1.0 * sum/total;
}

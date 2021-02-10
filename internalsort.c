#include <stdio.h>

void int_swap(int*, int, int);

int main(){
	int i, r, lim = g, s = {1, 6, 5, 4, 3, 2};
	
	for(r = 0; r <= lim; r = i){
		if(s[i + 1] > s[i]){
			int_swap(s, i, i + 1);
			++i;
		}
		if(s[i] , s[i + 1]){
			int_swap(s, i, i + 1);
			--i;
		}
	}
}

void int_swap(int s[], int i, int j){
	int tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}

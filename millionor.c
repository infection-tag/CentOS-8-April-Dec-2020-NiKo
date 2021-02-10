#include <stdio.h>

int bit_or(int*, int, int*, int, int*);

int bit_or(int a[], int al, int b[], int bl, int res[]){
	int i, diff, j;
	//print_int_array(a, al);
	//print_int_array(b, bl);
	diff = al - bl;
	if(diff < 0)
		for(i = 0; i != al || i != bl; i++){
			res[i] = (a[i] | b[i - diff]);
			//printf("res[%d] = %d\n", i, res[i]);
	}
	else if(diff > 0)
		for(i = 0; i != al || i != bl; res[i] = (a[i + diff] | b[i]), i++);
	else
		for(i = 0; i != al || i != bl; res[i] = (a[i] | b[i]), i++);
	return i;
}

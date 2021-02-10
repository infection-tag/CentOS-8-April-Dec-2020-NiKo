#include <stdio.h>

int bit_or(int*, int, int*, int, int*);
int convert_int_to_bit_array(int, int*);
void print_int_array(int*, int);
void reverse_int_string(int*, int);
void int_swap(int*, int, int);

int main(){
	int a[1024], al = convert_int_to_bit_array(45, a);
	int b[1024], bl = convert_int_to_bit_array(2, b);
	int c[1024], cl = convert_int_to_bit_array(23, c);
	int res[1024];
	printf("45 is %d ", al);
	print_int_array(a, al);
	printf("2 is %d ", bl);
	print_int_array(b, bl);
	printf("23 is %d ", cl);
	print_int_array(c, cl);
	//j = bit_and(a, al, b, bl, res);
	//printf("j: %d\n", j);
	//print_int_array(res, j);
}

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

int convert_int_to_bit_array(int n, int s[]){
	int mod, i, bin = 0;
	//for(i = 0; i != len; i++)
		//total = 10 * total + s[i];
	for(i = 0; n > 1; i++, n = (n - mod) / 2){
		mod = n % 2;
		s[i] = mod;
	}
	i++;
	s[i] = n;
	reverse_int_string(s, i);
	return i;
}

void print_int_array(int s[], int len){
	int i;
	for(i = 0; i != len; i++)
		printf("%d", s[i]);
	printf("\n");
}

void reverse_int_string(int s[], int len){
	for(int i = 0; i <= len; i++)
		int_swap(s, i, len - (i + 1));
}

/* Swap places in an int function */
void int_swap(int s[], int i, int j){
	int tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}

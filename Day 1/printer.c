#include <stdio.h>
#include <stdlib.h>

int total = 0;
char token;
char prev;
char first;

void main(){
	prev = getchar();
	first = prev;

	while((token = getchar()) != '\n'){
		if(token == prev)
			total += (prev - '0');
		prev = token;
	}

	if(prev == first)
		total += (prev - '0');

	printf("%d\n", total);
}

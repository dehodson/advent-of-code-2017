#include <stdio.h>
#include <stdlib.h>

int total = 0;
int length;
int pos = -1;
char token;

void main(int argc, char** argv){
	length = strlen(argv[1]);

	while(token = argv[1][++pos]){
		if(token == argv[1][(pos + (length / 2)) % length])
			total += (token - '0');
	}

	printf("%d\n", total);
}

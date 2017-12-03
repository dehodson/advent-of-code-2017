#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max, min, current, total = 0, num = 0, done = 0;
char token;

FILE *fp;

int main(int argc, char** argv){
	fp = fopen("input", "r");

	if(fp == NULL){
		printf("Can't open input file.\n");
		exit(1);
	}

	while(!done){
		max = INT_MIN;
		min = INT_MAX;
		current = 0;
		while((token = fgetc(fp)) != '\n'){
			if(token == EOF){
				done = 1;
				break;
			}
			if(token >= '0' && token <= '9'){
				current = (current * 10) + (token - '0');
			} else {
				if(current > max)
					max = current;
				if(current < min)
					min = current;
				current = 0;
			}
		}
		if(current > max)
			max = current;
		if(current < min)
			min = current;
		total += max - min;
	}

	printf("%d\n", total);
	return 0;
}

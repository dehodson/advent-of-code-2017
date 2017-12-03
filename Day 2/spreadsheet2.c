#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int max, min, current, e = 0, e2 = 0, total = 0, num = 0, done = 0;
char token;

int row[20];

FILE *fp;

int main(int argc, char** argv){
	fp = fopen("input", "r");
	int a, b;

	if(fp == NULL){
		printf("Can't open input file.\n");
		exit(1);
	}

	while(!done){
		max = INT_MIN;
		min = INT_MAX;
		current = 0;
		e = 0;

		for(int i = 0; i < 20; i++){
			row[i] = 0;
		}

		while((token = fgetc(fp)) != '\n'){
			if(token == EOF){
				done = 1;
				break;
			}
			if(token >= '0' && token <= '9'){
				current = (current * 10) + (token - '0');
			} else {
				row[e++] = current;
				current = 0;
			}
		}
		row[e++] = current;

		e = 0;
		while(row[e]){
			e2 = 0;
			while(e2 < e){
				a = row[e] > row[e2] ? row[e] : row[e2];
				b = row[e] > row[e2] ? row[e2] : row[e];
				if(a % b == 0){
					printf("%d, %d\n", a, b);
					total += a / b;
					row[e+1] = 0;
					break;
				}
				e2++;
			}
			e++;
		}

	}

	printf("%d\n", total);
	return 0;
}

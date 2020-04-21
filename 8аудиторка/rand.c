#include<stdio.h>
#include<stdlib.h>
float MakeRandFloat(int i) {
	srand(i);
	float ans = rand() % 100;
	ans += rand() % 10 / 10;
	ans += rand() % 10 / 100;
	ans += rand() % 10 / 1000;
	return ans;
}
#include <stdio.h>
#include <iostream>

using namespace std;
long long pow(long long a, long long b,long long c) {
	if (b == 1) {
		return a;
	}
	long long temp = pow(a, b / 2, c);
	if (b % 2 == 0) {
		return ((temp*temp) % c);
	}
	else { //b°¡ È¦¼ö 
		return ((temp*temp) % c * a) % c;
	}
}
int main(void) {
	long long a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	
	printf("%lld", pow(a%c,b,c));

		
	return 0;
}
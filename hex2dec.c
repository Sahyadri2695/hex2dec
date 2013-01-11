#include <stdio.h>

long hex2dec(char * a) {
	char c;
	long n = 0;
	
	while (*a) {
		c = *a++ - '0';

		if (c >= 17 && c <= 23) {
			c -= 7;

		} else if (c >= 49 && c <= 54) {
			c -= 39;

		} else if (c > 10 || c < 0) {
			goto INVALID;
		}

		n = (n << 4) + c;
	}

	return n;

INVALID:
	return -1;
}

int main(int argc, char ** argv) {
	int i;
	long n;

	for (i = 1; i < argc; i++) {
		n = hex2dec(argv[i]);

		if (n < 0) {
			fprintf(stderr, "%s input is invalid.\n", argv[i]);

		} else {
			printf("%s: %i\n", argv[i], n);
		}
	}

	return 0;
}

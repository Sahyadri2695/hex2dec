#include <stdio.h>

long hex2dec(char * a) {
	char c;
	long n = 0;
	
	while (*a) {
		c = *a++;

		if (c >= '0' && c <= '9') {
			c -= '0';

		} else if (c >= 'a' && c <= 'f') {
			c = (c - 'a') + 10;

		} else if (c >= 'A' && c <= 'F') {
			c = (c - 'A') + 10;

		} else {
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
			printf("%s: %li\n", argv[i], n);
		}
	}

	return 0;
}

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	if (argc < 2) {
		fprintf(stderr, "usage: rmsuf <string> <suffix>\n");
		return 1;
	}
	size_t lenstr = strlen(argv[1]);
	size_t lensuffix = strlen(argv[2]);
	if (lensuffix <= lenstr && strcasecmp(argv[1] + lenstr - lensuffix, argv[2]) == 0) {
		argv[1][lenstr - lensuffix] = '\0';
	}
	printf("%s\n", argv[1]);
	return 0;
}

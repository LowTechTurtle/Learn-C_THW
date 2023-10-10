#define _GNU_SOURCE
#include<glob.h>
#include<stdio.h>
#include<stdlib.h>
#include "dbg.h"
#include<string.h>
#define MAX_VALUE 512
int readfile(FILE *file, char word[])
{
	check(file != NULL, "U gave me nothing for a file pointer");
	check(strlen(word) > 0, "i dont take an empty string")

	char buffer[100];
	int i = 0;
	int line = 1;
	memset(buffer, '\0', 100);
	int rc = 0;
	while(!feof(file)) {
		buffer[i] = fgetc(file);
		if (buffer[i] == ' ') {
			buffer[i] = '\0';
			i = 0; 
			if (strcmp(word, buffer) == 0) {
				printf("Found '%s' at line %d.\n", buffer, line);
				rc = 1;
			}
			memset(buffer, '\0', 100);
			continue;
		} else if (buffer[i] == '\n') {
			buffer[i] = '\0';
			i = 0; 
			if (strcmp(word, buffer) == 0) {
				printf("Found '%s' at line %d.\n", buffer, line);
				rc = 1;
			}
			memset(buffer, '\0', 100);
			line += 1;
			continue;
		} else {
			i += 1;
		}
	}
	return rc;
error:
	fcloseall();
	return -1;
}

int main(int argc, char *argv[])
{
	check(argc > 1, "You need to give me what to find");
	int or_status = 0;
	if (strcmp("-o", argv[1]) == 0) {
		or_status = 1;
	}

	glob_t pglob;
	int rc = glob("/home/turtle/.logfind/*.logf", GLOB_ERR, NULL, &pglob);
	check(rc == 0, "Failed in getting path to log files");	
	char **found = pglob.gl_pathv;
	FILE *file;
	int i = 1;
	int j = 1;
	int rq = 1;
	while (*found) {
		file = fopen(*found, "r");	
		check(file != NULL, "Failed to get file");
		printf("File %s:\n", *found);
		if (or_status) {
			j = 2;
		}
		for (i = j; i < argc; i++) {
			printf("looking for %s\n", argv[i]);
			rewind(file);
			rc = readfile(file, argv[i]);
			if (or_status == 1) {
				if (rc == 1) {
				printf("File %s meet the requirement(s)\n", *found);
				rq = 0;
				break;
				} else { 
					continue;
				}
			} else {
				if (rc == 0) {
					break;
				} else {
					continue;
				}
			}
		}
		if (rc == 1 && rq == 1) {
			printf("File %s meet the requirement(s)\n", *found);
			rq = 1;
		}
		found++;
	}
	globfree(&pglob);
	return 0;
error:
	globfree(&pglob);
	fcloseall();
	return -1;
}

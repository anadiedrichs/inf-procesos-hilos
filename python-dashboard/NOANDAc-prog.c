
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {

    FILE * fp = popen("python display.py", "w");
    if (fp == NULL) {
        printf("popen error\n");
        exit(1);
    }

    int inc = 0;
    char buf[10];
/*
    while(1) {
        sprintf(buf, "%d", inc);
        fputs(buf, fp);
        inc++;
        sleep(1);
    }
*/
	while(1) {
		fprintf(fp, "%d\n", inc);
		inc++;
		fflush(fp);
		sleep(1);
	}


    return (0);
}

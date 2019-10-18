#include<stdio.h>
#include<time.h>

void main()
{
    time_t t;
    time(&t);
    printf("\n current time is : %s",ctime(&t));

	char buff[20];
	time_t now = time(NULL);
	strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
	printf("\n otros tiempos: %s \n", buff);
}



#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	char buff[50];
	int leido,t1,t2;
	t1 = open("t1",O_RDWR, 0777);
	t2 = open("t2",O_RDWR, 0777);
	leido = read (t1, buff, sizeof buff);
	buff[leido] = 33;
	write ( STDOUT_FILENO , buff, leido);
	write ( t2 , buff, (leido+1));

	return 0;
}

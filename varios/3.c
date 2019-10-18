#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	mkfifo("./t1", 0777);
	mkfifo("./t2", 0777);
	int t1;
	t1 = open("t1",O_RDWR, 0777);
	write (t1, "hola mundo\n", 11);

	return 0;
}

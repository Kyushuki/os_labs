#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"
#include "stdio.h"
#include "string.h"

#define NAMEDPIPE "/tmp/calc_pipe"
#define BUFSIZE 600

int main()
{
	int fd, len, result, num1, num2;
	char buf[BUFSIZE], op;
	if (mkfifo(NAMEDPIPE, 0777)){
		perror("mkinfo");
		return 1;
	}
	if ((fd = open(NAMEDPIPE, O_RDONLY)) <=0){
		perror("open");
		return 1;
	}
	do {	
		
		if ((len = read(fd, buf, BUFSIZE-1)) <=0){
			perror("read");
			close(fd);
			remove(NAMEDPIPE);
			break;
		} else {
			sscanf(buf, "%d %c %d", &num1, &op, &num2);
			switch(op){
				case '+':
					result = num1 + num2;
					break;
				case '-':
					result = num1 - num2;
					break;
				case '*':
					result = num1 * num2;
					break;
				case '/':
					if (num2 != 0){
						result = num1 / num2;
						break;
					}
					else{
						printf("cant divide by zero(0)\n");
						return 0;
					}
				default:
					printf("Incorrect operatror!\n");
					return 0;
			}
			printf("INCOMMING MESSEGE(%d): %s\n", len, buf);
			printf("RESULT:%i\n", result);
		}
		
	} while(1);
}

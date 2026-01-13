#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

	int fd[2];

	int a, b, c;
	pid_t pid;


	printf("\na = "); scanf("%d", &a);
	printf("b = "); scanf("%d", &b);
	printf("c = "); scanf("%d", &c);

	if(pipe(fd) == -1){
		printf("\nPipe failed.\n");
		return 1;
	}

 	pid = fork();
	if(pid < 0){
		printf("\nFork failed\n");
		return 1;
	}





	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>

typedef struct msg_buffer {
	long msg_type;
	char msg_text[100];
}msg_buffer ;




int main() {
	key_t msg_key;
	int msgid;
	msg_buffer message ;
	pid_t pid;

	msg_key = ftok("progfile", 65);
	msgid = msgget(msg_key, 0666 | IPC_CREAT);

	if(msgid == -1){
		printf("\nMessage Que Failed\n");
		return 1;
	}

	pid_t pid = fork();
	if(pid == 0){
		msgrcv(msgid, &message, sizeof(message), 1, 0);
	}else {
	}


	return 0;
}

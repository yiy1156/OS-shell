#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h> 
#include <string.h>


void read_command (char cmd[], char *par[]) {
	char line[1024];
	int count = 0, i=0, j=0;
	char *array[100], *pch;

	for ( ;; ) {
		int c = fgetc(stdin);
		line[count++] = (char) c;
		if (c=='\n') break;

	}
	if (count==1) return;
	pch = strtok(line, "\n");
	while (pch!=NULL) {
		array[i++] = strdup (pch);
		pch = strtok (NULL, "\n");
	}
	strcpy (cmd, array[0]);
	for (j=0; j<i; j++) {
		par[j] = array[j];
		par[i] = NULL;
	}
}

int main() {
	char cmd[100], command[100], *parameters[20];
	char *envp[] = {(char *) "PATH=/bin", 0};
	while (1) {
		printf ("lab1> ");
		read_command (command, parameters);
		printf ("Parent Process %d\n", getpid());
		if (strcmp (command, "greet") == 0)
			printf ("Hello\n");
			
		else if (strcmp (command, "printid") == 0)
			printf ("The ID of the current process is %d\n", getpid());
			
		else if (strcmp (command, "exit") == 0)
			exit(0);
		
		else {
			if (fork()!=0)
				wait (NULL);
			else {
				printf("Child process %d will execute the command %s\n", getpid(), command);
				strcpy (cmd, "/bin/");
				strcat (cmd, command);
				execve (cmd, parameters, envp);
			}
		}
		
		
	}
	return 0;
}


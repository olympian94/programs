#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#define SHM_SIZE 1024  //1k shared memory segment
int main(int argc, char *argv[])
{
	pid_t pid;
	key_t key;
	int shmid;
	char *data;
	int mode;
	//make the key
	if((key = ftok("shmdemo.c",'R')) == -1)
	{
		perror("ftok");
		exit(1);
	}
	//connect and create the segment
	if((shmid = shmget(key,SHM_SIZE, 0644|IPC_CREAT))==-1)
	{
		perror("shmget");
		exit(1);
	}

	int i=0;
	for(i=0; i<2; i++)
		pid=fork();

	//attach to the segment to get a ptr 
	data = shmat(shmid, (void*)0,0);
	if(data == (char*)(-1))
	{
		perror("shmat");
		exit(1);
	}
	//read or modify the segment
	if(argc==2)
	{
		printf("writing to segment: \"%s\"\n",argv[1]);
		strncpy(data,argv[1],SHM_SIZE);
	}
	else
	{
		printf("segment contains: \"%s\"\n",data);
	}
	//detach from the segment
	if(shmdt(data)==-1)
	{
		perror("shmdt");
		exit(1);
	}

	return 0;
}

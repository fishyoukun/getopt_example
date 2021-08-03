#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int ch;
	printf("enter\n");
	int readflag = 0;
	int writeflag = 0;
	unsigned int addr = 0;
	char value = 0;

	while ((ch = getopt(argc,argv,"r:w:h")) != -1)
	{
		printf("optind: %d\n",optind);
		switch(ch)
		{
		case 'r':
			printf("arg r parameter %s\n",optarg);
			addr = strtol(optarg,NULL,0);
			readflag = 1;
			break;
		case 'w':
			printf("arg w parameter %s\n",optarg);
			addr = strtol(optarg,NULL,0);
			value = (char)(strtol(argv[optind],NULL,0));
			writeflag = 1;
			break;
		case 'h':
			printf("print manual\n");
			break;
		default:
			printf("default");
			break;
		}
	}
	if (readflag)
	{
		//printf("argv[%d] = %s",optind-1,optarg);
		printf("read addr 0x%x\n",addr);
	}
	if (writeflag)
	{
		printf("write addr 0x%x to value 0x%x\n",addr,value);
	}
	printf("return\n");
	return 0;
}

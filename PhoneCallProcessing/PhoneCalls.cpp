#include <stdio.h>
#include <ctime>

int main ()
{
	time_t rawtime = 1187253017;
	struct tm timeinfo;
	char timebuf[26];

	int error;
	error = localtime_s( &timeinfo,&rawtime );
	if (error)
	{
		printf("Invalid argument to _localtime64_s.");
		return(1);
	}

	error = asctime_s (timebuf,26,&timeinfo);
	if (error)
	{
		printf("Invalid argument to asctime_s.");
		return(1);
	}

	printf( "%s \n", timebuf );

	return 0;
}
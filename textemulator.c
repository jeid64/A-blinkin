/*

Infosys Scroll Test
Michael J Moffitt 2014

*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "letters.h"

#define INFOSYS_DEFAULT_DELAY 90000

#define INFOSYS_SIM_WIDTH 3
#define INFOSYS_SIM_ZERO "   "
#define INFOSYS_SIM_ONE "###"

void print_msg(char *msg)
{

	int len = 0;
	for (int i = 0; i < 512; i++)
	{
		if (msg[i] == '\0')
		{
			len = i;
			break;
		}
	}

	for (unsigned int i = 0; i < len * 4; i++)
	{
		for (int k = 0; k < INFOSYS_SIM_WIDTH; k++)
		{
			char input = get_char_section(msg[i/4], i % 4);
			for (unsigned int j = 0; j < 8; j++)
			{
				if ((((unsigned int)input >> (7-j)) % 2) == 0)
				{
					printf(INFOSYS_SIM_ZERO);
				}
				else
				{
					printf(INFOSYS_SIM_ONE);
				}
			}
			printf("\n");
		}
		usleep(INFOSYS_DEFAULT_DELAY);
	}
}

int main(int argc, char **argv)
{
	char *msg = NULL;
	if (argc < 2)
	{
		printf("Usage: %s message\n",argv[0]);
		return 0;
	}
	for (unsigned int n = 1; n < argc; n++)
	{
		print_msg(argv[n]);
		print_msg(" ");
	}
	return 0;
}

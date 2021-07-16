#include "../includes/so_long.h"

#include <stdio.h>

int process_key(int key, void *param)
{
	(void) param;
	printf("Key %d was pressed\n", key);
	return (0);
}
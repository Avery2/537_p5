#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) 
{
	printf(1, "mencrypt returned value %d\n", mencrypt("0x3500", 10));
    exit();
} 

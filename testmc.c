#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"

int main(void) 
{
	char *ptr = sbrk(PGSIZE); // Allocate one page
	mencrypt(ptr, 1); // Encrypt the pages
	struct pt_entry pt_entry; 
	getpgtable(&pt_entry, 1); // Get the page table information for newly allocated page

	printf(1, "mencrypt returned value %d\n", mencrypt("0x3500", 10));
    exit();
} 

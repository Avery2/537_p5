#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_mencrypt(void)
{
	char* virtual_addr;
	int len;
	if(argint(0, &len) < 0)
	 return -1;
	if(argptr(1, &virtual_addr, sizeof(char*)) < 0)
	 return -1;
	// Should find what page virtual_addr lies in, and encrypt that page
	// IF that page is not already (fully or partially) encrypted




	// For learning, know how to:
	//1. How to grab certain entry from the page table
	// Start at size (sz) and walk down to 1
	// using walkpgdir(VA) we can get a PTE for some VA (increment by PGSIZE)
	// myproc()->pgdir // does something... I think it is a parameter to walkpgdir
	// myproc()->pgdir gives an array of PTEs
	// walkpgdir(pgdir, VA, 0)




	//2. How to change a certain bit in the page entry
	//3. How to access the physical memory from the kernel

	return -1;
}
























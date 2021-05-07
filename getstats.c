#include "types.h"
#include "user.h"
#include "getstats.h"

int main(void) {
  struct statistics p;
  if(!getstats(&p)) {
    printf(1, "number of system calls made = %d\n",p.system_calls);
    printf(1, "number of all hardware interrupts = %d\n",p.hwInterrupts);
    printf(1, "number of bytes transferred by read = %d\n",p.bytes_transferred_by_read);
    printf(1, "number of processes forked = %d\n",p.processes_forked);
    printf(1, "number of free pages = %d\n",p.free_pages);
    printf(1, "number of free buffers = %d\n",p.free_buffers);
    printf(1, "number of free struct-files = %d\n",p.free_struct_files);
    printf(1, "number of free inode = %d\n",p.free_inodes);
    printf(1, "number of free blocks on disk = %d\n",p.free_blocks_on_disk);
    printf(1, "Number of context switches = %d\n", p.context_switches);
  }
  else {
    printf(1, "Error\n");
  }
  exit();
}
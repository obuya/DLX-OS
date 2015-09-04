#include "usertraps.h"
#include "misc.h"
void hello(int);
void main (int argc, char *argv[])
{
  int i;
  static int  *p=0;
  int *pointer1;
  int *pointer2;
  int *pointer3;
  int *pointer4;
  int *pointer5;
  int *pointer6;
  sem_t s_procs_completed; // Semaphore to signal the original process that we're done
  if (argc != 2) { 
    Printf("Usage: %s <handle_to_procs_completed_semaphore>\n"); 
    Exit();
  } 

  // Convert the command-line strings into integers for use as handles
  s_procs_completed = dstrtol(argv[1], NULL, 10);

  // Now print a message to show that everything worked
  
 // Printf("hello_world (%d): Hello world!\n", getpid());
 
 // hello(i); //used to test stack grow
 // Printf(p[100000000]);  //used to test reaching somewhere outside the range of virtual memory
 // Printf(p[125000]); //used to test reaching withn virtual memory but not in user stack
//  for(i=0;i<10000;i++);
  pointer1=malloc(32);
 // Printf("pointer is 0x%d\n",pointer1);
  pointer2=malloc(64);
//  Printf("pointer is 0x%d\n",pointer2);
  pointer3=malloc(23);
//  Printf("pointer is 0x%d\n",pointer3);
  pointer4=malloc(128);
//  Printf("pointer is 0x%d\n",pointer4);
  pointer5=malloc(256);
//  Printf("pointer is 0x%d\n",pointer5);
  pointer6=malloc(256);
//  Printf("pointer is 0x%d\n",pointer6);
  mfree(pointer1);
  mfree(pointer2);
  mfree(pointer3);
  mfree(pointer4);
  mfree(pointer5);
  mfree(pointer6);
  // Signal the semaphore to tell the original process that we're done
  if(sem_signal(s_procs_completed) != SYNC_SUCCESS) {
    Printf("hello_world (%d): Bad semaphore s_procs_completed (%d)!\n", getpid(), s_procs_completed);
    Exit();
  }

  Printf("hello_world (%d): Done!\n", getpid());
}
void hello(int i)
{
  int test[100];
  int j;
  for(j=0;j<100;j++){
  test[j]=i;
  }
  Printf("hello_world, i= %d\n",i);
  if(i>0){
  i--;
  hello(i);
  }
}
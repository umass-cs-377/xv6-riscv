#define NPROC 64

struct pstat {
  int inuse[NPROC]; // whether this slot of the process table is in use (1 or 0)
  int pid[NPROC];   // PID of each process
  int priority[NPROC];  // current priority level of each process (0-3)
  
  // TODO change this to enum state
  int state[NPROC];  // current state (e.g., SLEEPING or RUNNABLE) of each process
  int ticks[NPROC][4];  // number of ticks each process has accumulated 
			// RUNNING/SCHEDULED at each of 4 priorities
  int wait_ticks[NPROC][4]; // number of ticks each process has waited before being scheduled
};

# Operating Systems

## Processes

### Fork

A `fork` is a system call used to create a new process by duplicating the calling process.
The new process is called the child process, and the original process is called the parent process.

The child processes runs concurrently with the parent process and has its own unique process ID (PID).

Parent and child processes share the file descriptors, but they have separate memory spaces.

#### Fork Return Values

`fork()` uses a return type of `pid_t`, which is a signed integer type used to represent process IDs.

The return value of `fork()` is:

1. 0 for the child process
2. Greater than 0 for the parent process (the child's process ID)

`getpid()` returns the process ID of the calling process.
`getppid()` returns the parent process ID of the calling process.

### Orphan process

An orphan process is a process that continues to run after its parent process has terminated or finished.
When a parent process ends before its child processes, the child processes become orphaned.

In most Unix-like operating systems, orphaned processes are adopted by the init process (process ID 1),
which becomes their new parent and will reap their exit status when they terminate.

### Zombie process

A zombie process is a process that has completed execution but still has an entry in the process table.

This happens when a child process terminates but its parent process hasn't yet called `wait()` or `waitpid()` to retrieve the child's exit status.
The zombie process has released its resources but maintains its process ID in the process table until the parent process acknowledges its termination.

Unlike orphan processes, zombies cannot be adopted by init.
They will remain zombies until their parent process reads their exit status or the parent process terminates
(at which point they're adopted by init which immediately reaps them).

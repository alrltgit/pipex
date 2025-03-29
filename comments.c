#include <unistd.h>
//functions:
// Pipex:
// The access() function checks whether a file or directory exists and whether the calling process has the required permissions to access it.
// Prototype:
int access(const char *pathname, int mode);
// Parameters
// pathname → The file or directory to check.
// mode → The type of check to perform (permissions).
// Return Value
// Returns 0 if the requested access is allowed.
// Returns -1 if access is denied or an error occurs (and sets errno).
// Modes (mode argument)
// ConstantMeaning
// F_OK Checks if the file exists
// R_OK Checks if the file is readable
// W_OK Checks if the file is writable
// X_OK Checks if the file is executable

// Both dup() and dup2() are used to duplicate file descriptors, commonly for redirecting input/output in shell-like programs:
// Prototype:
int dup(int oldfd);
// creates a copy of an existing file descriptor;
// the new fd always takes the lowest available number;
// both fds now point to the same file and share file offset and status.
// Return value:
// returns new file descriptor on success;
// returns -1 on failure (sets errno).
// Prototype:
int dup2(int oldfd, int newfd);
// similar to dup(), but allows specifying which fd number (newfd) to use;
// if newfd is already open, it's closed automatically before being replaced.
// Return value:
// returns newfd on success;
// return -1 on failure (sets errno).

// The execve() function replaces the current process image with a new one. It is used to execute a new program within the same process, discarding the previous program.
// Prototype:
int execve(const char *pathname, char *const argv[], char *const envp[]);
// Parameters
// pathname → The absolute or relative path to the executable file.
// argv[] → Argument list for the new program (argv[0] is the program name).
// envp[] → Array of environment variables (can be inherited from the current process).
// Return Value
// Does NOT return if successful (the new program completely replaces the calling process).
// Returns -1 if an error occurs, and errno is set.
// Common Use Cases
// 1. Implementing shells, where a command is executed as a new process.
// 2. Running other programs from within a process (e.g., executing scripts, binaries).
// 3. Creating custom exec wrappers for system calls.

// Prototype:
pid_t fork(void);
// Creates a new child process that is a duplicate of the parent.
// The child and parent execute the same code after fork().
// Return Values:
// Parent process: Returns the child’s PID.
// Child process: Returns 0.
// Failure: Returns -1.

// Prototype:
int pipe(int pipefd[2]);
// Creates a unidirectional communication channel between processes.
// pipefd[0] → Read end, pipefd[1] → Write end.
// Returns:
// 0 on success.
// -1 on failure.

// Prototype:
int unlink(const char *pathname);
// Removes a file from the filesystem.
// If the file is open, it is deleted when all references close.
// Returns:
// 0 on success.
// -1 on failure.

// Prototype:
pid_t wait(int *status);
// How It Works
// Pauses parent process until any child terminates.
// Stores the exit status in status (if not NULL).
// Returns:
// Child’s PID on success.
// -1 on failure.

// Prototype:
pid_t waitpid(pid_t pid, int *status, int options);
// Similar to wait(), but allows waiting for a specific child.
// pid options:
// > 0: Wait for the specific process with this PID.
// -1: Same as wait(), waits for any child.
// 0: Waits for children in the same process group.
// options can include:
// WNOHANG → Returns immediately if no child has exited.
// WUNTRACED → Reports stopped children.

// Function	Purpose
// fork()	Creates a new process (child)
// pipe()	Creates an inter-process communication channel
// unlink()	Deletes a file
// wait()	Parent waits for any child process to terminate
// waitpid()	Parent waits for a specific child process
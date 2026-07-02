# Philosophers

*This project has been created as part of the 42 curriculum by joaobarb.*

## Description

**Philosophers** is a classic concurrency problem that explores thread synchronization, mutexes, and deadlock prevention. The project simulates the famous "Dining Philosophers Problem" proposed by Edsger Dijkstra.

### The Problem

Several philosophers sit at a round table with a large bowl of spaghetti in the center. Between each pair of philosophers, there is a single fork. A philosopher needs two forks to eat.

**Philosophers alternate between three states:**
- **Thinking** - The philosopher is contemplating life
- **Eating** - The philosopher has acquired two forks and is eating
- **Sleeping** - The philosopher is resting after eating

### Project Goals

The main objectives of this project are:
- Learn about threads and processes
- Understand mutexes and their role in preventing data races
- Implement solutions to avoid deadlocks
- Practice resource sharing and synchronization
- Ensure no philosopher dies of starvation

### Implementation Details

This implementation uses:
- **Threads** for each philosopher
- **Mutexes** for fork management and shared resource protection
- **Waiter algorithm** to prevent deadlock and ensure fair resource distribution
- **Monitor thread** to detect philosopher deaths and completion conditions

The solution implements a fair scheduling algorithm that prioritizes the hungriest philosophers (those who haven't eaten for the longest time), preventing starvation while maintaining deadlock-free execution.

### Function Behaviour Replication

In this case, I needed to replicate the behaviour of the functions:
- **pthread_cond_init**
- **pthread_cond_destroy**
- **pthread_cond_wait**
- **pthread_cond_broadcast**
from the *pthread.h* library. I used the manuals to ensure that my functions would have the same result as the original ones. The functions are replicated on the *utilities_pthread.c* file

## Instructions

### Compilation

To compile the project, run:

```bash
make
```

This will create the `philo` executable.

### Execution

The program requires the following arguments:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

**Arguments:**
- `number_of_philosophers`: The number of philosophers and forks (must be > 0)
- `time_to_die`: Time in milliseconds before a philosopher dies without eating
- `time_to_eat`: Time in milliseconds it takes for a philosopher to eat
- `time_to_sleep`: Time in milliseconds a philosopher spends sleeping
- `[number_of_times_each_philosopher_must_eat]`: (Optional) If specified, the simulation stops when all philosophers have eaten at least this many times

**Example:**

```bash
./philo 5 800 200 200
```

This creates a simulation with 5 philosophers where:
- A philosopher dies if they don't eat within 800ms
- Eating takes 200ms
- Sleeping takes 200ms

**Example with meal limit:**

```bash
./philo 5 800 200 200 7
```

The simulation stops when all 5 philosophers have eaten at least 7 times.

### Output Format

The program outputs timestamped logs of philosopher actions:

```
      0 | Philosopher 1 is thinking
      0 | Philosopher 2 has taken a fork
      0 | Philosopher 2 has taken a fork
      0 | Philosopher 2 is eating
    200 | Philosopher 2 is sleeping
    200 | Philosopher 1 has taken a fork
    200 | Philosopher 1 has taken a fork
    200 | Philosopher 1 is eating
```

**Example of an easily readable output:** 

For cleaner debug and testing, simply use the following syntaxe:

```bash
./philo 5 800 200 200 5 | tail -n 5
```

**Easy way to check the system libraries functions used:**

```bash
nm -u ./philo
```

This extracts the last five lines from the program output, executing it without printing all of the messages before.

Each line shows:
- Timestamp in milliseconds from simulation start
- Philosopher ID
- Action performed

### Additional Make Commands

```bash
make clean   # Remove object files
make fclean  # Remove object files and executable
make re      # Recompile everything from scratch
```

## Technical Choices

### Architecture

The project is organized into multiple files following 42's Norm requirements:
- **main.c**: Entry point, cleanup, and safe printing
- **init.c**: Initialization of data structures and philosophers
- **philo_actions.c**: Core philosopher behavior (eat, sleep, think, routine)
- **threads.c**: Thread creation, joining, and monitoring
- **utilities.c - utilities_six.c**: Helper functions split across multiple files to respect the 5-functions-per-file limit

### Synchronization Strategy

1. **Fork Reservation System**: Uses a waiter mutex and condition variable to manage fork allocation
2. **Priority Scheduling**: Implements a "hungriest philosopher first" algorithm to prevent starvation
3. **Deadlock Prevention**: Total ordering of fork acquisition based on memory addresses
4. **Protected State**: Meal times and counts protected by per-philosopher mutexes

### Key Features

- ✅ No data races
- ✅ No deadlocks
- ✅ Fair resource distribution (prevents starvation)
- ✅ Accurate death detection
- ✅ Proper cleanup of all resources
- ✅ Handles edge cases (single philosopher, zero meals required)

## Resources

### Classic References & Documentation

1. **Edsger Dijkstra's Dining Philosophers Problem**
   - Original paper introducing the problem as a synchronization challenge
   - Foundation for understanding concurrent resource allocation

2. **POSIX Threads (Pthreads) Documentation**
   - [man pthread_create](https://man7.org/linux/man-pages/man3/pthread_create.3.html)
   - [man pthread_mutex_init](https://man7.org/linux/man-pages/man3/pthread_mutex_init.3.html)
   - [man pthread_join](https://man7.org/linux/man-pages/man3/pthread_join.3.html)
   - Essential for understanding thread lifecycle and mutex operations

3. **The Linux Programming Interface** by Michael Kerrisk
   - Chapters 28-29 cover pthreads and thread synchronization in depth
   - Practical examples and best practices for concurrent programming

4. **Operating Systems: Three Easy Pieces** (OSTEP)
   - Chapter on Concurrency and Synchronization Primitives
   - Explains deadlock prevention and starvation avoidance strategies

5. **man pages (Linux)**
   - `man usleep` - precision sleep functionality
   - `man gettimeofday` - timestamp acquisition for simulation timing
   - `man write` - system call for safe output in multithreaded context

### Tutorials & Articles

- POSIX Threads Programming Guide
- Lock-Free Programming concepts for deadlock prevention
- Waiter pattern implementations in concurrent systems

### How AI Was Used

**AI assistance was utilized in the following areas:**

1. **Architecture & Design**
   - Validating the waiter algorithm approach for deadlock prevention
   - Reviewing synchronization strategy to ensure thread-safety
   - Optimizing the "hungriest philosopher first" scheduling logic

2. **Constraint Management**
   - Identifying which standard library functions were forbidden vs. allowed
   - Help replacing forbidden functions (e.g., `pthread_cond_wait`, `exit`) with allowed alternatives
   - Converting condition variables to polling mechanisms with `usleep`

3. **Testing & Validation**
   - Verifying edge cases (single philosopher, zero meals required)
   - Ensuring accurate timestamp logging and death detection
   - Validating that no data races or deadlocks occur under various thread schedules

4. **Documentation**
   - Clarifying implementation decisions and technical choices
   - Documenting the synchronization strategy and its rationale
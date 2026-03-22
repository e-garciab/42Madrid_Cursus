*This project has been created as part of the 42 curriculum by egarcia2.*

# Philosophers

## Description

Philosophers is a project based on the classic **Dining Philosophers Problem**, originally formulated by Edsger Dijkstra. It simulates a concurrency scenario where a number of philosophers sit around a round table with a bowl of spaghetti in the center. There is one fork between each pair of adjacent philosophers.

Each philosopher alternates between three states: **thinking**, **eating**, and **sleeping**. To eat, a philosopher must pick up both the fork to their left and the fork to their right. Since forks are shared resources, the challenge is to synchronize access so that no philosopher starves and no deadlock or data race occurs.

The project implements the simulation using **threads** and **mutexes** to protect shared resources. Each philosopher runs as an independent thread, and each fork is protected by a mutex to prevent simultaneous access.

## Instructions

### Requirements
* Unix-like operating system (Linux or macOS)
* `gcc` or `cc`
* Make

### Compilation
Clone the repository and compile the project using:

`make`

This will produce an executable named `philo`.

#### Available Makefile rules:
* `make` or `make all` – compile the project
* `make clean` – remove object files
* `make fclean` – remove object files and the executable
* `make re` – recompile everything

### Execution
Run the program with:

```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Arguments:

| Argument | Description |
|---|---|
| `number_of_philosophers` | Number of philosophers (and forks) at the table |
| `time_to_die` | Time in ms before a philosopher dies if they haven't started eating |
| `time_to_eat` | Time in ms a philosopher spends eating (holds both forks) |
| `time_to_sleep` | Time in ms a philosopher spends sleeping |
| `number_of_times_each_philosopher_must_eat` | *(Optional)* Simulation stops when all philosophers have eaten this many times |


## Resources

### Technical References Used for the Project

The following resources were used to understand and implement the project:

* [Unix Threads in C](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2) - CodeVault playlist covering pthreads, mutexes and concurrency in C. 

* [The Dining Philosophers Problem](https://www.youtube.com/watch?v=FYUi-u7UWgw) - conceptual explanation of the classic problem and its solutions.

* For understanding [threads, mutexes and concurrence programming](https://www.codequoi.com/en/threads-mutexes-and-concurrent-programming-in-c/) - in-depth articles directly related to the philosophers project. 

* Linux man pages - `man pthread_create`, `man pthread_mutex_init`, `man gettimeofday`, `man usleep`


### Use of Artificial Intelligence
Artificial Intelligence tools were used responsibly and selectively during the development of this project, in accordance with the 42 guidelines.

Specifically, AI assistance was used for:
* Clarifying Unix concepts (threads, mutex, concurrency),
* Detecting and reasoning about potential errors, overflows, and undefined behaviour,
* Designing manual tests cases to validate the program behaviour,
* Improving code readability and documentation.

AI was not used to blindly generate complete solutions. The final implementation reflects my own understanding and learning process, with peer review and manual debugging playing a central role.

---

### Author
* egarcia2
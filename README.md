# Mini-libc

A minimalistic implementation of a standard C library for Linux systems. This project provides a freestanding libc built on Linux syscalls and implements a subset of the standard C library API. It is designed for educational purposes and for use in a university assignment.

## Features

- **String Functions**
  Implements common string operations:
  - `strcpy()`, `strcat()`, `strlen()`
  - `strncpy()`, `strncat()`
  - `strcmp()`, `strncmp()`, `strstr()`, `strrstr()`
  - `memcpy()`, `memset()`, `memmove()`, `memcmp()`

- **File I/O Functions**
  Basic support for POSIX file operations:
  - `open()`, `close()`, `lseek()`
  - `stat()`, `fstat()`
  - `truncate()`, `ftruncate()`

- **Memory Management**
  Fundamental dynamic memory routines:
  - `malloc()`, `free()`
  - `calloc()`, `realloc()`, `realloc_array()`
  - A simple memory list manager in `src/crt/mem_list.c`

- **Time and I/O**
  Additional functions:
  - `puts()`
  - `nanosleep()` and `sleep()`

- **System Call Interface**
  Direct system call invocations are used via the `syscall()` function defined in `src/syscall.c`.

- **Automated Testing and Linting**
  A custom checker script with Docker integration (see `local.sh` and [checker/checker.sh](checker/checker.sh)) and style linting via [checkpatch.pl](checkpatch.pl).

## Building the Project

There are multiple ways to build and test the project.

### Building mini-libc

- **Direct Build in `src/`**:
  Enter the `src/` directory and run:

  ```bash
  make
  ```

- **Building Samples**:
  To compile sample programs:

  ```bash
  cd samples
  make
  ```

### Running the Checker

There are automated scripts to build a Docker container, run tests, and perform static analysis.

- **Local Docker Build**:
  To build the Docker image using the provided script:

  ```bash
  ./local.sh docker build
  ```

- **Run the Checker in Docker**:
  To run the checker inside the Docker container:

  ```bash
  ./local.sh checker
  ```

- **Push the Checker Image**:
  Optionally, push the Docker image to the remote registry:

  ```bash
  ./local.sh docker push --user <username> --token <token>
  ```

## Testing and Grading

Tests for functionality and style are located in the `tests/` directory.

- **Run Tests and Grade**:
  From the [tests](tests) directory, execute:

  ```bash
  ./grade.sh
  ```

A successful test run shows scores for correctness (up to 90 points) and for coding style (up to 10 points).

## Implementation Details

- **Directory Structure**:
  - [src](src): The core implementation of mini-libc.
  - [samples](samples): Example programs to demonstrate the use of mini-libc.
  - [tests](tests): Automated tests for validation and grading.
  - [checker](checker): High-level checker script and supporting files for static analysis.
  - [local.sh](local.sh): Script to manage Docker builds, testing, and pushing images.
  - [checkpatch.pl](checkpatch.pl): Linter script to check style and license headers.

- **Docker Integration**:
  The project uses Docker to provide a consistent build and test environment. The [Dockerfile](Dockerfile) defines the build environment.

- **Memory Management**:
  A basic memory list manager is implemented in `src/crt/mem_list.c` along with its header in [src/include/internal/mm/mem_list.h](src/include/internal/mm/mem_list.h).

- **System Call Handling**:
  The function [`syscall()`](src/syscall.c) manages low-level system call invocations.

## Example Workflow

1. **Build mini-libc**:
   ```bash
   cd src
   make
   ```

2. **Run Automated Tests and Grade**:
   ```bash
   cd ../tests
   ./grade.sh
   ```

3. **Run the Local Checker in Docker**:
   ```bash
   ./local.sh docker build
   ./local.sh checker
   ```

4. **Fast Run Automated Tests and Grade (no linter, no prebuilds)**:
   ```bash
   cd tests
   make check
   ```
// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
  int call = syscall(__NR_close, fd);
  if (call < 0) {
    errno = -call;
    return -1;
  }

  return call;
}

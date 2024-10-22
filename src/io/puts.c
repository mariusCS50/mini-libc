// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <string.h>

int puts(const char *str)
{
  int call = write(1, str, strlen(str));

  if (call < 0) {
    errno = -call;
    return -1;
  }

  call = write(1, "\n", 1);

  if (call < 0) {
    errno = -call;
    return -1;
  }

  return call;
}

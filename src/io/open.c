// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
  int mode = 0;
	va_list args;
  va_start(args, flags);
  mode = va_arg(args, int);
  va_end(args);

  int call = syscall(__NR_open, filename, flags, mode);
  if (call < 0) {
    errno = -call;
    return -1;
  }

	return call;
}

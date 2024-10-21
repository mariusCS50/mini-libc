// SPDX-License-Identifier: BSD-3-Clause

#include <internal/syscall.h>
#include <errno.h>
#include <time.h>

int nanosleep(const struct timespec *duration, struct timespec *rem)
{
	int call = syscall(__NR_nanosleep, duration, rem);
  if (call < 0) {
    errno = -call;
    return -1;
  }

  return call;
}

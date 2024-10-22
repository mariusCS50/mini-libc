// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
  struct timespec duration = {seconds, 0};
	return nanosleep(&duration, NULL);
}

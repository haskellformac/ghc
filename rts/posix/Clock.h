/* -----------------------------------------------------------------------------
 *
 * (c) The GHC Team, 2012
 *
 * Posix monotonic clock
 *
 * ---------------------------------------------------------------------------*/

#ifndef POSIX_CLOCK_H
#define POSIX_CLOCK_H

#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif

#ifdef HAVE_TIME_H
# include <time.h>
#endif

#ifdef HAVE_SYS_TIME_H
# include <sys/time.h>
#endif

#if defined(darwin_HOST_OS) && MAC_OS_X_VERSION_MIN_REQUIRED < 101200
# define DARWIN_IGNORE_CLOCK_GETTIME
# include <mach/mach.h>
# include <mach/mach_time.h>
#elif defined(HAVE_CLOCK_GETTIME)
# ifdef _POSIX_MONOTONIC_CLOCK
#  define CLOCK_ID CLOCK_MONOTONIC
# else
#  define CLOCK_ID CLOCK_REALTIME
# endif
#endif

#endif /* POSIX_CLOCK_H */

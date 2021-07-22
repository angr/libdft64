#ifndef __SYSCALL_DESC_H__
#define __SYSCALL_DESC_H__

#include "libdft_api.h"

#define SYSCALL_MAX __NR_sched_getattr + 1 /* max syscall number */

/* system call descriptor */
typedef struct {
  size_t nargs;                           /* number of arguments */
  size_t save_args;                       /* flag; save arguments */
  size_t retval_args;                     /* flag; returns value in arguments */
  size_t map_args[SYSCALL_ARG_NUM];       /* arguments map */
  void (*pre)(THREADID, syscall_ctx_t *); /* pre-syscall callback */
  void (*post)(THREADID, syscall_ctx_t *); /* post-syscall callback */
} syscall_desc_t;

/* syscall API */
int syscall_set_pre(syscall_desc_t *, void (*)(THREADID, syscall_ctx_t *));
int syscall_clr_pre(syscall_desc_t *);
int syscall_set_post(syscall_desc_t *, void (*)(THREADID, syscall_ctx_t *));
int syscall_clr_post(syscall_desc_t *);

#define SYS_ACCEPT	5
#define SYS_GETSOCKNAME	6
#define SYS_GETPEERNAME	7
#define SYS_SOCKETPAIR	8
#define SYS_RECV	10
#define SYS_RECVFROM	12
#define SYS_GETSOCKOPT	15
#define SYS_RECVMSG	17
#define SYS_ACCEPT4	18
#define SYS_RECVMMSG	19

#endif /* __SYSCALL_DESC_H__ */

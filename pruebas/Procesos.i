# 1 "Procesos.c"
# 1 "<interno>"
# 1 "<l\355nea de orden>"
# 1 "Procesos.c"
# 1 "/usr/include/sys/types.h" 1 3 4
# 27 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 295 "/usr/include/features.h" 3 4
# 1 "/usr/include/sys/cdefs.h" 1 3 4
# 296 "/usr/include/features.h" 2 3 4
# 318 "/usr/include/features.h" 3 4
# 1 "/usr/include/gnu/stubs.h" 1 3 4
# 319 "/usr/include/features.h" 2 3 4
# 28 "/usr/include/sys/types.h" 2 3 4



# 1 "/usr/include/bits/types.h" 1 3 4
# 28 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 29 "/usr/include/bits/types.h" 2 3 4


# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.3.2/include/stddef.h" 1 3 4
# 213 "/usr/lib/gcc-lib/i386-redhat-linux/3.3.2/include/stddef.h" 3 4
typedef unsigned int size_t;
# 32 "/usr/include/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
# 62 "/usr/include/bits/types.h" 3 4
typedef struct
{
  long __val[2];
} __quad_t;
typedef struct
{
  __u_long __val[2];
} __u_quad_t;
# 129 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/typesizes.h" 1 3 4
# 130 "/usr/include/bits/types.h" 2 3 4






 typedef unsigned long long int __dev_t;
 typedef unsigned int __uid_t;
 typedef unsigned int __gid_t;
 typedef unsigned long int __ino_t;
 typedef unsigned long long int __ino64_t;
 typedef unsigned int __mode_t;
 typedef unsigned int __nlink_t;
 typedef long int __off_t;
 typedef long long int __off64_t;
 typedef int __pid_t;
 typedef struct { int __val[2]; } __fsid_t;
 typedef long int __clock_t;
 typedef unsigned long int __rlim_t;
 typedef unsigned long long int __rlim64_t;
 typedef unsigned int __id_t;
 typedef long int __time_t;
 typedef unsigned int __useconds_t;
 typedef long int __suseconds_t;

 typedef int __daddr_t;
 typedef long int __swblk_t;
 typedef int __key_t;


 typedef int __clockid_t;


 typedef int __timer_t;


 typedef long int __blksize_t;




 typedef long int __blkcnt_t;
 typedef long long int __blkcnt64_t;


 typedef unsigned long int __fsblkcnt_t;
 typedef unsigned long long int __fsblkcnt64_t;


 typedef unsigned long int __fsfilcnt_t;
 typedef unsigned long long int __fsfilcnt64_t;

 typedef int __ssize_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


 typedef int __intptr_t;


 typedef unsigned int __socklen_t;
# 32 "/usr/include/sys/types.h" 2 3 4



typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;



typedef __ino_t ino_t;
# 62 "/usr/include/sys/types.h" 3 4
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;
# 100 "/usr/include/sys/types.h" 3 4
typedef __pid_t pid_t;




typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 133 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 74 "/usr/include/time.h" 3 4


typedef __time_t time_t;



# 92 "/usr/include/time.h" 3 4
typedef __clockid_t clockid_t;
# 104 "/usr/include/time.h" 3 4
typedef __timer_t timer_t;
# 134 "/usr/include/sys/types.h" 2 3 4
# 147 "/usr/include/sys/types.h" 3 4
# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.3.2/include/stddef.h" 1 3 4
# 148 "/usr/include/sys/types.h" 2 3 4



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
# 163 "/usr/include/sys/types.h" 3 4
typedef char int8_t;
typedef short int int16_t;
typedef int int32_t;






typedef unsigned char u_int8_t;
typedef unsigned short int u_int16_t;
typedef unsigned int u_int32_t;




typedef int register_t;
# 213 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
# 37 "/usr/include/endian.h" 3 4
# 1 "/usr/include/bits/endian.h" 1 3 4
# 38 "/usr/include/endian.h" 2 3 4
# 214 "/usr/include/sys/types.h" 2 3 4


# 1 "/usr/include/sys/select.h" 1 3 4
# 31 "/usr/include/sys/select.h" 3 4
# 1 "/usr/include/bits/select.h" 1 3 4
# 32 "/usr/include/sys/select.h" 2 3 4


# 1 "/usr/include/bits/sigset.h" 1 3 4
# 23 "/usr/include/bits/sigset.h" 3 4
typedef int __sig_atomic_t;




typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
# 35 "/usr/include/sys/select.h" 2 3 4



typedef __sigset_t sigset_t;





# 1 "/usr/include/time.h" 1 3 4
# 118 "/usr/include/time.h" 3 4
struct timespec
  {
    __time_t tv_sec;
    long int tv_nsec;
  };
# 45 "/usr/include/sys/select.h" 2 3 4

# 1 "/usr/include/bits/time.h" 1 3 4
# 69 "/usr/include/bits/time.h" 3 4
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
# 47 "/usr/include/sys/select.h" 2 3 4


typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
# 67 "/usr/include/sys/select.h" 3 4
typedef struct
  {






    __fd_mask __fds_bits[1024 / (8 * sizeof (__fd_mask))];


  } fd_set;






typedef __fd_mask fd_mask;
# 99 "/usr/include/sys/select.h" 3 4

# 109 "/usr/include/sys/select.h" 3 4
extern int select (int __nfds, fd_set * __readfds,
                   fd_set * __writefds,
                   fd_set * __exceptfds,
                   struct timeval * __timeout);
# 128 "/usr/include/sys/select.h" 3 4

# 217 "/usr/include/sys/types.h" 2 3 4


# 1 "/usr/include/sys/sysmacros.h" 1 3 4
# 220 "/usr/include/sys/types.h" 2 3 4
# 231 "/usr/include/sys/types.h" 3 4
typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 266 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/bits/pthreadtypes.h" 1 3 4
# 23 "/usr/include/bits/pthreadtypes.h" 3 4
# 1 "/usr/include/bits/sched.h" 1 3 4
# 83 "/usr/include/bits/sched.h" 3 4
struct __sched_param
  {
    int __sched_priority;
  };
# 24 "/usr/include/bits/pthreadtypes.h" 2 3 4


struct _pthread_fastlock
{
  long int __status;
  int __spinlock;

};



typedef struct _pthread_descr_struct *_pthread_descr;





typedef struct __pthread_attr_s
{
  int __detachstate;
  int __schedpolicy;
  struct __sched_param __schedparam;
  int __inheritsched;
  int __scope;
  size_t __guardsize;
  int __stackaddr_set;
  void *__stackaddr;
  size_t __stacksize;
} pthread_attr_t;







typedef long __pthread_cond_align_t;


typedef struct
{
  struct _pthread_fastlock __c_lock;
  _pthread_descr __c_waiting;
  char __padding[48 - sizeof (struct _pthread_fastlock)
                 - sizeof (_pthread_descr) - sizeof (__pthread_cond_align_t)];
  __pthread_cond_align_t __align;
} pthread_cond_t;



typedef struct
{
  int __dummy;
} pthread_condattr_t;


typedef unsigned int pthread_key_t;





typedef struct
{
  int __m_reserved;
  int __m_count;
  _pthread_descr __m_owner;
  int __m_kind;
  struct _pthread_fastlock __m_lock;
} pthread_mutex_t;



typedef struct
{
  int __mutexkind;
} pthread_mutexattr_t;



typedef int pthread_once_t;
# 150 "/usr/include/bits/pthreadtypes.h" 3 4
typedef unsigned long int pthread_t;
# 267 "/usr/include/sys/types.h" 2 3 4



# 2 "Procesos.c" 2
# 1 "/usr/include/sys/wait.h" 1 3 4
# 28 "/usr/include/sys/wait.h" 3 4


# 1 "/usr/include/signal.h" 1 3 4
# 31 "/usr/include/signal.h" 3 4


# 1 "/usr/include/bits/sigset.h" 1 3 4
# 103 "/usr/include/bits/sigset.h" 3 4
extern int __sigismember (const __sigset_t *, int);
extern int __sigaddset (__sigset_t *, int);
extern int __sigdelset (__sigset_t *, int);
# 34 "/usr/include/signal.h" 2 3 4







typedef __sig_atomic_t sig_atomic_t;

# 58 "/usr/include/signal.h" 3 4
# 1 "/usr/include/bits/signum.h" 1 3 4
# 59 "/usr/include/signal.h" 2 3 4
# 73 "/usr/include/signal.h" 3 4
typedef void (*__sighandler_t) (int);




extern __sighandler_t __sysv_signal (int __sig, __sighandler_t __handler)
     ;
# 88 "/usr/include/signal.h" 3 4


extern __sighandler_t signal (int __sig, __sighandler_t __handler) ;
# 102 "/usr/include/signal.h" 3 4

# 114 "/usr/include/signal.h" 3 4
extern int kill (__pid_t __pid, int __sig) ;






extern int killpg (__pid_t __pgrp, int __sig) ;




extern int raise (int __sig) ;




extern __sighandler_t ssignal (int __sig, __sighandler_t __handler) ;
extern int gsignal (int __sig) ;




extern void psignal (int __sig, const char *__s);
# 149 "/usr/include/signal.h" 3 4
extern int __sigpause (int __sig_or_mask, int __is_sig);




extern int sigpause (int __mask) ;
# 177 "/usr/include/signal.h" 3 4
extern int sigblock (int __mask) ;


extern int sigsetmask (int __mask) ;


extern int siggetmask (void) ;
# 197 "/usr/include/signal.h" 3 4
typedef __sighandler_t sig_t;







# 1 "/usr/include/time.h" 1 3 4
# 206 "/usr/include/signal.h" 2 3 4


# 1 "/usr/include/bits/siginfo.h" 1 3 4
# 25 "/usr/include/bits/siginfo.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 26 "/usr/include/bits/siginfo.h" 2 3 4







typedef union sigval
  {
    int sival_int;
    void *sival_ptr;
  } sigval_t;
# 51 "/usr/include/bits/siginfo.h" 3 4
typedef struct siginfo
  {
    int si_signo;
    int si_errno;

    int si_code;

    union
      {
        int _pad[((128 / sizeof (int)) - 3)];


        struct
          {
            __pid_t si_pid;
            __uid_t si_uid;
          } _kill;


        struct
          {
            int si_tid;
            int si_overrun;
            sigval_t si_sigval;
          } _timer;


        struct
          {
            __pid_t si_pid;
            __uid_t si_uid;
            sigval_t si_sigval;
          } _rt;


        struct
          {
            __pid_t si_pid;
            __uid_t si_uid;
            int si_status;
            __clock_t si_utime;
            __clock_t si_stime;
          } _sigchld;


        struct
          {
            void *si_addr;
          } _sigfault;


        struct
          {
            long int si_band;
            int si_fd;
          } _sigpoll;
      } _sifields;
  } siginfo_t;
# 129 "/usr/include/bits/siginfo.h" 3 4
enum
{
  SI_ASYNCNL = -60,

  SI_TKILL = -6,

  SI_SIGIO,

  SI_ASYNCIO,

  SI_MESGQ,

  SI_TIMER,

  SI_QUEUE,

  SI_USER,

  SI_KERNEL = 0x80

};



enum
{
  ILL_ILLOPC = 1,

  ILL_ILLOPN,

  ILL_ILLADR,

  ILL_ILLTRP,

  ILL_PRVOPC,

  ILL_PRVREG,

  ILL_COPROC,

  ILL_BADSTK

};


enum
{
  FPE_INTDIV = 1,

  FPE_INTOVF,

  FPE_FLTDIV,

  FPE_FLTOVF,

  FPE_FLTUND,

  FPE_FLTRES,

  FPE_FLTINV,

  FPE_FLTSUB

};


enum
{
  SEGV_MAPERR = 1,

  SEGV_ACCERR

};


enum
{
  BUS_ADRALN = 1,

  BUS_ADRERR,

  BUS_OBJERR

};


enum
{
  TRAP_BRKPT = 1,

  TRAP_TRACE

};


enum
{
  CLD_EXITED = 1,

  CLD_KILLED,

  CLD_DUMPED,

  CLD_TRAPPED,

  CLD_STOPPED,

  CLD_CONTINUED

};


enum
{
  POLL_IN = 1,

  POLL_OUT,

  POLL_MSG,

  POLL_ERR,

  POLL_PRI,

  POLL_HUP

};
# 273 "/usr/include/bits/siginfo.h" 3 4
typedef struct sigevent
  {
    sigval_t sigev_value;
    int sigev_signo;
    int sigev_notify;

    union
      {
        int _pad[((64 / sizeof (int)) - 3)];



        __pid_t _tid;

        struct
          {
            void (*_function) (sigval_t);
            void *_attribute;
          } _sigev_thread;
      } _sigev_un;
  } sigevent_t;






enum
{
  SIGEV_SIGNAL = 0,

  SIGEV_NONE,

  SIGEV_THREAD,


  SIGEV_THREAD_ID = 4

};
# 209 "/usr/include/signal.h" 2 3 4



extern int sigemptyset (sigset_t *__set) ;


extern int sigfillset (sigset_t *__set) ;


extern int sigaddset (sigset_t *__set, int __signo) ;


extern int sigdelset (sigset_t *__set, int __signo) ;


extern int sigismember (const sigset_t *__set, int __signo) ;
# 241 "/usr/include/signal.h" 3 4
# 1 "/usr/include/bits/sigaction.h" 1 3 4
# 25 "/usr/include/bits/sigaction.h" 3 4
struct sigaction
  {


    union
      {

        __sighandler_t sa_handler;

        void (*sa_sigaction) (int, siginfo_t *, void *);
      }
    __sigaction_handler;







    __sigset_t sa_mask;


    int sa_flags;


    void (*sa_restorer) (void);
  };
# 242 "/usr/include/signal.h" 2 3 4


extern int sigprocmask (int __how, const sigset_t * __set,
                        sigset_t * __oset) ;






extern int sigsuspend (const sigset_t *__set);


extern int sigaction (int __sig, const struct sigaction * __act,
                      struct sigaction * __oact) ;


extern int sigpending (sigset_t *__set) ;






extern int sigwait (const sigset_t * __set, int * __sig);






extern int sigwaitinfo (const sigset_t * __set,
                        siginfo_t * __info);






extern int sigtimedwait (const sigset_t * __set,
                         siginfo_t * __info,
                         const struct timespec * __timeout);



extern int sigqueue (__pid_t __pid, int __sig, const union sigval __val)
     ;
# 297 "/usr/include/signal.h" 3 4
extern const char *const _sys_siglist[65];
extern const char *const sys_siglist[65];


struct sigvec
  {
    __sighandler_t sv_handler;
    int sv_mask;

    int sv_flags;

  };
# 321 "/usr/include/signal.h" 3 4
extern int sigvec (int __sig, const struct sigvec *__vec,
                   struct sigvec *__ovec) ;



# 1 "/usr/include/bits/sigcontext.h" 1 3 4
# 28 "/usr/include/bits/sigcontext.h" 3 4
# 1 "/usr/include/asm/sigcontext.h" 1 3 4
# 18 "/usr/include/asm/sigcontext.h" 3 4
struct _fpreg {
        unsigned short significand[4];
        unsigned short exponent;
};

struct _fpxreg {
        unsigned short significand[4];
        unsigned short exponent;
        unsigned short padding[3];
};

struct _xmmreg {
        unsigned long element[4];
};

struct _fpstate {

        unsigned long cw;
        unsigned long sw;
        unsigned long tag;
        unsigned long ipoff;
        unsigned long cssel;
        unsigned long dataoff;
        unsigned long datasel;
        struct _fpreg _st[8];
        unsigned short status;
        unsigned short magic;


        unsigned long _fxsr_env[6];
        unsigned long mxcsr;
        unsigned long reserved;
        struct _fpxreg _fxsr_st[8];
        struct _xmmreg _xmm[8];
        unsigned long padding[56];
};



struct sigcontext {
        unsigned short gs, __gsh;
        unsigned short fs, __fsh;
        unsigned short es, __esh;
        unsigned short ds, __dsh;
        unsigned long edi;
        unsigned long esi;
        unsigned long ebp;
        unsigned long esp;
        unsigned long ebx;
        unsigned long edx;
        unsigned long ecx;
        unsigned long eax;
        unsigned long trapno;
        unsigned long err;
        unsigned long eip;
        unsigned short cs, __csh;
        unsigned long eflags;
        unsigned long esp_at_signal;
        unsigned short ss, __ssh;
        struct _fpstate * fpstate;
        unsigned long oldmask;
        unsigned long cr2;
};
# 29 "/usr/include/bits/sigcontext.h" 2 3 4
# 327 "/usr/include/signal.h" 2 3 4


extern int sigreturn (struct sigcontext *__scp) ;
# 339 "/usr/include/signal.h" 3 4
extern int siginterrupt (int __sig, int __interrupt) ;

# 1 "/usr/include/bits/sigstack.h" 1 3 4
# 26 "/usr/include/bits/sigstack.h" 3 4
struct sigstack
  {
    void *ss_sp;
    int ss_onstack;
  };



enum
{
  SS_ONSTACK = 1,

  SS_DISABLE

};
# 50 "/usr/include/bits/sigstack.h" 3 4
typedef struct sigaltstack
  {
    void *ss_sp;
    int ss_flags;
    size_t ss_size;
  } stack_t;
# 342 "/usr/include/signal.h" 2 3 4
# 350 "/usr/include/signal.h" 3 4
extern int sigstack (struct sigstack *__ss, struct sigstack *__oss) ;



extern int sigaltstack (const struct sigaltstack * __ss,
                        struct sigaltstack * __oss) ;
# 378 "/usr/include/signal.h" 3 4
# 1 "/usr/include/bits/pthreadtypes.h" 1 3 4
# 379 "/usr/include/signal.h" 2 3 4
# 1 "/usr/include/bits/sigthread.h" 1 3 4
# 31 "/usr/include/bits/sigthread.h" 3 4
extern int pthread_sigmask (int __how,
                            const __sigset_t * __newmask,
                            __sigset_t * __oldmask);


extern int pthread_kill (pthread_t __threadid, int __signo) ;
# 380 "/usr/include/signal.h" 2 3 4






extern int __libc_current_sigrtmin (void) ;

extern int __libc_current_sigrtmax (void) ;




# 31 "/usr/include/sys/wait.h" 2 3 4
# 1 "/usr/include/sys/resource.h" 1 3 4
# 25 "/usr/include/sys/resource.h" 3 4
# 1 "/usr/include/bits/resource.h" 1 3 4
# 32 "/usr/include/bits/resource.h" 3 4
enum __rlimit_resource
{

  RLIMIT_CPU = 0,



  RLIMIT_FSIZE = 1,



  RLIMIT_DATA = 2,



  RLIMIT_STACK = 3,



  RLIMIT_CORE = 4,






  RLIMIT_RSS = 5,



  RLIMIT_NOFILE = 7,
  RLIMIT_OFILE = RLIMIT_NOFILE,




  RLIMIT_AS = 9,



  RLIMIT_NPROC = 6,



  RLIMIT_MEMLOCK = 8,



  RLIMIT_LOCKS = 10,


  RLIMIT_NLIMITS = 11,
  RLIM_NLIMITS = RLIMIT_NLIMITS


};
# 107 "/usr/include/bits/resource.h" 3 4
typedef __rlim_t rlim_t;







struct rlimit
  {

    rlim_t rlim_cur;

    rlim_t rlim_max;
  };
# 134 "/usr/include/bits/resource.h" 3 4
enum __rusage_who
{

  RUSAGE_SELF = 0,



  RUSAGE_CHILDREN = -1,



  RUSAGE_BOTH = -2

};


# 1 "/usr/include/bits/time.h" 1 3 4
# 151 "/usr/include/bits/resource.h" 2 3 4


struct rusage
  {

    struct timeval ru_utime;

    struct timeval ru_stime;

    long int ru_maxrss;


    long int ru_ixrss;

    long int ru_idrss;

    long int ru_isrss;


    long int ru_minflt;

    long int ru_majflt;

    long int ru_nswap;


    long int ru_inblock;

    long int ru_oublock;

    long int ru_msgsnd;

    long int ru_msgrcv;

    long int ru_nsignals;



    long int ru_nvcsw;


    long int ru_nivcsw;
  };







enum __priority_which
{
  PRIO_PROCESS = 0,

  PRIO_PGRP = 1,

  PRIO_USER = 2

};
# 26 "/usr/include/sys/resource.h" 2 3 4







# 43 "/usr/include/sys/resource.h" 3 4
typedef int __rlimit_resource_t;
typedef int __rusage_who_t;
typedef int __priority_which_t;





extern int getrlimit (__rlimit_resource_t __resource,
                      struct rlimit *__rlimits) ;
# 71 "/usr/include/sys/resource.h" 3 4
extern int setrlimit (__rlimit_resource_t __resource,
                      const struct rlimit *__rlimits) ;
# 89 "/usr/include/sys/resource.h" 3 4
extern int getrusage (__rusage_who_t __who, struct rusage *__usage) ;





extern int getpriority (__priority_which_t __which, id_t __who) ;



extern int setpriority (__priority_which_t __which, id_t __who, int __prio)
     ;


# 32 "/usr/include/sys/wait.h" 2 3 4





# 1 "/usr/include/bits/waitflags.h" 1 3 4
# 38 "/usr/include/sys/wait.h" 2 3 4
# 79 "/usr/include/sys/wait.h" 3 4
# 1 "/usr/include/bits/waitstatus.h" 1 3 4
# 65 "/usr/include/bits/waitstatus.h" 3 4
union wait
  {
    int w_status;
    struct
      {

        unsigned int __w_termsig:7;
        unsigned int __w_coredump:1;
        unsigned int __w_retcode:8;
        unsigned int:16;







      } __wait_terminated;
    struct
      {

        unsigned int __w_stopval:8;
        unsigned int __w_stopsig:8;
        unsigned int:16;






      } __wait_stopped;
  };
# 80 "/usr/include/sys/wait.h" 2 3 4
# 98 "/usr/include/sys/wait.h" 3 4
typedef enum
{
  P_ALL,
  P_PID,
  P_PGID
} idtype_t;
# 112 "/usr/include/sys/wait.h" 3 4
extern __pid_t wait (void * __stat_loc);
# 135 "/usr/include/sys/wait.h" 3 4
extern __pid_t waitpid (__pid_t __pid, int *__stat_loc, int __options);



# 1 "/usr/include/bits/siginfo.h" 1 3 4
# 25 "/usr/include/bits/siginfo.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 26 "/usr/include/bits/siginfo.h" 2 3 4
# 140 "/usr/include/sys/wait.h" 2 3 4
# 151 "/usr/include/sys/wait.h" 3 4
extern int waitid (idtype_t __idtype, __id_t __id, siginfo_t *__infop,
                   int __options);





struct rusage;






extern __pid_t wait3 (void * __stat_loc, int __options,
                      struct rusage * __usage) ;





struct rusage;


extern __pid_t wait4 (__pid_t __pid, void * __stat_loc, int __options,
                      struct rusage *__usage) ;




# 3 "Procesos.c" 2
# 1 "/usr/include/unistd.h" 1 3 4
# 28 "/usr/include/unistd.h" 3 4

# 171 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/bits/posix_opt.h" 1 3 4
# 172 "/usr/include/unistd.h" 2 3 4
# 195 "/usr/include/unistd.h" 3 4
# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.3.2/include/stddef.h" 1 3 4
# 196 "/usr/include/unistd.h" 2 3 4
# 236 "/usr/include/unistd.h" 3 4
typedef __intptr_t intptr_t;






typedef __socklen_t socklen_t;
# 256 "/usr/include/unistd.h" 3 4
extern int access (const char *__name, int __type) ;
# 286 "/usr/include/unistd.h" 3 4
extern __off_t lseek (int __fd, __off_t __offset, int __whence) ;
# 305 "/usr/include/unistd.h" 3 4
extern int close (int __fd);






extern ssize_t read (int __fd, void *__buf, size_t __nbytes);





extern ssize_t write (int __fd, const void *__buf, size_t __n);
# 369 "/usr/include/unistd.h" 3 4
extern int pipe (int __pipedes[2]) ;
# 378 "/usr/include/unistd.h" 3 4
extern unsigned int alarm (unsigned int __seconds) ;
# 390 "/usr/include/unistd.h" 3 4
extern unsigned int sleep (unsigned int __seconds);






extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     ;






extern int usleep (__useconds_t __useconds);
# 414 "/usr/include/unistd.h" 3 4
extern int pause (void);



extern int chown (const char *__file, __uid_t __owner, __gid_t __group)
     ;



extern int fchown (int __fd, __uid_t __owner, __gid_t __group) ;




extern int lchown (const char *__file, __uid_t __owner, __gid_t __group)
     ;




extern int chdir (const char *__path) ;



extern int fchdir (int __fd) ;
# 448 "/usr/include/unistd.h" 3 4
extern char *getcwd (char *__buf, size_t __size) ;
# 461 "/usr/include/unistd.h" 3 4
extern char *getwd (char *__buf) ;




extern int dup (int __fd) ;


extern int dup2 (int __fd, int __fd2) ;


extern char **__environ;







extern int execve (const char *__path, char *const __argv[],
                   char *const __envp[]) ;
# 492 "/usr/include/unistd.h" 3 4
extern int execv (const char *__path, char *const __argv[]) ;



extern int execle (const char *__path, const char *__arg, ...) ;



extern int execl (const char *__path, const char *__arg, ...) ;



extern int execvp (const char *__file, char *const __argv[]) ;




extern int execlp (const char *__file, const char *__arg, ...) ;




extern int nice (int __inc) ;




extern void _exit (int __status) ;





# 1 "/usr/include/bits/confname.h" 1 3 4
# 25 "/usr/include/bits/confname.h" 3 4
enum
  {
    _PC_LINK_MAX,

    _PC_MAX_CANON,

    _PC_MAX_INPUT,

    _PC_NAME_MAX,

    _PC_PATH_MAX,

    _PC_PIPE_BUF,

    _PC_CHOWN_RESTRICTED,

    _PC_NO_TRUNC,

    _PC_VDISABLE,

    _PC_SYNC_IO,

    _PC_ASYNC_IO,

    _PC_PRIO_IO,

    _PC_SOCK_MAXBUF,

    _PC_FILESIZEBITS,

    _PC_REC_INCR_XFER_SIZE,

    _PC_REC_MAX_XFER_SIZE,

    _PC_REC_MIN_XFER_SIZE,

    _PC_REC_XFER_ALIGN,

    _PC_ALLOC_SIZE_MIN,

    _PC_SYMLINK_MAX,

    _PC_2_SYMLINKS

  };


enum
  {
    _SC_ARG_MAX,

    _SC_CHILD_MAX,

    _SC_CLK_TCK,

    _SC_NGROUPS_MAX,

    _SC_OPEN_MAX,

    _SC_STREAM_MAX,

    _SC_TZNAME_MAX,

    _SC_JOB_CONTROL,

    _SC_SAVED_IDS,

    _SC_REALTIME_SIGNALS,

    _SC_PRIORITY_SCHEDULING,

    _SC_TIMERS,

    _SC_ASYNCHRONOUS_IO,

    _SC_PRIORITIZED_IO,

    _SC_SYNCHRONIZED_IO,

    _SC_FSYNC,

    _SC_MAPPED_FILES,

    _SC_MEMLOCK,

    _SC_MEMLOCK_RANGE,

    _SC_MEMORY_PROTECTION,

    _SC_MESSAGE_PASSING,

    _SC_SEMAPHORES,

    _SC_SHARED_MEMORY_OBJECTS,

    _SC_AIO_LISTIO_MAX,

    _SC_AIO_MAX,

    _SC_AIO_PRIO_DELTA_MAX,

    _SC_DELAYTIMER_MAX,

    _SC_MQ_OPEN_MAX,

    _SC_MQ_PRIO_MAX,

    _SC_VERSION,

    _SC_PAGESIZE,


    _SC_RTSIG_MAX,

    _SC_SEM_NSEMS_MAX,

    _SC_SEM_VALUE_MAX,

    _SC_SIGQUEUE_MAX,

    _SC_TIMER_MAX,




    _SC_BC_BASE_MAX,

    _SC_BC_DIM_MAX,

    _SC_BC_SCALE_MAX,

    _SC_BC_STRING_MAX,

    _SC_COLL_WEIGHTS_MAX,

    _SC_EQUIV_CLASS_MAX,

    _SC_EXPR_NEST_MAX,

    _SC_LINE_MAX,

    _SC_RE_DUP_MAX,

    _SC_CHARCLASS_NAME_MAX,


    _SC_2_VERSION,

    _SC_2_C_BIND,

    _SC_2_C_DEV,

    _SC_2_FORT_DEV,

    _SC_2_FORT_RUN,

    _SC_2_SW_DEV,

    _SC_2_LOCALEDEF,


    _SC_PII,

    _SC_PII_XTI,

    _SC_PII_SOCKET,

    _SC_PII_INTERNET,

    _SC_PII_OSI,

    _SC_POLL,

    _SC_SELECT,

    _SC_UIO_MAXIOV,

    _SC_IOV_MAX = _SC_UIO_MAXIOV,

    _SC_PII_INTERNET_STREAM,

    _SC_PII_INTERNET_DGRAM,

    _SC_PII_OSI_COTS,

    _SC_PII_OSI_CLTS,

    _SC_PII_OSI_M,

    _SC_T_IOV_MAX,



    _SC_THREADS,

    _SC_THREAD_SAFE_FUNCTIONS,

    _SC_GETGR_R_SIZE_MAX,

    _SC_GETPW_R_SIZE_MAX,

    _SC_LOGIN_NAME_MAX,

    _SC_TTY_NAME_MAX,

    _SC_THREAD_DESTRUCTOR_ITERATIONS,

    _SC_THREAD_KEYS_MAX,

    _SC_THREAD_STACK_MIN,

    _SC_THREAD_THREADS_MAX,

    _SC_THREAD_ATTR_STACKADDR,

    _SC_THREAD_ATTR_STACKSIZE,

    _SC_THREAD_PRIORITY_SCHEDULING,

    _SC_THREAD_PRIO_INHERIT,

    _SC_THREAD_PRIO_PROTECT,

    _SC_THREAD_PROCESS_SHARED,


    _SC_NPROCESSORS_CONF,

    _SC_NPROCESSORS_ONLN,

    _SC_PHYS_PAGES,

    _SC_AVPHYS_PAGES,

    _SC_ATEXIT_MAX,

    _SC_PASS_MAX,


    _SC_XOPEN_VERSION,

    _SC_XOPEN_XCU_VERSION,

    _SC_XOPEN_UNIX,

    _SC_XOPEN_CRYPT,

    _SC_XOPEN_ENH_I18N,

    _SC_XOPEN_SHM,


    _SC_2_CHAR_TERM,

    _SC_2_C_VERSION,

    _SC_2_UPE,


    _SC_XOPEN_XPG2,

    _SC_XOPEN_XPG3,

    _SC_XOPEN_XPG4,


    _SC_CHAR_BIT,

    _SC_CHAR_MAX,

    _SC_CHAR_MIN,

    _SC_INT_MAX,

    _SC_INT_MIN,

    _SC_LONG_BIT,

    _SC_WORD_BIT,

    _SC_MB_LEN_MAX,

    _SC_NZERO,

    _SC_SSIZE_MAX,

    _SC_SCHAR_MAX,

    _SC_SCHAR_MIN,

    _SC_SHRT_MAX,

    _SC_SHRT_MIN,

    _SC_UCHAR_MAX,

    _SC_UINT_MAX,

    _SC_ULONG_MAX,

    _SC_USHRT_MAX,


    _SC_NL_ARGMAX,

    _SC_NL_LANGMAX,

    _SC_NL_MSGMAX,

    _SC_NL_NMAX,

    _SC_NL_SETMAX,

    _SC_NL_TEXTMAX,


    _SC_XBS5_ILP32_OFF32,

    _SC_XBS5_ILP32_OFFBIG,

    _SC_XBS5_LP64_OFF64,

    _SC_XBS5_LPBIG_OFFBIG,


    _SC_XOPEN_LEGACY,

    _SC_XOPEN_REALTIME,

    _SC_XOPEN_REALTIME_THREADS,


    _SC_ADVISORY_INFO,

    _SC_BARRIERS,

    _SC_BASE,

    _SC_C_LANG_SUPPORT,

    _SC_C_LANG_SUPPORT_R,

    _SC_CLOCK_SELECTION,

    _SC_CPUTIME,

    _SC_THREAD_CPUTIME,

    _SC_DEVICE_IO,

    _SC_DEVICE_SPECIFIC,

    _SC_DEVICE_SPECIFIC_R,

    _SC_FD_MGMT,

    _SC_FIFO,

    _SC_PIPE,

    _SC_FILE_ATTRIBUTES,

    _SC_FILE_LOCKING,

    _SC_FILE_SYSTEM,

    _SC_MONOTONIC_CLOCK,

    _SC_MULTI_PROCESS,

    _SC_SINGLE_PROCESS,

    _SC_NETWORKING,

    _SC_READER_WRITER_LOCKS,

    _SC_SPIN_LOCKS,

    _SC_REGEXP,

    _SC_REGEX_VERSION,

    _SC_SHELL,

    _SC_SIGNALS,

    _SC_SPAWN,

    _SC_SPORADIC_SERVER,

    _SC_THREAD_SPORADIC_SERVER,

    _SC_SYSTEM_DATABASE,

    _SC_SYSTEM_DATABASE_R,

    _SC_TIMEOUTS,

    _SC_TYPED_MEMORY_OBJECTS,

    _SC_USER_GROUPS,

    _SC_USER_GROUPS_R,

    _SC_2_PBS,

    _SC_2_PBS_ACCOUNTING,

    _SC_2_PBS_LOCATE,

    _SC_2_PBS_MESSAGE,

    _SC_2_PBS_TRACK,

    _SC_SYMLOOP_MAX,

    _SC_STREAMS,

    _SC_2_PBS_CHECKPOINT,


    _SC_V6_ILP32_OFF32,

    _SC_V6_ILP32_OFFBIG,

    _SC_V6_LP64_OFF64,

    _SC_V6_LPBIG_OFFBIG,


    _SC_HOST_NAME_MAX,

    _SC_TRACE,

    _SC_TRACE_EVENT_FILTER,

    _SC_TRACE_INHERIT,

    _SC_TRACE_LOG

  };


enum
  {
    _CS_PATH,


    _CS_V6_WIDTH_RESTRICTED_ENVS,


    _CS_GNU_LIBC_VERSION,

    _CS_GNU_LIBPTHREAD_VERSION,


    _CS_LFS_CFLAGS = 1000,

    _CS_LFS_LDFLAGS,

    _CS_LFS_LIBS,

    _CS_LFS_LINTFLAGS,

    _CS_LFS64_CFLAGS,

    _CS_LFS64_LDFLAGS,

    _CS_LFS64_LIBS,

    _CS_LFS64_LINTFLAGS,


    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,

    _CS_XBS5_ILP32_OFF32_LDFLAGS,

    _CS_XBS5_ILP32_OFF32_LIBS,

    _CS_XBS5_ILP32_OFF32_LINTFLAGS,

    _CS_XBS5_ILP32_OFFBIG_CFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LIBS,

    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,

    _CS_XBS5_LP64_OFF64_CFLAGS,

    _CS_XBS5_LP64_OFF64_LDFLAGS,

    _CS_XBS5_LP64_OFF64_LIBS,

    _CS_XBS5_LP64_OFF64_LINTFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LIBS,

    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,


    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LIBS,

    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,

    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,

    _CS_POSIX_V6_LP64_OFF64_CFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LIBS,

    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS

  };
# 526 "/usr/include/unistd.h" 2 3 4


extern long int pathconf (const char *__path, int __name) ;


extern long int fpathconf (int __fd, int __name) ;


extern long int sysconf (int __name) ;



extern size_t confstr (int __name, char *__buf, size_t __len) ;




extern __pid_t getpid (void) ;


extern __pid_t getppid (void) ;




extern __pid_t getpgrp (void) ;
# 561 "/usr/include/unistd.h" 3 4
extern __pid_t __getpgid (__pid_t __pid) ;
# 570 "/usr/include/unistd.h" 3 4
extern int setpgid (__pid_t __pid, __pid_t __pgid) ;
# 587 "/usr/include/unistd.h" 3 4
extern int setpgrp (void) ;
# 605 "/usr/include/unistd.h" 3 4
extern __pid_t setsid (void) ;







extern __uid_t getuid (void) ;


extern __uid_t geteuid (void) ;


extern __gid_t getgid (void) ;


extern __gid_t getegid (void) ;




extern int getgroups (int __size, __gid_t __list[]) ;
# 638 "/usr/include/unistd.h" 3 4
extern int setuid (__uid_t __uid) ;




extern int setreuid (__uid_t __ruid, __uid_t __euid) ;




extern int seteuid (__uid_t __uid) ;






extern int setgid (__gid_t __gid) ;




extern int setregid (__gid_t __rgid, __gid_t __egid) ;




extern int setegid (__gid_t __gid) ;
# 690 "/usr/include/unistd.h" 3 4
extern __pid_t fork (void) ;






extern __pid_t vfork (void) ;





extern char *ttyname (int __fd) ;



extern int ttyname_r (int __fd, char *__buf, size_t __buflen) ;



extern int isatty (int __fd) ;





extern int ttyslot (void) ;




extern int link (const char *__from, const char *__to) ;



extern int symlink (const char *__from, const char *__to) ;




extern int readlink (const char * __path, char * __buf,
                     size_t __len) ;



extern int unlink (const char *__name) ;


extern int rmdir (const char *__path) ;



extern __pid_t tcgetpgrp (int __fd) ;


extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) ;






extern char *getlogin (void);
# 766 "/usr/include/unistd.h" 3 4
extern int setlogin (const char *__name) ;
# 775 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/getopt.h" 1 3 4
# 55 "/usr/include/getopt.h" 3 4
extern char *optarg;
# 69 "/usr/include/getopt.h" 3 4
extern int optind;




extern int opterr;



extern int optopt;
# 153 "/usr/include/getopt.h" 3 4
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts)
       ;
# 776 "/usr/include/unistd.h" 2 3 4







extern int gethostname (char *__name, size_t __len) ;






extern int sethostname (const char *__name, size_t __len) ;



extern int sethostid (long int __id) ;





extern int getdomainname (char *__name, size_t __len) ;
extern int setdomainname (const char *__name, size_t __len) ;





extern int vhangup (void) ;


extern int revoke (const char *__file) ;







extern int profil (unsigned short int *__sample_buffer, size_t __size,
                   size_t __offset, unsigned int __scale) ;





extern int acct (const char *__name) ;



extern char *getusershell (void) ;
extern void endusershell (void) ;
extern void setusershell (void) ;





extern int daemon (int __nochdir, int __noclose) ;






extern int chroot (const char *__path) ;



extern char *getpass (const char *__prompt);
# 857 "/usr/include/unistd.h" 3 4
extern int fsync (int __fd);






extern long int gethostid (void);


extern void sync (void) ;




extern int getpagesize (void) ;




extern int truncate (const char *__file, __off_t __length) ;
# 893 "/usr/include/unistd.h" 3 4
extern int ftruncate (int __fd, __off_t __length) ;
# 909 "/usr/include/unistd.h" 3 4
extern int getdtablesize (void) ;
# 918 "/usr/include/unistd.h" 3 4
extern int brk (void *__addr) ;





extern void *sbrk (intptr_t __delta) ;
# 939 "/usr/include/unistd.h" 3 4
extern long int syscall (long int __sysno, ...) ;
# 962 "/usr/include/unistd.h" 3 4
extern int lockf (int __fd, int __cmd, __off_t __len);
# 993 "/usr/include/unistd.h" 3 4
extern int fdatasync (int __fildes) ;
# 1024 "/usr/include/unistd.h" 3 4

# 4 "Procesos.c" 2
# 1 "/usr/include/errno.h" 1 3 4
# 32 "/usr/include/errno.h" 3 4




# 1 "/usr/include/bits/errno.h" 1 3 4
# 25 "/usr/include/bits/errno.h" 3 4
# 1 "/usr/include/linux/errno.h" 1 3 4



# 1 "/usr/include/asm/errno.h" 1 3 4
# 5 "/usr/include/linux/errno.h" 2 3 4
# 26 "/usr/include/bits/errno.h" 2 3 4
# 38 "/usr/include/bits/errno.h" 3 4
extern int *__errno_location (void) ;
# 37 "/usr/include/errno.h" 2 3 4
# 59 "/usr/include/errno.h" 3 4

# 5 "Procesos.c" 2
# 1 "/usr/include/stdio.h" 1 3 4
# 30 "/usr/include/stdio.h" 3 4




# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.3.2/include/stddef.h" 1 3 4
# 35 "/usr/include/stdio.h" 2 3 4
# 44 "/usr/include/stdio.h" 3 4


typedef struct _IO_FILE FILE;





# 62 "/usr/include/stdio.h" 3 4
typedef struct _IO_FILE __FILE;
# 72 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/libio.h" 1 3 4
# 32 "/usr/include/libio.h" 3 4
# 1 "/usr/include/_G_config.h" 1 3 4
# 14 "/usr/include/_G_config.h" 3 4
# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.3.2/include/stddef.h" 1 3 4
# 325 "/usr/lib/gcc-lib/i386-redhat-linux/3.3.2/include/stddef.h" 3 4
typedef long int wchar_t;
# 354 "/usr/lib/gcc-lib/i386-redhat-linux/3.3.2/include/stddef.h" 3 4
typedef unsigned int wint_t;
# 15 "/usr/include/_G_config.h" 2 3 4
# 24 "/usr/include/_G_config.h" 3 4
# 1 "/usr/include/wchar.h" 1 3 4
# 48 "/usr/include/wchar.h" 3 4
# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.3.2/include/stddef.h" 1 3 4
# 49 "/usr/include/wchar.h" 2 3 4

# 1 "/usr/include/bits/wchar.h" 1 3 4
# 51 "/usr/include/wchar.h" 2 3 4
# 76 "/usr/include/wchar.h" 3 4
typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
# 25 "/usr/include/_G_config.h" 2 3 4

typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
# 44 "/usr/include/_G_config.h" 3 4
# 1 "/usr/include/gconv.h" 1 3 4
# 28 "/usr/include/gconv.h" 3 4
# 1 "/usr/include/wchar.h" 1 3 4
# 48 "/usr/include/wchar.h" 3 4
# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.3.2/include/stddef.h" 1 3 4
# 49 "/usr/include/wchar.h" 2 3 4
# 29 "/usr/include/gconv.h" 2 3 4


# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.3.2/include/stddef.h" 1 3 4
# 32 "/usr/include/gconv.h" 2 3 4





enum
{
  __GCONV_OK = 0,
  __GCONV_NOCONV,
  __GCONV_NODB,
  __GCONV_NOMEM,

  __GCONV_EMPTY_INPUT,
  __GCONV_FULL_OUTPUT,
  __GCONV_ILLEGAL_INPUT,
  __GCONV_INCOMPLETE_INPUT,

  __GCONV_ILLEGAL_DESCRIPTOR,
  __GCONV_INTERNAL_ERROR
};



enum
{
  __GCONV_IS_LAST = 0x0001,
  __GCONV_IGNORE_ERRORS = 0x0002
};



struct __gconv_step;
struct __gconv_step_data;
struct __gconv_loaded_object;
struct __gconv_trans_data;



typedef int (*__gconv_fct) (struct __gconv_step *, struct __gconv_step_data *,
                            const unsigned char **, const unsigned char *,
                            unsigned char **, size_t *, int, int);


typedef wint_t (*__gconv_btowc_fct) (struct __gconv_step *, unsigned char);


typedef int (*__gconv_init_fct) (struct __gconv_step *);
typedef void (*__gconv_end_fct) (struct __gconv_step *);



typedef int (*__gconv_trans_fct) (struct __gconv_step *,
                                  struct __gconv_step_data *, void *,
                                  const unsigned char *,
                                  const unsigned char **,
                                  const unsigned char *, unsigned char **,
                                  size_t *);


typedef int (*__gconv_trans_context_fct) (void *, const unsigned char *,
                                          const unsigned char *,
                                          unsigned char *, unsigned char *);


typedef int (*__gconv_trans_query_fct) (const char *, const char ***,
                                        size_t *);


typedef int (*__gconv_trans_init_fct) (void **, const char *);
typedef void (*__gconv_trans_end_fct) (void *);

struct __gconv_trans_data
{

  __gconv_trans_fct __trans_fct;
  __gconv_trans_context_fct __trans_context_fct;
  __gconv_trans_end_fct __trans_end_fct;
  void *__data;
  struct __gconv_trans_data *__next;
};



struct __gconv_step
{
  struct __gconv_loaded_object *__shlib_handle;
  const char *__modname;

  int __counter;

  char *__from_name;
  char *__to_name;

  __gconv_fct __fct;
  __gconv_btowc_fct __btowc_fct;
  __gconv_init_fct __init_fct;
  __gconv_end_fct __end_fct;



  int __min_needed_from;
  int __max_needed_from;
  int __min_needed_to;
  int __max_needed_to;


  int __stateful;

  void *__data;
};



struct __gconv_step_data
{
  unsigned char *__outbuf;
  unsigned char *__outbufend;



  int __flags;



  int __invocation_counter;



  int __internal_use;

  __mbstate_t *__statep;
  __mbstate_t __state;



  struct __gconv_trans_data *__trans;
};



typedef struct __gconv_info
{
  size_t __nsteps;
  struct __gconv_step *__steps;
  struct __gconv_step_data __data [1];
} *__gconv_t;
# 45 "/usr/include/_G_config.h" 2 3 4
typedef union
{
  struct __gconv_info __cd;
  struct
  {
    struct __gconv_info __cd;
    struct __gconv_step_data __data;
  } __combined;
} _G_iconv_t;

typedef int _G_int16_t ;
typedef int _G_int32_t ;
typedef unsigned int _G_uint16_t ;
typedef unsigned int _G_uint32_t ;
# 33 "/usr/include/libio.h" 2 3 4
# 53 "/usr/include/libio.h" 3 4
# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.3.2/include/stdarg.h" 1 3 4
# 43 "/usr/lib/gcc-lib/i386-redhat-linux/3.3.2/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 54 "/usr/include/libio.h" 2 3 4
# 163 "/usr/include/libio.h" 3 4
struct _IO_jump_t; struct _IO_FILE;
# 173 "/usr/include/libio.h" 3 4
typedef void _IO_lock_t;





struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;
# 196 "/usr/include/libio.h" 3 4
};


enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
# 264 "/usr/include/libio.h" 3 4
struct _IO_FILE {
  int _flags;




  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;
# 312 "/usr/include/libio.h" 3 4
  __off64_t _offset;





  void *__pad1;
  void *__pad2;

  int _mode;

  char _unused2[15 * sizeof (int) - 2 * sizeof (void *)];

};


typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
# 351 "/usr/include/libio.h" 3 4
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn (void *__cookie, const char *__buf,
                                 size_t __n);







typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);


typedef int __io_close_fn (void *__cookie);
# 403 "/usr/include/libio.h" 3 4
extern int __underflow (_IO_FILE *) ;
extern int __uflow (_IO_FILE *) ;
extern int __overflow (_IO_FILE *, int) ;
extern wint_t __wunderflow (_IO_FILE *) ;
extern wint_t __wuflow (_IO_FILE *) ;
extern wint_t __woverflow (_IO_FILE *, wint_t) ;
# 433 "/usr/include/libio.h" 3 4
extern int _IO_getc (_IO_FILE *__fp) ;
extern int _IO_putc (int __c, _IO_FILE *__fp) ;
extern int _IO_feof (_IO_FILE *__fp) ;
extern int _IO_ferror (_IO_FILE *__fp) ;

extern int _IO_peekc_locked (_IO_FILE *__fp) ;





extern void _IO_flockfile (_IO_FILE *) ;
extern void _IO_funlockfile (_IO_FILE *) ;
extern int _IO_ftrylockfile (_IO_FILE *) ;
# 463 "/usr/include/libio.h" 3 4
extern int _IO_vfscanf (_IO_FILE * , const char * ,
                        __gnuc_va_list, int *) ;
extern int _IO_vfprintf (_IO_FILE *, const char *,
                         __gnuc_va_list) ;
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t) ;
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t) ;

extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int) ;
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int) ;

extern void _IO_free_backup_area (_IO_FILE *) ;
# 73 "/usr/include/stdio.h" 2 3 4
# 86 "/usr/include/stdio.h" 3 4


typedef _G_fpos_t fpos_t;




# 138 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/stdio_lim.h" 1 3 4
# 139 "/usr/include/stdio.h" 2 3 4



extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;









extern int remove (const char *__filename) ;

extern int rename (const char *__old, const char *__new) ;









extern FILE *tmpfile (void);
# 180 "/usr/include/stdio.h" 3 4
extern char *tmpnam (char *__s) ;





extern char *tmpnam_r (char *__s) ;
# 198 "/usr/include/stdio.h" 3 4
extern char *tempnam (const char *__dir, const char *__pfx)
     ;








extern int fclose (FILE *__stream);




extern int fflush (FILE *__stream);

# 223 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 237 "/usr/include/stdio.h" 3 4






extern FILE *fopen (const char * __filename,
                    const char * __modes);




extern FILE *freopen (const char * __filename,
                      const char * __modes,
                      FILE * __stream);
# 264 "/usr/include/stdio.h" 3 4

# 275 "/usr/include/stdio.h" 3 4
extern FILE *fdopen (int __fd, const char *__modes) ;
# 296 "/usr/include/stdio.h" 3 4



extern void setbuf (FILE * __stream, char * __buf) ;



extern int setvbuf (FILE * __stream, char * __buf,
                    int __modes, size_t __n) ;





extern void setbuffer (FILE * __stream, char * __buf,
                       size_t __size) ;


extern void setlinebuf (FILE *__stream) ;








extern int fprintf (FILE * __stream,
                    const char * __format, ...);




extern int printf (const char * __format, ...);

extern int sprintf (char * __s,
                    const char * __format, ...) ;





extern int vfprintf (FILE * __s, const char * __format,
                     __gnuc_va_list __arg);




extern int vprintf (const char * __format, __gnuc_va_list __arg);

extern int vsprintf (char * __s, const char * __format,
                     __gnuc_va_list __arg) ;





extern int snprintf (char * __s, size_t __maxlen,
                     const char * __format, ...)
     ;

extern int vsnprintf (char * __s, size_t __maxlen,
                      const char * __format, __gnuc_va_list __arg)
     ;

# 390 "/usr/include/stdio.h" 3 4





extern int fscanf (FILE * __stream,
                   const char * __format, ...);




extern int scanf (const char * __format, ...);

extern int sscanf (const char * __s,
                   const char * __format, ...) ;

# 432 "/usr/include/stdio.h" 3 4





extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);





extern int getchar (void);

# 456 "/usr/include/stdio.h" 3 4
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
# 467 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked (FILE *__stream);











extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);





extern int putchar (int __c);

# 500 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked (int __c, FILE *__stream);







extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream);


extern int putw (int __w, FILE *__stream);








extern char *fgets (char * __s, int __n, FILE * __stream);






extern char *gets (char *__s);

# 580 "/usr/include/stdio.h" 3 4





extern int fputs (const char * __s, FILE * __stream);





extern int puts (const char *__s);






extern int ungetc (int __c, FILE *__stream);






extern size_t fread (void * __ptr, size_t __size,
                     size_t __n, FILE * __stream);




extern size_t fwrite (const void * __ptr, size_t __size,
                      size_t __n, FILE * __s);

# 633 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void * __ptr, size_t __size,
                              size_t __n, FILE * __stream);
extern size_t fwrite_unlocked (const void * __ptr, size_t __size,
                               size_t __n, FILE * __stream);








extern int fseek (FILE *__stream, long int __off, int __whence);




extern long int ftell (FILE *__stream);




extern void rewind (FILE *__stream);

# 688 "/usr/include/stdio.h" 3 4






extern int fgetpos (FILE * __stream, fpos_t * __pos);




extern int fsetpos (FILE *__stream, const fpos_t *__pos);
# 711 "/usr/include/stdio.h" 3 4

# 720 "/usr/include/stdio.h" 3 4


extern void clearerr (FILE *__stream) ;

extern int feof (FILE *__stream) ;

extern int ferror (FILE *__stream) ;




extern void clearerr_unlocked (FILE *__stream) ;
extern int feof_unlocked (FILE *__stream) ;
extern int ferror_unlocked (FILE *__stream) ;








extern void perror (const char *__s);






# 1 "/usr/include/bits/sys_errlist.h" 1 3 4
# 27 "/usr/include/bits/sys_errlist.h" 3 4
extern int sys_nerr;
extern const char *const sys_errlist[];
# 750 "/usr/include/stdio.h" 2 3 4




extern int fileno (FILE *__stream) ;




extern int fileno_unlocked (FILE *__stream) ;
# 769 "/usr/include/stdio.h" 3 4
extern FILE *popen (const char *__command, const char *__modes);





extern int pclose (FILE *__stream);





extern char *ctermid (char *__s) ;
# 809 "/usr/include/stdio.h" 3 4
extern void flockfile (FILE *__stream) ;



extern int ftrylockfile (FILE *__stream) ;


extern void funlockfile (FILE *__stream) ;
# 833 "/usr/include/stdio.h" 3 4

# 6 "Procesos.c" 2

int
main() {


        pid_t pid;

        pid = fork();

        if (pid == -1) {

                fprintf(stdout, "Error: %d\n", (*__errno_location ()));
                exit(1);
        }

        if (pid == 0) {

                sleep(30);
                exit(1);

        }
        else {

                fprintf(stdout, "Hijo: %d\n", pid);

                int status;

                wait(&status);


                if (((((*(int *) &(status))) & 0x7f) == 0)) {

                        fprintf(stdout, "Hijo termino con codigo: %d\n",
                                ((((*(int *) &(status))) & 0xff00) >> 8));

                }
                else {

                        if ((!((((*(int *) &(status))) & 0xff) == 0x7f) && !((((*(int *) &(status))) & 0x7f) == 0))) {

                                fprintf(stdout, "Señal del hijo: %d\n",
                                        (((*(int *) &(status))) & 0x7f));
                        }
                        else {

                                if (((((*(int *) &(status))) & 0xff) == 0x7f)) {

                                        fprintf(stdout, "Señal de parada: %d\n",
                                                ((((*(int *) &(status))) & 0xff00) >> 8));
                                }

                        }

                }

        }

        return 0;
}

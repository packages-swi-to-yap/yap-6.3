/*************************************************************************
*									 *
*	 YAP Prolog 	@(#)c_interface.h	2.2			 *
*	Yap Prolog was developed at NCCUP - Universidade do Porto	 *
*									 *
* Copyright L.Damas, V.S.Costa and Universidade do Porto 1985-1997	 *
*									 *
**************************************************************************
*									 *
* File:		yap_structs.h						 *
* Last rev:	15/5/2000						 *
* mods:									 *
* comments:	Data structures and defines used in the Interface	 *
*									 *
*************************************************************************/

#if	defined(__STDC__)

#define PROTO(X,ARGS) X ARGS

#else

#define PROTO(X,ARGS) X()

#endif

#ifndef HAS_YAP_H

/* Type definitions */

typedef unsigned long CELL;  /* this is common to all current machines */

typedef int Bool;

typedef long int Int;

typedef double flt;

typedef CELL Term, Functor, Atom;

#ifndef TRUE
#define TRUE	1
#endif
#ifndef FALSE
#define FALSE	0
#endif

#endif

#define YAP_BOOT_FROM_PROLOG       0
#define YAP_BOOT_FROM_SAVED_CODE   1
#define YAP_BOOT_FROM_SAVED_STACKS 2
#define YAP_BOOT_FROM_SAVED_ERROR  -1

#define YAP_WRITE_QUOTED		0
#define YAP_WRITE_HANDLE_VARS		1
#define YAP_WRITE_IGNORE_OPS		2

#define YAP_CONSULT_MODE           0
#define YAP_RECONSULT_MODE         1

typedef struct {
  /* if NON-NULL, path where we can find the saved state */
  char *SavedState;
  /* if NON-0, minimal size for Heap or Code Area */
  int HeapSize;
  /* if NON-0, minimal size for Local+Global Stack */
  int StackSize;
  /* if NON-0, minimal size for Trail */
  int TrailSize;
  /* if NON-NULL, value for YAPLIBDIR */
  char *YapLibDir;
  /* if NON-NULL, name for a Prolog file to consult before entering top-level  */
  char *YapPrologBootFile;
  /* if previous NON-NULL and TRUE, halt after consulting that file  */
  int HaltAfterConsult;
  /* ignore .yaprc, .prolog.ini, etc. files.  */
  int FastBoot;
  /* the next three fields only interest YAPOR, but we keep them so that
     users don't need to recompile DLL in order to use YAPOR */
  /* if NON-0, number of workers we want to have (default=1) */
  int NumberWorkers;
  /* if NON-0, manage the inner scheduler loop (default = 10) */
  int SchedulerLoop;
  /* if NON-0, say how long to keep nodes (default = 3) */
  int DelayedReleaseLoad;
  /* end of YAPOR fields */
  /* number of arguments that Prolog will see */
  int Argc;
  /* array of arguments as seen by Prolog */
  char **Argv;
} yap_init_args;


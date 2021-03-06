
set (YAPOS_SOURCES
  alias.c
  charsio.c
  chartypes.c
  console.c
  files.c
  fmemopen.c
  format.c
  iopreds.c
  mem.c
  open_memstream.c
  pipes.c
  readline.c
  random.c
  readterm.c
  readutil.c
  sig.c
  sockets.c
  streams.c
  sysbits.c
  time.c
  writeterm.c
  ypsocks.c
  ypstdio.c
  )

set (YAPOS_HEADERS
  encoding.h
  iopreds.h
  fmemopen.h
  yapio.h
  sysbits.h
  )


include_directories (../H ../include ../OPTYap .  ${GMP_INCLUDE_DIR} ${PROJECT_BINARY_DIR})

 option (READLINE  "GNU readline console" ON)

 if (READLINE)
  macro_optional_find_package (Readline ON)
  macro_log_feature (READLINE_FOUND "libreadline"
    "Readline line editing library"
    "http://cnswww.cns.cwru.edu/php/chet/readline/rltop.html")

  if (READLINE_FOUND)
  # - Find the readline library
  # This module defines
  #  READLINE_INCLUDE_DIR, path to readline/readline.h, etc.
  #  READLINE_LIBRARIES, the libraries required to use READLINE.
  #  READLINE_FOUND, If false, do not try to use READLINE.
  # also defined, but not for general use are
  # READLINE_readline_LIBRARY, where to find the READLINE library.
  # READLINE_ncurses_LIBRARY, where to find the ncurses library [might not be defined]

  include_directories (BEFORE ${READLINE_INCLUDE_DIR})

  set(YAP_SYSTEM_OPTIONS "readline " ${YAP_SYSTEM_OPTIONS} PARENT_SCOPE)
  set( CMAKE_REQUIRED_LIBRARIES ${CMAKE_REQUIRED_LIBRARIES} ${READLINE_LIBRARIES} )
  check_library_exists( readline readline "" HAVE_LIBREADLINE )

  check_include_files( "stdio.h;readline/readline.h" HAVE_READLINE_READLINE_H )
  check_include_files( "stdio.h;readline/history.h"  HAVE_READLINE_HISTORY_H )
  if (HAVE_READLINE_READLINE_H)
    SET ( USE_READLINE ON )
    check_function_exists( add_history  HAVE_ADD_HISTORY )
  check_function_exists( rl_begin_undo_group HAVE_RL_BEGIN_UNDO_GROUP)
  check_function_exists( rl_clear_pending_input HAVE_RL_CLEAR_PENDING_INPUT)
  check_function_exists( rl_discard_argument HAVE_RL_DISCARD_ARGUMENT)
  check_function_exists( rl_filename_completion_function HAVE_RL_FILENAME_COMPLETION_FUNCTION)
  check_function_exists( rl_free_line_state HAVE_RL_FREE_LINE_STATE )
  check_function_exists( rl_insert_close  HAVE_RL_INSERT_CLOSE )
  check_function_exists( rl_reset_after_signal  HAVE_RL_RESET_AFTER_SIGNAL )
  check_function_exists( rl_set_keyboard_input_timeout  HAVE_RL_SET_KEYBOARD_INPUT_TIMEOUT )
  check_function_exists( rl_set_prompt  HAVE_RL_SET_PROMPT)
  check_variable_exists( rl_catch_signals "readline/readline.h"   HAVE_DECL_RL_CATCH_SIGNALS )
  check_symbol_exists( rl_completion_func_t stdio.h;readline/readline.h HAVE_DECL_RL_COMPLETION_FUNC_T )
  check_variable_exists( rl_done stdio.h;readline/readline.h  HAVE_DECL_RL_DONE )
  check_symbol_exists( rl_hook_func_t stdio.h;readline/readline.h  HAVE_DECL_RL_HOOK_FUNC_T )
  check_symbol_exists( rl_event_hook stdio.h;readline/readline.h HAVE_DECL_RL_EVENT_HOOK )
  check_variable_exists( rl_readline_state stdio.h;readline/readline.h HAVE_DECL_RL_READLINE_STATE )
     endif()
endif (READLINE_FOUND)

endif (READLINE)

set (POSITION_INDEPENDENT_CODE TRUE)

add_library (libYAPOs  OBJECT
  ${YAPOS_SOURCES}
  )

set_target_properties(libYAPOs
  PROPERTIES

  #  RPATH ${libdir} VERSION ${LIBYAPTAI_FULL_VERSION}
  #  SOVERSION ${LIBYAPTAI_MAJOR_VERSION}.${LIBYAPTAI_MINOR_VERSION}
  POSITION_INDEPENDENT_CODE TRUE
  OUTPUT_NAME YAPOs
  depends dheap
  )

configure_file ("${PROJECT_SOURCE_DIR}/os/YapIOConfig.h.cmake"
  "${PROJECT_BINARY_DIR}/os/YapIOConfig.h" )

  set( READLINE_LIBS ${READLINE_LIBRARIES} PARENT_SCOPE)


#set( CMAKE_REQUIRED_LIBRARIES ${CMAKE_REQUIRED_LIBRARIES} ${GMP_LIBRARIES} )

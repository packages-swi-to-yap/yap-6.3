set (SRC
  adterror.c
  allocate.c
  general.c
  iqueue.c
  pqueue.c
  problogbdd_lfi.c
  problogmath.c
  simplecudd.c
  )

 
add_executable (Problogbdd-Lfi
  ${SRC})

set_target_properties (Problogbdd-Lfi PROPERTIES
  OUTPUT_NAME problogbdd_lfi
  )

target_link_libraries(Problogbdd-Lfi
  ${CUDD_LIBRARIES}    
  libYap    
 )

  INCLUDE_DIRECTORIES( 
    ${CUDD_INCLUDE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    )
 
  install(TARGETS Problogbdd-Lfi
    RUNTIME DESTINATION ${bindir}
    LIBRARY DESTINATION ${dlls}
    )


macro(build_communi_lib LIB_NAME)
  add_library(${LIB_NAME} STATIC ${PRIV_HEADERS} ${PUB_HEADERS} ${SOURCE_FILES})

  target_link_libraries(${LIB_NAME} PUBLIC Qt5::Core Qt5::Network)
  target_include_directories(
    ${LIB_NAME}
    PUBLIC "${LibCommuni_INCLUDE_DIR}/IrcModel/"
           "${LibCommuni_INCLUDE_DIR}/IrcCore/"
           "${LibCommuni_INCLUDE_DIR}/IrcUtil/")

  target_compile_definitions(${LIB_NAME} PUBLIC IRC_STATIC
                                                IRC_NAMESPACE=Communi)

  install(FILES ${PUB_HEADERS} ${CONV_HEADERS}
          DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Irc${LIB_NAME}/)

  install(
    TARGETS ${LIB_NAME}
    LIBRARY
    ARCHIVE)
endmacro()

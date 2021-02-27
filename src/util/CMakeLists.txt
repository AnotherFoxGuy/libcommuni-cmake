# ------------------------------------------------------------------------------------------------#
# Util
# ------------------------------------------------------------------------------------------------#

project(Util)

set(CONV_HEADERS
    ${LibCommuni_INCLUDE_DIR}/IrcUtil/IrcCommandParser
    ${LibCommuni_INCLUDE_DIR}/IrcUtil/IrcCommandQueue
    ${LibCommuni_INCLUDE_DIR}/IrcUtil/IrcCompleter
    ${LibCommuni_INCLUDE_DIR}/IrcUtil/IrcLagTimer
    ${LibCommuni_INCLUDE_DIR}/IrcUtil/IrcPalette
    ${LibCommuni_INCLUDE_DIR}/IrcUtil/IrcTextFormat
    ${LibCommuni_INCLUDE_DIR}/IrcUtil/IrcUtil)

set(PUB_HEADERS
    ${LibCommuni_INCLUDE_DIR}/IrcUtil/irccommandparser.h
    ${LibCommuni_INCLUDE_DIR}/IrcUtil/irccommandqueue.h
    ${LibCommuni_INCLUDE_DIR}/IrcUtil/irccompleter.h
    ${LibCommuni_INCLUDE_DIR}/IrcUtil/irclagtimer.h
    ${LibCommuni_INCLUDE_DIR}/IrcUtil/ircpalette.h
    ${LibCommuni_INCLUDE_DIR}/IrcUtil/irctextformat.h
    ${LibCommuni_INCLUDE_DIR}/IrcUtil/ircutil.h)

set(PRIV_HEADERS
    ${LibCommuni_INCLUDE_DIR}/IrcUtil/irccommandparser_p.h
    ${LibCommuni_INCLUDE_DIR}/IrcUtil/irccommandqueue_p.h
    ${LibCommuni_INCLUDE_DIR}/IrcUtil/irclagtimer_p.h
    ${LibCommuni_INCLUDE_DIR}/IrcUtil/irctoken_p.h)

set(SOURCE_FILES
    ${CMAKE_CURRENT_LIST_DIR}/irccommandparser.cpp
    ${CMAKE_CURRENT_LIST_DIR}/irccommandqueue.cpp
    ${CMAKE_CURRENT_LIST_DIR}/irccompleter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/irclagtimer.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ircpalette.cpp
    ${CMAKE_CURRENT_LIST_DIR}/irctextformat.cpp
    ${CMAKE_CURRENT_LIST_DIR}/irctoken.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ircutil.cpp)

build_communi_lib("${PROJECT_NAME}")

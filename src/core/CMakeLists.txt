# ------------------------------------------------------------------------------------------------#
# Core
# ------------------------------------------------------------------------------------------------#
include(GNUInstallDirs)

project(Core)

set(CONV_HEADERS
    ${LibCommuni_INCLUDE_DIR}/IrcCore/Irc
    ${LibCommuni_INCLUDE_DIR}/IrcCore/IrcCommand
    ${LibCommuni_INCLUDE_DIR}/IrcCore/IrcCommandFilter
    ${LibCommuni_INCLUDE_DIR}/IrcCore/IrcConnection
    ${LibCommuni_INCLUDE_DIR}/IrcCore/IrcCore
    ${LibCommuni_INCLUDE_DIR}/IrcCore/IrcGlobal
    ${LibCommuni_INCLUDE_DIR}/IrcCore/IrcMessage
    ${LibCommuni_INCLUDE_DIR}/IrcCore/IrcMessageFilter
    ${LibCommuni_INCLUDE_DIR}/IrcCore/IrcNetwork
    ${LibCommuni_INCLUDE_DIR}/IrcCore/IrcProtocol)

set(PUB_HEADERS
    ${LibCommuni_INCLUDE_DIR}/IrcCore/irc.h
    ${LibCommuni_INCLUDE_DIR}/IrcCore/irccommand.h
    ${LibCommuni_INCLUDE_DIR}/IrcCore/ircconnection.h
    ${LibCommuni_INCLUDE_DIR}/IrcCore/irccore.h
    ${LibCommuni_INCLUDE_DIR}/IrcCore/ircfilter.h
    ${LibCommuni_INCLUDE_DIR}/IrcCore/ircglobal.h
    ${LibCommuni_INCLUDE_DIR}/IrcCore/ircmessage.h
    ${LibCommuni_INCLUDE_DIR}/IrcCore/ircnetwork.h
    ${LibCommuni_INCLUDE_DIR}/IrcCore/ircprotocol.h)

set(PRIV_HEADERS
    ${LibCommuni_INCLUDE_DIR}/IrcCore/irccommand_p.h
    ${LibCommuni_INCLUDE_DIR}/IrcCore/ircconnection_p.h
    ${LibCommuni_INCLUDE_DIR}/IrcCore/ircdebug_p.h
    ${LibCommuni_INCLUDE_DIR}/IrcCore/ircmessage_p.h
    ${LibCommuni_INCLUDE_DIR}/IrcCore/ircmessagecomposer_p.h
    ${LibCommuni_INCLUDE_DIR}/IrcCore/ircmessagedecoder_p.h
    ${LibCommuni_INCLUDE_DIR}/IrcCore/ircnetwork_p.h)

set(SOURCE_FILES
    ${CMAKE_CURRENT_LIST_DIR}/irc.cpp
    ${CMAKE_CURRENT_LIST_DIR}/irccommand.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ircconnection.cpp
    ${CMAKE_CURRENT_LIST_DIR}/irccore.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ircfilter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ircmessage.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ircmessage_p.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ircmessagecomposer.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ircmessagedecoder.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ircnetwork.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ircprotocol.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ircmessagedecoder_none.cpp
    # ${LibCommuni_SOURCE_DIR}/3rdparty/mozilla/rdf_utils.c
)

build_communi_lib("${PROJECT_NAME}" "${LibCommuni_INCLUDE_DIR}/IrcCore/")

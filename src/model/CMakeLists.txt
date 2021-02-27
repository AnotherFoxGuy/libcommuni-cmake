# ------------------------------------------------------------------------------------------------#
# Model
# ------------------------------------------------------------------------------------------------#

project(Model)

set(CONV_HEADERS
    ${LibCommuni_INCLUDE_DIR}/IrcModel/IrcBuffer
    ${LibCommuni_INCLUDE_DIR}/IrcModel/IrcBufferModel
    ${LibCommuni_INCLUDE_DIR}/IrcModel/IrcChannel
    ${LibCommuni_INCLUDE_DIR}/IrcModel/IrcModel
    ${LibCommuni_INCLUDE_DIR}/IrcModel/IrcUser
    ${LibCommuni_INCLUDE_DIR}/IrcModel/IrcUserModel)

set(PUB_HEADERS
    ${LibCommuni_INCLUDE_DIR}/IrcModel/ircbuffer.h
    ${LibCommuni_INCLUDE_DIR}/IrcModel/ircbuffermodel.h
    ${LibCommuni_INCLUDE_DIR}/IrcModel/ircchannel.h
    ${LibCommuni_INCLUDE_DIR}/IrcModel/ircmodel.h
    ${LibCommuni_INCLUDE_DIR}/IrcModel/ircuser.h
    ${LibCommuni_INCLUDE_DIR}/IrcModel/ircusermodel.h)

set(PRIV_HEADERS
    ${LibCommuni_INCLUDE_DIR}/IrcModel/ircbuffer_p.h
    ${LibCommuni_INCLUDE_DIR}/IrcModel/ircbuffermodel_p.h
    ${LibCommuni_INCLUDE_DIR}/IrcModel/ircchannel_p.h
    ${LibCommuni_INCLUDE_DIR}/IrcModel/ircuser_p.h
    ${LibCommuni_INCLUDE_DIR}/IrcModel/ircusermodel_p.h)

set(SOURCE_FILES
    ${CMAKE_CURRENT_LIST_DIR}/ircbuffer.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ircbuffermodel.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ircchannel.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ircmodel.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ircuser.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ircusermodel.cpp)

build_communi_lib("${PROJECT_NAME}")

cmake_minimum_required(VERSION 3.9)

project(duperagent VERSION 1.0.1 DESCRIPTION "duperagent description")

add_library (duperagent SHARED
    duperagent.h
    request.h
    response.h
    serialization.h
    jsvalueiterator.h
    config.h
    cookiejar.h
    promise.h
    promisemodule.h
    networkactivityindicator.h
    imageutils.h
    multipartsource.h
    duperagent.cpp
    request.cpp
    response.cpp
    serialization.cpp
    config.cpp
    cookiejar.cpp
    promise.cpp
    promisemodule.cpp
    networkactivityindicator.cpp
    imageutils.cpp
    multipartsource.cpp)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)
target_link_libraries(duperagent
    PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)

add_definitions(-DQT_NO_SSL)
target_include_directories (duperagent PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#
#contains(QT_CONFIG, ssl) | contains(QT_CONFIG, openssl) | contains(QT_CONFIG, openssl-linked) {
#    HEADERS += $$PWD/ssl.h
#    SOURCES += $$PWD/ssl.cpp
#}
#
#ios:OBJECTIVE_SOURCES += \
#    $$PWD/networkactivityindicator_ios.mm

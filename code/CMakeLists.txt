#Setup Visore
PROJECT(QRealFourier)

#Setup CMake
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

#Setup directory paths
SET(ROOT ${CMAKE_CURRENT_SOURCE_DIR})
SET(FFTREAL ${ROOT}/fftreal)
SET(exampleS ${ROOT}/examples)

#Setup Packaging and Version
message(error *${QT_USE_FILE}*)
message(error *${CMAKE_ROOT}*)
SET(CMAKE_MODULE_PATH ${ROOT}/cmake)
INCLUDE(Version)

#Setup Qt
FIND_PACKAGE(Qt COMPONENTS Core REQUIRED)
ADD_DEFINITIONS(${QT_DEFINITIONS})
INCLUDE(${QT_USE_FILE})

#Include common headers
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR} ${ROOT}/headers ${FFTREAL})

#Initiate source files
FILE(GLOB SOURCES ${ROOT}/sources/*.cpp)
FILE(GLOB FFTREAL_SOURCES ${FFTREAL}/*.hpp)
FILE(GLOB HEADERS ${ROOT}/headers/*.h)
FILE(GLOB FFTREAL_HEADERS ${FFTREAL}/*.h)

#Create shared library
ADD_LIBRARY(qrealfourier SHARED ${HEADERS} ${FFTREAL_HEADERS} ${SOURCES} ${FFTREAL_SOURCES})
SET_TARGET_PROPERTIES(qrealfourier PROPERTIES LINKER_LANGUAGE CXX)
TARGET_LINK_LIBRARIES(qrealfourier ${QT_QTCORE_LIBRARY})
SET_TARGET_PROPERTIES(qrealfourier PROPERTIES VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
SET_TARGET_PROPERTIES(qrealfourier PROPERTIES SOVERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

#Install library and header
INSTALL(TARGETS qrealfourier DESTINATION usr/lib/qrealfourier)
INSTALL(FILES ${HEADERS} DESTINATION usr/include/qrealfourier)

#Create example cases
ADD_EXECUTABLE(example1 ${exampleS}/example1.cpp)
TARGET_LINK_LIBRARIES(example1 qrealfourier)
ADD_EXECUTABLE(example2 ${exampleS}/example2.cpp)
TARGET_LINK_LIBRARIES(example2 qrealfourier)
ADD_EXECUTABLE(example3 ${exampleS}/example3.cpp)
TARGET_LINK_LIBRARIES(example3 qrealfourier)

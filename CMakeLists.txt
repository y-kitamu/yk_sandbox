cmake_minimum_required(VERSION 3.20)

# option(BUILD_WINDOWS "" OFF)
project(YKSandbox VERSION 0.1 LANGUAGES CXX) # CUDA)

set(BUILD_SHARED_LIBS OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

include(cmake/utility.cmake)

set(LIBARIES "" CACHE INTERNAL "")
set(EXTERNAL_LIBS "" CACHE INTERNAL "")

# fmt
add_subdirectory(ext/fmt)
set(EXTERNAL_LIBS ${EXTERNA_LIBS} fmt::fmt CACHE INTERNAL "")
include_directories(AFTER
  src/
  ext/fmt/include)

# opencv

# scripts

add_subdirectory(src)
add_subdirectory(scripts)

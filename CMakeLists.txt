cmake_minimum_required(VERSION 3.20)

# option(BUILD_WINDOWS "" OFF)
project(YKSandbox VERSION 0.1 LANGUAGES CXX) # CUDA)

set(BUILD_SHARED_LIBS OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

include(cmake/utility.cmake)

set(LIBRARIES "" CACHE INTERNAL "")
set(EXTERNAL_LIBS "" CACHE INTERNAL "")

# fmt
add_subdirectory(ext/fmt)
set(EXTERNAL_LIBS ${EXTERNA_LIBS} fmt::fmt CACHE INTERNAL "")
include_directories(AFTER
  src/
  ext/libtiff/libtiff
  ext/fmt/include
  ext/argparse/include
  ext/opencv/include
  ext/opencv/modules/core/include
  ext/opencv/modules/imgcodecs/include
  ext/opencv/modules/imgproc/include
)

if (BUILD_WINDOWS)
  message(STATUS "Windows Build Settings")
  include_directories(AFTER
    ext/build_win/libtiff/libtiff
    ext/build_win/opencv
    )
  file(GLOB opencv_deps "${CMAKE_CURRENT_SOURCE_DIR}/ext/build_win/opencv/3rdparty/lib/*.a")
  message(STATUS "opencv deps = ${opencv_deps}")
  set(EXTERNAL_LIBS ${EXTERNAL_LIBS}
    ${CMAKE_CURRENT_SOURCE_DIR}/ext/build_win/libtiff/libtiff/libtiffxx.a
    ${CMAKE_CURRENT_SOURCE_DIR}/ext/build_win/libtiff/libtiff/libtiff.a
    ${CMAKE_CURRENT_SOURCE_DIR}/ext/build_win/opencv/lib/libopencv_world455.a
    ${opencv_deps}
    )
else()
  message(STATUS "Linux Build Settings")
  include_directories(AFTER
      ext/build/opencv
      )
  set(EXTERNAL_LIBS ${EXTERNAL_LIBS}
    ${CMAKE_CURRENT_SOURCE_DIR}/ext/build/libtiff/libtiff/libtiffxx.a
    ${CMAKE_CURRENT_SOURCE_DIR}/ext/build/libtiff/libtiff/libtiff.a
    ${CMAKE_CURRENT_SOURCE_DIR}/ext/build/opencv/lib/libopencv_world.a
    ${CMAKE_CURRENT_SOURCE_DIR}/ext/build/opencv/3rdparty/lib/libIlmImf.a
    CACHE INTERNAL "")
endif()

# opencv
# find_package(OpenCV REQUIRED)

# message("LIBRARIES = ${LIBRARIES}")
# message("EXTERNAL_LIBS = ${EXTERNAL_LIBS}")

add_subdirectory(src)
add_subdirectory(scripts)

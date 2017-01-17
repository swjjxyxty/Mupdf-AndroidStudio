# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.4.1)

add_subdirectory(src/main/cpp/thirdparty)
# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds it for you.
# Gradle automatically packages shared libraries with your APK.

include_directories(
	src/main/cpp/thirdparty/jbig2dec
	src/main/cpp/thirdparty/openjpeg/libopenjpeg
	src/main/cpp/thirdparty/jpeg
	src/main/cpp/thirdparty/mujs
	src/main/cpp/thirdparty/zlib
	src/main/cpp/thirdparty/freetype/include
	src/main/cpp/source/fitz
	src/main/cpp/source/pdf
	src/main/cpp/source/xps
	src/main/cpp/source/cbz
	src/main/cpp/source/img
	src/main/cpp/source/tiff
	src/main/cpp/scripts/freetype
	src/main/cpp/scripts/jpeg
	src/main/cpp/scripts/openjpeg
	src/main/cpp/generated
	src/main/cpp/resources
	src/main/cpp/include
	src/main/cpp
	)
set(MY_ROOT src/main/cpp)
file(GLOB FITZ_FILES "${MY_ROOT}/source/fitz/*.c")
file(GLOB PDF_FILES "${MY_ROOT}/source/pdf/*.c")
file(GLOB XPS_FILES "${MY_ROOT}/source/xps/*.c")
file(GLOB CBZ_FILES "${MY_ROOT}/source/cbz/*.c")
file(GLOB GPRF_FILES "${MY_ROOT}/source/gprf/*.c")
file(GLOB HTML_FILES "${MY_ROOT}/source/html/*.c")

list(APPEND SRC_LIST ${FITZ_FILES})
list(APPEND SRC_LIST ${PDF_FILES})
list(APPEND SRC_LIST ${XPS_FILES})
list(APPEND SRC_LIST ${CBZ_FILES})
list(APPEND SRC_LIST ${GPRF_FILES})
list(APPEND SRC_LIST ${HTML_FILES})
list(APPEND SRC_LIST ${MY_ROOT}/source/pdf/js/pdf-js.c
                     ${MY_ROOT}/source/pdf/js/pdf-jsimp-mu.c)

MESSAGE(STATUS "--------------------${FITZ_FILES}")
MESSAGE(STATUS "${SRC_LIST}")


add_library( # Sets the name of the library.
             mupdfcore

             # Sets the library as a shared library.
             STATIC

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
             ${SRC_LIST})


add_library( # Sets the name of the library.
             mupdf

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
             src/main/cpp/mupdf.c)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because system libraries are included in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

find_library( # Sets the name of the path variable.
              jnigraphics-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              jnigraphics )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in the
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       mupdf

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib}
                       ${jnigraphics-lib}
                       mupdfcore
                       mupdfthirdparty)

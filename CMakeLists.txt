cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

#
# OPTIONS
#
option(SUPPRESS_WARNINGS "Suppress compiler warnings" OFF)
option(CLANG_TIDY "Perform Clang-Tidy" OFF)
option(CLANG_TIDY_FIX "Perform fixes for Clang-Tidy" OFF)

if(UNIX)
  option(STATIC_LINK_LIBGCC "Linking libgcc statically" OFF)
  option(STATIC_LINK_LIBSTDCPP "Linking libstdc++ statically" OFF)
endif()

#
# VARIABLES
#

# Local variables
if(UNIX AND NOT APPLE)
  set(LINUX TRUE)
endif()

# Default CMake variables
set(CMAKE_BUILD_TYPE
    Release
    CACHE
      STRING
      "Specifies the build type on single-configuration generators. Defaults to Release."
)

if(UNIX)
  # Prefer clang
  set(CMAKE_C_COMPILER
      "clang"
      CACHE STRING "Specifies the C compiler. Defaults to clang")
  set(CMAKE_CXX_COMPILER
      "clang++"
      CACHE STRING "Specifies the C++ compiler. Defaults to clang++")
endif()

# Default CMake environment variables
set(ENV{CMAKE_EXPORT_COMPILE_COMMANDS} ON)

#
# OUTPUT PATH
#
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>/lib)

#
# PROJECT
#
project(cmake_sample_all CXX)

#
# COMPILER/LINKER FLAGS
#
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT MSVC)
  # Prefer -g3 to -g
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3")
  set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -g3")

  # Show warnings
  if(NOT SUPPRESS_WARNINGS)
    set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wcast-align -Wcast-qual -Wdelete-non-virtual-dtor -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wfloat-equal -Winit-self -Wredundant-decls -Wconversion -Wsign-promo -Wswitch-default -Wswitch-enum -Wvariadic-macros -Wwrite-strings -Wno-unknown-pragmas"
    )

    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wshadow")
    elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-pragmas")
    endif()
  endif()

  # Static linking of libgcc/libstdc++
  if(LINUX OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    if(STATIC_LINK_LIBGCC)
      add_link_options(-static-libgcc)
    endif()
    if(STATIC_LINK_LIBSTDCPP)
      add_link_options(-static-libstdc++)
    endif()
  endif()

  if(APPLE AND "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang") # except AppleClang
    # Use libc++ instead of libstdc++
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
  endif()
else() # MSVC
  # Show warnings
  if(SUPPRESS_WARNINGS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /w")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
endif()

if(WIN32)
  if(VCPKG_TARGET_TRIPLET MATCHES "static")
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
  else()
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
  endif()
endif()

# fPIC/fPIE
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Hide symbols
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

if(LINUX)
  add_link_options(-Wl,--exclude-libs,ALL)
endif()

# Strip for release build
add_link_options($<$<CONFIG:Release,MinSizeRel>:-s>)

# Set shared library search path to ORIGIN
set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

if(LINUX)
  set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")
elseif(APPLE)
  set(CMAKE_INSTALL_RPATH "@loader_path/../lib")
endif()

#
# EXPORT COMPILE COMMANDS
#
if(CMAKE_EXPORT_COMPILE_COMMANDS)
  add_custom_target(gen_compile_commands ALL
                    COMMENT "Generating compile_commands.json")

  # Remove old file
  add_custom_command(
    TARGET gen_compile_commands
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E remove
            ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json)

  # Generate a compilation database with header files
  if(NOT COMPDB)
    find_program(COMPDB compdb)
  endif()

  if(COMPDB)
    add_custom_command(
      TARGET gen_compile_commands
      POST_BUILD
      WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
      COMMAND ${COMPDB} list > ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
      COMMENT "Running compdb")
  else()
    message(AUTHOR_WARNING "'compdb' not found")

    # Copy file instead of compdb
    add_custom_command(
      TARGET gen_compile_commands
      POST_BUILD
      WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
      COMMAND
        ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json)
  endif()
endif()

#
# SUBDIRECTORIES
#

# header only library project
add_subdirectory(my_header_lib)

# static library project
add_subdirectory(my_static_lib)

# shared library project
add_subdirectory(my_shared_lib)

# CUDA project
add_subdirectory(cuda)

# main project
add_subdirectory(main)

#
# CTest
#
enable_testing()
add_subdirectory(test)

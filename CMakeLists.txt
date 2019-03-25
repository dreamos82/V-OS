cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(VOS VERSION 0.1.0 LANGUAGES CXX C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 98)

# Defaults
set(CMAKE_INCLUDE_DIRECTORIES_PROJECT_BEFORE ON)
set(CMAKE_COLOR_MAKEFILE ON)

# Ensure env
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR "Create a separate build directory and run 'cmake path_to_libb2 [options]' there.")
endif()
if(NOT CMAKE_GENERATOR STREQUAL "Ninja")
    message(FATAL_ERROR "Only Ninja generator is supported: cmake ... -GNinja")
endif()
if (NOT CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(FATAL_ERROR "Only Linux is supported.")
endif()

# Color diagnostics
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    SET(DIAG_FLAGS "-fcolor-diagnostics")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    SET(DIAG_FLAGS "-fdiagnostics-color")
endif()

# Build type flags.
set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -ggdb -include build/BeOSBuildCompatibility.h")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -g0- include build/BeOSBuildCompatibility.h")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -include build/BeOSBuildCompatibility.h")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -include build/BeOSBuildCompatibility.h")

# Common compiler flags.
set(COMMON_FLAGS "-include build/BeOSBuildCompatibility.h -Wall   \
	-Wpointer-arith -Wcast-align -Wsign-compare -Wstrict-aliasing \
	-Wno-multichar -fPIC ${DIAG_FLAGS}")

# V\OS defines
set(GLOBAL_CFLAGS
)

set(SOURCE_HEADERS_DIR "headers")

file(GLOB_RECURSE PUBLIC_HEADERS "headers/*.h")

# Default include directories.
include_directories(
	"headers"

	"headers/build"
	"headers/build/config_headers"
	"headers/config"
	"headers/util"
	"headers/libs/agg/"

	"headers/os"
	"headers/os/app"
	"headers/os/drivers"
	"headers/os/kernel"
	"headers/os/support"
	"headers/os/storage"

	"headers/private/kernel"
	"headers/private/libroot"
	"headers/private/shared"
	"headers/private/system"
	"headers/private/system/arch/x86_64"

	"headers/posix"

	"headers/os/config"
	"headers/os/libs/agg/dbg_new"
	"headers/os/libs/agg/util"
	"headers/os/libs/icon"
	"headers/os/libs/linprog"
	"headers/os/add-ons/file_system"
	"headers/os/add-ons/graphics"
	"headers/os/add-ons/registrar"
	"headers/os/app"
	"headers/os/arch/x86_64"
	"headers/os/device"
	"headers/os/drivers/bus"
	"headers/os/game"
	"headers/os/interface"
	"headers/os/kernel"
	"headers/os/locale/"
	"headers/os/locale/tools"
	"headers/os/mail"
	"headers/os/net"
	"headers/os/storage"
	"headers/os/support"
	"headers/os/posix/compat/sys"
	"headers/private/"
	"headers/private/app"
	"headers/private/binary_compatibility"
	"headers/private/graphics"
	"headers/private/graphics/common"
	"headers/private/graphics/vesa"
	"headers/private/input"
	"headers/private/interface"
	"headers/private/kernel/util"
	"headers/private/libroot"
	"headers/private/locale"
	"headers/private/mount"
	"headers/private/notification"
	"headers/private/print"
	"headers/private/runtime_loader"
	"headers/private/shared"
	"headers/private/storage/"
	"headers/private/storage/mime"
	"headers/private/storage/sniffer"
	"headers/private/support"
	"headers/private/syslog_daemon"
	"headers/private/system/arch/x86"
	"headers/private/tracker"

	"headers/headers/os/private/system/arch/x86_64private/tracker"

	"src/kits/tracker/"

	"src/kits/storage/mime"
	"src/kits/interface/layouter/"
	"src/kits/interface/textview_support/"

	"src/servers/app"
	"src/servers/app/drawing"
	"src/servers/app/font"
	"src/servers/app/stackandtile"
	"src/servers/app/decorator"
	"src/servers/app/drawing/Painter"
	"src/servers/app/drawing/Painter/drawing_modes"

	"headers/libs/icon/"
	"headers/libs/agg/"
	"headers/libs/linprog/"

	"src/servers/registrar/"
	"src/servers/registrar/mime/"

	"src/libs/icon/shape/"

	"build/config_headers"

    #${PUBLIC_HEADERS}
    #${INTERFACE_HEADERS_DIR}
)

# Set flags.
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_FLAGS} \
	-Woverloaded-virtual -Wno-ctor-dtor-privacy \
	-Wnon-virtual-dtor -fexceptions -fpermissive")

# Goal is to work without libctdc++ installed
set(CMAKE_CXX_IMPLICIT_LINK_LIBRARIES "libc")
set(CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES "")

# Compute platform bits.
math(EXPR PLATFORM_BITS "8*${CMAKE_SIZEOF_VOID_P}")

# Log some information.
message(STATUS "")
message(STATUS "============= Build environment =============")
message(STATUS "CMAKE_SYSTEM:                    ${CMAKE_SYSTEM}")
message(STATUS "CMAKE_SYSTEM_PROCESSOR:          ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "CMAKE_SIZEOF_VOID_P:             ${CMAKE_SIZEOF_VOID_P}")
message(STATUS "PLATFORM_BITS:                   ${PLATFORM_BITS}")
message(STATUS "CMAKE_C_FLAGS:                   ${CMAKE_C_FLAGS}")
message(STATUS "CMAKE_CXX_FLAGS:                 ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_BUILD_TYPE:                ${CMAKE_BUILD_TYPE}")
message(STATUS "CMAKE_C_COMPILER:                ${CMAKE_C_COMPILER}")
message(STATUS "CMAKE_CXX_COMPILER:              ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_AR:                        ${CMAKE_AR}")
message(STATUS "CMAKE_RANLIB:                    ${CMAKE_RANLIB}")
message(STATUS "=============================================")
message(STATUS "")

# Sub directories
add_subdirectory(headers)
add_subdirectory(src)

# Deps
set(BUILD_ICU ON)
set(ICU_BUILD_VERSION 57.0)
add_subdirectory(external/icu-cmake)
 #  Copyright 2019, Dario Casalinuovo. All rights reserved.
 #  Distributed under the terms of the LGPL License.

include(CMakeParseArguments)

# Usage:
# Application(
# 	{targetname}
#	LIBS
#	{libslist}
#	INCLUDES
#	{includesList}
# )

macro( Application name )

	set( _OPTIONS_ARGS )
	set( _ONE_VALUE_ARGS )
	set( _MULTI_VALUE_ARGS SOURCES LIBS INCLUDES )

	cmake_parse_arguments( _APPLICATION "${_OPTIONS_ARGS}" "${_ONE_VALUE_ARGS}" "${_MULTI_VALUE_ARGS}" ${ARGN} )

	# TODO support for resources (rdef)

	if( _APPLICATION_SOURCES )
		add_executable(${name} ${_APPLICATION_SOURCES})
	else()
		message( FATAL_ERROR "APPLICATION: 'SOURCES' argument required." )
	endif()

	list (INSERT _APPLICATION_LIBS 0 root)
	list (INSERT _APPLICATION_LIBS 0 be)
	target_link_libraries(${name} PRIVATE ${_APPLICATION_LIBS})

	# Add current dir headers
	list (APPEND _APPLICATION_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR})
	target_include_directories(${name} PUBLIC ${_APPLICATION_INCLUDES})

endmacro()

macro( Server name )

	set( _OPTIONS_ARGS )
	set( _ONE_VALUE_ARGS )
	set( _MULTI_VALUE_ARGS SOURCES LIBS INCLUDES )

	cmake_parse_arguments( _SERVER "${_OPTIONS_ARGS}" "${_ONE_VALUE_ARGS}" "${_MULTI_VALUE_ARGS}" ${ARGN} )

	add_executable(${name} ${_SERVER_SOURCES})

	list (INSERT _SERVER_LIBS 0 root)
	list (INSERT _SERVER_LIBS 0 be)
	target_link_libraries(${name} PRIVATE ${_SERVER_LIBS})

	list (APPEND _SERVER_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR})
	target_include_directories(${name} PUBLIC ${_SERVER_INCLUDES})

endmacro()

macro( AddOn name type )

	set( _OPTIONS_ARGS )
	set( _ONE_VALUE_ARGS )
	set( _MULTI_VALUE_ARGS SOURCES LIBS INCLUDES )

	cmake_parse_arguments( _ADDON "${_OPTIONS_ARGS}" "${_ONE_VALUE_ARGS}" "${_MULTI_VALUE_ARGS}" ${ARGN} )

	add_library(${name} ${type} ${_ADDON_SOURCES})

	target_link_libraries(${name} PRIVATE ${_ADDON_LIBS})

	# Add current dir headers
	list ( APPEND _ADDON_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR} )
	target_include_directories(${name} PUBLIC ${_ADDON_INCLUDES})

endmacro()

# TODO: Add macros for Test, Catalog

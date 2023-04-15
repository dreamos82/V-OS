/*
 * Copyright 2007-2014 Haiku, Inc. All rights reserved.
 * Distributed under the terms of the MIT License.
 */
#ifndef _BUILD_ERRORS_H
#define _BUILD_ERRORS_H


#include <errno.h> /* build-specific overrides errno */
#include <limits.h>


/* Error baselines */
#define B_GENERAL_ERROR_BASE		INT_MIN
#define B_OS_ERROR_BASE				(B_GENERAL_ERROR_BASE + 0x1000)
#define B_APP_ERROR_BASE			(B_GENERAL_ERROR_BASE + 0x2000)
#define B_INTERFACE_ERROR_BASE		(B_GENERAL_ERROR_BASE + 0x3000)
#define B_MEDIA_ERROR_BASE			(B_GENERAL_ERROR_BASE + 0x4000)
										/* - 0x41ff */
#define B_TRANSLATION_ERROR_BASE	(B_GENERAL_ERROR_BASE + 0x4800)
										/* - 0x48ff */
#define B_MIDI_ERROR_BASE			(B_GENERAL_ERROR_BASE + 0x5000)
#define B_STORAGE_ERROR_BASE		(B_GENERAL_ERROR_BASE + 0x6000)
#define B_POSIX_ERROR_BASE			(B_GENERAL_ERROR_BASE + 0x7000)
#define B_MAIL_ERROR_BASE			(B_GENERAL_ERROR_BASE + 0x8000)
#define B_PRINT_ERROR_BASE			(B_GENERAL_ERROR_BASE + 0x9000)
#define B_DEVICE_ERROR_BASE			(B_GENERAL_ERROR_BASE + 0xa000)

/* Developer-defined errors start at (B_ERRORS_END+1) */
#define B_ERRORS_END				(B_GENERAL_ERROR_BASE + 0xffff)

/* General Errors */
#define B_NO_MEMORY					(B_GENERAL_ERROR_BASE + 0)
#define B_IO_ERROR					(B_GENERAL_ERROR_BASE + 1)
#define B_PERMISSION_DENIED			(B_GENERAL_ERROR_BASE + 2)
#define B_BAD_INDEX					(B_GENERAL_ERROR_BASE + 3)
#define B_BAD_TYPE					(B_GENERAL_ERROR_BASE + 4)
#define B_BAD_VALUE					(B_GENERAL_ERROR_BASE + 5)
#define B_MISMATCHED_VALUES			(B_GENERAL_ERROR_BASE + 6)
#define B_NAME_NOT_FOUND			(B_GENERAL_ERROR_BASE + 7)
#define B_NAME_IN_USE				(B_GENERAL_ERROR_BASE + 8)
#define B_TIMED_OUT					(B_GENERAL_ERROR_BASE + 9)
#define B_INTERRUPTED				(B_GENERAL_ERROR_BASE + 10)
#define B_WOULD_BLOCK				(B_GENERAL_ERROR_BASE + 11)
#define B_CANCELED					(B_GENERAL_ERROR_BASE + 12)
#define B_NO_INIT					(B_GENERAL_ERROR_BASE + 13)
#define B_NOT_INITIALIZED			(B_GENERAL_ERROR_BASE + 13)
#define B_BUSY						(B_GENERAL_ERROR_BASE + 14)
#define B_NOT_ALLOWED				(B_GENERAL_ERROR_BASE + 15)
#define B_BAD_DATA					(B_GENERAL_ERROR_BASE + 16)
#define B_DONT_DO_THAT				(B_GENERAL_ERROR_BASE + 17)

#define B_ERROR						(-1)
#define B_OK						((int)0)
#define B_NO_ERROR					((int)0)

/* Kernel Kit Errors */
#define B_BAD_SEM_ID				(B_OS_ERROR_BASE + 0)
#define B_NO_MORE_SEMS				(B_OS_ERROR_BASE + 1)

#define B_BAD_THREAD_ID				(B_OS_ERROR_BASE + 0x100)
#define B_NO_MORE_THREADS			(B_OS_ERROR_BASE + 0x101)
#define B_BAD_THREAD_STATE			(B_OS_ERROR_BASE + 0x102)
#define B_BAD_TEAM_ID				(B_OS_ERROR_BASE + 0x103)
#define B_NO_MORE_TEAMS				(B_OS_ERROR_BASE + 0x104)

#define B_BAD_PORT_ID				(B_OS_ERROR_BASE + 0x200)
#define B_NO_MORE_PORTS				(B_OS_ERROR_BASE + 0x201)

#define B_BAD_IMAGE_ID				(B_OS_ERROR_BASE + 0x300)
#define B_BAD_ADDRESS				(B_OS_ERROR_BASE + 0x301)
#define B_NOT_AN_EXECUTABLE			(B_OS_ERROR_BASE + 0x302)
#define B_MISSING_LIBRARY			(B_OS_ERROR_BASE + 0x303)
#define B_MISSING_SYMBOL			(B_OS_ERROR_BASE + 0x304)
#define B_UNKNOWN_EXECUTABLE		(B_OS_ERROR_BASE + 0x305)
#define B_LEGACY_EXECUTABLE			(B_OS_ERROR_BASE + 0x306)

#define B_DEBUGGER_ALREADY_INSTALLED	(B_OS_ERROR_BASE + 0x400)

/* Application Kit Errors */
#define B_BAD_REPLY							(B_APP_ERROR_BASE + 0)
#define B_DUPLICATE_REPLY					(B_APP_ERROR_BASE + 1)
#define B_MESSAGE_TO_SELF					(B_APP_ERROR_BASE + 2)
#define B_BAD_HANDLER						(B_APP_ERROR_BASE + 3)
#define B_ALREADY_RUNNING					(B_APP_ERROR_BASE + 4)
#define B_LAUNCH_FAILED						(B_APP_ERROR_BASE + 5)
#define B_AMBIGUOUS_APP_LAUNCH				(B_APP_ERROR_BASE + 6)
#define B_UNKNOWN_MIME_TYPE					(B_APP_ERROR_BASE + 7)
#define B_BAD_SCRIPT_SYNTAX					(B_APP_ERROR_BASE + 8)
#define B_LAUNCH_FAILED_NO_RESOLVE_LINK		(B_APP_ERROR_BASE + 9)
#define B_LAUNCH_FAILED_EXECUTABLE			(B_APP_ERROR_BASE + 10)
#define B_LAUNCH_FAILED_APP_NOT_FOUND		(B_APP_ERROR_BASE + 11)
#define B_LAUNCH_FAILED_APP_IN_TRASH		(B_APP_ERROR_BASE + 12)
#define B_LAUNCH_FAILED_NO_PREFERRED_APP	(B_APP_ERROR_BASE + 13)
#define B_LAUNCH_FAILED_FILES_APP_NOT_FOUND	(B_APP_ERROR_BASE + 14)
#define B_BAD_MIME_SNIFFER_RULE				(B_APP_ERROR_BASE + 15)
#define B_NOT_A_MESSAGE						(B_APP_ERROR_BASE + 16)
#define B_SHUTDOWN_CANCELLED				(B_APP_ERROR_BASE + 17)
#define B_SHUTTING_DOWN						(B_APP_ERROR_BASE + 18)

/* Storage Kit/File System Errors */
#define B_FILE_ERROR						(B_STORAGE_ERROR_BASE + 0)
/* 1 was B_FILE_NOT_FOUND (deprecated) */
#define B_FILE_EXISTS						(B_STORAGE_ERROR_BASE + 2)
#define B_ENTRY_NOT_FOUND					(B_STORAGE_ERROR_BASE + 3)
#define B_NAME_TOO_LONG						(B_STORAGE_ERROR_BASE + 4)
#define B_NOT_A_DIRECTORY					(B_STORAGE_ERROR_BASE + 5)
#define B_DIRECTORY_NOT_EMPTY				(B_STORAGE_ERROR_BASE + 6)
#define B_DEVICE_FULL						(B_STORAGE_ERROR_BASE + 7)
#define B_READ_ONLY_DEVICE					(B_STORAGE_ERROR_BASE + 8)
#define B_IS_A_DIRECTORY					(B_STORAGE_ERROR_BASE + 9)
#define B_NO_MORE_FDS						(B_STORAGE_ERROR_BASE + 10)
#define B_CROSS_DEVICE_LINK					(B_STORAGE_ERROR_BASE + 11)
#define B_LINK_LIMIT						(B_STORAGE_ERROR_BASE + 12)
#define B_BUSTED_PIPE						(B_STORAGE_ERROR_BASE + 13)
#define B_UNSUPPORTED						(B_STORAGE_ERROR_BASE + 14)
#define B_PARTITION_TOO_SMALL				(B_STORAGE_ERROR_BASE + 15)
#define B_PARTIAL_READ						(B_STORAGE_ERROR_BASE + 16)
#define B_PARTIAL_WRITE						(B_STORAGE_ERROR_BASE + 17)

/* POSIX Errors */
#define B_TO_POSIX_ERROR(error)		(error)
#define B_FROM_POSIX_ERROR(error)	(error)

#define B_POSIX_ENOMEM		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 0)
#define HAIKU_E2BIG			B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 1)
#define HAIKU_ECHILD		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 2)
#define HAIKU_EDEADLK		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 3)
#define HAIKU_EFBIG			B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 4)
#define HAIKU_EMLINK		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 5)
#define HAIKU_ENFILE		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 6)
#define HAIKU_ENODEV		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 7)
#define HAIKU_ENOLCK		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 8)
#define HAIKU_ENOSYS		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 9)
#define HAIKU_ENOTTY		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 10)
#define HAIKU_ENXIO			B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 11)
#define HAIKU_ESPIPE		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 12)
#define HAIKU_ESRCH			B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 13)
#define HAIKU_EFPOS			B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 14)
#define HAIKU_ESIGPARM		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 15)
#define HAIKU_EDOM			B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 16)
#define HAIKU_ERANGE		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 17)
#define HAIKU_EPROTOTYPE	B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 18)
#define HAIKU_EPROTONOSUPPORT	B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 19)
#define HAIKU_EPFNOSUPPORT	B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 20)
#define HAIKU_EAFNOSUPPORT	B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 21)
#define HAIKU_EADDRINUSE	B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 22)
#define HAIKU_EADDRNOTAVAIL	B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 23)
#define HAIKU_ENETDOWN		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 24)
#define HAIKU_ENETUNREACH	B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 25)
#define HAIKU_ENETRESET		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 26)
#define HAIKU_ECONNABORTED	B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 27)
#define HAIKU_ECONNRESET	B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 28)
#define HAIKU_EISCONN		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 29)
#define HAIKU_ENOTCONN		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 30)
#define HAIKU_ESHUTDOWN		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 31)
#define HAIKU_ECONNREFUSED	B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 32)
#define HAIKU_EHOSTUNREACH	B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 33)
#define HAIKU_ENOPROTOOPT	B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 34)
#define HAIKU_ENOBUFS		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 35)
#define HAIKU_EINPROGRESS	B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 36)
#define HAIKU_EALREADY		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 37)
#define HAIKU_EILSEQ		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 38)
#define HAIKU_ENOMSG		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 39)
#define HAIKU_ESTALE		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 40)
#define HAIKU_EOVERFLOW		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 41)
#define HAIKU_EMSGSIZE		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 42)
#define HAIKU_EOPNOTSUPP	B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 43)
#define HAIKU_ENOTSOCK		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 44)
#define HAIKU_EHOSTDOWN		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 45)
#define HAIKU_EBADMSG		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 46)
#define HAIKU_ECANCELED		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 47)
#define HAIKU_EDESTADDRREQ	B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 48)
#define HAIKU_EDQUOT		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 49)
#define HAIKU_EIDRM			B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 50)
#define HAIKU_EMULTIHOP		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 51)
#define HAIKU_ENODATA		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 52)
#define HAIKU_ENOLINK		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 53)
#define HAIKU_ENOSR			B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 54)
#define HAIKU_ENOSTR		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 55)
#define HAIKU_ENOTSUP		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 56)
#define HAIKU_EPROTO		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 57)
#define HAIKU_ETIME			B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 58)
#define HAIKU_ETXTBSY		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 59)
#define HAIKU_ENOATTR		B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 60)
#define HAIKU_ENOTRECOVERABLE	B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 61)
#define HAIKU_EOWNERDEAD	B_TO_POSIX_ERROR(B_POSIX_ERROR_BASE + 62)

/* B_NO_MEMORY (0x80000000) can't be negated, so it needs special handling */
#define HAIKU_ENOMEM		B_NO_MEMORY

/* POSIX errors that can be mapped to BeOS error codes */
#define HAIKU_EACCES		B_TO_POSIX_ERROR(B_PERMISSION_DENIED)
#define HAIKU_EINTR			B_TO_POSIX_ERROR(B_INTERRUPTED)
#define HAIKU_EIO			B_TO_POSIX_ERROR(B_IO_ERROR)
#define HAIKU_EBUSY			B_TO_POSIX_ERROR(B_BUSY)
#define HAIKU_EFAULT		B_TO_POSIX_ERROR(B_BAD_ADDRESS)
#define HAIKU_ETIMEDOUT		B_TO_POSIX_ERROR(B_TIMED_OUT)
#define HAIKU_EAGAIN 		B_TO_POSIX_ERROR(B_WOULD_BLOCK)	/* SysV compatibility */
#define HAIKU_EWOULDBLOCK 	B_TO_POSIX_ERROR(B_WOULD_BLOCK)	/* BSD compatibility */
#define HAIKU_EBADF			B_TO_POSIX_ERROR(B_FILE_ERROR)
#define HAIKU_EEXIST		B_TO_POSIX_ERROR(B_FILE_EXISTS)
#define HAIKU_EINVAL		B_TO_POSIX_ERROR(B_BAD_VALUE)
#define HAIKU_ENAMETOOLONG	B_TO_POSIX_ERROR(B_NAME_TOO_LONG)
#define HAIKU_ENOENT		B_TO_POSIX_ERROR(B_ENTRY_NOT_FOUND)
#define HAIKU_EPERM			B_TO_POSIX_ERROR(B_NOT_ALLOWED)
#define HAIKU_ENOTDIR		B_TO_POSIX_ERROR(B_NOT_A_DIRECTORY)
#define HAIKU_EISDIR		B_TO_POSIX_ERROR(B_IS_A_DIRECTORY)
#define HAIKU_ENOTEMPTY		B_TO_POSIX_ERROR(B_DIRECTORY_NOT_EMPTY)
#define HAIKU_ENOSPC		B_TO_POSIX_ERROR(B_DEVICE_FULL)
#define HAIKU_EROFS			B_TO_POSIX_ERROR(B_READ_ONLY_DEVICE)
#define HAIKU_EMFILE		B_TO_POSIX_ERROR(B_NO_MORE_FDS)
#define HAIKU_EXDEV			B_TO_POSIX_ERROR(B_CROSS_DEVICE_LINK)
#define HAIKU_ELOOP			B_TO_POSIX_ERROR(B_LINK_LIMIT)
#define HAIKU_ENOEXEC		B_TO_POSIX_ERROR(B_NOT_AN_EXECUTABLE)
#define HAIKU_EPIPE			B_TO_POSIX_ERROR(B_BUSTED_PIPE)

/* new error codes that can be mapped to POSIX errors */
#ifndef BUILDING_HAIKU_ERROR_MAPPER
#define B_BUFFER_OVERFLOW			B_FROM_POSIX_ERROR(HAIKU_EOVERFLOW)
#define B_TOO_MANY_ARGS				B_FROM_POSIX_ERROR(HAIKU_E2BIG)
#define B_FILE_TOO_LARGE			B_FROM_POSIX_ERROR(HAIKU_EFBIG)
#define B_RESULT_NOT_REPRESENTABLE	B_FROM_POSIX_ERROR(HAIKU_ERANGE)
#define B_DEVICE_NOT_FOUND			B_FROM_POSIX_ERROR(HAIKU_ENODEV)
#define B_NOT_SUPPORTED				B_FROM_POSIX_ERROR(HAIKU_EOPNOTSUPP)
#endif

/* Media Kit Errors */
#define B_STREAM_NOT_FOUND				(B_MEDIA_ERROR_BASE + 0)
#define B_SERVER_NOT_FOUND				(B_MEDIA_ERROR_BASE + 1)
#define B_RESOURCE_NOT_FOUND			(B_MEDIA_ERROR_BASE + 2)
#define B_RESOURCE_UNAVAILABLE			(B_MEDIA_ERROR_BASE + 3)
#define B_BAD_SUBSCRIBER				(B_MEDIA_ERROR_BASE + 4)
#define B_SUBSCRIBER_NOT_ENTERED		(B_MEDIA_ERROR_BASE + 5)
#define B_BUFFER_NOT_AVAILABLE			(B_MEDIA_ERROR_BASE + 6)
#define B_LAST_BUFFER_ERROR				(B_MEDIA_ERROR_BASE + 7)

#define B_MEDIA_SYSTEM_FAILURE			(B_MEDIA_ERROR_BASE + 100)
#define B_MEDIA_BAD_NODE				(B_MEDIA_ERROR_BASE + 101)
#define B_MEDIA_NODE_BUSY				(B_MEDIA_ERROR_BASE + 102)
#define B_MEDIA_BAD_FORMAT				(B_MEDIA_ERROR_BASE + 103)
#define B_MEDIA_BAD_BUFFER				(B_MEDIA_ERROR_BASE + 104)
#define B_MEDIA_TOO_MANY_NODES			(B_MEDIA_ERROR_BASE + 105)
#define B_MEDIA_TOO_MANY_BUFFERS		(B_MEDIA_ERROR_BASE + 106)
#define B_MEDIA_NODE_ALREADY_EXISTS		(B_MEDIA_ERROR_BASE + 107)
#define B_MEDIA_BUFFER_ALREADY_EXISTS	(B_MEDIA_ERROR_BASE + 108)
#define B_MEDIA_CANNOT_SEEK				(B_MEDIA_ERROR_BASE + 109)
#define B_MEDIA_CANNOT_CHANGE_RUN_MODE	(B_MEDIA_ERROR_BASE + 110)
#define B_MEDIA_APP_ALREADY_REGISTERED	(B_MEDIA_ERROR_BASE + 111)
#define B_MEDIA_APP_NOT_REGISTERED		(B_MEDIA_ERROR_BASE + 112)
#define B_MEDIA_CANNOT_RECLAIM_BUFFERS	(B_MEDIA_ERROR_BASE + 113)
#define B_MEDIA_BUFFERS_NOT_RECLAIMED	(B_MEDIA_ERROR_BASE + 114)
#define B_MEDIA_TIME_SOURCE_STOPPED		(B_MEDIA_ERROR_BASE + 115)
#define B_MEDIA_TIME_SOURCE_BUSY		(B_MEDIA_ERROR_BASE + 116)
#define B_MEDIA_BAD_SOURCE				(B_MEDIA_ERROR_BASE + 117)
#define B_MEDIA_BAD_DESTINATION			(B_MEDIA_ERROR_BASE + 118)
#define B_MEDIA_ALREADY_CONNECTED		(B_MEDIA_ERROR_BASE + 119)
#define B_MEDIA_NOT_CONNECTED			(B_MEDIA_ERROR_BASE + 120)
#define B_MEDIA_BAD_CLIP_FORMAT			(B_MEDIA_ERROR_BASE + 121)
#define B_MEDIA_ADDON_FAILED			(B_MEDIA_ERROR_BASE + 122)
#define B_MEDIA_ADDON_DISABLED			(B_MEDIA_ERROR_BASE + 123)
#define B_MEDIA_CHANGE_IN_PROGRESS		(B_MEDIA_ERROR_BASE + 124)
#define B_MEDIA_STALE_CHANGE_COUNT		(B_MEDIA_ERROR_BASE + 125)
#define B_MEDIA_ADDON_RESTRICTED		(B_MEDIA_ERROR_BASE + 126)
#define B_MEDIA_NO_HANDLER				(B_MEDIA_ERROR_BASE + 127)
#define B_MEDIA_DUPLICATE_FORMAT		(B_MEDIA_ERROR_BASE + 128)
#define B_MEDIA_REALTIME_DISABLED		(B_MEDIA_ERROR_BASE + 129)
#define B_MEDIA_REALTIME_UNAVAILABLE	(B_MEDIA_ERROR_BASE + 130)

/* Mail Kit Errors */
#define B_MAIL_NO_DAEMON				(B_MAIL_ERROR_BASE + 0)
#define B_MAIL_UNKNOWN_USER				(B_MAIL_ERROR_BASE + 1)
#define B_MAIL_WRONG_PASSWORD			(B_MAIL_ERROR_BASE + 2)
#define B_MAIL_UNKNOWN_HOST				(B_MAIL_ERROR_BASE + 3)
#define B_MAIL_ACCESS_ERROR				(B_MAIL_ERROR_BASE + 4)
#define B_MAIL_UNKNOWN_FIELD			(B_MAIL_ERROR_BASE + 5)
#define B_MAIL_NO_RECIPIENT				(B_MAIL_ERROR_BASE + 6)
#define B_MAIL_INVALID_MAIL				(B_MAIL_ERROR_BASE + 7)

/* Printing Errors */
#define B_NO_PRINT_SERVER				(B_PRINT_ERROR_BASE + 0)

/* Device Kit Errors */
#define B_DEV_INVALID_IOCTL				(B_DEVICE_ERROR_BASE + 0)
#define B_DEV_NO_MEMORY					(B_DEVICE_ERROR_BASE + 1)
#define B_DEV_BAD_DRIVE_NUM				(B_DEVICE_ERROR_BASE + 2)
#define B_DEV_NO_MEDIA					(B_DEVICE_ERROR_BASE + 3)
#define B_DEV_UNREADABLE				(B_DEVICE_ERROR_BASE + 4)
#define B_DEV_FORMAT_ERROR				(B_DEVICE_ERROR_BASE + 5)
#define B_DEV_TIMEOUT					(B_DEVICE_ERROR_BASE + 6)
#define B_DEV_RECALIBRATE_ERROR			(B_DEVICE_ERROR_BASE + 7)
#define B_DEV_SEEK_ERROR				(B_DEVICE_ERROR_BASE + 8)
#define B_DEV_ID_ERROR					(B_DEVICE_ERROR_BASE + 9)
#define B_DEV_READ_ERROR				(B_DEVICE_ERROR_BASE + 10)
#define B_DEV_WRITE_ERROR				(B_DEVICE_ERROR_BASE + 11)
#define B_DEV_NOT_READY					(B_DEVICE_ERROR_BASE + 12)
#define B_DEV_MEDIA_CHANGED				(B_DEVICE_ERROR_BASE + 13)
#define B_DEV_MEDIA_CHANGE_REQUESTED	(B_DEVICE_ERROR_BASE + 14)
#define B_DEV_RESOURCE_CONFLICT			(B_DEVICE_ERROR_BASE + 15)
#define B_DEV_CONFIGURATION_ERROR		(B_DEVICE_ERROR_BASE + 16)
#define B_DEV_DISABLED_BY_USER			(B_DEVICE_ERROR_BASE + 17)
#define B_DEV_DOOR_OPEN					(B_DEVICE_ERROR_BASE + 18)

#define B_DEV_INVALID_PIPE				(B_DEVICE_ERROR_BASE + 19)
#define B_DEV_CRC_ERROR					(B_DEVICE_ERROR_BASE + 20)
#define B_DEV_STALLED					(B_DEVICE_ERROR_BASE + 21)
#define B_DEV_BAD_PID					(B_DEVICE_ERROR_BASE + 22)
#define B_DEV_UNEXPECTED_PID			(B_DEVICE_ERROR_BASE + 23)
#define B_DEV_DATA_OVERRUN				(B_DEVICE_ERROR_BASE + 24)
#define B_DEV_DATA_UNDERRUN				(B_DEVICE_ERROR_BASE + 25)
#define B_DEV_FIFO_OVERRUN				(B_DEVICE_ERROR_BASE + 26)
#define B_DEV_FIFO_UNDERRUN				(B_DEVICE_ERROR_BASE + 27)
#define B_DEV_PENDING					(B_DEVICE_ERROR_BASE + 28)
#define B_DEV_MULTIPLE_ERRORS			(B_DEVICE_ERROR_BASE + 29)
#define B_DEV_TOO_LATE					(B_DEVICE_ERROR_BASE + 30)

/* Translation Kit Errors */
#define B_TRANSLATION_BASE_ERROR		(B_TRANSLATION_ERROR_BASE + 0)
#define B_NO_TRANSLATOR					(B_TRANSLATION_ERROR_BASE + 1)
#define B_ILLEGAL_DATA					(B_TRANSLATION_ERROR_BASE + 2)


/* build-specific code */
#ifndef BUILDING_HAIKU_ERROR_MAPPER
	#undef E2BIG
	#undef ECHILD
	#undef EDEADLK
	#undef EFBIG
	#undef EMLINK
	#undef ENFILE
	#undef ENODEV
	#undef ENOLCK
	#undef ENOSYS
	#undef ENOTTY
	#undef ENXIO
	#undef ESPIPE
	#undef ESRCH
	#undef EFPOS
	#undef ESIGPARM
	#undef EDOM
	#undef ERANGE
	#undef EPROTOTYPE
	#undef EPROTONOSUPPORT
	#undef EPFNOSUPPORT
	#undef EAFNOSUPPORT
	#undef EADDRINUSE
	#undef EADDRNOTAVAIL
	#undef ENETDOWN
	#undef ENETUNREACH
	#undef ENETRESET
	#undef ECONNABORTED
	#undef ECONNRESET
	#undef EISCONN
	#undef ENOTCONN
	#undef ESHUTDOWN
	#undef ECONNREFUSED
	#undef EHOSTUNREACH
	#undef ENOPROTOOPT
	#undef ENOBUFS
	#undef EINPROGRESS
	#undef EALREADY
	#undef EILSEQ
	#undef ENOMSG
	#undef ESTALE
	#undef EOVERFLOW
	#undef EMSGSIZE
	#undef EOPNOTSUPP
	#undef ENOTSOCK
	#undef EHOSTDOWN
	#undef EBADMSG
	#undef ECANCELED
	#undef EDESTADDRREQ
	#undef EDQUOT
	#undef EIDRM
	#undef EMULTIHOP
	#undef ENODATA
	#undef ENOLINK
	#undef ENOSR
	#undef ENOSTR
	#undef ENOTSUP
	#undef EPROTO
	#undef ETIME
	#undef ETXTBSY
	#undef ENOMEM
	#undef EACCES
	#undef EINTR
	#undef EIO
	#undef EBUSY
	#undef EFAULT
	#undef ETIMEDOUT
	#undef EAGAIN
	#undef EWOULDBLOCK
	#undef EBADF
	#undef EEXIST
	#undef EINVAL
	#undef ENAMETOOLONG
	#undef ENOENT
	#undef EPERM
	#undef ENOTDIR
	#undef EISDIR
	#undef ENOTEMPTY
	#undef ENOSPC
	#undef EROFS
	#undef EMFILE
	#undef EXDEV
	#undef ELOOP
	#undef ENOEXEC
	#undef EPIPE
	#undef ENOATTR

	#define E2BIG HAIKU_E2BIG
	#define ECHILD HAIKU_ECHILD
	#define EDEADLK HAIKU_EDEADLK
	#define EFBIG HAIKU_EFBIG
	#define EMLINK HAIKU_EMLINK
	#define ENFILE HAIKU_ENFILE
	#define ENODEV HAIKU_ENODEV
	#define ENOLCK HAIKU_ENOLCK
	#define ENOSYS HAIKU_ENOSYS
	#define ENOTTY HAIKU_ENOTTY
	#define ENXIO HAIKU_ENXIO
	#define ESPIPE HAIKU_ESPIPE
	#define ESRCH HAIKU_ESRCH
	#define EFPOS HAIKU_EFPOS
	#define ESIGPARM HAIKU_ESIGPARM
	#define EDOM HAIKU_EDOM
	#define ERANGE HAIKU_ERANGE
	#define EPROTOTYPE HAIKU_EPROTOTYPE
	#define EPROTONOSUPPORT HAIKU_EPROTONOSUPPORT
	#define EPFNOSUPPORT HAIKU_EPFNOSUPPORT
	#define EAFNOSUPPORT HAIKU_EAFNOSUPPORT
	#define EADDRINUSE HAIKU_EADDRINUSE
	#define EADDRNOTAVAIL HAIKU_EADDRNOTAVAIL
	#define ENETDOWN HAIKU_ENETDOWN
	#define ENETUNREACH HAIKU_ENETUNREACH
	#define ENETRESET HAIKU_ENETRESET
	#define ECONNABORTED HAIKU_ECONNABORTED
	#define ECONNRESET HAIKU_ECONNRESET
	#define EISCONN HAIKU_EISCONN
	#define ENOTCONN HAIKU_ENOTCONN
	#define ESHUTDOWN HAIKU_ESHUTDOWN
	#define ECONNREFUSED HAIKU_ECONNREFUSED
	#define EHOSTUNREACH HAIKU_EHOSTUNREACH
	#define ENOPROTOOPT HAIKU_ENOPROTOOPT
	#define ENOBUFS HAIKU_ENOBUFS
	#define EINPROGRESS HAIKU_EINPROGRESS
	#define EALREADY HAIKU_EALREADY
	#define EILSEQ HAIKU_EILSEQ
	#define ENOMSG HAIKU_ENOMSG
	#define ESTALE HAIKU_ESTALE
	#define EOVERFLOW HAIKU_EOVERFLOW
	#define EMSGSIZE HAIKU_EMSGSIZE
	#define EOPNOTSUPP HAIKU_EOPNOTSUPP
	#define ENOTSOCK HAIKU_ENOTSOCK
	#define EHOSTDOWN HAIKU_EHOSTDOWN
	#define	EBADMSG HAIKU_EBADMSG
	#define ECANCELED HAIKU_ECANCELED
	#define EDESTADDRREQ HAIKU_EDESTADDRREQ
	#define EDQUOT HAIKU_EDQUOT
	#define EIDRM HAIKU_EIDRM
	#define EMULTIHOP HAIKU_EMULTIHOP
	#define ENODATA HAIKU_ENODATA
	#define ENOLINK HAIKU_ENOLINK
	#define ENOSR HAIKU_ENOSR
	#define ENOSTR HAIKU_ENOSTR
	#define ENOTSUP HAIKU_ENOTSUP
	#define EPROTO HAIKU_EPROTO
	#define ETIME HAIKU_ETIME
	#define ETXTBSY HAIKU_ETXTBSY
	#define ENOMEM HAIKU_ENOMEM
	#define EACCES HAIKU_EACCES
	#define EINTR HAIKU_EINTR
	#define EIO HAIKU_EIO
	#define EBUSY HAIKU_EBUSY
	#define EFAULT HAIKU_EFAULT
	#define ETIMEDOUT HAIKU_ETIMEDOUT
	#define EAGAIN HAIKU_EAGAIN
	#define EWOULDBLOCK HAIKU_EWOULDBLOCK
	#define EBADF HAIKU_EBADF
	#define EEXIST HAIKU_EEXIST
	#define EINVAL HAIKU_EINVAL
	#define ENAMETOOLONG HAIKU_ENAMETOOLONG
	#define ENOENT HAIKU_ENOENT
	#define EPERM HAIKU_EPERM
	#define ENOTDIR HAIKU_ENOTDIR
	#define EISDIR HAIKU_EISDIR
	#define ENOTEMPTY HAIKU_ENOTEMPTY
	#define ENOSPC HAIKU_ENOSPC
	#define EROFS HAIKU_EROFS
	#define EMFILE HAIKU_EMFILE
	#define EXDEV HAIKU_EXDEV
	#define ELOOP HAIKU_ELOOP
	#define ENOEXEC HAIKU_ENOEXEC
	#define EPIPE HAIKU_EPIPE
	#define ENOATTR HAIKU_ENOATTR

	//#undef errno
	//#define errno (*_haiku_build_errno())
#elif defined(HAIKU_HOST_PLATFORM_HAIKU)
#	include <../os/support/Errors.h>
#endif	// ! BUILDING_HAIKU_ERROR_MAPPER

#ifdef __cplusplus
extern "C" {
#endif

extern int *_haiku_build_errno();
extern int _haiku_to_host_error(int error);

#ifdef __cplusplus
}
#endif


#endif	/* _BUILD_ERRORS_H */

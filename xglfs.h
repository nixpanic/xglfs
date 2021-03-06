/* vim: set tabstop=4:softtabstop=4:shiftwidth=4:noexpandtab */

/*
 * xglfs - GlusterFS API FUSE client
 * Copyright (C) Oleksandr Natalenko <oleksandr@natalenko.name>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <fuse.h>
#include <glusterfs/api/glfs.h>
#include <string.h>

#define GLFS_DEFAULT_PORT		24007
#define GLFS_DEFAULT_PROTOCOL	"tcp"
#define GLFS_DEFAULT_VERBOSITY	7
#define DEV_NULL				"/dev/null"

#ifdef __GNUC__
#define likely(x)				__builtin_expect(!!(x), 1)
#define unlikely(x)				__builtin_expect(!!(x), 0)
#else /* __GNUC__ */
#define likely(x)				(x)
#define unlikely(x)				(x)
#endif /* __GNUC__ */

struct xglfs_state
{
	glfs_t* fs;
	char* protocol;
	char* server;
	int port;
	char* volume;
	char* glfs_logfile;
	int glfs_verbosity;
};

#define XGLFS_STATE	((struct xglfs_state*)fuse_get_context()->private_data)
#define FH_TO_FD(A)	((glfs_fd_t*)(uintptr_t)(A))
#define FD_TO_FH(A)	((uint64_t)(uintptr_t)(A))


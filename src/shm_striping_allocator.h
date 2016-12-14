/**
* Copyright (C) 2008 Happy Fish / YuQing
*
* FastDFS may be copied only under the terms of the GNU General
* Public License V3, which may be found in the FastDFS source kit.
* Please visit the FastDFS Home Page http://www.csource.org/ for more detail.
**/

//shm_striping_allocator.h

#ifndef _SHM_STRIPING_ALLOCATOR_H
#define _SHM_STRIPING_ALLOCATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "common_define.h"
#include "shmcache_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
allocator init
parameters:
	allocator: the allocator pointer
    ssp_index: segment and striping pair
    base_offset: the base offset
	total_size: the memory size
return error no, 0 for success, != 0 fail
*/
void shm_striping_allocator_init(struct shm_striping_allocator *allocator,
		const struct shm_segment_striping_pair *ssp_index,
        const int64_t base_offset, const int total_size);

/**
reset for recycle use
parameters:
	allocator: the allocator pointer
*/
void shm_striping_allocator_reset(struct shm_striping_allocator *allocator);

/**
alloc memory from the allocator
parameters:
	allocator: the allocator pointer
    size: alloc bytes
return the alloced memory offset, return -1 if fail
*/
int64_t shm_striping_allocator_alloc(struct shm_striping_allocator *allocator,
        const int size);

/**
free memory to the allocator
parameters:
	allocator: the allocator pointer
    size: alloc bytes
return none
*/
void shm_striping_allocator_free(struct shm_striping_allocator *allocator,
        const int size);

#ifdef __cplusplus
}
#endif

#endif


/*
 * CAAM public-level include definitions for the key blob
 *
 * Copyright (C) 2015 Freescale Semiconductor, Inc.
 */

#ifndef CAAM_KEYBLOB_H
#define CAAM_KEYBLOB_H


#include <linux/ioctl.h>
#include <linux/types.h>

struct caam_kb_data {
	char *rawkey;
    size_t rawkey_len;
    char *keyblob;
    size_t keyblob_len;
    char *keymod;
    size_t keymod_len;
};


/* Define space required for BKEK + MAC tag storage in any blob */
#define BLOB_OVERHEAD (32 + 16)

#define CAAM_KB_MAGIC		'I'

/**
 * DOC: CAAM_KB_ENCRYPT - generate a key blob from raw key
 *
 * Takes an caam_kb_data struct and returns it with the key blob
 */
#define CAAM_KB_ENCRYPT		_IOWR(CAAM_KB_MAGIC, 0, \
				      struct caam_kb_data)

/**
 * DOC: CAAM_KB_DECRYPT - get keys from a key blob
 *
 * Takes an caam_kb_data struct and returns it with the raw key.
 */
#define CAAM_KB_DECRYPT		_IOWR(CAAM_KB_MAGIC, 1, struct caam_kb_data)


/**
 * DOC: CAAM_KB_GET_MONOTONIC_COUNTER - retrieves 8-byte monotonic counter 
 *
 * Retrieves 8-byte monotonic counter and places it in keymod location (little endian).
 */
#define CAAM_KB_GET_MONOTONIC_COUNTER		_IOWR(CAAM_KB_MAGIC, 2, struct caam_kb_data)

/**
 * DOC: CAAM_KB_INC_MONOTONIC_COUNTER - Increments monotonic counter. 
 *
 * Increments monotonic counter. 
 */
#define CAAM_KB_INC_MONOTONIC_COUNTER		_IOWR(CAAM_KB_MAGIC, 3, struct caam_kb_data)



#ifndef GENMEM_KEYMOD_LEN
#define GENMEM_KEYMOD_LEN 16
#endif

#endif /* CAAM_KEYBLOB_H */

/* SPDX-License-Identifier: GPL-2.0+ WITH Linux-syscall-note */
/*
 * include/uapi/linux/if_macsec.h - MACsec device
 *
 * Copyright (c) 2015 Sabrina Dubroca <sd@queasysnail.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef _MACSEC_H
#define _MACSEC_H

#include <linux/types.h>

#define MACSEC_GENL_NAME "macsec"
#define MACSEC_GENL_VERSION 1

#define MACSEC_MAX_KEY_LEN 128

#define MACSEC_KEYID_LEN 16

#define MACSEC_DEFAULT_CIPHER_ID   0x0080020001000001ULL
#define MACSEC_DEFAULT_CIPHER_ALT  0x0080C20001000001ULL

#define MACSEC_MIN_ICV_LEN 8
#define MACSEC_MAX_ICV_LEN 32
/* upper limit for ICV length as recommended by IEEE802.1AE-2006 */
#define MACSEC_STD_ICV_LEN 16

enum macsec_attrs {
	MACSEC_ATTR_UNSPEC,
	MACSEC_ATTR_IFINDEX,     /* u32, ifindex of the MACsec netdevice */
	MACSEC_ATTR_RXSC_CONFIG, /* config, nested macsec_rxsc_attrs */
	MACSEC_ATTR_SA_CONFIG,   /* config, nested macsec_sa_attrs */
	MACSEC_ATTR_SECY,        /* dump, nested macsec_secy_attrs */
	MACSEC_ATTR_TXSA_LIST,   /* dump, nested, macsec_sa_attrs for each TXSA */
	MACSEC_ATTR_RXSC_LIST,   /* dump, nested, macsec_rxsc_attrs for each RXSC */
	MACSEC_ATTR_TXSC_STATS,  /* dump, nested, macsec_txsc_stats_attr */
	MACSEC_ATTR_SECY_STATS,  /* dump, nested, macsec_secy_stats_attr */
	__MACSEC_ATTR_END,
	NUM_MACSEC_ATTR = __MACSEC_ATTR_END,
	MACSEC_ATTR_MAX = __MACSEC_ATTR_END - 1,
};

enum macsec_secy_attrs {
	MACSEC_SECY_ATTR_UNSPEC,
	MACSEC_SECY_ATTR_SCI,
	MACSEC_SECY_ATTR_ENCODING_SA,
	MACSEC_SECY_ATTR_WINDOW,
	MACSEC_SECY_ATTR_CIPHER_SUITE,
	MACSEC_SECY_ATTR_ICV_LEN,
	MACSEC_SECY_ATTR_PROTECT,
	MACSEC_SECY_ATTR_REPLAY,
	MACSEC_SECY_ATTR_OPER,
	MACSEC_SECY_ATTR_VALIDATE,
	MACSEC_SECY_ATTR_ENCRYPT,
	MACSEC_SECY_ATTR_INC_SCI,
	MACSEC_SECY_ATTR_ES,
	MACSEC_SECY_ATTR_SCB,
	MACSEC_SECY_ATTR_PAD,
	__MACSEC_SECY_ATTR_END,
	NUM_MACSEC_SECY_ATTR = __MACSEC_SECY_ATTR_END,
	MACSEC_SECY_ATTR_MAX = __MACSEC_SECY_ATTR_END - 1,
};

enum macsec_rxsc_attrs {
	MACSEC_RXSC_ATTR_UNSPEC,
	MACSEC_RXSC_ATTR_SCI,     /* config/dump, u64 */
	MACSEC_RXSC_ATTR_ACTIVE,  /* config/dump, u8 0..1 */
	MACSEC_RXSC_ATTR_SA_LIST, /* dump, nested */
	MACSEC_RXSC_ATTR_STATS,   /* dump, nested, macsec_rxsc_stats_attr */
	MACSEC_RXSC_ATTR_PAD,
	__MACSEC_RXSC_ATTR_END,
	NUM_MACSEC_RXSC_ATTR = __MACSEC_RXSC_ATTR_END,
	MACSEC_RXSC_ATTR_MAX = __MACSEC_RXSC_ATTR_END - 1,
};

enum macsec_sa_attrs {
	MACSEC_SA_ATTR_UNSPEC,
	MACSEC_SA_ATTR_AN,     /* config/dump, u8 0..3 */
	MACSEC_SA_ATTR_ACTIVE, /* config/dump, u8 0..1 */
	MACSEC_SA_ATTR_PN,     /* config/dump, u32 */
	MACSEC_SA_ATTR_KEY,    /* config, data */
	MACSEC_SA_ATTR_KEYID,  /* config/dump, 128-bit */
	MACSEC_SA_ATTR_STATS,  /* dump, nested, macsec_sa_stats_attr */
	MACSEC_SA_ATTR_PAD,
	__MACSEC_SA_ATTR_END,
	NUM_MACSEC_SA_ATTR = __MACSEC_SA_ATTR_END,
	MACSEC_SA_ATTR_MAX = __MACSEC_SA_ATTR_END - 1,
};

enum macsec_nl_commands {
	MACSEC_CMD_GET_TXSC,
	MACSEC_CMD_ADD_RXSC,
	MACSEC_CMD_DEL_RXSC,
	MACSEC_CMD_UPD_RXSC,
	MACSEC_CMD_ADD_TXSA,
	MACSEC_CMD_DEL_TXSA,
	MACSEC_CMD_UPD_TXSA,
	MACSEC_CMD_ADD_RXSA,
	MACSEC_CMD_DEL_RXSA,
	MACSEC_CMD_UPD_RXSA,
};

/* u64 per-RXSC stats */
enum macsec_rxsc_stats_attr {
	MACSEC_RXSC_STATS_ATTR_UNSPEC,
	MACSEC_RXSC_STATS_ATTR_IN_OCTETS_VALIDATED,
	MACSEC_RXSC_STATS_ATTR_IN_OCTETS_DECRYPTED,
	MACSEC_RXSC_STATS_ATTR_IN_PKTS_UNCHECKED,
	MACSEC_RXSC_STATS_ATTR_IN_PKTS_DELAYED,
	MACSEC_RXSC_STATS_ATTR_IN_PKTS_OK,
	MACSEC_RXSC_STATS_ATTR_IN_PKTS_INVALID,
	MACSEC_RXSC_STATS_ATTR_IN_PKTS_LATE,
	MACSEC_RXSC_STATS_ATTR_IN_PKTS_NOT_VALID,
	MACSEC_RXSC_STATS_ATTR_IN_PKTS_NOT_USING_SA,
	MACSEC_RXSC_STATS_ATTR_IN_PKTS_UNUSED_SA,
	MACSEC_RXSC_STATS_ATTR_PAD,
	__MACSEC_RXSC_STATS_ATTR_END,
	NUM_MACSEC_RXSC_STATS_ATTR = __MACSEC_RXSC_STATS_ATTR_END,
	MACSEC_RXSC_STATS_ATTR_MAX = __MACSEC_RXSC_STATS_ATTR_END - 1,
};

/* u32 per-{RX,TX}SA stats */
enum macsec_sa_stats_attr {
	MACSEC_SA_STATS_ATTR_UNSPEC,
	MACSEC_SA_STATS_ATTR_IN_PKTS_OK,
	MACSEC_SA_STATS_ATTR_IN_PKTS_INVALID,
	MACSEC_SA_STATS_ATTR_IN_PKTS_NOT_VALID,
	MACSEC_SA_STATS_ATTR_IN_PKTS_NOT_USING_SA,
	MACSEC_SA_STATS_ATTR_IN_PKTS_UNUSED_SA,
	MACSEC_SA_STATS_ATTR_OUT_PKTS_PROTECTED,
	MACSEC_SA_STATS_ATTR_OUT_PKTS_ENCRYPTED,
	__MACSEC_SA_STATS_ATTR_END,
	NUM_MACSEC_SA_STATS_ATTR = __MACSEC_SA_STATS_ATTR_END,
	MACSEC_SA_STATS_ATTR_MAX = __MACSEC_SA_STATS_ATTR_END - 1,
};

/* u64 per-TXSC stats */
enum macsec_txsc_stats_attr {
	MACSEC_TXSC_STATS_ATTR_UNSPEC,
	MACSEC_TXSC_STATS_ATTR_OUT_PKTS_PROTECTED,
	MACSEC_TXSC_STATS_ATTR_OUT_PKTS_ENCRYPTED,
	MACSEC_TXSC_STATS_ATTR_OUT_OCTETS_PROTECTED,
	MACSEC_TXSC_STATS_ATTR_OUT_OCTETS_ENCRYPTED,
	MACSEC_TXSC_STATS_ATTR_PAD,
	__MACSEC_TXSC_STATS_ATTR_END,
	NUM_MACSEC_TXSC_STATS_ATTR = __MACSEC_TXSC_STATS_ATTR_END,
	MACSEC_TXSC_STATS_ATTR_MAX = __MACSEC_TXSC_STATS_ATTR_END - 1,
};

/* u64 per-SecY stats */
enum macsec_secy_stats_attr {
	MACSEC_SECY_STATS_ATTR_UNSPEC,
	MACSEC_SECY_STATS_ATTR_OUT_PKTS_UNTAGGED,
	MACSEC_SECY_STATS_ATTR_IN_PKTS_UNTAGGED,
	MACSEC_SECY_STATS_ATTR_OUT_PKTS_TOO_LONG,
	MACSEC_SECY_STATS_ATTR_IN_PKTS_NO_TAG,
	MACSEC_SECY_STATS_ATTR_IN_PKTS_BAD_TAG,
	MACSEC_SECY_STATS_ATTR_IN_PKTS_UNKNOWN_SCI,
	MACSEC_SECY_STATS_ATTR_IN_PKTS_NO_SCI,
	MACSEC_SECY_STATS_ATTR_IN_PKTS_OVERRUN,
	MACSEC_SECY_STATS_ATTR_PAD,
	__MACSEC_SECY_STATS_ATTR_END,
	NUM_MACSEC_SECY_STATS_ATTR = __MACSEC_SECY_STATS_ATTR_END,
	MACSEC_SECY_STATS_ATTR_MAX = __MACSEC_SECY_STATS_ATTR_END - 1,
};

#endif /* _MACSEC_H */

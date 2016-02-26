#ifndef __LINUX_PKT_CLS_H
#define __LINUX_PKT_CLS_H

#include <linux/types.h>
#include <linux/pkt_sched.h>


/* Action attributes */
enum {
	TCA_ACT_UNSPEC,
	TCA_ACT_KIND,
	TCA_ACT_OPTIONS,
	TCA_ACT_INDEX,
	TCA_ACT_STATS,
	__TCA_ACT_MAX
};

#define TCA_ACT_MAX __TCA_ACT_MAX
#define TCA_OLD_COMPAT (TCA_ACT_MAX+1)
#define TCA_ACT_MAX_PRIO 32
#define TCA_ACT_BIND	1
#define TCA_ACT_NOBIND	0
#define TCA_ACT_UNBIND	1
#define TCA_ACT_NOUNBIND	0
#define TCA_ACT_REPLACE		1
#define TCA_ACT_NOREPLACE	0

#define TC_ACT_UNSPEC	(-1)
#define TC_ACT_OK		0
#define TC_ACT_RECLASSIFY	1
#define TC_ACT_SHOT		2
#define TC_ACT_PIPE		3
#define TC_ACT_STOLEN		4
#define TC_ACT_QUEUED		5
#define TC_ACT_REPEAT		6
#define TC_ACT_REDIRECT		7
#define TC_ACT_JUMP		0x10000000

/* Action type identifiers*/
enum {
	TCA_ID_UNSPEC=0,
	TCA_ID_POLICE=1,
	/* other actions go here */
	__TCA_ID_MAX=255
};

#define TCA_ID_MAX __TCA_ID_MAX

struct tc_police {
	__u32			index;
	int			action;
#define TC_POLICE_UNSPEC	TC_ACT_UNSPEC
#define TC_POLICE_OK		TC_ACT_OK
#define TC_POLICE_RECLASSIFY	TC_ACT_RECLASSIFY
#define TC_POLICE_SHOT		TC_ACT_SHOT
#define TC_POLICE_PIPE		TC_ACT_PIPE

	__u32			limit;
	__u32			burst;
	__u32			mtu;
	struct tc_ratespec	rate;
	struct tc_ratespec	peakrate;
	int 			refcnt;
	int 			bindcnt;
	__u32			capab;
};

struct tcf_t {
	__u64   install;
	__u64   lastuse;
	__u64   expires;
};

struct tc_cnt {
	int                   refcnt; 
	int                   bindcnt;
};

#define tc_gen \
	__u32                 index; \
	__u32                 capab; \
	int                   action; \
	int                   refcnt; \
	int                   bindcnt

enum {
	TCA_POLICE_UNSPEC,
	TCA_POLICE_TBF,
	TCA_POLICE_RATE,
	TCA_POLICE_PEAKRATE,
	TCA_POLICE_AVRATE,
	TCA_POLICE_RESULT,
	__TCA_POLICE_MAX
#define TCA_POLICE_RESULT TCA_POLICE_RESULT
};

#define TCA_POLICE_MAX (__TCA_POLICE_MAX - 1)

/* U32 filters */

#define TC_U32_HTID(h) ((h)&0xFFF00000)
#define TC_U32_USERHTID(h) (TC_U32_HTID(h)>>20)
#define TC_U32_HASH(h) (((h)>>12)&0xFF)
#define TC_U32_NODE(h) ((h)&0xFFF)
#define TC_U32_KEY(h) ((h)&0xFFFFF)
#define TC_U32_UNSPEC	0
#define TC_U32_ROOT	(0xFFF00000)

enum {
	TCA_U32_UNSPEC,
	TCA_U32_CLASSID,
	TCA_U32_HASH,
	TCA_U32_LINK,
	TCA_U32_DIVISOR,
	TCA_U32_SEL,
	TCA_U32_POLICE,
	TCA_U32_ACT,   
	TCA_U32_INDEV,
	TCA_U32_PCNT,
	TCA_U32_MARK,
	TCA_U32_FLAGS,
	__TCA_U32_MAX
};

#define TCA_U32_MAX (__TCA_U32_MAX - 1)

struct tc_u32_key {
	__be32		mask;
	__be32		val;
	int		off;
	int		offmask;
};

struct tc_u32_sel {
	unsigned char		flags;
	unsigned char		offshift;
	unsigned char		nkeys;

	__be16			offmask;
	__u16			off;
	short			offoff;

	short			hoff;
	__be32			hmask;
	struct tc_u32_key	keys[0];
};

struct tc_u32_mark {
	__u32		val;
	__u32		mask;
	__u32		success;
};

struct tc_u32_pcnt {
	__u64 rcnt;
	__u64 rhit;
	__u64 kcnts[0];
};

/* Flags */

#define TC_U32_TERMINAL		1
#define TC_U32_OFFSET		2
#define TC_U32_VAROFFSET	4
#define TC_U32_EAT		8

#define TC_U32_MAXDEPTH 8


/* RSVP filter */

enum {
	TCA_RSVP_UNSPEC,
	TCA_RSVP_CLASSID,
	TCA_RSVP_DST,
	TCA_RSVP_SRC,
	TCA_RSVP_PINFO,
	TCA_RSVP_POLICE,
	TCA_RSVP_ACT,
	__TCA_RSVP_MAX
};

#define TCA_RSVP_MAX (__TCA_RSVP_MAX - 1 )

struct tc_rsvp_gpi {
	__u32	key;
	__u32	mask;
	int	offset;
};

struct tc_rsvp_pinfo {
	struct tc_rsvp_gpi dpi;
	struct tc_rsvp_gpi spi;
	__u8	protocol;
	__u8	tunnelid;
	__u8	tunnelhdr;
	__u8	pad;
};

/* ROUTE filter */

enum {
	TCA_ROUTE4_UNSPEC,
	TCA_ROUTE4_CLASSID,
	TCA_ROUTE4_TO,
	TCA_ROUTE4_FROM,
	TCA_ROUTE4_IIF,
	TCA_ROUTE4_POLICE,
	TCA_ROUTE4_ACT,
	__TCA_ROUTE4_MAX
};

#define TCA_ROUTE4_MAX (__TCA_ROUTE4_MAX - 1)


/* FW filter */

enum {
	TCA_FW_UNSPEC,
	TCA_FW_CLASSID,
	TCA_FW_POLICE,
	TCA_FW_INDEV, /*  used by CONFIG_NET_CLS_IND */
	TCA_FW_ACT, /* used by CONFIG_NET_CLS_ACT */
	TCA_FW_MASK,
	__TCA_FW_MAX
};

#define TCA_FW_MAX (__TCA_FW_MAX - 1)

/* TC index filter */

enum {
	TCA_TCINDEX_UNSPEC,
	TCA_TCINDEX_HASH,
	TCA_TCINDEX_MASK,
	TCA_TCINDEX_SHIFT,
	TCA_TCINDEX_FALL_THROUGH,
	TCA_TCINDEX_CLASSID,
	TCA_TCINDEX_POLICE,
	TCA_TCINDEX_ACT,
	__TCA_TCINDEX_MAX
};

#define TCA_TCINDEX_MAX     (__TCA_TCINDEX_MAX - 1)

/* Flow filter */

enum {
	FLOW_KEY_SRC,
	FLOW_KEY_DST,
	FLOW_KEY_PROTO,
	FLOW_KEY_PROTO_SRC,
	FLOW_KEY_PROTO_DST,
	FLOW_KEY_IIF,
	FLOW_KEY_PRIORITY,
	FLOW_KEY_MARK,
	FLOW_KEY_NFCT,
	FLOW_KEY_NFCT_SRC,
	FLOW_KEY_NFCT_DST,
	FLOW_KEY_NFCT_PROTO_SRC,
	FLOW_KEY_NFCT_PROTO_DST,
	FLOW_KEY_RTCLASSID,
	FLOW_KEY_SKUID,
	FLOW_KEY_SKGID,
	FLOW_KEY_VLAN_TAG,
	FLOW_KEY_RXHASH,
	__FLOW_KEY_MAX,
};

#define FLOW_KEY_MAX	(__FLOW_KEY_MAX - 1)

enum {
	FLOW_MODE_MAP,
	FLOW_MODE_HASH,
};

enum {
	TCA_FLOW_UNSPEC,
	TCA_FLOW_KEYS,
	TCA_FLOW_MODE,
	TCA_FLOW_BASECLASS,
	TCA_FLOW_RSHIFT,
	TCA_FLOW_ADDEND,
	TCA_FLOW_MASK,
	TCA_FLOW_XOR,
	TCA_FLOW_DIVISOR,
	TCA_FLOW_ACT,
	TCA_FLOW_POLICE,
	TCA_FLOW_EMATCHES,
	TCA_FLOW_PERTURB,
	__TCA_FLOW_MAX
};

#define TCA_FLOW_MAX	(__TCA_FLOW_MAX - 1)

/* Basic filter */

enum {
	TCA_BASIC_UNSPEC,
	TCA_BASIC_CLASSID,
	TCA_BASIC_EMATCHES,
	TCA_BASIC_ACT,
	TCA_BASIC_POLICE,
	__TCA_BASIC_MAX
};

#define TCA_BASIC_MAX (__TCA_BASIC_MAX - 1)


/* Cgroup classifier */

enum {
	TCA_CGROUP_UNSPEC,
	TCA_CGROUP_ACT,
	TCA_CGROUP_POLICE,
	TCA_CGROUP_EMATCHES,
	__TCA_CGROUP_MAX,
};

#define TCA_CGROUP_MAX (__TCA_CGROUP_MAX - 1)

/* BPF classifier */

#define TCA_BPF_FLAG_ACT_DIRECT		(1 << 0)

enum {
	TCA_BPF_UNSPEC,
	TCA_BPF_ACT,
	TCA_BPF_POLICE,
	TCA_BPF_CLASSID,
	TCA_BPF_OPS_LEN,
	TCA_BPF_OPS,
	TCA_BPF_FD,
	TCA_BPF_NAME,
	TCA_BPF_FLAGS,
	__TCA_BPF_MAX,
};

#define TCA_BPF_MAX (__TCA_BPF_MAX - 1)

/* Flower classifier */

enum {
	TCA_FLOWER_UNSPEC,
	TCA_FLOWER_CLASSID,
	TCA_FLOWER_INDEV,
	TCA_FLOWER_ACT,
	TCA_FLOWER_KEY_ETH_DST,		/* ETH_ALEN */
	TCA_FLOWER_KEY_ETH_DST_MASK,	/* ETH_ALEN */
	TCA_FLOWER_KEY_ETH_SRC,		/* ETH_ALEN */
	TCA_FLOWER_KEY_ETH_SRC_MASK,	/* ETH_ALEN */
	TCA_FLOWER_KEY_ETH_TYPE,	/* be16 */
	TCA_FLOWER_KEY_IP_PROTO,	/* u8 */
	TCA_FLOWER_KEY_IPV4_SRC,	/* be32 */
	TCA_FLOWER_KEY_IPV4_SRC_MASK,	/* be32 */
	TCA_FLOWER_KEY_IPV4_DST,	/* be32 */
	TCA_FLOWER_KEY_IPV4_DST_MASK,	/* be32 */
	TCA_FLOWER_KEY_IPV6_SRC,	/* struct in6_addr */
	TCA_FLOWER_KEY_IPV6_SRC_MASK,	/* struct in6_addr */
	TCA_FLOWER_KEY_IPV6_DST,	/* struct in6_addr */
	TCA_FLOWER_KEY_IPV6_DST_MASK,	/* struct in6_addr */
	TCA_FLOWER_KEY_TCP_SRC,		/* be16 */
	TCA_FLOWER_KEY_TCP_DST,		/* be16 */
	TCA_FLOWER_KEY_UDP_SRC,		/* be16 */
	TCA_FLOWER_KEY_UDP_DST,		/* be16 */
	__TCA_FLOWER_MAX,
};

#define TCA_FLOWER_MAX (__TCA_FLOWER_MAX - 1)

/* Extended Matches */

struct tcf_ematch_tree_hdr {
	__u16		nmatches;
	__u16		progid;
};

enum {
	TCA_EMATCH_TREE_UNSPEC,
	TCA_EMATCH_TREE_HDR,
	TCA_EMATCH_TREE_LIST,
	__TCA_EMATCH_TREE_MAX
};
#define TCA_EMATCH_TREE_MAX (__TCA_EMATCH_TREE_MAX - 1)

struct tcf_ematch_hdr {
	__u16		matchid;
	__u16		kind;
	__u16		flags;
	__u16		pad; /* currently unused */
};

/*  0                   1
 *  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 
 * +-----------------------+-+-+---+
 * |         Unused        |S|I| R |
 * +-----------------------+-+-+---+
 *
 * R(2) ::= relation to next ematch
 *          where: 0 0 END (last ematch)
 *                 0 1 AND
 *                 1 0 OR
 *                 1 1 Unused (invalid)
 * I(1) ::= invert result
 * S(1) ::= simple payload
 */
#define TCF_EM_REL_END	0
#define TCF_EM_REL_AND	(1<<0)
#define TCF_EM_REL_OR	(1<<1)
#define TCF_EM_INVERT	(1<<2)
#define TCF_EM_SIMPLE	(1<<3)

#define TCF_EM_REL_MASK	3
#define TCF_EM_REL_VALID(v) (((v) & TCF_EM_REL_MASK) != TCF_EM_REL_MASK)

enum {
	TCF_LAYER_LINK,
	TCF_LAYER_NETWORK,
	TCF_LAYER_TRANSPORT,
	__TCF_LAYER_MAX
};
#define TCF_LAYER_MAX (__TCF_LAYER_MAX - 1)

/* Ematch type assignments
 *   1..32767		Reserved for ematches inside kernel tree
 *   32768..65535	Free to use, not reliable
 */
#define	TCF_EM_CONTAINER	0
#define	TCF_EM_CMP		1
#define	TCF_EM_NBYTE		2
#define	TCF_EM_U32		3
#define	TCF_EM_META		4
#define	TCF_EM_TEXT		5
#define	TCF_EM_VLAN		6
#define	TCF_EM_CANID		7
#define	TCF_EM_IPSET		8
#define	TCF_EM_MAX		8

enum {
	TCF_EM_PROG_TC
};

enum {
	TCF_EM_OPND_EQ,
	TCF_EM_OPND_GT,
	TCF_EM_OPND_LT
};

#endif

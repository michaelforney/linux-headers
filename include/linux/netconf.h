/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef _LINUX_NETCONF_H_
#define _LINUX_NETCONF_H_

#include <linux/types.h>
#include <linux/netlink.h>

struct netconfmsg {
	__u8	ncm_family;
};

enum {
	NETCONFA_UNSPEC,
	NETCONFA_IFINDEX,
	NETCONFA_FORWARDING,
	NETCONFA_RP_FILTER,
	NETCONFA_MC_FORWARDING,
	NETCONFA_PROXY_NEIGH,
	NETCONFA_IGNORE_ROUTES_WITH_LINKDOWN,
	NETCONFA_INPUT,
	__NETCONFA_MAX
};
#define NETCONFA_MAX	(__NETCONFA_MAX - 1)
#define NETCONFA_ALL	-1

#define NETCONFA_IFINDEX_ALL		-1
#define NETCONFA_IFINDEX_DEFAULT	-2

#endif /* _LINUX_NETCONF_H_ */

#ifndef _LINUX_QRTR_H
#define _LINUX_QRTR_H

#include <linux/socket.h>
#include <linux/types.h>

#define QRTR_NODE_BCAST	0xffffffffu
#define QRTR_PORT_CTRL	0xfffffffeu

struct sockaddr_qrtr {
	__kernel_sa_family_t sq_family;
	__u32 sq_node;
	__u32 sq_port;
};

#endif /* _LINUX_QRTR_H */

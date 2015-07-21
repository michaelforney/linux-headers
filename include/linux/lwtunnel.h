#ifndef _LWTUNNEL_H_
#define _LWTUNNEL_H_

#include <linux/types.h>

enum lwtunnel_encap_types {
	LWTUNNEL_ENCAP_NONE,
	LWTUNNEL_ENCAP_MPLS,
	__LWTUNNEL_ENCAP_MAX,
};

#define LWTUNNEL_ENCAP_MAX (__LWTUNNEL_ENCAP_MAX - 1)


#endif /* _LWTUNNEL_H_ */

/*
 * acceptorimpl.h
 *
 *  Created on: 2014-10-3
 *      Author: qianqians
 */
#ifdef _WINDOWS
#include <WinSock2.h>

#ifndef _reliable_acceptorimlp_h
#define _reliable_acceptorimlp_h

#include "../../windows/handle.h"
#include "../../typedef.h"

namespace Fossilizid{
namespace remoteq{

namespace reliable{

struct acceptorimlp : public handle{
	acceptorimlp(QUEUE que, ENDPOINT ep);

	char * outbuf;
	SOCKET sl, sa;
	QUEUE que;
};

} /* namespace reliable */

} /* namespace remoteq */
} /* namespace Fossilizid */

#endif //_reliable_acceptorimlp_h

#endif //_WINDOWS

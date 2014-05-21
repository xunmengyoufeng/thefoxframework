/*
 * @filename Acceptor.h
 * @brief tcp acceptor
 * @author macwe@qq.com
 */

#ifndef _THEFOX_NET_ACCEPTOR_H_
#define _THEFOX_NET_ACCEPTOR_H_

#include <base/types.h>
#include <net/callbacks.h>
#include <net/socket.h>
#include <net/event.h>

namespace thefox
{

class TcpServer;
#ifdef WIN32
class Thread;
#endif

class Acceptor
{
public:
    Acceptor(TcpServer *server, const InetAddress& listenAddr);
    ~Acceptor(void);

	bool listen();
	bool listening() const { return _listening; }

#ifndef WIN32
	void handleAccept(IoEvent *ev);
#endif

private:
	THEFOX_DISALLOW_EVIL_CONSTRUCTORS(Acceptor);

	TcpServer *_server;
	Socket _acceptSocket;
	bool _listening;

#ifdef WIN32
	void acceptLoop();
	Thread *_acceptThread;
	HANDLE _hAcceptEvent;
#else
	IoEvent _acceptEvent;
#endif
};

} // namespace thefox

#endif // _THEFOX_NET_ACCEPTOR_H_
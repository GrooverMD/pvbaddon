/* include/wsockcompat.h
 * Windows -> Berkeley Sockets compatibility things.
 */

#undef  __XML_WSOCKCOMPAT_H__
#define __XML_WSOCKCOMPAT_H__
#if !defined __XML_WSOCKCOMPAT_H__
#define __XML_WSOCKCOMPAT_H__

#ifdef _WIN32_WCE
#include <winsock.h>
#else
#undef HAVE_ERRNO_H
#include <winsock2.h>
#endif

#if !defined SOCKLEN_T
#define SOCKLEN_T int
#endif

#define EWOULDBLOCK             WSAEWOULDBLOCK
#define EINPROGRESS             WSAEINPROGRESS
#define EALREADY                WSAEALREADY
#define ENOTSOCK                WSAENOTSOCK
#define EDESTADDRREQ            WSAEDESTADDRREQ
#define EMSGSIZE                WSAEMSGSIZE
#define EPROTOTYPE              WSAEPROTOTYPE
#define ENOPROTOOPT             WSAENOPROTOOPT
#define EPROTONOSUPPORT         WSAEPROTONOSUPPORT
#define ESOCKTNOSUPPORT         WSAESOCKTNOSUPPORT
#define EOPNOTSUPP              WSAEOPNOTSUPP
#define EPFNOSUPPORT            WSAEPFNOSUPPORT
#define EAFNOSUPPORT            WSAEAFNOSUPPORT
#define EADDRINUSE              WSAEADDRINUSE
#define EADDRNOTAVAIL           WSAEADDRNOTAVAIL
#define ENETDOWN                WSAENETDOWN
#define ENETUNREACH             WSAENETUNREACH
#define ENETRESET               WSAENETRESET
#define ECONNABORTED            WSAECONNABORTED
#define ECONNRESET              WSAECONNRESET
#define ENOBUFS                 WSAENOBUFS
#define EISCONN                 WSAEISCONN
#define ENOTCONN                WSAENOTCONN
#define ESHUTDOWN               WSAESHUTDOWN
#define ETOOMANYREFS            WSAETOOMANYREFS
#define ETIMEDOUT               WSAETIMEDOUT
#define ECONNREFUSED            WSAECONNREFUSED
#define ELOOP                   WSAELOOP
#define EHOSTDOWN               WSAEHOSTDOWN
#define EHOSTUNREACH            WSAEHOSTUNREACH
#define EPROCLIM                WSAEPROCLIM
#define EUSERS                  WSAEUSERS
#define EDQUOT                  WSAEDQUOT
#define ESTALE                  WSAESTALE
#define EREMOTE                 WSAEREMOTE
/* These cause conflicts with the codes from errno.h. Since they are 
   not used in the relevant code (nanoftp, nanohttp), we can leave 
   them disabled.
#define ENAMETOOLONG            WSAENAMETOOLONG
#define ENOTEMPTY               WSAENOTEMPTY
*/

#endif /* __XML_WSOCKCOMPAT_H__ */

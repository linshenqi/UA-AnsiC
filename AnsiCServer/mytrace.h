#ifndef __MY_TRACE_H__
#define __MY_TRACE_H__


#define SERVER_TRACE
#ifdef SERVER_TRACE
#define MY_TRACE printf
#else
#define MY_TRACE(x,...) ((void)0)
#endif

#endif

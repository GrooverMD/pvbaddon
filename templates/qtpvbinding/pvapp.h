//***************************************************************************
//                          pvapp.h  -  description
//                             -------------------
//  begin            : Sa. Mrz 5 08:49:21 2011
//  generated by     : pvdevelop (C) Lehrig Software Engineering
//  email            : lehrig@t-online.de
//***************************************************************************
#ifndef _PVAPP_H_
#define _PVAPP_H_

#ifdef USE_INETD
static int trace=0; // todo: set trace=0 if you do not want printf() within event loop
#else
static int trace=1; // todo: set trace=0 if you do not want printf() within event loop
#endif

#include "processviewserver.h"
// todo: comment me out
//#include "rlmodbusclient.h"
//#include "rlsiemenstcpclient.h"
//#include "rlppiclient.h"
//#include "modbusdaemon.h"             // this is generated
//#include "siemensdaemon.h"            // this is generated
//#include "ppidaemon.h"                // this is generated

int show_mask1(PARAM *p);

#endif

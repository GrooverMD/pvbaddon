//***************************************************************************
//                          pvapp.h  -  description
//                             -------------------
//  begin            : Do. Mai 30 17:29:06 2013
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
#include "rlsvganimator.h"
#include "rlstate.h"

int show_mask1(PARAM *p);

#endif

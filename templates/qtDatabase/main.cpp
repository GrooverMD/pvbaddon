//***************************************************************************
//                          main.cpp  -  description
//                             -------------------
//  begin            : Fr. Mai 28 10:56:01 2010
//  generated by     : pvdevelop (C) Lehrig Software Engineering
//  email            : lehrig@t-online.de
//***************************************************************************
#include "pvapp.h"
#include <QCoreApplication>
// todo: comment me out. you can insert these objects as extern in your masks.
//rlModbusClient     modbus(modbusdaemon_MAILBOX,modbusdaemon_SHARED_MEMORY,modbusdaemon_SHARED_MEMORY_SIZE);
//rlSiemensTCPClient siemensTCP(siemensdaemon_MAILBOX,siemensdaemon_SHARED_MEMORY,siemensdaemon_SHARED_MEMORY_SIZE);
//rlPPIClient        ppi(ppidaemon_MAILBOX,ppidaemon_SHARED_MEMORY,ppidaemon_SHARED_MEMORY_SIZE);

// DATABASE code
// here we define the database
// in maskX_slots.h we define it as extern
qtDatabase db;
rlMutex    dbmutex;

int pvMain(PARAM *p)
{
int ret;

  pvSetCaption(p,"pvs");
  pvResize(p,0,1280,1024);
  //pvScreenHint(p,1024,768); // this may be used to automatically set the zoomfactor
  ret = 1;
  pvGetInitialMask(p);
  if(strcmp(p->initial_mask,"mask1") == 0) ret = 1;

  while(1)
  {
    if(trace) printf("show_mask%d\n", ret);
    switch(ret)
    {
      case 1:
        pvStatusMessage(p,-1,-1,-1,"mask1");
        ret = show_mask1(p);
        break;
      default:
        return 0;
    }
  }
}

#ifdef USE_INETD
int main(int ac, char **av)
{
PARAM p;

  pvInit(ac,av,&p);
  /* here you may interpret ac,av and set p->user to your data */
  
  // DATABASE code
  // here we open a mysql database
  // database information_schema is in every mysql database
  int ret = db.open("QMYSQL","localhost","information_schema","","");
  printf("db.open ret=%d\n", ret);
  
  pvMain(&p);
  return 0;
}
#else  // multi threaded server
int main(int ac, char **av)
{
PARAM p;
int   s;

  QCoreApplication app(ac,av);
  pvInit(ac,av,&p);
  /* here you may interpret ac,av and set p->user to your data */

  // DATABASE code
  // here we open a mysql database
  // database information_schema is in every mysql database
  int ret = db.open("QMYSQL","localhost","information_schema","","");
  printf("db.open ret=%d\n", ret);

  while(1)
  {
    s = pvAccept(&p);
    if(s != -1) pvCreateThread(&p,s);
    else        break;
  }
  return 0;
}
#endif

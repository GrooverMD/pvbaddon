////////////////////////////////////////////////////////////////////////////
//
// show_mask1 for ProcessViewServer created: Do Jan 17 17:06:13 2008
//
////////////////////////////////////////////////////////////////////////////
#include "pvapp.h"

// _begin_of_generated_area_ (do not edit -> use ui2pvc) -------------------

// our mask contains the following objects
enum {
  ID_MAIN_WIDGET = 0,
  obj1,
  markFlow,
  markBlower1,
  markBlower2,
  markUVunit,
  markPump,
  label1,
  label2,
  label3,
  label4,
  label5,
  ID_END_OF_WIDGETS
};

  static const char *toolTip[] = {
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  ""};

  static const char *whatsThis[] = {
  "",
  "BioCompactSchm.png",
  "grey.png",
  "green.png",
  "red.png",
  "grey.png",
  "grey.png",
  "",
  "",
  "",
  "",
  "",
  ""};

  static const int widgetType[ID_END_OF_WIDGETS+1] = {
  0,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLabel,
  -1 };

static int generated_defineMask(PARAM *p)
{
  int w,h,depth;

  if(p == NULL) return 1;
  w = h = depth = strcmp(toolTip[0],whatsThis[0]);
  if(widgetType[0] == -1) return 1;
  if(w==h) depth=0; // fool the compiler
  pvStartDefinition(p,ID_END_OF_WIDGETS);

  pvDownloadFile(p,"BioCompactSchm.png");
  pvQImage(p,obj1,0,"BioCompactSchm.png",&w,&h,&depth);
  pvSetGeometry(p,obj1,5,5,979,441);
  pvSetFont(p,obj1,"Sans Serif",10,0,0,0,0);
  pvSetWhatsThis(p,obj1,pvtr("BioCompactSchm.png"));

  pvDownloadFile(p,"grey.png");
  pvQImage(p,markFlow,obj1,"grey.png",&w,&h,&depth);
  pvSetGeometry(p,markFlow,31,189,35,35);
  pvSetFont(p,markFlow,"Sans Serif",10,0,0,0,0);
  pvSetWhatsThis(p,markFlow,pvtr("grey.png"));

  pvDownloadFile(p,"green.png");
  pvQImage(p,markBlower1,obj1,"green.png",&w,&h,&depth);
  pvSetGeometry(p,markBlower1,165,19,35,35);
  pvSetFont(p,markBlower1,"Sans Serif",10,0,0,0,0);
  pvSetWhatsThis(p,markBlower1,pvtr("green.png"));

  pvDownloadFile(p,"red.png");
  pvQImage(p,markBlower2,obj1,"red.png",&w,&h,&depth);
  pvSetGeometry(p,markBlower2,346,19,35,35);
  pvSetFont(p,markBlower2,"Sans Serif",10,0,0,0,0);
  pvSetWhatsThis(p,markBlower2,pvtr("red.png"));

  pvDownloadFile(p,"grey.png");
  pvQImage(p,markUVunit,obj1,"grey.png",&w,&h,&depth);
  pvSetGeometry(p,markUVunit,800,124,35,35);
  pvSetFont(p,markUVunit,"Sans Serif",10,0,0,0,0);
  pvSetWhatsThis(p,markUVunit,pvtr("grey.png"));

  pvDownloadFile(p,"grey.png");
  pvQImage(p,markPump,obj1,"grey.png",&w,&h,&depth);
  pvSetGeometry(p,markPump,840,329,35,35);
  pvSetFont(p,markPump,"Sans Serif",10,0,0,0,0);
  pvSetWhatsThis(p,markPump,pvtr("grey.png"));

  pvQLabel(p,label1,0);
  pvSetGeometry(p,label1,5,465,550,30);
  pvSetText(p,label1,pvtr("Label1"));
  pvSetFont(p,label1,"Sans Serif",10,0,0,0,0);

  pvQLabel(p,label2,0);
  pvSetGeometry(p,label2,5,495,550,30);
  pvSetText(p,label2,pvtr("Label2"));
  pvSetFont(p,label2,"Sans Serif",10,0,0,0,0);

  pvQLabel(p,label3,0);
  pvSetGeometry(p,label3,5,525,550,30);
  pvSetText(p,label3,pvtr("Label3"));
  pvSetFont(p,label3,"Sans Serif",10,0,0,0,0);

  pvQLabel(p,label4,0);
  pvSetGeometry(p,label4,5,555,550,30);
  pvSetText(p,label4,pvtr("Label4"));
  pvSetFont(p,label4,"Sans Serif",10,0,0,0,0);

  pvQLabel(p,label5,0);
  pvSetGeometry(p,label5,5,585,550,30);
  pvSetText(p,label5,pvtr("Label5"));
  pvSetFont(p,label5,"Sans Serif",10,0,0,0,0);


  pvEndDefinition(p);
  return 0;
}

// _end_of_generated_area_ (do not edit -> use ui2pvc) ---------------------

#include "mask1_slots.h"

static int defineMask(PARAM *p)
{
  if(p == NULL) return 1;
  generated_defineMask(p);
  // (todo: add your code here)
  return 0;
}


static int showData(PARAM *p, DATA *d)
{
  if(p == NULL) return 1;
  if(d == NULL) return 1;
  return 0;
}

static int readData(DATA *d) // from shared memory, database or something else
{
  if(d == NULL) return 1;
  // (todo: add your code here)
  return 0;
}


int show_mask1(PARAM *p)
{
  DATA d;
  char event[MAX_EVENT_LENGTH];
  char text[MAX_EVENT_LENGTH];
  char str1[MAX_EVENT_LENGTH];
  int  i,w,h,val,x,y,button,ret;
  float xval, yval;

  defineMask(p);
  //rlSetDebugPrintf(1);
  if((ret=slotInit(p,&d)) != 0) return ret;
  readData(&d); // from shared memory, database or something else
  showData(p,&d);
  while(1)
  {
    pvPollEvent(p,event);
    switch(pvParseEvent(event, &i, text))
    {
      case NULL_EVENT:
        readData(&d); // from shared memory, database or something else
        showData(p,&d);
        if((ret=slotNullEvent(p,&d)) != 0) return ret;
        break;
      case BUTTON_EVENT:
        printf("BUTTON_EVENT id=%d\n",i);
        if((ret=slotButtonEvent(p,i,&d)) != 0) return ret;
        break;
      case BUTTON_PRESSED_EVENT:
        printf("BUTTON_PRESSED_EVENT id=%d\n",i);
        if((ret=slotButtonPressedEvent(p,i,&d)) != 0) return ret;
        break;
      case BUTTON_RELEASED_EVENT:
        printf("BUTTON_RELEASED_EVENT id=%d\n",i);
        if((ret=slotButtonReleasedEvent(p,i,&d)) != 0) return ret;
        break;
      case TEXT_EVENT:
        printf("TEXT_EVENT id=%d %s\n",i,text);
        if((ret=slotTextEvent(p,i,&d,text)) != 0) return ret;
        break;
      case SLIDER_EVENT:
        sscanf(text,"(%d)",&val);
        printf("SLIDER_EVENT val=%d\n",val);
        if((ret=slotSliderEvent(p,i,&d,val)) != 0) return ret;
        break;
      case CHECKBOX_EVENT:
        printf("CHECKBOX_EVENT id=%d %s\n",i,text);
        if((ret=slotCheckboxEvent(p,i,&d,text)) != 0) return ret;
        break;
      case RADIOBUTTON_EVENT:
        printf("RADIOBUTTON_EVENT id=%d %s\n",i,text);
        if((ret=slotRadioButtonEvent(p,i,&d,text)) != 0) return ret;
        break;
      case GL_INITIALIZE_EVENT:
        printf("you have to call initializeGL()\n");
        if((ret=slotGlInitializeEvent(p,i,&d)) != 0) return ret;
        break;
      case GL_PAINT_EVENT:
        printf("you have to call paintGL()\n");
        if((ret=slotGlPaintEvent(p,i,&d)) != 0) return ret;
        break;
      case GL_RESIZE_EVENT:
        sscanf(text,"(%d,%d)",&w,&h);
        printf("you have to call resizeGL(w,h)\n");
        if((ret=slotGlResizeEvent(p,i,&d,w,h)) != 0) return ret;
        break;
      case GL_IDLE_EVENT:
        if((ret=slotGlIdleEvent(p,i,&d)) != 0) return ret;
        break;
      case TAB_EVENT:
        sscanf(text,"(%d)",&val);
        printf("TAB_EVENT(%d,page=%d)\n",i,val);
        if((ret=slotTabEvent(p,i,&d,val)) != 0) return ret;
        break;
      case TABLE_TEXT_EVENT:
        sscanf(text,"(%d,%d,",&x,&y);
        pvGetText(text,str1);
        printf("TABLE_TEXT_EVENT(%d,%d,\"%s\")\n",x,y,str1);
        if((ret=slotTableTextEvent(p,i,&d,x,y,str1)) != 0) return ret;
        break;
      case TABLE_CLICKED_EVENT:
        sscanf(text,"(%d,%d,%d)",&x,&y,&button);
        printf("TABLE_CLICKED_EVENT(%d,%d,button=%d)\n",x,y,button);
        if((ret=slotTableClickedEvent(p,i,&d,x,y,button)) != 0) return ret;
        break;
      case SELECTION_EVENT:
        sscanf(text,"(%d,",&val);
        pvGetText(text,str1);
        printf("SELECTION_EVENT(column=%d,\"%s\")\n",val,str1);
        if((ret=slotSelectionEvent(p,i,&d,val,str1)) != 0) return ret;
        break;
      case CLIPBOARD_EVENT:
        sscanf(text,"(%d",&val);
        printf("CLIPBOARD_EVENT(id=%d)\n",val);
        printf("clipboard = \n%s\n",p->clipboard);
        if((ret=slotClipboardEvent(p,i,&d,val)) != 0) return ret;
        break;
      case RIGHT_MOUSE_EVENT:
        printf("RIGHT_MOUSE_EVENT id=%d text=%s\n",i,text);
        if((ret=slotRightMouseEvent(p,i,&d,text)) != 0) return ret;
        break;
      case KEYBOARD_EVENT:
        sscanf(text,"(%d",&val);
        printf("KEYBOARD_EVENT modifier=%d key=%d\n",i,val);
        if((ret=slotKeyboardEvent(p,i,&d,val,i)) != 0) return ret;
        break;
      case PLOT_MOUSE_MOVED_EVENT:
        sscanf(text,"(%f,%f)",&xval,&yval);
        printf("PLOT_MOUSE_MOVE %f %f\n",xval,yval);
        if((ret=slotMouseMovedEvent(p,i,&d,xval,yval)) != 0) return ret;
        break;
      case PLOT_MOUSE_PRESSED_EVENT:
        sscanf(text,"(%f,%f)",&xval,&yval);
        printf("PLOT_MOUSE_PRESSED %f %f\n",xval,yval);
        if((ret=slotMousePressedEvent(p,i,&d,xval,yval)) != 0) return ret;
        break;
      case PLOT_MOUSE_RELEASED_EVENT:
        sscanf(text,"(%f,%f)",&xval,&yval);
        printf("PLOT_MOUSE_RELEASED %f %f\n",xval,yval);
        if((ret=slotMouseReleasedEvent(p,i,&d,xval,yval)) != 0) return ret;
        break;
      case MOUSE_OVER_EVENT:
        sscanf(text,"%d",&val);
        printf("MOUSE_OVER_EVENT %d\n",val);
        if((ret=slotMouseOverEvent(p,i,&d,val)) != 0) return ret;
        break;
      case USER_EVENT:
        printf("USER_EVENT id=%d %s\n",i,text);
        if((ret=slotUserEvent(p,i,&d,text)) != 0) return ret;
        break;
      default:
        printf("UNKNOWN_EVENT id=%d %s\n",i,text);
        break;
    }
  }
}

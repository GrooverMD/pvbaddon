/** Generated by xsd2c*/
#ifndef __CallList_H__
#define __CallList_H__


#include "CallFunc.h"

#ifndef _DESERIALIZER_DISABLE_
	#include <libxml/parser.h>
#endif


#define TO_CALLLIST(derived) (derived->__base) 


#ifdef __cplusplus
extern "C" {
#endif 


/**
 *	OBJECT: CallList
 */
struct CallList
{
	struct CallFunc_List* operation_head;
	struct CallFunc_List* operation_tail;
};

/**
 *	LIST: CallList_List
 */
struct CallList_List
{
	struct CallList* value;
	struct CallList_List* next;
};


struct CallList* CallList_Create();
void CallList_Free(struct CallList* obj);
void CallList_Sax_Serialize(struct CallList* obj,
		 const char *root_element_name,
		 void (*OnStartElement)(const char* element_name, int attr_count, char **keys, char **values, void* userData),
		 void (*OnCharacters)(const char* element_name, const char* chars, void* userData),
		 void (*OnEndElement)(const char* element_name, void* userData),
		 void* userData);

#ifndef _DESERIALIZER_DISABLE_
struct CallList* CallList_Deserialize(xmlNodePtr xmlRoot);
#endif

void CallList_Add_operation(struct CallList* obj, struct CallFunc* operation);
struct CallFunc_List* CallList_Get_operation(struct CallList* obj);


#ifdef __cplusplus
};
#endif /*__cplusplus*/



#endif

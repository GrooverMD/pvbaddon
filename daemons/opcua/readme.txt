OPC UA daemon for use with pvbrowser
####################################################################################################

This daemon has become possible by the use of:
http://open62541.org

This OSS project provides a C library for implementing OPC UA client and server software.

Attention: This is an early release of our daemon and not all features might be included.
But it is already usable for browse/read/write basic datatypes.
The question is "what about recursive data?".
Currently "browse" does not recurse, it lists the variables visible on top of the tree.

Thus this version must be extended in the future.

####################################################################################################
HOWTO evaluate this daemon (under linux)

### In terminal 1 start the server: ###
cd pvbaddon/daemons/opcua/server
./pvs

### In terminal 2 you may now "Browse" the server: ###
cd pvbaddon/daemons/opcua/client
./opcua_client opc.tcp://localhost:16664 Browse -longname
####################################################
#./opcua_client opc.tcp://localhost:16664 Browse
#
# Itemlist := NAMESPACE#NODEID#BROWSE NAME#DISPLAY NAME
# Lines starting with # are treated as comment lines
####################################################
0#61#FolderType#FolderType
0#2253#Server#Server
1#95#current time#current time
1#96#cpu temperature#cpu temperature
1#97#status LED#status LED
1#the.answer#the answer#the answer
1#50000#Demo#Demo

./opcua_client opc.tcp://localhost:16664 Browse -longname > opvua.itemlist

### In terminal 2 you may now "Run" the daemon (which will write to the pvbrowser shared memory) ###
cd pvbaddon/daemons/opcua/client
./opcua_client opc.tcp://localhost:16664 Run

### In terminal 3 you may now run an example pvserver ###
cd pvbaddon/daemons/opcua/pvs
./pvs

### You may now run the pvbrowser client ###
pvbrowser pv://localhost

####################################################################################################

Datatype identifier:

Boolean:
SByte:
Byte:
Int16:
UInt16:
Int32:
UInt32:
Int64:
UInt64:
Float:
Double:
String:
Guid:
NodeId:
ExpandedNodeId:
QualifiedName:
LocalizedText:
ExtensionObject:
DataValue:
Variant:
DiagnosticInfo:

Example howto send an Int32 value:
opc.writeStringValue("1#the.answer", "Int32:123");

Parameter 1 is the variable name (see opcua.itemlist which was generated by browse).
Parameter 2 is the Int32 value.


 #ifndef _my_addressspace
#define _my_addressspace

#define ARRAYSIZE_OF_VALUEATTRIBUTE					12

typedef struct{
	OpcUa_NodeId			ReferenceTypeId;
	OpcUa_Boolean			IsInverse;
	OpcUa_NodeId			Target_NodeId;							/*OpcUa_ExpandedNodeId	TargetId;*/
    OpcUa_StringA			Target_NamespaceUri;					/*OpcUa_ExpandedNodeId	TargetId;*/								
}_ReferenceNode_;


typedef struct{
	OpcUa_NodeId	    NodeId;
	OpcUa_NodeClass     NodeClass;									
	OpcUa_StringA		BrowseName;									/*OpcUa_QualifiedName  BrowseName;*/
	OpcUa_StringA		DisplayName;								/*OpcUa_LocalizedText  DisplayName;*/
	OpcUa_Int32         NoOfReferences;								
  /*OpcUa_UInt32        WriteMask;*/
  /*OpcUa_UInt32        UserWriteMask;*/
	_ReferenceNode_* References;									/* OpcUa_ReferenceNode* References;*/
}_BaseAttribute_;


typedef struct{
	_BaseAttribute_		 BaseAttribute;
	OpcUa_Boolean        IsAbstract;
}_ObjectTypeKnoten_;

typedef struct{
	_BaseAttribute_		 BaseAttribute;
	OpcUa_Byte           EventNotifier;
}_ObjectKnoten_;

typedef struct{
	_BaseAttribute_		BaseAttribute;
	OpcUa_Boolean       IsAbstract;
    OpcUa_Boolean       Symmetric;
    OpcUa_StringA		InverseName_text;							 /*OpcUa_LocalizedText  InverseName;*/
	OpcUa_StringA		InverseName_locale;							 /*OpcUa_LocalizedText  InverseName;*/
}_ReferenceTypeKnoten_;


typedef struct{
	_BaseAttribute_		 BaseAttribute;
	OpcUa_Boolean        IsAbstract;
}_DataTypeKnoten_;


typedef union 
{
    OpcUa_UInt32*            UInt32Array;
    OpcUa_Double*            DoubleArray;
    OpcUa_StringA*           StringArray;
	OpcUa_Boolean*           BooleanArray;
}
my_VariantArrayUnion;

typedef struct
{
    /* The total number of elements in all dimensions. */
    OpcUa_Int32  Length;

    /* The data stored in the array. */
    my_VariantArrayUnion Value;
}
my_VariantArrayValue;

/* A union that contains one of the built-in types,which are used in nano server addressspace. */
typedef union 
{
    OpcUa_UInt32             UInt32;
    OpcUa_Double             Double;
    OpcUa_StringA            String;
	OpcUa_Boolean            Boolean;
	OpcUa_DateTime			 DateTime;
    my_VariantArrayValue	 Array;
}
my_VariantUnion;


typedef struct 
{
    /* Indicates the datatype stored in the Variant. This is always one of the OpcUa_BuiltInType values. */
    /* This is the datatype of a single element if the Variant contains an array. */
    OpcUa_Byte          Datatype;

    /* A flag indicating that an array with one or more dimensions is stored in the Variant. */
    OpcUa_Byte          ArrayType;

    /* The value stored in the Variant. */
    my_VariantUnion		Value;
}
my_Variant;

typedef struct{
	_BaseAttribute_		 BaseAttribute;
	OpcUa_Int			 ValueIndex;
    OpcUa_NodeId		 DataType;									
    OpcUa_Int32          ValueRank;
    OpcUa_Int32          NoOfArrayDimensions;
    OpcUa_UInt32         ArrayDimensions;
    OpcUa_Boolean        IsAbstract;
}_VariableTypeKnoten_;

typedef struct{
	_BaseAttribute_		 BaseAttribute;
	OpcUa_Int			 ValueIndex;
    OpcUa_NodeId		 DataType;									
    OpcUa_Int32          ValueRank;
    OpcUa_Int32          NoOfArrayDimensions;
    OpcUa_UInt32         ArrayDimensions;
    OpcUa_Byte           AccessLevel;
    OpcUa_Byte           UserAccessLevel;
   // OpcUa_Double         MinimumSamplingInterval;
    OpcUa_Boolean        Historizing;
}_VariableKnoten_;




#endif/*_my_addressspace*/
#ifndef _SVM_H
#define _SVM_H

#include <stdint.h>

typedef struct CS_TypeSpecifier_tag CS_TypeSpecifier;

typedef enum {
    CS_FALSE = 0,
    CS_TRUE = 1    
} CS_Boolean;

typedef enum {
    CS_BOOLEAN_TYPE,
    CS_INT_TYPE,
    CS_DOUBLE_TYPE,    
} CS_BasicType;


typedef struct {
    char          *name;
    CS_TypeSpecifier *type;
} CS_Variable;

typedef enum {
    CS_CONSTANT_INT,
    CS_CONSTANT_DOUBLE
} CS_ConstantType;

typedef struct {
    CS_ConstantType type;
    union {
      int    c_int;
      double c_double;
    }u;    
} CS_ConstantPool;


struct CS_TypeSpecifier_tag {
    CS_BasicType       basic_type;
};

typedef struct {
    uint32_t         constant_pool_count;
    CS_ConstantPool *constant_pool;
    uint32_t         global_variable_count;
    CS_Variable     *global_variable;
    uint32_t        code_size;
    uint8_t         *code;
} CS_Executable;


typedef enum {
    SVM_PUSH_INT = 1,
    SVM_PUSH_DOUBLE,
    SVM_PUSH_STACK_INT,
    SVM_PUSH_STACK_DOUBLE,
    SVM_POP_STACK_INT,
    SVM_POP_STACK_DOUBLE,
    SVM_PUSH_STATIC_INT,
    SVM_PUSH_STATIC_DOUBLE,
    SVM_POP_STATIC_INT,
    SVM_POP_STATIC_DOUBLE,
    SVM_ADD_INT,
    SVM_ADD_DOUBLE,
    SVM_SUB_INT,
    SVM_SUB_DOUBLE,
    SVM_MUL_INT,
    SVM_MUL_DOUBLE,
    SVM_DIV_INT,
    SVM_DIV_DOUBLE,
    SVM_MOD_INT,
    SVM_MOD_DOUBLE,
    SVM_MINUS_INT,
    SVM_MINUS_DOUBLE,
    SVM_INCREMENT,
    SVM_DECREMENT,
    SVM_CAST_INT_TO_DOUBLE,
    SVM_CAST_DOUBLE_TO_INT,
    SVM_EQ_INT,
    SVM_EQ_DOUBLE,
    SVM_NE_INT,
    SVM_NE_DOUBLE,
    SVM_GT_INT,
    SVM_GT_DOUBLE,
    SVM_GE_INT,
    SVM_GE_DOUBLE,
    SVM_LT_INT,
    SVM_LT_DOUBLE,
    SVM_LE_INT,
    SVM_LE_DOUBLE,
    SVM_LOGICAL_AND,
    SVM_LOGICAL_OR,
    SVM_LOGICAL_NOT,
    SVM_POP,
    SVM_PUSH_FUNCTION,
    SVM_INVOKE,
    SVM_RETURN
} SVM_Opcode;

typedef struct {
    char    *opname;
    char    *parameter;    
    uint8_t s_size;
} OpcodeInfo;

extern OpcodeInfo svm_opcode_info[];

/* disasm.c */
void show_variables(CS_Variable* variables, int size);
void disasm(uint8_t* code, uint32_t len);
#endif
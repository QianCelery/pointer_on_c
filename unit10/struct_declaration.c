/*
 * @Author: Celery
 * @Date: 2021-10-21 10:13:13
 * @LastEditTime: 2021-10-21 15:15:07
 * @LastEditors: Celery
 * @Description: 对一些信息类型进行结构声明
 * @FilePath: \unit10\struct_declaration.c
 * 
 */
#include "stdio.h"
#include "string.h"

enum PN_TYPE {CALLED, CALLING, BILLED};

typedef struct 
{
    short area;
    short exchange;
    short station;
} PHONE_NUMBER;

typedef struct
{
    short year;
    short month;
    short day;
    int time;
    PHONE_NUMBER number[3];
} LONG_DISTANCE_BILL;

typedef struct
{
    float suggested_price;
    float actual_selling_price;
    float sales_tax;
    float licensing_fee;
}CRASH_SALE;

typedef struct
{
    float suggested_price;
    float actual_selling_price;
    float down_payment; 
    float security_deposit;
    float monthly_payment;
    int lease_term;
}LOAN_SALE;

typedef struct
{
    float suggested_price;
    float actual_selling_price;
    float sales_tax;
    float licensing_fee;
    float down_payment;
    int loan_duration;
    float monthly_payment;
    char bank_name[20];

}RENT;

typedef struct
{
    char customer_name[20];
    char customer_addr[40];
    char model[20];
    enum {crash, loan, rent} type;
    union 
    {
        CRASH_SALE *info_crash;
        LOAN_SALE *info_loan;
        RENT *info_rent;
    } info;
}SALES_STATUS;



typedef union 
{
    unsigned short addr;
    struct
    {
        unsigned short dst_reg : 3;
        unsigned short dst_mode : 3;
        unsigned short opcode : 10;
    }sgl_op;

    struct 
    {
        unsigned short dst_reg : 3;
        unsigned short dst_mode : 3;
        unsigned short src_reg : 3;
        unsigned short src_mode : 3;
        unsigned short opcode : 4;
    }dbl_op;

    struct
    {
        unsigned short offset : 8;
        unsigned short opcode : 8;
    }brach;

    struct
    {
        unsigned short dst_reg : 3;
        unsigned short dst_mode : 3;
        unsigned short src_reg : 3;
        unsigned short opcode : 7;
    }reg_src;

    struct 
    {
        unsigned short opcode;
    }misc;

}machine_inst;

int main(void)
{
    PHONE_NUMBER num1 = {123, 123, 123};
    PHONE_NUMBER num2 = {123, 123, 123};
    PHONE_NUMBER num3 = {123, 123, 123};

    CRASH_SALE info1 = {1, 1, 1, 1};
    LOAN_SALE  info2 = {1, 1, 1, 1, 1, 1};
    RENT info3 = {1, 1, 1, 1, 1, 1, 1, "celery bank"};
    SALES_STATUS status = {"celery", "baiyang", "test", rent, (CRASH_SALE * )&info3};

    machine_inst x = {0x1234};











    return 0;
}



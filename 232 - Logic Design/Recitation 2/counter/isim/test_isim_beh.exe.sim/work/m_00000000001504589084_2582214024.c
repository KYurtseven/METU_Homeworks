/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xcb73ee62 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "D:/Google Downloads/Recitation 2/counter/counter.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static int ng3[] = {1, 0};



static void Always_34_0(char *t0)
{
    char t8[8];
    char t30[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t31;

LAB0:    t1 = (t0 + 1692U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(34, ng0);
    t2 = (t0 + 1888);
    *((int *)t2) = 1;
    t3 = (t0 + 1720);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(35, ng0);

LAB5:    t4 = (t0 + 148);
    xsi_vlog_namedbase_setdisablestate(t4, &&LAB6);
    t5 = (t0 + 1592);
    xsi_vlog_namedbase_pushprocess(t4, t5);

LAB7:    xsi_set_current_line(38, ng0);
    t6 = ((char*)((ng1)));
    t7 = (t0 + 1168);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 4, 0LL);
    xsi_set_current_line(39, ng0);
    t2 = (t0 + 848U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t8, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB11;

LAB8:    if (t18 != 0)
        goto LAB10;

LAB9:    *((unsigned int *)t8) = 1;

LAB11:    t7 = (t8 + 4);
    t21 = *((unsigned int *)t7);
    t22 = (~(t21));
    t23 = *((unsigned int *)t8);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB12;

LAB13:    xsi_set_current_line(43, ng0);
    t2 = (t0 + 940U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t8, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB19;

LAB16:    if (t18 != 0)
        goto LAB18;

LAB17:    *((unsigned int *)t8) = 1;

LAB19:    t7 = (t8 + 4);
    t21 = *((unsigned int *)t7);
    t22 = (~(t21));
    t23 = *((unsigned int *)t8);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB20;

LAB21:
LAB22:
LAB14:    t2 = (t0 + 148);
    xsi_vlog_namedbase_popprocess(t2);

LAB6:    t3 = (t0 + 1592);
    xsi_vlog_dispose_process_subprogram_invocation(t3);
    goto LAB2;

LAB10:    t6 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t6) = 1;
    goto LAB11;

LAB12:    xsi_set_current_line(39, ng0);

LAB15:    xsi_set_current_line(40, ng0);
    t26 = ((char*)((ng1)));
    t27 = (t0 + 1168);
    xsi_vlogvar_wait_assign_value(t27, t26, 0, 0, 4, 1000LL);
    goto LAB14;

LAB18:    t6 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t6) = 1;
    goto LAB19;

LAB20:    xsi_set_current_line(43, ng0);

LAB23:    xsi_set_current_line(44, ng0);
    t26 = (t0 + 1168);
    t27 = (t26 + 36U);
    t28 = *((char **)t27);
    t29 = ((char*)((ng3)));
    memset(t30, 0, 8);
    xsi_vlog_unsigned_add(t30, 32, t28, 4, t29, 32);
    t31 = (t0 + 1168);
    xsi_vlogvar_wait_assign_value(t31, t30, 0, 0, 4, 1000LL);
    goto LAB22;

}


extern void work_m_00000000001504589084_2582214024_init()
{
	static char *pe[] = {(void *)Always_34_0};
	xsi_register_didat("work_m_00000000001504589084_2582214024", "isim/test_isim_beh.exe.sim/work/m_00000000001504589084_2582214024.didat");
	xsi_register_executes(pe);
}

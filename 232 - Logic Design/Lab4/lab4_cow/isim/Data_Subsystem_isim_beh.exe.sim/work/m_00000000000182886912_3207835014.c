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
static const char *ng0 = "D:/Google Downloads/lab4_cow/lab4_cow/Reg_File.v";
static int ng1[] = {0, 0};
static int ng2[] = {32, 0};
static int ng3[] = {1, 0};



static void Always_19_0(char *t0)
{
    char t13[8];
    char t15[8];
    char t16[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    char *t14;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    unsigned int t27;
    int t28;
    char *t29;
    unsigned int t30;
    int t31;
    int t32;
    unsigned int t33;
    unsigned int t34;
    int t35;
    int t36;

LAB0:    t1 = (t0 + 2260U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(19, ng0);
    t2 = (t0 + 2456);
    *((int *)t2) = 1;
    t3 = (t0 + 2288);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(20, ng0);

LAB5:    xsi_set_current_line(21, ng0);
    t4 = (t0 + 1140U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(27, ng0);

LAB15:    xsi_set_current_line(28, ng0);
    t2 = (t0 + 1644);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = (t0 + 1644);
    t11 = (t5 + 44U);
    t12 = *((char **)t11);
    t14 = (t0 + 1644);
    t17 = (t14 + 40U);
    t18 = *((char **)t17);
    t19 = (t0 + 680U);
    t20 = *((char **)t19);
    xsi_vlog_generic_get_array_select_value(t13, 32, t4, t12, t18, 2, 1, t20, 5, 2);
    t19 = (t0 + 1460);
    xsi_vlogvar_wait_assign_value(t19, t13, 0, 0, 32, 4000LL);
    xsi_set_current_line(29, ng0);
    t2 = (t0 + 1644);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = (t0 + 1644);
    t11 = (t5 + 44U);
    t12 = *((char **)t11);
    t14 = (t0 + 1644);
    t17 = (t14 + 40U);
    t18 = *((char **)t17);
    t19 = (t0 + 772U);
    t20 = *((char **)t19);
    xsi_vlog_generic_get_array_select_value(t13, 32, t4, t12, t18, 2, 1, t20, 5, 2);
    t19 = (t0 + 1552);
    xsi_vlogvar_wait_assign_value(t19, t13, 0, 0, 32, 4000LL);
    xsi_set_current_line(30, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB16;

LAB17:
LAB18:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(22, ng0);

LAB9:    xsi_set_current_line(23, ng0);
    xsi_set_current_line(23, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 1736);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 32);

LAB10:    t2 = (t0 + 1736);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t13, 0, 8);
    xsi_vlog_signed_less(t13, 32, t4, 32, t5, 32);
    t11 = (t13 + 4);
    t6 = *((unsigned int *)t11);
    t7 = (~(t6));
    t8 = *((unsigned int *)t13);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB11;

LAB12:    goto LAB8;

LAB11:    xsi_set_current_line(24, ng0);
    t12 = ((char*)((ng1)));
    t14 = (t0 + 1644);
    t17 = (t0 + 1644);
    t18 = (t17 + 44U);
    t19 = *((char **)t18);
    t20 = (t0 + 1644);
    t21 = (t20 + 40U);
    t22 = *((char **)t21);
    t23 = (t0 + 1736);
    t24 = (t23 + 36U);
    t25 = *((char **)t24);
    xsi_vlog_generic_convert_array_indices(t15, t16, t19, t22, 2, 1, t25, 32, 1);
    t26 = (t15 + 4);
    t27 = *((unsigned int *)t26);
    t28 = (!(t27));
    t29 = (t16 + 4);
    t30 = *((unsigned int *)t29);
    t31 = (!(t30));
    t32 = (t28 && t31);
    if (t32 == 1)
        goto LAB13;

LAB14:    xsi_set_current_line(23, ng0);
    t2 = (t0 + 1736);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t13, 0, 8);
    xsi_vlog_signed_add(t13, 32, t4, 32, t5, 32);
    t11 = (t0 + 1736);
    xsi_vlogvar_assign_value(t11, t13, 0, 0, 32);
    goto LAB10;

LAB13:    t33 = *((unsigned int *)t15);
    t34 = *((unsigned int *)t16);
    t35 = (t33 - t34);
    t36 = (t35 + 1);
    xsi_vlogvar_wait_assign_value(t14, t12, 0, *((unsigned int *)t16), t36, 0LL);
    goto LAB14;

LAB16:    xsi_set_current_line(31, ng0);

LAB19:    xsi_set_current_line(32, ng0);
    t4 = (t0 + 956U);
    t5 = *((char **)t4);
    t4 = (t0 + 1644);
    t11 = (t0 + 1644);
    t12 = (t11 + 44U);
    t14 = *((char **)t12);
    t17 = (t0 + 1644);
    t18 = (t17 + 40U);
    t19 = *((char **)t18);
    t20 = (t0 + 864U);
    t21 = *((char **)t20);
    xsi_vlog_generic_convert_array_indices(t13, t15, t14, t19, 2, 1, t21, 5, 2);
    t20 = (t13 + 4);
    t27 = *((unsigned int *)t20);
    t28 = (!(t27));
    t22 = (t15 + 4);
    t30 = *((unsigned int *)t22);
    t31 = (!(t30));
    t32 = (t28 && t31);
    if (t32 == 1)
        goto LAB20;

LAB21:    goto LAB18;

LAB20:    t33 = *((unsigned int *)t13);
    t34 = *((unsigned int *)t15);
    t35 = (t33 - t34);
    t36 = (t35 + 1);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, *((unsigned int *)t15), t36, 4000LL);
    goto LAB21;

}


extern void work_m_00000000000182886912_3207835014_init()
{
	static char *pe[] = {(void *)Always_19_0};
	xsi_register_didat("work_m_00000000000182886912_3207835014", "isim/Data_Subsystem_isim_beh.exe.sim/work/m_00000000000182886912_3207835014.didat");
	xsi_register_executes(pe);
}

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
static const char *ng0 = "D:/Google Downloads/lab4_cow/lab4_cow/Extender.v";
static int ng1[] = {15, 0};
static int ng2[] = {1, 0};
static int ng3[] = {31, 0};
static int ng4[] = {16, 0};
static int ng5[] = {0, 0};



static void Always_13_0(char *t0)
{
    char t13[8];
    char t18[8];
    char t42[8];
    char t43[8];
    char t44[8];
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
    char *t15;
    char *t16;
    char *t17;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    char *t49;
    char *t50;
    unsigned int t51;
    int t52;
    char *t53;
    unsigned int t54;
    int t55;
    int t56;
    char *t57;
    unsigned int t58;
    int t59;
    int t60;
    unsigned int t61;
    int t62;
    unsigned int t63;
    unsigned int t64;
    int t65;
    int t66;

LAB0:    t1 = (t0 + 1524U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(13, ng0);
    t2 = (t0 + 1720);
    *((int *)t2) = 1;
    t3 = (t0 + 1552);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(14, ng0);

LAB5:    xsi_set_current_line(15, ng0);
    t4 = (t0 + 772U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(29, ng0);

LAB27:    xsi_set_current_line(30, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 1000);
    t4 = (t0 + 1000);
    t5 = (t4 + 44U);
    t11 = *((char **)t5);
    t12 = ((char*)((ng3)));
    t14 = ((char*)((ng4)));
    xsi_vlog_convert_partindices(t13, t18, t42, ((int*)(t11)), 2, t12, 32, 1, t14, 32, 1);
    t15 = (t13 + 4);
    t6 = *((unsigned int *)t15);
    t52 = (!(t6));
    t16 = (t18 + 4);
    t7 = *((unsigned int *)t16);
    t55 = (!(t7));
    t56 = (t52 && t55);
    t17 = (t42 + 4);
    t8 = *((unsigned int *)t17);
    t59 = (!(t8));
    t60 = (t56 && t59);
    if (t60 == 1)
        goto LAB28;

LAB29:    xsi_set_current_line(31, ng0);
    t2 = (t0 + 680U);
    t3 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t13 + 4);
    t4 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 0);
    *((unsigned int *)t13) = t7;
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 0);
    *((unsigned int *)t2) = t9;
    t10 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t10 & 65535U);
    t21 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t21 & 65535U);
    t5 = (t0 + 1000);
    t11 = (t0 + 1000);
    t12 = (t11 + 44U);
    t14 = *((char **)t12);
    t15 = ((char*)((ng1)));
    t16 = ((char*)((ng5)));
    xsi_vlog_convert_partindices(t18, t42, t43, ((int*)(t14)), 2, t15, 32, 1, t16, 32, 1);
    t17 = (t18 + 4);
    t22 = *((unsigned int *)t17);
    t52 = (!(t22));
    t19 = (t42 + 4);
    t23 = *((unsigned int *)t19);
    t55 = (!(t23));
    t56 = (t52 && t55);
    t20 = (t43 + 4);
    t24 = *((unsigned int *)t20);
    t59 = (!(t24));
    t60 = (t56 && t59);
    if (t60 == 1)
        goto LAB30;

LAB31:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(16, ng0);

LAB9:    xsi_set_current_line(17, ng0);
    t11 = (t0 + 680U);
    t12 = *((char **)t11);
    t11 = (t0 + 656U);
    t14 = (t11 + 44U);
    t15 = *((char **)t14);
    t16 = ((char*)((ng1)));
    xsi_vlog_generic_get_index_select_value(t13, 32, t12, t15, 2, t16, 32, 1);
    t17 = ((char*)((ng2)));
    memset(t18, 0, 8);
    t19 = (t13 + 4);
    t20 = (t17 + 4);
    t21 = *((unsigned int *)t13);
    t22 = *((unsigned int *)t17);
    t23 = (t21 ^ t22);
    t24 = *((unsigned int *)t19);
    t25 = *((unsigned int *)t20);
    t26 = (t24 ^ t25);
    t27 = (t23 | t26);
    t28 = *((unsigned int *)t19);
    t29 = *((unsigned int *)t20);
    t30 = (t28 | t29);
    t31 = (~(t30));
    t32 = (t27 & t31);
    if (t32 != 0)
        goto LAB13;

LAB10:    if (t30 != 0)
        goto LAB12;

LAB11:    *((unsigned int *)t18) = 1;

LAB13:    t34 = (t18 + 4);
    t35 = *((unsigned int *)t34);
    t36 = (~(t35));
    t37 = *((unsigned int *)t18);
    t38 = (t37 & t36);
    t39 = (t38 != 0);
    if (t39 > 0)
        goto LAB14;

LAB15:    xsi_set_current_line(23, ng0);

LAB22:    xsi_set_current_line(24, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 1000);
    t4 = (t0 + 1000);
    t5 = (t4 + 44U);
    t11 = *((char **)t5);
    t12 = ((char*)((ng3)));
    t14 = ((char*)((ng4)));
    xsi_vlog_convert_partindices(t13, t18, t42, ((int*)(t11)), 2, t12, 32, 1, t14, 32, 1);
    t15 = (t13 + 4);
    t6 = *((unsigned int *)t15);
    t52 = (!(t6));
    t16 = (t18 + 4);
    t7 = *((unsigned int *)t16);
    t55 = (!(t7));
    t56 = (t52 && t55);
    t17 = (t42 + 4);
    t8 = *((unsigned int *)t17);
    t59 = (!(t8));
    t60 = (t56 && t59);
    if (t60 == 1)
        goto LAB23;

LAB24:    xsi_set_current_line(25, ng0);
    t2 = (t0 + 680U);
    t3 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t13 + 4);
    t4 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 0);
    *((unsigned int *)t13) = t7;
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 0);
    *((unsigned int *)t2) = t9;
    t10 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t10 & 65535U);
    t21 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t21 & 65535U);
    t5 = (t0 + 1000);
    t11 = (t0 + 1000);
    t12 = (t11 + 44U);
    t14 = *((char **)t12);
    t15 = ((char*)((ng1)));
    t16 = ((char*)((ng5)));
    xsi_vlog_convert_partindices(t18, t42, t43, ((int*)(t14)), 2, t15, 32, 1, t16, 32, 1);
    t17 = (t18 + 4);
    t22 = *((unsigned int *)t17);
    t52 = (!(t22));
    t19 = (t42 + 4);
    t23 = *((unsigned int *)t19);
    t55 = (!(t23));
    t56 = (t52 && t55);
    t20 = (t43 + 4);
    t24 = *((unsigned int *)t20);
    t59 = (!(t24));
    t60 = (t56 && t59);
    if (t60 == 1)
        goto LAB25;

LAB26:
LAB16:    goto LAB8;

LAB12:    t33 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t33) = 1;
    goto LAB13;

LAB14:    xsi_set_current_line(18, ng0);

LAB17:    xsi_set_current_line(19, ng0);
    t40 = ((char*)((ng2)));
    t41 = (t0 + 1000);
    t45 = (t0 + 1000);
    t46 = (t45 + 44U);
    t47 = *((char **)t46);
    t48 = ((char*)((ng3)));
    t49 = ((char*)((ng4)));
    xsi_vlog_convert_partindices(t42, t43, t44, ((int*)(t47)), 2, t48, 32, 1, t49, 32, 1);
    t50 = (t42 + 4);
    t51 = *((unsigned int *)t50);
    t52 = (!(t51));
    t53 = (t43 + 4);
    t54 = *((unsigned int *)t53);
    t55 = (!(t54));
    t56 = (t52 && t55);
    t57 = (t44 + 4);
    t58 = *((unsigned int *)t57);
    t59 = (!(t58));
    t60 = (t56 && t59);
    if (t60 == 1)
        goto LAB18;

LAB19:    xsi_set_current_line(20, ng0);
    t2 = (t0 + 680U);
    t3 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t13 + 4);
    t4 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 0);
    *((unsigned int *)t13) = t7;
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 0);
    *((unsigned int *)t2) = t9;
    t10 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t10 & 65535U);
    t21 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t21 & 65535U);
    t5 = (t0 + 1000);
    t11 = (t0 + 1000);
    t12 = (t11 + 44U);
    t14 = *((char **)t12);
    t15 = ((char*)((ng1)));
    t16 = ((char*)((ng5)));
    xsi_vlog_convert_partindices(t18, t42, t43, ((int*)(t14)), 2, t15, 32, 1, t16, 32, 1);
    t17 = (t18 + 4);
    t22 = *((unsigned int *)t17);
    t52 = (!(t22));
    t19 = (t42 + 4);
    t23 = *((unsigned int *)t19);
    t55 = (!(t23));
    t56 = (t52 && t55);
    t20 = (t43 + 4);
    t24 = *((unsigned int *)t20);
    t59 = (!(t24));
    t60 = (t56 && t59);
    if (t60 == 1)
        goto LAB20;

LAB21:    goto LAB16;

LAB18:    t61 = *((unsigned int *)t44);
    t62 = (t61 + 0);
    t63 = *((unsigned int *)t42);
    t64 = *((unsigned int *)t43);
    t65 = (t63 - t64);
    t66 = (t65 + 1);
    xsi_vlogvar_wait_assign_value(t41, t40, t62, *((unsigned int *)t43), t66, 0LL);
    goto LAB19;

LAB20:    t25 = *((unsigned int *)t43);
    t62 = (t25 + 0);
    t26 = *((unsigned int *)t18);
    t27 = *((unsigned int *)t42);
    t65 = (t26 - t27);
    t66 = (t65 + 1);
    xsi_vlogvar_wait_assign_value(t5, t13, t62, *((unsigned int *)t42), t66, 500LL);
    goto LAB21;

LAB23:    t9 = *((unsigned int *)t42);
    t62 = (t9 + 0);
    t10 = *((unsigned int *)t13);
    t21 = *((unsigned int *)t18);
    t65 = (t10 - t21);
    t66 = (t65 + 1);
    xsi_vlogvar_wait_assign_value(t3, t2, t62, *((unsigned int *)t18), t66, 0LL);
    goto LAB24;

LAB25:    t25 = *((unsigned int *)t43);
    t62 = (t25 + 0);
    t26 = *((unsigned int *)t18);
    t27 = *((unsigned int *)t42);
    t65 = (t26 - t27);
    t66 = (t65 + 1);
    xsi_vlogvar_wait_assign_value(t5, t13, t62, *((unsigned int *)t42), t66, 500LL);
    goto LAB26;

LAB28:    t9 = *((unsigned int *)t42);
    t62 = (t9 + 0);
    t10 = *((unsigned int *)t13);
    t21 = *((unsigned int *)t18);
    t65 = (t10 - t21);
    t66 = (t65 + 1);
    xsi_vlogvar_wait_assign_value(t3, t2, t62, *((unsigned int *)t18), t66, 0LL);
    goto LAB29;

LAB30:    t25 = *((unsigned int *)t43);
    t62 = (t25 + 0);
    t26 = *((unsigned int *)t18);
    t27 = *((unsigned int *)t42);
    t65 = (t26 - t27);
    t66 = (t65 + 1);
    xsi_vlogvar_wait_assign_value(t5, t13, t62, *((unsigned int *)t42), t66, 500LL);
    goto LAB31;

}


extern void work_m_00000000000821496654_2664993444_init()
{
	static char *pe[] = {(void *)Always_13_0};
	xsi_register_didat("work_m_00000000000821496654_2664993444", "isim/Data_Subsystem_isim_beh.exe.sim/work/m_00000000000821496654_2664993444.didat");
	xsi_register_executes(pe);
}

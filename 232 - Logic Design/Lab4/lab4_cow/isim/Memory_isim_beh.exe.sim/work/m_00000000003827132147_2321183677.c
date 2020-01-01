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
static const char *ng0 = "D:/Google Downloads/lab4_cow/lab4_cow/Memory.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {0U, 0U};
static int ng3[] = {7, 0};
static unsigned int ng4[] = {1U, 0U};
static unsigned int ng5[] = {2U, 0U};
static unsigned int ng6[] = {3U, 0U};
static int ng7[] = {1, 0};
static int ng8[] = {15, 0};
static int ng9[] = {8, 0};
static int ng10[] = {23, 0};
static int ng11[] = {16, 0};
static int ng12[] = {31, 0};
static int ng13[] = {24, 0};



static void Always_19_0(char *t0)
{
    char t29[8];
    char t30[8];
    char t35[8];
    char t37[8];
    char t44[8];
    char t45[8];
    char t46[8];
    char t69[8];
    char t70[8];
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
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;
    char *t28;
    char *t31;
    char *t32;
    char *t33;
    int t34;
    char *t36;
    char *t38;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    char *t47;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    unsigned int t53;
    int t54;
    char *t55;
    unsigned int t56;
    int t57;
    int t58;
    char *t59;
    unsigned int t60;
    int t61;
    int t62;
    unsigned int t63;
    int t64;
    unsigned int t65;
    unsigned int t66;
    int t67;
    int t68;
    int t71;
    int t72;
    unsigned int t73;
    unsigned int t74;
    int t75;
    unsigned int t76;
    unsigned int t77;
    int t78;
    int t79;

LAB0:    t1 = (t0 + 2156U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(19, ng0);
    t2 = (t0 + 2352);
    *((int *)t2) = 1;
    t3 = (t0 + 2184);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(20, ng0);

LAB5:    xsi_set_current_line(21, ng0);
    t4 = (t0 + 1128U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(22, ng0);

LAB9:    xsi_set_current_line(23, ng0);
    t11 = (t0 + 1448);
    t12 = (t11 + 36U);
    t13 = *((char **)t12);
    t14 = (t13 + 4);
    t15 = *((unsigned int *)t14);
    t16 = (~(t15));
    t17 = *((unsigned int *)t13);
    t18 = (t17 & t16);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB10;

LAB11:
LAB12:    goto LAB8;

LAB10:    xsi_set_current_line(24, ng0);

LAB13:    xsi_set_current_line(25, ng0);
    t20 = (t0 + 944U);
    t21 = *((char **)t20);
    t20 = (t21 + 4);
    t22 = *((unsigned int *)t20);
    t23 = (~(t22));
    t24 = *((unsigned int *)t21);
    t25 = (t24 & t23);
    t26 = (t25 != 0);
    if (t26 > 0)
        goto LAB14;

LAB15:
LAB16:    xsi_set_current_line(57, ng0);
    t2 = (t0 + 1036U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB45;

LAB46:
LAB47:    goto LAB12;

LAB14:    xsi_set_current_line(26, ng0);

LAB17:    xsi_set_current_line(27, ng0);
    t27 = ((char*)((ng1)));
    t28 = (t0 + 1448);
    xsi_vlogvar_wait_assign_value(t28, t27, 0, 0, 1, 200LL);
    xsi_set_current_line(28, ng0);
    t2 = (t0 + 852U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(34, ng0);

LAB22:    xsi_set_current_line(35, ng0);
    t2 = (t0 + 760U);
    t3 = *((char **)t2);
    memset(t29, 0, 8);
    t2 = (t29 + 4);
    t4 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 0);
    *((unsigned int *)t29) = t7;
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 0);
    *((unsigned int *)t2) = t9;
    t10 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t10 & 3U);
    t15 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t15 & 3U);

LAB23:    t5 = ((char*)((ng2)));
    t34 = xsi_vlog_unsigned_case_compare(t29, 2, t5, 2);
    if (t34 == 1)
        goto LAB24;

LAB25:    t2 = ((char*)((ng4)));
    t34 = xsi_vlog_unsigned_case_compare(t29, 2, t2, 2);
    if (t34 == 1)
        goto LAB26;

LAB27:    t2 = ((char*)((ng5)));
    t34 = xsi_vlog_unsigned_case_compare(t29, 2, t2, 2);
    if (t34 == 1)
        goto LAB28;

LAB29:    t2 = ((char*)((ng6)));
    t34 = xsi_vlog_unsigned_case_compare(t29, 2, t2, 2);
    if (t34 == 1)
        goto LAB30;

LAB31:
LAB32:
LAB20:    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 1448);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 8000LL);
    goto LAB16;

LAB18:    xsi_set_current_line(29, ng0);

LAB21:    xsi_set_current_line(30, ng0);
    t4 = (t0 + 1632);
    t5 = (t4 + 36U);
    t11 = *((char **)t5);
    t12 = (t0 + 1632);
    t13 = (t12 + 44U);
    t14 = *((char **)t13);
    t20 = (t0 + 1632);
    t21 = (t20 + 40U);
    t27 = *((char **)t21);
    t28 = (t0 + 760U);
    t31 = *((char **)t28);
    memset(t30, 0, 8);
    t28 = (t30 + 4);
    t32 = (t31 + 4);
    t15 = *((unsigned int *)t31);
    t16 = (t15 >> 2);
    *((unsigned int *)t30) = t16;
    t17 = *((unsigned int *)t32);
    t18 = (t17 >> 2);
    *((unsigned int *)t28) = t18;
    t19 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t19 & 4194303U);
    t22 = *((unsigned int *)t28);
    *((unsigned int *)t28) = (t22 & 4194303U);
    xsi_vlog_generic_get_array_select_value(t29, 32, t11, t14, t27, 2, 1, t30, 22, 2);
    t33 = (t0 + 1540);
    xsi_vlogvar_wait_assign_value(t33, t29, 0, 0, 32, 0LL);
    goto LAB20;

LAB24:    xsi_set_current_line(37, ng0);

LAB33:    xsi_set_current_line(38, ng0);
    t11 = (t0 + 1632);
    t12 = (t11 + 36U);
    t13 = *((char **)t12);
    t14 = (t0 + 1632);
    t20 = (t14 + 44U);
    t21 = *((char **)t20);
    t27 = (t0 + 1632);
    t28 = (t27 + 40U);
    t31 = *((char **)t28);
    t32 = (t0 + 760U);
    t33 = *((char **)t32);
    memset(t35, 0, 8);
    t32 = (t35 + 4);
    t36 = (t33 + 4);
    t16 = *((unsigned int *)t33);
    t17 = (t16 >> 2);
    *((unsigned int *)t35) = t17;
    t18 = *((unsigned int *)t36);
    t19 = (t18 >> 2);
    *((unsigned int *)t32) = t19;
    t22 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t22 & 4194303U);
    t23 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t23 & 4194303U);
    xsi_vlog_generic_get_array_select_value(t30, 32, t13, t21, t31, 2, 1, t35, 22, 2);
    memset(t37, 0, 8);
    t38 = (t37 + 4);
    t39 = (t30 + 4);
    t24 = *((unsigned int *)t30);
    t25 = (t24 >> 0);
    *((unsigned int *)t37) = t25;
    t26 = *((unsigned int *)t39);
    t40 = (t26 >> 0);
    *((unsigned int *)t38) = t40;
    t41 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t41 & 255U);
    t42 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t42 & 255U);
    t43 = (t0 + 1540);
    t47 = (t0 + 1540);
    t48 = (t47 + 44U);
    t49 = *((char **)t48);
    t50 = ((char*)((ng3)));
    t51 = ((char*)((ng1)));
    xsi_vlog_convert_partindices(t44, t45, t46, ((int*)(t49)), 2, t50, 32, 1, t51, 32, 1);
    t52 = (t44 + 4);
    t53 = *((unsigned int *)t52);
    t54 = (!(t53));
    t55 = (t45 + 4);
    t56 = *((unsigned int *)t55);
    t57 = (!(t56));
    t58 = (t54 && t57);
    t59 = (t46 + 4);
    t60 = *((unsigned int *)t59);
    t61 = (!(t60));
    t62 = (t58 && t61);
    if (t62 == 1)
        goto LAB34;

LAB35:    goto LAB32;

LAB26:    xsi_set_current_line(41, ng0);

LAB36:    xsi_set_current_line(42, ng0);
    t3 = (t0 + 1632);
    t4 = (t3 + 36U);
    t5 = *((char **)t4);
    t11 = (t0 + 1632);
    t12 = (t11 + 44U);
    t13 = *((char **)t12);
    t14 = (t0 + 1632);
    t20 = (t14 + 40U);
    t21 = *((char **)t20);
    t27 = (t0 + 760U);
    t28 = *((char **)t27);
    memset(t35, 0, 8);
    t27 = (t35 + 4);
    t31 = (t28 + 4);
    t6 = *((unsigned int *)t28);
    t7 = (t6 >> 2);
    *((unsigned int *)t35) = t7;
    t8 = *((unsigned int *)t31);
    t9 = (t8 >> 2);
    *((unsigned int *)t27) = t9;
    t10 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t10 & 4194303U);
    t15 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t15 & 4194303U);
    xsi_vlog_generic_get_array_select_value(t30, 32, t5, t13, t21, 2, 1, t35, 22, 2);
    memset(t37, 0, 8);
    t32 = (t37 + 4);
    t33 = (t30 + 4);
    t16 = *((unsigned int *)t30);
    t17 = (t16 >> 8);
    *((unsigned int *)t37) = t17;
    t18 = *((unsigned int *)t33);
    t19 = (t18 >> 8);
    *((unsigned int *)t32) = t19;
    t22 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t22 & 255U);
    t23 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t23 & 255U);
    t36 = (t0 + 1540);
    t38 = (t0 + 1540);
    t39 = (t38 + 44U);
    t43 = *((char **)t39);
    t47 = ((char*)((ng3)));
    t48 = ((char*)((ng1)));
    xsi_vlog_convert_partindices(t44, t45, t46, ((int*)(t43)), 2, t47, 32, 1, t48, 32, 1);
    t49 = (t44 + 4);
    t24 = *((unsigned int *)t49);
    t54 = (!(t24));
    t50 = (t45 + 4);
    t25 = *((unsigned int *)t50);
    t57 = (!(t25));
    t58 = (t54 && t57);
    t51 = (t46 + 4);
    t26 = *((unsigned int *)t51);
    t61 = (!(t26));
    t62 = (t58 && t61);
    if (t62 == 1)
        goto LAB37;

LAB38:    goto LAB32;

LAB28:    xsi_set_current_line(45, ng0);

LAB39:    xsi_set_current_line(46, ng0);
    t3 = (t0 + 1632);
    t4 = (t3 + 36U);
    t5 = *((char **)t4);
    t11 = (t0 + 1632);
    t12 = (t11 + 44U);
    t13 = *((char **)t12);
    t14 = (t0 + 1632);
    t20 = (t14 + 40U);
    t21 = *((char **)t20);
    t27 = (t0 + 760U);
    t28 = *((char **)t27);
    memset(t35, 0, 8);
    t27 = (t35 + 4);
    t31 = (t28 + 4);
    t6 = *((unsigned int *)t28);
    t7 = (t6 >> 2);
    *((unsigned int *)t35) = t7;
    t8 = *((unsigned int *)t31);
    t9 = (t8 >> 2);
    *((unsigned int *)t27) = t9;
    t10 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t10 & 4194303U);
    t15 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t15 & 4194303U);
    xsi_vlog_generic_get_array_select_value(t30, 32, t5, t13, t21, 2, 1, t35, 22, 2);
    memset(t37, 0, 8);
    t32 = (t37 + 4);
    t33 = (t30 + 4);
    t16 = *((unsigned int *)t30);
    t17 = (t16 >> 16);
    *((unsigned int *)t37) = t17;
    t18 = *((unsigned int *)t33);
    t19 = (t18 >> 16);
    *((unsigned int *)t32) = t19;
    t22 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t22 & 255U);
    t23 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t23 & 255U);
    t36 = (t0 + 1540);
    t38 = (t0 + 1540);
    t39 = (t38 + 44U);
    t43 = *((char **)t39);
    t47 = ((char*)((ng3)));
    t48 = ((char*)((ng1)));
    xsi_vlog_convert_partindices(t44, t45, t46, ((int*)(t43)), 2, t47, 32, 1, t48, 32, 1);
    t49 = (t44 + 4);
    t24 = *((unsigned int *)t49);
    t54 = (!(t24));
    t50 = (t45 + 4);
    t25 = *((unsigned int *)t50);
    t57 = (!(t25));
    t58 = (t54 && t57);
    t51 = (t46 + 4);
    t26 = *((unsigned int *)t51);
    t61 = (!(t26));
    t62 = (t58 && t61);
    if (t62 == 1)
        goto LAB40;

LAB41:    goto LAB32;

LAB30:    xsi_set_current_line(49, ng0);

LAB42:    xsi_set_current_line(50, ng0);
    t3 = (t0 + 1632);
    t4 = (t3 + 36U);
    t5 = *((char **)t4);
    t11 = (t0 + 1632);
    t12 = (t11 + 44U);
    t13 = *((char **)t12);
    t14 = (t0 + 1632);
    t20 = (t14 + 40U);
    t21 = *((char **)t20);
    t27 = (t0 + 760U);
    t28 = *((char **)t27);
    memset(t35, 0, 8);
    t27 = (t35 + 4);
    t31 = (t28 + 4);
    t6 = *((unsigned int *)t28);
    t7 = (t6 >> 2);
    *((unsigned int *)t35) = t7;
    t8 = *((unsigned int *)t31);
    t9 = (t8 >> 2);
    *((unsigned int *)t27) = t9;
    t10 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t10 & 4194303U);
    t15 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t15 & 4194303U);
    xsi_vlog_generic_get_array_select_value(t30, 32, t5, t13, t21, 2, 1, t35, 22, 2);
    memset(t37, 0, 8);
    t32 = (t37 + 4);
    t33 = (t30 + 4);
    t16 = *((unsigned int *)t30);
    t17 = (t16 >> 24);
    *((unsigned int *)t37) = t17;
    t18 = *((unsigned int *)t33);
    t19 = (t18 >> 24);
    *((unsigned int *)t32) = t19;
    t22 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t22 & 255U);
    t23 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t23 & 255U);
    t36 = (t0 + 1540);
    t38 = (t0 + 1540);
    t39 = (t38 + 44U);
    t43 = *((char **)t39);
    t47 = ((char*)((ng3)));
    t48 = ((char*)((ng1)));
    xsi_vlog_convert_partindices(t44, t45, t46, ((int*)(t43)), 2, t47, 32, 1, t48, 32, 1);
    t49 = (t44 + 4);
    t24 = *((unsigned int *)t49);
    t54 = (!(t24));
    t50 = (t45 + 4);
    t25 = *((unsigned int *)t50);
    t57 = (!(t25));
    t58 = (t54 && t57);
    t51 = (t46 + 4);
    t26 = *((unsigned int *)t51);
    t61 = (!(t26));
    t62 = (t58 && t61);
    if (t62 == 1)
        goto LAB43;

LAB44:    goto LAB32;

LAB34:    t63 = *((unsigned int *)t46);
    t64 = (t63 + 0);
    t65 = *((unsigned int *)t44);
    t66 = *((unsigned int *)t45);
    t67 = (t65 - t66);
    t68 = (t67 + 1);
    xsi_vlogvar_wait_assign_value(t43, t37, t64, *((unsigned int *)t45), t68, 0LL);
    goto LAB35;

LAB37:    t40 = *((unsigned int *)t46);
    t64 = (t40 + 0);
    t41 = *((unsigned int *)t44);
    t42 = *((unsigned int *)t45);
    t67 = (t41 - t42);
    t68 = (t67 + 1);
    xsi_vlogvar_wait_assign_value(t36, t37, t64, *((unsigned int *)t45), t68, 0LL);
    goto LAB38;

LAB40:    t40 = *((unsigned int *)t46);
    t64 = (t40 + 0);
    t41 = *((unsigned int *)t44);
    t42 = *((unsigned int *)t45);
    t67 = (t41 - t42);
    t68 = (t67 + 1);
    xsi_vlogvar_wait_assign_value(t36, t37, t64, *((unsigned int *)t45), t68, 0LL);
    goto LAB41;

LAB43:    t40 = *((unsigned int *)t46);
    t64 = (t40 + 0);
    t41 = *((unsigned int *)t44);
    t42 = *((unsigned int *)t45);
    t67 = (t41 - t42);
    t68 = (t67 + 1);
    xsi_vlogvar_wait_assign_value(t36, t37, t64, *((unsigned int *)t45), t68, 0LL);
    goto LAB44;

LAB45:    xsi_set_current_line(58, ng0);

LAB48:    xsi_set_current_line(59, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 1448);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 200LL);
    xsi_set_current_line(60, ng0);
    t2 = (t0 + 852U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB49;

LAB50:    xsi_set_current_line(65, ng0);

LAB55:    xsi_set_current_line(66, ng0);
    t2 = (t0 + 760U);
    t3 = *((char **)t2);
    memset(t30, 0, 8);
    t2 = (t30 + 4);
    t4 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 0);
    *((unsigned int *)t30) = t7;
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 0);
    *((unsigned int *)t2) = t9;
    t10 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t10 & 3U);
    t15 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t15 & 3U);

LAB56:    t5 = ((char*)((ng2)));
    t34 = xsi_vlog_unsigned_case_compare(t30, 2, t5, 2);
    if (t34 == 1)
        goto LAB57;

LAB58:    t2 = ((char*)((ng4)));
    t34 = xsi_vlog_unsigned_case_compare(t30, 2, t2, 2);
    if (t34 == 1)
        goto LAB59;

LAB60:    t2 = ((char*)((ng5)));
    t34 = xsi_vlog_unsigned_case_compare(t30, 2, t2, 2);
    if (t34 == 1)
        goto LAB61;

LAB62:    t2 = ((char*)((ng6)));
    t34 = xsi_vlog_unsigned_case_compare(t30, 2, t2, 2);
    if (t34 == 1)
        goto LAB63;

LAB64:
LAB65:
LAB51:    xsi_set_current_line(85, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 1448);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 8000LL);
    goto LAB47;

LAB49:    xsi_set_current_line(61, ng0);

LAB52:    xsi_set_current_line(62, ng0);
    t4 = (t0 + 1220U);
    t5 = *((char **)t4);
    t4 = (t0 + 1632);
    t11 = (t0 + 1632);
    t12 = (t11 + 44U);
    t13 = *((char **)t12);
    t14 = (t0 + 1632);
    t20 = (t14 + 40U);
    t21 = *((char **)t20);
    t27 = (t0 + 760U);
    t28 = *((char **)t27);
    memset(t37, 0, 8);
    t27 = (t37 + 4);
    t31 = (t28 + 4);
    t15 = *((unsigned int *)t28);
    t16 = (t15 >> 2);
    *((unsigned int *)t37) = t16;
    t17 = *((unsigned int *)t31);
    t18 = (t17 >> 2);
    *((unsigned int *)t27) = t18;
    t19 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t19 & 4194303U);
    t22 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t22 & 4194303U);
    xsi_vlog_generic_convert_array_indices(t30, t35, t13, t21, 2, 1, t37, 22, 2);
    t32 = (t30 + 4);
    t23 = *((unsigned int *)t32);
    t34 = (!(t23));
    t33 = (t35 + 4);
    t24 = *((unsigned int *)t33);
    t54 = (!(t24));
    t57 = (t34 && t54);
    if (t57 == 1)
        goto LAB53;

LAB54:    goto LAB51;

LAB53:    t25 = *((unsigned int *)t30);
    t26 = *((unsigned int *)t35);
    t58 = (t25 - t26);
    t61 = (t58 + 1);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, *((unsigned int *)t35), t61, 0LL);
    goto LAB54;

LAB57:    xsi_set_current_line(68, ng0);

LAB66:    xsi_set_current_line(69, ng0);
    t11 = (t0 + 1220U);
    t12 = *((char **)t11);
    memset(t35, 0, 8);
    t11 = (t35 + 4);
    t13 = (t12 + 4);
    t16 = *((unsigned int *)t12);
    t17 = (t16 >> 0);
    *((unsigned int *)t35) = t17;
    t18 = *((unsigned int *)t13);
    t19 = (t18 >> 0);
    *((unsigned int *)t11) = t19;
    t22 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t22 & 255U);
    t23 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t23 & 255U);
    t14 = (t0 + 1632);
    t20 = (t0 + 1632);
    t21 = (t20 + 44U);
    t27 = *((char **)t21);
    t28 = (t0 + 1632);
    t31 = (t28 + 40U);
    t32 = *((char **)t31);
    t33 = (t0 + 760U);
    t36 = *((char **)t33);
    memset(t45, 0, 8);
    t33 = (t45 + 4);
    t38 = (t36 + 4);
    t24 = *((unsigned int *)t36);
    t25 = (t24 >> 2);
    *((unsigned int *)t45) = t25;
    t26 = *((unsigned int *)t38);
    t40 = (t26 >> 2);
    *((unsigned int *)t33) = t40;
    t41 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t41 & 4194303U);
    t42 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t42 & 4194303U);
    xsi_vlog_generic_convert_array_indices(t37, t44, t27, t32, 2, 1, t45, 22, 2);
    t39 = (t0 + 1632);
    t43 = (t39 + 44U);
    t47 = *((char **)t43);
    t48 = ((char*)((ng3)));
    t49 = ((char*)((ng1)));
    xsi_vlog_convert_partindices(t46, t69, t70, ((int*)(t47)), 2, t48, 32, 1, t49, 32, 1);
    t50 = (t37 + 4);
    t53 = *((unsigned int *)t50);
    t54 = (!(t53));
    t51 = (t44 + 4);
    t56 = *((unsigned int *)t51);
    t57 = (!(t56));
    t58 = (t54 && t57);
    t52 = (t46 + 4);
    t60 = *((unsigned int *)t52);
    t61 = (!(t60));
    t62 = (t58 && t61);
    t55 = (t69 + 4);
    t63 = *((unsigned int *)t55);
    t64 = (!(t63));
    t67 = (t62 && t64);
    t59 = (t70 + 4);
    t65 = *((unsigned int *)t59);
    t68 = (!(t65));
    t71 = (t67 && t68);
    if (t71 == 1)
        goto LAB67;

LAB68:    goto LAB65;

LAB59:    xsi_set_current_line(72, ng0);

LAB69:    xsi_set_current_line(73, ng0);
    t3 = (t0 + 1220U);
    t4 = *((char **)t3);
    memset(t35, 0, 8);
    t3 = (t35 + 4);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (t6 >> 8);
    *((unsigned int *)t35) = t7;
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 8);
    *((unsigned int *)t3) = t9;
    t10 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t10 & 255U);
    t15 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t15 & 255U);
    t11 = (t0 + 1632);
    t12 = (t0 + 1632);
    t13 = (t12 + 44U);
    t14 = *((char **)t13);
    t20 = (t0 + 1632);
    t21 = (t20 + 40U);
    t27 = *((char **)t21);
    t28 = (t0 + 760U);
    t31 = *((char **)t28);
    memset(t45, 0, 8);
    t28 = (t45 + 4);
    t32 = (t31 + 4);
    t16 = *((unsigned int *)t31);
    t17 = (t16 >> 2);
    *((unsigned int *)t45) = t17;
    t18 = *((unsigned int *)t32);
    t19 = (t18 >> 2);
    *((unsigned int *)t28) = t19;
    t22 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t22 & 4194303U);
    t23 = *((unsigned int *)t28);
    *((unsigned int *)t28) = (t23 & 4194303U);
    xsi_vlog_generic_convert_array_indices(t37, t44, t14, t27, 2, 1, t45, 22, 2);
    t33 = (t0 + 1632);
    t36 = (t33 + 44U);
    t38 = *((char **)t36);
    t39 = ((char*)((ng8)));
    t43 = ((char*)((ng9)));
    xsi_vlog_convert_partindices(t46, t69, t70, ((int*)(t38)), 2, t39, 32, 1, t43, 32, 1);
    t47 = (t37 + 4);
    t24 = *((unsigned int *)t47);
    t54 = (!(t24));
    t48 = (t44 + 4);
    t25 = *((unsigned int *)t48);
    t57 = (!(t25));
    t58 = (t54 && t57);
    t49 = (t46 + 4);
    t26 = *((unsigned int *)t49);
    t61 = (!(t26));
    t62 = (t58 && t61);
    t50 = (t69 + 4);
    t40 = *((unsigned int *)t50);
    t64 = (!(t40));
    t67 = (t62 && t64);
    t51 = (t70 + 4);
    t41 = *((unsigned int *)t51);
    t68 = (!(t41));
    t71 = (t67 && t68);
    if (t71 == 1)
        goto LAB70;

LAB71:    goto LAB65;

LAB61:    xsi_set_current_line(76, ng0);

LAB72:    xsi_set_current_line(77, ng0);
    t3 = (t0 + 1220U);
    t4 = *((char **)t3);
    memset(t35, 0, 8);
    t3 = (t35 + 4);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (t6 >> 16);
    *((unsigned int *)t35) = t7;
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 16);
    *((unsigned int *)t3) = t9;
    t10 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t10 & 255U);
    t15 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t15 & 255U);
    t11 = (t0 + 1632);
    t12 = (t0 + 1632);
    t13 = (t12 + 44U);
    t14 = *((char **)t13);
    t20 = (t0 + 1632);
    t21 = (t20 + 40U);
    t27 = *((char **)t21);
    t28 = (t0 + 760U);
    t31 = *((char **)t28);
    memset(t45, 0, 8);
    t28 = (t45 + 4);
    t32 = (t31 + 4);
    t16 = *((unsigned int *)t31);
    t17 = (t16 >> 2);
    *((unsigned int *)t45) = t17;
    t18 = *((unsigned int *)t32);
    t19 = (t18 >> 2);
    *((unsigned int *)t28) = t19;
    t22 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t22 & 4194303U);
    t23 = *((unsigned int *)t28);
    *((unsigned int *)t28) = (t23 & 4194303U);
    xsi_vlog_generic_convert_array_indices(t37, t44, t14, t27, 2, 1, t45, 22, 2);
    t33 = (t0 + 1632);
    t36 = (t33 + 44U);
    t38 = *((char **)t36);
    t39 = ((char*)((ng10)));
    t43 = ((char*)((ng11)));
    xsi_vlog_convert_partindices(t46, t69, t70, ((int*)(t38)), 2, t39, 32, 1, t43, 32, 1);
    t47 = (t37 + 4);
    t24 = *((unsigned int *)t47);
    t54 = (!(t24));
    t48 = (t44 + 4);
    t25 = *((unsigned int *)t48);
    t57 = (!(t25));
    t58 = (t54 && t57);
    t49 = (t46 + 4);
    t26 = *((unsigned int *)t49);
    t61 = (!(t26));
    t62 = (t58 && t61);
    t50 = (t69 + 4);
    t40 = *((unsigned int *)t50);
    t64 = (!(t40));
    t67 = (t62 && t64);
    t51 = (t70 + 4);
    t41 = *((unsigned int *)t51);
    t68 = (!(t41));
    t71 = (t67 && t68);
    if (t71 == 1)
        goto LAB73;

LAB74:    goto LAB65;

LAB63:    xsi_set_current_line(80, ng0);

LAB75:    xsi_set_current_line(81, ng0);
    t3 = (t0 + 1220U);
    t4 = *((char **)t3);
    memset(t35, 0, 8);
    t3 = (t35 + 4);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (t6 >> 24);
    *((unsigned int *)t35) = t7;
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 24);
    *((unsigned int *)t3) = t9;
    t10 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t10 & 255U);
    t15 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t15 & 255U);
    t11 = (t0 + 1632);
    t12 = (t0 + 1632);
    t13 = (t12 + 44U);
    t14 = *((char **)t13);
    t20 = (t0 + 1632);
    t21 = (t20 + 40U);
    t27 = *((char **)t21);
    t28 = (t0 + 760U);
    t31 = *((char **)t28);
    memset(t45, 0, 8);
    t28 = (t45 + 4);
    t32 = (t31 + 4);
    t16 = *((unsigned int *)t31);
    t17 = (t16 >> 2);
    *((unsigned int *)t45) = t17;
    t18 = *((unsigned int *)t32);
    t19 = (t18 >> 2);
    *((unsigned int *)t28) = t19;
    t22 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t22 & 4194303U);
    t23 = *((unsigned int *)t28);
    *((unsigned int *)t28) = (t23 & 4194303U);
    xsi_vlog_generic_convert_array_indices(t37, t44, t14, t27, 2, 1, t45, 22, 2);
    t33 = (t0 + 1632);
    t36 = (t33 + 44U);
    t38 = *((char **)t36);
    t39 = ((char*)((ng12)));
    t43 = ((char*)((ng13)));
    xsi_vlog_convert_partindices(t46, t69, t70, ((int*)(t38)), 2, t39, 32, 1, t43, 32, 1);
    t47 = (t37 + 4);
    t24 = *((unsigned int *)t47);
    t54 = (!(t24));
    t48 = (t44 + 4);
    t25 = *((unsigned int *)t48);
    t57 = (!(t25));
    t58 = (t54 && t57);
    t49 = (t46 + 4);
    t26 = *((unsigned int *)t49);
    t61 = (!(t26));
    t62 = (t58 && t61);
    t50 = (t69 + 4);
    t40 = *((unsigned int *)t50);
    t64 = (!(t40));
    t67 = (t62 && t64);
    t51 = (t70 + 4);
    t41 = *((unsigned int *)t51);
    t68 = (!(t41));
    t71 = (t67 && t68);
    if (t71 == 1)
        goto LAB76;

LAB77:    goto LAB65;

LAB67:    t66 = *((unsigned int *)t70);
    t72 = (t66 + 0);
    t73 = *((unsigned int *)t44);
    t74 = *((unsigned int *)t69);
    t75 = (t73 + t74);
    t76 = *((unsigned int *)t46);
    t77 = *((unsigned int *)t69);
    t78 = (t76 - t77);
    t79 = (t78 + 1);
    xsi_vlogvar_wait_assign_value(t14, t35, t72, t75, t79, 0LL);
    goto LAB68;

LAB70:    t42 = *((unsigned int *)t70);
    t72 = (t42 + 0);
    t53 = *((unsigned int *)t44);
    t56 = *((unsigned int *)t69);
    t75 = (t53 + t56);
    t60 = *((unsigned int *)t46);
    t63 = *((unsigned int *)t69);
    t78 = (t60 - t63);
    t79 = (t78 + 1);
    xsi_vlogvar_wait_assign_value(t11, t35, t72, t75, t79, 0LL);
    goto LAB71;

LAB73:    t42 = *((unsigned int *)t70);
    t72 = (t42 + 0);
    t53 = *((unsigned int *)t44);
    t56 = *((unsigned int *)t69);
    t75 = (t53 + t56);
    t60 = *((unsigned int *)t46);
    t63 = *((unsigned int *)t69);
    t78 = (t60 - t63);
    t79 = (t78 + 1);
    xsi_vlogvar_wait_assign_value(t11, t35, t72, t75, t79, 0LL);
    goto LAB74;

LAB76:    t42 = *((unsigned int *)t70);
    t72 = (t42 + 0);
    t53 = *((unsigned int *)t44);
    t56 = *((unsigned int *)t69);
    t75 = (t53 + t56);
    t60 = *((unsigned int *)t46);
    t63 = *((unsigned int *)t69);
    t78 = (t60 - t63);
    t79 = (t78 + 1);
    xsi_vlogvar_wait_assign_value(t11, t35, t72, t75, t79, 0LL);
    goto LAB77;

}


extern void work_m_00000000003827132147_2321183677_init()
{
	static char *pe[] = {(void *)Always_19_0};
	xsi_register_didat("work_m_00000000003827132147_2321183677", "isim/Memory_isim_beh.exe.sim/work/m_00000000003827132147_2321183677.didat");
	xsi_register_executes(pe);
}

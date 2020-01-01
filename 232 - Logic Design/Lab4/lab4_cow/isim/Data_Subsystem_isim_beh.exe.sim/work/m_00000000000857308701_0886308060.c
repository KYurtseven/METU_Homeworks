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
static const char *ng0 = "D:/Google Downloads/lab4_cow/lab4_cow/ALU.v";
static unsigned int ng1[] = {0U, 0U};
static int ng2[] = {0, 0};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {3U, 0U};
static unsigned int ng6[] = {4U, 0U};
static unsigned int ng7[] = {5U, 0U};
static unsigned int ng8[] = {6U, 0U};
static unsigned int ng9[] = {7U, 0U};
static unsigned int ng10[] = {8U, 0U};
static unsigned int ng11[] = {9U, 0U};
static unsigned int ng12[] = {10U, 0U};
static unsigned int ng13[] = {11U, 0U};
static unsigned int ng14[] = {12U, 0U};
static unsigned int ng15[] = {13U, 0U};
static unsigned int ng16[] = {14U, 0U};
static unsigned int ng17[] = {15U, 0U};
static unsigned int ng18[] = {0U, 15U};
static unsigned int ng19[] = {15U, 15U};



static void Always_33_0(char *t0)
{
    char t9[16];
    char t10[8];
    char t19[8];
    char t26[8];
    char t43[8];
    char t54[8];
    char t63[8];
    char t79[8];
    char t119[8];
    char t120[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    char *t42;
    char *t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    char *t52;
    char *t53;
    char *t55;
    char *t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    char *t64;
    char *t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    char *t78;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    char *t84;
    char *t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    char *t93;
    char *t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    char *t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    char *t116;
    char *t117;
    int t118;
    char *t121;
    char *t122;
    char *t123;
    char *t124;
    char *t125;
    char *t126;

LAB0:    t1 = (t0 + 2260U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(33, ng0);
    t2 = (t0 + 2456);
    *((int *)t2) = 1;
    t3 = (t0 + 2288);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(34, ng0);

LAB5:    xsi_set_current_line(35, ng0);
    t4 = (t0 + 864U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t4, 4);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng7)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng8)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng9)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng10)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng11)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB25;

LAB26:    t2 = ((char*)((ng12)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB27;

LAB28:    t2 = ((char*)((ng13)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB29;

LAB30:    t2 = ((char*)((ng14)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB31;

LAB32:    t2 = ((char*)((ng15)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB33;

LAB34:    t2 = ((char*)((ng16)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB35;

LAB36:    t2 = ((char*)((ng17)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB37;

LAB38:
LAB39:    xsi_set_current_line(67, ng0);
    t2 = (t0 + 864U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng18)));
    memset(t19, 0, 8);
    if (*((unsigned int *)t3) != *((unsigned int *)t2))
        goto LAB88;

LAB86:    t4 = (t3 + 4);
    t7 = (t2 + 4);
    if (*((unsigned int *)t4) != *((unsigned int *)t7))
        goto LAB88;

LAB87:    *((unsigned int *)t19) = 1;

LAB88:    memset(t26, 0, 8);
    t8 = (t19 + 4);
    t11 = *((unsigned int *)t8);
    t12 = (~(t11));
    t13 = *((unsigned int *)t19);
    t14 = (t13 & t12);
    t15 = (t14 & 1U);
    if (t15 != 0)
        goto LAB89;

LAB90:    if (*((unsigned int *)t8) != 0)
        goto LAB91;

LAB92:    t18 = (t26 + 4);
    t16 = *((unsigned int *)t26);
    t20 = (!(t16));
    t21 = *((unsigned int *)t18);
    t22 = (t20 || t21);
    if (t22 > 0)
        goto LAB93;

LAB94:    memcpy(t63, t26, 8);

LAB95:    memset(t10, 0, 8);
    t65 = (t63 + 4);
    t61 = *((unsigned int *)t65);
    t62 = (~(t61));
    t66 = *((unsigned int *)t63);
    t67 = (t66 & t62);
    t68 = (t67 & 1U);
    if (t68 != 0)
        goto LAB109;

LAB107:    if (*((unsigned int *)t65) == 0)
        goto LAB106;

LAB108:    t78 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t78) = 1;

LAB109:    t83 = (t10 + 4);
    t69 = *((unsigned int *)t83);
    t70 = (~(t69));
    t71 = *((unsigned int *)t10);
    t72 = (t71 & t70);
    t73 = (t72 != 0);
    if (t73 > 0)
        goto LAB110;

LAB111:
LAB112:    goto LAB2;

LAB7:    xsi_set_current_line(36, ng0);
    t7 = ((char*)((ng2)));
    t8 = (t0 + 1644);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);
    goto LAB39;

LAB9:    xsi_set_current_line(38, ng0);

LAB40:    xsi_set_current_line(39, ng0);
    t3 = (t0 + 680U);
    t4 = *((char **)t3);
    t3 = (t0 + 772U);
    t7 = *((char **)t3);
    xsi_vlog_unsigned_add(t9, 33, t4, 32, t7, 32);
    t3 = (t0 + 1736);
    xsi_vlogvar_assign_value(t3, t9, 0, 0, 33);
    xsi_set_current_line(40, ng0);
    t2 = (t0 + 1736);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    memset(t10, 0, 8);
    t7 = (t10 + 4);
    t8 = (t4 + 4);
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    *((unsigned int *)t10) = t12;
    t13 = *((unsigned int *)t8);
    t14 = (t13 >> 0);
    *((unsigned int *)t7) = t14;
    t15 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t15 & 4294967295U);
    t16 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t16 & 4294967295U);
    t17 = (t0 + 1644);
    xsi_vlogvar_assign_value(t17, t10, 0, 0, 32);
    xsi_set_current_line(41, ng0);
    t2 = (t0 + 1736);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    memset(t10, 0, 8);
    t7 = (t10 + 4);
    t8 = (t4 + 8);
    t17 = (t4 + 12);
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 0);
    t13 = (t12 & 1);
    *((unsigned int *)t10) = t13;
    t14 = *((unsigned int *)t17);
    t15 = (t14 >> 0);
    t16 = (t15 & 1);
    *((unsigned int *)t7) = t16;
    t18 = (t0 + 1460);
    xsi_vlogvar_assign_value(t18, t10, 0, 0, 1);
    xsi_set_current_line(42, ng0);
    t2 = (t0 + 680U);
    t3 = *((char **)t2);
    memset(t10, 0, 8);
    t2 = (t10 + 4);
    t4 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t12 = (t11 >> 31);
    t13 = (t12 & 1);
    *((unsigned int *)t10) = t13;
    t14 = *((unsigned int *)t4);
    t15 = (t14 >> 31);
    t16 = (t15 & 1);
    *((unsigned int *)t2) = t16;
    t7 = (t0 + 772U);
    t8 = *((char **)t7);
    memset(t19, 0, 8);
    t7 = (t19 + 4);
    t17 = (t8 + 4);
    t20 = *((unsigned int *)t8);
    t21 = (t20 >> 31);
    t22 = (t21 & 1);
    *((unsigned int *)t19) = t22;
    t23 = *((unsigned int *)t17);
    t24 = (t23 >> 31);
    t25 = (t24 & 1);
    *((unsigned int *)t7) = t25;
    memset(t26, 0, 8);
    t18 = (t10 + 4);
    t27 = (t19 + 4);
    t28 = *((unsigned int *)t10);
    t29 = *((unsigned int *)t19);
    t30 = (t28 ^ t29);
    t31 = *((unsigned int *)t18);
    t32 = *((unsigned int *)t27);
    t33 = (t31 ^ t32);
    t34 = (t30 | t33);
    t35 = *((unsigned int *)t18);
    t36 = *((unsigned int *)t27);
    t37 = (t35 | t36);
    t38 = (~(t37));
    t39 = (t34 & t38);
    if (t39 != 0)
        goto LAB44;

LAB41:    if (t37 != 0)
        goto LAB43;

LAB42:    *((unsigned int *)t26) = 1;

LAB44:    t41 = (t0 + 680U);
    t42 = *((char **)t41);
    memset(t43, 0, 8);
    t41 = (t43 + 4);
    t44 = (t42 + 4);
    t45 = *((unsigned int *)t42);
    t46 = (t45 >> 31);
    t47 = (t46 & 1);
    *((unsigned int *)t43) = t47;
    t48 = *((unsigned int *)t44);
    t49 = (t48 >> 31);
    t50 = (t49 & 1);
    *((unsigned int *)t41) = t50;
    t51 = (t0 + 1736);
    t52 = (t51 + 36U);
    t53 = *((char **)t52);
    memset(t54, 0, 8);
    t55 = (t54 + 4);
    t56 = (t53 + 4);
    t57 = *((unsigned int *)t53);
    t58 = (t57 >> 31);
    t59 = (t58 & 1);
    *((unsigned int *)t54) = t59;
    t60 = *((unsigned int *)t56);
    t61 = (t60 >> 31);
    t62 = (t61 & 1);
    *((unsigned int *)t55) = t62;
    memset(t63, 0, 8);
    t64 = (t43 + 4);
    t65 = (t54 + 4);
    t66 = *((unsigned int *)t43);
    t67 = *((unsigned int *)t54);
    t68 = (t66 ^ t67);
    t69 = *((unsigned int *)t64);
    t70 = *((unsigned int *)t65);
    t71 = (t69 ^ t70);
    t72 = (t68 | t71);
    t73 = *((unsigned int *)t64);
    t74 = *((unsigned int *)t65);
    t75 = (t73 | t74);
    t76 = (~(t75));
    t77 = (t72 & t76);
    if (t77 != 0)
        goto LAB46;

LAB45:    if (t75 != 0)
        goto LAB47;

LAB48:    t80 = *((unsigned int *)t26);
    t81 = *((unsigned int *)t63);
    t82 = (t80 & t81);
    *((unsigned int *)t79) = t82;
    t83 = (t26 + 4);
    t84 = (t63 + 4);
    t85 = (t79 + 4);
    t86 = *((unsigned int *)t83);
    t87 = *((unsigned int *)t84);
    t88 = (t86 | t87);
    *((unsigned int *)t85) = t88;
    t89 = *((unsigned int *)t85);
    t90 = (t89 != 0);
    if (t90 == 1)
        goto LAB49;

LAB50:
LAB51:    t110 = (t79 + 4);
    t111 = *((unsigned int *)t110);
    t112 = (~(t111));
    t113 = *((unsigned int *)t79);
    t114 = (t113 & t112);
    t115 = (t114 != 0);
    if (t115 > 0)
        goto LAB52;

LAB53:    xsi_set_current_line(43, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1552);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB54:    goto LAB39;

LAB11:    xsi_set_current_line(46, ng0);

LAB55:    xsi_set_current_line(47, ng0);
    t3 = (t0 + 680U);
    t4 = *((char **)t3);
    t3 = (t0 + 772U);
    t7 = *((char **)t3);
    memset(t10, 0, 8);
    xsi_vlog_unsigned_minus(t10, 32, t4, 32, t7, 32);
    t3 = (t0 + 1644);
    xsi_vlogvar_assign_value(t3, t10, 0, 0, 32);
    xsi_set_current_line(48, ng0);
    t2 = (t0 + 680U);
    t3 = *((char **)t2);
    t2 = (t0 + 772U);
    t4 = *((char **)t2);
    memset(t10, 0, 8);
    t2 = (t3 + 4);
    if (*((unsigned int *)t2) != 0)
        goto LAB57;

LAB56:    t7 = (t4 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB57;

LAB60:    if (*((unsigned int *)t3) < *((unsigned int *)t4))
        goto LAB58;

LAB59:    t17 = (t0 + 1460);
    xsi_vlogvar_assign_value(t17, t10, 0, 0, 1);
    xsi_set_current_line(49, ng0);
    t2 = (t0 + 680U);
    t3 = *((char **)t2);
    memset(t10, 0, 8);
    t2 = (t10 + 4);
    t4 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t12 = (t11 >> 31);
    t13 = (t12 & 1);
    *((unsigned int *)t10) = t13;
    t14 = *((unsigned int *)t4);
    t15 = (t14 >> 31);
    t16 = (t15 & 1);
    *((unsigned int *)t2) = t16;
    t7 = (t0 + 772U);
    t8 = *((char **)t7);
    memset(t19, 0, 8);
    t7 = (t19 + 4);
    t17 = (t8 + 4);
    t20 = *((unsigned int *)t8);
    t21 = (t20 >> 31);
    t22 = (t21 & 1);
    *((unsigned int *)t19) = t22;
    t23 = *((unsigned int *)t17);
    t24 = (t23 >> 31);
    t25 = (t24 & 1);
    *((unsigned int *)t7) = t25;
    memset(t26, 0, 8);
    t18 = (t10 + 4);
    t27 = (t19 + 4);
    t28 = *((unsigned int *)t10);
    t29 = *((unsigned int *)t19);
    t30 = (t28 ^ t29);
    t31 = *((unsigned int *)t18);
    t32 = *((unsigned int *)t27);
    t33 = (t31 ^ t32);
    t34 = (t30 | t33);
    t35 = *((unsigned int *)t18);
    t36 = *((unsigned int *)t27);
    t37 = (t35 | t36);
    t38 = (~(t37));
    t39 = (t34 & t38);
    if (t39 != 0)
        goto LAB62;

LAB61:    if (t37 != 0)
        goto LAB63;

LAB64:    t41 = (t0 + 680U);
    t42 = *((char **)t41);
    memset(t43, 0, 8);
    t41 = (t43 + 4);
    t44 = (t42 + 4);
    t45 = *((unsigned int *)t42);
    t46 = (t45 >> 31);
    t47 = (t46 & 1);
    *((unsigned int *)t43) = t47;
    t48 = *((unsigned int *)t44);
    t49 = (t48 >> 31);
    t50 = (t49 & 1);
    *((unsigned int *)t41) = t50;
    t51 = (t0 + 1644);
    t52 = (t51 + 36U);
    t53 = *((char **)t52);
    memset(t54, 0, 8);
    t55 = (t54 + 4);
    t56 = (t53 + 4);
    t57 = *((unsigned int *)t53);
    t58 = (t57 >> 31);
    t59 = (t58 & 1);
    *((unsigned int *)t54) = t59;
    t60 = *((unsigned int *)t56);
    t61 = (t60 >> 31);
    t62 = (t61 & 1);
    *((unsigned int *)t55) = t62;
    memset(t63, 0, 8);
    t64 = (t43 + 4);
    t65 = (t54 + 4);
    t66 = *((unsigned int *)t43);
    t67 = *((unsigned int *)t54);
    t68 = (t66 ^ t67);
    t69 = *((unsigned int *)t64);
    t70 = *((unsigned int *)t65);
    t71 = (t69 ^ t70);
    t72 = (t68 | t71);
    t73 = *((unsigned int *)t64);
    t74 = *((unsigned int *)t65);
    t75 = (t73 | t74);
    t76 = (~(t75));
    t77 = (t72 & t76);
    if (t77 != 0)
        goto LAB66;

LAB65:    if (t75 != 0)
        goto LAB67;

LAB68:    t80 = *((unsigned int *)t26);
    t81 = *((unsigned int *)t63);
    t82 = (t80 & t81);
    *((unsigned int *)t79) = t82;
    t83 = (t26 + 4);
    t84 = (t63 + 4);
    t85 = (t79 + 4);
    t86 = *((unsigned int *)t83);
    t87 = *((unsigned int *)t84);
    t88 = (t86 | t87);
    *((unsigned int *)t85) = t88;
    t89 = *((unsigned int *)t85);
    t90 = (t89 != 0);
    if (t90 == 1)
        goto LAB69;

LAB70:
LAB71:    t110 = (t79 + 4);
    t111 = *((unsigned int *)t110);
    t112 = (~(t111));
    t113 = *((unsigned int *)t79);
    t114 = (t113 & t112);
    t115 = (t114 != 0);
    if (t115 > 0)
        goto LAB72;

LAB73:    xsi_set_current_line(50, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1552);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB74:    goto LAB39;

LAB13:    xsi_set_current_line(52, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t0 + 1644);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    goto LAB39;

LAB15:    xsi_set_current_line(53, ng0);
    t3 = (t0 + 680U);
    t4 = *((char **)t3);
    t3 = (t0 + 772U);
    t7 = *((char **)t3);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t7);
    t13 = (t11 & t12);
    *((unsigned int *)t10) = t13;
    t3 = (t4 + 4);
    t8 = (t7 + 4);
    t17 = (t10 + 4);
    t14 = *((unsigned int *)t3);
    t15 = *((unsigned int *)t8);
    t16 = (t14 | t15);
    *((unsigned int *)t17) = t16;
    t20 = *((unsigned int *)t17);
    t21 = (t20 != 0);
    if (t21 == 1)
        goto LAB75;

LAB76:
LAB77:    t40 = (t0 + 1644);
    xsi_vlogvar_assign_value(t40, t10, 0, 0, 32);
    goto LAB39;

LAB17:    xsi_set_current_line(54, ng0);
    t3 = (t0 + 680U);
    t4 = *((char **)t3);
    t3 = (t0 + 772U);
    t7 = *((char **)t3);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t7);
    t13 = (t11 | t12);
    *((unsigned int *)t10) = t13;
    t3 = (t4 + 4);
    t8 = (t7 + 4);
    t17 = (t10 + 4);
    t14 = *((unsigned int *)t3);
    t15 = *((unsigned int *)t8);
    t16 = (t14 | t15);
    *((unsigned int *)t17) = t16;
    t20 = *((unsigned int *)t17);
    t21 = (t20 != 0);
    if (t21 == 1)
        goto LAB78;

LAB79:
LAB80:    t40 = (t0 + 1644);
    xsi_vlogvar_assign_value(t40, t10, 0, 0, 32);
    goto LAB39;

LAB19:    xsi_set_current_line(55, ng0);
    t3 = (t0 + 680U);
    t4 = *((char **)t3);
    t3 = (t0 + 772U);
    t7 = *((char **)t3);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    *((unsigned int *)t10) = t13;
    t3 = (t4 + 4);
    t8 = (t7 + 4);
    t17 = (t10 + 4);
    t14 = *((unsigned int *)t3);
    t15 = *((unsigned int *)t8);
    t16 = (t14 | t15);
    *((unsigned int *)t17) = t16;
    t20 = *((unsigned int *)t17);
    t21 = (t20 != 0);
    if (t21 == 1)
        goto LAB81;

LAB82:
LAB83:    t18 = (t0 + 1644);
    xsi_vlogvar_assign_value(t18, t10, 0, 0, 32);
    goto LAB39;

LAB21:    xsi_set_current_line(56, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t0 + 1644);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    goto LAB39;

LAB23:    xsi_set_current_line(57, ng0);
    t3 = (t0 + 680U);
    t4 = *((char **)t3);
    t3 = (t0 + 1644);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 32);
    goto LAB39;

LAB25:    xsi_set_current_line(58, ng0);
    t3 = (t0 + 772U);
    t4 = *((char **)t3);
    t3 = (t0 + 1644);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 32);
    goto LAB39;

LAB27:    xsi_set_current_line(59, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t0 + 680U);
    t7 = *((char **)t4);
    memset(t19, 0, 8);
    t4 = (t19 + 4);
    t8 = (t7 + 4);
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 0);
    *((unsigned int *)t19) = t12;
    t13 = *((unsigned int *)t8);
    t14 = (t13 >> 0);
    *((unsigned int *)t4) = t14;
    t15 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t15 & 2147483647U);
    t16 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t16 & 2147483647U);
    xsi_vlogtype_concat(t10, 32, 32, 2U, t19, 31, t3, 1);
    t17 = (t0 + 1644);
    xsi_vlogvar_assign_value(t17, t10, 0, 0, 32);
    goto LAB39;

LAB29:    xsi_set_current_line(60, ng0);
    t3 = (t0 + 680U);
    t4 = *((char **)t3);
    memset(t19, 0, 8);
    t3 = (t19 + 4);
    t7 = (t4 + 4);
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 1);
    *((unsigned int *)t19) = t12;
    t13 = *((unsigned int *)t7);
    t14 = (t13 >> 1);
    *((unsigned int *)t3) = t14;
    t15 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t15 & 2147483647U);
    t16 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t16 & 2147483647U);
    t8 = ((char*)((ng1)));
    xsi_vlogtype_concat(t10, 32, 32, 2U, t8, 1, t19, 31);
    t17 = (t0 + 1644);
    xsi_vlogvar_assign_value(t17, t10, 0, 0, 32);
    goto LAB39;

LAB31:    xsi_set_current_line(61, ng0);
    t3 = (t0 + 680U);
    t4 = *((char **)t3);
    memset(t19, 0, 8);
    t3 = (t19 + 4);
    t7 = (t4 + 4);
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 31);
    t13 = (t12 & 1);
    *((unsigned int *)t19) = t13;
    t14 = *((unsigned int *)t7);
    t15 = (t14 >> 31);
    t16 = (t15 & 1);
    *((unsigned int *)t3) = t16;
    t8 = (t0 + 680U);
    t17 = *((char **)t8);
    memset(t26, 0, 8);
    t8 = (t26 + 4);
    t18 = (t17 + 4);
    t20 = *((unsigned int *)t17);
    t21 = (t20 >> 0);
    *((unsigned int *)t26) = t21;
    t22 = *((unsigned int *)t18);
    t23 = (t22 >> 0);
    *((unsigned int *)t8) = t23;
    t24 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t24 & 2147483647U);
    t25 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t25 & 2147483647U);
    xsi_vlogtype_concat(t10, 32, 32, 2U, t26, 31, t19, 1);
    t27 = (t0 + 1644);
    xsi_vlogvar_assign_value(t27, t10, 0, 0, 32);
    goto LAB39;

LAB33:    xsi_set_current_line(62, ng0);
    t3 = (t0 + 680U);
    t4 = *((char **)t3);
    memset(t19, 0, 8);
    t3 = (t19 + 4);
    t7 = (t4 + 4);
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 1);
    *((unsigned int *)t19) = t12;
    t13 = *((unsigned int *)t7);
    t14 = (t13 >> 1);
    *((unsigned int *)t3) = t14;
    t15 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t15 & 2147483647U);
    t16 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t16 & 2147483647U);
    t8 = (t0 + 680U);
    t17 = *((char **)t8);
    memset(t26, 0, 8);
    t8 = (t26 + 4);
    t18 = (t17 + 4);
    t20 = *((unsigned int *)t17);
    t21 = (t20 >> 0);
    t22 = (t21 & 1);
    *((unsigned int *)t26) = t22;
    t23 = *((unsigned int *)t18);
    t24 = (t23 >> 0);
    t25 = (t24 & 1);
    *((unsigned int *)t8) = t25;
    xsi_vlogtype_concat(t10, 32, 32, 2U, t26, 1, t19, 31);
    t27 = (t0 + 1644);
    xsi_vlogvar_assign_value(t27, t10, 0, 0, 32);
    goto LAB39;

LAB35:    xsi_set_current_line(63, ng0);
    t3 = (t0 + 680U);
    t4 = *((char **)t3);
    t3 = ((char*)((ng6)));
    memset(t10, 0, 8);
    xsi_vlog_unsigned_add(t10, 32, t4, 32, t3, 32);
    t7 = (t0 + 1644);
    xsi_vlogvar_assign_value(t7, t10, 0, 0, 32);
    goto LAB39;

LAB37:    xsi_set_current_line(64, ng0);
    t3 = (t0 + 680U);
    t4 = *((char **)t3);
    memset(t10, 0, 8);
    t3 = (t10 + 4);
    t7 = (t4 + 4);
    t11 = *((unsigned int *)t4);
    t12 = (~(t11));
    *((unsigned int *)t10) = t12;
    *((unsigned int *)t3) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB85;

LAB84:    t20 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t20 & 4294967295U);
    t21 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t21 & 4294967295U);
    t8 = (t0 + 1644);
    xsi_vlogvar_assign_value(t8, t10, 0, 0, 32);
    goto LAB39;

LAB43:    t40 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t40) = 1;
    goto LAB44;

LAB46:    *((unsigned int *)t63) = 1;
    goto LAB48;

LAB47:    t78 = (t63 + 4);
    *((unsigned int *)t63) = 1;
    *((unsigned int *)t78) = 1;
    goto LAB48;

LAB49:    t91 = *((unsigned int *)t79);
    t92 = *((unsigned int *)t85);
    *((unsigned int *)t79) = (t91 | t92);
    t93 = (t26 + 4);
    t94 = (t63 + 4);
    t95 = *((unsigned int *)t26);
    t96 = (~(t95));
    t97 = *((unsigned int *)t93);
    t98 = (~(t97));
    t99 = *((unsigned int *)t63);
    t100 = (~(t99));
    t101 = *((unsigned int *)t94);
    t102 = (~(t101));
    t6 = (t96 & t98);
    t103 = (t100 & t102);
    t104 = (~(t6));
    t105 = (~(t103));
    t106 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t106 & t104);
    t107 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t107 & t105);
    t108 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t108 & t104);
    t109 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t109 & t105);
    goto LAB51;

LAB52:    xsi_set_current_line(42, ng0);
    t116 = ((char*)((ng3)));
    t117 = (t0 + 1552);
    xsi_vlogvar_assign_value(t117, t116, 0, 0, 1);
    goto LAB54;

LAB57:    t8 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB59;

LAB58:    *((unsigned int *)t10) = 1;
    goto LAB59;

LAB62:    *((unsigned int *)t26) = 1;
    goto LAB64;

LAB63:    t40 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t40) = 1;
    goto LAB64;

LAB66:    *((unsigned int *)t63) = 1;
    goto LAB68;

LAB67:    t78 = (t63 + 4);
    *((unsigned int *)t63) = 1;
    *((unsigned int *)t78) = 1;
    goto LAB68;

LAB69:    t91 = *((unsigned int *)t79);
    t92 = *((unsigned int *)t85);
    *((unsigned int *)t79) = (t91 | t92);
    t93 = (t26 + 4);
    t94 = (t63 + 4);
    t95 = *((unsigned int *)t26);
    t96 = (~(t95));
    t97 = *((unsigned int *)t93);
    t98 = (~(t97));
    t99 = *((unsigned int *)t63);
    t100 = (~(t99));
    t101 = *((unsigned int *)t94);
    t102 = (~(t101));
    t6 = (t96 & t98);
    t103 = (t100 & t102);
    t104 = (~(t6));
    t105 = (~(t103));
    t106 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t106 & t104);
    t107 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t107 & t105);
    t108 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t108 & t104);
    t109 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t109 & t105);
    goto LAB71;

LAB72:    xsi_set_current_line(49, ng0);
    t116 = ((char*)((ng3)));
    t117 = (t0 + 1552);
    xsi_vlogvar_assign_value(t117, t116, 0, 0, 1);
    goto LAB74;

LAB75:    t22 = *((unsigned int *)t10);
    t23 = *((unsigned int *)t17);
    *((unsigned int *)t10) = (t22 | t23);
    t18 = (t4 + 4);
    t27 = (t7 + 4);
    t24 = *((unsigned int *)t4);
    t25 = (~(t24));
    t28 = *((unsigned int *)t18);
    t29 = (~(t28));
    t30 = *((unsigned int *)t7);
    t31 = (~(t30));
    t32 = *((unsigned int *)t27);
    t33 = (~(t32));
    t103 = (t25 & t29);
    t118 = (t31 & t33);
    t34 = (~(t103));
    t35 = (~(t118));
    t36 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t36 & t34);
    t37 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t37 & t35);
    t38 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t38 & t34);
    t39 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t39 & t35);
    goto LAB77;

LAB78:    t22 = *((unsigned int *)t10);
    t23 = *((unsigned int *)t17);
    *((unsigned int *)t10) = (t22 | t23);
    t18 = (t4 + 4);
    t27 = (t7 + 4);
    t24 = *((unsigned int *)t18);
    t25 = (~(t24));
    t28 = *((unsigned int *)t4);
    t103 = (t28 & t25);
    t29 = *((unsigned int *)t27);
    t30 = (~(t29));
    t31 = *((unsigned int *)t7);
    t118 = (t31 & t30);
    t32 = (~(t103));
    t33 = (~(t118));
    t34 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t34 & t32);
    t35 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t35 & t33);
    goto LAB80;

LAB81:    t22 = *((unsigned int *)t10);
    t23 = *((unsigned int *)t17);
    *((unsigned int *)t10) = (t22 | t23);
    goto LAB83;

LAB85:    t13 = *((unsigned int *)t10);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t10) = (t13 | t14);
    t15 = *((unsigned int *)t3);
    t16 = *((unsigned int *)t7);
    *((unsigned int *)t3) = (t15 | t16);
    goto LAB84;

LAB89:    *((unsigned int *)t26) = 1;
    goto LAB92;

LAB91:    t17 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB92;

LAB93:    t27 = (t0 + 864U);
    t40 = *((char **)t27);
    t27 = ((char*)((ng19)));
    memset(t43, 0, 8);
    if (*((unsigned int *)t40) != *((unsigned int *)t27))
        goto LAB98;

LAB96:    t41 = (t40 + 4);
    t42 = (t27 + 4);
    if (*((unsigned int *)t41) != *((unsigned int *)t42))
        goto LAB98;

LAB97:    *((unsigned int *)t43) = 1;

LAB98:    memset(t54, 0, 8);
    t44 = (t43 + 4);
    t23 = *((unsigned int *)t44);
    t24 = (~(t23));
    t25 = *((unsigned int *)t43);
    t28 = (t25 & t24);
    t29 = (t28 & 1U);
    if (t29 != 0)
        goto LAB99;

LAB100:    if (*((unsigned int *)t44) != 0)
        goto LAB101;

LAB102:    t30 = *((unsigned int *)t26);
    t31 = *((unsigned int *)t54);
    t32 = (t30 | t31);
    *((unsigned int *)t63) = t32;
    t52 = (t26 + 4);
    t53 = (t54 + 4);
    t55 = (t63 + 4);
    t33 = *((unsigned int *)t52);
    t34 = *((unsigned int *)t53);
    t35 = (t33 | t34);
    *((unsigned int *)t55) = t35;
    t36 = *((unsigned int *)t55);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB103;

LAB104:
LAB105:    goto LAB95;

LAB99:    *((unsigned int *)t54) = 1;
    goto LAB102;

LAB101:    t51 = (t54 + 4);
    *((unsigned int *)t54) = 1;
    *((unsigned int *)t51) = 1;
    goto LAB102;

LAB103:    t38 = *((unsigned int *)t63);
    t39 = *((unsigned int *)t55);
    *((unsigned int *)t63) = (t38 | t39);
    t56 = (t26 + 4);
    t64 = (t54 + 4);
    t45 = *((unsigned int *)t56);
    t46 = (~(t45));
    t47 = *((unsigned int *)t26);
    t6 = (t47 & t46);
    t48 = *((unsigned int *)t64);
    t49 = (~(t48));
    t50 = *((unsigned int *)t54);
    t103 = (t50 & t49);
    t57 = (~(t6));
    t58 = (~(t103));
    t59 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t59 & t57);
    t60 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t60 & t58);
    goto LAB105;

LAB106:    *((unsigned int *)t10) = 1;
    goto LAB109;

LAB110:    xsi_set_current_line(68, ng0);

LAB113:    xsi_set_current_line(69, ng0);
    t84 = (t0 + 1644);
    t85 = (t84 + 36U);
    t93 = *((char **)t85);
    t94 = ((char*)((ng2)));
    memset(t120, 0, 8);
    t110 = (t93 + 4);
    t116 = (t94 + 4);
    t74 = *((unsigned int *)t93);
    t75 = *((unsigned int *)t94);
    t76 = (t74 ^ t75);
    t77 = *((unsigned int *)t110);
    t80 = *((unsigned int *)t116);
    t81 = (t77 ^ t80);
    t82 = (t76 | t81);
    t86 = *((unsigned int *)t110);
    t87 = *((unsigned int *)t116);
    t88 = (t86 | t87);
    t89 = (~(t88));
    t90 = (t82 & t89);
    if (t90 != 0)
        goto LAB117;

LAB114:    if (t88 != 0)
        goto LAB116;

LAB115:    *((unsigned int *)t120) = 1;

LAB117:    memset(t119, 0, 8);
    t121 = (t120 + 4);
    t91 = *((unsigned int *)t121);
    t92 = (~(t91));
    t95 = *((unsigned int *)t120);
    t96 = (t95 & t92);
    t97 = (t96 & 1U);
    if (t97 != 0)
        goto LAB118;

LAB119:    if (*((unsigned int *)t121) != 0)
        goto LAB120;

LAB121:    t123 = (t119 + 4);
    t98 = *((unsigned int *)t119);
    t99 = *((unsigned int *)t123);
    t100 = (t98 || t99);
    if (t100 > 0)
        goto LAB122;

LAB123:    t101 = *((unsigned int *)t119);
    t102 = (~(t101));
    t104 = *((unsigned int *)t123);
    t105 = (t102 || t104);
    if (t105 > 0)
        goto LAB124;

LAB125:    if (*((unsigned int *)t123) > 0)
        goto LAB126;

LAB127:    if (*((unsigned int *)t119) > 0)
        goto LAB128;

LAB129:    memcpy(t79, t125, 8);

LAB130:    t126 = (t0 + 1276);
    xsi_vlogvar_assign_value(t126, t79, 0, 0, 1);
    xsi_set_current_line(70, ng0);
    t2 = (t0 + 1644);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    memset(t26, 0, 8);
    t7 = (t26 + 4);
    t8 = (t4 + 4);
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 31);
    t13 = (t12 & 1);
    *((unsigned int *)t26) = t13;
    t14 = *((unsigned int *)t8);
    t15 = (t14 >> 31);
    t16 = (t15 & 1);
    *((unsigned int *)t7) = t16;
    t17 = ((char*)((ng3)));
    memset(t43, 0, 8);
    t18 = (t26 + 4);
    t27 = (t17 + 4);
    t20 = *((unsigned int *)t26);
    t21 = *((unsigned int *)t17);
    t22 = (t20 ^ t21);
    t23 = *((unsigned int *)t18);
    t24 = *((unsigned int *)t27);
    t25 = (t23 ^ t24);
    t28 = (t22 | t25);
    t29 = *((unsigned int *)t18);
    t30 = *((unsigned int *)t27);
    t31 = (t29 | t30);
    t32 = (~(t31));
    t33 = (t28 & t32);
    if (t33 != 0)
        goto LAB134;

LAB131:    if (t31 != 0)
        goto LAB133;

LAB132:    *((unsigned int *)t43) = 1;

LAB134:    memset(t19, 0, 8);
    t41 = (t43 + 4);
    t34 = *((unsigned int *)t41);
    t35 = (~(t34));
    t36 = *((unsigned int *)t43);
    t37 = (t36 & t35);
    t38 = (t37 & 1U);
    if (t38 != 0)
        goto LAB135;

LAB136:    if (*((unsigned int *)t41) != 0)
        goto LAB137;

LAB138:    t44 = (t19 + 4);
    t39 = *((unsigned int *)t19);
    t45 = *((unsigned int *)t44);
    t46 = (t39 || t45);
    if (t46 > 0)
        goto LAB139;

LAB140:    t47 = *((unsigned int *)t19);
    t48 = (~(t47));
    t49 = *((unsigned int *)t44);
    t50 = (t48 || t49);
    if (t50 > 0)
        goto LAB141;

LAB142:    if (*((unsigned int *)t44) > 0)
        goto LAB143;

LAB144:    if (*((unsigned int *)t19) > 0)
        goto LAB145;

LAB146:    memcpy(t10, t52, 8);

LAB147:    t53 = (t0 + 1368);
    xsi_vlogvar_assign_value(t53, t10, 0, 0, 1);
    xsi_set_current_line(71, ng0);
    t2 = (t0 + 1644);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t7 = (t0 + 1092);
    xsi_vlogvar_wait_assign_value(t7, t4, 0, 0, 32, 6000LL);
    xsi_set_current_line(72, ng0);
    t2 = (t0 + 1552);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t7 = (t0 + 1460);
    t8 = (t7 + 36U);
    t17 = *((char **)t8);
    t18 = (t0 + 1368);
    t27 = (t18 + 36U);
    t40 = *((char **)t27);
    t41 = (t0 + 1276);
    t42 = (t41 + 36U);
    t44 = *((char **)t42);
    xsi_vlogtype_concat(t10, 4, 4, 4U, t44, 1, t40, 1, t17, 1, t4, 1);
    t51 = (t0 + 1184);
    xsi_vlogvar_wait_assign_value(t51, t10, 0, 0, 4, 6000LL);
    goto LAB112;

LAB116:    t117 = (t120 + 4);
    *((unsigned int *)t120) = 1;
    *((unsigned int *)t117) = 1;
    goto LAB117;

LAB118:    *((unsigned int *)t119) = 1;
    goto LAB121;

LAB120:    t122 = (t119 + 4);
    *((unsigned int *)t119) = 1;
    *((unsigned int *)t122) = 1;
    goto LAB121;

LAB122:    t124 = ((char*)((ng3)));
    goto LAB123;

LAB124:    t125 = ((char*)((ng1)));
    goto LAB125;

LAB126:    xsi_vlog_unsigned_bit_combine(t79, 1, t124, 1, t125, 1);
    goto LAB130;

LAB128:    memcpy(t79, t124, 8);
    goto LAB130;

LAB133:    t40 = (t43 + 4);
    *((unsigned int *)t43) = 1;
    *((unsigned int *)t40) = 1;
    goto LAB134;

LAB135:    *((unsigned int *)t19) = 1;
    goto LAB138;

LAB137:    t42 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t42) = 1;
    goto LAB138;

LAB139:    t51 = ((char*)((ng3)));
    goto LAB140;

LAB141:    t52 = ((char*)((ng1)));
    goto LAB142;

LAB143:    xsi_vlog_unsigned_bit_combine(t10, 1, t51, 1, t52, 1);
    goto LAB147;

LAB145:    memcpy(t10, t51, 8);
    goto LAB147;

}


extern void work_m_00000000000857308701_0886308060_init()
{
	static char *pe[] = {(void *)Always_33_0};
	xsi_register_didat("work_m_00000000000857308701_0886308060", "isim/Data_Subsystem_isim_beh.exe.sim/work/m_00000000000857308701_0886308060.didat");
	xsi_register_executes(pe);
}

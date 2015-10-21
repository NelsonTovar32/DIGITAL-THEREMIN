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

/* This file is designed for use with ISim build 0x8ef4fb42 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "D:/DIGITAL-ISE/SENSOR_HCSR04 - copia/DIGPOT.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};
static unsigned int ng3[] = {100U, 0U};
static unsigned int ng4[] = {127U, 0U};
static unsigned int ng5[] = {0U, 0U};
static unsigned int ng6[] = {124U, 0U};



static int sp_pulse(char *t1, char *t2)
{
    char t9[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t10;
    char *t11;
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
    char *t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;

LAB0:    t0 = 1;
    t3 = (t2 + 28U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 484);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(83, ng0);

LAB5:    xsi_set_current_line(84, ng0);
    t5 = (t1 + 1728);
    t6 = (t5 + 36U);
    t7 = *((char **)t6);
    t8 = ((char*)((ng1)));
    memset(t9, 0, 8);
    t10 = (t7 + 4);
    t11 = (t8 + 4);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = *((unsigned int *)t10);
    t16 = *((unsigned int *)t11);
    t17 = (t15 ^ t16);
    t18 = (t14 | t17);
    t19 = *((unsigned int *)t10);
    t20 = *((unsigned int *)t11);
    t21 = (t19 | t20);
    t22 = (~(t21));
    t23 = (t18 & t22);
    if (t23 != 0)
        goto LAB9;

LAB6:    if (t21 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t9) = 1;

LAB9:    t25 = (t9 + 4);
    t26 = *((unsigned int *)t25);
    t27 = (~(t26));
    t28 = *((unsigned int *)t9);
    t29 = (t28 & t27);
    t30 = (t29 != 0);
    if (t30 > 0)
        goto LAB10;

LAB11:
LAB12:
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 28U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB8:    t24 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t24) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(85, ng0);

LAB13:    xsi_set_current_line(86, ng0);
    t31 = ((char*)((ng1)));
    t32 = (t1 + 1912);
    xsi_vlogvar_assign_value(t32, t31, 0, 0, 1);
    goto LAB12;

}

static void Always_37_0(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;

LAB0:    t1 = (t0 + 2436U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(37, ng0);
    t2 = (t0 + 2776);
    *((int *)t2) = 1;
    t3 = (t0 + 2464);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(38, ng0);

LAB5:    xsi_set_current_line(39, ng0);
    t5 = (t0 + 856U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t5 = (t6 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t5) == 0)
        goto LAB6;

LAB8:    t12 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t12) = 1;

LAB9:    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (~(t14));
    t16 = *((unsigned int *)t4);
    t17 = (t16 & t15);
    t18 = (t17 != 0);
    if (t18 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(43, ng0);
    t2 = (t0 + 856U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB14;

LAB15:
LAB16:
LAB12:    goto LAB2;

LAB6:    *((unsigned int *)t4) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(40, ng0);

LAB13:    xsi_set_current_line(41, ng0);
    t19 = ((char*)((ng1)));
    t20 = (t0 + 1268);
    xsi_vlogvar_assign_value(t20, t19, 0, 0, 1);
    goto LAB12;

LAB14:    xsi_set_current_line(44, ng0);

LAB17:    xsi_set_current_line(45, ng0);
    t5 = ((char*)((ng2)));
    t6 = (t0 + 1268);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 1);
    goto LAB16;

}

static void Always_49_1(char *t0)
{
    char t6[8];
    char t10[8];
    char t24[8];
    char t40[8];
    char t48[8];
    char t90[8];
    char t104[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    char *t9;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    char *t23;
    char *t25;
    char *t26;
    unsigned int t27;
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
    char *t39;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    char *t47;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    char *t53;
    char *t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    char *t62;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    int t72;
    int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    char *t86;
    char *t87;
    char *t88;
    char *t89;
    char *t91;
    char *t92;
    char *t93;
    char *t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    char *t100;
    char *t101;
    char *t102;
    char *t103;
    char *t105;

LAB0:    t1 = (t0 + 2580U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 2784);
    *((int *)t2) = 1;
    t3 = (t0 + 2608);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(50, ng0);

LAB5:    xsi_set_current_line(51, ng0);
    t4 = (t0 + 1040U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB7;

LAB6:    t8 = (t4 + 4);
    if (*((unsigned int *)t8) != 0)
        goto LAB7;

LAB10:    if (*((unsigned int *)t5) < *((unsigned int *)t4))
        goto LAB8;

LAB9:    memset(t10, 0, 8);
    t11 = (t6 + 4);
    t12 = *((unsigned int *)t11);
    t13 = (~(t12));
    t14 = *((unsigned int *)t6);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t11) != 0)
        goto LAB13;

LAB14:    t18 = (t10 + 4);
    t19 = *((unsigned int *)t10);
    t20 = *((unsigned int *)t18);
    t21 = (t19 || t20);
    if (t21 > 0)
        goto LAB15;

LAB16:    memcpy(t48, t10, 8);

LAB17:    t80 = (t48 + 4);
    t81 = *((unsigned int *)t80);
    t82 = (~(t81));
    t83 = *((unsigned int *)t48);
    t84 = (t83 & t82);
    t85 = (t84 != 0);
    if (t85 > 0)
        goto LAB29;

LAB30:    xsi_set_current_line(64, ng0);
    t2 = (t0 + 1040U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    if (*((unsigned int *)t4) != 0)
        goto LAB52;

LAB51:    t5 = (t2 + 4);
    if (*((unsigned int *)t5) != 0)
        goto LAB52;

LAB55:    if (*((unsigned int *)t3) < *((unsigned int *)t2))
        goto LAB54;

LAB53:    *((unsigned int *)t6) = 1;

LAB54:    memset(t10, 0, 8);
    t8 = (t6 + 4);
    t12 = *((unsigned int *)t8);
    t13 = (~(t12));
    t14 = *((unsigned int *)t6);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB56;

LAB57:    if (*((unsigned int *)t8) != 0)
        goto LAB58;

LAB59:    t11 = (t10 + 4);
    t19 = *((unsigned int *)t10);
    t20 = *((unsigned int *)t11);
    t21 = (t19 || t20);
    if (t21 > 0)
        goto LAB60;

LAB61:    memcpy(t48, t10, 8);

LAB62:    t62 = (t48 + 4);
    t81 = *((unsigned int *)t62);
    t82 = (~(t81));
    t83 = *((unsigned int *)t48);
    t84 = (t83 & t82);
    t85 = (t84 != 0);
    if (t85 > 0)
        goto LAB74;

LAB75:
LAB76:
LAB31:    goto LAB2;

LAB7:    t9 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB9;

LAB8:    *((unsigned int *)t6) = 1;
    goto LAB9;

LAB11:    *((unsigned int *)t10) = 1;
    goto LAB14;

LAB13:    t17 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB14;

LAB15:    t22 = (t0 + 856U);
    t23 = *((char **)t22);
    t22 = ((char*)((ng1)));
    memset(t24, 0, 8);
    t25 = (t23 + 4);
    t26 = (t22 + 4);
    t27 = *((unsigned int *)t23);
    t28 = *((unsigned int *)t22);
    t29 = (t27 ^ t28);
    t30 = *((unsigned int *)t25);
    t31 = *((unsigned int *)t26);
    t32 = (t30 ^ t31);
    t33 = (t29 | t32);
    t34 = *((unsigned int *)t25);
    t35 = *((unsigned int *)t26);
    t36 = (t34 | t35);
    t37 = (~(t36));
    t38 = (t33 & t37);
    if (t38 != 0)
        goto LAB21;

LAB18:    if (t36 != 0)
        goto LAB20;

LAB19:    *((unsigned int *)t24) = 1;

LAB21:    memset(t40, 0, 8);
    t41 = (t24 + 4);
    t42 = *((unsigned int *)t41);
    t43 = (~(t42));
    t44 = *((unsigned int *)t24);
    t45 = (t44 & t43);
    t46 = (t45 & 1U);
    if (t46 != 0)
        goto LAB22;

LAB23:    if (*((unsigned int *)t41) != 0)
        goto LAB24;

LAB25:    t49 = *((unsigned int *)t10);
    t50 = *((unsigned int *)t40);
    t51 = (t49 & t50);
    *((unsigned int *)t48) = t51;
    t52 = (t10 + 4);
    t53 = (t40 + 4);
    t54 = (t48 + 4);
    t55 = *((unsigned int *)t52);
    t56 = *((unsigned int *)t53);
    t57 = (t55 | t56);
    *((unsigned int *)t54) = t57;
    t58 = *((unsigned int *)t54);
    t59 = (t58 != 0);
    if (t59 == 1)
        goto LAB26;

LAB27:
LAB28:    goto LAB17;

LAB20:    t39 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t39) = 1;
    goto LAB21;

LAB22:    *((unsigned int *)t40) = 1;
    goto LAB25;

LAB24:    t47 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t47) = 1;
    goto LAB25;

LAB26:    t60 = *((unsigned int *)t48);
    t61 = *((unsigned int *)t54);
    *((unsigned int *)t48) = (t60 | t61);
    t62 = (t10 + 4);
    t63 = (t40 + 4);
    t64 = *((unsigned int *)t10);
    t65 = (~(t64));
    t66 = *((unsigned int *)t62);
    t67 = (~(t66));
    t68 = *((unsigned int *)t40);
    t69 = (~(t68));
    t70 = *((unsigned int *)t63);
    t71 = (~(t70));
    t72 = (t65 & t67);
    t73 = (t69 & t71);
    t74 = (~(t72));
    t75 = (~(t73));
    t76 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t76 & t74);
    t77 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t77 & t75);
    t78 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t78 & t74);
    t79 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t79 & t75);
    goto LAB28;

LAB29:    xsi_set_current_line(52, ng0);

LAB32:    xsi_set_current_line(53, ng0);
    t86 = (t0 + 1040U);
    t87 = *((char **)t86);
    t86 = (t0 + 1544);
    t88 = (t86 + 36U);
    t89 = *((char **)t88);
    memset(t90, 0, 8);
    t91 = (t87 + 4);
    if (*((unsigned int *)t91) != 0)
        goto LAB34;

LAB33:    t92 = (t89 + 4);
    if (*((unsigned int *)t92) != 0)
        goto LAB34;

LAB37:    if (*((unsigned int *)t87) < *((unsigned int *)t89))
        goto LAB36;

LAB35:    *((unsigned int *)t90) = 1;

LAB36:    t94 = (t90 + 4);
    t95 = *((unsigned int *)t94);
    t96 = (~(t95));
    t97 = *((unsigned int *)t90);
    t98 = (t97 & t96);
    t99 = (t98 != 0);
    if (t99 > 0)
        goto LAB38;

LAB39:    xsi_set_current_line(58, ng0);
    t2 = (t0 + 1040U);
    t3 = *((char **)t2);
    t2 = (t0 + 1544);
    t4 = (t2 + 36U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t7 = (t3 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB43;

LAB42:    t8 = (t5 + 4);
    if (*((unsigned int *)t8) != 0)
        goto LAB43;

LAB46:    if (*((unsigned int *)t3) < *((unsigned int *)t5))
        goto LAB44;

LAB45:    t11 = (t6 + 4);
    t12 = *((unsigned int *)t11);
    t13 = (~(t12));
    t14 = *((unsigned int *)t6);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB47;

LAB48:
LAB49:
LAB40:    goto LAB31;

LAB34:    t93 = (t90 + 4);
    *((unsigned int *)t90) = 1;
    *((unsigned int *)t93) = 1;
    goto LAB36;

LAB38:    xsi_set_current_line(54, ng0);

LAB41:    xsi_set_current_line(55, ng0);
    t100 = (t0 + 1040U);
    t101 = *((char **)t100);
    t100 = (t0 + 1544);
    t102 = (t100 + 36U);
    t103 = *((char **)t102);
    memset(t104, 0, 8);
    xsi_vlog_unsigned_minus(t104, 7, t101, 7, t103, 7);
    t105 = (t0 + 1636);
    xsi_vlogvar_assign_value(t105, t104, 0, 0, 7);
    xsi_set_current_line(56, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1452);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB40;

LAB43:    t9 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB45;

LAB44:    *((unsigned int *)t6) = 1;
    goto LAB45;

LAB47:    xsi_set_current_line(59, ng0);

LAB50:    xsi_set_current_line(60, ng0);
    t17 = (t0 + 1544);
    t18 = (t17 + 36U);
    t22 = *((char **)t18);
    t23 = (t0 + 1040U);
    t25 = *((char **)t23);
    memset(t10, 0, 8);
    xsi_vlog_unsigned_minus(t10, 7, t22, 7, t25, 7);
    t23 = (t0 + 1636);
    xsi_vlogvar_assign_value(t23, t10, 0, 0, 7);
    xsi_set_current_line(61, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1452);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB49;

LAB52:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB54;

LAB56:    *((unsigned int *)t10) = 1;
    goto LAB59;

LAB58:    t9 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB59;

LAB60:    t17 = (t0 + 856U);
    t18 = *((char **)t17);
    t17 = ((char*)((ng1)));
    memset(t24, 0, 8);
    t22 = (t18 + 4);
    t23 = (t17 + 4);
    t27 = *((unsigned int *)t18);
    t28 = *((unsigned int *)t17);
    t29 = (t27 ^ t28);
    t30 = *((unsigned int *)t22);
    t31 = *((unsigned int *)t23);
    t32 = (t30 ^ t31);
    t33 = (t29 | t32);
    t34 = *((unsigned int *)t22);
    t35 = *((unsigned int *)t23);
    t36 = (t34 | t35);
    t37 = (~(t36));
    t38 = (t33 & t37);
    if (t38 != 0)
        goto LAB66;

LAB63:    if (t36 != 0)
        goto LAB65;

LAB64:    *((unsigned int *)t24) = 1;

LAB66:    memset(t40, 0, 8);
    t26 = (t24 + 4);
    t42 = *((unsigned int *)t26);
    t43 = (~(t42));
    t44 = *((unsigned int *)t24);
    t45 = (t44 & t43);
    t46 = (t45 & 1U);
    if (t46 != 0)
        goto LAB67;

LAB68:    if (*((unsigned int *)t26) != 0)
        goto LAB69;

LAB70:    t49 = *((unsigned int *)t10);
    t50 = *((unsigned int *)t40);
    t51 = (t49 & t50);
    *((unsigned int *)t48) = t51;
    t41 = (t10 + 4);
    t47 = (t40 + 4);
    t52 = (t48 + 4);
    t55 = *((unsigned int *)t41);
    t56 = *((unsigned int *)t47);
    t57 = (t55 | t56);
    *((unsigned int *)t52) = t57;
    t58 = *((unsigned int *)t52);
    t59 = (t58 != 0);
    if (t59 == 1)
        goto LAB71;

LAB72:
LAB73:    goto LAB62;

LAB65:    t25 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB66;

LAB67:    *((unsigned int *)t40) = 1;
    goto LAB70;

LAB69:    t39 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t39) = 1;
    goto LAB70;

LAB71:    t60 = *((unsigned int *)t48);
    t61 = *((unsigned int *)t52);
    *((unsigned int *)t48) = (t60 | t61);
    t53 = (t10 + 4);
    t54 = (t40 + 4);
    t64 = *((unsigned int *)t10);
    t65 = (~(t64));
    t66 = *((unsigned int *)t53);
    t67 = (~(t66));
    t68 = *((unsigned int *)t40);
    t69 = (~(t68));
    t70 = *((unsigned int *)t54);
    t71 = (~(t70));
    t72 = (t65 & t67);
    t73 = (t69 & t71);
    t74 = (~(t72));
    t75 = (~(t73));
    t76 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t76 & t74);
    t77 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t77 & t75);
    t78 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t78 & t74);
    t79 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t79 & t75);
    goto LAB73;

LAB74:    xsi_set_current_line(65, ng0);

LAB77:    xsi_set_current_line(66, ng0);
    t63 = (t0 + 1040U);
    t80 = *((char **)t63);
    t63 = ((char*)((ng4)));
    memset(t90, 0, 8);
    t86 = (t80 + 4);
    if (*((unsigned int *)t86) != 0)
        goto LAB79;

LAB78:    t87 = (t63 + 4);
    if (*((unsigned int *)t87) != 0)
        goto LAB79;

LAB82:    if (*((unsigned int *)t80) < *((unsigned int *)t63))
        goto LAB81;

LAB80:    *((unsigned int *)t90) = 1;

LAB81:    t89 = (t90 + 4);
    t95 = *((unsigned int *)t89);
    t96 = (~(t95));
    t97 = *((unsigned int *)t90);
    t98 = (t97 & t96);
    t99 = (t98 != 0);
    if (t99 > 0)
        goto LAB83;

LAB84:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 1040U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng6)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    if (*((unsigned int *)t4) != 0)
        goto LAB88;

LAB87:    t5 = (t2 + 4);
    if (*((unsigned int *)t5) != 0)
        goto LAB88;

LAB91:    if (*((unsigned int *)t3) < *((unsigned int *)t2))
        goto LAB90;

LAB89:    *((unsigned int *)t6) = 1;

LAB90:    t8 = (t6 + 4);
    t12 = *((unsigned int *)t8);
    t13 = (~(t12));
    t14 = *((unsigned int *)t6);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB92;

LAB93:
LAB94:
LAB85:    goto LAB76;

LAB79:    t88 = (t90 + 4);
    *((unsigned int *)t90) = 1;
    *((unsigned int *)t88) = 1;
    goto LAB81;

LAB83:    xsi_set_current_line(67, ng0);

LAB86:    xsi_set_current_line(68, ng0);
    t91 = ((char*)((ng5)));
    t92 = (t0 + 1544);
    xsi_vlogvar_assign_value(t92, t91, 0, 0, 7);
    goto LAB85;

LAB88:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB90;

LAB92:    xsi_set_current_line(71, ng0);

LAB95:    xsi_set_current_line(72, ng0);
    t9 = ((char*)((ng4)));
    t11 = (t0 + 1544);
    xsi_vlogvar_assign_value(t11, t9, 0, 0, 7);
    goto LAB94;

}


extern void work_m_00000000001936981447_1726683468_init()
{
	static char *pe[] = {(void *)Always_37_0,(void *)Always_49_1};
	static char *se[] = {(void *)sp_pulse};
	xsi_register_didat("work_m_00000000001936981447_1726683468", "isim/DIGPOT_isim_beh.exe.sim/work/m_00000000001936981447_1726683468.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}

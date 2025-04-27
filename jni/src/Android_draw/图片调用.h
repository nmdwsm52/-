#include "draw.h"   
#include "枪械图片/问号.h"
#include "枪械图片/拳头.h"
#include "枪械图片/AC_VAL.h"
#include "枪械图片/_98K.h"
#include "枪械图片/AKM.h"
#include "枪械图片/AMR.h"
#include "枪械图片/AUG.h"
#include "枪械图片/AWM.h"
#include "枪械图片/DBS.h"
#include "枪械图片/DP_28.h"
#include "枪械图片/G36C.h"
#include "枪械图片/M1014.h"
#include "枪械图片/M16A4.h"
#include "枪械图片/M200.h"
#include "枪械图片/M24.h"
#include "枪械图片/M249.h"
#include "枪械图片/M416.h"
#include "枪械图片/M417.h"
#include "枪械图片/M762.h"
#include "枪械图片/MG3.h"
#include "枪械图片/MK12.h"
#include "枪械图片/MK14.h"
#include "枪械图片/MK20_H.h"
#include "枪械图片/MK47.h"
#include "枪械图片/MP5K.h"
#include "枪械图片/Mini14.h"
#include "枪械图片/P18C手枪.h"
#include "枪械图片/P1911手枪.h"
#include "枪械图片/P90.h"
#include "枪械图片/P92手枪.h"
#include "枪械图片/QBU.h"
#include "枪械图片/QBZ.h"
#include "枪械图片/R45手枪.h"
#include "枪械图片/S12K.h"
#include "枪械图片/S1897.h"
#include "枪械图片/S686.h"
#include "枪械图片/SCAR_L.h"
#include "枪械图片/SKS.h"
#include "枪械图片/SLR.h"
#include "枪械图片/UMP45.h"
#include "枪械图片/UZI.h"
#include "枪械图片/VSS.h"
#include "枪械图片/Win94.h"
#include "枪械图片/信号枪.h"
#include "枪械图片/十字弩.h"
#include "枪械图片/左轮手枪.h"
#include "枪械图片/平底锅.h"
#include "枪械图片/手榴弹.h"
#include "枪械图片/撬棍.h"
#include "枪械图片/汤姆逊.h"
#include "枪械图片/沙漠之鹰.h"
#include "枪械图片/烟雾弹.h"
#include "枪械图片/燃烧瓶.h"
#include "枪械图片/爆炸猎弓.h"
#include "枪械图片/狗砸.h"
#include "枪械图片/短管霰弹.h"
#include "枪械图片/砍刀.h"
#include "枪械图片/维克托.h"
#include "枪械图片/莫辛纳甘.h"
#include "枪械图片/蜜獾.h"
#include "枪械图片/蝎式手枪.h"
#include "枪械图片/野牛.h"
#include "枪械图片/镰刀.h"
#include "枪械图片/闪光弹.h"


ImTextureID weapon[200];

void 加载枪械图片() {

weapon[0] = VK.ImAgeHeadFile(问号, sizeof(问号));
weapon[1] = VK.ImAgeHeadFile(拳头, sizeof(拳头));

weapon[2] = VK.ImAgeHeadFile(M416, sizeof(M416));
weapon[3] = VK.ImAgeHeadFile(M762, sizeof(M762));
weapon[4] = VK.ImAgeHeadFile(SCAR_L, sizeof(SCAR_L));
weapon[5] = VK.ImAgeHeadFile(AKM, sizeof(AKM));
weapon[6] = VK.ImAgeHeadFile(QBZ, sizeof(QBZ));
weapon[7] = VK.ImAgeHeadFile(AUG, sizeof(AUG));
weapon[8] = VK.ImAgeHeadFile(G36C, sizeof(G36C));
weapon[9] = VK.ImAgeHeadFile(M16A4, sizeof(M16A4));
weapon[10] = VK.ImAgeHeadFile(MK47, sizeof(MK47));
weapon[11] = VK.ImAgeHeadFile(蜜獾, sizeof(蜜獾));
weapon[12] = VK.ImAgeHeadFile(狗砸, sizeof(狗砸));
//30


weapon[31] = VK.ImAgeHeadFile(AC_VAL, sizeof(AC_VAL));
weapon[32] = VK.ImAgeHeadFile(MP5K, sizeof(MP5K));
weapon[33] = VK.ImAgeHeadFile(P90, sizeof(P90));
weapon[34] = VK.ImAgeHeadFile(UMP45, sizeof(UMP45));
weapon[35] = VK.ImAgeHeadFile(UZI, sizeof(UZI));
weapon[36] = VK.ImAgeHeadFile(野牛, sizeof(野牛));
weapon[37] = VK.ImAgeHeadFile(汤姆逊, sizeof(汤姆逊));
weapon[38] = VK.ImAgeHeadFile(维克托, sizeof(维克托));
//50


weapon[51] = VK.ImAgeHeadFile(AWM, sizeof(AWM));
weapon[52] = VK.ImAgeHeadFile(AMR, sizeof(AMR));
weapon[53] = VK.ImAgeHeadFile(_98K, sizeof(_98K));
weapon[54] = VK.ImAgeHeadFile(M200, sizeof(M200));
weapon[55] = VK.ImAgeHeadFile(M24, sizeof(M24));
weapon[56] = VK.ImAgeHeadFile(Win94, sizeof(Win94));
weapon[57] = VK.ImAgeHeadFile(莫辛纳甘, sizeof(莫辛纳甘));
//70


weapon[71] = VK.ImAgeHeadFile(M417, sizeof(M417));
weapon[72] = VK.ImAgeHeadFile(MK12, sizeof(MK12));
weapon[73] = VK.ImAgeHeadFile(MK14, sizeof(MK14));
weapon[74] = VK.ImAgeHeadFile(MK20_H, sizeof(MK20_H));
weapon[75] = VK.ImAgeHeadFile(Mini14, sizeof(Mini14));
weapon[76] = VK.ImAgeHeadFile(M1014, sizeof(M1014));
weapon[77] = VK.ImAgeHeadFile(QBU, sizeof(QBU));
weapon[78] = VK.ImAgeHeadFile(SKS, sizeof(SKS));
weapon[79] = VK.ImAgeHeadFile(SLR, sizeof(SLR));
weapon[80] = VK.ImAgeHeadFile(VSS, sizeof(VSS));
//90


weapon[90] = VK.ImAgeHeadFile(DBS, sizeof(DBS));
weapon[91] = VK.ImAgeHeadFile(S12K, sizeof(S12K));
weapon[92] = VK.ImAgeHeadFile(S1897, sizeof(S1897));
weapon[93] = VK.ImAgeHeadFile(S686, sizeof(S686));
//100


weapon[101] = VK.ImAgeHeadFile(DP_28, sizeof(DP_28));
weapon[102] = VK.ImAgeHeadFile(M249, sizeof(M249));
weapon[103] = VK.ImAgeHeadFile(MG3, sizeof(MG3));
//110


weapon[111] = VK.ImAgeHeadFile(P18C手枪, sizeof(P18C手枪));
weapon[112] = VK.ImAgeHeadFile(P1911手枪, sizeof(P1911手枪));
weapon[113] = VK.ImAgeHeadFile(P92手枪, sizeof(P92手枪));
weapon[114] = VK.ImAgeHeadFile(R45手枪, sizeof(R45手枪));
weapon[115] = VK.ImAgeHeadFile(信号枪, sizeof(信号枪));
weapon[116] = VK.ImAgeHeadFile(左轮手枪, sizeof(左轮手枪));
weapon[117] = VK.ImAgeHeadFile(沙漠之鹰, sizeof(沙漠之鹰));
weapon[118] = VK.ImAgeHeadFile(短管霰弹, sizeof(短管霰弹));
weapon[119] = VK.ImAgeHeadFile(蝎式手枪, sizeof(蝎式手枪));
//130


weapon[131] = VK.ImAgeHeadFile(砍刀, sizeof(砍刀));
weapon[132] = VK.ImAgeHeadFile(撬棍, sizeof(撬棍));
weapon[133] = VK.ImAgeHeadFile(镰刀, sizeof(镰刀));
weapon[134] = VK.ImAgeHeadFile(平底锅, sizeof(平底锅));
//140


weapon[141] = VK.ImAgeHeadFile(十字弩, sizeof(十字弩));
weapon[142] = VK.ImAgeHeadFile(爆炸猎弓, sizeof(爆炸猎弓));
//150


weapon[151] = VK.ImAgeHeadFile(闪光弹, sizeof(闪光弹));
weapon[152] = VK.ImAgeHeadFile(烟雾弹, sizeof(烟雾弹));
weapon[153] = VK.ImAgeHeadFile(燃烧瓶, sizeof(燃烧瓶));
weapon[154] = VK.ImAgeHeadFile(手榴弹, sizeof(手榴弹));
//160


}
#ifndef CLASS_H
#define CLASS_H

using namespace std;

bool alike(const string& Gname, const string& ClassName) {
return (Gname.find(ClassName)!= string::npos);
}


string 金插(const string& n) {
if (n.find("perPeopleSkill") != string::npos)
return "金插";
return "";
}


string 信号枪_(const string& n) {
if (n.find("BP_Pistol_Flaregun_Wrapper_C") != string::npos || n.find("Flare") != string::npos)
return "信号枪";
return "";
}




string 盒子空投(const string& n) {
if (alike(n, "CharacterDeadInventoryBox_C"))
return "敌人盒子";
if (alike(n, "_TrainingBoxListWrapper_C"))
return "盒子";
if (alike(n, "PickUpListWrapperActor"))
return "盒子";
if (alike(n, "CharacterDeadInventory_C"))
return "敌人盒子";
if (alike(n, "_AirDropPlane_C") || alike(n, "_AirDropPlane_SuperPeople_C"))
return "空投飞机";
if (alike(n, "_AirDropBox_C") || alike(n, "_AirDropBox_SuperPeople_C"))
return "空投盒子";
return "";
}

string 载具(const string& n) {
if (alike(n, "Horse"))
return "马";
if (alike(n, "_Mountainbike_Training_C"))
return "自行车";
if (alike(n, "licedTrain_C"))
return "磁吸小火车";
if (alike(n, "VH_BRDM_C"))
return "装甲车";
if (alike(n, "VH_Scooter_C"))
return "小电驴";
if (alike(n, "VH_Motorcycle"))
return "摩托车";
if (alike(n, "VH_MotorcycleCart"))
return "摩托手推车";
if (alike(n, "VH_Snowmobile_C"))
return "雪地车";
if (alike(n, "VH_Tuk"))
return "三轮老爷车";
if (alike(n, "Buggy"))
return "蹦蹦";
if (alike(n, "Dacia"))
return "小轿车";
if (alike(n, "UAZ"))
return "吉普车";
if (alike(n, "PickUp_07_C"))
return "大皮卡车";
if (alike(n, "Rony"))
return "小皮卡车";
if (alike(n, "Mirado"))
return "四轮敞篷车";
if (alike(n, "MiniBus"))
return "大巴车";
if (alike(n, "PG117"))
return "4 人快艇";
if (alike(n, "AquaRail"))
return "摩托艇";
if (alike(n, "Snowbike"))
return "雪地摩托车";
if (alike(n, "CoupeRB"))
return "双人跑车";
if (alike(n, "Motorglider"))
return "滑翔机";
if (alike(n, "Monster"))
return "电车";
if (alike(n, "UTV"))
return "越野车";
if (alike(n, "Bigfoot"))
return "大脚车";
if (alike(n, "VH_ATV"))
return "越野车";
if (alike(n, "AIVH_Leopard_1A3_C"))
return "低级坦克 BOSS";
if (alike(n, "ClassicStore"))
return "高级坦克 BOSS";
if (alike(n, "TrackVehicle_BP_C"))
return "地铁矿车";
if (alike(n, "AIVH_Weapon_Turret_C"))
return "地铁坦克";
return "";
}

bool GetVehicleInfo(char *gname, char **name) {
     //ALOGD("判断类名%s",ClassName);            
    if (strstr(gname, "_Mountainbike_Training_C") != nullptr) {
        *name = "自行车";
        
        return true;
    }
    if (strstr(gname, "Mirado") != nullptr) {
        *name = "双人跑车";
        
        return true;
    }
    if (strstr(gname, "Scooter") != nullptr) {
        *name = "小绵羊";
        
        return true;
    }
    if (strstr(gname, "_BRDM_C") != nullptr) {

        *name = "装甲车";
        
        return true;
    }
    if (strstr(gname, "Motorcycle")!= nullptr) {

        *name = "摩托车";
        
        return true;
    }
    if (strstr(gname, "Motorcycle") != nullptr) {

        *name = "摩托车";
        
        return true;
    }    
    if (strstr(gname, "Motorcycle")!= nullptr) {

        *name = "三轮摩托";
        
        return true;
    }

    if (strstr(gname, "Motorcycle")!= nullptr) {

        *name = "三轮摩托";
        
        return true;
    }
    if (strstr(gname, "Snowmobile") != nullptr) {

        *name = "雪地摩托";
        
        return true;
    }
    if (strstr(gname, "Snowmobile") != nullptr) {

        *name = "雪地摩托";
        
        return true;
    }
    if (strstr(gname, "StationWagon") != nullptr) {

        *name = "旅行车";
        
        return true;
    }    
    if (strstr(gname, "_VH_Buggy_C") != nullptr) {

        *name = "蹦蹦车";
        
        return true;
    }
    if (strstr(gname, "Dacia") != nullptr) {

        *name = "轿车";
        
        return true;
    }
    if (strstr(gname, "_UAZ01_New_C") != nullptr) {

        *name = "吉普车";
        
        return true;
    }
    if (strstr(gname, "PickUp_07_C") != nullptr) {

        *name = "皮卡车";
        
        return true;
    }
    if (strstr(gname, "CoupeRB") != nullptr) {

        *name = "双人跑车";
        
        return true;
    }
    if (strstr(gname, "Mirado") != nullptr) {

        *name = "敞篷跑车";
        
        return true;
    }
    if (strstr(gname, "_MiniBus_01_C") != nullptr) {

        *name = "迷你巴士";
        
        return true;
    }
    if (strstr(gname, "_PG117_C") != nullptr) {
        *name = "快艇";
        
        return true;
    }
    if (strstr(gname, "uaRail_1_C") != nullptr) {
        *name = "摩托艇";
        
        return true;
    }
    if (strstr(gname, "_Motorglider_C") != nullptr) {
        *name = "滑翔机";
        
        return true;
    }
    if (strstr(gname, "licedTrain_C") != nullptr) {
        *name = "磁吸小火车";
        
        return true;
    }
        if (strstr(gname, "Buggy") != nullptr) {
        *name = "蹦蹦车";
        
        return true;
    }
            if (strstr(gname, "PG117") != nullptr) {
        *name = "船";
        
        return true;
    }
        if (strstr(gname, "UAZ") != nullptr) {
        *name = "吉普车";
        
        return true;
    }
        if (strstr(gname, "TrackVehicle") != nullptr) {
        *name = "地铁车";
        
        return true;
    }
    if (strstr(gname, "Horse") != nullptr) {
        *name = "马";
        
        return true;
    }
    return false;
}

string 姥爷物资(const string& n) {
if (alike(n, "FileBag_Lua_Lv1_C"))
return "手提包 V1";
if (alike(n, "FileBag_Lua_Lv2_C"))
return "手提包 V2";
if (alike(n, "FileBag_Lua_Lv3_C"))
return "手提包 V3";
if (alike(n, "FileBag_Lua_Lv4_C"))
return "手提包 V4";
if (alike(n, "FileBag_Lua_Lv5_C"))
return "手提包 V5";
if (alike(n, "EggBox_Lua_Lv1_C"))
return "隐匿点";
return "";
}

string 信函箱(const string& n) {
if (alike(n, "FileBox_Lua_Lv1_C"))
return "信函箱 V1";
if (alike(n, "FileBox_Lua_Lv2_C"))
return "信函箱 V2";
if (alike(n, "FileBox_Lua_Lv3_C"))
return "信函箱 V3";
if (alike(n, "FileBox_Lua_Lv4_C"))
return "信函箱 V4";
if (alike(n, "FileBox_Lua_Lv5_C"))
return "信函箱 V5";
return "";
}




string 宝箱(const string& n) {
if (alike(n, "Escape_SupplyBax_Lv1_C") || alike(n, "EscapeBoxHight_SupplyBox_Lv1_C"))
return "1 级宝箱";
if (alike(n, "Escape_SupplyBax_Lv2_C") || alike(n, "EscapeBoxHight_SupplyBox_Lv2_C"))
return "2 级宝箱";
if (alike(n, "Escape_SupplyBax_Lv3_C") || alike(n, "EscapeBoxHight_SupplyBox_Lv3_C"))
return "3 级宝箱";
if (alike(n, "Escape_SupplyBax_Lv4_C") || alike(n, "EscapeBoxHight_SupplyBox_Lv4_C"))
return "4 级宝箱";
if (alike(n, "Escape_SupplyBax_Lv5_C") || alike(n, "EscapeBoxHight_SupplyBox_Lv5_C"))
return "5 级宝箱";
return "";
}


string 物资箱(const string& n) {
if (alike(n, "ClassicStore"))
return "黑店";
if (alike(n, "ItemBox_Lua_Lv1_C"))
return "物资箱 V1";
if (alike(n, "ItemBox_Lua_Lv2_C"))
return "物资箱 V2";
if (alike(n, "ItemBox_Lua_Lv3_C"))
return "物资箱 V3";
if (alike(n, "ItemBox_Lua_Lv4_C"))
return "物资箱 V4";
if (alike(n, "ItemBox_Lua_Lv5_C"))
return "物资箱 V5";
if (alike(n, "ItemBox_Lua_Lv6_C"))
return "物资箱 V6";
return "";
}


string 武器箱(const string& n) {
if (alike(n, "EscapeBox_Weapon_Lv1_c") || alike(n, "EscapeBoxHight_Weapon_Lv1_C"))
return "1 级武器箱";
if (alike(n, "EscapeBox_Weapon_Lv2_c") || alike(n, "EscapeBoxHight_Weapon_Lv2_C"))
return "2 级武器箱";
if (alike(n, "EscapeBox_Weapon_Lv3_c") || alike(n, "EscapeBoxHight_Weapon_Lv3_C"))
return "3 级武器箱";
if (alike(n, "EscapeBox_Weapon_Lv4_c") || alike(n, "EscapeBoxHight_Weapon_Lv4_C"))
return "4 级武器箱";
if (alike(n, "EscapeBox_Weapon_Lv5_c") || alike(n, "EscapeBoxHight_Weapon_Lv5_C"))
return "5 级武器箱";
return "";
}


string 药品箱(const string& n) {
if (alike(n, "EscapeBox_Medical_Lv1_C") || alike(n, "EscapeBoxHight_Medical_Lv1_C"))
return "1 级药品箱";
if (alike(n, "EscapeBox_Medical_Lv2_C") || alike(n, "EscapeBoxHight_Medical_Lv2_C"))
return "2 级药品箱";
if (alike(n, "EscapeBox_Medical_Lv3_C") || alike(n, "EscapeBoxHight_Medical_Lv3_C"))
return "3 级药品箱";
return "";
}


string 药品(const string& n) {
if (alike(n, "ink_Pickup_C"))
return "饮料";
if (alike(n, "rstaid_Pickup_C"))
return "医药包";
if (alike(n, "lls_Pickup_C"))
return "止痛药";
if (alike(n, "rstAidbox_Pickup_C"))
return "医药箱";
if (alike(n, "_revivalAED_Pickup_C"))
return "自救器";
if (alike(n, "jection_Pickup_C"))
return "肾上腺素";
return "";
}


string 手枪(const string& n) {
if (alike(n, "P92"))
return "P92";
if (alike(n, "Vz61"))
return "Vz61";
if (alike(n, "R45"))
return "R45";
if (alike(n, "P1911"))
return "P1911";
if (alike(n, "P18C"))
return "P18C";
if (alike(n, "BP_Pistol_DesertEagle_Wrapper_C"))
return "沙漠之鹰";
return "";
}


string 步枪(const string& n) {
if (alike(n, "Rifle_AKM_Wrapper_C"))
return "AKM";
if (alike(n, "Rifle_M416_Wrapper_C"))
return "M416";
if (alike(n, "Rifle_M16A4_Wrapper_C"))
return "M16A4";
if (alike(n, "Rifle_SCAR_Wrapper_C"))
return "SCAR";
if (alike(n, "Rifle_QBZ_Wrapper_C"))
return "QBZ";
return "";
}


string 霰弹枪(const string& n) {
if (alike(n, "ShotGun_S12K_Wrapper_C"))
return "S12K";
if (alike(n, "ShotGun_DP12_Wrapper_C"))
return "DBS散弹枪";
if (alike(n, "ShotGun_S686_Wrapper_C"))
return "S686";
if (alike(n, "ShotGun_S1897_Wrapper_C"))
return "S1897";
if (alike(n, "ShotGun_SPAS-12_Wrapper_C"))
return "SPAS_12";
return "";
}


string 冲锋枪(const string& n) {
if (alike(n, "MachineGun_UMP9_Wrapper_C"))
return "UMP-45";
if (alike(n, "MachineGun_TommyGun_Wrapper_C"))
return "汤姆逊冲锋枪";
if (alike(n, "MachineGun_PP19_Wrapper_C"))
return "野牛";
if (alike(n, "MachineGun_Uzi_Wrapper_C"))
return "Uzi";
return "";
}


string 狙击枪(const string& n) {
if (alike(n, "Sniper_Kar98k_Wrapper_C"))
return "Kar98k";
if (alike(n, "Sniper_Win94_Wrapper_C"))
return "WIN94";
if (alike(n, "Sniper_Mini14_Wrapper_C"))
return "Mini14";
if (alike(n, "Sniper_SKS_Wrapper_C"))
return "SKS";
if (alike(n, "Sniper_M24_Wrapper_C"))
return "M24";
if (alike(n, "WEP_Mk14_Pickup_C"))
return "MK14";
return "";
}


string 瞄准镜(const string& n) {
if (alike(n, "MZJ_HD_Pickup_C"))
return "红点";
if (alike(n, "MZJ_QX_Pickup_C"))
return "全息瞄准镜";
if (alike(n, "MZJ_SideRMR_Pickup_C"))
return "侧面瞄准镜";
if (alike(n, "MZJ_2X_Pickup_C"))
return "2倍镜";
if (alike(n, "MZJ_3X_Pickup_C"))
return "3倍镜";
if (alike(n, "MZJ_4X_Pickup_C"))
return "4倍镜";
if (alike(n, "MZJ_6X_Pickup_C"))
return "6倍镜";
if (alike(n, "MZJ_8X_Pickup_C"))
return "8倍镜";
return "";
}


string 弹夹(const string& n) {
if (alike(n, "DJ_Large_EQ_Pickup_C"))
return "步枪快扩";
if (alike(n, "DJ_Large_E_Pickup_C"))
return "步枪扩容";
if (alike(n, "DJ_Sniper_EQ_Pickup_C"))
return "狙击枪快扩";
if (alike(n, "DJ_Sniper_E_Pickup_C"))
return "狙击枪扩容";
if (alike(n, "DJ_Mid_E_Pickup_C"))
return "冲锋枪扩容";
if (alike(n, "DJ_Mid_EQ_Pickup_C"))
return "冲锋枪快扩";
if (alike(n, "ZDD_Sniper_Pickup_C"))
return "子弹袋";
if (alike(n, "DJ_DrumMag_Pickup_C"))
return "小型弹鼓";
if (alike(n, "ZDD_Crossbow_Q_Pickup_C"))
return "箭袋";
if (alike(n, "DJ_ShotGun_Pickup_C"))
return "散弹枪快速填装器";
if (alike(n, "DJ_Mid_Q_Pickup_C"))
return "手枪快速扩容";
return "";
}


string 枪口(const string& n) {
if (alike(n, "QK_Large_Suppressor_Pickup_C"))
return "步枪消音器";
if (alike(n, "QK_Sniper_Suppressor_Pickup_C"))
return "狙击枪消音器";
if (alike(n, "QT_Sniper_Pickup_C"))
return "托腮板";
if (alike(n, "QK_Large_Compensator_Pickup_C"))
return "步枪补偿器";
if (alike(n, "QK_Sniper_Compensator_Pickup_C"))
return "狙击枪补偿器";
if (alike(n, "QK_Large_FlashHider_Pickup_C"))
return "步枪消焰器";
if (alike(n, "WB_Vertical_Pickup_C"))
return "垂直握把";
if (alike(n, "QK_Choke_Pickup_C"))
return "收束器";
if (alike(n, "WB_Lasersight_Pickup_C"))
return "激光瞄准器";
return "";
}


string 子弹(const string& n) {
 if (alike(n, "Ammo_556mm_Pickup_C"))
return "5.56子弹";
if (alike(n, "Ammo_762mm_Pickup_C"))
return "7.62子弹";
if (alike(n, "Ammo_45AC_Pickup_C"))
return ".45口径子弹";
if (alike(n, "Ammo_9mm_Pickup_C"))
return "9毫米子弹";
if (alike(n, "Ammo_12Guage_Pickup_C"))
return "12口径子弹";
if (alike(n, "Ammo_300Magnum_Pickup_C"))
return "马格南";
return "";
}


string 狗子(const string& n) {
if (alike(n, "Watcher_C") || alike(n, "Watcher_Child_C") || alike(n, "HungerH_C") || alike(n, "HungerB_C") || alike(n, "VenomVariant_C") || alike(n, "BurningVariant_C") || alike(n, "Library_C") || alike(n, "AIMob_PatrolDog_C"))
return "狗子";
return "";
}




char *dzdz(int dzid) {
switch (dzid) {

//站立一系列
case 8:
 return"立正";
break;
case 521:
 return"开镜";
break;
case 648:
 return"开火";
break;
case 649:
 return"开火";
break;
case 1032:
 return"探头";
break;
case 1033:
 return"探头";
break;
case 136:
 return"开火";
break;
case 137:
case 139:
 return"开火";
break;
case 1160:
 return"探头";
break;
case 1161:
 return"探头";
break;
case 1544:
 return"开镜";
break;
case 1545:
 return"开镜";
break;
case 1672:
 return"开火";
break;
case 1673:
 return"开火";
break;
case 8200:
 return"挥拳";
break;
case 8201:
case 8203:
 return"挥拳";
break;
case 267:
 return"换弹";
break;
case 17417:
 return"投掷";
break;
//蹲下一系列
case 16:
 return"蹲下";
break;
case 17:
case 147:
 return"开火";
break;
case 656:
 return"开火";
break;
case 657:
 return"开火";
break;
case 1040:
 return"探头";
break;
case 1041:
 return"探头";
break;
case 528:
 return"开镜";
break;
case 529:
 return"开镜";
break;
case 1168:
 return"开火";
break;
case 1169:
 return"开火";
break;
case 1552:
 return"开镜";
break;
case 1553:
 return"开镜";
break;
case 1680:
 return"开火";
break;
case 1681:
 return"开火";
break;
case 8209:
 return"挥拳";
break;
case 275:
 return"换弹";
break;
case 2064:
 return"换枪";
break;
case 16401:
 return"投掷";
break;
case 17425:
 return"投掷";
break;
case 65553:
 return"打药";
break;
//趴下一系列
case 32:
 return"趴下";
break;
case 33:
case 34:
case 35:
 return"趴下";
break;
case 544:
 return"开镜";
break;
case 545:
 return"开镜";
break;
case 672:
 return"开火";
break;
case 289:
case 291:
 return"换弹";
break;
case 16417:
 return"投掷";
break;
//跳跃一系列
case 72:
 return"跳跃";
break;
case 73:
case 75:
 return"跳跃";
break;
case 8264:
 return"跳拳";
break;
case 8265:
case 8267:
 return"跳拳";
break;
case 203:
 return"开火";
break;
case 331:
 return"换弹";
break;
//车一系列
case 524296:
 return"开车";
break;
case 1048584:
 return"没动";
break;
case 3145736:
 return"探头";
break;
case 3145864:
 return"开火";
break;
case 3146248:
 return"开镜";
break;
case 3146376:
 return"开火";
break;
case 3145992:
 return"换弹";
break;
case 3162120:
 return"投掷";
break;
//游泳
case 4194307:
case 4194305:
 return"游泳";
break;
//倒地

//其它一系列
case 16777226:
 return"攀爬";
break;
case 10:
 return"跑跳";
break;
case 8202:
 return"跳拳";
break;
case 268435464:
 return"跳舞";
break;
case 1073741832:
 return"立正";
break;


case 329:
case 328:
case 288:
case 272:
case 273:
case 264:
case 265:
return "换弹";
break;

case 9:
return "行走";
break;

case 11:
return "跑路";
break;

case 16777224:
return "翻墙";
break;


case 16392:
case 17416:
case 16400:
case 17424:
case 16416:
case 16456:
case 16393:
case 16457:
return "投掷";
break;


case 520:
return "开镜";
break;

case 65545:
return "打药";
break;

case 200:
case 201:
return "跳枪";
break;

case 144:
case 145:
return "蹲着";
break;

case 160:
return "趴下";
break;

case 8208:
return "蹲拳";
break;

case 8211:
return "蹲跑";
break;

case 19:
return "蹲跑";
break;

case 131072:
case 524303:
case 524304:
case 524289:
return "倒地";
break;

case 2056:
case 2057:
case 2059:
case 2065:
case 2067:
case 2081:
case 2080:
case 2083:
case 2121:
case 2120:
case 2123:
return "切枪";
break;

case 4194304:
return "游泳";
break;

case 65544:
case 65552:

case 65568:
return "打药";
break;


default:
return "未知";
break;
}
return nullptr;
} 

int GetWeapon(int Wuqi) {
switch (Wuqi) {
//突击步枪
case 101008:
return 30; //M762
break;
case 1010081:
return 31; //M762破损
break;
case 1010082:
return 32; //M762修复
break;
case 1010083:
return 33; //M762完好
break;
case 1010084:
return 34; //M762改进
break;
case 1010085:
return 35; //M762精制
break;
case 1010086:
return 37; //M762独眼
break;
case 1010087:
return 38; //M762钢铁
break;

case 101001:
return 50; //AKM
break;
case 1010011:
return 51; //AKM破损
break;
case 1010012:
return 52; //AKM修复
break;
case 1010013:
return 53; //AKM完好
break;
case 1010014:
return 54; //AKM改进
break;
case 1010015:
return 55; //AKM精制
break;
case 1010016:
return 57; //AKM独眼
break;
case 1010017:
return 58; //AKM钢铁
break;

case 101004:
return 20; //M416
break;
case 1010041:
return 21; //M416破损
break;
case 1010042:
return 22; //M416修复
break;
case 1010043:
return 23; //M416完好
break;
case 1010044:
return 24; //M416改进
break;
case 1010045:
return 25; //M416精制
break;
case 1010046:
return 27; //M416独眼
break;
case 1010047:
return 28; //M416钢铁
break;

case 101003:
return 40; //SCAR_L
break;
case 1010031:
return 41; //SCAR_L破损
break;
case 1010032:
return 42; //SCAR_L修复
break;
case 1010033:
return 43; //SCAR_L完好
break;
case 1010034:
return 44; //SCAR_L改进
break;
case 1010035:
return 45; //SCAR_L精制
break;
case 1010036:
return 47; //SCAR_L独眼
break;
case 1010037:
return 48; //SCAR_L钢铁
break;

case 101002:
return 90; //M16A4
break;
case 1010021:
return 91; //M16A4破损
break;
case 1010022:
return 92; //M16A4修复
break;
case 1010023:
return 93; //M16A4完好
break;
case 1010024:
return 94; //M16A4改进
break;
case 1010025:
return 95; //M16A4精制
break;
case 1010026:
return 97; //M16A4独眼
break;
case 1010027:
return 98; //M16A4钢铁
break;

case 101009:
return 100; //MK47
break;
case 1010091:
return 101; //MK47破损
break;
case 1010092:
return 102; //MK47修复
break;
case 1010093:
return 103; //MK47完好
break;
case 1010094:
return 104; //MK47改进
break;
case 1010095:
return 105; //MK47精制
break;
case 1010096:
return 107; //MK47独眼
break;
case 1010097:
return 108; //MK47钢铁
break;

case 101006:
return 70; //AUG
break;
case 1010061:
return 71; //AUG破损
break;
case 1010062:
return 72; //AUG修复
break;
case 1010063:
return 73; //AUG完好
break;
case 1010064:
return 74; //AUG改进
break;
case 1010065:
return 75; //AUG精制
break;
case 1010066:
return 77; //AUG独眼
break;
case 1010067:
return 78; //AUG钢铁
break;

case 101005:
return 120; //狗砸
break;
case 1010051:
return 121; //狗砸破损
break;
case 1010052:
return 122; //狗砸修复
break;
case 1010053:
return 123; //狗砸完好
break;
case 1010054:
return 124; //狗砸改进
break;
case 1010055:
return 125; //狗砸精制
break;
case 1010056:
return 127; //狗砸独眼
break;
case 1010057:
return 128; //狗砸钢铁
break;

case 101010:
return 80; //G36C
break;
case 1010101:
return 81; //G36C破损
break;
case 1010102:
return 82; //G36C修复
break;
case 1010103:
return 83; //G36C完好
break;
case 1010104:
return 84; //G36C改进
break;
case 1010105:
return 85; //G36C精制
break;
case 1010106:
return 87; //G36C独眼
break;
case 1010107:
return 88; //G36C钢铁
break;

case 101007:
return 60; //QBZ
break;
case 1010071:
return 61; //QBZ破损
break;
case 1010072:
return 62; //QBZ修复
break;
case 1010073:
return 63; //QBZ完好
break;
case 1010074:
return 64; //QBZ改进
break;
case 1010075:
return 65; //QBZ精制
break;
case 1010076:
return 67; //QBZ独眼
break;
case 1010077:
return 68; //QBZ钢铁
break;

case 101011:
return 310; //AC_VAL
break;
case 1010111:
return 311; //AC_VAL破损
break;
case 1010112:
return 312; //AC_VAL修复
break;
case 1010113:
return 313; //AC_VAL完好
break;
case 1010114:
return 314; //AC_VAL改进
break;
case 1010115:
return 315; //AC_VAL精制
break;
case 1010116:
return 317; //AC_VAL独眼
break;
case 1010117:
return 318; //AC_VAL钢铁
break;

case 101012:
return 110; //蜜獾突击步枪
break;
case 1010121:
return 111; //蜜獾突击步枪破损
break;
case 1010122:
return 112; //蜜獾突击步枪修复
break;
case 1010123:
return 113; //蜜獾突击步枪完好
break;
case 1010124:
return 114; //蜜獾突击步枪改进
break;
case 1010125:
return 115; //蜜獾突击步枪精制
break;
case 1010126:
return 117; //蜜獾突击步枪独眼
break;
case 1010127:
return 118; //蜜獾突击步枪钢铁
break;
//连狙
case 103009:
return 790; //SLR
break;
case 1030091:
return 791; //SLR破损
break;
case 1030092:
return 792; //SLR修复
break;
case 1030093:
return 793; //SLR完好
break;
case 1030094:
return 794; //SLR改进
break;
case 1030095:
return 795; //SLR精制
break;
case 1030096:
return 797; //SLR独眼
break;
case 1030097:
return 798; //SLR钢铁
break;

case 103005:
return 800; //VSS
break;
case 1030051:
return 801; //VSS破损
break;
case 1030052:
return 802; //VSS修复
break;
case 1030053:
return 803; //VSS完好
break;
case 1030054:
return 804; //VSS改进
break;
case 1030055:
return 805; //VSS精制
break;
case 1030056:
return 807; //VSS独眼
break;
case 1030057:
return 808; //VSS钢铁
break;

case 103006:
return 750; //Mini14
break;
case 1030061:
return 751; //Mini14破损
break;
case 1030062:
return 752; //Mini14修复
break;
case 1030063:
return 753; //Mini14完好
break;
case 1030064:
return 754; //Mini14改进
break;
case 1030065:
return 755; //Mini14精制
break;
case 1030066:
return 757; //Mini14独眼
break;
case 1030067:
return 758; //Mini14钢铁
break;

case 103010:
return 770; //QBU
break;
case 1030101:
return 771; //QBU破损
break;
case 1030102:
return 772; //QBU修复
break;
case 1030103:
return 773; //QBU完好
break;
case 1030104:
return 774; //QBU改进
break;
case 1030105:
return 775; //QBU精制
break;
case 1030106:
return 777; //QBU独眼
break;
case 1030107:
return 778; //QBU钢铁
break;

case 103004:
return 780; //SKS
break;
case 1030041:
return 781; //SKS破损
break;
case 1030042:
return 782; //SKS修复
break;
case 1030043:
return 783; //SKS完好
break;
case 1030044:
return 784; //SKS改进
break;
case 1030045:
return 785; //SKS精制
break;
case 1030046:
return 787; //SKS独眼
break;
case 1030047:
return 788; //SKS钢铁
break;

case 103007:
return 730; //MK14
break;
case 1030071:
return 731; //MK14破损
break;
case 1030072:
return 732; //MK14修复
break;
case 1030073:
return 733; //MK14完好
break;
case 1030074:
return 734; //MK14改进
break;
case 1030075:
return 735; //MK14精制
break;
case 1030076:
return 737; //MK14独眼
break;
case 1030077:
return 738; //MK14钢铁
break;

case 103014:
return 740; //MK20_H
break;
case 1030141:
return 741; //MK20_H破损
break;
case 1030142:
return 742; //MK20_H修复
break;
case 1030143:
return 743; //MK20_H完好
break;
case 1030144:
return 744; //MK20_H改进
break;
case 1030145:
return 745; //MK20_H精制
break;
case 1030146:
return 747; //MK20_H独眼
break;
case 1030147:
return 748; //MK20_H钢铁
break;

case 103013:
return 710; //M417
break;
case 1030131:
return 711; //M417破损
break;
case 1030132:
return 712; //M417修复
break;
case 1030133:
return 713; //M417完好
break;
case 1030134:
return 714; //M417改进
break;
case 1030135:
return 715; //M417精制
break;
case 1030136:
return 717; //M417独眼
break;
case 1030137:
return 718; //M417钢铁
break;
//连狙
case 103012:
return 520; //AMR
break;
case 1030121:
return 521; //AMR破损
break;
case 1030122:
return 522; //AMR修复
break;
case 1030123:
return 523; //AMR完好
break;
case 1030124:
return 524; //AMR改进
break;
case 1030125:
return 525; //AMR精制
break;
case 1030126:
return 527; //AMR独眼
break;
case 1030127:
return 528; //AMR钢铁
break;

case 103003:
return 510; //AWM
break;
case 1030031:
return 511; //AWM破损
break;
case 1030032:
return 512; //AWM修复
break;
case 1030033:
return 513; //AWM完好
break;
case 1030034:
return 514; //AWM改进
break;
case 1030035:
return 515; //AWM精制
break;
case 1030036:
return 517; //AWM独眼
break;
case 1030037:
return 518; //AWM钢铁
break;

case 103002:
return 550; //M24
break;
case 1030021:
return 551; //M24破损
break;
case 1030022:
return 552; //M24修复
break;
case 1030023:
return 553; //M24完好
break;
case 1030024:
return 554; //M24改进
break;
case 1030025:
return 555; //M24精制
break;
case 1030026:
return 557; //M24独眼
break;
case 1030027:
return 558; //M24钢铁
break;

case 103011:
return 570; //莫辛纳甘
break;
case 1030111:
return 571; //莫辛纳甘破损
break;
case 1030112:
return 572; //莫辛纳甘修复
break;
case 1030113:
return 573; //莫辛纳甘完好
break;
case 1030114:
return 574; //莫辛纳甘改进
break;
case 1030115:
return 575; //莫辛纳甘精制
break;
case 1030116:
return 577; //莫辛纳甘独眼
break;
case 1030117:
return 578; //莫辛纳甘钢铁
break;

case 103001:
return 530; //_98K
break;
case 1030011:
return 531; //_98K破损
break;
case 1030012:
return 532; //_98K修复
break;
case 1030013:
return 533; //_98K完好
break;
case 1030014:
return 534; //_98K改进
break;
case 1030015:
return 535; //_98K精制
break;
case 1030016:
return 537; //_98K独眼
break;
case 1030017:
return 538; //_98K钢铁
break;

case 103008:
return 560; //Win94
break;
case 1030081:
return 561; //Win94破损
break;
case 1030082:
return 562; //Win94修复
break;
case 1030083:
return 563; //Win94完好
break;
case 1030084:
return 564; //Win94改进
break;
case 1030085:
return 565; //Win94精制
break;
case 1030086:
return 567; //Win94独眼
break;
case 1030087:
return 568; //Win94钢铁
break;
//机关枪
case 105001:
return 550; //M249
break;
case 1050011:
return 551; //M249破损
break;
case 1050012:
return 552; //M249修复
break;
case 1050013:
return 553; //M249完好
break;
case 1050014:
return 554; //M249改进
break;
case 1050015:
return 555; //M249精制
break;
case 1050016:
return 557; //M249独眼
break;
case 1050017:
return 558; //M249钢铁
break;

case 105002:
return 1010; //DP_28
break;
case 1050021:
return 1011; //DP_28破损
break;
case 1050022:
return 1012; //DP_28修复
break;
case 1050023:
return 1013; //DP_28完好
break;
case 1050024:
return 1014; //DP_28改进
break;
case 1050025:
return 1015; //DP_28精制
break;
case 1050026:
return 1017; //DP_28独眼
break;
case 1050027:
return 1018; //DP_28钢铁
break;

case 105010:
return 1030; //MG3
break;
case 1050101:
return 1031; //MG3破损
break;
case 1050102:
return 1032; //MG3修复
break;
case 1050103:
return 1033; //MG3完好
break;
case 1050104:
return 1034; //MG3改进
break;
case 1050105:
return 1035; //MG3精制
break;
case 1050106:
return 1037; //MG3独眼
break;
case 1050107:
return 1038; //MG3钢铁
break;

case 107001:
return 1410; //十字弩
break;
case 1070011:
return 1411; //十字弩破损
break;
case 1070012:
return 1412; //十字弩修复
break;
case 1070013:
return 1413; //十字弩完好
break;
case 1070014:
return 1414; //十字弩改进
break;
case 1070015:
return 1415; //十字弩精制
break;
case 1070016:
return 1417; //十字弩独眼
break;
case 1070017:
return 1418; //十字弩钢铁
break;

case 107007:
return 1420; //爆炸猎弓
break;
case 1070071:
return 1421; //爆炸猎弓破损
break;
case 1070072:
return 1422; //爆炸猎弓修复
break;
case 1070073:
return 1423; //爆炸猎弓完好
break;
case 1070074:
return 1424; //爆炸猎弓改进
break;
case 1070075:
return 1425; //爆炸猎弓精制
break;
case 1070076:
return 1427; //爆炸猎弓独眼
break;
case 1070077:
return 1428; //爆炸猎弓钢铁
break;
//冲锋枪
case 102001:
return 350; //UZI
break;
case 1020011:
return 351; //UZI破损
break;
case 1020012:
return 352; //UZI修复
break;
case 1020013:
return 353; //UZI完好
break;
case 1020014:
return 354; //UZI改进
break;
case 1020015:
return 355; //UZI精制
break;
case 1020016:
return 357; //UZI独眼
break;
case 1020017:
return 358; //UZI钢铁
break;

case 102003:
return 380; //维克托
break;
case 1020031:
return 381; //维克托破损
break;
case 1020032:
return 382; //维克托修复
break;
case 1020033:
return 383; //维克托完好
break;
case 1020034:
return 384; //维克托改进
break;
case 1020035:
return 385; //维克托精制
break;
case 1020036:
return 387; //维克托独眼
break;
case 1020037:
return 388; //维克托钢铁
break;

case 100103:
return 360; //野牛 PP_19
break;
case 1001031:
return 361; //野牛 PP_19破损
break;
case 1001032:
return 362; //野牛 PP_19修复
break;
case 1001033:
return 363; //野牛 PP_19完好
break;
case 1001034:
return 364; //野牛 PP_19改进
break;
case 1001035:
return 365; //野牛 PP_19精制
break;
case 1001036:
return 367; //野牛 PP_19独眼
break;
case 1001037:
return 368; //野牛 PP_19钢铁
break;

case 102007:
return 320; //MP5K
break;
case 1020071:
return 321; //MP5K破损
break;
case 1020072:
return 322; //MP5K修复
break;
case 1020073:
return 323; //MP5K完好
break;
case 1020074:
return 324; //MP5K改进
break;
case 1020075:
return 325; //MP5K精制
break;
case 1020076:
return 327; //MP5K独眼
break;
case 1020077:
return 328; //MP5K钢铁
break;

case 102002:
return 340; //UMP45
break;
case 1020021:
return 341; //UMP45破损
break;
case 1020022:
return 342; //UMP45修复
break;
case 1020023:
return 343; //UMP45完好
break;
case 1020024:
return 344; //UMP45改进
break;
case 1020025:
return 345; //UMP45精制
break;
case 1020026:
return 347; //UMP45独眼
break;
case 1020027:
return 348; //UMP45钢铁
break;

case 102004:
return 370; //汤姆逊
break;
case 1020041:
return 371; //汤姆逊破损
break;
case 1020042:
return 372; //汤姆逊修复
break;
case 1020043:
return 373; //汤姆逊完好
break;
case 1020044:
return 374; //汤姆逊改进
break;
case 1020045:
return 375; //汤姆逊精制
break;
case 1020046:
return 377; //汤姆逊独眼
break;
case 1020047:
return 378; //汤姆逊钢铁
break;

case 102105:
return 330; //P90
break;
case 1021051:
return 331; //P90破损
break;
case 1021052:
return 332; //P90修复
break;
case 1021053:
return 333; //P90完好
break;
case 1021054:
return 334; //P90改进
break;
case 1021055:
return 335; //P90精制
break;
case 1021056:
return 337; //P90独眼
break;
case 1021057:
return 338; //P90钢铁
break;

case 102005:
return 360; //野牛
break;
case 1020051:
return 361; //野牛破损
break;
case 1020052:
return 362; //野牛修复
break;
case 1020053:
return 363; //野牛完好
break;
case 1020054:
return 364; //野牛改进
break;
case 1020055:
return 365; //野牛精制
break;
case 1020056:
return 367; //野牛独眼
break;
case 1020057:
return 368; //野牛钢铁
break;
//霰弹枪
case 104001:
return 930; //S686
break;
case 1040011:
return 931; //S686破损
break;
case 1040012:
return 932; //S686修复
break;
case 1040013:
return 933; //S686完好
break;
case 1040014:
return 934; //S686改进
break;
case 1040015:
return 935; //S686精制
break;
case 1040016:
return 937; //S686独眼
break;
case 1040017:
return 938; //S686钢铁
break;

case 104002:
return 920; //S1897
break;
case 1040021:
return 921; //S1897破损
break;
case 1040022:
return 922; //S1897修复
break;
case 1040023:
return 923; //S1897完好
break;
case 1040024:
return 924; //S1897改进
break;
case 1040025:
return 925; //S1897精制
break;
case 1040026:
return 927; //S1897独眼
break;
case 1040027:
return 928; //S1897钢铁
break;

case 104003:
return 910; //S12K
break;
case 1040031:
return 911; //S12K破损
break;
case 1040032:
return 912; //S12K修复
break;
case 1040033:
return 913; //S12K完好
break;
case 1040034:
return 914; //S12K改进
break;
case 1040035:
return 915; //S12K精制
break;
case 1040036:
return 917; //S12K独眼
break;
case 1040037:
return 918; //S12K钢铁
break;

case 104004:
return 900; //DBS
break;
case 1040041:
return 901; //DBS破损
break;
case 1040042:
return 902; //DBS修复
break;
case 1040043:
return 903; //DBS完好
break;
case 1040044:
return 904; //DBS改进
break;
case 1040045:
return 905; //DBS精制
break;
case 1040046:
return 907; //DBS独眼
break;
case 1040047:
return 908; //DBS钢铁
break;

case 104100:
return 0; //SPAS_12 没有
break;
case 1041001:
return 1; //SPAS_12破损
break;
case 1041002:
return 2; //SPAS_12修复
break;
case 1041003:
return 3; //SPAS_12完好
break;
case 1041004:
return 4; //SPAS_12改进
break;
case 1041005:
return 5; //SPAS_12精制
break;
case 1041006:
return 7; //SPAS_12独眼
break;
case 1041007:
return 8; //SPAS_12钢铁
break;
//投掷爆炸物
case 602001:
return 1510; //闪光弹
break;
case 602002:
return 1520; //烟雾弹
break;
case 602003:
return 1530; //燃烧瓶
break;
case 602004:
return 1540; //手榴弹
break;
//近战武器
case 108001:
return 1310; //砍刀
break;
case 108002:
return 1320; //撬棍
break;
case 108003:
return 1330; //镰刀
break;
case 108004:
return 1340; //平底锅
break;
case 0:
return 10; //拳头
break;
case 9808001:
return 1131; //P92手枪破损
break;
case 9808002:
return 1132; //P92手枪修复
break;
case 9808003:
return 1133; //P92手枪完好
break;
case 9808008:
return 1121; //P1911手枪破损
break;
case 9808009:
return 1122; //P1911手枪修复
break;
case 9808010:
return 1123; //P1911手枪完好
break;
case 9808015:
return 1161; //左轮手枪破损
break;
case 9808016:
return 1162; //左轮手枪修复
break;
case 9808017:
return 1163; //左轮手枪完好
break;
case 9808022:
return 1111; //P18C手枪破损
break;
case 9808023:
return 1112; //P18C手枪修复
break;
case 9808024:
return 1113; //P18C手枪完好
break;
case 9808029:
return 1141; //R45手枪破损
break;
case 9808030:
return 1142; //R45手枪修复
break;
case 9808031:
return 1143; //R45手枪完好
break;
case 9808036:
return 1181; //短管霰弹枪破损
break;
case 9808037:
return 1182; //短管霰弹枪修复
break;
case 9808038:
return 1183; //短管霰弹枪完好
break;
case 9808043:
return 1192; //蝎式手枪修复
break;
case 9808044:
return 1193; //蝎式手枪完好
break;
case 9808045:
return 1194; //蝎式手枪改进
break;
case 9808046:
return 1191; //蝎式手枪破损
break;
case 9808050:
return 1172; //沙漠之鹰手枪修复
break;
case 9808051:
return 1173; //沙漠之鹰手枪完好
break;
case 9808052:
return 1174; //沙漠之鹰手枪改进
break;
case 9808053:
return 1171; //沙漠之鹰手枪破损
break;
case 9808057:
return 2; //TMP_9手枪修复  没有
break;
case 9808058:
return 3; //TMP_9手枪完好
break;
case 9808059:
return 4; //TMP_9手枪改进
break;
case 9808060:
return 1150; //信号枪
break;
case 9808061:
return 1; //TMP_9手枪破损
break;
case 9809001:
return 1411; //十字弩破损
break;
case 9809002:
return 1412; //十字弩修复
break;
case 9809003:
return 1413; //十字弩完好
break;
case 9809009:
return 1429; //爆炸猎弓骑警
break;
case 9809010:
return 1429; //爆炸猎弓
break;
case 9810001:
return 931; //S686霰弹枪破损
break;
case 9810002:
return 932; //S686霰弹枪修复
break;
case 9810003:
return 933; //S686霰弹枪完好
break;
case 9810008:
return 921; //S1897霰弹枪破损
break;
case 9810009:
return 922; //S1897霰弹枪修复
break;
case 9810010:
return 923; //S1897霰弹枪完好
break;
case 9810015:
return 915; //S12K霰弹枪精制
break;
case 9810016:
return 912; //S12K霰弹枪修复
break;
case 9810017:
return 913; //S12K霰弹枪完好
break;
case 9810018:
return 914; //S12K霰弹枪改进
break;
case 9810022:
return 902; //DBS霰弹枪修复
break;
case 9810023:
return 903; //DBS霰弹枪完好
break;
case 9810024:
return 904; //DBS霰弹枪改进
break;
case 9810025:
return 905; //DBS霰弹枪精制
break;
case 9810029:
return 2; //SPAS_12霰弹枪修复  没有
break;
case 9810030:
return 3; //SPAS_12霰弹枪完好
break;
case 9810031:
return 4; //SPAS_12霰弹枪改进
break;
case 9810032:
return 5; //SPAS_12霰弹枪精制
break;
case 9810036:
return 2; //AA12_G霰弹枪修复  没有
break;
case 9810037:
return 3; //AA12_G霰弹枪完好
break;
case 9810038:
return 4; //AA12_G霰弹枪改进
break;
case 9810041:
return 5; //AA12_G霰弹枪精制
break;
case 9811001:
return 351; //UZI冲锋枪破损
break;
case 9811002:
return 352; //UZI冲锋枪修复
break;
case 9811003:
return 353; //UZI冲锋枪完好
break;
case 9811004:
return 354; //UZI冲锋枪改进
break;
case 9811008:
return 341; //UMP45冲锋枪破损
break;
case 9811009:
return 342; //UMP45冲锋枪修复
break;
case 9811010:
return 343; //UMP45冲锋枪完好
break;
case 9811011:
return 344; //UMP45冲锋枪改进
break;
case 9811015:
return 386; //维克托冲锋枪卓越
break;
case 9811016:
return 383; //维克托冲锋枪完好
break;
case 9811017:
return 384; //维克托冲锋枪改进
break;
case 9811018:
return 385; //维克托冲锋枪精制
break;
case 9811019:
return 386; //维克托冲锋枪卓越
break;
case 9811020:
return 388; //维克托冲锋枪黑鹰
break;
case 9811021:
return 387; //维克托冲锋枪铁爪
break;
case 9811022:
return 371; //汤姆逊冲锋枪破损
break;
case 9811023:
return 372; //汤姆逊冲锋枪修复
break;
case 9811024:
return 373; //汤姆逊冲锋枪完好
break;
case 9811025:
return 374; //汤姆逊冲锋枪改进
break;
case 9811029:
return 361; //野牛冲锋枪破损
break;
case 9811030:
return 362; //野牛冲锋枪修复
break;
case 9811031:
return 363; //野牛冲锋枪完好
break;
case 9811036:
return 326; //MP5K冲锋枪卓越
break;
case 9811037:
return 323; //MP5K冲锋枪完好
break;
case 9811038:
return 324; //MP5K冲锋枪改进
break;
case 9811039:
return 325; //MP5K冲锋枪精制
break;
case 9811040:
return 326; //MP5K冲锋枪卓越
break;
case 9811041:
return 328; //MP5K冲锋枪黑鹰
break;
case 9811042:
return 327; //MP5K冲锋枪铁爪
break;
case 9811043:
return 2; //AKS_74U冲锋枪修复   没有
break;
case 9811044:
return 3; //AKS_74U冲锋枪完好
break;
case 9811045:
return 4; //AKS_74U冲锋枪改进
break;
case 9811046:
return 5; //AKS_74U冲锋枪精制
break;
case 9811047:
return 6; //AKS_74U冲锋枪卓越
break;
case 9811048:
return 7; //AKS_74U冲锋枪铁爪
break;
case 9811049:
return 8; //AKS_74U冲锋枪黑鹰
break;
case 9811050:
return 336; //P90冲锋枪卓越
break;
case 9811051:
return 333; //P90冲锋枪完好
break;
case 9811052:
return 334; //P90冲锋枪改进
break;
case 9811053:
return 335; //P90冲锋枪精制
break;
case 9811054:
return 336; //P90冲锋枪卓越
break;
case 9811055:
return 338; //P90冲锋枪黑鹰
break;
case 9811056:
return 337; //P90冲锋枪铁爪
break;
case 9812002:
return 56; //AKM突击步枪卓越
break;
case 9812003:
return 53; //AKM突击步枪完好
break;
case 9812004:
return 54; //AKM突击步枪改进
break;
case 9812005:
return 55; //AKM突击步枪精制
break;
case 9812006:
return 56; //AKM突击步枪卓越
break;
case 9812007:
return 58; //AKM突击步枪黑鹰
break;
case 9812008:
return 57; //AKM突击步枪铁爪
break;
case 9812009:
return 91; //M16A4突击步枪破损
break;
case 9812010:
return 92; //M16A4突击步枪修复
break;
case 9812011:
return 93; //M16A4突击步枪完好
break;
case 9812012:
return 94; //M16A4突击步枪改进
break;
case 9812015:
return 46; //SCAR_L突击步枪卓越
break;
case 9812016:
return 43; //SCAR_L突击步枪完好
break;
case 9812017:
return 44; //SCAR_L突击步枪改进
break;
case 9812018:
return 45; //SCAR_L突击步枪精制
break;
case 9812019:
return 46; //SCAR_L突击步枪卓越
break;
case 9812020:
return 48; //SCAR_L突击步枪黑鹰
break;
case 9812021:
return 47; //SCAR_L突击步枪铁爪
break;
case 9812022:
return 27; //M416突击步枪铁爪
break;
case 9812023:
return 26; //M416突击步枪卓越
break;
case 9812024:
return 23; //M416突击步枪完好
break;
case 9812025:
return 24; //M416突击步枪改进
break;
case 9812026:
return 25; //M416突击步枪精制
break;
case 9812027:
return 26; //M416突击步枪卓越
break;
case 9812028:
return 28; //M416突击步枪黑鹰
break;
case 9812029:
return 126; //狗砸突击步枪卓越
break;
case 9812030:
return 124; //狗砸突击步枪改进
break;
case 9812031:
return 125; //狗砸突击步枪精制
break;
case 9812032:
return 126; //狗砸突击步枪卓越
break;
case 9812033:
return 128; //狗砸突击步枪黑鹰
break;
case 9812034:
return 127; //狗砸突击步枪铁爪
break;
case 9812036:
return 76; //AUG突击步枪卓越
break;
case 9812037:
return 74; //AUG突击步枪改进
break;
case 9812038:
return 75; //AUG突击步枪精制
break;
case 9812039:
return 76; //AUG突击步枪卓越
break;
case 9812040:
return 78; //AUG突击步枪黑鹰
break;
case 9812041:
return 77; //AUG突击步枪铁爪
break;
case 9812043:
return 66; //QBZ突击步枪卓越
break;
case 9812044:
return 63; //QBZ突击步枪完好
break;
case 9812045:
return 64; //QBZ突击步枪改进
break;
case 9812046:
return 65; //QBZ突击步枪精制
break;
case 9812047:
return 66; //QBZ突击步枪卓越
break;
case 9812048:
return 68; //QBZ突击步枪黑鹰
break;
case 9812049:
return 67; //QBZ突击步枪铁爪
break;
case 9812050:
return 36; //M762突击步枪卓越
break;
case 9812051:
return 33; //M762突击步枪完好
break;
case 9812052:
return 34; //M762突击步枪改进
break;
case 9812053:
return 35; //M762突击步枪精制
break;
case 9812054:
return 36; //M762突击步枪卓越
break;
case 9812055:
return 38; //M762突击步枪黑鹰
break;
case 9812056:
return 37; //M762突击步枪铁爪
break;
case 9812057:
return 101; //MK47突击步枪破损
break;
case 9812058:
return 102; //MK47突击步枪修复
break;
case 9812059:
return 103; //MK47突击步枪完好
break;
case 9812060:
return 104; //MK47突击步枪改进
break;
case 9812064:
return 86; //G36C突击步枪卓越
break;
case 9812065:
return 83; //G36C突击步枪完好
break;
case 9812066:
return 84; //G36C突击步枪改进
break;
case 9812067:
return 85; //G36C突击步枪精制
break;
case 9812068:
return 86; //G36C突击步枪卓越
break;
case 9812069:
return 88; //G36C突击步枪黑鹰
break;
case 9812070:
return 87; //G36C突击步枪铁爪
break;
case 9812071:
return 311; //AC_VAL突击步枪破损
break;
case 9812072:
return 312; //AC_VAL突击步枪修复
break;
case 9812073:
return 313; //AC_VAL突击步枪完好
break;
case 9812074:
return 314; //AC_VAL突击步枪改进
break;
case 9812078:
return 116; //蜜獾突击步枪卓越
break;
case 9812079:
return 113; //蜜獾突击步枪完好
break;
case 9812080:
return 114; //蜜獾突击步枪改进
break;
case 9812081:
return 115; //蜜獾突击步枪精制
break;
case 9812082:
return 116; //蜜獾突击步枪卓越
break;
case 9812083:
return 118; //蜜獾突击步枪黑鹰
break;
case 9812084:
return 117; //蜜獾突击步枪铁爪
break;
case 9812085:
return 6; //FAMAS突击步枪卓越  没有
break;
case 9812086:
return 3; //FAMAS突击步枪完好
break;
case 9812087:
return 4; //FAMAS突击步枪改进
break;
case 9812088:
return 5; //FAMAS突击步枪精制
break;
case 9812089:
return 6; //FAMAS突击步枪卓越
break;
case 9812090:
return 8; //FAMAS突击步枪黑鹰
break;
case 9812091:
return 7; //FAMAS突击步枪铁爪
break;
case 9812092:
return 29; //M416卡德
break;
case 9813001:
return 556; //M249轻机枪卓越
break;
case 9813002:
return 554; //M249轻机枪改进
break;
case 9813003:
return 555; //M249轻机枪精制
break;
case 9813004:
return 556; //M249轻机枪卓越
break;
case 9813005:
return 558; //M249轻机枪黑鹰
break;
case 9813006:
return 557; //M249轻机枪铁爪
break;
case 9813008:
return 1011; //DP_28轻机枪破损
break;
case 9813009:
return 1012; //DP_28轻机枪修复
break;
case 9813010:
return 1013; //DP_28轻机枪完好
break;
case 9813022:
return 1036; //MG3轻机枪卓越
break;
case 9813023:
return 1034; //MG3轻机枪改进
break;
case 9813024:
return 1035; //MG3轻机枪精制
break;
case 9813025:
return 1036; //MG3轻机枪卓越
break;
case 9813026:
return 1038; //MG3轻机枪黑鹰
break;
case 9813027:
return 1037; //MG3轻机枪铁爪
break;
case 9813029:
return 6; //PKM轻机枪卓越  没有
break;
case 9813030:
return 4; //PKM轻机枪改进
break;
case 9813031:
return 5; //PKM轻机枪精制
break;
case 9813032:
return 6; //PKM轻机枪卓越
break;
case 9813033:
return 8; //PKM轻机枪黑鹰
break;
case 9813034:
return 7; //PKM轻机枪铁爪
break;
case 9814001:
return 532; //_98K狙击枪修复
break;
case 9814002:
return 533; //_98K狙击枪完好
break;
case 9814003:
return 534; //_98K狙击枪改进
break;
case 9814008:
return 556; //M24狙击枪卓越
break;
case 9814009:
return 553; //M24狙击枪完好
break;
case 9814010:
return 554; //M24狙击枪改进
break;
case 9814011:
return 555; //M24狙击枪精制
break;
case 9814012:
return 556; //M24狙击枪卓越
break;
case 9814013:
return 558; //M24狙击枪黑鹰
break;
case 9814014:
return 557; //M24狙击枪铁爪
break;
case 9814015:
return 516; //AWM狙击枪卓越
break;
case 9814016:
return 514; //AWM狙击枪改进
break;
case 9814017:
return 515; //AWM狙击枪精制
break;
case 9814018:
return 516; //AWM狙击枪卓越
break;
case 9814019:
return 518; //AWM狙击枪黑鹰
break;
case 9814020:
return 517; //AWM狙击枪铁爪
break;
case 9814022:
return 571; //莫辛纳甘狙击枪破损
break;
case 9814023:
return 572; //莫辛纳甘狙击枪修复
break;
case 9814024:
return 573; //莫辛纳甘狙击枪完好
break;
case 9814029:
return 561; //Win94狙击枪破损
break;
case 9814030:
return 562; //Win94狙击枪修复
break;
case 9814031:
return 563; //Win94狙击枪完好
break;
case 9814036:
return 526; //AMR狙击枪卓越
break;
case 9814037:
return 524; //AMR狙击枪改进
break;
case 9814038:
return 525; //AMR狙击枪精制
break;
case 9814039:
return 526; //AMR狙击枪卓越
break;
case 9814040:
return 528; //AMR狙击枪黑鹰
break;
case 9814041:
return 527; //AMR狙击枪铁爪
break;
case 9814043:
return 546; //M200狙击枪卓越
break;
case 9814044:
return 543; //M200狙击枪完好
break;
case 9814045:
return 544; //M200狙击枪改进
break;
case 9814046:
return 545; //M200狙击枪精制
break;
case 9814047:
return 546; //M200狙击枪卓越
break;
case 9814048:
return 548; //M200狙击枪黑鹰
break;
case 9814049:
return 547; //M200狙击枪铁爪
break;
case 9814050:
return 4; //SVD狙击枪改进  没有
break;
case 9814051:
return 5; //SVD狙击枪精制
break;
case 9814052:
return 6; //SVD狙击枪卓越
break;
case 9814053:
return 6; //SVD狙击枪卓越
break;
case 9815001:
return 786; //SKS射手步枪卓越
break;
case 9815002:
return 783; //SKS射手步枪完好
break;
case 9815003:
return 784; //SKS射手步枪改进
break;
case 9815004:
return 785; //SKS射手步枪精制
break;
case 9815005:
return 786; //SKS射手步枪卓越
break;
case 9815006:
return 788; //SKS射手步枪黑鹰
break;
case 9815007:
return 787; //SKS射手步枪铁爪
break;
case 9815008:
return 801; //VSS射手步枪破损
break;
case 9815009:
return 802; //VSS射手步枪修复
break;
case 9815010:
return 803; //VSS射手步枪完好
break;
case 9815015:
return 751; //Mini14射手步枪破损
break;
case 9815016:
return 752; //Mini14射手步枪修复
break;
case 9815017:
return 753; //Mini14射手步枪完好
break;
case 9815018:
return 754; //Mini14射手步枪改进
break;
case 9815022:
return 736; //MK14射手步枪卓越
break;
case 9815023:
return 733; //MK14射手步枪完好
break;
case 9815024:
return 734; //MK14射手步枪改进
break;
case 9815025:
return 735; //MK14射手步枪精制
break;
case 9815026:
return 736; //MK14射手步枪卓越
break;
case 9815027:
return 738; //MK14射手步枪黑鹰
break;
case 9815028:
return 737; //MK14射手步枪铁爪
break;
case 9815029:
return 796; //SLR射手步枪卓越
break;
case 9815030:
return 793; //SLR射手步枪完好
break;
case 9815031:
return 794; //SLR射手步枪改进
break;
case 9815032:
return 795; //SLR射手步枪精制
break;
case 9815033:
return 796; //SLR射手步枪卓越
break;
case 9815034:
return 798; //SLR射手步枪黑鹰
break;
case 9815035:
return 797; //SLR射手步枪铁爪
break;
case 9815036:
return 771; //QBU射手步枪破损
break;
case 9815037:
return 772; //QBU射手步枪修复
break;
case 9815038:
return 773; //QBU射手步枪完好
break;
case 9815039:
return 774; //QBU射手步枪改进
break;
case 9815043:
return 716; //M417射手步枪卓越
break;
case 9815044:
return 713; //M417射手步枪完好
break;
case 9815045:
return 714; //M417射手步枪改进
break;
case 9815046:
return 715; //M417射手步枪精制
break;
case 9815047:
return 716; //M417射手步枪卓越
break;
case 9815048:
return 718; //M417射手步枪黑鹰
break;
case 9815049:
return 717; //M417射手步枪铁爪
break;
case 9815050:
return 746; //MK20_H射手步枪卓越
break;
case 9815051:
return 743; //MK20_H射手步枪完好
break;
case 9815052:
return 744; //MK20_H射手步枪改进
break;
case 9815053:
return 745; //MK20_H射手步枪精制
break;
case 9815054:
return 746; //MK20_H射手步枪卓越
break;
case 9815055:
return 748; //MK20_H射手步枪黑鹰
break;
case 9815056:
return 747; //MK20_H射手步枪铁爪
break;
case 9815064:
return 726; //MK12射手步枪卓越
break;
case 9815065:
return 723; //MK12射手步枪完好
break;
case 9815066:
return 724; //MK12射手步枪改进
break;
case 9815067:
return 725; //MK12射手步枪精制
break;
case 9815068:
return 726; //MK12射手步枪卓越
break;
case 9815069:
return 728; //MK12射手步枪黑鹰
break;
case 9815070:
return 727; //MK12射手步枪铁爪
break;
// case 9815071:
// return 9; //M134_装甲重机枪  没有
break;
default:
return 0;
break;}
return 0;
}


char *GetHol(int Wuqi) {
  switch (Wuqi) {
//突击步枪
    case 101008:
      return "M762";
      break;
    case 1010081:
      return "M762破损";
      break;
    case 1010082:
      return "M762修复";
      break;
    case 1010083:
      return "M762完好";
      break;
    case 1010084:
      return "M762改进";
      break;
    case 1010085:
      return "M762精致";
      break;
    case 1010086:
      return "M762独眼";
      break;
    case 1010087:
      return "M762钢铁";
      break;

    case 101001:
      return "AKM";
      break;
    case 1010011:
      return "AKM破损";
      break;
    case 1010012:
      return "AKM修复";
      break;
    case 1010013:
      return "AKM完好";
      break;
    case 1010014:
      return "AKM改进";
      break;
    case 1010015:
      return "AKM精致";
      break;
    case 1010016:
      return "AKM独眼";
      break;
    case 1010017:
      return "AKM钢铁";
      break;

    case 101004:
      return "M416";
      break;
    case 1010041:
      return "M416破损";
      break;
    case 1010042:
      return "M416修复";
      break;
    case 1010043:
      return "M416完好";
      break;
    case 1010044:
      return "M416改进";
      break;
    case 1010045:
      return "M416精致";
      break;
    case 1010046:
      return "M416独眼";
      break;
    case 1010047:
      return "M416钢铁";
      break;

    case 101003:
      return "SCAR-L";
      break;
    case 1010031:
      return "SCAR-L破损";
      break;
    case 1010032:
      return "SCAR-L修复";
      break;
    case 1010033:
      return "SCAR-L完好";
      break;
    case 1010034:
      return "SCAR-L改进";
      break;
    case 1010035:
      return "SCAR-L精致";
      break;
    case 1010036:
      return "SCAR-L独眼";
      break;
    case 1010037:
      return "SCAR-L钢铁";
      break;

    case 101002:
      return "M16A4";
      break;
    case 1010021:
      return "M16A4破损";
      break;
    case 1010022:
      return "M16A4修复";
      break;
    case 1010023:
      return "M16A4完好";
      break;
    case 1010024:
      return "M16A4改进";
      break;
    case 1010025:
      return "M16A4精致";
      break;
    case 1010026:
      return "M16A4独眼";
      break;
    case 1010027:
      return "M16A4钢铁";
      break;

    case 101009:
      return "Mk47";
      break;
    case 1010091:
      return "Mk47破损";
      break;
    case 1010092:
      return "Mk47修复";
      break;
    case 1010093:
      return "Mk47完好";
      break;
    case 1010094:
      return "Mk47改进";
      break;
    case 1010095:
      return "Mk47精致";
      break;
    case 1010096:
      return "Mk47独眼";
      break;
    case 1010097:
      return "Mk47钢铁";
      break;

    case 101006:
      return "AUG";
      break;
    case 1010061:
      return "AUG破损";
      break;
    case 1010062:
      return "AUG修复";
      break;
    case 1010063:
      return "AUG完好";
      break;
    case 1010064:
      return "AUG改进";
      break;
    case 1010065:
      return "AUG精致";
      break;
    case 1010066:
      return "AUG独眼";
      break;
    case 1010067:
      return "AUG钢铁";
      break;

    case 101005:
      return "Groza";
      break;
    case 1010051:
      return "Groza破损";
      break;
    case 1010052:
      return "Groza修复";
      break;
    case 1010053:
      return "Groza完好";
      break;
    case 1010054:
      return "Groza改进";
      break;
    case 1010055:
      return "Groza精致";
      break;
    case 1010056:
      return "Groza独眼";
      break;
    case 1010057:
      return "Groza钢铁";
      break;

    case 101010:
      return "G36C";
      break;
    case 1010101:
      return "G36C破损";
      break;
    case 1010102:
      return "G36C修复";
      break;
    case 1010103:
      return "G36C完好";
      break;
    case 1010104:
      return "G36C改进";
      break;
    case 1010105:
      return "G36C精致";
      break;
    case 1010106:
      return "G36C独眼";
      break;
    case 1010107:
      return "G36C钢铁";
      break;

    case 101007:
      return "QBZ";
      break;
    case 1010071:
      return "QBZ破损";
      break;
    case 1010072:
      return "QBZ修复";
      break;
    case 1010073:
      return "QBZ完好";
      break;
    case 1010074:
      return "QBZ改进";
      break;
    case 1010075:
      return "QBZ精致";
      break;
    case 1010076:
      return "QBZ独眼";
      break;
    case 1010077:
      return "QBZ钢铁";
      break;

    case 101011:
      return "AC-VAL";
      break;
    case 1010111:
      return "AC-VAL破损";
      break;
    case 1010112:
      return "AC-VAL修复";
      break;
    case 1010113:
      return "AC-VAL完好";
      break;
    case 1010114:
      return "AC-VAL改进";
      break;
    case 1010115:
      return "AC-VAL精致";
      break;
    case 1010116:
      return "AC-VAL独眼";
      break;
    case 1010117:
      return "AC-VAL钢铁";
      break;

    case 101012:
      return "蜜獾突击步枪";
      break;
    case 1010121:
      return "蜜獾突击步枪破损";
      break;
    case 1010122:
      return "蜜獾突击步枪修复";
      break;
    case 1010123:
      return "蜜獾突击步枪完好";
      break;
    case 1010124:
      return "蜜獾突击步枪改进";
      break;
    case 1010125:
      return "蜜獾突击步枪精致";
      break;
    case 1010126:
      return "蜜獾突击步枪独眼";
      break;
    case 1010127:
      return "蜜獾突击步枪钢铁";
      break;
//连狙
    case 103009:
      return "SLR";
      break;
    case 1030091:
      return "SLR破损";
      break;
    case 1030092:
      return "SLR修复";
      break;
    case 1030093:
      return "SLR完好";
      break;
    case 1030094:
      return "SLR改进";
      break;
    case 1030095:
      return "SLR精致";
      break;
    case 1030096:
      return "SLR独眼";
      break;
    case 1030097:
      return "SLR钢铁";
      break;

    case 103005:
      return "VSS";
      break;
    case 1030051:
      return "VSS破损";
      break;
    case 1030052:
      return "VSS修复";
      break;
    case 1030053:
      return "VSS完好";
      break;
    case 1030054:
      return "VSS改进";
      break;
    case 1030055:
      return "VSS精致";
      break;
    case 1030056:
      return "VSS独眼";
      break;
    case 1030057:
      return "VSS钢铁";
      break;

    case 103006:
      return "Mini14";
      break;
    case 1030061:
      return "Mini14破损";
      break;
    case 1030062:
      return "Mini14修复";
      break;
    case 1030063:
      return "Mini14完好";
      break;
    case 1030064:
      return "Mini14改进";
      break;
    case 1030065:
      return "Mini14精致";
      break;
    case 1030066:
      return "Mini14独眼";
      break;
    case 1030067:
      return "Mini14钢铁";
      break;

    case 103010:
      return "QBU";
      break;
    case 1030101:
      return "QBU破损";
      break;
    case 1030102:
      return "QBU修复";
      break;
    case 1030103:
      return "QBU完好";
      break;
    case 1030104:
      return "QBU改进";
      break;
    case 1030105:
      return "QBU精致";
      break;
    case 1030106:
      return "QBU独眼";
      break;
    case 1030107:
      return "QBU钢铁";
      break;

    case 103004:
      return "SKS";
      break;
    case 1030041:
      return "SKS破损";
      break;
    case 1030042:
      return "SKS修复";
      break;
    case 1030043:
      return "SKS完好";
      break;
    case 1030044:
      return "SKS改进";
      break;
    case 1030045:
      return "SKS精致";
      break;
    case 1030046:
      return "SKS独眼";
      break;
    case 1030047:
      return "SKS钢铁";
      break;

    case 103007:
      return "MK14";
      break;
    case 1030071:
      return "MK14破损";
      break;
    case 1030072:
      return "MK14修复";
      break;
    case 1030073:
      return "MK14完好";
      break;
    case 1030074:
      return "MK14改进";
      break;
    case 1030075:
      return "MK14精致";
      break;
    case 1030076:
      return "MK14独眼";
      break;
    case 1030077:
      return "MK14钢铁";
      break;

    case 103014:
      return "MK20-H";
      break;
    case 1030141:
      return "MK20-H破损";
      break;
    case 1030142:
      return "MK20-H修复";
      break;
    case 1030143:
      return "MK20-H完好";
      break;
    case 1030144:
      return "MK20-H改进";
      break;
    case 1030145:
      return "MK20-H精致";
      break;
    case 1030146:
      return "MK20-H独眼";
      break;
    case 1030147:
      return "MK20-H钢铁";
      break;

    case 103013:
      return "M4117";
      break;
    case 1030131:
      return "M4117破损";
      break;
    case 1030132:
      return "M4117修复";
      break;
    case 1030133:
      return "M4117完好";
      break;
    case 1030134:
      return "M4117改进";
      break;
    case 1030135:
      return "M4117精致";
      break;
    case 1030136:
      return "M4117独眼";
      break;
    case 1030137:
      return "M4117钢铁";
      break;
//连狙
    case 103012:
      return "ARM";
      break;
    case 1030121:
      return "ARM破损";
      break;
    case 1030122:
      return "ARM修复";
      break;
    case 1030123:
      return "ARM完好";
      break;
    case 1030124:
      return "ARM改进";
      break;
    case 1030125:
      return "ARM精致";
      break;
    case 1030126:
      return "ARM独眼";
      break;
    case 1030127:
      return "ARM钢铁";
      break;

    case 103003:
      return "AWM";
      break;
    case 1030031:
      return "AWM破损";
      break;
    case 1030032:
      return "AWM修复";
      break;
    case 1030033:
      return "AWM完好";
      break;
    case 1030034:
      return "AWM改进";
      break;
    case 1030035:
      return "AWM精致";
      break;
    case 1030036:
      return "AWM独眼";
      break;
    case 1030037:
      return "AWM钢铁";
      break;

    case 103002:
      return "M24";
      break;
    case 1030021:
      return "M24破损";
      break;
    case 1030022:
      return "M24修复";
      break;
    case 1030023:
      return "M24完好";
      break;
    case 1030024:
      return "M24改进";
      break;
    case 1030025:
      return "M24精致";
      break;
    case 1030026:
      return "M24独眼";
      break;
    case 1030027:
      return "M24钢铁";
      break;

    case 103011:
      return "莫幸纳甘";
      break;
    case 1030111:
      return "莫幸纳甘破损";
      break;
    case 1030112:
      return "莫幸纳甘修复";
      break;
    case 1030113:
      return "莫幸纳甘完好";
      break;
    case 1030114:
      return "莫幸纳甘改进";
      break;
    case 1030115:
      return "莫幸纳甘精致";
      break;
    case 1030116:
      return "莫幸纳甘独眼";
      break;
    case 1030117:
      return "莫幸纳甘钢铁";
      break;

    case 103001:
      return "Kar98K";
      break;
    case 1030011:
      return "Kar98K破损";
      break;
    case 1030012:
      return "Kar98K修复";
      break;
    case 1030013:
      return "Kar98K完好";
      break;
    case 1030014:
      return "Kar98K改进";
      break;
    case 1030015:
      return "Kar98K精致";
      break;
    case 1030016:
      return "Kar98K独眼";
      break;
    case 1030017:
      return "Kar98K钢铁";
      break;

    case 103008:
      return "Win94";
      break;
    case 1030081:
      return "Win94破损";
      break;
    case 1030082:
      return "Win94修复";
      break;
    case 1030083:
      return "Win94完好";
      break;
    case 1030084:
      return "Win94改进";
      break;
    case 1030085:
      return "Win94精致";
      break;
    case 1030086:
      return "Win94独眼";
      break;
    case 1030087:
      return "Win94钢铁";
      break;
//机关枪
    case 105001:
      return "M249";
      break;
    case 1050011:
      return "M249破损";
      break;
    case 1050012:
      return "M249修复";
      break;
    case 1050013:
      return "M249完好";
      break;
    case 1050014:
      return "M249改进";
      break;
    case 1050015:
      return "M249精致";
      break;
    case 1050016:
      return "M249独眼";
      break;
    case 1050017:
      return "M249钢铁";
      break;

    case 105002:
      return "DP-28";
      break;
    case 1050021:
      return "DP-28破损";
      break;
    case 1050022:
      return "DP-28修复";
      break;
    case 1050023:
      return "DP-28完好";
      break;
    case 1050024:
      return "DP-28改进";
      break;
    case 1050025:
      return "DP-28精致";
      break;
    case 1050026:
      return "DP-28独眼";
      break;
    case 1050027:
      return "DP-28钢铁";
      break;

    case 105010:
      return "MG3";
      break;
    case 1050101:
      return "MG3破损";
      break;
    case 1050102:
      return "MG3修复";
      break;
    case 1050103:
      return "MG3完好";
      break;
    case 1050104:
      return "MG3改进";
      break;
    case 1050105:
      return "MG3精致";
      break;
    case 1050106:
      return "MG3独眼";
      break;
    case 1050107:
      return "MG3钢铁";
      break;

    case 107001:
      return "十字弩";
      break;
    case 1070011:
      return "十字弩破损";
      break;
    case 1070012:
      return "十字弩修复";
      break;
    case 1070013:
      return "十字弩完好";
      break;
    case 1070014:
      return "十字弩改进";
      break;
    case 1070015:
      return "十字弩精致";
      break;
    case 1070016:
      return "十字弩独眼";
      break;
    case 1070017:
      return "十字弩钢铁";
      break;

    case 107007:
      return "爆炸猎弓";
      break;
    case 1070071:
      return "爆炸猎弓破损";
      break;
    case 1070072:
      return "爆炸猎弓修复";
      break;
    case 1070073:
      return "爆炸猎弓完好";
      break;
    case 1070074:
      return "爆炸猎弓改进";
      break;
    case 1070075:
      return "爆炸猎弓精致";
      break;
    case 1070076:
      return "爆炸猎弓独眼";
      break;
    case 1070077:
      return "爆炸猎弓钢铁";
      break;
//冲锋枪
    case 102001:
      return "UZI";
      break;
    case 1020011:
      return "UZI破损";
      break;
    case 1020012:
      return "UZI修复";
      break;
    case 1020013:
      return "UZI完好";
      break;
    case 1020014:
      return "UZI改进";
      break;
    case 1020015:
      return "UZI精致";
      break;
    case 1020016:
      return "UZI独眼";
      break;
    case 1020017:
      return "UZI钢铁";
      break;

    case 102003:
      return "Vector";
      break;
    case 1020031:
      return "Vector破损";
      break;
    case 1020032:
      return "Vector修复";
      break;
    case 1020033:
      return "Vector完好";
      break;
    case 1020034:
      return "Vector改进";
      break;
    case 1020035:
      return "Vector精致";
      break;
    case 1020036:
      return "Vector独眼";
      break;
    case 1020037:
      return "Vector钢铁";
      break;
      
    case 100103:
      return "PP-19";
      break;
    case 1001031:
      return "PP-19破损";
      break;
    case 1001032:
      return "PP-19修复";
      break;
    case 1001033:
      return "PP-19完好";
      break;
    case 1001034:
      return "PP-19改进";
      break;
    case 1001035:
      return "PP-19精致";
      break;
    case 1001036:
      return "PP-19独眼";
      break;
    case 1001037:
      return "PP-19钢铁";
      break;

    case 102007:
      return "MP5K";
      break;
    case 1020071:
      return "MP5K破损";
      break;
    case 1020072:
      return "MP5K修复";
      break;
    case 1020073:
      return "MP5K完好";
      break;
    case 1020074:
      return "MP5K改进";
      break;
    case 1020075:
      return "MP5K精致";
      break;
    case 1020076:
      return "MP5K独眼";
      break;
    case 1020077:
      return "MP5K钢铁";
      break;

    case 102002:
      return "UMP-45";
      break;
    case 1020021:
      return "UMP-45破损";
      break;
    case 1020022:
      return "UMP-45修复";
      break;
    case 1020023:
      return "UMP-45完好";
      break;
    case 1020024:
      return "UMP-45改进";
      break;
    case 1020025:
      return "UMP-45精致";
      break;
    case 1020026:
      return "UMP-45独眼";
      break;
    case 1020027:
      return "UMP-45钢铁";
      break;

    case 102004:
      return "汤姆逊";
      break;
    case 1020041:
      return "汤姆逊破损";
      break;
    case 1020042:
      return "汤姆逊修复";
      break;
    case 1020043:
      return "汤姆逊完好";
      break;
    case 1020044:
      return "汤姆逊改进";
      break;
    case 1020045:
      return "汤姆逊精致";
      break;
    case 1020046:
      return "汤姆逊独眼";
      break;
    case 1020047:
      return "汤姆逊钢铁";
      break;

    case 102105:
      return "P90";
      break;
    case 1021051:
      return "P90破损";
      break;
    case 1021052:
      return "P90修复";
      break;
    case 1021053:
      return "P90完好";
      break;
    case 1021054:
      return "P90改进";
      break;
    case 1021055:
      return "P90精致";
      break;
    case 1021056:
      return "P90独眼";
      break;
    case 1021057:
      return "P90钢铁";
      break;

    case 102005:
      return "野牛";
      break;
    case 1020051:
      return "野牛破损";
      break;
    case 1020052:
      return "野牛修复";
      break;
    case 1020053:
      return "野牛完好";
      break;
    case 1020054:
      return "野牛改进";
      break;
    case 1020055:
      return "野牛精致";
      break;
    case 1020056:
      return "野牛独眼";
      break;
    case 1020057:
      return "野牛钢铁";
      break;
//霰弹枪
    case 104001:
      return "S686";
      break;
    case 1040011:
      return "S686破损";
      break;
    case 1040012:
      return "S686修复";
      break;
    case 1040013:
      return "S686完好";
      break;
    case 1040014:
      return "S686改进";
      break;
    case 1040015:
      return "S686精致";
      break;
    case 1040016:
      return "S686独眼";
      break;
    case 1040017:
      return "S686钢铁";
      break;

    case 104002:
      return "S1897";
      break;
    case 1040021:
      return "S1897破损";
      break;
    case 1040022:
      return "S1897修复";
      break;
    case 1040023:
      return "S1897完好";
      break;
    case 1040024:
      return "S1897改进";
      break;
    case 1040025:
      return "S1897精致";
      break;
    case 1040026:
      return "S1897独眼";
      break;
    case 1040027:
      return "S1897钢铁";
      break;

    case 104003:
      return "S12K";
      break;
    case 1040031:
      return "S12K破损";
      break;
    case 1040032:
      return "S12K修复";
      break;
    case 1040033:
      return "S12K完好";
      break;
    case 1040034:
      return "S12K改进";
      break;
    case 1040035:
      return "S12K精致";
      break;
    case 1040036:
      return "S12K独眼";
      break;
    case 1040037:
      return "S12K钢铁";
      break;

    case 104004:
      return "DBS";
      break;
    case 1040041:
      return "DBS破损";
      break;
    case 1040042:
      return "DBS修复";
      break;
    case 1040043:
      return "DBS完好";
      break;
    case 1040044:
      return "DBS改进";
      break;
    case 1040045:
      return "DBS精致";
      break;
    case 1040046:
      return "DBS独眼";
      break;
    case 1040047:
      return "DBS钢铁";
      break;

    case 104100:
      return "SPAS-12";
      break;
    case 1041001:
      return "SPAS-12破损";
      break;
    case 1041002:
      return "SPAS-12修复";
      break;
    case 1041003:
      return "SPAS-12完好";
      break;
    case 1041004:
      return "SPAS-12改进";
      break;
    case 1041005:
      return "SPAS-12精致";
      break;
    case 1041006:
      return "SPAS-12独眼";
      break;
    case 1041007:
      return "SPAS-12钢铁";
      break;
//投掷爆炸物
    case 602004:
      return "手榴弹";
      break;
    case 602003:
      return "燃烧瓶";
      break;
    case 602002:
      return "烟雾弹";
      break;
    case 602001:
      return "震撼弹";
      break;
//近战武器
    case 108003:
      return "镰刀";
      break;
    case 108002:
      return "撬棍";
      break;
    case 108001:
      return "大砍刀";
      break;
    case 108004:
      return "平底锅";
      break;
    case 0:
      return "拳头";
      break;
      case 9808001:
return "P92手枪(破损)";
      break;
case 9808002:
return "P92手枪(修复)";
      break;
case 9808003:
return "P92手枪(完好)";
      break;
case 9808008:
return "P1911手枪(破损)";
      break;
case 9808009:
return "P1911手枪(修复)";
      break;
case 9808010:
return "P1911手枪(完好)";
      break;
case 9808015:
return "R1895手枪(破损)";
      break;
case 9808016:
return "R1895手枪(修复)";
      break;
case 9808017:
return "R1895手枪(完好)";
      break;
case 9808022:
return "P18C手枪(破损)";
      break;
case 9808023:
return "P18C手枪(修复)";
      break;
case 9808024:
return "P18C手枪(完好)";
      break;
case 9808029:
return "R45手枪(破损)";
      break;
case 9808030:
return "R45手枪(修复)";
      break;
case 9808031:
return "R45手枪(完好)";
      break;
case 9808036:
return "短管霰弹枪(破损)";
      break;
case 9808037:
return "短管霰弹枪(修复)";
      break;
case 9808038:
return "短管霰弹枪(完好)";
      break;
case 9808043:
return "蝎式手枪(修复)";
      break;
case 9808044:
return "蝎式手枪(完好)";
      break;
case 9808045:
return "蝎式手枪(改进)";
      break;
case 9808046:
return "蝎式手枪(破损)";
      break;
case 9808050:
return "沙漠之鹰手枪(修复)";
      break;
case 9808051:
return "沙漠之鹰手枪(完好)";
      break;
case 9808052:
return "沙漠之鹰手枪(改进)";
      break;
case 9808053:
return "沙漠之鹰手枪(破损)";
      break;
case 9808057:
return "TMP-9手枪(修复)";
      break;
case 9808058:
return "TMP-9手枪(完好)";
      break;
case 9808059:
return "TMP-9手枪(改进)";
      break;
case 9808060:
return "空投信号枪";
      break;
case 9808061:
return "TMP-9手枪(破损)";
      break;
case 9809001:
return "十字弩(破损)";
      break;
case 9809002:
return "十字弩(修复)";
      break;
case 9809003:
return "十字弩(完好)";
      break;
case 9809009:
return "爆炸猎弓(骑警Boss)";
      break;
case 9809010:
return "爆炸猎弓·杰西";
      break;
case 9810001:
return "S686霰弹枪(破损)";
      break;
case 9810002:
return "S686霰弹枪(修复)";
      break;
case 9810003:
return "S686霰弹枪(完好)";
      break;
case 9810008:
return "S1897霰弹枪(破损)";
      break;
case 9810009:
return "S1897霰弹枪(修复)";
      break;
case 9810010:
return "S1897霰弹枪(完好)";
      break;
case 9810015:
return "S12K霰弹枪(精制)";
      break;
case 9810016:
return "S12K霰弹枪(修复)";
      break;
case 9810017:
return "S12K霰弹枪(完好)";
      break;
case 9810018:
return "S12K霰弹枪(改进)";
      break;
case 9810022:
return "DBS霰弹枪(修复)";
      break;
case 9810023:
return "DBS霰弹枪(完好)";
      break;
case 9810024:
return "DBS霰弹枪(改进)";
      break;
case 9810025:
return "DBS霰弹枪(精制)";
      break;
case 9810029:
return "SPAS-12霰弹枪(修复)";
      break;
case 9810030:
return "SPAS-12霰弹枪(完好)";
      break;
case 9810031:
return "SPAS-12霰弹枪(改进)";
      break;
case 9810032:
return "SPAS-12霰弹枪(精制)";
      break;
case 9810036:
return "AA12-G霰弹枪(修复)";
      break;
case 9810037:
return "AA12-G霰弹枪(完好)";
      break;
case 9810038:
return "AA12-G霰弹枪(改进)";
      break;
case 9810041:
return "AA12-G霰弹枪(精制)";
      break;
case 9811001:
return "UZI冲锋枪(破损)";
      break;
case 9811002:
return "UZI冲锋枪(修复)";
      break;
case 9811003:
return "UZI冲锋枪(完好)";
      break;
case 9811004:
return "UZI冲锋枪(改进)";
      break;
case 9811008:
return "UMP45冲锋枪(破损)";
      break;
case 9811009:
return "UMP45冲锋枪(修复)";
      break;
case 9811010:
return "UMP45冲锋枪(完好)";
      break;
case 9811011:
return "UMP45冲锋枪(改进)";
      break;
case 9811015:
return "Vector冲锋枪(卓越)";
      break;
case 9811016:
return "Vector冲锋枪(完好)";
      break;
case 9811017:
return "Vector冲锋枪(改进)";
      break;
case 9811018:
return "Vector冲锋枪(精制)";
      break;
case 9811019:
return "Vector冲锋枪(卓越)";
      break;
case 9811020:
return "Vector冲锋枪(黑鹰)";
      break;
case 9811021:
return "Vector冲锋枪(铁爪)";
      break;
case 9811022:
return "汤姆逊冲锋枪(破损)";
      break;
case 9811023:
return "汤姆逊冲锋枪(修复)";
      break;
case 9811024:
return "汤姆逊冲锋枪(完好)";
      break;
case 9811025:
return "汤姆逊冲锋枪(改进)";
      break;
case 9811029:
return "野牛冲锋枪(破损)";
      break;
case 9811030:
return "野牛冲锋枪(修复)";
      break;
case 9811031:
return "野牛冲锋枪(完好)";
      break;
case 9811036:
return "MP5K冲锋枪(卓越)";
      break;
case 9811037:
return "MP5K冲锋枪(完好)";
      break;
case 9811038:
return "MP5K冲锋枪(改进)";
      break;
case 9811039:
return "MP5K冲锋枪(精制)";
      break;
case 9811040:
return "MP5K冲锋枪(卓越)";
      break;
case 9811041:
return "MP5K冲锋枪(黑鹰)";
      break;
case 9811042:
return "MP5K冲锋枪(铁爪)";
      break;
case 9811043:
return "AKS-74U冲锋枪(卓越)";
      break;
case 9811044:
return "AKS-74U冲锋枪(完好)";
      break;
case 9811045:
return "AKS-74U冲锋枪(改进)";
      break;
case 9811046:
return "AKS-74U冲锋枪(精制)";
      break;
case 9811047:
return "AKS-74U冲锋枪(卓越)";
      break;
case 9811048:
return "AKS-74U冲锋枪(铁爪)";
      break;
case 9811049:
return "AKS-74U冲锋枪(黑鹰)";
      break;
case 9811050:
return "P90冲锋枪(卓越)";
      break;
case 9811051:
return "P90冲锋枪(完好)";
      break;
case 9811052:
return "P90冲锋枪(改进)";
      break;
case 9811053:
return "P90冲锋枪(精制)";
      break;
case 9811054:
return "P90冲锋枪(卓越)";
      break;
case 9811055:
return "P90冲锋枪(黑鹰)";
      break;
case 9811056:
return "P90冲锋枪(铁爪)";
      break;
case 9812002:
return "AKM突击步枪(卓越)";
      break;
case 9812003:
return "AKM突击步枪(完好)";
      break;
case 9812004:
return "AKM突击步枪(改进)";
      break;
case 9812005:
return "AKM突击步枪(精制)";
      break;
case 9812006:
return "AKM突击步枪(卓越)";
      break;
case 9812007:
return "AKM突击步枪(黑鹰)";
      break;
case 9812008:
return "AKM突击步枪(铁爪)";
      break;
case 9812009:
return "M16A4突击步枪(破损)";
      break;
case 9812010:
return "M16A4突击步枪(修复)";
      break;
case 9812011:
return "M16A4突击步枪(完好)";
      break;
case 9812012:
return "M16A4突击步枪(改进)";
      break;
case 9812015:
return "SCAR-L突击步枪(卓越)";
      break;
case 9812016:
return "SCAR-L突击步枪(完好)";
      break;
case 9812017:
return "SCAR-L突击步枪(改进)";
      break;
case 9812018:
return "SCAR-L突击步枪(精制)";
      break;
case 9812019:
return "SCAR-L突击步枪(卓越)";
      break;
case 9812020:
return "SCAR-L突击步枪(黑鹰)";
      break;
case 9812021:
return "SCAR-L突击步枪(铁爪)";
      break;
case 9812022:
return "M416突击步枪(铁爪)";
      break;
case 9812023:
return "M416突击步枪(卓越)";
      break;
case 9812024:
return "M416突击步枪(完好)";
      break;
case 9812025:
return "M416突击步枪(改进)";
      break;
case 9812026:
return "M416突击步枪(精制)";
      break;
case 9812027:
return "M416突击步枪(卓越)";
      break;
case 9812028:
return "M416突击步枪(黑鹰)";
      break;
case 9812029:
return "GROZA突击步枪(卓越)";
      break;
case 9812030:
return "GROZA突击步枪(改进)";
      break;
case 9812031:
return "GROZA突击步枪(精制)";
      break;
case 9812032:
return "GROZA突击步枪(卓越)";
      break;
case 9812033:
return "GROZA突击步枪(黑鹰)";
      break;
case 9812034:
return "GROZA突击步枪(铁爪)";
      break;
case 9812036:
return "AUG突击步枪(卓越)";
      break;
case 9812037:
return "AUG突击步枪(改进)";
      break;
case 9812038:
return "AUG突击步枪(精制)";
      break;
case 9812039:
return "AUG突击步枪(卓越)";
      break;
case 9812040:
return "AUG突击步枪(黑鹰)";
      break;
case 9812041:
return "AUG突击步枪(铁爪)";
      break;
case 9812043:
return "QBZ突击步枪(卓越)";
      break;
case 9812044:
return "QBZ突击步枪(完好)";
      break;
case 9812045:
return "QBZ突击步枪(改进)";
      break;
case 9812046:
return "QBZ突击步枪(精制)";
      break;
case 9812047:
return "QBZ突击步枪(卓越)";
      break;
case 9812048:
return "QBZ突击步枪(黑鹰)";
      break;
case 9812049:
return "QBZ突击步枪(铁爪)";
      break;
case 9812050:
return "M762突击步枪(卓越)";
      break;
case 9812051:
return "M762突击步枪(完好)";
      break;
case 9812052:
return "M762突击步枪(改进)";
      break;
case 9812053:
return "M762突击步枪(精制)";
      break;
case 9812054:
return "M762突击步枪(卓越)";
      break;
case 9812055:
return "M762突击步枪(黑鹰)";
      break;
case 9812056:
return "M762突击步枪(铁爪)";
      break;
case 9812057:
return "Mk47突击步枪(破损)";
      break;
case 9812058:
return "Mk47突击步枪(修复)";
      break;
case 9812059:
return "Mk47突击步枪(完好)";
      break;
case 9812060:
return "Mk47突击步枪(改进)";
      break;
case 9812064:
return "G36C突击步枪(卓越)";
      break;
case 9812065:
return "G36C突击步枪(完好)";
      break;
case 9812066:
return "G36C突击步枪(改进)";
      break;
case 9812067:
return "G36C突击步枪(精制)";
      break;
case 9812068:
return "G36C突击步枪(卓越)";
      break;
case 9812069:
return "G36C突击步枪(黑鹰)";
      break;
case 9812070:
return "G36C突击步枪(铁爪)";
      break;
case 9812071:
return "AC-VAL突击步枪(破损)";
      break;
case 9812072:
return "AC-VAL突击步枪(修复)";
      break;
case 9812073:
return "AC-VAL突击步枪(完好)";
      break;
case 9812074:
return "AC-VAL突击步枪(改进)";
      break;
case 9812078:
return "蜜獾突击步枪(卓越)";
      break;
case 9812079:
return "蜜獾突击步枪(完好)";
      break;
case 9812080:
return "蜜獾突击步枪(改进)";
      break;
case 9812081:
return "蜜獾突击步枪(精制)";
      break;
case 9812082:
return "蜜獾突击步枪(卓越)";
      break;
case 9812083:
return "蜜獾突击步枪(黑鹰)";
      break;
case 9812084:
return "蜜獾突击步枪(铁爪)";
      break;
case 9812085:
return "FAMAS突击步枪(卓越)";
      break;
case 9812086:
return "FAMAS突击步枪(完好)";
      break;
case 9812087:
return "FAMAS突击步枪(改进)";
      break;
case 9812088:
return "FAMAS突击步枪(精制)";
      break;
case 9812089:
return "FAMAS突击步枪(卓越)";
      break;
case 9812090:
return "FAMAS突击步枪(黑鹰)";
      break;
case 9812091:
return "FAMAS突击步枪(铁爪)";
      break;
case 9812092:
return "M416突击步枪·卡德尔";
      break;
case 9813001:
return "M249轻机枪(卓越)";
      break;
case 9813002:
return "M249轻机枪(改进)";
      break;
case 9813003:
return "M249轻机枪(精制)";
      break;
case 9813004:
return "M249轻机枪(卓越)";
      break;
case 9813005:
return "M249轻机枪(黑鹰)";
      break;
case 9813006:
return "M249轻机枪(铁爪)";
      break;
case 9813008:
return "DP-28轻机枪(破损)";
      break;
case 9813009:
return "DP-28轻机枪(修复)";
      break;
case 9813010:
return "DP-28轻机枪(完好)";
      break;
case 9813022:
return "MG3轻机枪(卓越)";
      break;
case 9813023:
return "MG3轻机枪(改进)";
      break;
case 9813024:
return "MG3轻机枪(精制)";
      break;
case 9813025:
return "MG3轻机枪(卓越)";
      break;
case 9813026:
return "MG3轻机枪(黑鹰)";
      break;
case 9813027:
return "MG3轻机枪(铁爪)";
      break;
case 9813029:
return "PKM轻机枪(卓越)";
      break;
case 9813030:
return "PKM轻机枪(改进)";
      break;
case 9813031:
return "PKM轻机枪(精制)";
      break;
case 9813032:
return "PKM轻机枪(卓越)";
      break;
case 9813033:
return "PKM轻机枪(黑鹰)";
      break;
case 9813034:
return "PKM轻机枪(铁爪)";
      break;
case 9814001:
return "Kar98K狙击枪(修复)";
      break;
case 9814002:
return "Kar98K狙击枪(完好)";
      break;
case 9814003:
return "Kar98K狙击枪(改进)";
      break;
case 9814008:
return "M24狙击枪(卓越)";
      break;
case 9814009:
return "M24狙击枪(完好)";
      break;
case 9814010:
return "M24狙击枪(改进)";
      break;
case 9814011:
return "M24狙击枪(精制)";
      break;
case 9814012:
return "M24狙击枪(卓越)";
      break;
case 9814013:
return "M24狙击枪(黑鹰)";
      break;
case 9814014:
return "M24狙击枪(铁爪)";
      break;
case 9814015:
return "AWM狙击枪(卓越)";
      break;
case 9814016:
return "AWM狙击枪(改进)";
      break;
case 9814017:
return "AWM狙击枪(精制)";
      break;
case 9814018:
return "AWM狙击枪(卓越)";
      break;
case 9814019:
return "AWM狙击枪(黑鹰)";
      break;
case 9814020:
return "AWM狙击枪(铁爪)";
      break;
case 9814022:
return "莫辛纳甘狙击枪(破损)";
      break;
case 9814023:
return "莫辛纳甘狙击枪(修复)";
      break;
case 9814024:
return "莫辛纳甘狙击枪(完好)";
      break;
case 9814029:
return "Win94狙击枪(破损)";
      break;
case 9814030:
return "Win94狙击枪(修复)";
      break;
case 9814031:
return "Win94狙击枪(完好)";
      break;
case 9814036:
return "AMR狙击枪(卓越)";
      break;
case 9814037:
return "AMR狙击枪(改进)";
      break;
case 9814038:
return "AMR狙击枪(精制)";
      break;
case 9814039:
return "AMR狙击枪(卓越)";
      break;
case 9814040:
return "AMR狙击枪(黑鹰)";
      break;
case 9814041:
return "AMR狙击枪(铁爪)";
      break;
case 9814043:
return "M200狙击枪(卓越)";
      break;
case 9814044:
return "M200狙击枪(完好)";
      break;
case 9814045:
return "M200狙击枪(改进)";
      break;
case 9814046:
return "M200狙击枪(精制)";
      break;
case 9814047:
return "M200狙击枪(卓越)";
      break;
case 9814048:
return "M200狙击枪(黑鹰)";
      break;
case 9814049:
return "M200狙击枪(铁爪)";
      break;
case 9814050:
return "SVD狙击枪(改进)";
      break;
case 9814051:
return "SVD狙击枪(精制)";
      break;
case 9814052:
return "SVD狙击枪(卓越)";
      break;
case 9814053:
return "SVD狙击枪(卓越)";
      break;
case 9815001:
return "SKS射手步枪(卓越)";
      break;
case 9815002:
return "SKS射手步枪(完好)";
      break;
case 9815003:
return "SKS射手步枪(改进)";
      break;
case 9815004:
return "SKS射手步枪(精制)";
      break;
case 9815005:
return "SKS射手步枪(卓越)";
      break;
case 9815006:
return "SKS射手步枪(黑鹰)";
      break;
case 9815007:
return "SKS射手步枪(铁爪)";
      break;
case 9815008:
return "VSS射手步枪(破损)";
      break;
case 9815009:
return "VSS射手步枪(修复)";
      break;
case 9815010:
return "VSS射手步枪(完好)";
      break;
case 9815015:
return "Mini14射手步枪(破损)";
      break;
case 9815016:
return "Mini14射手步枪(修复)";
      break;
case 9815017:
return "Mini14射手步枪(完好)";
      break;
case 9815018:
return "Mini14射手步枪(改进)";
      break;
case 9815022:
return "Mk14射手步枪(卓越)";
      break;
case 9815023:
return "Mk14射手步枪(完好)";
      break;
case 9815024:
return "Mk14射手步枪(改进)";
      break;
case 9815025:
return "Mk14射手步枪(精制)";
      break;
case 9815026:
return "Mk14射手步枪(卓越)";
      break;
case 9815027:
return "Mk14射手步枪(黑鹰)";
      break;
case 9815028:
return "Mk14射手步枪(铁爪)";
      break;
case 9815029:
return "SLR射手步枪(卓越)";
      break;
case 9815030:
return "SLR射手步枪(完好)";
      break;
case 9815031:
return "SLR射手步枪(改进)";
      break;
case 9815032:
return "SLR射手步枪(精制)";
      break;
case 9815033:
return "SLR射手步枪(卓越)";
      break;
case 9815034:
return "SLR射手步枪(黑鹰)";
      break;
case 9815035:
return "SLR射手步枪(铁爪)";
      break;
case 9815036:
return "QBU射手步枪(破损)";
      break;
case 9815037:
return "QBU射手步枪(修复)";
      break;
case 9815038:
return "QBU射手步枪(完好)";
      break;
case 9815039:
return "QBU射手步枪(改进)";
      break;
case 9815043:
return "M417射手步枪(卓越)";
      break;
case 9815044:
return "M417射手步枪(完好)";
      break;
case 9815045:
return "M417射手步枪(改进)";
      break;
case 9815046:
return "M417射手步枪(精制)";
      break;
case 9815047:
return "M417射手步枪(卓越)";
      break;
case 9815048:
return "M417射手步枪(黑鹰)";
      break;
case 9815049:
return "M417射手步枪(铁爪)";
      break;
case 9815050:
return "MK20-H射手步枪(卓越)";
      break;
case 9815051:
return "MK20-H射手步枪(完好)";
      break;
case 9815052:
return "MK20-H射手步枪(改进)";
      break;
case 9815053:
return "MK20-H射手步枪(精制)";
      break;
case 9815054:
return "MK20-H射手步枪(卓越)";
      break;
case 9815055:
return "MK20-H射手步枪(黑鹰)";
      break;
case 9815056:
return "MK20-H射手步枪(铁爪)";
      break;
case 9815064:
return "MK12射手步枪(卓越)";
      break;
case 9815065:
return "MK12射手步枪(完好)";
      break;
case 9815066:
return "MK12射手步枪(改进)";
      break;
case 9815067:
return "MK12射手步枪(精制)";
      break;
case 9815068:
return "MK12射手步枪(卓越)";
      break;
case 9815069:
return "MK12射手步枪(黑鹰)";
      break;
case 9815070:
return "MK12射手步枪(铁爪)";
      break;
case 9815071:
return "M134_装甲重机枪";
      break;
    default:
      return "未收录";
      break;
  }
  return nullptr;
} 

std::string tou(int 头)
{
std::string StateName = "X";
if (头 == 0) {
 StateName = "无"; 
}
if (头 == 502001||头 == 502004||头 == 502101) {
 StateName = "一"; 
}
if (头 == 502002||头 == 502005||头 == 502102) {
 StateName = "二"; 
}
if (头 == 502003||头 == 502006||头 == 502103) {
 StateName = "三"; 
}
if (头 == 502104) {
 StateName = "四"; 
}
if (头 == 502107) {
 StateName = "四·"; 
}
if (头 == 502110) {
 StateName = "四·"; 
}
if (头 == 502105) {
 StateName = "五"; 
}
if (头 == 502108) {
 StateName = "五·"; 
}
if (头 == 502111) {
 StateName = "五·"; 
}
if (头 == 502106) {
 StateName = "六"; 
}
if (头 == 502109) {
 StateName = "六·"; 
}
if (头 == 502112) {
 StateName = "六·"; 
}
if (头 == 9804001) {
 StateName = "一"; 
}
if (头 == 9804002) {
 StateName = "二"; 
}
if (头 == 9804003) {
 StateName = "三"; 
}
if (头 == 9804004) {
 StateName = "四"; 
}
if (头 == 9804005) {
 StateName = "四"; 
}
if (头 == 9804006) {
 StateName = "四"; 
}
if (头 == 9804007) {
 StateName = "五"; 
}
if (头 == 9804008) {
 StateName = "五"; 
}
if (头 == 9804009) {
 StateName = "五"; 
}
if (头 == 9804010) {
 StateName = "六"; 
}
if (头 == 9804011) {
 StateName = "六"; 
}
if (头 == 9804012) {
 StateName = "六"; 
}
if (头 == 9804013) {
 StateName = "七"; 
}
if (头 == 9804014) {
 StateName = "七"; 
}
if (头 == 9804015) {
 StateName = "七"; 
}
if (头 == 9804016) {
 StateName = "夜"; 
}
if (头 == 9804017) {
 StateName = "七"; 
}
if (头 == 9804018) {
 StateName = "七"; 
}
if (头 == 9804019) {
 StateName = "七"; 
}
return StateName;
}

std::string jia(int 甲) {
std::string StateName = "X";
if (甲 == 0) {
 StateName = "无"; 
}
if (甲 == 503001||甲 == 503004||甲 == 503101) {
 StateName = "一"; 
}
if (甲 == 503002||甲 == 503005||甲 == 503102) {
 StateName = "二"; 
}
if (甲 == 503003||甲 == 503006||甲 == 503103) {
 StateName = "三"; 
}
if (甲== 503104) {
 StateName = "四"; 
}
if (甲 == 503107) {
 StateName = "四·"; 
}
if (甲 == 503110) {
 StateName = "四·"; 
}
if (甲== 503105) {
 StateName = "五"; 
}
if (甲 == 503108) {
 StateName = "五·"; 
}
if (甲 == 503111) {
 StateName = "五·"; 
}
if (甲== 503106) {
 StateName = "六"; 
}
if (甲 == 503109) {
 StateName = "六·"; 
}
if (甲 == 503112) {
 StateName = "六·"; 
}
if (甲 == 9804020) {
 StateName = "腿"; 
}
if (甲 == 9805001) {
 StateName = "一"; 
}
if (甲 == 9805002) {
 StateName = "二"; 
}
if (甲 == 9805003) {
 StateName = "三"; 
}
if (甲 == 9805004) {
 StateName = "四"; 
}
if (甲 == 9805005) {
 StateName = "四"; 
}
if (甲 == 9805006) {
 StateName = "四"; 
}
if (甲 == 9805007) {
 StateName = "五"; 
}
if (甲 == 9805008) {
 StateName = "五"; 
}
if (甲 == 9805009) {
 StateName = "五"; 
}
if (甲 == 9805010) {
 StateName = "六"; 
}
if (甲 == 9805011) {
 StateName = "六"; 
}
if (甲 == 9805012) {
 StateName = "六"; 
}
if (甲 == 9805013) {
 StateName = "七"; 
}
if (甲 == 9805014) {
 StateName = "七"; 
}
if (甲 == 9805015) {
 StateName = "七"; 
}
if (甲 == 9805016) {
 StateName = "七"; 
}
if (甲 == 9805017) {
 StateName = "七"; 
}
if (甲 == 9805018) {
 StateName = "七"; 
}
if (甲 == 9805020) {
 StateName = "机"; 
}
if (甲 == 9805021) {
 StateName = "四"; 
}
if (甲 == 9805022) {
 StateName = "四"; 
}
if (甲 == 9805023) {
 StateName = "四"; 
}
if (甲 == 9805024) {
 StateName = "五"; 
}
if (甲 == 9805025) {
 StateName = "五"; 
}
if (甲 == 9805026) {
 StateName = "五"; 
}
if (甲 == 9805027) {
 StateName = "六"; 
}
if (甲 == 9805028) {
 StateName = "六"; 
}
if (甲 == 9805029) {
 StateName = "六"; 
}
if (甲 == 9805030) {
 StateName = "七"; 
}
if (甲 == 9805031) {
 StateName = "七"; 
}
if (甲 == 9805032) {
 StateName = "七"; 
}
if (甲 == 9805033) {
 StateName = "七"; 
}
if (甲 == 9805034) {
 StateName = "七"; 
}
if (甲 == 9805035) {
 StateName = "七"; 
}
if (甲 == 9805098) {
 StateName = "七"; 
}
if (甲 == 9805099) {
 StateName = "七"; 
}
return StateName;
}
 std::string bao(int 包) {
 std::string StateName = "未知";
 if (包 == 0) {
 StateName = "无"; 
 }
 if (包 == 501001||包 == 501004||包 == 501101) {
  StateName = "一"; 
 }
 if (包 == 501002||包 == 501005||包 == 501102) {
  StateName = "二"; 
 }
 if (包 == 501003||包 == 501006||包 == 501103) {
  StateName = "三"; 
 }
 if (包 == 501104||包 == 501107||包 == 501110) {
  StateName = "四"; 
 }
 if (包 == 501105||包 == 501108||包 == 501111) {
  StateName = "五"; 
 }
 if (包 == 501106||包 == 501109||包 == 501112) {
  StateName = "六"; 
 }
 if (包 == 9806001) {
  StateName = "1级背包"; 
 }
 if (包 == 9806002) {
  StateName = "2级背包"; 
 }
 if (包 == 9806003) {
  StateName = "3级背包"; 
 }
 if (包 == 9806004) {
  StateName = "4级背包"; 
 }
 if (包 == 9806005) {
  StateName = "4级背包"; 
 }
 if (包 == 9806006) {
  StateName = "4级背包"; 
 }
 if (包 == 9806007) {
  StateName = "5级背包"; 
 }
 if (包 == 9806008) {
  StateName = "5级背包"; 
 }
 if (包 == 9806009) {
  StateName = "5级背包"; 
 }
 if (包 == 9806010) {
  StateName = "6级背包"; 
 }
 if (包 == 9806011) {
  StateName = "6级背包"; 
 }
 if (包 == 9806012) {
  StateName = "6级背包"; 
 }
 if (包 == 9806013) {
  StateName = "7级背包"; 
 }
 if (包 == 9806014) {
  StateName = "7级背包"; 
 }
 if (包 == 9806015) {
  StateName = "7级背包"; 
 }
 if (包 == 9806016) {
  StateName = "7级背包"; 
 }
 if (包 == 9806017) {
  StateName = "7级背包"; 
 }
 if (包 == 9806018) {
  StateName = "7级背包"; 
 }
 return StateName;
 }

// 只有地铁物资的，没经典全物资，有愿意分享的小伙伴可以发一下
inline const char* GetItems(int Id) {
switch (Id) {
case 9801001:  
return "卧底证";
break;
case 9801002:
return "能源电池";
break;
case 9801003:
return "加密房间房卡";
break;
case 9801004:
return "勘察情报";
break;
case 9802001:
return "金库密码卡-白";
break;
case 9802002:
return "金库密码卡-黄";
break;
case 9802003:
return "金库密码卡-红";
break;
case 9802004:
return "金库密码卡-绿";
break;
case 9802005:
return "金库密码卡-黑";
break;
case 9802006:
return "功勋奖章（铜）";
break;
case 9802007:
return "功勋奖章（银）";
break;
case 9802008:
return "功勋奖章（金）";
break;
case 9802009:
return "撤离信号电话机";
break;
case 9803001:
return "1级变卖物测试";
break;
case 9803002:
return "2级变卖物测试";
break;
case 9803003:
return "3级变卖物测试";
break;
case 9803004:
return "4级变卖物测试";
break;
case 9803005:
return "5级变卖物测试";
break;
case 9803006:
return "6级变卖物测试";
break;
case 9803007:
return "7级变卖物测试";
break;
case 9803008:
return "指南针";
break;
case 9803009:
return "明信片";
break;
case 9803010:
return "旧式录像带";
break;
case 9803011:
return "扑克牌";
break;
case 9803012:
return "军用水壶";
break;
case 9803013:
return "罐头";
break;
case 9803014:
return "杂志";
break;
case 9803015:
return "便携手礼";
break;
case 9803016:
return "旅行手册";
break;
case 9803017:
return "钱";
break;
case 9803018:
return "零件包";
break;
case 9803019:
return "机油";
break;
case 9803020:
return "怀表";
break;
case 9803021:
return "怡神精油";
break;
case 9803022:
return "爱心项链";
break;
case 9803023:
return "燃气瓶";
break;
case 9803024:
return "润滑油";
break;
case 9803025:
return "汽车钥匙";
break;
case 9803026:
return "柴油";
break;
case 9803027:
return "军用手表";
break;
case 9803028:
return "高级钱";
break;
case 9803029:
return "科技部件";
break;
case 9803030:
return "狗牌";
break;
case 9803031:
return "信号发生器";
break;
case 9803032:
return "净水器";
break;
case 9803033:
return "CPU处理器";
break;
case 9803034:
return "探测器";
break;
case 9803035:
return "平板电脑";
break;
case 9803036:
return "军用电池";
break;
case 9803037:
return "军用电路板";
break;
case 9803038:
return "精密仪器蓝图";
break;
case 9803039:
return "绝密情报";
break;
case 9803040:
return "设计图纸";
break;
case 9803041:
return "显卡";
break;
case 9803042:
return "镜头";
break;
case 9803043:
return "珍稀古钱币";
break;
case 9803044:
return "一根金条";
break;
case 9803045:
return "光子鸡奖杯";
break;
case 9803046:
return "野兽碎骨";
break;
case 9803047:
return "野兽头骨";
break;
case 9803048:
return "异变的肩骨";
break;
case 9803049:
return "装甲碎片";
break;
case 9803050:
return "装甲能源部件";
break;
case 9803051:
return "装甲爆发部件";
break;
case 9803052:
return "紫矿碎片";
break;
case 9803053:
return "紫矿晶块";
break;
case 9803054:
return "稀有宝石";
break;
case 9803055:
return "黄金烤鸡";
break;
case 9803056:
return "收发信器";
break;
case 9803057:
return "钛合金";
break;
case 9803058:
return "制动引擎";
break;
case 9803059:
return "胶卷";
break;
case 9803060:
return "拉刀";
break;
case 9803061:
return "打火机";
break;
case 9803062:
return "黑胶唱片";
break;
case 9803063:
return "窃听装置";
break;
case 9803064:
return "摄像头";
break;
case 9803065:
return "雷管";
break;
case 9803066:
return "黑鹰勋章";
break;
case 9803067:
return "金狼雕像";
break;
case 9803068:
return "密信";
break;
case 9803069:
return "紫色试管药剂";
break;
case 9803070:
return "数据芯片";
break;
case 9804001:
return "1级头盔";
break;
case 9804002:
return "2级头盔";
break;
case 9804003:
return "3级头盔";
break;
case 9804004:
return "4级头盔";
break;
case 9804005:
return "4级头盔(铁爪)";
break;
case 9804006:
return "4级头盔(黑鹰)";
break;
case 9804007:
return "5级头盔";
break;
case 9804008:
return "5级头盔(铁爪)";
break;
case 9804009:
return "5级头盔(黑鹰)";
break;
case 9804010:
return "6级头盔";
break;
case 9804011:
return "6级头盔(铁爪)";
break;
case 9804012:
return "6级头盔(黑鹰)";
break;
case 9804013:
return "7级头盔";
break;
case 9804014:
return "7级头盔(铁爪)";
break;
case 9804015:
return "7级头盔(黑鹰)";
break;
case 9804016:
return "头戴夜视仪";
break;
case 9804017:
return "7级头盔";
break;
case 9804018:
return "7级头盔(铁爪)";
break;
case 9804019:
return "7级头盔(黑鹰)";
break;
case 9804020:
return "机甲腿甲（冲刺技能）";
break;
case 9805001:
return "1级防弹衣";
break;
case 9805002:
return "2级防弹衣";
break;
case 9805003:
return "3级防弹衣";
break;
case 9805004:
return "4级防弹衣";
break;
case 9805005:
return "4级防弹衣(铁爪)";
break;
case 9805006:
return "4级防弹衣(黑鹰)";
break;
case 9805007:
return "5级防弹衣";
break;
case 9805008:
return "5级防弹衣(铁爪)";
break;
case 9805009:
return "5级防弹衣(黑鹰)";
break;
case 9805010:
return "6级防弹衣";
break;
case 9805011:
return "6级防弹衣(铁爪)";
break;
case 9805012:
return "6级防弹衣(黑鹰)";
break;
case 9805013:
return "7级防弹衣";
break;
case 9805014:
return "7级防弹衣(铁爪)";
break;
case 9805015:
return "7级防弹衣(黑鹰)";
break;
case 9805016:
return "7级防弹衣";
break;
case 9805017:
return "7级防弹衣(铁爪)";
break;
case 9805018:
return "7级防弹衣(黑鹰)";
break;
case 9805020:
return "机甲防具";
break;
case 9805021:
return "子物品-4级防弹衣";
break;
case 9805022:
return "子物品-4级防弹衣(铁爪)";
break;
case 9805023:
return "子物品-4级防弹衣(黑鹰)";
break;
case 9805024:
return "子物品-5级防弹衣";
break;
case 9805025:
return "子物品-5级防弹衣(铁爪)";
break;
case 9805026:
return "子物品-5级防弹衣(黑鹰)";
break;
case 9805027:
return "子物品-6级防弹衣";
break;
case 9805028:
return "子物品-6级防弹衣(铁爪)";
break;
case 9805029:
return "6级防弹衣(黑鹰)";
break;

case 9805030:
return "子物品-7级防弹衣";
break;
case 9805031:
return "子物品-7级防弹衣(铁爪)";
break;
case 9805032:
return "子物品-7级防弹衣(黑鹰)";
break;
case 9805033:
return "子物品-7级防弹衣";
break;
case 9805034:
return "子物品-7级防弹衣(铁爪)";
break;
case 9805035:
return "子物品-7级防弹衣(黑鹰)";
break;
case 9805098:
return "子物品-7级防弹衣·特劳斯";
break;
case 9805099:
return "7级防弹衣·特劳斯";
break;
case 9806001:
return "1级背包";
break;
case 9806002:
return "2级背包";
break;
case 9806003:
return "3级背包";
break;
case 9806004:
return "4级背包";
break;
case 9806005:
return "4级背包(铁爪)";
break;
case 9806006:
return "4级背包(黑鹰)";
break;
case 9806007:
return "5级背包";
break;
case 9806008:
return "5级背包(铁爪)";
break;
case 9806009:
return "5级背包(黑鹰)";
break;
case 9806010:
return "6级背包";
break;
case 9806011:
return "6级背包(铁爪)";
break;
case 9806012:
return "6级背包(黑鹰)";
break;
case 9806013:
return "7级背包";
break;
case 9806014:
return "7级背包(铁爪)";
break;
case 9806015:
return "7级背包(黑鹰)";
break;
case 9806016:
return "7级背包";
break;
case 9806017:
return "7级背包(铁爪)";
break;
case 9806018:
return "7级背包(黑鹰)";
break;
case 9807001:
return "大砍刀";
break;
case 9807002:
return "撬棍";
break;
case 9807003:
return "镰刀";
break;
case 9807004:
return "平底锅";
break;
case 9807005:
return "火焰刀·维列";
break;
case 9808001:
return "P92手枪(破损)";
break;
case 9808002:
return "P92手枪(修复)";
break;
case 9808003:
return "P92手枪(完好)";
break;
case 9808008:
return "P1911手枪(破损)";
break;
case 9808009:
return "P1911手枪(修复)";
break;
case 9808010:
return "P1911手枪(完好)";
break;
case 9808015:
return "R1895手枪(破损)";
break;
case 9808016:
return "R1895手枪(修复)";
break;
case 9808017:
return "R1895手枪(完好)";
break;
case 9808022:
return "P18C手枪(破损)";
break;
case 9808023:
return "P18C手枪(修复)";
break;
case 9808024:
return "P18C手枪(完好)";
break;
case 9808029:
return "R45手枪(破损)";
break;
case 9808030:
return "R45手枪(修复)";
break;
case 9808031:
return "R45手枪(完好)";
break;
case 9808036:
return "短管霰弹枪(破损)";
break;
case 9808037:
return "短管霰弹枪(修复)";
break;
case 9808038:
return "短管霰弹枪(完好)";
break;
case 9808043:
return "蝎式手枪(修复)";
break;
case 9808044:
return "蝎式手枪(完好)";
break;
case 9808045:
return "蝎式手枪(改进)";
break;
case 9808046:
return "蝎式手枪(破损)";
break;
case 9808050:
return "沙漠之鹰手枪(修复)";
break;
case 9808051:
return "沙漠之鹰手枪(完好)";
break;
case 9808052:
return "沙漠之鹰手枪(改进)";
break;
case 9808053:
return "沙漠之鹰手枪(破损)";
break;
case 9808057:
return "TMP-9手枪(修复)";
break;
case 9808058:
return "TMP-9手枪(完好)";
break;
case 9808059:
return "TMP-9手枪(改进)";
break;
case 9808060:
return "空投信号枪";
break;
case 9808061:
return "TMP-9手枪(破损)";
break;
case 9809001:
return "十字弩(破损)";
break;
case 9809002:
return "十字弩(修复)";
break;
case 9809003:
return "十字弩(完好)";
break;
case 9809009:
return "爆炸猎弓(骑警Boss)";
break;
case 9809010:
return "爆炸猎弓·杰西";
break;
case 9810001:
return "S686霰弹枪(破损)";
break;
case 9810002:
return "S686霰弹枪(修复)";
break;
case 9810003:
return "S686霰弹枪(完好)";
break;
case 9810008:
return "S1897霰弹枪(破损)";
break;
case 9810009:
return "S1897霰弹枪(修复)";
break;
case 9810010:
return "S1897霰弹枪(完好)";
break;
case 9810015:
return "S12K霰弹枪(精制)";
break;
case 9810016:
return "S12K霰弹枪(修复)";
break;
case 9810017:
return "S12K霰弹枪(完好)";
break;
case 9810018:
return "S12K霰弹枪(改进)";
break;
case 9810022:
return "DBS霰弹枪(修复)";
break;
case 9810023:
return "DBS霰弹枪(完好)";
break;
case 9810024:
return "DBS霰弹枪(改进)";
break;
case 9810025:
return "DBS霰弹枪(精制)";
break;
case 9810029:
return "SPAS-12霰弹枪(修复)";
break;
case 9810030:
return "SPAS-12霰弹枪(完好)";
break;
case 9810031:
return "SPAS-12霰弹枪(改进)";
break;
case 9810032:
return "SPAS-12霰弹枪(精制)";
break;
case 9810036:
return "AA12-G霰弹枪(修复)";
break;
case 9810037:
return "AA12-G霰弹枪(完好)";
break;
case 9810038:
return "AA12-G霰弹枪(改进)";
break;
case 9810041:
return "AA12-G霰弹枪(精制)";
break;
case 9811001:
return "UZI冲锋枪(破损)";
break;
case 9811002:
return "UZI冲锋枪(修复)";
break;
case 9811003:
return "UZI冲锋枪(完好)";
break;
case 9811004:
return "UZI冲锋枪(改进)";
break;
case 9811008:
return "UMP45冲锋枪(破损)";
break;
case 9811009:
return "UMP45冲锋枪(修复)";
break;
case 9811010:
return "UMP45冲锋枪(完好)";
break;
case 9811011:
return "UMP45冲锋枪(改进)";
break;
case 9811015:
return "Vector冲锋枪(卓越)";
break;
case 9811016:
return "Vector冲锋枪(完好)";
break;
case 9811017:
return "Vector冲锋枪(改进)";
break;
case 9811018:
return "Vector冲锋枪(精制)";
break;
case 9811019:
return "Vector冲锋枪(卓越)";
break;
case 9811020:
return "Vector冲锋枪(黑鹰)";
break;
case 9811021:
return "Vector冲锋枪(铁爪)";
break;
case 9811022:
return "汤姆逊冲锋枪(破损)";
break;
case 9811023:
return "汤姆逊冲锋枪(修复)";
break;
case 9811024:
return "汤姆逊冲锋枪(完好)";
break;
case 9811025:
return "汤姆逊冲锋枪(改进)";
break;
case 9811029:
return "野牛冲锋枪(破损)";
break;
case 9811030:
return "野牛冲锋枪(修复)";
break;
case 9811031:
return "野牛冲锋枪(完好)";
break;
case 9811036:
return "MP5K冲锋枪(卓越)";
break;
case 9811037:
return "MP5K冲锋枪(完好)";
break;
case 9811038:
return "MP5K冲锋枪(改进)";
break;
case 9811039:
return "MP5K冲锋枪(精制)";
break;
case 9811040:
return "MP5K冲锋枪(卓越)";
break;
case 9811041:
return "MP5K冲锋枪(黑鹰)";
break;
case 9811042:
return "MP5K冲锋枪(铁爪)";
break;
case 9811043:
return "AKS-74U冲锋枪(卓越)";
break;
case 9811044:
return "AKS-74U冲锋枪(完好)";
break;
case 9811045:
return "AKS-74U冲锋枪(改进)";
break;
case 9811046:
return "AKS-74U冲锋枪(精制)";
break;
case 9811047:
return "AKS-74U冲锋枪(卓越)";
break;
case 9811048:
return "AKS-74U冲锋枪(铁爪)";
break;
case 9811049:
return "AKS-74U冲锋枪(黑鹰)";
break;
case 9811050:
return "P90冲锋枪(卓越)";
break;
case 9811051:
return "P90冲锋枪(完好)";
break;
case 9811052:
return "P90冲锋枪(改进)";
break;
case 9811053:
return "P90冲锋枪(精制)";
break;
case 9811054:
return "P90冲锋枪(卓越)";
break;
case 9811055:
return "P90冲锋枪(黑鹰)";
break;
case 9811056:
return "P90冲锋枪(铁爪)";
break;
case 9812002:
return "AKM突击步枪(卓越)";
break;
case 9812003:
return "AKM突击步枪(完好)";
break;
case 9812004:
return "AKM突击步枪(改进)";
break;
case 9812005:
return "AKM突击步枪(精制)";
break;
case 9812006:
return "AKM突击步枪(卓越)";
break;
case 9812007:
return "AKM突击步枪(黑鹰)";
break;
case 9812008:
return "AKM突击步枪(铁爪)";
break;
case 9812009:
return "M16A4突击步枪(破损)";
break;
case 9812010:
return "M16A4突击步枪(修复)";
break;
case 9812011:
return "M16A4突击步枪(完好)";
break;
case 9812012:
return "M16A4突击步枪(改进)";
break;
case 9812015:
return "SCAR-L突击步枪(卓越)";
break;
case 9812016:
return "SCAR-L突击步枪(完好)";
break;
case 9812017:
return "SCAR-L突击步枪(改进)";
break;
case 9812018:
return "SCAR-L突击步枪(精制)";
break;
case 9812019:
return "SCAR-L突击步枪(卓越)";
break;
case 9812020:
return "SCAR-L突击步枪(黑鹰)";
break;
case 9812021:
return "SCAR-L突击步枪(铁爪)";
break;
case 9812022:
return "M416突击步枪(铁爪)";
break;
case 9812023:
return "M416突击步枪(卓越)";
break;
case 9812024:
return "M416突击步枪(完好)";
break;
case 9812025:
return "M416突击步枪(改进)";
break;
case 9812026:
return "M416突击步枪(精制)";
break;
case 9812027:
return "M416突击步枪(卓越)";
break;
case 9812028:
return "M416突击步枪(黑鹰)";
break;
case 9812029:
return "GROZA突击步枪(卓越)";
break;
case 9812030:
return "GROZA突击步枪(改进)";
break;
case 9812031:
return "GROZA突击步枪(精制)";
break;
case 9812032:
return "GROZA突击步枪(卓越)";
break;
case 9812033:
return "GROZA突击步枪(黑鹰)";
break;
case 9812034:
return "GROZA突击步枪(铁爪)";
break;
case 9812036:
return "AUG突击步枪(卓越)";
break;
case 9812037:
return "AUG突击步枪(改进)";
break;
case 9812038:
return "AUG突击步枪(精制)";
break;
case 9812039:
return "AUG突击步枪(卓越)";
break;
case 9812040:
return "AUG突击步枪(黑鹰)";
break;
case 9812041:
return "AUG突击步枪(铁爪)";
break;
case 9812043:
return "QBZ突击步枪(卓越)";
break;
case 9812044:
return "QBZ突击步枪(完好)";
break;
case 9812045:
return "QBZ突击步枪(改进)";
break;
case 9812046:
return "QBZ突击步枪(精制)";
break;
case 9812047:
return "QBZ突击步枪(卓越)";
break;
case 9812048:
return "QBZ突击步枪(黑鹰)";
break;
case 9812049:
return "QBZ突击步枪(铁爪)";
break;
case 9812050:
return "M762突击步枪(卓越)";
break;
case 9812051:
return "M762突击步枪(完好)";
break;
case 9812052:
return "M762突击步枪(改进)";
break;
case 9812053:
return "M762突击步枪(精制)";
break;
case 9812054:
return "M762突击步枪(卓越)";
break;
case 9812055:
return "M762突击步枪(黑鹰)";
break;
case 9812056:
return "M762突击步枪(铁爪)";
break;
case 9812057:
return "Mk47突击步枪(破损)";
break;
case 9812058:
return "Mk47突击步枪(修复)";
break;
case 9812059:
return "Mk47突击步枪(完好)";
break;
case 9812060:
return "Mk47突击步枪(改进)";
break;
case 9812064:
return "G36C突击步枪(卓越)";
break;
case 9812065:
return "G36C突击步枪(完好)";
break;
case 9812066:
return "G36C突击步枪(改进)";
break;
case 9812067:
return "G36C突击步枪(精制)";
break;
case 9812068:
return "G36C突击步枪(卓越)";
break;
case 9812069:
return "G36C突击步枪(黑鹰)";
break;
case 9812070:
return "G36C突击步枪(铁爪)";
break;
case 9812071:
return "AC-VAL突击步枪(破损)";
break;
case 9812072:
return "AC-VAL突击步枪(修复)";
break;
case 9812073:
return "AC-VAL突击步枪(完好)";
break;
case 9812074:
return "AC-VAL突击步枪(改进)";
break;
case 9812078:
return "蜜獾突击步枪(卓越)";
break;
case 9812079:
return "蜜獾突击步枪(完好)";
break;
case 9812080:
return "蜜獾突击步枪(改进)";
break;
case 9812081:
return "蜜獾突击步枪(精制)";
break;
case 9812082:
return "蜜獾突击步枪(卓越)";
break;
case 9812083:
return "蜜獾突击步枪(黑鹰)";
break;
case 9812084:
return "蜜獾突击步枪(铁爪)";
break;
case 9812085:
return "Famas突击步枪(卓越)";
break;
case 9812086:
return "Famas突击步枪(完好)";
break;
case 9812087:
return "Famas突击步枪(改进)";
break;
case 9812088:
return "Famas突击步枪(精制)";
break;
case 9812089:
return "Famas突击步枪(卓越)";
break;
case 9812090:
return "Famas突击步枪(黑鹰)";
break;
case 9812091:
return "Famas突击步枪(铁爪)";
break;
case 9812092:
return "M416突击步枪·卡德尔";
break;
case 9813001:
return "M249轻机枪(卓越)";
break;
case 9813002:
return "M249轻机枪(改进)";
break;
case 9813003:
return "M249轻机枪(精制)";
break;
case 9813004:
return "M249轻机枪(卓越)";
break;
case 9813005:
return "M249轻机枪(黑鹰)";
break;
case 9813006:
return "M249轻机枪(铁爪)";
break;
case 9813008:
return "DP-28轻机枪(破损)";
break;
case 9813009:
return "DP-28轻机枪(修复)";
break;
case 9813010:
return "DP-28轻机枪(完好)";
break;
case 9813022:
return "MG3轻机枪(卓越)";
break;
case 9813023:
return "MG3轻机枪(改进)";
break;
case 9813024:
return "MG3轻机枪(精制)";
break;
case 9813025:
return "MG3轻机枪(卓越)";
break;
case 9813026:
return "MG3轻机枪(黑鹰)";
break;
case 9813027:
return "MG3轻机枪(铁爪)";
break;
case 9813029:
return "PKM轻机枪(卓越)";
break;
case 9813030:
return "PKM轻机枪(改进)";
break;
case 9813031:
return "PKM轻机枪(精制)";
break;
case 9813032:
return "PKM轻机枪(卓越)";
break;
case 9813033:
return "PKM轻机枪(黑鹰)";
break;
case 9813034:
return "PKM轻机枪(铁爪)";
break;
case 9814001:
return "Kar98K狙击枪(修复)";
break;
case 9814002:
return "Kar98K狙击枪(完好)";
break;
case 9814003:
return "Kar98K狙击枪(改进)";
break;
case 9814008:
return "M24狙击枪(卓越)";
break;
case 9814009:
return "M24狙击枪(完好)";
break;
case 9814010:
return "M24狙击枪(改进)";
break;
case 9814011:
return "M24狙击枪(精制)";
break;
case 9814012:
return "M24狙击枪(卓越)";
break;
case 9814013:
return "M24狙击枪(黑鹰)";
break;
case 9814014:
return "M24狙击枪(铁爪)";
break;
case 9814015:
return "AWM狙击枪(卓越)";
break;
case 9814016:
return "AWM狙击枪(改进)";
break;
case 9814017:
return "AWM狙击枪(精制)";
break;
case 9814018:
return "AWM狙击枪(卓越)";
break;
case 9814019:
return "AWM狙击枪(黑鹰)";
break;
case 9814020:
return "AWM狙击枪(铁爪)";
break;
case 9814022:
return "莫辛纳甘狙击枪(破损)";
break;
case 9814023:
return "莫辛纳甘狙击枪(修复)";
break;
case 9814024:
return "莫辛纳甘狙击枪(完好)";
break;
case 9814029:
return "Win94狙击枪(破损)";
break;
case 9814030:
return "Win94狙击枪(修复)";
break;
case 9814031:
return "Win94狙击枪(完好)";
break;
case 9814036:
return "AMR狙击枪(卓越)";
break;
case 9814037:
return "AMR狙击枪(改进)";
break;
case 9814038:
return "AMR狙击枪(精制)";
break;
case 9814039:
return "AMR狙击枪(卓越)";
break;
case 9814040:
return "AMR狙击枪(黑鹰)";
break;
case 9814041:
return "AMR狙击枪(铁爪)";
break;
case 9814043:
return "M200狙击枪(卓越)";
break;
case 9814044:
return "M200狙击枪(完好)";
break;
case 9814045:
return "M200狙击枪(改进)";
break;
case 9814046:
return "M200狙击枪(精制)";
break;
case 9814047:
return "M200狙击枪(卓越)";
break;
case 9814048:
return "M200狙击枪(黑鹰)";
break;
case 9814049:
return "M200狙击枪(铁爪)";
break;
case 9815001:
return "SKS射手步枪(卓越)";
break;
case 9815002:
return "SKS射手步枪(完好)";
break;
case 9815003:
return "SKS射手步枪(改进)";
break;
case 9815004:
return "SKS射手步枪(精制)";
break;
case 9815005:
return "SKS射手步枪(卓越)";
break;
case 9815006:
return "SKS射手步枪(黑鹰)";
break;
case 9815007:
return "SKS射手步枪(铁爪)";
break;
case 9815008:
return "VSS射手步枪(破损)";
break;
case 9815009:
return "VSS射手步枪(修复)";
break;
case 9815010:
return "VSS射手步枪(完好)";
break;
case 9815015:
return "Mini14射手步枪(破损)";
break;
case 9815016:
return "Mini14射手步枪(修复)";
break;
case 9815017:
return "Mini14射手步枪(完好)";
break;
case 9815018:
return "Mini14射手步枪(改进)";
break;
case 9815022:
return "Mk14射手步枪(卓越)";
break;
case 9815023:
return "Mk14射手步枪(完好)";
break;
case 9815024:
return "Mk14射手步枪(改进)";
break;
case 9815025:
return "Mk14射手步枪(精制)";
break;
case 9815026:
return "Mk14射手步枪(卓越)";
break;
case 9815027:
return "Mk14射手步枪(黑鹰)";
break;
case 9815028:
return "Mk14射手步枪(铁爪)";
break;
case 9815029:
return "SLR射手步枪(卓越)";
break;
case 9815030:
return "SLR射手步枪(完好)";
break;
case 9815031:
return "SLR射手步枪(改进)";
break;
case 9815032:
return "SLR射手步枪(精制)";
break;
case 9815033:
return "SLR射手步枪(卓越)";
break;
case 9815034:
return "SLR射手步枪(黑鹰)";
break;
case 9815035:
return "SLR射手步枪(铁爪)";
break;
case 9815036:
return "QBU射手步枪(破损)";
break;
case 9815037:
return "QBU射手步枪(修复)";
break;
case 9815038:
return "QBU射手步枪(完好)";
break;
case 9815039:
return "QBU射手步枪(改进)";
break;
case 9815043:
return "M417射手步枪(卓越)";
break;
case 9815044:
return "M417射手步枪(完好)";
break;
case 9815045:
return "M417射手步枪(改进)";
break;
case 9815046:
return "M417射手步枪(精制)";
break;
case 9815047:
return "M417射手步枪(卓越)";
break;
case 9815048:
return "M417射手步枪(黑鹰)";
break;
case 9815049:
return "M417射手步枪(铁爪)";
break;
case 9815050:
return "MK20-H射手步枪(卓越)";
break;
case 9815051:
return "MK20-H射手步枪(完好)";
break;
case 9815052:
return "MK20-H射手步枪(改进)";
break;
case 9815053:
return "MK20-H射手步枪(精制)";
break;
case 9815054:
return "MK20-H射手步枪(卓越)";
break;
case 9815055:
return "MK20-H射手步枪(黑鹰)";
break;
case 9815056:
return "MK20-H射手步枪(铁爪)";
break;
case 9815064:
return "MK12射手步枪(卓越)";
break;
case 9815065:
return "MK12射手步枪(完好)";
break;
case 9815066:
return "MK12射手步枪(改进)";
break;
case 9815067:
return "MK12射手步枪(精制)";
break;
case 9815068:
return "MK12射手步枪(卓越)";
break;
case 9815069:
return "MK12射手步枪(黑鹰)";
break;
case 9815070:
return "MK12射手步枪(铁爪)";
break;
case 9815071:
return "M134_装甲重机枪";
break;
case 9816001:
return "钢制插板(破损)";
break;
case 9816002:
return "钢制插板(修复)";
break;
case 9816003:
return "钢制插板(完好)";
break;
case 9816004:
return "钢制插板(改进)";
break;
case 9816005:
return "钢制插板(精制)";
break;
case 9816006:
return "复合纤维插板(破损)";
break;
case 9816007:
return "复合纤维插板(修复)";
break;
case 9816008:
return "复合纤维插板(完好)";
break;
case 9816009:
return "复合纤维插板(改进)";
break;
case 9816010:
return "复合纤维插板(精制)";
break;
case 9816011:
return "内衬外骨骼(破损)";
break;
case 9816012:
return "内衬外骨骼(修复)";
break;
case 9816013:
return "内衬外骨骼(完好)";
break;
case 9816014:
return "内衬外骨骼(改进)";
break;
case 9816015:
return "内衬外骨骼(精制)";
break;
case 9816016:
return "尼龙绑带(破损)";
break;
case 9816017:
return "尼龙绑带(修复)";
break;
case 9816018:
return "尼龙绑带(完好)";
break;
case 9816019:
return "尼龙绑带(改进)";
break;
case 9816020:
return "尼龙绑带(精制)";
break;
case 9816021:
return "战术小包(破损)";
break;
case 9816022:
return "战术小包(修复)";
break;
case 9816023:
return "战术小包(完好)";
break;
case 9816024:
return "战术小包(改进)";
break;
case 9816025:
return "战术小包(精制)";
break;
case 9816026:
return "信号增强器";
break;
case 9817001:
return "红点瞄准镜";
break;
case 9817002:
return "全息瞄准镜";
break;
case 9817003:
return "2倍 瞄准镜";
break;
case 9817004:
return "4倍 瞄准镜";
break;
case 9817005:
return "8倍 瞄准镜";
break;
case 9817006:
return "3倍 瞄准镜";
break;
case 9817007:
return "6倍 瞄准镜";
break;
case 9817008:
return "侧面瞄准镜";
break;
case 9817010:
return "夜视瞄准镜";
break;
case 9817011:
return "热成像瞄准镜";
break;
case 9818001:
return "霰弹枪收束器(破损)";
break;
case 9818002:
return "霰弹枪收束器(修复)";
break;
case 9818003:
return "霰弹枪收束器(完好)";
break;
case 9818004:
return "霰弹枪收束器(改进)";
break;
case 9818008:
return "枪口补偿器(冲锋枪)(修复)";
break;
case 9818009:
return "枪口补偿器(冲锋枪)(完好)";
break;
case 9818010:
return "枪口补偿器(冲锋枪)(改进)";
break;
case 9818011:
return "枪口补偿器(冲锋枪)(精制)";
break;
case 9818015:
return "枪口补偿器(狙击枪)(修复)";
break;
case 9818016:
return "枪口补偿器(狙击枪)(完好)";
break;
case 9818017:
return "枪口补偿器(狙击枪)(改进)";
break;
case 9818018:
return "枪口补偿器(狙击枪)(精制)";
break;
case 9818022:
return "消焰器(冲锋枪)(破损)";
break;
case 9818023:
return "消焰器(冲锋枪)(修复)";
break;
case 9818024:
return "消焰器(冲锋枪)(完好)";
break;
case 9818025:
return "消焰器(冲锋枪)(改进)";
break;
case 9818029:
return "消焰器(狙击枪)(修复)";
break;
case 9818030:
return "消焰器(狙击枪)(完好)";
break;
case 9818031:
return "消焰器(狙击枪)(改进)";
break;
case 9818032:
return "消焰器(狙击枪)(精制)";
break;
case 9818036:
return "消音器(冲锋枪,手枪)(修复)";
break;
case 9818037:
return "消音器(冲锋枪,手枪)(完好)";
break;
case 9818038:
return "消音器(冲锋枪,手枪)(改进)";
break;
case 9818039:
return "消音器(冲锋枪,手枪)(精制)";
break;
case 9818043:
return "消音器(狙击枪)(修复)";
break;
case 9818044:
return "消音器(狙击枪)(完好)";
break;
case 9818045:
return "消音器(狙击枪)(改进)";
break;
case 9818046:
return "消音器(狙击枪)(精制)";
break;
case 9818058:
return "枪口补偿器(步枪)(修复)";
break;
case 9818059:
return "枪口补偿器(步枪)(完好)";
break;
case 9818060:
return "枪口补偿器(步枪)(改进)";
break;
case 9818061:
return "枪口补偿器(步枪)(精制)";
break;
case 9818064:
return "消焰器(步枪)(破损)";
break;
case 9818065:
return "消焰器(步枪)(修复)";
break;
case 9818066:
return "消焰器(步枪)(完好)";
break;
case 9818067:
return "消焰器(步枪)(改进)";
break;
case 9818072:
return "消音器(步枪)(修复)";
break;
case 9818073:
return "消音器(步枪)(完好)";
break;
case 9818074:
return "消音器(步枪)(改进)";
break;
case 9818075:
return "消音器(步枪)(精制)";
break;
case 9818078:
return "鸭嘴枪口(霰弹枪)(破损)";
break;
case 9818079:
return "鸭嘴枪口(霰弹枪)(修复)";
break;
case 9818080:
return "鸭嘴枪口(霰弹枪)(完好)";
break;
case 9818081:
return "鸭嘴枪口(霰弹枪)(改进)";
break;
case 9818082:
return "鸭嘴枪口(霰弹枪)(精制)";
break;
case 9818085:
return "延长枪管(冲锋枪)(破损)";
break;
case 9818086:
return "延长枪管(冲锋枪)(修复)";
break;
case 9818087:
return "延长枪管(冲锋枪)(完好)";
break;
case 9818088:
return "延长枪管(冲锋枪)(改进)";
break;
case 9818092:
return "延长枪管(步枪,狙击枪)(破损)";
break;
case 9818093:
return "延长枪管(步枪,狙击枪)(修复)";
break;
case 9818094:
return "延长枪管(步枪,狙击枪)(完好)";
break;
case 9818095:
return "延长枪管(步枪,狙击枪)(改进)";
break;
case 9819001:
return "扩容弹匣(冲锋枪,手枪)(破损)";
break;
case 9819002:
return "扩容弹匣(冲锋枪,手枪)(修复)";
break;
case 9819003:
return "扩容弹匣(冲锋枪,手枪)(完好)";
break;
case 9819004:
return "扩容弹匣(冲锋枪,手枪)(改进)";
break;
case 9819005:
return "扩容弹匣(冲锋枪,手枪)(精制)";
break;
case 9819008:
return "快速弹匣(冲锋枪,手枪)(破损)";
break;
case 9819009:
return "快速弹匣(冲锋枪,手枪)(修复)";
break;
case 9819010:
return "快速弹匣(冲锋枪,手枪)(完好)";
break;
case 9819011:
return "快速弹匣(冲锋枪,手枪)(改进)";
break;
case 9819012:
return "快速弹匣(冲锋枪,手枪)(精制)";
break;
case 9819036:
return "快速扩容弹匣(冲锋枪,手枪)(修复)";
break;
case 9819037:
return "快速扩容弹匣(冲锋枪,手枪)(完好)";
break;
case 9819038:
return "快速扩容弹匣(冲锋枪,手枪)(改进)";
break;
case 9819039:
return "快速扩容弹匣(冲锋枪,手枪)(精制)";
break;
case 9819043:
return "扩容弹匣(狙击枪)(破损)";
break;
case 9819044:
return "扩容弹匣(狙击枪)(修复)";
break;
case 9819045:
return "扩容弹匣(狙击枪)(完好)";
break;
case 9819046:
return "扩容弹匣(狙击枪)(改进)";
break;
case 9819047:
return "扩容弹匣(狙击枪)(精制)";
break;
case 9819050:
return "快速弹匣(狙击枪)(破损)";
break;
case 9819051:
return "快速弹匣(狙击枪)(修复)";
break;
case 9819052:
return "快速弹匣(狙击枪)(完好)";
break;
case 9819053:
return "快速弹匣(狙击枪)(改进)";
break;
case 9819054:
return "快速弹匣(狙击枪)(精制)";
break;
case 9819057:
return "快速扩容弹匣(狙击枪)(修复)";
break;
case 9819058:
return "快速扩容弹匣(狙击枪)(完好)";
break;
case 9819059:
return "快速扩容弹匣(狙击枪)(改进)";
break;
case 9819060:
return "快速扩容弹匣(狙击枪)(精制)";
break;
case 9819071:
return "扩容弹匣(步枪,机枪)(破损)";
break;
case 9819072:
return "扩容弹匣(步枪,机枪)(修复)";
break;
case 9819073:
return "扩容弹匣(步枪,机枪)(完好)";
break;
case 9819074:
return "扩容弹匣(步枪,机枪)(改进)";
break;
case 9819075:
return "扩容弹匣(步枪,机枪)(精制)";
break;
case 9819078:
return "快速弹匣(步枪,机枪)(破损)";
break;
case 9819079:
return "快速弹匣(步枪,机枪)(修复)";
break;
case 9819080:
return "快速弹匣(步枪,机枪)(完好)";
break;
case 9819081:
return "快速弹匣(步枪,机枪)(改进)";
break;
case 9819082:
return "快速弹匣(步枪,机枪)(精制)";
break;
case 9819086:
return "快速扩容弹匣(步枪,机枪)(修复)";
break;
case 9819087:
return "快速扩容弹匣(步枪,机枪)(完好)";
break;
case 9819088:
return "快速扩容弹匣(步枪,机枪)(改进)";
break;
case 9819089:
return "快速扩容弹匣(步枪,机枪)(精制)";
break;
case 9819092:
return "子弹袋(狙击枪,霰弹枪)(修复)";
break;
case 9819093:
return "子弹袋(狙击枪,霰弹枪)(完好)";
break;
case 9819094:
return "子弹袋(狙击枪,霰弹枪)(改进)";
break;
case 9819095:
return "子弹袋(狙击枪,霰弹枪)(精制)";
break;
case 9819106:
return "霰弹快速装填器";
break;
case 9819156:
return "M134默认弹匣";
break;
case 9820002:
return "战术枪托(修复)";
break;
case 9820003:
return "战术枪托(完好)";
break;
case 9820004:
return "战术枪托(改进)";
break;
case 9820005:
return "战术枪托(精制)";
break;
case 9820008:
return "托腮板(狙击枪)(修复)";
break;
case 9820009:
return "托腮板(狙击枪)(完好)";
break;
case 9820010:
return "托腮板(狙击枪)(改进)";
break;
case 9820011:
return "托腮板(狙击枪)(精制)";
break;
case 9820015:
return "箭袋(十字弩)(破损)";
break;
case 9820016:
return "箭袋(十字弩)(修复)";
break;
case 9820017:
return "箭袋(十字弩)(完好)";
break;
case 9820018:
return "箭袋(十字弩)(改进)";
break;
case 9820019:
return "箭袋(十字弩)(精制)";
break;
case 9820022:
return "撞火枪托";
break;
case 9820023:
return "枪托(Micro UZI)(修复)";
break;
case 9820024:
return "枪托(Micro UZI)(完好)";
break;
case 9820025:
return "枪托(Micro UZI)(改进)";
break;
case 9820026:
return "枪托(Micro UZI)(精制)";
break;
case 9821001:
return "直角前握把(破损)";
break;
case 9821002:
return "直角前握把(修复)";
break;
case 9821003:
return "直角前握把(完好)";
break;
case 9821004:
return "直角前握把(改进)";
break;
case 9821005:
return "直角前握把(精制)";
break;
case 9821008:
return "垂直握把(破损)";
break;
case 9821009:
return "垂直握把(修复)";
break;
case 9821010:
return "垂直握把(完好)";
break;
case 9821011:
return "垂直握把(改进)";
break;
case 9821012:
return "垂直握把(精制)";
break;
case 9821015:
return "轻型握把(破损)";
break;
case 9821016:
return "轻型握把(修复)";
break;
case 9821017:
return "轻型握把(完好)";
break;
case 9821018:
return "轻型握把(改进)";
break;
case 9821019:
return "轻型握把(精制)";
break;
case 9821022:
return "半截式握把(破损)";
break;
case 9821023:
return "半截式握把(修复)";
break;
case 9821024:
return "半截式握把(完好)";
break;
case 9821025:
return "半截式握把(改进)";
break;
case 9821026:
return "半截式握把(精制)";
break;
case 9821029:
return "拇指握把(破损)";
break;
case 9821030:
return "拇指握把(修复)";
break;
case 9821031:
return "拇指握把(完好)";
break;
case 9821032:
return "拇指握把(改进)";
break;
case 9821033:
return "拇指握把(精制)";
break;
case 9821036:
return "激光瞄准器(破损)";
break;
case 9821037:
return "激光瞄准器(修复)";
break;
case 9821038:
return "激光瞄准器(完好)";
break;
case 9821039:
return "激光瞄准器(改进)";
break;
case 9821040:
return "激光瞄准器(精制)";
break;
case 9821044:
return "下挂榴弹发射器";
break;
case 9821045:
return "下挂喷火器";
break;
case 9823001:
return "9毫米子弹(锈蚀)";
break;
case 9823002:
return "9毫米子弹(普通)";
break;
case 9823003:
return "9毫米子弹(抛光)";
break;
case 9823004:
return "9毫米子弹(高爆)";
break;
case 9823005:
return "9毫米子弹(爆燃)";
break;
case 9823006:
return "9毫米子弹(剧毒)";
break;
case 9823007:
return "5.7毫米子弹(锈蚀)";
break;
case 9823008:
return "5.7毫米子弹(普通)";
break;
case 9823009:
return "5.7毫米子弹(抛光)";
break;
case 9823010:
return "5.7毫米子弹(高爆)";
break;
case 9823011:
return "5.7毫米子弹(爆燃)";
break;
case 9823012:
return "5.7毫米子弹(剧毒)";
break;
case 9823013:
return "7.62毫米子弹(锈蚀)";
break;
case 9823014:
return "7.62毫米子弹(普通)";
break;
case 9823015:
return "7.62毫米子弹(抛光)";
break;
case 9823016:
return "7.62毫米子弹(高爆)";
break;
case 9823017:
return "7.62毫米子弹(爆燃)";
break;
case 9823018:
return "7.62毫米子弹(剧毒)";
break;
case 9823019:
return "5.56毫米子弹(锈蚀)";
break;
case 9823020:
return "5.56毫米子弹(普通)";
break;
case 9823021:
return "5.56毫米子弹(抛光)";
break;
case 9823022:
return "5.56毫米子弹(高爆)";
break;
case 9823023:
return "5.56毫米子弹(爆燃)";
break;
case 9823024:
return "5.56毫米子弹(剧毒)";
break;
case 9823025:
return "12口径霰弹(锈蚀)";
break;
case 9823026:
return "12口径霰弹(普通)";
break;
case 9823027:
return "12口径霰弹(抛光)";
break;
case 9823028:
return "12口径霰弹(高爆)";
break;
case 9823029:
return "12口径霰弹(爆燃)";
break;
case 9823030:
return "12口径霰弹(剧毒)";
break;
case 9823031:
return ".45口径子弹(锈蚀)";
break;
case 9823032:
return ".45口径子弹(普通)";
break;
case 9823033:
return ".45口径子弹(抛光)";
break;
case 9823034:
return ".45口径子弹(高爆)";
break;
case 9823035:
return ".45口径子弹(爆燃)";
break;
case 9823036:
return ".45口径子弹(剧毒)";
break;
case 9823037:
return ".300马格南子弹(锈蚀)";
break;
case 9823038:
return ".300马格南子弹(普通)";
break;
case 9823039:
return ".300马格南子弹(抛光)";
break;
case 9823040:
return ".300马格南子弹(高爆)";
break;
case 9823041:
return ".300马格南子弹(爆燃)";
break;
case 9823042:
return ".300马格南子弹(剧毒)";
break;
case 9823043:
return ".50口径子弹(锈蚀)";
break;
case 9823044:
return ".50口径子弹(普通)";
break;
case 9823045:
return ".50口径子弹(抛光)";
break;
case 9823046:
return ".50口径子弹(高爆)";
break;
case 9823047:
return ".50口径子弹(爆燃)";
break;
case 9823048:
return ".50口径子弹(剧毒)";
break;
case 9823049:
return ".408口径子弹(锈蚀)";
break;
case 9823050:
return ".408口径子弹(普通)";
break;
case 9823051:
return ".408口径子弹(抛光)";
break;
case 9823052:
return ".408口径子弹(高爆)";
break;
case 9823053:
return ".408口径子弹(爆燃)";
break;
case 9823054:
return ".408口径子弹(剧毒)";
break;
case 9823060:
return "装甲加特林子弹";
break;
case 9823061:
return "40mm榴弹";
break;
case 9823062:
return "火箭弹";
break;
case 9823063:
return "燃气瓶";
break;
case 9823064:
return "9毫米子弹(竞赛)";
break;
case 9823065:
return "5.7毫米子弹(竞赛)";
break;
case 9823066:
return "7.62毫米子弹(竞赛)";
break;
case 9823067:
return "5.56毫米子弹(竞赛)";
break;
case 9823068:
return "12口径霰弹(竞赛)";
break;
case 9823069:
return ".45口径子弹(竞赛)";
break;
case 9823070:
return ".300马格南子弹(竞赛)";
break;
case 9823071:
return ".50口径子弹(竞赛)";
break;
case 9823072:
return ".408口径子弹(竞赛)";
break;
case 9823073:
return "箭矢(锈蚀)";
break;
case 9823074:
return "箭矢(普通)";
break;
case 9823075:
return "箭矢(抛光)";
break;
case 9823076:
return "箭矢(高爆)";
break;
case 9823077:
return "箭矢(爆燃)";
break;
case 9823078:
return "箭矢(剧毒)";
break;
case 9823079:
return "箭矢(竞赛)";
break;
case 9823080:
return "E玩法信号弹";
break;
case 9824001:
return "能量饮料";
break;
case 9824002:
return "肾上腺素";
break;
case 9824003:
return "止痛药";
break;
case 9824004:
return "绷带";
break;
case 9824005:
return "急救包";
break;
case 9824006:
return "全能医疗箱";
break;
case 9824007:
return "抗干扰药";
break;
case 9825001:
return "震爆弹";
break;
case 9825002:
return "烟雾弹";
break;
case 9825003:
return "燃烧瓶";
break;
case 9825004:
return "破片手榴弹";
break;
case 9826001:
return "液氮地雷";
break;
case 9826002:
return "雷鸣地雷";
break;
case 9826003:
return "自救型除颤器";
break;
case 9826004:
return "便携式生命探测仪";
break;
case 9826005:
return "弹道追踪仪";
break;
case 9828001:
return "RPG-7火箭筒";
break;
case 9828002:
return "M79榴弹发射器";
break;
case 9828003:
return "突击盾牌";
break;
default:
return "不知道";
break;
}
}


#endif
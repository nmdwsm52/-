#ifndef STRUCT_H
#define STRUCT_H
#include <Function.h>
#include <sys/types.h>


struct Data {
pid_t pid = -1;
int Count,PlayerCount,BotCount,TotalUp;
uintptr_t libUE4;
uintptr_t Gname,Matrixs,Uworld,Uleve,Arrayaddr,Oneself;
uintptr_t Objaddr,Object,Mesh,Human,Bone;
float matrix[16]; // 游戏矩阵
float Fov; // 自身fov
int IsFiring; // 开火判断
int IsAiming; // 开镜判断
int MyWeapon; // 自身手持
int MyTeam; // 自身队伍
float w; // 人物宽度
Vec3 Pos; // 敌人坐标
Vec3 MyPos; // 自身坐标
Vec2 ScreenPos; // 屏幕坐标
Vec3 Predict; // 移动向量
float camera; // 人物相机
//int Act; // 动作
int 敌方动作;
int TeamID; // 队伍
int scwq;//手持武器
int weapon; // 手持
int dqzd; // 当前子弹
int zdmax; // 最大子弹
int drt; // 敌人头
int drj; // 敌人甲
int drb; // 敌人包
bool IsBot; // 人机判断
float Health; // 血量百分比
float Distance; // 距离
char PlayerName[32]; // 玩家名称
float angle; // 雷达旋转值

BoneStruct Head;   
BoneStruct Chest;
BoneStruct Pelvis;
BoneStruct Left_Shoulder;
BoneStruct Right_Shoulder;
BoneStruct Left_Elbow;
BoneStruct Right_Elbow;
BoneStruct Left_Wrist;
BoneStruct Right_Wrist;
BoneStruct Left_Thigh;
BoneStruct Right_Thigh;
BoneStruct Left_Knee;
BoneStruct Right_Knee;
BoneStruct Left_Ankle;
BoneStruct Right_Ankle;
	};
	


struct WuziData{
int Objaddr,Object;
int Count = 0;
float w; // 宽度
Vec3 Pos; // 世界坐标
Vec2 ScreenPos; // 屏幕坐标
float camera; // 相机
float Distance; // 距离
char Name[128]; // 类名
};

extern Data qiyuan;
extern WuziData wz;

  
#endif

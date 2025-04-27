
//微验网络验证//
//如果是AIDE编译jni，请将原main.cpp删除，将此注入好的文件改成main.cpp
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <pthread.h>
#include <fstream>
#include <string.h>
#include <time.h>
#include <malloc.h>
#include <iostream>
#include <fstream>
#include<iostream>
#include<ctime>
using namespace std;

#include <draw.h>
#include <TouchHelper.h>
#include "Android_draw/图片调用.h"
#include "Android_draw/图片/touxiang.h"
#include "Android_draw/图片/自瞄关.h"
#include "Android_draw/图片/自瞄开.h"
#include "wanbai.h"//驱动
#include "结构体.h" // 结构体
#include "物资类.h" // 物资类函数
#include "imgui_ui.h" //ui主要部分

int style_zt = 0;
int style_zx = 0;
int style_bw = 0;
int style_cd = 0;
int style_idx = 0;
int PlayerId;
using namespace std;
timer RenderingFPS;


float 录屏 = false;
static bool isTimerRunning = false;  // 计时器是否运行
static int timerStartTime = 0;       // 计时器开始的时间
static float 录屏时长 = 30; // 默认时间为30秒

bool DrawIo[50];
float NumIo[50];
bool 物资[50];
ImColor 物资颜色[50];
ImColor 绘制颜色[16]; //0触摸颜色12方框颜色34方框背景56射线78骨骼 (真人/人机)
float 绘制粗细[16]; //12方框粗细34射线粗细56骨骼粗细
float draw_style[20];

float fwjl = NumIo[3]; // 自瞄用的，动态范围

ImTextureID logo_png, aim_png; //图片纹理
Data qiyuan; // 敌人及自身结构
WuziData wz; // 物资结构
string wht, flp;

void Draw_Meun();
void AimBotAuto();
void NumIoLoad(const char *name);
void Draw_Main(ImDrawList *Draw);
void 启动和平精英() {
    string command = "am start -n com.vng.pubgmobile/com.epicgames.ue4.SplashActivity";
    system(command.c_str());
}



const char* color_codes[] = {
    "\033[31;1m", // 红色
    "\033[32;1m", // 绿色
    "\033[33;1m", // 黄色
    "\033[34;1m", // 蓝色
    "\033[35;1m", // 紫色
    "\033[36;1m"  // 青色
};


int main() {
   






// 自定义物资();

    //无后台模式
     printf("\033[35;1m           \n请输入: 1 [开启]，2 [关闭]   (y是开启，n是不开)\033[0m\n");
    printf("[—]是否开启无后台运行(尽量不用开)[1/2]：");
    cin >> wht;
    if (wht == "1" || wht == "Y" || wht == "y")
    {
        pid_t pid = fork();
        if (pid > 0)
        {
            exit(0);
        }
        else if (pid == 0)
        {
            
        }
        else
        {
            fprintf(stderr, "[+]开启无后台失败! 请尝试不开启\n");
            exit(1);
        }
    }
    else if (wht == "2" || wht == "N" || wht == "n")
    {
    }
    else
    {
         printf("\033[35;1m**输入错误**\033[0m\n");
        
        exit(0);
    }
    //获取分辨率
    screen_config(); 
    init_screen_x = screen_x + screen_y;
    init_screen_y = screen_y + screen_x;
    printf("\033[37;1m"); 
    printf("[+]是否开启防录屏[1/2]：");
    cin >> flp;
    if (flp == "1" || flp == "Y" || flp == "y")
    {
        if(!init_vulkan(init_screen_x,init_screen_y,true))
        {
            exit(0);
        }
    }
    else if (flp == "2" || flp == "N" || flp == "n")
    {
        if(!init_vulkan(init_screen_x,init_screen_y,false))
        {
            exit(0);
        }
    }
    else
    {
        printf("\033[35;1m输入错误\033[0m\n");
        exit(0);
    }



draw_style[10] = 5;
NumIoLoad("LFM1配置");



if (draw_style[10] == 5) {
printf("\033[36;1m"); //蓝色
printf("输入序列号:\n[0].删除配置\n[1].和平精英\n");
system("sleep 0.1");
// 启动和平精英();  // 调用启动和平精英的函数
// system("sleep 0.5");
// // GetBase();

cin >> draw_style[10];
system("sleep 0.5");
启动和平精英();  // 调用启动和平精英的函数
}



// 随机颜色
srand((unsigned int)time(NULL));
int random_index = rand() % 6;
printf("%s", color_codes[random_index]);
if (draw_style[10] == 0) {
printf("删除成功\n");
} else if (draw_style[10] == 1) {
printf("当前载入游戏: 和平精英\n");
}




if (draw_style[12] == 0) {//没写好
if(!init_vulkan(init_screen_x,init_screen_y,false))
        {
            exit(0);
        }
}
if (draw_style[12] == 1) {
if(!init_vulkan(init_screen_x,init_screen_y,true))
        {
            exit(0);
        }
}


// 渲染初始化
ImGui_init();
// 触摸初始化
TouchScreenHandle();
// 自瞄线程
new thread(AimBotAuto);
// 音量键线程
new thread(音量键隐藏);
// ui样式设置
window_set();
// 获取图片纹理
logo_png = VK.ImAgeHeadFile(touxiang, sizeof(touxiang));
// aim_png = VK.ImAgeHeadFile(自瞄开关, sizeof(自瞄开关));
aim_png = VK.ImAgeHeadFile(自瞄开, sizeof(自瞄开));
aim_png = VK.ImAgeHeadFile(自瞄关, sizeof(自瞄关));
加载枪械图片();

// 初始化pfs
RenderingFPS.AotuFPS_init();
// 设置均和
RenderingFPS.setAffinity();

ImGui_ImplAndroid_NewFrame(init_screen_x, init_screen_y);

// 程序主循环
while (true) {
RenderingFPS.SetFps(NumIo[12]);
RenderingFPS.AotuFPS();

VK_Begin();
if (qiyuan.pid > 0 && qiyuan.libUE4 > 0)
Draw_Main(ImGui::GetForegroundDrawList());
Draw_Meun();
VK_End();      
}

// 清理资源
shutdown();
//free(名言.from);
return 0;
}







// 设置程序初始化的一些参数
void CleanData() {
物资颜色[0] = ImColor(255, 255, 255, 255);
物资颜色[1] = ImColor(255, 255, 255, 255);
物资颜色[2] = ImColor(255, 255, 255, 255);
物资颜色[3] = ImColor(255, 255, 255, 255);
物资颜色[4] = ImColor(255, 255, 255, 255);
物资颜色[5] = ImColor(255, 255, 255, 255);
物资颜色[6] = ImColor(255, 255, 255, 255);
物资颜色[7] = ImColor(255, 255, 255, 255);
物资颜色[8] = ImColor(255, 0, 0, 255);
物资颜色[9] = ImColor(255, 0, 0, 255);
物资颜色[10] = ImColor(255, 255, 255, 255);
物资颜色[11] = ImColor(255, 255, 255, 255);
物资颜色[12] = ImColor(255, 255, 255, 255);
物资颜色[13] = ImColor(255, 255, 255, 255);
物资颜色[14] = ImColor(255, 255, 255, 255);
物资颜色[15] = ImColor(255, 255, 255, 255);
物资颜色[16] = ImColor(255, 255, 255, 255);
物资颜色[17] = ImColor(255, 255, 255, 255);
物资颜色[18] = ImColor(255, 255, 255, 255);
物资颜色[19] = ImColor(255, 255, 255, 255);
物资颜色[20] = ImColor(255, 255, 255, 255);
绘制颜色[0] = ImColor(255, 0, 0, 150);
绘制颜色[1] = {1.0f,0.0f,0.0f,1.0f};
绘制颜色[2] = ImColor(255,255,255,255);
绘制颜色[3] = ImColor(0,0,0,25);
绘制颜色[4] = ImColor(0,0,0,0);
绘制颜色[5] = ImColor(255,0,0,255);
绘制颜色[6] = ImColor(255,255,255,255);
绘制颜色[7] = ImColor(255,0,0,255);
绘制颜色[8] = ImColor(255,255,255,255);
绘制粗细[1] = 1.5f;
绘制粗细[2] = 1.5f;
绘制粗细[3] = 1.5f;
绘制粗细[4] = 1.5f;
绘制粗细[5] = 2.5f;
绘制粗细[6] = 2.5f;
NumIo[1] = 300.0f;  
NumIo[2] = 400.0f;
NumIo[3] = 120.0f;
NumIo[4] = 15.0f;
NumIo[6] = 1400.0f;
NumIo[5] = 650.0f;
NumIo[7] = 300.0f;  
NumIo[8] = 0.0f;  
NumIo[9] = 3.5f; 
NumIo[10] = 0.0f;  
NumIo[11] = 600.0f;
NumIo[12] = 90;
NumIo[13] = 0.0f;
NumIo[14] = 1.5f;
NumIo[15] = 0.0f;
NumIo[16] = 100.0f;
NumIo[17] = 400.0f;
NumIo[19] = 150.0f;
NumIo[20] = 0.0f;
NumIo[21] = 0.0f;
NumIo[22] = 1.0f;
NumIo[23] = 255.0f;
draw_style[3] = 120;
draw_style[7] = 1;
draw_style[8] = 100;
draw_style[9] = 100;
draw_style[12] = 0;
}

// 一些函数的定义
#include "Android_draw/其他.h"
#define AIMBOT_SEPARATED
#include "Aim/Aim.h"
int AimCount, MaxPlayerCount, Gmin = -1;
float zm_x, zm_y;
bool IsAimLongAim = false;
char AimName[32];
Vec2 vpvp;
AimStruct Aim[100]; // 自瞄结构









// 绘图主函数
void Draw_Main(ImDrawList *Draw) {
//尽量绘制类放这



if (draw_style[10] == 0) {
system("rm -rf /data/LFM配置");
exit(1);
}
 else if (draw_style[10] == 1) {
#include "Android_draw/hook.h"
// system("sleep 0.2");
// 启动和平精英();  // 调用启动和平精英的函数
// system("sleep 0.5");

}

//骨骼节点开关选择
if (draw_style[91] == 0) {
DrawIo[19] = false;
}
if (draw_style[91] == 1) {
DrawIo[19] = true;
}

// 自瞄圈圈
if(DrawIo[20] && qiyuan.TotalUp){
if (DrawIo[20] && qiyuan.IsFiring == 1 && DrawIo[25]&&Gmin != -1) {
Draw->AddCircle({screen_x / 2, screen_y / 2}, fwjl, ImColor(0,255,0,255), 0, 2.5f);
}else if(DrawIo[20]) {
Draw->AddCircle({screen_x / 2, screen_y / 2}, NumIo[3], ImColor(0,255,0,255), 0, 2.5f); 
}
}
if(DrawIo[44]){
// 自瞄射线
if (Gmin != -1) {
Draw->AddLine({screen_x / 2, screen_y / 2}, {vpvp.x, vpvp.y}, ImColor(255,255,255,255), 3.0f);
}
}
// 触摸区域
if (DrawIo[21]) {
string ssf;  
ssf += "勿放控件，长按拖动";
auto textSize = ImGui::CalcTextSize(ssf.c_str(), 0, 32);
Draw->AddRectFilled({0,0}, {screen_x, screen_y},ImColor(0,0,0,110));
Draw->AddRectFilled({NumIo[6] - NumIo[7] / 2, screen_y - NumIo[5] + NumIo[7] / 2}, {NumIo[6] + NumIo[7] / 2, screen_y - NumIo[5] - NumIo[7] / 2}, 绘制颜色[0]); 
Draw->AddText(NULL, 32, {NumIo[6] - (textSize.x / 2), screen_y - NumIo[5]}, ImColor(255, 255, 255), ssf.c_str());
}



char *CasName;

for (int i = 0; i < wz.Count; i++)
{

if (wz.w>0){
if (DrawIo[11]&&GetVehicleInfo(wz.Name, &CasName)) {//载具
string name;
name += CasName;
name += "[";
name += to_string((int)wz.Distance);
name += "米]";
auto textSize = ImGui::CalcTextSize(name.c_str(),0, 20);
Draw->AddText(NULL, 20,{wz.ScreenPos.x-(textSize.x / 2), wz.ScreenPos.y}, ImColor(255, 255, 255, 255), name.c_str());
}
}
            }

// 雷达背景
if (DrawIo[7] && qiyuan.TotalUp) {
ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(NumIo[1] - NumIo[19], NumIo[2] - NumIo[19]),  ImVec2(NumIo[1] + NumIo[19], NumIo[2] + NumIo[19]), ImColor(255, 255, 255, 70), 50.0f );//颜色和圆角
ImGui::GetForegroundDrawList()->AddRect({NumIo[1] - NumIo[19],NumIo[2]-NumIo[19]},{NumIo[1] +NumIo[19],NumIo[2]+NumIo[19]},ImColor(255,255,255,125),50,0,4.0f);

ImVec2 pointss[4] = {
ImVec2(NumIo[1] - 8.0f, NumIo[2] + 12.0f), //左脚
ImVec2(NumIo[1], NumIo[2] - 10.0f), //顶点
ImVec2(NumIo[1] + 8.0f, NumIo[2] + 12.0f), //右脚
ImVec2(NumIo[1], NumIo[2] + 6.0f) //中心
};

ImGui::GetBackgroundDrawList()->AddTriangleFilled(pointss[0], pointss[1], pointss[3], ImColor(255,0,0,255));
ImGui::GetBackgroundDrawList()->AddTriangleFilled(pointss[2], pointss[1], pointss[3], ImColor(255,0,0,255));
ImGui::GetBackgroundDrawList()->AddQuad(pointss[0], pointss[1], pointss[2], pointss[3], ImColor(0.0f, 0.0f, 0.0f, 1.0f), 1.335f);
}



} //绘图函数结束


/*// 线性插值
void 线性插值() {
Lerp(窗口x.beg, 窗口x.end, 0.111f);
Lerp(窗口y.beg, 窗口y.end, 0.1f);
Lerp(位置x.beg, 位置x.end, 0.111f);
Lerp(位置y.beg, 位置y.end, 0.1f);
Lerp(设置.beg, 设置.end, 0.06f);
Lerp(调色板.beg, 调色板.end, 0.06f);
Lerp(homepage, homepages, 0.06f);
Lerp(setup, setups, 0.08f);
Lerp(调色板页数.beg, 调色板页数.end, 0.04f);
Lerp(灵动岛宽度.beg, 灵动岛宽度.end, 0.125f);
}


// 菜单，刚写的时候很简洁整齐，东西越来越多就看起来很屎了...
void Draw_Meun() {


window_x = 1250.0f;
window_y = 700.0f;
灵动岛();
自瞄图片();
线性插值();


if (开关) {
窗口x.end = 1250.0f;
窗口y.end = 700.0f;
位置x.end = (float)screen_x/2 - (窗口x.beg - 设置.beg + 调色板.beg)/2;
位置y.end = (float)screen_y/2 - 窗口y.beg/2;
} else {
窗口x.end = 0;
窗口y.end = 0;
位置x.end = 0;
位置y.end = 0;
}




//ImGui::SetNextWindowPos({位置x.beg, 位置y.beg}); //设置窗口位置
ImGui::SetNextWindowSize(ImVec2(窗口x.beg - 设置.beg + 调色板.beg, 窗口y.beg)); //设置窗口的大小 
if (windows) {
zhu_set(); //主窗口设置
ImGui::Begin("币子", &window, /*ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | *ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize );
ImGui::PopStyleVar(); // 恢复之前的圆角设置 
ImGui::PopStyleColor(); //释放边框的颜色设置
//算法刚好ui中间间隔都是15像素，细细品味
aevrage_all = window_x / 6.302521f; 
aevrage_now = ImGui::GetWindowSize().x / 6.302521f; 
// aevrage_now = ImGui::GetWindowSize().x / 6.25f; 
tab0 = window_y * 0;
tab1  = window_y * 1;
tab2 = window_y * 2;
tab3 = window_y * 3;
tab4 = window_y * 4;

// 绘制第一个子窗口
if (window) {
ImGui::SetCursorPos(ImVec2(15, 15));
ImGui::BeginChild("左侧标题", ImVec2(aevrage_now, 670), true);
DrawLogo(logo_png ,{ImGui::GetWindowPos().x + aevrage_now/1.944444f, ImGui::GetWindowPos().y + 90}, 85);
//减32是因为imgui控件每个间隔16像素
ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5); //设置光标位置
ImGui::Separator();
		if (ImGui::Button("主页", ImVec2(140, 66)))
    			{
    				Tab = 0;					
    			}
    			ImGui::ItemSize(ImVec2(0, 2));
    			if (ImGui::Button("绘制", ImVec2(140, 66)))
    			{
    				Tab = 1;					
    			}
    			ImGui::ItemSize(ImVec2(0, 2));
    			if (ImGui::Button("自瞄", ImVec2(140, 66)))
    			{
    				Tab = 2;				
    			} 
    			ImGui::ItemSize(ImVec2(0, 2));
    			if (ImGui::Button("设置", ImVec2(140, 66)))
    			{
    				Tab = 3;					
    			}
    			ImGui::ItemSize(ImVec2(0, 2));
				if (ImGui::Button("隐藏", ImVec2(140, 66)))
    			{
    				开关 = false;
    			}
ImGui::EndChild(); 
    

    

if (Tab == 0) {
homepages = tab0;
设置.end = 0;
} else if (Tab == 1) {
homepages = tab1;
设置.end = 0;
} else if (Tab == 2) {
homepages = tab2;
设置.end = 0;
} else if (Tab == 3) {
homepages = tab3;
设置.end = 252.0f;
} else if (Tab == 4) {
homepages = tab4;
设置.end = 0;
}
ImGui::SetCursorPos(ImVec2(aevrage_now + 30, 15 + tab0 - homepage));
ImGui::BeginChild("主页，第一排，第一个", ImVec2(aevrage_now*3, 670), true); 
主页_1();
ImGui::EndChild();


ImGui::SetCursorPos(ImVec2(aevrage_now*4 + 45, 15 + tab0 - homepage));
ImGui::BeginChild("主页，第一排，第二个", ImVec2(aevrage_now*2, 670), true); 
主页_2();
ImGui::EndChild();

ImGui::SetCursorPos(ImVec2(aevrage_now + 30, 15 + tab1 - homepage));
ImGui::BeginChild("绘制，第一排，第一个", ImVec2(aevrage_now*3, 410), true); 
绘制_1();
ImGui::EndChild();


ImGui::SetCursorPos(ImVec2(aevrage_now*4 + 45, 15 + tab1 - homepage));
ImGui::BeginChild("绘制，第一排，第二个", ImVec2(aevrage_now*2, 320), true);
绘制_2();
ImGui::EndChild();


ImGui::SetCursorPos(ImVec2(aevrage_now + 30, 440 + tab1 - homepage));
ImGui::BeginChild("绘制，第二排，第一个", ImVec2(aevrage_now*3, 245), true, ImGuiWindowFlags_NoScrollbar);
绘制_3();
ImGui::EndChild();


ImGui::SetCursorPos(ImVec2(aevrage_now*4 + 45, 350 + tab1 - homepage));
ImGui::BeginChild("绘制，第二排，第二个", ImVec2(aevrage_now*2, 335), true, ImGuiWindowFlags_NoScrollbar);
绘制_4();
ImGui::EndChild();


ImGui::SetCursorPos(ImVec2(aevrage_now + 30, 15 + tab2 - homepage));
ImGui::BeginChild("自瞄，第一排，第一个", ImVec2(aevrage_now*3, 340), true, ImGuiWindowFlags_NoScrollbar);
自瞄_1();
ImGui::EndChild();


ImGui::SetCursorPos(ImVec2(aevrage_now*4 + 45, 15 + tab2 - homepage));
ImGui::BeginChild("自瞄，第一排，第二个", ImVec2(aevrage_now*2, 670), true);
自瞄_2();
ImGui::EndChild();


ImGui::SetCursorPos(ImVec2(aevrage_now + 30, 370 + tab2 - homepage));
ImGui::BeginChild("自瞄，第二排，第一个", ImVec2(aevrage_now*3, 315), true, ImGuiWindowFlags_NoScrollbar);
自瞄_3();
ImGui::EndChild();

设置_调色板_size = 调色板.beg / 4.5f;
ImGui::SetCursorPos(ImVec2(aevrage_now + 30, 15 + tab3 - homepage));
ImGui::BeginChild("设置", ImVec2(aevrage_all*4 - 设置_调色板_size, 670), true, ImGuiWindowFlags_NoScrollbar);
设置页面();
ImGui::EndChild();

ImGui::SetCursorPos(ImVec2(aevrage_all*5.03f - 设置_调色板_size / 3.2f, 15 + tab3 - homepage));
ImGui::BeginChild("设置2", ImVec2(aevrage_all*1.75f, 670), true, ImGuiWindowFlags_NoScrollbar);
设置_0();
ImGui::EndChild();

}
  


ImGui::End();
}





}


bool 待更新[20];

void 主页_1() {
if (名言开关) {
// 释放之前的名言
free(名言.quote);
free(名言.from);

// 获取新的名言
OneSay result = 获取名人名言();
if (result.quote && result.from) {
名言.quote = result.quote;
名言.from = result.from;
} else {
名言.quote = strdup(" 名言获取失败，请重启后重试！");
名言.from = NULL;
}
// 设置标志为不需要请求新的名言
名言开关 = false;
}

CenteredText("币子内核", 1.7f);
ImGui::BeginChild("主页独白", ImVec2(ImGui::GetContentRegionAvail().x, 170), true, ImGuiWindowFlags_NoScrollbar);
ImGui::Text("本程序用于游戏公司修复游戏漏洞参考\n严禁个人使用本程序进行破坏游戏平衡的行为\n使用后的任何行为跟作者无关\n必须在下载后24小时内删除本程序"); 
ImGui::EndChild();
ImGui::TextColored(ImColor(230, 0, 0,225), " 币子频道TG:@qiyuannb ");
ImGui::TextColored(ImColor(230, 0, 0,225), " 请注意演戏!!! ");
ImGui::Text (" 当前帧率: %1.f   VK渲染耗时: %.3fms ", ImGui::GetIO().Framerate, ImGui::GetIO().DeltaTime * 1000.0f);
ImGui::Text (" 设备分辨率为: %dx%d", screen_x, screen_y);
if (qiyuan.libUE4)
{
ImGui::TextColored(ImColor(0, 255, 0,225), " libUE4.so: 0x%lX", qiyuan.libUE4);
} else {
ImGui::TextColored(ImColor(255, 0, 0,225), " libUE4.so: 0x%lX", qiyuan.libUE4);
}


static bool 来句名言;
if (!来句名言) {
来句名言 = true;
名言开关 = true;
} else {
if (名言.quote && 名言.from) {
ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 9); //设置光标位置
ImGui::TextWrapped("“%s”", 名言.quote);
ImGui::Text(" 出自: %s", 名言.from);
} else {
ImGui::TextWrapped(" 名言获取失败,请重新尝试");
}
ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 9); //设置光标位置
if (button("来句名言", ImVec2(0, 0), 8.0f, ImVec4(0.86f, 0.86f, 0.86f, 0.0f), ImVec4(0.0f, 0.0f, 0.0f, 1.0f) )) {
名言开关 = true;
}
}
}

void 清理(){
system("rm -rf /data/user/0/com.tencent.tmgp.pubgmhd/files/ano_tmp");
system("rm -rf /data/data/com.tencent.tmgp.pubgmhd/files/ano_tmp");
}


void 主页_2() {
title("录制");

static float 录屏时长 = 30; // 默认时间为10秒
static atomic<bool> isRecording(false); // 全局变量
static float lp_beg, lp_end;
lp_beg += (lp_end - lp_beg) * (0.2f * speed); // 动画速率

SliderFloat("自定义录制秒数", &录屏时长, 1, 120,"%1.f");
ImGui::Spacing();ImGui::Spacing();ImGui::Spacing();

Line(365);
ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX() - lp_beg, ImGui::GetCursorPosY())); //设置光标位置
if (button("开始录制", ImVec2(365, 70))) {
lp_end = 400;
if (!isRecording.load()) {
isRecording.store(true);
thread([](int 录屏时长) {
  // 非阻塞式开始录制
string beijingTime = getBeijingTimeString(); // 获取北京时间字符串
string fileName = "/sdcard/币子内核录制" + beijingTime + ".mp4";
string command = "screenrecord --time-limit " + to_string(录屏时长) + " " + fileName + " &";
system(command.c_str());

isRecording.store(false);
}, 录屏时长).detach();
}
}
// Line(365);
ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX() + 400 - lp_beg, ImGui::GetCursorPosY() - 82.5f)); //设置光标位置
if (button("停止录制", ImVec2(365, 70))) {
lp_end = 0;
system("pkill -l SIGINT screenrecord");
isRecording.store(false);
}
Line(365);


// 显示按钮
if (!qiyuan.libUE4) {
    // 如果未获取到UE4数据，显示“[!]初始化游戏数据”按钮
    if (ImGui::Button("[!]初始化游戏数据", ImVec2(365, 70))) {
        清理(); // 执行清理操作
        GetBase(); // 获取基础数据
    }
} else {
    // 如果已获取到UE4数据，显示“[!]注销读写”按钮
    if (ImGui::Button("[!]注销读写[退出]", ImVec2(365, 70))) {
        exit(0); // 退出程序
    }
}
Line(365);



if (button("截屏", ImVec2(365, 70))) {
string beijingTime = getBeijingTimeString(); // 获取北京时间字符串
string fileName = "/sdcard/币子内核截屏." + beijingTime + ".png";
string screenshotCommand = "screencap -p \'" + fileName + "\'";
int result = system(screenshotCommand.c_str());
if (result == 0) {
std::cout << "截屏成功" << std::endl;
} else {
std::cout << "截屏失败" << std::endl;
}
}
Line(365);
if (button("地铁配置", ImVec2(365, 70))) {
                        DrawIo[3] = true;
                        DrawIo[17] = true;
                        DrawIo[10] = true;
                        DrawIo[2] = true;
                        DrawIo[5] = true;
                        DrawIo[7] = true;
                        DrawIo[6] = true;
                        DrawIo[8] = true;
                        DrawIo[14] = true;
                        DrawIo[15] = true;
                        DrawIo[13] = true;
                        DrawIo[19] = true;
                        物资[1] = true;
                        DrawIo[43] = true;;
}
Line(365);
if (button("经典配置", ImVec2(365, 70))) {
	                    DrawIo[3] = true;
                        物资[10] = true;
                        DrawIo[10] = true;
                        DrawIo[2] = true;
                        DrawIo[5] = true;
                        DrawIo[7] = true;
                        DrawIo[6] = true;
                        DrawIo[8] = true;
                        DrawIo[14] = true;
                        DrawIo[15] = true;
                        DrawIo[13] = true;
                        DrawIo[19] = true;
                        物资[0] = true;
                        DrawIo[12] = true;
                        物资[9] = true;
                        物资[8] = true;;

}
Line(365);
ImGui::TextColored(ImColor(255, 0, 0,225), "");

            ImGui::SameLine(+50.0f);
           if (ImGui::Combo("", &style_zt, "原生主题\0酷安主题\0巴托主题\0蓝色主题\0透明主题\0凯撒主题\0独特蓝灰\0红色主题\0绿色主题\0黑色主题\0温迪主题\0"))
            {
                switch (style_zt)
                {
            case 0:
                原版();
                break;
            case 1:
                酷安(); 
                break;
            case 2:
                巴巴托斯(); 
                break;
            case 3:
                冰冷(); 
                break;
            case 4:
                透明();
                break;
            case 5:
                凯撒(); 
                break;
            case 6:
                独特蓝灰(); 
                break;
                case 7:
                
                橙色(); 
                break;
                case 8:
                粉色();
                break;
                case 9:
                炫酷黑();
                break;
                case 10:
                温迪(); 
                break;
            }
            }
            }









void 绘制_1() {
title("常用绘制");
Checkbox("绘制方框", &DrawIo[1]);
ImGui::SameLine();
Checkbox("绘制骨骼", &DrawIo[3]);
ImGui::SameLine();
Checkbox("绘制手持", &DrawIo[10]);

Checkbox("绘制射线", &DrawIo[2]);
ImGui::SameLine();
Checkbox("绘制距离", &DrawIo[5]);
ImGui::SameLine();
Checkbox("绘制雷达", &DrawIo[7]);

Checkbox("绘制血量", &DrawIo[6]);
ImGui::SameLine();
Checkbox("骨骼节点", &DrawIo[19]);
ImGui::SameLine();
Checkbox("手雷预警", &DrawIo[14]);

Checkbox("忽略人机", &DrawIo[17]);
ImGui::SameLine();
Checkbox("绘制盒子", &物资[10]);
ImGui::SameLine();
Checkbox("地铁箱子", &物资[1]);


Checkbox("绘制载具", &物资[0]);
ImGui::SameLine();
Checkbox("绘制金插", &物资[8]);
ImGui::SameLine();
Checkbox("绘信号枪", &物资[9]);
}

void 绘制_2() {
title("绘图样式");
vector<string> 人数样式 = {"普通", "仿比翼", "混合"};
vector<string> 绘图样式 = {"扁圆", "方形", "圆环"};

qiyuannb(人数样式, draw_style[0], 0, 120.0f);
qiyuannb(绘图样式, draw_style[1], 0, 120.0f);
}

void 绘制_3() {
title("敌背设置");
Checkbox("背敌预警", &DrawIo[8]);
vector<string> 敌背样式 = {"圆形", "箭头"};

qiyuannb(敌背样式, draw_style[2], 0, 120.0f);
}

void 绘制_4() {
title("雷达参数调节");
SliderFloat ("雷达X", &NumIo[1], 10, 3200, "%1.f");
SliderFloat ("雷达Y", &NumIo[2], 10, 1440, "%1.f");
SliderFloat ("雷达缩放比例", &NumIo[16], 70, 150, "%1.f", 5);
}





void 自瞄_1() {
title("自瞄设置");
Checkbox("自瞄开关", &DrawIo[20]);

Checkbox("持续锁定", &DrawIo[30]);
ImGui::SameLine();
Checkbox("准心射线", &DrawIo[44]);
ImGui::SameLine();
Checkbox("触摸位置", &DrawIo[21]);

Checkbox("动态范围", &DrawIo[25]);
ImGui::SameLine();
Checkbox("忽略人机", &DrawIo[31]);
}




void 自瞄_2() {
title("自瞄参数");
//SliderFloat ("自瞄距离", &NumIo[19], 10.0f, 500.0f, "%1.f");
SliderFloat ("自瞄大小", &NumIo[3], 10.0f, 800.0f, "%1.f");
// SliderFloat ("喷子距离", &自动瞄准.喷子自瞄距离, 10.0f, 500.0f, "%1.f");
// SliderFloat ("范围粗细", &自动瞄准.范围粗细, 0.5f, 10.0f, "%0.1f");
SliderFloat ("平滑力度", &NumIo[9], 1.0f, 50.0f, "%0.1f");
SliderFloat ("瞄准速度", &NumIo[4], 1.0f, 30.0f, "%0.1f");
// SliderFloat ("触摸范围", &NumIo[7], 50.01f, 400.0f, "%0.2f");
//SliderFloat ("子弹下坠", &NumIo[11], 100.0f, 1000.0f, "%1.f");
SliderFloat ("压枪力度", &NumIo[14], 0.1f, 8.0f, "%.1f", 5);
SliderFloat ("预判调节", &NumIo[22], 0.1f, 5.0f, "%.1f", 5);
}

void 自瞄_3() {
title("锁定设置");
            if (ImGui::Combo("触发条件", &style_bw, "开火自瞄\0开镜自瞄\0开火开镜\0")) {
                switch (style_bw) 
                {
                    case 0:NumIo[0] = 0.0; 
                        break;
                    case 1:NumIo[0] = 1.0; 
                         break;
                    case 2:NumIo[0] = 2.0; 
                        break;                          
                }          
            }
            
            if (ImGui::Combo("瞄准优先", &style_zx, "准心优先\0距离优先\0")) {
                switch (style_zx) 
                {
                    case 0:NumIo[21] = 0.0; 
                        break;
                    case 1:NumIo[21] = 1.0; 
                         break;
                }          
            }
                        if (ImGui::Combo("自瞄部位", &style_idx, "自动\0头部\0胸部\0臀部\0")) {
                switch (style_idx) 
                {
                    case 0:NumIo[8] = 0.0; 
                        break;
                    case 1:NumIo[8] = 1.0; 
                         break;
                    case 2:NumIo[8] = 2.0; 
                        break;
                    case 3:NumIo[8] = 3.0; 
                        break;
                }          
            }                     
            ImGui::Spacing();//间距
            ImGui::Spacing();//间距
            title("其他设置");
            if (ImGui::Combo("充电位置", &style_cd, "充电口右\0充电口左\0")) {
                switch (style_cd) 
                {
                    case 0:NumIo[10] = 0.0; 
                        break;
                    case 1:NumIo[10] = 1.0; 
                         break;
                }          
            }
           

}



int 页 = 1;
void 设置_0() {
ostringstream oss;
oss << "第" << 页 << "页"; 


title("调色板");
调色板按钮(tsb_but, 鸡鸡鸡, 0, 315, 90, 1 );
ImGui::Spacing();
ImGui::SetCursorPos(ImVec2( 15 + 调色板页数.beg, 180));
绘制调色板();
ImGui::Spacing();


if (button("上1页", ImVec2(95,60), 8.0f, ImVec4(0.86f, 0.86f, 0.86f, 1.0f))) {
调色板页数.end += 330;
页 -= 1;
}
ImGui::SameLine();
button(oss.str().c_str(), ImVec2(95,60), 8.0f, ImVec4(0.86f, 0.86f, 0.86f, 1.0f), ImVec4(0.0f, 0.0f, 0.0f, 0.0f), ImVec4(0.86f, 0.86f, 0.86f, 1.0f));
ImGui::SameLine();
if (button("下1页", ImVec2(95,60), 8.0f, ImVec4(0.86f, 0.86f, 0.86f, 1.0f))) {
调色板页数.end -= 330;
页 += 1;
}

if (调色板页数.end >= 0) {
调色板页数.end = 0;
页 = 1;
} else if (调色板页数.end <= -660) {
调色板页数.end = -660;
页 = 3;
}
}




void 设置页面() {
vector<string> 设置页面 = {"常用设置", "色彩设置", "物质绘制", "物资颜色", "物资色2"}; //偏好设置放颜色绘制大小
qiyuannb(设置页面, 设置_Tab, 0, ImGui::GetWindowSize().x / 5.2f, 90.0f);
float 设置tab_size = aevrage_all*4 - 设置_调色板_size;
tab_0 = 设置tab_size * 0;
tab_1  = 设置tab_size * 1;
tab_2 = 设置tab_size * 2;
tab_3 = 设置tab_size * 3;
tab_4 = 设置tab_size * 4;

if (Tab == 3 && 设置_Tab == 0) {
setups = tab_0;
调色板.end = 0;
} else if (Tab == 3 && 设置_Tab == 1) {
setups = tab_1;
调色板.end = 340.0f;
} else if (Tab == 3 && 设置_Tab == 2) {
setups = tab_2;
调色板.end = 0;
} else if (Tab == 3 && 设置_Tab == 3) {
setups = tab_3;
调色板.end = 0;
} else if (Tab == 3 && 设置_Tab == 4) {
setups = tab_4;
调色板.end = 0;
} else {
调色板.end = 0;
}


ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.0f, 0.0f, 0.0f, 0.0f)); // 设置边框颜色 
ImGui::SetCursorPos(ImVec2(tab_0 - setup, 105));
ImGui::BeginChild("常用设置 ", ImVec2(tab_1, 560), true, ImGuiWindowFlags_NoScrollbar); 
ImGui::PopStyleColor();
设置_1();
ImGui::EndChild();


ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.0f, 0.0f, 0.0f, 0.0f)); // 设置边框颜色 
ImGui::SetCursorPos(ImVec2(tab_1 - setup, 105));
ImGui::BeginChild("色彩设置", ImVec2(tab_1, 560), true, ImGuiWindowFlags_NoScrollbar);
ImGui::PopStyleColor();
设置_2();
ImGui::EndChild();


ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.0f, 0.0f, 0.0f, 0.0f)); // 设置边框颜色 
ImGui::SetCursorPos(ImVec2(tab_2 - setup, 105));
ImGui::BeginChild("物资绘制", ImVec2(tab_1, 560), true, ImGuiWindowFlags_NoScrollbar);
ImGui::PopStyleColor();
设置_3();
ImGui::EndChild();


ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.0f, 0.0f, 0.0f, 0.0f)); // 设置边框颜色 
ImGui::SetCursorPos(ImVec2(tab_3 - setup, 105));
ImGui::BeginChild("物资颜色", ImVec2(tab_1, 560), true, ImGuiWindowFlags_NoScrollbar);
ImGui::PopStyleColor();
设置_4();
ImGui::EndChild();


ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.0f, 0.0f, 0.0f, 0.0f)); // 设置边框颜色 
ImGui::SetCursorPos(ImVec2(tab_4 - setup, 105));
ImGui::BeginChild("物资色2", ImVec2(tab_1, 560), true, ImGuiWindowFlags_NoScrollbar);
ImGui::PopStyleColor();
设置_5();
ImGui::EndChild();

}


void 设置_1() {
SliderFloat ("Gui刷新率(调成游戏帧率)", &NumIo[12], 60.0f, 120.0f, "%1.f", 5);
SliderFloat ("全局动画速率(60帧2.0倍 90帧1.5倍 120帧1.0倍)", &speed, 0.5f, 3.0f, "%0.2f", 5);
//SliderFloat ("雷达缩放比例", &NumIo[16], 70, 150, "%1.f", 5);

ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 110); //设置光标位置
if (button("保存配置", ImVec2(243, 100), 20.0f, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), ImVec4(0.25f, 0.25f, 0.25f, 1.0f))) {
NumIoSave("LFM配置");
}
ImGui::SameLine();
if (button("重置配置", ImVec2(243, 100), 20.0f, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), ImVec4(0.25f, 0.25f, 0.25f, 1.0f))) {
CleanData();
}
ImGui::SameLine();
if (button("退出辅助", ImVec2(243, 100), 20.0f, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), ImVec4(0.25f, 0.25f, 0.25f, 1.0f))) {
exit(0);
}
}


void 设置_2() {
ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5); //设置光标位置
SliderFloat (( "透明度: " + tsb_but).c_str(), &透明度, 0.0f, 1000.0f, "%1.f", 5);

调色板按钮("玩家边框", 绘制颜色[1], 1 );
ImGui::SameLine();
调色板按钮("人机边框", 绘制颜色[2], 2 );

调色板按钮("玩家填充", 绘制颜色[3], 3 );
ImGui::SameLine();
调色板按钮("人机填充", 绘制颜色[4], 4 );

调色板按钮("玩家射线", 绘制颜色[5], 5 );
ImGui::SameLine();
调色板按钮("人机射线", 绘制颜色[6], 6 );

调色板按钮("玩家骨骼", 绘制颜色[7], 7 );
ImGui::SameLine();
调色板按钮("人机骨骼", 绘制颜色[8], 8 );

}


void 设置_3() {

Checkbox("载具", &物资[0]);
ImGui::SameLine();
Checkbox("宝箱", &物资[1]);
ImGui::SameLine();
Checkbox("物资箱", &物资[2]);
ImGui::SameLine();
Checkbox("武器箱", &物资[3]);

Checkbox("药品箱", &物资[4]);
ImGui::SameLine();
Checkbox("信函箱", &物资[5]);
ImGui::SameLine();
Checkbox("坦克", &物资[6]);
ImGui::SameLine();
Checkbox("狗子", &物资[7]);

Checkbox("金插", &物资[8]);
ImGui::SameLine();
Checkbox("信号枪", &物资[9]);
ImGui::SameLine();
Checkbox("盒子空投", &物资[10]);
ImGui::SameLine();
Checkbox("药品", &物资[11]);

Checkbox("手枪", &物资[12]);
ImGui::SameLine();
Checkbox("步枪", &物资[13]);
ImGui::SameLine();
Checkbox("冲锋枪", &物资[14]);
ImGui::SameLine();
Checkbox("狙击枪", &物资[15]);

Checkbox("霰弹枪", &物资[16]);
ImGui::SameLine();
Checkbox("子弹", &物资[17]);
ImGui::SameLine();
Checkbox("弹夹", &物资[18]);
ImGui::SameLine();
Checkbox("枪口", &物资[19]);
ImGui::SameLine();
Checkbox("瞄准镜", &物资[20]);




}




void 设置_4() {
vector<string> 防录屏开关 = {"防录屏关", "防录屏开"};



qiyuannb(防录屏开关, draw_style[12], 0, 140, 80);
ImGui::ColorEdit4("信号枪", (float*)&物资颜色[9]);
ImGui::ColorEdit4("盒子空投", (float*)&物资颜色[10]);
ImGui::ColorEdit4("药品", (float*)&物资颜色[11]);
ImGui::ColorEdit4("手枪", (float*)&物资颜色[12]);
ImGui::ColorEdit4("步枪", (float*)&物资颜色[13]);
ImGui::ColorEdit4("冲锋枪", (float*)&物资颜色[14]);
ImGui::ColorEdit4("狙击枪", (float*)&物资颜色[15]);
ImGui::ColorEdit4("霰弹枪", (float*)&物资颜色[16]);
ImGui::ColorEdit4("子弹", (float*)&物资颜色[17]);
ImGui::ColorEdit4("弹夹", (float*)&物资颜色[18]);


}

void 设置_5() {
ImGui::ColorEdit4("载具", (float*)&物资颜色[0]);
ImGui::ColorEdit4("宝箱", (float*)&物资颜色[1]);
ImGui::ColorEdit4("物资箱", (float*)&物资颜色[2]);
ImGui::ColorEdit4("武器箱", (float*)&物资颜色[3]);
ImGui::ColorEdit4("药品箱", (float*)&物资颜色[4]);
ImGui::ColorEdit4("信函箱", (float*)&物资颜色[5]);
ImGui::ColorEdit4("坦克", (float*)&物资颜色[6]);
ImGui::ColorEdit4("狗子", (float*)&物资颜色[7]);
ImGui::ColorEdit4("金插", (float*)&物资颜色[8]);
ImGui::ColorEdit4("枪口", (float*)&物资颜色[19]);
ImGui::ColorEdit4("瞄准镜", (float*)&物资颜色[20]);

}*/

void 线性插值() {
Lerp(窗口x.beg, 窗口x.end, 0.111f);
Lerp(窗口y.beg, 窗口y.end, 0.1f);
Lerp(位置x.beg, 位置x.end, 0.05f);
Lerp(位置y.beg, 位置y.end, 0.1f);
Lerp(动画.beg, 动画.end, 0.06f);
Lerp(圆角值.beg, 圆角值.end, 0.1f);
Lerp(设置.beg, 设置.end, 0.06f);
Lerp(调色板.beg, 调色板.end, 0.06f);
Lerp(homepage, homepages, 0.06f);
Lerp(setup, setups, 0.08f);
Lerp(调色板页数.beg, 调色板页数.end, 0.04f);
Lerp(灵动岛宽度.beg, 灵动岛宽度.end, 0.125f);
Lerp(灵动岛高度s.beg, 灵动岛高度s.end, 0.1f);
Lerp(灵动岛高度x.beg, 灵动岛高度x.end, 0.1f);
Lerp(字体位置.beg, 字体位置.end, 0.125f);
Lerp(字体大小.beg, 字体大小.end, 0.125f);
}


float 贝塞尔x(float t, float p0, float p1, float p2, float p3) {
    float u = 1 - t;
    return u * u * u * p0 + 1 * u * u * t * p1 + 2 * u * t * t * p2 + t * t * t * p3;
}

float 贝塞尔y(float t, float k0, float k1, float k2, float k3) {
    float u = 1 - t;
    return u * u * u * k0 + 2 * u * u * t * k1 + 4 * u * t * t * k2 + t * t * t * k3;
}



// 菜单，刚写的时候很简洁整齐，东西越来越多就看起来很屎了...
void Draw_Meun() {
window_x = 1000.0f;
window_y = 700.0f;
灵动岛();
/*if (DrawIo[34]) {
自瞄图片();
}*/
线性插值();
if (开关) {
位置x.end = 10;
动画.end = 1;
人数位置.beg = 0;
} else {
位置x.end = 0;
动画.end = 0;
人数位置.beg = 50;
if (Tab == 3) {
窗口x.end = 332 - 调色板.beg;
} else {
窗口x.end = 80;
}
窗口y.end = 80;
}

float p0 = (float)screen_x / 2 - (窗口x.beg - 设置.beg + 调色板.beg) / 2;
float k0 = 33;


float p1 = (float)screen_x / 2 + 700;
float k1 = 80;

float p2 = (float)screen_x / 2 - (窗口x.beg - 设置.beg + 调色板.beg) / 2;
float k2 = (float)screen_y / 2 - 窗口y.beg / 2;

float p3 = (float)screen_x / 2 - (窗口x.beg - 设置.beg + 调色板.beg) / 2;
float k3 = (float)screen_y / 2 - 窗口y.beg / 2;

float t = 动画.beg;

float 不知道 = 0;
float 听不懂 = 0;
不知道 += 贝塞尔x(t, p0, p1, p2, p3);
听不懂 += 贝塞尔y(t, k0, k1, k2, k3);

//printf("\n%.1f\n", 不知道);
/*
if(不知道 > (-84)) 
{
printf("\n1\n");
}
*/
if (动画.beg < 0.01) windows = 0;else windows = 1;
if (动画.beg > 0.99) 圆角 = 25; else 圆角 = 50;
if (动画.beg > 0.99) window = 1;else window = 0;
if (动画.beg > 0.9) {
窗口x.end = 1100.0f;
窗口y.end = 730.0f;
//窗口x和窗口y相差550.0f
} else {
if (Tab == 3) {
窗口x.end = 332 - 调色板.beg;
} else {
窗口x.end = 80;
}
窗口y.end = 80;

}
ImGui::SetNextWindowPos({不知道, 听不懂}); // 设置窗口位置
ImGui::SetNextWindowSize(ImVec2(窗口x.beg - 设置.beg + 调色板.beg, 窗口y.beg)); //设置窗口的大小 
if (windows) {
zhu_set(); //主窗口设置
ImGui::Begin("白云", &window, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize );
ImGui::PopStyleVar(); // 恢复之前的圆角设置 
ImGui::PopStyleColor(); //释放边框的颜色设置
//算法刚好ui中间间隔都是15像素，细细品味
aevrage_all = window_x / 6.302521f; 
aevrage_now = ImGui::GetWindowSize().x / 6.302521f; 
// aevrage_now = ImGui::GetWindowSize().x / 6.25f; 
tab0 = window_y * 0;
tab1  = window_y * 1;
tab2 = window_y * 2;
tab3 = window_y * 3;
tab4 = window_y * 4;

// 绘制第一个子窗口
if (window) {
ImGui::SetCursorPos(ImVec2(45, 20));
ImGui::BeginChild("左侧标题", ImVec2(aevrage_now*1.22, 670), true);
DrawLogo(logo_png ,{ImGui::GetWindowPos().x + aevrage_now/1.944444f, ImGui::GetWindowPos().y + 90}, 85);
//图片2
/*auto Pos = ImGui::GetWindowPos();
DrawLogo(logo_png, {Pos.x + 97, Pos.y + 75}, 85);
ImGui::SetCursorPos({0, 160});
*/
//减32是因为imgui控件每个间隔16像素
ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5); //设置光标位置
ImGui::Separator();
if (button("主页", ImVec2(ImGui::GetContentRegionAvail().x,81))) 
Tab = 0;
ImGui::Separator();
if (button("绘制", ImVec2(ImGui::GetContentRegionAvail().x,81))) 
Tab = 1;
ImGui::Separator();
if (button("自瞄", ImVec2(ImGui::GetContentRegionAvail().x,81))) 
Tab = 2;
ImGui::Separator();
if (button("调节", ImVec2(ImGui::GetContentRegionAvail().x,81)))  
Tab = 3;
ImGui::Separator();
if (button("设置", ImVec2(ImGui::GetContentRegionAvail().x,81)))  
Tab = 4;
//ImGui::Separator();
/*if (button("隐藏", ImVec2(ImGui::GetContentRegionAvail().x,81))) 
开关 = false;*/
ImGui::EndChild(); 


if (Tab == 0) {
homepages = tab0;
设置.end = 0;
} else if (Tab == 1) {
homepages = tab1;
设置.end = 0;
} else if (Tab == 2) {
homepages = tab2;
设置.end = 0;
} else if (Tab == 3) {
homepages = tab3;
设置.end = 0;
} else if (Tab == 4) {
homepages = tab4;
设置.end = 0;
}
//135是左写小就是右--35是下写小就是上
//4是左600是大小
ImGui::SetCursorPos(ImVec2(aevrage_now + 135, 38 + tab0 - homepage));
ImGui::BeginChild("主页，第一排，第一个", ImVec2(aevrage_now*4, 600), true); 
主页_1();
ImGui::EndChild();



ImGui::SetCursorPos(ImVec2(aevrage_now + 135, 38 + tab1 - homepage));
ImGui::BeginChild("绘制，第一排，第一个", ImVec2(aevrage_now*4, 600), true); 
绘制_1();
ImGui::EndChild();



ImGui::SetCursorPos(ImVec2(aevrage_now + 135, 38 + tab2 - homepage));
ImGui::BeginChild("自瞄，第一排，第一个", ImVec2(aevrage_now*4, 600), true, ImGuiWindowFlags_NoScrollbar);
自瞄_1();
ImGui::EndChild();



ImGui::SetCursorPos(ImVec2(aevrage_now + 135, 38 + tab3 - homepage));
ImGui::BeginChild("调节，第一排，第一个", ImVec2(aevrage_now*4, 630), true, ImGuiWindowFlags_NoScrollbar);
调节_1();
ImGui::EndChild();




ImGui::SetCursorPos(ImVec2(aevrage_now + 135, 38 + tab4 - homepage));
ImGui::BeginChild("设置，第一排，第一个", ImVec2(aevrage_now*4, 600), true, ImGuiWindowFlags_NoScrollbar);
设置_1();
ImGui::EndChild();

}
ImGui::End();
}





}


bool 待更新[20];

void 主页_1() {


CenteredText("LFM内核", 1.7f);
//ImGui::BeginChild("主页独白", ImVec2(ImGui::GetContentRegionAvail().x, 170), true, ImGuiWindowFlags_NoScrollbar);
ImGui::Text("本程序仅供游戏公司用于修复游戏漏洞做参考\n严禁个人使用本程序进行破坏游戏平衡的行为\n个人使用者的任何行为与作者无关\n请在下载后24小时内删除本程序"); 
/*//ImGui::EndChild();
// float 电量 = 获取电量();
// string 开机时间 = 获取开机时间();
// ImGui::TextColored(ImColor(230, 0, 0,225), " 当前手机已运行: %s", 开机时间.c_str());
//ImGui::TextColored(ImColor(105, 176, 255, 255), " 咬一口白云棉花糖 嗯～ 是草莓味！");
ImGui::Text (" 当前帧率: %1.f   渲染耗时: %.3fms ", ImGui::GetIO().Framerate, ImGui::GetIO().DeltaTime * 1000.0f);
ImGui::Text (" 设备分辨率为: %dx%d", screen_x, screen_y);
if (qiyuan.libUE4)
{
ImGui::TextColored(ImColor(0, 255, 0,225), " libUE4.so: 0x%lX", qiyuan.libUE4);
} else {
ImGui::TextColored(ImColor(255, 0, 0,225), " libUE4.so: 0x%lX", qiyuan.libUE4);
}*/
static atomic<bool> isRecording(false); // 全局变量
static float lp_beg, lp_end;
lp_beg += (lp_end - lp_beg) * (0.2f * speed); // 动画速率


if (button("开启录制", ImVec2(-1,75), 20.0f, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), ImVec4(0.25f, 0.25f, 0.25f, 1.0f))) {
lp_end = 400;
isTimerRunning = true;
timerStartTime = static_cast<int>(ImGui::GetTime());  // 记录计时器开始时的时间
isRecording.store(true);
录屏 = true;
thread([](int 录屏时长) {
// 非阻塞式开始录制
string beijingTime = getBeijingTimeString(); // 获取北京时间字符串
string fileName = "/sdcard/录制_" + beijingTime + ".mp4";
string command = "screenrecord --time-limit " + to_string(录屏时长) + " " + fileName + " &";
system(command.c_str());
isRecording.store(false);
}, 录屏时长).detach();   
}

// 这里添加计时结束的逻辑
if (isTimerRunning && (ImGui::GetTime() - timerStartTime >= 录屏时长)) {
lp_end = 0; // 设置结束位置
isTimerRunning = false; // 停止计时
system("pkill -l SIGINT screenrecord"); // 停止录制
//录屏 = false; // 结束录屏
}
if (button("停止录制", ImVec2(-1,75), 20.0f, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), ImVec4(0.25f, 0.25f, 0.25f, 1.0f))) {
    lp_end = 0;
    system("pkill -l SIGINT screenrecord");
    isRecording.store(false);
    录屏 = false;
    isTimerRunning = false;
}
SliderFloat("自定义录制秒数", &录屏时长, 1, 120, "%1.f");
ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing();

if (button("链接数据", ImVec2(-1,75), 20.0f, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), ImVec4(0.25f, 0.25f, 0.25f, 1.0f))) {
GetBase();
}


}


/*void 主页_2() {
title("录制区域");
Line(365);

static atomic<bool> isRecording(false); // 全局变量
static float lp_beg, lp_end;
lp_beg += (lp_end - lp_beg) * (0.2f * speed); // 动画速率

SliderFloat("自定义录制秒数", &录屏时长, 1, 120, "%1.f");
ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing();

Line(365);
ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX() - lp_beg, ImGui::GetCursorPosY())); //设置光标位置
if (button("开始录制", ImVec2(365, 70))) {
lp_end = 400;
isTimerRunning = true;
timerStartTime = static_cast<int>(ImGui::GetTime());  // 记录计时器开始时的时间
isRecording.store(true);
录屏 = true;
thread([](int 录屏时长) {
// 非阻塞式开始录制
string beijingTime = getBeijingTimeString(); // 获取北京时间字符串
string fileName = "/sdcard/录制_" + beijingTime + ".mp4";
string command = "screenrecord --time-limit " + to_string(录屏时长) + " " + fileName + " &";
system(command.c_str());
isRecording.store(false);
}, 录屏时长).detach();   
}

// 这里添加计时结束的逻辑
if (isTimerRunning && (ImGui::GetTime() - timerStartTime >= 录屏时长)) {
lp_end = 0; // 设置结束位置
isTimerRunning = false; // 停止计时
system("pkill -l SIGINT screenrecord"); // 停止录制
//录屏 = false; // 结束录屏
}

ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX() + 400 - lp_beg, ImGui::GetCursorPosY() - 82.5f)); //设置光标位置
if (button("停止录制", ImVec2(365, 70))) {
    lp_end = 0;
    system("pkill -l SIGINT screenrecord");
    isRecording.store(false);
    录屏 = false;
    isTimerRunning = false;
}
Line(365);

if (button("无限时长", ImVec2(365, 70))) {
录屏时长 = 9999;
}
Line(365);
if (button("链接数据", ImVec2(365, 70))) {
GetBase();
}


}*/




//ImGui::SameLine();
//ImGui::Checkbox("绘制手持", &DrawIo[10]);

void 绘制_1() {
title("主绘制");
ImGui::Checkbox("方框", &DrawIo[1]);
ImGui::SameLine();
ImGui::Checkbox("骨骼", &DrawIo[3]);
ImGui::SameLine();
ImGui::Checkbox("射线", &DrawIo[2]);
ImGui::SameLine();
ImGui::Checkbox("距离", &DrawIo[5]);

//ImGui::SameLine();
ImGui::Checkbox("血量", &DrawIo[6]);
ImGui::SameLine();
ImGui::Checkbox("雷达", &DrawIo[7]);
ImGui::SameLine();
ImGui::Checkbox("背敌", &DrawIo[8]);
ImGui::SameLine();
ImGui::Checkbox("忽机", &DrawIo[17]);




ImGui::Checkbox("忽地", &DrawIo[32]);
ImGui::SameLine();
ImGui::Checkbox("手持", &DrawIo[10]);
ImGui::SameLine();
ImGui::Checkbox("载具", &物资[0]);
ImGui::SameLine();
ImGui::Checkbox("手雷", &DrawIo[14]);
ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal, 2.0f);
SliderFloat ("雷达X", &NumIo[1], 10, 3200, "%1.f");
SliderFloat ("雷达Y", &NumIo[2], 10, 1440, "%1.f");
SliderFloat ("雷达大小", &NumIo[19], 10, 300, "%1.f");

/*ImGui::SameLine();
ImGui::Checkbox("绘制盒子", &DrawIo[18]);
ImGui::SameLine();
ImGui::Checkbox("绘制类名", &DrawIo[15]);


ImGui::Checkbox("绘制载具", &物资[0]);
ImGui::SameLine();
ImGui::Checkbox("绘制金插", &DrawIo[19]);
ImGui::SameLine();
ImGui::Checkbox("绘信号枪", &DrawIo[16]);*/
}

/*void 绘制_2() {
title("绘图样式");
vector<string> 人数样式 = {"灵动鸟", "不动鸟", "没有鸟"};
vector<string> 绘图样式 = {"彩色", "联赛", "圆环"};
vector<string> 雷达样式 = {"血量", "距离", "队伍"};
whiteqiyuan(人数样式, draw_style[0], 0, 120.0f);
whiteqiyuan(绘图样式, draw_style[1], 0, 120.0f);
whiteqiyuan(雷达样式, draw_style[2], 0, 120.0f);
// whiteqiyuan(雷达样式, NumIo[20], 0, 120.0f);
}

void 绘制_3() {
title("灵动鸟信息");
vector<string> 灵动岛左边文字 = {"左-头甲", "左-品质", "左-动作", "待投稿"};
vector<string> 灵动岛右边文字 = {"右-头甲", "右-品质", "右-动作", "待投稿"};
whiteqiyuan(灵动岛左边文字, draw_style[6], 0, 140.5f, 75);
whiteqiyuan(灵动岛右边文字, draw_style[7], 0, 140.5f, 75);
}

void 绘制_4() {
title("参数调节");
SliderFloat ("雷达X", &NumIo[1], 10, 3200, "%1.f");
SliderFloat ("雷达Y", &NumIo[2], 10, 1440, "%1.f");
SliderFloat ("雷达大小", &NumIo[19], 10, 300, "%1.f");
}*/





void 自瞄_1() {
title("自瞄设置");
ImGui::Checkbox("自瞄开关", &DrawIo[20]);
ImGui::SameLine();
ImGui::Checkbox("触摸位置", &DrawIo[21]);


//ImGui::SameLine();
//Checkbox("准心射线", &DrawIo[44]);
//ImGui::SameLine();
ImGui::Checkbox("持续锁定", &DrawIo[30]);
ImGui::SameLine();
ImGui::Checkbox("动态范围", &DrawIo[25]);

ImGui::Checkbox("忽略人机", &DrawIo[31]);
            if (ImGui::Combo("触发条件", &style_bw, "开火自瞄\0开镜自瞄\0开火开镜\0")) {
                switch (style_bw) 
                {
                    case 0:NumIo[0] = 0.0; 
                        break;
                    case 1:NumIo[0] = 1.0; 
                         break;
                    case 2:NumIo[0] = 2.0; 
                        break;                          
                }          
            }
            
            if (ImGui::Combo("瞄准优先", &style_zx, "准心优先\0距离优先\0")) {
                switch (style_zx) 
                {
                    case 0:NumIo[21] = 0.0; 
                        break;
                    case 1:NumIo[21] = 1.0; 
                         break;
                }          
            }
                        if (ImGui::Combo("自瞄部位", &style_idx, "自动\0头部\0胸部\0臀部\0")) {
                switch (style_idx) 
                {
                    case 0:NumIo[8] = 0.0; 
                        break;
                    case 1:NumIo[8] = 1.0; 
                         break;
                    case 2:NumIo[8] = 2.0; 
                        break;
                    case 3:NumIo[8] = 3.0; 
                        break;
                }          
            }                    
            if (ImGui::Combo("充电位置", &style_cd, "充电口右\0充电口左\0")) {
                switch (style_cd) 
                {
                    case 0:NumIo[10] = 0.0; 
                        break;
                    case 1:NumIo[10] = 1.0; 
                         break;
                }          
            }
/*Checkbox("腰射", &DrawIo[31]);
ImGui::SameLine();
Checkbox("大小", &DrawIo[31]);
ImGui::SameLine();
Checkbox("平滑", &DrawIo[31]);

Checkbox("瞄准速度", &DrawIo[31]);
ImGui::SameLine();
Checkbox("子弹速度", &DrawIo[31]);

Checkbox("触摸", &DrawIo[31]);
ImGui::SameLine();
Checkbox("预判", &DrawIo[31]);
ImGui::SameLine();
Checkbox("压枪", &DrawIo[31]);*/
//ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal, 2.0f);
// SliderFloat ("自瞄距离", &NumIo[19], 10.0f, 500.0f, "%1.f");

}




/*第二个自瞄窗口展示
void 自瞄_1() {
    title("自瞄设置");
    ImGui::Checkbox("自瞄开关", &DrawIo[20]);
    ImGui::SameLine();
    Checkbox("传统", &DrawIo[30]);
    ImGui::SameLine();
    Checkbox("视角", &DrawIo[30]);
    ImGui::SameLine();
    ImGui::Checkbox("触摸位置", &DrawIo[21]);

    ImGui::Checkbox("持续锁定", &DrawIo[30]);
    ImGui::SameLine();
    ImGui::Checkbox("动态范围", &DrawIo[25]);
    ImGui::SameLine();
    ImGui::Checkbox("忽略人机", &DrawIo[31]);

    vector<string> 自瞄方式 = {"开火", "开镜", "火|镜", "任何"};
    whiteqiyuan(自瞄方式, NumIo[0], 0, 140.5f);

    ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal, 2.0f);

    // 创建一个折叠式区域
    ImGui::SetNextItemOpen(true, ImGuiCond_FirstUseEver);
    if (ImGui::CollapsingHeader("自瞄参数设置", ImGuiTreeNodeFlags_DefaultOpen)) {
        ImGui::BeginGroup();
        ImGui::Text("自瞄范围");
        ImGui::SameLine(150);
        SliderFloat("##自瞄范围", &NumIo[3], 10.0f, 800.0f, "%1.f");

        ImGui::Text("平滑力度");
        ImGui::SameLine(150);
        SliderFloat("##平滑力度", &NumIo[9], 1.0f, 50.0f, "%0.1f");

        ImGui::Text("瞄准速度");
        ImGui::SameLine(150);
        SliderFloat("##瞄准速度", &NumIo[4], 1.0f, 30.0f, "%0.1f");

        ImGui::Text("子弹速度");
        ImGui::SameLine(150);
        SliderFloat("##子弹速度", &NumIo[11], 100.0f, 1000.0f, "%1.f");

        ImGui::Text("压枪力度");
        ImGui::SameLine(150);
        SliderFloat("##压枪力度", &NumIo[14], 0.1f, 8.0f, "%.1f", 5);

        ImGui::Text("预判调节");
        ImGui::SameLine(150);
        SliderFloat("##预判调节", &NumIo[22], 0.1f, 5.0f, "%.1f", 5);

        ImGui::EndGroup();
    }
}
*/
void 调节_1() {
    // 函数实现
    title("调节设置");
    SliderFloat ("自瞄范围", &NumIo[3], 10.0f, 800.0f, "%1.f");
    SliderFloat ("平滑力度", &NumIo[9], 1.0f, 50.0f, "%0.1f");
    SliderFloat ("瞄准速度", &NumIo[4], 1.0f, 30.0f, "%0.1f");
    SliderFloat ("触摸范围", &NumIo[7], 50.01f, 400.0f, "%0.2f");
  //  SliderFloat ("子弹速度", &NumIo[11], 100.0f, 1000.0f, "%1.f");
    SliderFloat ("压枪力度", &NumIo[14], 0.1f, 8.0f, "%.1f", 5);
    SliderFloat ("预判调节", &NumIo[22], 0.1f, 5.0f, "%.1f", 5);
    //SliderFloat ("自瞄距离", &NumIo[19], 10.0f, 500.0f, "%1.f");
}


void 设置_1() {
title("设置");
SliderFloat ("Gui刷新率(调成游戏帧率左右 不然绘制飘呀飘)", &NumIo[12], 60.0f, 120.0f, "%1.f", 5);
SliderFloat ("全局动画速率(60帧2.0倍 90帧1.5倍 120帧1.0倍)", &speed, 0.5f, 3.0f, "%0.2f", 5);
SliderFloat ("雷达缩放比例", &NumIo[16], 70, 150, "%1.f", 5);
//SliderFloat ("灵动岛透明度", &NumIo[23], 0, 255, "%1.f", 5);
ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal, 2.0f);
if (button("保存配置", ImVec2(ImGui::GetContentRegionAvail().x, 100), 20.0f, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), ImVec4(0.25f, 0.25f, 0.25f, 1.0f))) {
NumIoSave("LFM配置");
}
ImGui::Spacing();
if (button("注销并退出", ImVec2(ImGui::GetContentRegionAvail().x, 100), 20.0f, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), ImVec4(0.25f, 0.25f, 0.25f, 1.0f))) {
exit(0);
}


}

void 设置定时器(int 毫秒, std::function<void()> 回调) {
    std::thread([毫秒, 回调]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(毫秒));
        回调();
    }).detach();
}

void 灵动岛() {

// 灵动岛
float pxx = screen_x/2;
string play = to_string(qiyuan.PlayerCount);
string bot = to_string(qiyuan.BotCount);
if (isTimerRunning && (ImGui::GetTime() - timerStartTime > 录屏时长)) {
录屏 = false; // 结束录屏
}


if (录屏) {
灵动岛宽度.end = 80;
字体大小.end = 45;
字体位置.end = 120;
灵动岛高度x.end = 0;
if (录屏&&strstr(wz.Name, "BP_Grenade_Shoulei_C")) {
灵动岛宽度.end = 160;
字体大小.end = 45;
字体位置.end = 120;
灵动岛高度x.end = 60;
} else if (录屏&&strstr(wz.Name, "BP_Grenade_Burn_C") || 录屏&&strstr(wz.Name, "BP_Grenade_Burn_Sallete_C")) {
灵动岛宽度.end = 80;
字体大小.end = 45;
字体位置.end = 120;
灵动岛高度x.end = 60;
} else if (录屏&&strstr(wz.Name, "BP_Grenade_Shoulei_C") &&strstr(wz.Name, "BP_Grenade_Burn_C")) {
灵动岛宽度.end = 160;
字体大小.end = 45;
字体位置.end = 120;
灵动岛高度x.end = 60;
}
} else if (strstr(wz.Name, "BP_Grenade_Shoulei_C")) {
灵动岛宽度.end = 80;
字体大小.end = 0;
字体位置.end = 0;
灵动岛高度x.end = 60;
if (录屏&&strstr(wz.Name, "BP_Grenade_Shoulei_C")) {
灵动岛宽度.end = 160;
字体大小.end = 45;
字体位置.end = 120;
灵动岛高度x.end = 60;
} else if (录屏&&strstr(wz.Name, "BP_Grenade_Burn_C") || 录屏&&strstr(wz.Name, "BP_Grenade_Burn_Sallete_C")) {
灵动岛宽度.end = 80;
字体大小.end = 45;
字体位置.end = 120;
灵动岛高度x.end = 60;
} else if (录屏&&strstr(wz.Name, "BP_Grenade_Shoulei_C") &&strstr(wz.Name, "BP_Grenade_Burn_C")) {
灵动岛宽度.end = 160;
字体大小.end = 45;
字体位置.end = 120;
灵动岛高度x.end = 60;
}
} else if (strstr(wz.Name, "BP_Grenade_Burn_C") || strstr(wz.Name, "BP_Grenade_Burn_Sallete_C")) {
灵动岛宽度.end = 30;
字体大小.end = 0;
字体位置.end = 0;
灵动岛高度x.end = 60;
if (录屏&&strstr(wz.Name, "BP_Grenade_Shoulei_C")) {
灵动岛宽度.end = 160;
字体大小.end = 45;
字体位置.end = 120;
灵动岛高度x.end = 60;
} else if (录屏&&strstr(wz.Name, "BP_Grenade_Burn_C") || 录屏&&strstr(wz.Name, "BP_Grenade_Burn_Sallete_C")) {
灵动岛宽度.end = 80;
字体大小.end = 45;
字体位置.end = 120;
灵动岛高度x.end = 60;
} else if (录屏&&strstr(wz.Name, "BP_Grenade_Shoulei_C") &&strstr(wz.Name, "BP_Grenade_Burn_C")) {
灵动岛宽度.end = 160;
字体大小.end = 45;
字体位置.end = 120;
灵动岛高度x.end = 60;
}
} else if (strstr(wz.Name, "BP_Grenade_Shoulei_C") &&strstr(wz.Name, "BP_Grenade_Burn_C") || strstr(wz.Name, "BP_Grenade_Burn_Sallete_C")) {
灵动岛宽度.end = 0;
字体大小.end = 0;
字体位置.end = 0;
灵动岛高度x.end = 60;
if (录屏&&strstr(wz.Name, "BP_Grenade_Shoulei_C")) {
灵动岛宽度.end = 160;
字体大小.end = 45;
字体位置.end = 120;
灵动岛高度x.end = 60;
} else if (录屏&&strstr(wz.Name, "BP_Grenade_Burn_C") || 录屏&&strstr(wz.Name, "BP_Grenade_Burn_Sallete_C")) {
灵动岛宽度.end = 80;
字体大小.end = 45;
字体位置.end = 120;
灵动岛高度x.end = 60;
} else if (录屏&&strstr(wz.Name, "BP_Grenade_Shoulei_C") &&strstr(wz.Name, "BP_Grenade_Burn_C")) {
灵动岛宽度.end = 160;
字体大小.end = 45;
字体位置.end = 120;
灵动岛高度x.end = 60;
}
} else {
灵动岛宽度.end = 0;
字体大小.end = 0;
字体位置.end = 0;
灵动岛高度x.end = 0;
}

if (位置x.beg > 3.5&&位置x.beg < 6.5) {
灵动岛高度s.end = -10;
灵动岛高度x.end = -10;
灵动岛宽度.end = -16;
if (录屏&&(位置x.beg > 4&&位置x.beg < 5)) {
灵动岛宽度.end = 80;
字体大小.end = 45;
字体位置.end = 120;
灵动岛高度s.end = -8;
灵动岛高度x.end = -8;
} else if (开关&&strstr(wz.Name, "BP_Grenade_Shoulei_C")) {
灵动岛宽度.end = 70;
灵动岛高度x.end = 50;
}
} else {
灵动岛高度s.end = 0;
}



float 灵动岛 = 灵动岛宽度.beg;
float 灵动岛s = 灵动岛高度s.beg;
float 灵动岛x = 灵动岛高度x.beg;
int 透明度 = NumIo[23];
int 透明调节;
if (120 > 透明度) {
透明调节 = 120;
if (透明度 < 10) {
透明调节 = 0;
}
} else {
透明调节 = 透明度;
if (透明度 < 10) {
透明调节 = 0;
}
}

ImGui::GetForegroundDrawList()->AddRectFilled(
        {pxx - (95) - 灵动岛 , 35 - 灵动岛s },
        {pxx + (95) + 灵动岛 , 110 + 灵动岛x },
        ImColor(235, 235, 235, 透明度),
        200, 0); // 白色背景
ImGui::GetForegroundDrawList()->AddRect(
        {pxx - (95) - 灵动岛 , 35 - 灵动岛s },
        {pxx + (95) + 灵动岛 , 110 + 灵动岛x },
        ImColor(255, 255, 255, 透明度),
        200, 0, 3.3f); // 白色边框
        
string guistr = "手雷";
string ytzw = "附近有投掷物";
if (录屏) {
if (strstr(wz.Name, "BP_Grenade_Shoulei_C") || strstr(wz.Name, "BP_Grenade_Shoulei_C")) {
auto textSize_left = ImGui::GetFont()->CalcTextSizeA((45), FLT_MAX, -1, guistr.c_str(), NULL, NULL);
ImGui::GetForegroundDrawList()->AddText(NULL, (45), ImVec2(pxx - (textSize_left.x / 2) - (110) - 80, (74) - (textSize_left.y / 2)), ImColor(30,144,255,透明调节), guistr.c_str());

auto textSize_right = ImGui::GetFont()->CalcTextSizeA((45), FLT_MAX, -1, guistr.c_str(), NULL, NULL);
ImGui::GetForegroundDrawList()->AddText(NULL, (45), ImVec2(pxx - (textSize_right.x / 2) + (110) + 80, (74) - (textSize_right.y / 2)), ImColor(30,144,255,透明调节), guistr.c_str());
}
} else {
if (strstr(wz.Name, "BP_Grenade_Shoulei_C")) {
auto textSize_left = ImGui::GetFont()->CalcTextSizeA((45), FLT_MAX, -1, guistr.c_str(), NULL, NULL);
ImGui::GetForegroundDrawList()->AddText(NULL, (45), ImVec2(pxx - (textSize_left.x / 2) - (110), (74) - (textSize_left.y / 2)), ImColor(30,144,255,透明调节), guistr.c_str());

auto textSize_right = ImGui::GetFont()->CalcTextSizeA((45), FLT_MAX, -1, guistr.c_str(), NULL, NULL);
ImGui::GetForegroundDrawList()->AddText(NULL, (45), ImVec2(pxx - (textSize_right.x / 2) + (110), (74) - (textSize_right.y / 2)), ImColor(30,144,255,透明调节), guistr.c_str());
}
}

if (人数位置.beg > 10) {
// 玩家
auto textSize_play = ImGui::GetFont()->CalcTextSizeA((50), FLT_MAX, -1, play.c_str(), NULL, NULL);
ImGui::GetForegroundDrawList()->AddText(NULL, (50), ImVec2(pxx - (textSize_play.x / 2) - (45), (73.5f) - (textSize_play.y / 2)), ImColor(255, 0, 0, 255), play.c_str());
// 人机
auto textSize_bot = ImGui::GetFont()->CalcTextSizeA((50), FLT_MAX, -1, bot.c_str(), NULL, NULL);
ImGui::GetForegroundDrawList()->AddText(NULL, (50), ImVec2(pxx - (textSize_bot.x / 2) + (45), (73.5f) - (textSize_bot.y / 2)), ImColor(0, 255, 0, 240), bot.c_str());
} else {
string bynh = "点我关闭";
auto textSize_bynh = ImGui::GetFont()->CalcTextSizeA((logo.beg), FLT_MAX, -1, bynh.c_str(), NULL, NULL);
ImGui::GetForegroundDrawList()->AddText(NULL, 38, ImVec2(pxx - (textSize_bynh.x / 2) - 58.0, (75) - (textSize_bynh.y / 2) - 22), ImColor(30,144,255), bynh.c_str());
}

if (录屏) {
// 获取当前秒数，并计算已过的时间
int currentTime = static_cast<int>(ImGui::GetTime());
int elapsedSeconds = currentTime - timerStartTime;
// 绘制圆圈的颜色逻辑
ImColor circleColor;
if (elapsedSeconds < 0) {
circleColor = ImColor(255,255,255);  // 白色
} else if (elapsedSeconds % 2 == 1) {
circleColor = ImColor(255, 0, 0, 255);      // 红色
}  else {
circleColor = ImColor(255,255,255,255);  // 默认颜色
}
// 调整圆圈的视觉效果，匹配图片中的小球样式
float circleRadius = 15.0f ;  // 根据图片调整半径
ImVec2 circlePos = ImVec2(pxx - (字体位置.beg) - 5, (72) );  // 圆圈位置
// 增加动态边框绘制，边框颜色与圆球颜色相同
float borderThickness = 4.0f;  // 边框厚度为 4.0f
ImGui::GetForegroundDrawList()->AddCircle(circlePos, circleRadius + borderThickness + 4.0f, circleColor, 100, borderThickness);  // 边框颜色动态变化
// 左边圆圈填充颜色
ImGui::GetForegroundDrawList()->AddCircleFilled(circlePos, circleRadius, circleColor, 100);
// 右边计时器绘制
string timerText = std::to_string(elapsedSeconds);  // 将已过秒数转换为字符串
auto textSize_timer = ImGui::GetFont()->CalcTextSizeA((字体大小.beg) , FLT_MAX, -1, timerText.c_str(), NULL, NULL);
// 计算计时器文本的X坐标，使其居中
float textPosX = pxx + (字体位置.beg - 5)  - textSize_timer.x / 2.0f;
ImGui::GetForegroundDrawList()->AddText(NULL, (字体大小.beg + 5) ,
ImVec2(textPosX, (74)  - (textSize_timer.y / 2)),
ImColor(30,144,255), timerText.c_str());
}


if (strstr(wz.Name, "BP_Grenade_Shoulei_C") || strstr(wz.Name, "BP_Grenade_Burn_C") || strstr(wz.Name, "BP_Grenade_Burn_Sallete_C")) {
auto textSize_bynh = ImGui::GetFont()->CalcTextSizeA((logo.beg), FLT_MAX, -1, ytzw.c_str(), NULL, NULL);
    // 调整文字位置，向下移动20个像素点
    ImGui::GetForegroundDrawList()->AddText(NULL, 40 , ImVec2(pxx - (textSize_bynh.x / 2) - 88 , (120) - (textSize_bynh.y / 2)), ImColor(30,144,255,透明调节), ytzw.c_str());
}


 //灵动岛点击事件
ImVec2 childWindowSize = ImVec2(650, 250); // 设置子悬浮窗的初始大小
ImVec2 childWindowPos = ImVec2(screen_x/2-(325), 0); // 子悬浮窗的初始位置
ImGui::SetNextWindowPos(childWindowPos);//悬浮窗位置
ImGui::SetNextWindowSize(childWindowSize);//悬浮窗大小
// 临时设置子悬浮窗的背景颜色为透明
ImVec4 transparentColor = ImVec4(0.0f, 0.0f, 0.0f, 0.0f); // 完全透明
ImGui::PushStyleColor(ImGuiCol_WindowBg, transparentColor);
ImGui::PushStyleColor(ImGuiCol_Border, transparentColor);
ImGui::PushStyleColor(ImGuiCol_BorderShadow, transparentColor);
ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f)); // 设置按钮背景色为透明
ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 0.0f, 0.0f, 0.0f)); // 设置按钮悬停时背景色为透明
ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.0f, 0.0f, 0.0f, 0.0f)); // 设置按钮按下时背景色为透明
ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 100); // 设置圆角大小
ImGui::Begin("灵动岛点击事件", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

ImGui::SetCursorPos(ImVec2((325) - (100) - 灵动岛 , (33)));
if(ImGui::Button("", ImVec2((200), (80)))){
开关 = !开关;
}
ImGui::SetCursorPos(ImVec2((325) - (100) + 灵动岛 , (33)));
if(ImGui::Button(" ", ImVec2((200), (80)))){
开关 = !开关;
}

ImGui::End();
ImGui::PopStyleVar(); //恢复圆角
ImGui::PopStyleColor(6); //释放颜色
 




}

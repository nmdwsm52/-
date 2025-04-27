

// 绘制物资
void 物资函数(const function<string(const string&)> itemFunction, int drawIoIndex, int maxDistance, int fontSize = 30) {
string name;
name = itemFunction(wz.Name);
if (物资[drawIoIndex] &&!name.empty()) {
if (wz.Distance < maxDistance) {
name += "[";
name += to_string((int)wz.Distance);
name += "米]";
auto textSize = ImGui::CalcTextSize(name.c_str(), 0, fontSize);
ImGui::GetForegroundDrawList()->AddText(NULL, fontSize, { wz.ScreenPos.x - (textSize.x / 2), wz.ScreenPos.y }, 物资颜色[drawIoIndex], name.c_str());
}
}
}


// 绘制头像
void DrawLogo(ImTextureID ID,ImVec2 center, float size) {
ImGui::SetCursorPos({size*2, size*2});
ImGui::GetWindowDrawList()->AddImageRounded(ID,ImVec2(center.x - size, center.y - size), ImVec2(center.x + size, center.y + size), ImVec2(0, 0), ImVec2(1, 1), ImColor(255, 255, 255, 255), 999);
}

// 计算骨骼
FTransform getBone(uintptr_t addr) {
FTransform transform;
driver->read(addr, reinterpret_cast<void*>(&transform), 4 * 11);
return transform;
}

// 计算距离
void GetDistance(Vec3 Object, Vec3 Self, float *Distance) {
float DistanceX = pow(Object.x - Self.x, 2);
float DistanceY = pow(Object.y - Self.y, 2);
float DistanceZ = pow(Object.z - Self.z, 2);
*Distance = sqrt(DistanceX + DistanceY + DistanceZ) * 0.01f;
}

// 计算雷达的旋转量
Vec2 rotateCoord(float angle, float objRadar_x, float objRadar_y) {
Vec2 radarCoordinate;
float s = sin(angle * PI / 180);
float c = cos(angle * PI / 180);
radarCoordinate.x = objRadar_x * c + objRadar_y * s;
radarCoordinate.y = -objRadar_x * s + objRadar_y * c;
return radarCoordinate;
}

// 物资类名
void GetClassName(char *Name, long int address, int id) {
long int ClassNameadd = driver->read<uintptr_t>(address + (id / 0x4000) * 0x8);
long int ClassNameaddr = driver->read<uintptr_t>(ClassNameadd + (id % 0x4000) * 0x8);
driver->read(ClassNameaddr + 0xC, Name, 64);
}
char* 获取类名(long addr) {
int id = driver->read<int>(addr + 0x18);
long ye = driver->read<uintptr_t>(qiyuan.Gname + (id / 0x4000) * 8);
long xu = driver->read<uintptr_t>(ye + (id % 0x4000) * 8);
static char Item[256];
driver->read(xu + 0xc, Item, sizeof(Item));
return Item;
}


// 玩家名字
void getUTF8(UTF8 * buf, long namepy) {
UTF16 buf16[16] = { 0 };
driver->read(namepy, buf16, 28);
UTF16 *pTempUTF16 = buf16;
UTF8 *pTempUTF8 = buf;
UTF8 *pUTF8End = pTempUTF8 + 32;
while (pTempUTF16 < pTempUTF16 + 28) {
if (*pTempUTF16 <= 0x007F && pTempUTF8 + 1 < pUTF8End) {
*pTempUTF8++ = (UTF8) * pTempUTF16;
} else if (*pTempUTF16 >= 0x0080 && *pTempUTF16 <= 0x07FF && pTempUTF8 + 2 < pUTF8End) {
*pTempUTF8++ = (*pTempUTF16 >> 6) | 0xC0;
*pTempUTF8++ = (*pTempUTF16 & 0x3F) | 0x80;
} else if (*pTempUTF16 >= 0x0800 && *pTempUTF16 <= 0xFFFF && pTempUTF8 + 3 < pUTF8End) {
*pTempUTF8++ = (*pTempUTF16 >> 12) | 0xE0;
*pTempUTF8++ = ((*pTempUTF16 >> 6) & 0x3F) | 0x80;
*pTempUTF8++ = (*pTempUTF16 & 0x3F) | 0x80;
} else {
break;
}
pTempUTF16++;
}
}

// WorldToScreen系类函数，将游戏三维坐标转化为屏幕二维坐标
Vec2 WorldIsScreen(Vec3 obj, float ViewW) {
float x = screen_x/2 + (qiyuan.matrix[0] * obj.x + qiyuan.matrix[4] * obj.y + qiyuan.matrix[8] * obj.z + qiyuan.matrix[12]) / ViewW * screen_x/2;
float y = screen_y/2 - (qiyuan.matrix[1] * obj.x + qiyuan.matrix[5] * obj.y + qiyuan.matrix[9] * obj.z + qiyuan.matrix[13]) / ViewW * screen_y/2;
return Vec2(x, y);
}
Vec2 WorldToScreen(Vec3 obj, float a[16], float b) {
Vec2 bscreen;
float camear = qiyuan.matrix[3] * obj.x + qiyuan.matrix[7] * obj.y + qiyuan.matrix[11] * obj.z + qiyuan.matrix[15];
bscreen.x = screen_x/2 + (qiyuan.matrix[0] * obj.x + qiyuan.matrix[4] * obj.y + qiyuan.matrix[8] * obj.z + qiyuan.matrix[12]) / camear * screen_x/2;
bscreen.y = screen_y/2 - (qiyuan.matrix[1] * obj.x + qiyuan.matrix[5] * obj.y + qiyuan.matrix[9] * obj.z + qiyuan.matrix[13]) / camear * screen_y/2;
return bscreen;
}
void WorldToScreen(Vec2 *bscreen, float *camea, float *w, Vec3 obj) { 
float camear = qiyuan.matrix[3] * obj.x + qiyuan.matrix[7] * obj.y + qiyuan.matrix[11] * obj.z + qiyuan.matrix[15];
*camea = camear;
bscreen->x = screen_x/2 + (qiyuan.matrix[0] * obj.x + qiyuan.matrix[4] * obj.y + qiyuan.matrix[8] * obj.z + qiyuan.matrix[12]) / camear * screen_x/2;
bscreen->y = screen_y/2 - (qiyuan.matrix[1] * obj.x + qiyuan.matrix[5] * obj.y + qiyuan.matrix[9] * obj.z + qiyuan.matrix[13]) / camear * screen_y/2;
float bscreenZ = screen_y/2 - (qiyuan.matrix[1] * obj.x + qiyuan.matrix[5] * obj.y + qiyuan.matrix[9] * (obj.z + 165) + qiyuan.matrix[13]) / camear * screen_y/2;
float bscreenz = bscreen->y - bscreenZ;
*w = (bscreen->y - bscreenZ) / 2;
}


// 绘制骨骼函数
void DrawBone(ImVec2 start, ImVec2 end) {
if (!isnan(start.x) && !isnan(start.y) && !isnan(end.x) && !isnan(end.x)) {
double dx = start.x - end.x;
double dy = start.y - end.y;
if (sqrt(dx * dx + dy * dy) > 100)
return;
if (qiyuan.IsBot) {
ImGui::GetForegroundDrawList()->AddLine(start, end, 绘制颜色[8], 绘制粗细[5]);
} else {
ImGui::GetForegroundDrawList()->AddLine(start, end, 绘制颜色[7], 绘制粗细[6]);
}
}
}



// 载入游戏数据
int GetBase() {
if (draw_style[10] == 0) {
system("rm -rf /data/Mx1.0.1配置");
print:("请重新启动");
exit(1);

// const char* game_package_names[] = {"com.tencent.ig", "com.rekoo.pubgm", "com.pubg.krmobile", "com.vng.pubgmobile"};
// size_t game_count = sizeof(game_package_names) / sizeof(game_package_names[0]);
// for(size_t i = 0; i < game_count; i++) {
// qiyuan.pid = driver->GetPid((char*)game_package_names[i]);
// if (qiyuan.pid > 0 && qiyuan.pid < 100000) {
// driver->init_pid(qiyuan.pid);
// break;
// }
// }
// if (qiyuan.pid <= 0) {
// printf("\nPUBG未启动\n");
// return 0;
// }
// qiyuan.libUE4 = driver->getModuleBase("libUE4.so");
// memset(qiyuan.matrix, 0, 16);
// qiyuan.Matrixs = driver->read<uintptr_t>(driver->read<uintptr_t>(qiyuan.libUE4 + 0xce93a70) + 0xc0) + 0x9d0;



} else if (draw_style[10] == 1) {

qiyuan.pid = driver->GetPid("com.tencent.tmgp.pubgmhd"); //获取pid
if (qiyuan.pid > 0 && qiyuan.pid < 100000) //判断防止获取错误
driver->init_pid(qiyuan.pid);
else {
printf("\n和平精英未启动\n");
return 0;
}
qiyuan.libUE4 = driver->getModuleBase("libUE4.so"); //获取模块头即ue4地址
memset(qiyuan.matrix, 0, 16); //初始化矩阵数组
qiyuan.Matrixs = driver->read<uintptr_t>(driver->read<uintptr_t>(qiyuan.libUE4 + 0x1122C960) + 0x20) + 0x270; //修改这里

}

return 1;
}


FILE *numSave = nullptr;

// 保存参数
void NumIoSave(const char *name) {
if (numSave == nullptr) {
string SaveFile = "/data";
SaveFile += "/";
SaveFile += name;
numSave = fopen(SaveFile.c_str(), "wb+");
}
fseek(numSave, 0, SEEK_SET);
fwrite(DrawIo, sizeof(bool) * 50, 1, numSave);
fwrite(NumIo, sizeof(float) * 50, 1, numSave);
fwrite(draw_style, sizeof(float) * 20, 1, numSave);
// fwrite(style_idx, sizeof(float) * 20, 1, numSave);
// fwrite(style_zt, sizeof(float) * 20, 1, numSave);
// fwrite(style_cd, sizeof(float) * 20, 1, numSave);
// fwrite(style_bw, sizeof(float) * 20, 1, numSave);
fwrite(&绘制粗细, sizeof(float) * 16, 1, numSave);
fwrite(&绘制颜色, sizeof(ImColor) * 16, 1, numSave);
fwrite(&物资, sizeof(bool) * 50, 1, numSave);
fwrite(&物资颜色, sizeof(ImColor) * 50, 1, numSave);
fflush(numSave);
fsync(fileno(numSave));
}

// 读取保存的参数[Mx1.0.1配置]
void NumIoLoad(const char *name) {
if (numSave == nullptr) {
string SaveFile = "/data";
SaveFile += "/";
SaveFile += name;
numSave = fopen(SaveFile.c_str(), "rb+");
}
if (numSave != nullptr) {
fseek(numSave, 0, SEEK_SET);
fread(DrawIo, sizeof(bool) * 50, 1, numSave);
fread(NumIo, sizeof(float) * 50, 1, numSave);
fread(draw_style, sizeof(float) * 20, 1, numSave);
fread(&绘制粗细, sizeof(float) * 16, 1, numSave);
fread(&绘制颜色, sizeof(ImColor) * 16, 1, numSave);
fread(&物资, sizeof(bool) * 50, 1, numSave);
fread(&物资颜色, sizeof(ImColor) * 50, 1, numSave);
} else {
CleanData();
}
}


// 音量键隐藏
void 音量键隐藏() {
DIR *dir = opendir("/dev/input/");
if (dir == NULL) {
printf("未找到输入设备\n");
exit(1);
}
struct dirent *ptr = NULL;
int count = 0;
while ((ptr = readdir(dir))!= NULL) {
if (strstr(ptr->d_name, "event"))
count++;
}

if (count == 0) return;

int *fdArray = (int *)malloc(count * sizeof(int));

for (int i = 0; i < count; i++) {
char temp[128];
sprintf(temp, "/dev/input/event%d", i);
fdArray[i] = open(temp, O_RDWR | O_NONBLOCK);
}

struct input_event ev;

while (1) {
for (int i = 0; i < count; i++) {
memset(&ev, 0, sizeof(ev));
read(fdArray[i], &ev, sizeof(ev));
if (ev.type == EV_KEY && ev.code == KEY_VOLUMEDOWN && ev.value == 1) {
开关 = false;
}
if (ev.type == EV_KEY && ev.code == KEY_VOLUMEUP && ev.value == 1) {
开关 = true;
}

usleep(1350);
}
usleep(500);
}
usleep(1500);
}






// 血量绘制函数
void DrawHealth(Vec2 box, float w, float iHealth, uint32_t TeamID, char* name) {
float cornerRadius = 7.0f; 
float x = box.x;
float y = box.y;

float 差值;
// if (TeamID > 99) TeamID = TeamID/2;
if (TeamID > 9) 差值 = 3; else 差值 = 0;
char TeamText[50];
sprintf(TeamText, "%d.%s", TeamID, name); 
char Teamid[50];
sprintf(Teamid, "%d", TeamID); 

ImColor 联赛health = iHealth == 100.0f ? ImColor(255, 255, 255, 155) :
                   iHealth >= 75.0f ? ImColor(255, 255, 255, 255) :
                   iHealth >= 50.0f ? ImColor(255, 150, 150, 255) :
                   iHealth >= 25.0f ? ImColor(255, 80, 80, 255) :
                                      ImColor(255, 0, 0, 255);
ImColor 圆环health = (iHealth <= 100.0f && iHealth >= 85.0f) ? ImColor(0, 255, 0, 255) :
              (iHealth <= 85.0f && iHealth >= 70.0f) ? ImColor(190, 255, 0, 255) :
              (iHealth <= 70.0f && iHealth >= 55.0f) ? ImColor(230, 255, 0, 255) :
              (iHealth <= 55.0f && iHealth >= 40.0f) ? ImColor(255, 170, 0, 255) :
              (iHealth <= 40.0f && iHealth >= 25.0f) ? ImColor(255, 130, 0, 255) :
              (iHealth <= 25.0f && iHealth >= 10.0f) ? ImColor(255, 90, 0, 255) :
              (iHealth <= 10.0f && iHealth >= 0.0f) ? ImColor(255, 0, 0, 255) :
              ImColor(0, 0, 0, 255); // 默认颜色，以防 iHealth 超出预期范围

// 彩色绘图
if (DrawIo[6] && draw_style[1] == 0) {
ImGui::GetBackgroundDrawList()->AddRect({x - 76, y - 15}, {x + 76, y - 3}, ImColor(0,0,0,255), cornerRadius);
if (iHealth > 0)
ImGui::GetBackgroundDrawList()->AddRectFilled({x - 75, y - 15}, {x - 75 + (iHealth * 150 / 100), y - 6},ImColor(arr[TeamID % length]), cornerRadius);
auto textSize_信息 = ImGui::GetFont()->CalcTextSizeA(27, FLT_MAX, -1, TeamText, NULL, NULL);
DrawTf.绘制字体描边(27, x - (textSize_信息.x / 2), box.y - 25 - (textSize_信息.y / 2), ImVec4{255,255,255,255}, TeamText);//队伍ID


// 联赛绘图
} else if (DrawIo[6] && draw_style[1] == 1) {
auto textSize_id = ImGui::GetFont()->CalcTextSizeA(23, FLT_MAX, -1, Teamid, NULL, NULL);
ImGui::GetBackgroundDrawList()->AddRectFilled({x - 75 , y - (43 )}, {(x-60-差值) + textSize_id.x , y - (17 )}, ImColor(arr[TeamID % length]), 0); //队伍

tm = 123;
ImGui::GetBackgroundDrawList()->AddRectFilled({(x-60-差值) + textSize_id.x , y - (43 )}, {x + 75 , y - (17 )}, ImColor(arr[TeamID % length]), 0); //名字
tm = 255;
ImVec2 triangle[3] = {ImVec2(x - 7, y - 11), ImVec2(x, y - 2), ImVec2(x + 7, y - 11)};
ImGui::GetBackgroundDrawList()->AddTriangleFilled(triangle[0], triangle[1], triangle[2], ImColor(arr[TeamID % length])
);

if (iHealth > 0)
ImGui::GetBackgroundDrawList()->AddRectFilled({x - (75 ), y - (17 )}, {x - (75 ) + (iHealth * 150 / 100), y - 11}, 联赛health, 0);
else 
ImGui::GetBackgroundDrawList()->AddRectFilled({x - (75 ), y - (17 )}, {x + (75 ), y - 11}, ImColor(255, 0, 0, 255), 0);

DrawTf.绘制字体描边(23, x - 67.5f - 差值, y - 29 - (textSize_id.y / 2), ImVec4{255,255,255,255}, Teamid);//队伍ID
auto textSize_信息 = ImGui::GetFont()->CalcTextSizeA(23, FLT_MAX, -1, name, NULL, NULL);
DrawTf.绘制字体描边(23, (x-53) + textSize_id.x, y - 29 - (textSize_信息.y / 2), ImVec4{255,255,255,255}, name);//名字

// 圆环绘图
} else if (DrawIo[6] && draw_style[1] == 2) {
string 血量 = to_string((int)iHealth);
auto textSize1 = ImGui::GetFont()->CalcTextSizeA((25), FLT_MAX, -1, 血量.c_str(), NULL, NULL); 

if (iHealth > 0) {
圆环(ImVec2(x, y - 45), 25.0f, 圆环health, 10.0f, 100, iHealth);
ImGui::GetForegroundDrawList()->AddText(NULL, (25), ImVec2(x - (textSize1.x / 2), y - 45 - (textSize1.y / 2)), 圆环health, 血量.c_str());
} else {
圆环(ImVec2(x, y - 45), 25.0f, 圆环health, 10.0f, 100, 100);
}


}
}












void 自瞄图片() {
ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 65); //圆角
ImGui::SetNextWindowSize(ImVec2(130, 130)); //窗口大小
ImGui::Begin("AimbotWindow", NULL, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize);
ImVec2 image_size = ImVec2(110, 110);
ImVec2 window_pos = ImGui::GetWindowPos(); 
ImVec2 window_center = ImVec2(window_pos.x + ImGui::GetWindowWidth() / 2, window_pos.y + ImGui::GetWindowHeight() / 2);

static float rotation_angle = 0.0f;
float cos_a = cosf(rotation_angle * 3.14159265358979323846 / 180.0f);
float sin_a = sinf(rotation_angle * 3.14159265358979323846 / 180.0f);
ImVec2 ul = ImVec2(-image_size.x * 0.5f, -image_size.y * 0.5f);
ImVec2 ur = ImVec2(image_size.x * 0.5f, -image_size.y * 0.5f);
ImVec2 br = ImVec2(image_size.x * 0.5f, image_size.y * 0.5f);
ImVec2 bl = ImVec2(-image_size.x * 0.5f, image_size.y * 0.5f);
ImVec2 rotated_ul = ImVec2(ul.x * cos_a - ul.y * sin_a, ul.x * sin_a + ul.y * cos_a) + window_center;
ImVec2 rotated_ur = ImVec2(ur.x * cos_a - ur.y * sin_a, ur.x * sin_a + ur.y * cos_a) + window_center;
ImVec2 rotated_br = ImVec2(br.x * cos_a - br.y * sin_a, br.x * sin_a + br.y * cos_a) + window_center;
ImVec2 rotated_bl = ImVec2(bl.x * cos_a - bl.y * sin_a, bl.x * sin_a + bl.y * cos_a) + window_center;
if (DrawIo[20]) 
rotation_angle -= 2.0f * speed;
ImGui::GetWindowDrawList()->AddImageQuad(aim_png, rotated_ul, rotated_ur, rotated_br, rotated_bl);
static bool Active = false;
if (state(Active)) {
DrawIo[20] = !DrawIo[20];
}

ImGui::End();
ImGui::PopStyleVar();//恢复圆角
}



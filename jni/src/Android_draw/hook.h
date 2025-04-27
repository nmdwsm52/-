AimCount = 0;
qiyuan.PlayerCount = 0;
qiyuan.BotCount = 0;

// 游戏数据
qiyuan.Gname = driver->read<uintptr_t>(qiyuan.libUE4 + 0x10BE9988);
qiyuan.Uworld = driver->read<uintptr_t>(qiyuan.libUE4 + 0x11259798);
qiyuan.Uleve = driver->read<uintptr_t>(qiyuan.Uworld + 0x90);
qiyuan.Arrayaddr = driver->read<uintptr_t>(qiyuan.Uleve + 0xA0);
qiyuan.Count = driver->read<int>(qiyuan.Uleve + 0xA8);

// 自身一系类
qiyuan.Oneself = driver->read<uintptr_t>(driver->read<uintptr_t>(driver->read<uintptr_t>(driver->read<uintptr_t>(driver->read<uintptr_t>(qiyuan.libUE4 + 0x11259798) + 0x98) + 0x88) + 0x30) + 0x3150);
qiyuan.MyTeam = driver->read<int>(qiyuan.Oneself + 0xa98);//队伍阵营
qiyuan.MyWeapon = driver->read<int>(driver->read<uintptr_t>(driver->read<uintptr_t>(qiyuan.Oneself + 0x2eb0)+ 0x668)+ 0xba0); //手持
driver->read(driver->read<uintptr_t>(qiyuan.Oneself + 0x278) + 0x1F0, &qiyuan.MyPos, 12);
driver->read(qiyuan.Matrixs, &qiyuan.matrix, 16 * 4);

// 自身fov，开火，开镜，雷达旋转值
qiyuan.Fov = driver->read<float>(driver->read<uintptr_t>(driver->read<uintptr_t>(qiyuan.Oneself + 0x5138) + 0x5e8) + 0x610);
qiyuan.IsFiring = driver->read<int>(qiyuan.Oneself + 0x2150);
qiyuan.IsAiming = driver->read<int>(qiyuan.Oneself + 0x15a8);
qiyuan.angle = driver->read<float>(qiyuan.Oneself + 0x4e08);//+ 0x8e0)+ 0x5ec); 




for (int i = 0; i < qiyuan.Count; i ++) {
qiyuan.Objaddr = driver->read<uintptr_t>(qiyuan.Arrayaddr + 8 * i);

if (qiyuan.Oneself == qiyuan.Objaddr || qiyuan.Objaddr <= 0x10000000 || qiyuan.Objaddr % 4 != 0 || qiyuan.Objaddr >= 0x10000000000)
continue;

uintptr_t object = driver->read<uintptr_t>(qiyuan.Objaddr + 0x278);
if (object <= 0xffff || object == 0 || object <= 0x10000000 || object % 4 != 0 || object >= 0x10000000000)
continue;

if (driver->read<float>(qiyuan.Objaddr + 0x3230) != 479.5) {
GetClassName(wz.Name, qiyuan.Gname, driver->read<int>(qiyuan.Objaddr + 0x18));
driver->read(object + 0x1F0, &wz.Pos, 12);
GetDistance(wz.Pos, qiyuan.MyPos, &wz.Distance);
WorldToScreen(&wz.ScreenPos, &wz.camera, &wz.w, wz.Pos);
} else {




//人机不绘制
if(DrawIo[17])
{
  // 是否为人机
if (qiyuan.IsBot == 1)
{
 continue;
}
}

// 死亡不绘制
int State = driver->read<int>(qiyuan.Objaddr + 0x1478);
if (State == 1048576 || State == 1048592 || State == 1048577 || State == 0)
continue;

// 自身队伍不绘制
qiyuan.TeamID = driver->read<int>(qiyuan.Objaddr + 0xa98);
if (qiyuan.TeamID == qiyuan.MyTeam || qiyuan.TeamID < 1)
continue;

// 血量百分比大于百分之100不绘制
qiyuan.Health = (driver->read<float>(qiyuan.Objaddr + 0xe70) / driver->read<float>(qiyuan.Objaddr + 0xe78)) * 100;
if (qiyuan.Health > 100)
continue;


driver->read(object + 0x1F0, &qiyuan.Pos, 12); //读取坐标
GetDistance(qiyuan.Pos, qiyuan.MyPos, &qiyuan.Distance); //用坐标计算出距离
WorldToScreen(&qiyuan.ScreenPos, &qiyuan.camera, &qiyuan.w, qiyuan.Pos); 

// 人机判断
if (driver->read<int>(qiyuan.Objaddr +  0xab4)) qiyuan.IsBot = 1; else qiyuan.IsBot = 0;
// 统计人数
if (qiyuan.IsBot) qiyuan.BotCount++; else qiyuan.PlayerCount++;


// 超出屏幕不绘制
if (qiyuan.w < 0 || qiyuan.w > screen_x)
continue;


if (driver->read<uintptr_t>(qiyuan.Objaddr + 0x1000)) {
driver->read(driver->read<uintptr_t>(qiyuan.Objaddr + 0xf30) + 0x1330, &qiyuan.Predict, sizeof(qiyuan.Predict)); // 载具向量
} else {
driver->read(object + 0xf74, &qiyuan.Predict, sizeof(qiyuan.Predict)); // 敌人向量
}

// 头甲包
long int rw = driver->read<uintptr_t>(driver->read<uintptr_t>(driver->read<uintptr_t>(qiyuan.Objaddr + 0x348) + 0x30) + 0x388);
qiyuan.drb = driver->read<int>(rw + 0x1C4);
qiyuan.drt = driver->read<int>(rw + 0x1FC);
qiyuan.drj = driver->read<int>(rw + 0x234);
 
// 动作，手持，当前子弹，最大子弹
qiyuan.敌方动作 = driver->read<int>(driver->read<uint64_t>(qiyuan.Objaddr + 0x1478));//状态
//qiyuan.Act = driver->read<uintptr_t>(qiyuan.Objaddr + 0x13e8);
qiyuan.weapon = driver->read<int>(driver->read<uintptr_t>(driver->read<uintptr_t>(qiyuan.Objaddr + 0x2eb0)+ 0x668)+ 0xba0); //手持
qiyuan.dqzd = driver->read<int>(driver->read<uintptr_t>(driver->read<uintptr_t>(qiyuan.Objaddr + 0x2eb0) + 0x668) + 0x18b0);
qiyuan.zdmax = driver->read<int>(driver->read<uintptr_t>(driver->read<uintptr_t>(qiyuan.Objaddr + 0x2eb0) + 0x668) + 0x18b4);
qiyuan.scwq = driver->read<uintptr_t>(driver->read<uintptr_t>(driver->read<uintptr_t>(qiyuan.Objaddr + 0x2eb0)+ 0x668)+ 0xba0); //敌人手持


// 骨骼
qiyuan.Mesh = driver->read<uintptr_t>(qiyuan.Objaddr + 0x5e0);
qiyuan.Human = qiyuan.Mesh + 0x1e0;
qiyuan.Bone = driver->read<uintptr_t>(qiyuan.Mesh + 0x7b8) + 0x30;
int BoneCount = driver->read<uint64_t>(qiyuan.Mesh + 0x7b8+8);//修改这里
// 名字   
getUTF8(qiyuan.PlayerName, driver->read<uintptr_t>(qiyuan.Objaddr + 0xa18));//列阵偏移


int p = (BoneCount == 68) ? 33 : 32;
int o = (BoneCount == 68) ? 34 : 33;
int a = (BoneCount == 68) ? 13 : 63;
int b = (BoneCount == 68) ? 35 : 62;
int c = (BoneCount == 68) ? 55 : 52;
int d = (BoneCount == 68) ? 59 : 56;
int e = (BoneCount == 68) ? 56 : 53;
int f = (BoneCount == 68) ? 60 : 57;
int g = (BoneCount == 68) ? 57 : 54;
int h = (BoneCount == 68) ? 61 : 58;


FTransform meshtrans = getBone(qiyuan.Human);
FMatrix c2wMatrix = TransformToMatrix(meshtrans);
FTransform headtrans = getBone(qiyuan.Bone + 5 * 48);
FMatrix boneMatrix = TransformToMatrix(headtrans);
qiyuan.Head.Pos = MarixToVector(MatrixMulti(boneMatrix, c2wMatrix));
qiyuan.Head.Pos.z += 7; /* 脖子长度 */
qiyuan.Head.ScreenPos = WorldToScreen(qiyuan.Head.Pos, qiyuan.matrix, qiyuan.camera);

/* 胸部 */
FTransform chesttrans = getBone(qiyuan.Bone + 4 * 48);
FMatrix boneMatrix1 = TransformToMatrix(chesttrans);
qiyuan.Chest.Pos = MarixToVector(MatrixMulti(boneMatrix1, c2wMatrix));
qiyuan.Chest.ScreenPos = WorldToScreen(qiyuan.Chest.Pos, qiyuan.matrix, qiyuan.camera);

/* 盆骨 */
FTransform pelvistrans = getBone(qiyuan.Bone + 0 * 48);
FMatrix boneMatrix2 = TransformToMatrix(pelvistrans);
qiyuan.Pelvis.Pos = MarixToVector(MatrixMulti(boneMatrix2, c2wMatrix));
qiyuan.Pelvis.ScreenPos = WorldToScreen(qiyuan.Pelvis.Pos, qiyuan.matrix, qiyuan.camera);

/* 左肩膀 */
FTransform lshtrans = getBone(qiyuan.Bone + 11 * 48);
FMatrix boneMatrix3 = TransformToMatrix(lshtrans);
qiyuan.Left_Shoulder.Pos = MarixToVector(MatrixMulti(boneMatrix3, c2wMatrix));
qiyuan.Left_Shoulder.ScreenPos = WorldToScreen(qiyuan.Left_Shoulder.Pos, qiyuan.matrix, qiyuan.camera);

/* 右肩膀 */
FTransform rshtrans = getBone(qiyuan.Bone + p * 48);
FMatrix boneMatrix4 = TransformToMatrix(rshtrans);
qiyuan.Right_Shoulder.Pos = MarixToVector(MatrixMulti(boneMatrix4, c2wMatrix));
qiyuan.Right_Shoulder.ScreenPos = WorldToScreen(qiyuan.Right_Shoulder.Pos, qiyuan.matrix, qiyuan.camera);

/* 左手肘 */
FTransform lelbtrans = getBone(qiyuan.Bone + 12 * 48);
FMatrix boneMatrix5 = TransformToMatrix(lelbtrans);
qiyuan.Left_Elbow.Pos = MarixToVector(MatrixMulti(boneMatrix5, c2wMatrix));
qiyuan.Left_Elbow.ScreenPos = WorldToScreen(qiyuan.Left_Elbow.Pos, qiyuan.matrix, qiyuan.camera);

/* 右手肘 */
FTransform relbtrans = getBone(qiyuan.Bone + o * 48);
FMatrix boneMatrix6 = TransformToMatrix(relbtrans);
qiyuan.Right_Elbow.Pos = MarixToVector(MatrixMulti(boneMatrix6, c2wMatrix));
qiyuan.Right_Elbow.ScreenPos = WorldToScreen(qiyuan.Right_Elbow.Pos, qiyuan.matrix, qiyuan.camera);

/* 左手腕 */
FTransform lwtrans = getBone(qiyuan.Bone + a * 48);
FMatrix boneMatrix7 = TransformToMatrix(lwtrans);
qiyuan.Left_Wrist.Pos = MarixToVector(MatrixMulti(boneMatrix7, c2wMatrix));
qiyuan.Left_Wrist.ScreenPos = WorldToScreen(qiyuan.Left_Wrist.Pos, qiyuan.matrix, qiyuan.camera);

/* 右手腕 */
FTransform rwtrans = getBone(qiyuan.Bone + b * 48);
FMatrix boneMatrix8 = TransformToMatrix(rwtrans);
qiyuan.Right_Wrist.Pos = MarixToVector(MatrixMulti(boneMatrix8, c2wMatrix));
qiyuan.Right_Wrist.ScreenPos = WorldToScreen(qiyuan.Right_Wrist.Pos, qiyuan.matrix, qiyuan.camera);

/* 左大腿 */
FTransform Llshtrans = getBone(qiyuan.Bone + c * 48);
FMatrix boneMatrix9 = TransformToMatrix(Llshtrans);
qiyuan.Left_Thigh.Pos = MarixToVector(MatrixMulti(boneMatrix9, c2wMatrix));
qiyuan.Left_Thigh.ScreenPos = WorldToScreen(qiyuan.Left_Thigh.Pos, qiyuan.matrix, qiyuan.camera);

/* 右大腿 */
FTransform Lrshtrans = getBone(qiyuan.Bone + d * 48);
FMatrix boneMatrix10 = TransformToMatrix(Lrshtrans);
qiyuan.Right_Thigh.Pos = MarixToVector(MatrixMulti(boneMatrix10, c2wMatrix));
qiyuan.Right_Thigh.ScreenPos = WorldToScreen(qiyuan.Right_Thigh.Pos, qiyuan.matrix, qiyuan.camera);

/* 左膝盖 */
FTransform Llelbtrans = getBone(qiyuan.Bone + e * 48);
FMatrix boneMatrix11 = TransformToMatrix(Llelbtrans);
qiyuan.Left_Knee.Pos = MarixToVector(MatrixMulti(boneMatrix11, c2wMatrix));
qiyuan.Left_Knee.ScreenPos = WorldToScreen(qiyuan.Left_Knee.Pos, qiyuan.matrix, qiyuan.camera);

/* 右膝盖 */
FTransform Lrelbtrans = getBone(qiyuan.Bone + f * 48);
FMatrix boneMatrix12 = TransformToMatrix(Lrelbtrans);
qiyuan.Right_Knee.Pos = MarixToVector(MatrixMulti(boneMatrix12, c2wMatrix));
qiyuan.Right_Knee.ScreenPos = WorldToScreen(qiyuan.Right_Knee.Pos, qiyuan.matrix, qiyuan.camera);

/* 左脚腕 */
FTransform Llwtrans = getBone(qiyuan.Bone + g * 48);
FMatrix boneMatrix13 = TransformToMatrix(Llwtrans);
qiyuan.Left_Ankle.Pos = MarixToVector(MatrixMulti(boneMatrix13, c2wMatrix));
qiyuan.Left_Ankle.ScreenPos = WorldToScreen(qiyuan.Left_Ankle.Pos, qiyuan.matrix, qiyuan.camera);

/* 右脚腕 */
FTransform Lrwtrans = getBone(qiyuan.Bone + h * 48);
FMatrix boneMatrix14 = TransformToMatrix(Lrwtrans);
qiyuan.Right_Ankle.Pos = MarixToVector(MatrixMulti(boneMatrix14, c2wMatrix));
qiyuan.Right_Ankle.ScreenPos = WorldToScreen(qiyuan.Right_Ankle.Pos, qiyuan.matrix, qiyuan.camera);
		






if (DrawIo[20] && ((DrawIo[31] && !qiyuan.IsBot) || !DrawIo[31]) && ((DrawIo[32] && qiyuan.Health > 0) || !DrawIo[32])) {
strcpy(Aim[AimCount].Name, qiyuan.PlayerName);
Aim[AimCount].WodDistance = qiyuan.Distance;
Aim[AimCount].AimMovement = qiyuan.Predict;
if (NumIo[8] == 1.0){
Aim[AimCount].ObjAim = qiyuan.Head.Pos;
Aim[AimCount].ScreenDistance = sqrt(pow(screen_x / 2 - qiyuan.Head.ScreenPos.x, 2) + pow(screen_y / 2 - qiyuan.Head.ScreenPos.y, 2));
} else if (NumIo[8] == 2.0){
Aim[AimCount].ObjAim = qiyuan.Chest.Pos;
Aim[AimCount].ScreenDistance = sqrt(pow(screen_x / 2 - qiyuan.Chest.ScreenPos.x, 2) + pow(screen_y / 2 - qiyuan.Chest.ScreenPos.y, 2));
} else if (NumIo[8] == 3.0){
Aim[AimCount].ObjAim = qiyuan.Pelvis.Pos; 
Aim[AimCount].ScreenDistance = sqrt(pow(screen_x / 2 - qiyuan.Pelvis.ScreenPos.x, 2) + pow(screen_y / 2 - qiyuan.Pelvis.ScreenPos.y, 2));
} else {
Aim[AimCount].ObjAim = qiyuan.Head.Pos;
Aim[AimCount].ScreenDistance = sqrt(pow(screen_x / 2 - qiyuan.Head.ScreenPos.x, 2) + pow(screen_y / 2 - qiyuan.Head.ScreenPos.y, 2));
}  
AimCount++;
}




float top, right, left, bottom, top1; 


// 背敌
	/*if (DrawIo[8]) {//敌背
			
			
			if(draw_style[2]==0){
                std::string ssd;
                

ssd += "  队伍";
ssd += to_string((int)qiyuan.TeamID);
                ssd += "  \n  [";
ssd += std::to_string((int) qiyuan.Distance); 
ssd += "米]";

                auto textSize = ImGui::CalcTextSize(ssd.c_str(), 0, 28);
				tm = 120.f/255.f;
                if (qiyuan.Head.ScreenPos.x + qiyuan.w < 0) {
                    Draw->AddCircleFilled({40, qiyuan.Head.ScreenPos.y}, 50, ImColor(arr[qiyuan.TeamID%length]));    
                    Draw->AddText(NULL, 28, {40 - (textSize.x / 2), qiyuan.Head.ScreenPos.y - (textSize.y / 2)}, ImColor(255, 255, 255), ssd.c_str());                                      
                } else if (qiyuan.w > 0 && qiyuan.Head.ScreenPos.x > screen_x) {
                    Draw->AddCircleFilled({screen_x - 40, qiyuan.Head.ScreenPos.y}, 50, ImColor(arr[qiyuan.TeamID%length]));                       
                    Draw->AddText(NULL, 28, {screen_x - 40 - (textSize.x / 2), qiyuan.Head.ScreenPos.y - (textSize.y / 2)}, ImColor(255, 255, 255), ssd.c_str());                                      
                } else if (qiyuan.w > 0 && qiyuan.Head.ScreenPos.y + qiyuan.w < 0) {               
                    Draw->AddCircleFilled({qiyuan.Head.ScreenPos.x, 40}, 50, ImColor(arr[qiyuan.TeamID%length]));     
                    Draw->AddText(NULL, 28, {qiyuan.Head.ScreenPos.x - (textSize.x / 2), 40 - (textSize.y / 2)}, ImColor(255, 255, 255), ssd.c_str());                                      
                } else if (qiyuan.w < 0) {
                    Draw->AddCircleFilled({screen_x - qiyuan.Head.ScreenPos.x, screen_y - 40}, 50, ImColor(arr[qiyuan.TeamID%length]));   
                    Draw->AddText(NULL, 28, {screen_x - qiyuan.Head.ScreenPos.x - (textSize.x / 2), screen_y - 40 - (textSize.y / 2)}, ImColor(255, 255, 255), ssd.c_str());                                      
                }
                }
		
              if(draw_style[2]==1){  
				tm = 120.f/255.f;
				float cameras = qiyuan.matrix[3] * qiyuan.Pos.x + qiyuan.matrix[7] * qiyuan.Pos.y + qiyuan.matrix[11] * qiyuan.Pos.z + qiyuan.matrix[15]; 
				if (!qiyuan.IsBot) {				
					OffScreen(qiyuan.ScreenPos, cameras, ImColor(arr[qiyuan.TeamID%length]), NumIo[3] + 20 + qiyuan.Distance * 0.3);
				} else {
					OffScreen(qiyuan.ScreenPos, cameras, ImColor(255, 255, 255, 255), NumIo[3] + 20 + qiyuan.Distance * 0.3);
				}
				
				}
            }*/

if (DrawIo[8]) {
tm = 120.f/255.f;
float cameras = qiyuan.matrix[3] * qiyuan.Pos.x + qiyuan.matrix[7] * qiyuan.Pos.y + qiyuan.matrix[11] * qiyuan.Pos.z + qiyuan.matrix[15]; 
if (!qiyuan.IsBot) {
OffScreen(qiyuan.ScreenPos, cameras, ImColor(arr[qiyuan.TeamID%length]), NumIo[3] + 20 + qiyuan.Distance * 0.3);
} else {
OffScreen(qiyuan.ScreenPos, cameras, ImColor(255, 255, 255, 255), NumIo[3] + 20 + qiyuan.Distance * 0.3);
}
}

left  = qiyuan.Head.ScreenPos.x - qiyuan.w * 0.6;
right = qiyuan.Head.ScreenPos.x + qiyuan.w * 0.6;

if (!qiyuan.Head.Pos.x) {
top1 = qiyuan.Pelvis.ScreenPos.y - qiyuan.Chest.ScreenPos.y;
} else {
top1 = qiyuan.Pelvis.ScreenPos.y - qiyuan.Head.ScreenPos.y;
}

top  = qiyuan.Pelvis.ScreenPos.y - top1 - qiyuan.w / 5;

if (qiyuan.Left_Ankle.ScreenPos.y < qiyuan.Right_Ankle.ScreenPos.y) {
bottom = qiyuan.Right_Ankle.ScreenPos.y + qiyuan.w / 10;
} else {
bottom = qiyuan.Left_Ankle.ScreenPos.y  + qiyuan.w / 10;
}

//方框
if (DrawIo[1]) {
if (qiyuan.IsBot) {//定义人机方框
Draw->AddRect({left, top}, {right, bottom}, 绘制颜色[2], 0, 0, 绘制粗细[2]); 
Draw->AddRectFilled({left, top}, {right, bottom}, 绘制颜色[4]); 
} else {  
Draw->AddRect({left, top}, {right, bottom}, 绘制颜色[1], 0, 0, 绘制粗细[1]);
Draw->AddRectFilled({left, top}, {right, bottom}, 绘制颜色[3]); 
if (qiyuan.敌方动作 == 65552 or qiyuan.敌方动作 == 69648 or qiyuan.敌方动作 == 69664 or qiyuan.敌方动作 == 65600 or qiyuan.敌方动作 == 65681 or qiyuan.敌方动作 == 65569 or qiyuan.敌方动作 == 65601 or qiyuan.敌方动作 == 65553 or qiyuan.敌方动作 == 69649) {
               Draw->AddRectFilled({left, top}, {right, bottom}, ImColor(255,0,0,50));//背景颜色     填充色
Draw->AddRect({left, top}, {right, bottom}, ImColor(255, 0, 0, 255)); // 红色边框，不填充颜色
// 绘制7秒倒数文本
    static float countdown = 7.0f;
    static std::chrono::steady_clock::time_point lastTime = std::chrono::steady_clock::now();
    auto currentTime = std::chrono::steady_clock::now();
    std::chrono::duration<float> elapsedSeconds = currentTime - lastTime;

    if (elapsedSeconds.count() >= 1.0f) {
        countdown -= elapsedSeconds.count();
        lastTime = currentTime;
    }
        if (countdown > 0) {
        char buffer[32];
        sprintf(buffer, "%.1f", countdown);
        Draw->AddText({left + 10, top + 10}, ImColor(255, 255, 255, 255), buffer); // 白色文本
    } else {
        countdown = 7.0f; // 重置倒计时
    }
               } else if (qiyuan.scwq == 102008 or qiyuan.scwq == 102007 or qiyuan.scwq == 102005 or qiyuan.scwq == 102004 or qiyuan.scwq == 102003 or qiyuan.scwq == 102002 or qiyuan.scwq == 102001 or qiyuan.scwq == 104100 or qiyuan.scwq == 104005 or qiyuan.scwq == 104004 or qiyuan.scwq == 104003 or qiyuan.scwq == 104002 or qiyuan.scwq == 104001)
    {
        //color = ImColor(0, 0, 255, 255); // 深蓝【冲锋枪】       
        Draw->AddRectFilled({left, top}, {right, bottom}, ImColor(0,0,255,50));
       
    }  else if (qiyuan.scwq == 105010 or qiyuan.scwq == 101005 or qiyuan.scwq == 102105 or qiyuan.scwq == 101013 or qiyuan.scwq == 103003 or qiyuan.scwq == 103013 or qiyuan.scwq == 103012 or qiyuan.scwq == 203032 or qiyuan.scwq == 103906)
    {
        
       // color = ImColor(135, 206, 235, 255); // 天蓝【空投枪】
       Draw->AddRectFilled({left, top}, {right, bottom}, ImColor(135,206,235,50));
    } else if (qiyuan.scwq == 9825003 or qiyuan.scwq == 602043 or qiyuan.scwq == 602003)
    {
          
      //  color = ImColor(255, 165, 0, 255); // 橙【燃烧瓶】
      Draw->AddRectFilled({left, top}, {right, bottom}, ImColor(255,165,0,50));
    } else if (qiyuan.scwq == 602042 or qiyuan.scwq == 602002)
    {
            
       // color = ImColor(0, 128, 0, 255); // 深绿【烟雾弹】
       Draw->AddRectFilled({left, top}, {right, bottom}, ImColor(0,128,0,50));
    } else if (qiyuan.敌方动作 == 524288 or qiyuan.敌方动作 == 131072 or qiyuan.敌方动作 == 524303 or qiyuan.敌方动作 == 524304 or qiyuan.敌方动作 == 524289)
    {
          
              
        //color = ImColor(0, 0, 0, 255); // 黑【倒地】
        Draw->AddRectFilled({left, top}, {right, bottom}, ImColor(0,0,0,50));
    }  else if (qiyuan.敌方动作 == 12583952 or qiyuan.敌方动作 == 12582928 or qiyuan.敌方动作 == 4194320 or qiyuan.敌方动作 == 2097168)
    {
                   
              
        //color = ImColor(0, 0, 0, 255); // 黄【开车】
        Draw->AddRectFilled({left, top}, {right, bottom}, ImColor(255,255,0,40));
    }
}
}



// 射线
if (DrawIo[2]) {
float 射线_y;
if (qiyuan.IsBot) {
if (draw_style[0] == 0 || draw_style[0] == 1) 射线_y = 73; else if (draw_style[0] == 2) 射线_y = screen_y*0.135f;
Draw->AddLine({screen_x / 2 , 射线_y}, {qiyuan.Head.ScreenPos.x, qiyuan.Head.ScreenPos.y}, 绘制颜色[6], 绘制粗细[4]);  
} else {
Draw->AddLine({screen_x / 2 , 射线_y}, {qiyuan.Head.ScreenPos.x, qiyuan.Head.ScreenPos.y}, 绘制颜色[5], 绘制粗细[3]);  
}
}

// 骨骼
if (DrawIo[3]) {
Draw->AddCircle({qiyuan.Head.ScreenPos.x, qiyuan.Head.ScreenPos.y}, qiyuan.w / 6, 绘制颜色[7], 100);
DrawBone({qiyuan.Head.ScreenPos.x, qiyuan.Head.ScreenPos.y}, {qiyuan.Chest.ScreenPos.x, qiyuan.Chest.ScreenPos.y});
DrawBone({qiyuan.Chest.ScreenPos.x, qiyuan.Chest.ScreenPos.y}, {qiyuan.Pelvis.ScreenPos.x, qiyuan.Pelvis.ScreenPos.y});
DrawBone({qiyuan.Chest.ScreenPos.x, qiyuan.Chest.ScreenPos.y}, {qiyuan.Left_Shoulder.ScreenPos.x, qiyuan.Left_Shoulder.ScreenPos.y});
DrawBone({qiyuan.Chest.ScreenPos.x, qiyuan.Chest.ScreenPos.y}, {qiyuan.Right_Shoulder.ScreenPos.x, qiyuan.Right_Shoulder.ScreenPos.y});
DrawBone({qiyuan.Left_Shoulder.ScreenPos.x, qiyuan.Left_Shoulder.ScreenPos.y}, {qiyuan.Left_Elbow.ScreenPos.x, qiyuan.Left_Elbow.ScreenPos.y});
DrawBone({qiyuan.Right_Shoulder.ScreenPos.x, qiyuan.Right_Shoulder.ScreenPos.y},{qiyuan.Right_Elbow.ScreenPos.x, qiyuan.Right_Elbow.ScreenPos.y});
DrawBone({qiyuan.Left_Elbow.ScreenPos.x, qiyuan.Left_Elbow.ScreenPos.y}, {qiyuan.Left_Wrist.ScreenPos.x, qiyuan.Left_Wrist.ScreenPos.y});
DrawBone({qiyuan.Right_Elbow.ScreenPos.x, qiyuan.Right_Elbow.ScreenPos.y}, {qiyuan.Right_Wrist.ScreenPos.x, qiyuan.Right_Wrist.ScreenPos.y});
DrawBone({qiyuan.Pelvis.ScreenPos.x, qiyuan.Pelvis.ScreenPos.y}, {qiyuan.Left_Thigh.ScreenPos.x, qiyuan.Left_Thigh.ScreenPos.y});
DrawBone({qiyuan.Pelvis.ScreenPos.x, qiyuan.Pelvis.ScreenPos.y}, {qiyuan.Right_Thigh.ScreenPos.x, qiyuan.Right_Thigh.ScreenPos.y});
DrawBone({qiyuan.Left_Thigh.ScreenPos.x, qiyuan.Left_Thigh.ScreenPos.y}, {qiyuan.Left_Knee.ScreenPos.x, qiyuan.Left_Knee.ScreenPos.y});
DrawBone({qiyuan.Right_Thigh.ScreenPos.x, qiyuan.Right_Thigh.ScreenPos.y}, {qiyuan.Right_Knee.ScreenPos.x, qiyuan.Right_Knee.ScreenPos.y});
DrawBone({qiyuan.Left_Knee.ScreenPos.x, qiyuan.Left_Knee.ScreenPos.y}, {qiyuan.Left_Ankle.ScreenPos.x, qiyuan.Left_Ankle.ScreenPos.y});
DrawBone({qiyuan.Right_Knee.ScreenPos.x, qiyuan.Right_Knee.ScreenPos.y}, {qiyuan.Right_Ankle.ScreenPos.x, qiyuan.Right_Ankle.ScreenPos.y});
}

if(DrawIo[19]){
//绘制头部骨骼节点
Draw->AddCircleFilled({qiyuan.Head.ScreenPos.x, qiyuan.Head.ScreenPos.y}, qiyuan.w / 15, 绘制颜色[7], 100);
// 绘制左肩骨骼点
Draw->AddCircleFilled({qiyuan.Left_Shoulder.ScreenPos.x, qiyuan.Left_Shoulder.ScreenPos.y}, qiyuan.w / 15, 绘制颜色[7], 100);

// 绘制右肩骨骼点
Draw->AddCircleFilled({qiyuan.Right_Shoulder.ScreenPos.x, qiyuan.Right_Shoulder.ScreenPos.y}, qiyuan.w / 15, 绘制颜色[7], 100);

// 绘制左肘骨骼点
Draw->AddCircleFilled({qiyuan.Left_Elbow.ScreenPos.x, qiyuan.Left_Elbow.ScreenPos.y}, qiyuan.w / 15, 绘制颜色[7], 100);

// 绘制右肘骨骼点
Draw->AddCircleFilled({qiyuan.Right_Elbow.ScreenPos.x, qiyuan.Right_Elbow.ScreenPos.y}, qiyuan.w / 15, 绘制颜色[7], 100);

// 绘制左腕骨骼点
Draw->AddCircleFilled({qiyuan.Left_Wrist.ScreenPos.x, qiyuan.Left_Wrist.ScreenPos.y}, qiyuan.w / 15, 绘制颜色[7], 100);

// 绘制右腕骨骼点
Draw->AddCircleFilled({qiyuan.Right_Wrist.ScreenPos.x, qiyuan.Right_Wrist.ScreenPos.y}, qiyuan.w / 15, 绘制颜色[7], 100);

// 绘制左大腿骨骼点
Draw->AddCircleFilled({qiyuan.Left_Thigh.ScreenPos.x, qiyuan.Left_Thigh.ScreenPos.y}, qiyuan.w / 15, 绘制颜色[7], 100);

// 绘制右大腿骨骼点
Draw->AddCircleFilled({qiyuan.Right_Thigh.ScreenPos.x, qiyuan.Right_Thigh.ScreenPos.y}, qiyuan.w / 15, 绘制颜色[7], 100);

// 绘制左膝盖骨骼点
Draw->AddCircleFilled({qiyuan.Left_Knee.ScreenPos.x, qiyuan.Left_Knee.ScreenPos.y}, qiyuan.w / 15, 绘制颜色[7], 100);

// 绘制右膝盖骨骼点
Draw->AddCircleFilled({qiyuan.Right_Knee.ScreenPos.x, qiyuan.Right_Knee.ScreenPos.y}, qiyuan.w / 15, 绘制颜色[7], 100);

// 绘制左脚踝骨骼点
Draw->AddCircleFilled({qiyuan.Left_Ankle.ScreenPos.x, qiyuan.Left_Ankle.ScreenPos.y}, qiyuan.w / 15, 绘制颜色[7], 100);

// 绘制右脚踝骨骼点
Draw->AddCircleFilled({qiyuan.Right_Ankle.ScreenPos.x, qiyuan.Right_Ankle.ScreenPos.y}, qiyuan.w / 15, 绘制颜色[7], 100);
}


// 血量&名字
if (DrawIo[6]) {
if (!qiyuan.IsBot) {
DrawHealth({qiyuan.Head.ScreenPos.x, top }, qiyuan.w * 2, qiyuan.Health, qiyuan.TeamID, qiyuan.PlayerName);
} else {
DrawHealth({qiyuan.Head.ScreenPos.x, top }, qiyuan.w * 2, qiyuan.Health, qiyuan.TeamID, "人机");
}
}



// // 手持
// 武器id = GetWeapon(qiyuan.Weapon);
// if (DrawIo[10]) {
// string s;
// s += to_string((int)qiyuan.dqzd);
// s += "/";
// s += to_string((int)qiyuan.zdmax);
// auto textSize = ImGui::GetFont()->CalcTextSizeA(25, FLT_MAX, -1, s.c_str(), NULL, NULL); 
// ImGui::GetForegroundDrawList()->AddText(NULL, 25.f, { qiyuan.Head.ScreenPos.x - (textSize.x / 2), top - 45 - (textSize.y / 2) }, ImColor(255,255,255,255), s.c_str());
// /*
// float png_y = (draw_style[1] == 2) ? 45 : 0;
// // ImGui::GetForegroundDrawList()->AddImage(weapon[武器id/10], {qiyuan.Head.ScreenPos.x - 60, top - 80 - png_y}, {qiyuan.Head.ScreenPos.x + 60, top - 40 - png_y});*/
// }

// 距离
if (DrawIo[5]) {
string 距离 = to_string((int) qiyuan.Distance);
距离 += " m";
auto textSize_距离 = ImGui::GetFont()->CalcTextSizeA((25), FLT_MAX, -1, 距离.c_str(), NULL, NULL);
DrawTf.绘制字体描边(25, qiyuan.Pelvis.ScreenPos.x - textSize_距离.x/2, bottom + 15, ImVec4{1.0f, 1.0f, 1.0f, 1.0f},  距离.c_str());
}
// int png_y;
// char *武器id;
int  武器id;
武器id = GetWeapon(qiyuan.weapon);
if (DrawIo[10])
{
//加载枪械图片();
  string s;
  s += GetHol(qiyuan.scwq);
  s += " ";
  s += to_string((int)qiyuan.dqzd);
  s += "/";
  s += to_string((int)qiyuan.zdmax);
  auto textSize = ImGui::GetFont()->CalcTextSizeA(25, FLT_MAX, -1, s.c_str(), NULL, NULL); 
  ImGui::GetForegroundDrawList()->AddText(NULL, 25.f, { qiyuan.Head.ScreenPos.x - (textSize.x / 2), top - 45 - (textSize.y / 2) }, ImColor(255,255,255,255), s.c_str());
 // PlayerId = qiyuan.scwq;
//绘制手持(ID[PlayerId],qiyuan.Head.ScreenPos.x- -75, top - 90);
//float png_y = (DrawIo[10] == true) ? 45 : 0;
//ImGui::GetForegroundDrawList()->AddImage(weapon[武器id/10], {qiyuan.Head.ScreenPos.x - 60, top - 80 - png_y}, {qiyuan.Head.ScreenPos.x + 60, top - 40 - png_y});
}
float aa;
float bb;
int Health;
int Distance;
// if (draw_style[66] == 0) {
if (DrawIo[7] && qiyuan.TotalUp) {
// Vec2 Radar = {(qiyuan.MyPos.x - qiyuan.Pos.x) / NumIo[16], (qiyuan.MyPos.y - qiyuan.Pos.y) / NumIo[16]}; // 不旋转的雷达
float radius = qiyuan.Distance/NumIo[16];
Vec2 Radar = rotateCoord(qiyuan.angle, (qiyuan.MyPos.x - qiyuan.Pos.x) / (qiyuan.Distance / radius), (qiyuan.MyPos.y -qiyuan.Pos.y) / (qiyuan.Distance / radius)); // 旋转的雷达
string ld;
string ai;
// if (NumIo[1] + Radar.x >= NumIo[1] - 100 && NumIo[1] + Radar.x <= NumIo[1] + 100 && NumIo[2] + Radar.y >= NumIo[2] - 100 && NumIo[2] + Radar.y <= NumIo[2] + 100) {

ImColor color;
if (qiyuan.IsBot == 1) {
color = ImColor(255, 255, 255);//假人背景色白色
if (draw_style[2] == 0) {
ai += to_string((int) qiyuan.Health);//显示血量假人
} else if (draw_style[2] == 1) {
ai += to_string((int)qiyuan.Distance);//显示距离假人
} else if (draw_style[2] == 2) {
ai += to_string((int)qiyuan.TeamID);//显示队伍编号假人
}
} else {
color = ImColor(arr[qiyuan.TeamID]);//背景色跟随血量颜色
if (draw_style[2] == 0) {
ld += to_string((int) qiyuan.Health);//显示血量真人
} else if (draw_style[2] == 1) {
ld += to_string((int)qiyuan.Distance);//显示距离真人
} else if (draw_style[2] == 2) {
ld += to_string((int)qiyuan.TeamID);//显示队伍编号真人
}
}


auto textSize_ld = ImGui::CalcTextSize(ld.c_str());
auto textSize_ai = ImGui::CalcTextSize(ai.c_str());
// 计算圆形的中心位置
ImVec2 centerPos = ImVec2(NumIo[1] + Radar.x, NumIo[2] + Radar.y);
ImVec2 textPos = ImVec2(centerPos.x - textSize_ld.x / 3.4f, centerPos.y - textSize_ld.y / 3.5f);
ImVec2 textPos1 = ImVec2(centerPos.x - textSize_ai.x / 3.4f, centerPos.y - textSize_ai.y / 3.5f);

ImGui::GetForegroundDrawList()->AddCircleFilled(centerPos, 20, color);
ImGui::GetForegroundDrawList()->AddCircle(centerPos, 21, ImColor(0, 0, 0), 0, 2);
ImGui::GetForegroundDrawList()->AddText(NULL, 21, textPos, ImColor(0, 0, 0), ld.c_str());
ImGui::GetForegroundDrawList()->AddText(NULL, 21, textPos1, ImColor(0, 0, 0), ai.c_str());
// }

}
	
	/*if(DrawIo[16384])
            {  
            
            
	float fps = ImGui::GetIO().Framerate;
    std::string sFPS = "帧率: " + std::to_string(fps);
    Draw->AddText(NULL, 25, {150, 25}, ImColor(255, 0, 0), sFPS.c_str());       
    
ImVec2 watermarkPos(150, 85);
            }*/
	
/*	for (int i = 0; i < qiyuan.Count; i ++)
	{
	Distance = qiyuan.Distance;
    Health = qiyuan.Health;
		if (qiyuan.Distance > NumIo[17])
			continue;		
			
		Vec2 Radar = {(qiyuan.MyPos.x - qiyuan.Pos.x) / NumIo[16], (qiyuan.MyPos.y - qiyuan.Pos.y) / NumIo[16]};

        // 雷达
        float middlex = Radar.y;
        Radar.y = -Radar.x;
        Radar.x = middlex;
        float sina = -Radar.y / sqrt(Radar.x * Radar.x + Radar.y * Radar.y);
        float cosa = -Radar.x / sqrt(Radar.x * Radar.x + Radar.y * Radar.y);
        float xiebian = sqrt(qiyuan.matrix[7] * qiyuan.matrix[7] + qiyuan.matrix[3] * qiyuan.matrix[3]);
        float sinb = qiyuan.matrix[7] / xiebian;
        float cosb = qiyuan.matrix[3] / xiebian;
        float dis = sqrt(Radar.x * Radar.x + Radar.y * Radar.y);

        float sinab = sina * cosb - sinb * cosa;
        float cosab = cosa * cosb + sina * sinb;
        aa = sinb;
        bb = cosb;

        Radar.x = dis * cosab;
        Radar.y = dis * sinab;

        if ((Radar.x) * (Radar.x) + (Radar.y) * (Radar.y) <= 40000) {
            if (qiyuan.IsBot) {
                Draw->AddCircleFilled({NumIo[1] + Radar.x, NumIo[2] + Radar.y}, 3, ImColor(255, 255, 255)); // 修改圆圈点颜色和大小
            } else {
                tm = 150.f / 255.f;
                Draw->AddCircleFilled({NumIo[1] + Radar.x, NumIo[2] + Radar.y}, 15, ImColor(arr[qiyuan.TeamID % length]));
                string sdt = to_string((int)qiyuan.TeamID);
                auto textSize = ImGui::CalcTextSize(sdt.c_str(), 0, 25);
                Draw->AddText(NULL, 25, {NumIo[1] + Radar.x - textSize.x / 2, NumIo[2] + Radar.y - textSize.y * 0.45}, ImColor(255, 255, 255), sdt.c_str());
            }
        }
    }*/

// if (draw_style[66] == 1) {
// 雷达点
// if (DrawIo[7] && qiyuan.TotalUp) {
// // Vec2 Radar = {(qiyuan.MyPos.x - qiyuan.Pos.x) / NumIo[16], (qiyuan.MyPos.y - qiyuan.Pos.y) / NumIo[16]}; // 不旋转的雷达
// float radius = qiyuan.Distance/NumIo[16];
// Vec2 Radar = rotateCoord(qiyuan.angle, (qiyuan.MyPos.x - qiyuan.Pos.x) / (qiyuan.Distance / radius), (qiyuan.MyPos.y -qiyuan.Pos.y) / (qiyuan.Distance / radius)); // 旋转的雷达
// string ld;
// string ai;
// // if (NumIo[1] + Radar.x >= NumIo[1] - 100 && NumIo[1] + Radar.x <= NumIo[1] + 100 && NumIo[2] + Radar.y >= NumIo[2] - 100 && NumIo[2] + Radar.y <= NumIo[2] + 100) {

// ImColor color;
// if (qiyuan.IsBot == 1) {
// color = ImColor(255, 255, 255);//假人背景色白色
// if (draw_style[2] == 0) {
// ai += to_string((int) qiyuan.Health);//显示血量假人
// } else if (draw_style[2] == 1) {
// ai += to_string((int)qiyuan.Distance);//显示距离假人
// } else if (draw_style[2] == 2) {
// ai += to_string((int)qiyuan.TeamID);//显示队伍编号假人
// }
// } else {
// color = ImColor(arr[qiyuan.TeamID]);//背景色跟随血量颜色
// if (draw_style[2] == 0) {
// ld += to_string((int) qiyuan.Health);//显示血量真人
// } else if (draw_style[2] == 1) {
// ld += to_string((int)qiyuan.Distance);//显示距离真人
// } else if (draw_style[2] == 2) {
// ld += to_string((int)qiyuan.TeamID);//显示队伍编号真人
// }
// }


// auto textSize_ld = ImGui::CalcTextSize(ld.c_str());
// auto textSize_ai = ImGui::CalcTextSize(ai.c_str());
// // 计算圆形的中心位置
// ImVec2 centerPos = ImVec2(NumIo[1] + Radar.x, NumIo[2] + Radar.y);
// ImVec2 textPos = ImVec2(centerPos.x - textSize_ld.x / 3.4f, centerPos.y - textSize_ld.y / 3.5f);
// ImVec2 textPos1 = ImVec2(centerPos.x - textSize_ai.x / 3.4f, centerPos.y - textSize_ai.y / 3.5f);

// ImGui::GetForegroundDrawList()->AddCircleFilled(centerPos, 20, color);
// ImGui::GetForegroundDrawList()->AddCircle(centerPos, 21, ImColor(0, 0, 0), 0, 2);
// ImGui::GetForegroundDrawList()->AddText(NULL, 21, textPos, ImColor(0, 0, 0), ld.c_str());
// ImGui::GetForegroundDrawList()->AddText(NULL, 21, textPos1, ImColor(0, 0, 0), ai.c_str());
// // }

// }



} //人物绘制结束



if (wz.w > 0){
物资函数(载具, 0, 400);
物资函数(宝箱, 1, 150);
物资函数(物资箱, 2, 150);
物资函数(武器箱, 3, 150);
物资函数(药品箱, 4, 150);
物资函数(信函箱, 5, 150);
物资函数(姥爷物资, 6, 150);
物资函数(狗子, 7, 150);
 
物资函数(金插, 8, 120);
物资函数(信号枪_, 9, 200);
物资函数(盒子空投, 10, 150);
物资函数(药品, 11, 150);
物资函数(手枪, 12, 150);
物资函数(步枪, 13, 150);
物资函数(冲锋枪, 14, 150);
物资函数(狙击枪, 15, 150);
物资函数(霰弹枪, 16, 150);
物资函数(子弹, 17, 150);
物资函数(弹夹, 18, 150);
物资函数(枪口, 19, 150);
物资函数(瞄准镜, 20, 150);




// {
// string name;
// name += "[";
// name += to_string((int)wz.Distance);
// name += "米]";
// auto textSize = ImGui::CalcTextSize(name.c_str(),0, 20);
// Draw->AddText(NULL, 30,{wz.ScreenPos.x-(textSize.x / 2), wz.ScreenPos.y}, ImColor(0, 258, 0, 255), wz.Name);  
// }



if (DrawIo[14]) {
string name;
string name1;
string name2;
name += "手榴弹[" + to_string((int)wz.Distance) + "米]\n";
name1 += "燃烧瓶[" + to_string((int)wz.Distance) + "米]\n";
name2 += "烟雾弹[" + to_string((int)wz.Distance) + "米]\n";
if (strstr(wz.Name, "ProjGrenade_BP_C") || strstr(wz.Name, "BP_Grenade_Shoulei_C")) {
Draw->AddText(NULL, 20, { wz.ScreenPos.x - 25, wz.ScreenPos.y - 10 }, ImColor(255, 0, 0), name.c_str());
Draw->AddCircle({ wz.ScreenPos.x, wz.ScreenPos.y }, 45.0f, ImColor(255, 0, 0), 12);
} else if (strstr(wz.Name, "BP_Grenade_Burn_C") || strstr(wz.Name, "ProjBurn_BP_C")) {
Draw->AddText(NULL, 20, { wz.ScreenPos.x - 25, wz.ScreenPos.y - 10 }, ImColor(255, 255, 0), name1.c_str());
Draw->AddCircle({ wz.ScreenPos.x, wz.ScreenPos.y }, 45.0f, ImColor(255, 0, 0), 12);
} else if (strstr(wz.Name, "BP_Grenade_Smoke_C")) {
Draw->AddText(NULL, 25, { wz.ScreenPos.x - 25, wz.ScreenPos.y - 10 }, ImColor(0, 255, 0), name2.c_str());
Draw->AddCircle({ wz.ScreenPos.x, wz.ScreenPos.y }, 45.0f, ImColor(0, 255, 0), 12);
}


if (strstr(wz.Name, "BP_Grenade_Shoulei_C") || strstr(wz.Name, "BP_Grenade_Burn_C")) {
if (wz.Distance < 100) {
// 在屏幕中间绘制一个附近有手雷的文本
string guistr = "附近有投掷物";
Draw->AddText(NULL, 70, {screen_x/2 -160, screen_y  -900}, ImColor(255, 0, 0), guistr.c_str());
}
}
}
}






} //总循环
MaxPlayerCount = AimCount;
qiyuan.TotalUp = qiyuan.PlayerCount + qiyuan.BotCount;
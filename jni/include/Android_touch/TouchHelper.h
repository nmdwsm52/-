
#ifndef TOUCHHELPER_H
#define TOUCHHELPER_H
#define BITS_PER_LONG (sizeof(long) * 8)
#define NBITS(x) ((((x)-1)/BITS_PER_LONG)+1)
#define test_bit(array, bit) ((array[bit / BITS_PER_LONG] >> bit % BITS_PER_LONG) & 1)

void HandleTouchEvent();

bool GrabTouchScreen();

enum FingerStatus {
    FINGER_NO, // 无状态
    FINGER_X_UPDATE, // X更新
    FINGER_Y_UPDATE, // Y更新
    FINGER_XY_UPDATE, // XY同时更新
    FINGER_UP // 抬起
};

struct TouchFinger {
    int x = -1, y = -1; // 触摸点XY数据
    int tracking_id = -1; // 触摸点追踪ID数据
    int status = FINGER_NO;
    timeval time;
};// 10根手指

void Touch_Down(int slot,int x,int y); // 按下

void Touch_Move(int slot,int x,int y); // 移动 等价于 Touch_Down

void Touch_Up(int slot); // 抬起

TouchFinger* getTouchFinger(int slot);

void setTouchCallback(void (*_callback)(TouchFinger*));

void TouchScreenHandle(); // 监听
	
#endif

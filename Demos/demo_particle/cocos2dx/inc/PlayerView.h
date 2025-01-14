#pragma once

#include "cocos2d.h"
#include "Common-cpp/inc/Common.h"

class PlayerView : public cocos2d::CCNode
{
public:
	static const int MAX_USERNAME_LEN = 128;

	PlayerView(int number, const ExitGames::Common::JString& name, int cellSize, float borderWidth);

	void setPos(int x, int y);
	void setColor(int color);
	void setColor(const cocos2d::ccColor3B&);
	int getColor(void);
	void setNumber(int number);
	const ExitGames::Common::JString& getName(void);
	int getX(void);
	int getY(void);
	int getNumber(void);
	void updateView(int size);
	void fadeOpacity(float v);
	void resetOpacity(void);
private:
	cocos2d::CCSprite* sprite;
	int number;
	int x;
	int y;
	cocos2d::ccColor3B color;
	cocos2d::CCLabelBMFont* label;
	int cellSize;
	float borderWidth;
	ExitGames::Common::JString name;
	float opacity;
};
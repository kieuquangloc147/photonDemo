#pragma once

#include "cocos2d.h"
#include "../../src/LoadBalancingListener.h"
#include "../../src/BaseView.h"
#include "PlayerView.h"
#include "ListController.h"


class DemoScene : public cocos2d::CCLayer, public BaseView
{
public:
	DemoScene(void);
	~DemoScene(void);
	static DemoScene* create(void);
	
	void setLBC(ExitGames::LoadBalancing::Client* lbc, LoadBalancingListener* lbl);
	void setupUI(void);
	void tick(float delta);

	virtual void updateState(int state, const ExitGames::Common::JString& stateStr, const ExitGames::Common::JString& joinedRoomName);
	virtual void initPlayers();
	virtual void addPlayer(int playerNr, const ExitGames::Common::JString& playerName, bool local);
	virtual void removePlayer(int playerNr);
	virtual void changePlayerColor(int playerNr, int color);
	virtual void changePlayerPos(int playerNr, int x, int y);
    virtual void setupScene(int gridSize);
	virtual void updateRoomList(const ExitGames::Common::JVector<ExitGames::Common::JString>& roomNames);

	//from cocos2d::CCLayer
	virtual bool init(void);
	virtual void onExit(void);
	virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);

private: 
	int mCanvasSize;
	int mCellSize;

	cocos2d::CCDrawNode* mpCanvas;
	cocos2d::CCDrawNode* mpChecker;
	cocos2d::CCDrawNode* mpGrid;
	cocos2d::CCNode* mpPlayersNode;

	ExitGames::LoadBalancing::Client* mpLbc;
	LoadBalancingListener* mpLbl;

	cocos2d::CCLabelBMFont* mpLabelState;
	ListController* mpRoomList;

	void drawChecker(int gridSize);
	void drawGrid(int gridSize);
	void updatePlayerCellSizes(int gridSize);

	void menuNewGameCallback(CCObject* pSender);
	void menuLeaveCallback(CCObject* pSender);
	void menuGridSizeCallback(CCObject* pSender);
	void menuRandomColorCallback(CCObject* pSender);
	void menuAutomoveCallback(bool automove);
	void menuUseGroupsCallback(bool useGroups);

	void roomListCallback(const ExitGames::Common::JString& name);
	
	void onTouch(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);

	float setupDesktop(bool movable);
};
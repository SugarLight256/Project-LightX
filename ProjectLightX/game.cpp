#include "DxLib.h"
#include "player.h"
#include "map.h"
#include "panel.h"
#include "icon.h"
#include "game.h"
#include "gamenMgr.h"
#include "PUnit.h"
#include "EUnit.h"
#include "PShot.h"
#include "EShot.h"
#include "coll.h"
#include "player.h"
#include "enemy.h"
#include "Source.h"

int end;

void game_Update(){
	if(CheckHitKey(KEY_INPUT_ESCAPE)!=0 || end==1){
		end=0;
		WaitTimer(1200);
		gamenMgr_Change(-1);
	}
}
	

void game_Draw(){
	cam_Move();
	camera_calc();
	Map_Draw();
	map_calc();
	EUnit_Mgr();
	PUnit_Mgr();	
	PUnit_Coll();
	EUnit_Coll();
	PShot_Mgr();
	EShot_Mgr();
	Player_HP();
	Enemy_HP();
	panel_Draw();
	icon_Draw();
	Sou_Calc();
}

void gameOver(){
	end=1;
	Sou_Syoki();
	PUnit_Re();
	EUnit_Re();
	Player_Re();
	Enemy_Re();
}
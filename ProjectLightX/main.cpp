#include "DxLib.h"
#include "player.h"
#include "map.h"
#include "panel.h"
#include "game.h"
#include "menu.h"
#include "icon.h"
#include "config.h"
#include "gamenMgr.h"
#include "PUnit.h"
#include "EUnit.h"
#include "Pshot.h"
#include "EShot.h"
#include "PHP.h"
#include "enemy.h"
#include "save.h"
#include "load.h"

int menuSelect=1;
int MSelect;
int BGM;

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){

	SetAlwaysRunFlag(TRUE);
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	menu_Syoki();
	Map_Syoki();
	PHP_Syoki();
	panel_Syoki();
	icon_Syoki();
	EUnit_Syoki();
	PShot_Syoki();
	EShot_Syoki();
	Player_Syoki();
	Enemy_Syoki();

	while(ProcessMessage()==0 && ClearDrawScreen()==0 ){
	
	gamenMgr_Update();
	if(gamenMgr_Draw()==1){
		break;
	}
	if(icon_Touch()==1){
		DrawString(0,30,"config",1);
	}
	if(icon_Touch()==2){
		DrawString(0,30,"sound",1);
	}
	
	ScreenFlip();

	}
	
	DxLib_End();
	return 0;
}
	
	
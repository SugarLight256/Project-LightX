#include "DxLib.h"
#include "game.h"
#include "config.h"
#include "menu.h"
#include "gamenMgr.h"

int gamen=-1;

void gamenMgr_Update(){
	switch(gamen){
		case -1:
			menu_Update();
			break;
		case 0:
			game_Update();
			break;
		case 1:
			config_Update();
			break;
		case 2:
			break;
	}
}

int gamenMgr_Draw(){
	switch(gamen){
		case -1:
			menu_Draw();
			break;
		case 0:
			game_Draw();
			break;
		case 1:
			config_Draw();
			break;
		case 2:
			break;
		case 3:
			return 1;
	}
}

void gamenMgr_Change(int tugiGamen){
	if(gamen==2){
	}
	gamen=tugiGamen;
}			
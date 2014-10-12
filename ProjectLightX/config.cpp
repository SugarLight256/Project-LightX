#include "DxLib.h"
#include "config.h"
#include "gamenMgr.h"

extern int color[3];

void config_Update(){
    if(CheckHitKey(KEY_INPUT_ESCAPE)!=0){
        gamenMgr_Change(-1);
    }
}

void config_Draw(){
	DrawString(30,0,"コンフィグです（未実装）設定画面になります",color[2]);	
}
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
	DrawString(30,0,"�R���t�B�O�ł��i�������j�ݒ��ʂɂȂ�܂�",color[2]);	
}
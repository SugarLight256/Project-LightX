#include "DxLib.h"
#include "icon.h"
#include "gamenMgr.h"
#include "Source.h"

int config_Icon,sound_Icon;
int Mouse,X,Y;
int icon_Flag=0;
extern int SouLevel;
extern int Source;

void icon_Syoki(){      //読み込み
	config_Icon=LoadGraph("img/configIcon.png");
	sound_Icon =LoadGraph("img/soundIcon.png");

}

int icon_Touch(){      //クリック判定クリックされたらicon_Flagを立てる
	Mouse=GetMouseInput();
	GetMousePoint( &X, &Y ); 
	icon_Flag=0;
	if(Mouse & MOUSE_INPUT_LEFT){  
		if(X>=600 && X<=616  &&  Y>=450 && Y<=466){
			gamenMgr_Change(1);
			DrawString(0,0,"config_Flag=1",1); //動作確認用
		}
		if(X>=570&&X<=586&&Y>=450&&Y<=466){  //未実装　BGMを消す
			icon_Flag=2;
			if(Source>=SouLevel*SouLevel*SouLevel*3){
				Sou_Mine();
			}
			DrawString(0,0,"Sound_Flag=1",1);  //動作確認用
		}
	}
	return (icon_Flag);
}
	
void icon_Draw(){                      //アイコンの描写
	DrawGraph(600,450,config_Icon,TRUE);
	DrawGraph(570,450,sound_Icon,TRUE);
}
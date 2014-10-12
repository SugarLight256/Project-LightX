#include "DxLib.h"
#include "menu.h"
#include "gamenMgr.h"
#include "Key.h"

#define MENUTAG 4

extern int Key[256];
int SelectNum=0;
int menuGraph;



typedef struct{
        int x, y;
        char name[128];
} menuTag_t;

menuTag_t menuTag[MENUTAG]={
                { 120, 115, "ゲームスタート" }, 
                { 140, 150, "コンフィグ" },
				{ 140, 187, "ドック" },
                { 140, 300, "ゲーム終了" },
};

void menu_Syoki(){
	
	menuGraph=LoadGraph("img/menu.png");
}


void menu_Update(){
	KeyCalc();
    if(CheckHitKey(KEY_INPUT_G)!=0){
        gamenMgr_Change(0);
    }
    if(CheckHitKey(KEY_INPUT_C)!=0){
        gamenMgr_Change(1);
    }
    if(Key[KEY_INPUT_RETURN]==1){
    	if(SelectNum==0){
			gamenMgr_Change(0);
		}else if(SelectNum==1){
			gamenMgr_Change(1);
		}else if(SelectNum==2){
			gamenMgr_Change(2);	
		}else if(SelectNum==3){
			gamenMgr_Change(3);
		}
    }
}
 

void menu_Draw(){
	
	DrawGraph(0,0,menuGraph,TRUE);
	if( Key[ KEY_INPUT_UP ] == 1 && SelectNum >= 1){ // 上キーが押された瞬間だけ処理

			SelectNum = SelectNum - 1; // 現在の選択項目を一つ上にずらす(逆ループする)
	}
	if( Key[ KEY_INPUT_DOWN ] == 1 && SelectNum <= MENUTAG-2){ // 下キーが押された瞬間だけ処理
	
			SelectNum = SelectNum + 1; // 現在の選択項目を一つ下にずらす(ループする)
	}	
	if(Key[ KEY_INPUT_DOWN ] == 1 || Key[ KEY_INPUT_UP ] == 1){		
	    for( int i=0; i<MENUTAG; i++ ){              // メニュー項目数である5個ループ処理
	        if( i == SelectNum ){          // 今処理しているのが、選択番号と同じ要素なら
				menuTag[i].x = 120; // 座標を80にする
			} else {                       // 今処理しているのが、選択番号以外なら
   	       	 	menuTag[i].x = 140;// 座標を100にする
   	       	}
		}
	}
	
	for( int i=0; i<MENUTAG; i++ ){
		DrawFormatString( menuTag[i].x, menuTag[i].y, GetColor(180,60,230), menuTag[i].name );
	}
	
}
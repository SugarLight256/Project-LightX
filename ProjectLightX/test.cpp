#include "DxLib.h"
 
int Pspeed;//プレイヤー速さ
int Espeed;//敵
int PtamaX,PtamaY;//弾座標
int gamenX,gamenY;//弾座
int PX,EX;//プレイヤーX,敵X（Yは固定）
int cameraX;//画面の座標
int cam_idouryou;//画面の移動量（MAPXから)
 
 
void camera_calc(){
    cameraX+=cam_idouryou;
}
 
void Psyoki(){
    PX=0;
}
 
void Esyoki(){
    EX=1800;
} 
 
void cam_Move(){
	cam_idouryou=0;
    	if(CheckHitKey(KEY_INPUT_RIGHT)==1 && idouryou>0){
    	    cam_idouryou=-1;                  //画面を左に動かす
    	}else if(CheckHitKey(KEY_INPUT_LEFT)==1 && idouryou<1800){
    	    cam_idouryou=1;        //画面を右に動かす
    	}
}   	
 
void Map_Draw(){
    DrawGraph(0,0,"mapGraph",FALSE);
}
 
void Pcalc(){//計算
    PX=PX+Pspeed;
}
 
void Ecalc(){
    EX=EX+Espeed;
}
    
 
void PDraw(){
    DrawGraph(PX+idouryou,210,PyotGraph,TRUE);
}
 
void EDraw(){
    DrawGraph(EX+idouryou,210,EyotGraph,TRUE);
}
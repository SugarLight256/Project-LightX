#include "DxLib.h"
#include "map.h"
 
#define SHOT_MAX 200 
 
int Pspeed;//プレイヤー速さ
int Espeed;//敵
int PtamaX,PtamaY;//弾座標
int gamenX,gamenY;//弾座
int PX,EX;//プレイヤーX,敵X（Yは固定）
int cameraX;//画面の座標
int cam_idouryou;//画面の移動量（MAPXから）
int mapGraph;    //マップ画像
int mapX;        //マップの座表
 
 
void camera_calc(){
    cameraX=cameraX+cam_idouryou;
}

void map_calc(){
	mapX=mapX+cam_idouryou;
}

void Map_Syoki(){
	mapGraph=LoadGraph("img/stage.png");
}
 
void Psyoki(){
    PX=0;
}
 
void Esyoki(){
    EX=1800;
} 
 
void cam_Move(){                          //画面の移動
	cam_idouryou=0;
    	if(CheckHitKey(KEY_INPUT_RIGHT)==1 && mapX+1800 && mapX+1795 >=640){
    	    cam_idouryou=-5;                  //画面を左に動かす
    	}else if(CheckHitKey(KEY_INPUT_LEFT)==1 &&  mapX+5<=0){
    	    cam_idouryou=5;        //画面を右に動かす
    	}
}   	
 
void Map_Draw(){
    DrawGraph(mapX,0,mapGraph,FALSE);
}
 
    
 
void PDraw(int x,int y,int Graph){
    DrawGraph(x+cameraX,y,Graph,TRUE);//map上に描写するのでmapの座標を足して返す
}
 
void EDraw(int x,int y,int Graph){
    DrawGraph(x+cameraX,y,Graph,TRUE);
}

int Stop(int x){
	x=x+cameraX;					//今描写している座標を足して止まっているように描写
	return (x);
}

//int GetShotX(int i){
//	int j;
//	for(j=0;j>SHOT_MAX;j++){
//		return (dataP[i].dataPS[j].x);
//	}
//}

int DrawX(int x){
	return (x+cameraX);
}
	
	
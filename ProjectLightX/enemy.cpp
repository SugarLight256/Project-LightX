#include "DxLib.h"
#include "PUnit.h"
#include "struct.h"
#include "game.h"
#include "map.h"
#include "gamenMgr.h"

extern struct UNITDATAE_t dataE[UNIT_MAX];
extern int color[3];
extern int mapGraph;

int EGameOverGraph;
int EBaseGraph;

int Eend;

int Egrade;
int Edef=1;
int EMAXEHP=2000;
int EHP=2000;

double EBarWari;


void Enemy_Syoki(){
	EBaseGraph=LoadGraph("img/EBase.png");	
	EGameOverGraph=LoadGraph("img/GameClear.png");
}

void Enemy_Re(){
	
	EHP=EMAXEHP;
	
}

void Enemy_EHPDraw(double EBarWari){
	  
	DrawBox(330-2,10-2,630+2,20+2,color[0],TRUE);
	DrawBox(330,10,630,20,color[1],TRUE);
	DrawBox(330,10,EBarWari,20,color[2],TRUE);
	
	DrawGraph(DrawX(1550),35,EBaseGraph,TRUE);

}

void Enemy_Calc(){
	int ShotX;
	int ShotY;
	for(int i=0;i<UNIT_MAX;i++){
	for(int j=0;j<EQUIP_MAX;j++){
	for(int k=0;k<SHOT_MAX;k++){
		ShotX=dataP[i].PEquip[j].dataPS[k].x;
		ShotY=dataP[i].PEquip[j].dataPS[k].y;
		if(ShotX > 1550 && ShotX < 1800 && ShotY < 250 && ShotY > 100){
			EHP=(EHP-dataP[i].PEquip[j].dataPS[k].damage)/Edef;
			dataP[i].PEquip[j].dataPS[k].flag=0;
			dataP[i].PEquip[j].dataPS[k].x   =2000;
	    }
	}
	}
	}
}

void Enemy_HP(){

	Enemy_Calc();	
	EBarWari=(double)300*EHP/EMAXEHP+330;
	Enemy_EHPDraw(EBarWari);	
	if(EHP<=0){
		EHP=0;
		DrawGraph(200,200,EGameOverGraph,TRUE);
		DrawString(1,80,"ゲームのリセットが未実装なので一度終了しないと再度プレイできません",TRUE);
		if(Eend==1){
			gameOver();
		}
		Eend=1;
	}
	DrawFormatString(450,8,123,"%d/%d",EHP,EMAXEHP);
	
}

void Enemy_Mgr(){
	
}

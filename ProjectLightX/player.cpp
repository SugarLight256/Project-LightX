#include "DxLib.h"
#include "EUnit.h"
#include "struct.h"
#include "map.h"
#include "game.h"
#include "gamenMgr.h"

extern struct UNITDATAE_t dataE[UNIT_MAX];
extern int color[3];
extern int mapGraph;

int PBaseGraph;
int GameOverGraph;
int grade;
int def=1;
int MAXHP=2000;
int HP=2000;

double BarWari;


void Player_Syoki(){

	PBaseGraph=LoadGraph("img/PBase.png");	
	GameOverGraph=LoadGraph("img/GameOver.png");
}

void Player_Re(){
	
	HP=MAXHP;
	
}

void Player_HPDraw(double BarWari){
	  
	DrawBox(10-2,10-2,310+2,20+2,color[0],TRUE);
	DrawBox(10,10,310,20,color[1],TRUE);
	DrawBox(10,10,310*BarWari,20,color[2],TRUE);
	
	DrawGraph(DrawX(0),35,PBaseGraph,TRUE);

}

void Player_Calc(){

	int ShotX;
	int ShotY;
	for(int i=0;i<UNIT_MAX;i++){
	for(int j=0;j<EQUIP_MAX;j++){
	for(int k=0;k<SHOT_MAX;k++){
		ShotX=dataE[i].EEquip[j].dataES[k].x;
		ShotY=dataE[i].EEquip[j].dataES[k].y;
		if(ShotX < 250 && ShotX > 0 && ShotY < 250 && ShotY > 100){
			HP=HP-dataE[i].EEquip[j].dataES[k].damage;
			dataE[i].EEquip[j].dataES[k].flag=0;
			dataE[i].EEquip[j].dataES[k].x   =2000;
	    }
	}
	}
	}
}

void Player_HP(){

	Player_Calc();	
	BarWari=(double)HP/MAXHP;
	Player_HPDraw(BarWari);	
	if(HP <= 0){
		DrawGraph(200,200,GameOverGraph,TRUE);
		gameOver();
	}
	DrawFormatString(130,8,123,"%d/%d",HP,MAXHP);
	
}

void Player_Mgr(){
	
}
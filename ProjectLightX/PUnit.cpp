#include "DxLib.h"
#include "map.h"
#include "struct.h"
#include "PShot.h"
#include "PHP.h"
#include "Source.h"
#include "doc.h"

struct UNITDATAP_t dataP[UNIT_MAX];
extern struct UNITDATAE_t dataE[UNIT_MAX];
extern struct SlotTag_t Slot[SLOT_MAX]; 

int PyotGraph,PikadaGraph,PkyakusenGraph;
int PyotGraphX,PyotGraphY,PikadaGraphX,PikadaGraphY,PkyakusenGraphX,PkyakusenGraphY;

int PyotCoolTime;
int PikadaCoolTime;
int PkyakusenCoolTime;

int Pfi;
float Min;
float now;
int lap;
int befX;
int befY;

void PUnit_Re(){
	for(int i=0;i<UNIT_MAX;i++){
	for(int j=0;j<EQUIP_MAX;j++){
		dataP[i].x=2000;
		dataP[i].flag=0;
		dataP[i].PEquip[j].cool=0;
		dataP[i].PEquip[j].bull=100;
	}
	}
}

void PUnit_Syoki(){  
	int i;                             //読み込み
	PyotGraph  =LoadGraph("img/Unit/yot.png");
	PikadaGraph=LoadGraph("img/Unit/ikada.png");
	PkyakusenGraph=LoadGraph("img/Unit/kyakusen.png");
	GetGraphSize(PyotGraph,&PyotGraphX,&PyotGraphY);
	GetGraphSize(PikadaGraph,&PikadaGraphX,&PikadaGraphY);
	GetGraphSize(PkyakusenGraph,&PkyakusenGraphX,&PkyakusenGraphY);
	for(i=0;i<UNIT_MAX;i++){
		dataP[i].x=2000;
		dataP[i].flag=0;
	}
	PUnit_Re();
}

void PUnit_Input(int type,int i){
	switch(type){
		case 1:
			dataP[i].type =Slot[0].type;
			dataP[i].flag =1;
			dataP[i].x    =0;
			dataP[i].y    =215-PyotGraphY;
			dataP[i].speed=1;
			dataP[i].range=Slot[0].range;
			dataP[i].MAXHP=100;
			dataP[i].HP   =100;
			dataP[i].w    =PikadaGraphX;
			dataP[i].h    =PikadaGraphY;
			PikadaCoolTime=0; //クールダウンタイムリセット
			Sou_Update(-15);
			break;
		case 2:
			dataP[i].type =Slot[1].type;
			dataP[i].flag =1;
			dataP[i].x    =0;
			dataP[i].y    =215-PikadaGraphY;
			dataP[i].speed=0.7;
			dataP[i].range=Slot[1].range;
			dataP[i].MAXHP=100;
			dataP[i].HP   =100;
			dataP[i].w    =PyotGraphX;
			dataP[i].h    =PyotGraphY;
			Sou_Update(-25);
			PyotCoolTime=0;   //クールダウンタイムリセット
			break;
		case 3:
			dataP[i].type =Slot[2].type;
			dataP[i].flag =1;
			dataP[i].x    =0;
			dataP[i].y    =215-PikadaGraphY;
			dataP[i].speed=0.5;
			dataP[i].range=Slot[2].range;
			dataP[i].MAXHP=150;
			dataP[i].HP   =150;
			dataP[i].w    =PkyakusenGraphX;
			dataP[i].h    =PkyakusenGraphY;
			Sou_Update(-40);
			PkyakusenCoolTime=0;   //クールダウンタイムリセット
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
	}
}

void PUnit_Select(int i){                      //押されているボタンに応じて
	if(dataP[i].flag==0){
		if(CheckHitKey(KEY_INPUT_1)==1 && PikadaCoolTime>=120 && Sou_Give() >= 15 && Slot[0].flag==1){
			PUnit_Input(1,i);
		}else if(CheckHitKey(KEY_INPUT_1)==1 && Slot[0].flag!=1){
			DrawString(320-200,460,"スロットにユニットが指定されていません",123);
		}
		if(CheckHitKey(KEY_INPUT_2)==1 && PyotCoolTime>=130 && Sou_Give() >= 25 && Slot[1].flag==1){
            PUnit_Input(2,i);
		}else if(CheckHitKey(KEY_INPUT_2)==1 && Slot[1].flag!=1){
			DrawString(320-200,460,"スロットにユニットが指定されていません",123);
		} 
		if(CheckHitKey(KEY_INPUT_3)==1 && PkyakusenCoolTime>=150 && Sou_Give() >= 40 && Slot[2].flag==1){
			PUnit_Input(3,i);
		}else if(CheckHitKey(KEY_INPUT_3)==1 && Slot[2].flag!=1){
			DrawString(320-200,460,"スロットにユニットが指定されていません",123);
		} 	
	}
}

void PUnit_Draw(int i,int type){    //描写用関数
		if(dataP[i].flag==1){
			switch(dataP[i].type){
				case 1:
					PDraw(dataP[i].x,dataP[i].y,PikadaGraph);
					break;
				case 2:
					PDraw(dataP[i].x,dataP[i].y,PyotGraph);
					break;
				case 3:
					PDraw(dataP[i].x,dataP[i].y,PkyakusenGraph);
			}
		}
}

int PUnit_Range(int i){ //索敵範囲
	int mj;
	int xl,yl,r;
	int befXl;
	for(int j=0;j<UNIT_MAX;j++){
		if(dataE[j].flag==1){
			xl = dataE[j].x - dataP[i].x;      //索敵範囲計算
			yl = dataE[j].y - dataP[i].y;
			if(xl <= befXl){
				befXl=xl;
				mj=j;
			}
		}
	}
	r = befXl * befXl + yl * yl;
	switch(dataP[i].type){
	case 1:
		if(  r < dataP[i].range * dataP[i].range ){
			dataP[i].rangeFlag=1;	
			dataP[i].Ex=dataE[mj].x+dataE[mj].w/2;
			dataP[i].Ey=dataE[mj].y+dataE[mj].h/2;
			return 0;
		}else{
			dataP[i].rangeFlag=0;
			return 0;
		}
		break;
	case 2:
		if(  r < dataP[i].range * dataP[i].range ){
			dataP[i].rangeFlag=1;
			dataP[i].Ex=dataE[mj].x+dataE[mj].w/2;
			dataP[i].Ey=dataE[mj].y+dataE[mj].h/2;
			return 0;
		}else{
			dataP[i].rangeFlag=0;
			return 0;
		}
		break;
	case 3:     //以下追加予定
		if(  r < dataP[i].range * dataP[i].range ){
			dataP[i].rangeFlag=1;
			dataP[i].Ex=dataE[mj].x+dataE[mj].w/2;
			dataP[i].Ey=dataE[mj].y+dataE[mj].h/2;
			return 0;
		}else{
			dataP[i].rangeFlag=0;
			return 0;
		}
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	}
	if((dataP[i].x-1550)*(dataP[i].x-1550) < dataP[i].range * dataP[i].range){
		dataP[i].rangeFlag=1;
	}
}

void PUnit_Calc(int i){                 //移動計算
	if(dataP[i].flag==1){
		if(dataP[i].rangeFlag!=1){             
			dataP[i].x=dataP[i].x+dataP[i].speed;
		}else{
			Stop(dataP[i].x);                //マップのスクロールに合わせる
		}
		
		dataP[i].rangeFlag=0;
		PUnit_Draw(i,dataP[i].type);       //描写関数実行
		if(dataP[i].rangeFlag != 1){
			PUnit_Range(i);
		}
	}
}

void PUnit_HP(int i){
	if(dataP[i].flag==1){
		switch(dataP[i].type){
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
		}
	}
}

void PUnit_HP(){
	int i;
	int Mi=0;
	Min=1;
	
	for(i=0;i<UNIT_MAX;i++){
	
		if(dataP[i].flag==1){
			HP_Calc(dataP[i].MAXHP/2,dataP[i].x+dataP[i].w/2,dataP[i].y,dataP[i].HP);
			now=(float)dataP[i].HP/dataP[i].MAXHP;
			if(now <= Min){
				Min=now;
				Mi=i;
			}
			if(dataP[i].x > befX){
				befX=dataP[i].x;
			}
		}
	}
	HP_Calc(dataP[Mi].MAXHP/2,dataP[Mi].x+dataP[Mi].w/2,dataP[Mi].y,dataP[Mi].HP);
}
	
		
void PUnit_Mgr(){
	for(Pfi=0;Pfi<UNIT_MAX;Pfi++){
	
		PUnit_Select(Pfi);
	    PUnit_Calc(Pfi);
		
		if(dataP[Pfi].x <= befX+2 && dataP[Pfi].x >= befX-2){
			lap++;
		}
	}

	befX=DrawX(befX);
	if(lap > 1 && befX > 10){
		DrawFormatString(befX,befY,0,"%d",lap);
	}
	lap=0;
	befX=0;
	PUnit_HP();
	PikadaCoolTime++;
	PyotCoolTime++;
	PkyakusenCoolTime++;
}
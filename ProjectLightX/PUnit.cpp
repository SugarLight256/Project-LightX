#include "DxLib.h"
#include "map.h"
#include "struct.h"
#include "PShot.h"
#include "PHP.h"
#include "Source.h"
#include "doc.h"
#include "PUnit.h"

struct UNITDATAP_t dataP[UNIT_MAX];
extern struct UNITDATAE_t dataE[UNIT_MAX];
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

char a[100]="abcdefg";

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

void PUnit_Draw(int i,int type){    //•`ŽÊ—pŠÖ”
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

int PUnit_Range(int i){ //õ“G”ÍˆÍ
	int mj;
	int xl,yl,r;
	int befXl;
	for(int j=0;j<UNIT_MAX;j++){
		if(dataE[j].flag==1){
			xl = dataE[j].x - dataP[i].x;      //õ“G”ÍˆÍŒvŽZ
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
	case 3:     //ˆÈ‰º’Ç‰Á—\’è
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

void PUnit_Calc(int i){                 //ˆÚ“®ŒvŽZ
	if(dataP[i].flag==1){
		if(dataP[i].rangeFlag!=1){             
			dataP[i].x=dataP[i].x+dataP[i].speed;
		}else{
			Stop(dataP[i].x);                //ƒ}ƒbƒv‚ÌƒXƒNƒ[ƒ‹‚É‡‚í‚¹‚é
		}
		
		dataP[i].rangeFlag=0;
		PUnit_Draw(i,dataP[i].type);       //•`ŽÊŠÖ”ŽÀs
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
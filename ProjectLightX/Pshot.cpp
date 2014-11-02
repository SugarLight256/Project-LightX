#include "DxLib.h"
#include "PShot.h"
#include "struct.h"
#include "map.h"
#include "Weapon.h"

int PMG;
int PMS;

int PSfi,PSfj;

extern struct UNITDATAP_t dataP[UNIT_MAX];
extern struct UNITDATAE_t dataE[UNIT_MAX];

void PShot_Syoki(){

	PMG=LoadGraph("img/shot/MG.png");
	PMS=LoadGraph("img/shot/mis.png");
	
}

void PShot_Select(int i,int j,int k){
	if(dataP[i].rangeFlag==1){
		switch(dataP[i].type){
		case 1:
			if(dataP[i].PEquip[j].cool >= 60 /*&& dataP[i].PEquip[j].bull > 0*/){
				if(dataP[i].PEquip[j].dataPS[k].flag != 1){
					dataP[i].PEquip[j].dataPS[k].x     = dataP[i].x + 24;
					dataP[i].PEquip[j].dataPS[k].y     = dataP[i].y + 5;
					dataP[i].PEquip[j].dataPS[k].flag  = 1;
					dataP[i].PEquip[j].cool            = 0;
					dataP[i].PEquip[j].type            = 1;
					dataP[i].PEquip[j].dataPS[k].speedX= 3;
					dataP[i].PEquip[j].dataPS[k].speedY= 3;
					dataP[i].PEquip[j].dataPS[k].type  = 1;
					dataP[i].PEquip[j].dataPS[k].damage= 1;
					dataP[i].PEquip[j].dataPS[k].Graph = PMG;
				}
			}
			break;
		case 2:
			if(dataP[i].PEquip[j].cool >= 60 /*&& dataP[i].PEquip[j].bull > 0*/){
				if(dataP[i].PEquip[j].dataPS[k].flag != 1){
					dataP[i].PEquip[j].dataPS[k].x     = dataP[i].x + 24;
					dataP[i].PEquip[j].dataPS[k].y     = dataP[i].y + 5;
					dataP[i].PEquip[j].dataPS[k].flag  = 1;
					dataP[i].PEquip[j].cool            = 0;
					dataP[i].PEquip[j].type            = 1;
					dataP[i].PEquip[j].dataPS[k].speedX= 3;
					dataP[i].PEquip[j].dataPS[k].speedY= 3;
					dataP[i].PEquip[j].dataPS[k].type  = 1;
					dataP[i].PEquip[j].dataPS[k].damage= 1;
					dataP[i].PEquip[j].dataPS[k].Graph = PMG;
				}
			}
			break;
		case 3:
			if(dataP[i].PEquip[j].cool >= 60 /*&& dataP[i].PEquip[j].bull > 0*/){
				if(dataP[i].PEquip[j].dataPS[k].flag != 1){
					dataP[i].PEquip[j].dataPS[k].x     = dataP[i].x + 24;
					dataP[i].PEquip[j].dataPS[k].y     = dataP[i].y + 5;
					dataP[i].PEquip[j].dataPS[k].flag  = 1;
					dataP[i].PEquip[j].cool            = 0;
					dataP[i].PEquip[j].type            = 3;
					dataP[i].PEquip[j].dataPS[k].speedX= 0;
					dataP[i].PEquip[j].dataPS[k].speedY= 6;
					dataP[i].PEquip[j].dataPS[k].type  = 3;
					dataP[i].PEquip[j].dataPS[k].damage= 2;
					dataP[i].PEquip[j].dataPS[k].Graph = PMS;
				}
			}
			break;
		}
	}
}		

void PShot_Mgr(){
	for(int i=0;i<UNIT_MAX;i++){
	if(dataP[i].flag==1){
	for(int j=0;j<EQUIP_MAX;j++){
	for(int k=0;k<SHOT_MAX;k++){
    
	PShot_Select(i,j,k); 
	if(dataP[i].PEquip[j].dataPS[k].flag==1){
		
		PWeapon_Mgr(i,j,k);
		
		if(dataP[i].PEquip[j].dataPS[k].x < 0 || dataP[i].PEquip[j].dataPS[k].x > 1800){
			dataP[i].PEquip[j].dataPS[k].flag=0;
		}else if(dataP[i].PEquip[j].dataPS[k].y < -20 || dataP[i].PEquip[j].dataPS[k].y >= 500){
			dataP[i].PEquip[j].dataPS[k].flag =0;
		}
	} else {
		dataP[i].PEquip[j].dataPS[k].x    =2000;
		dataP[i].PEquip[j].dataPS[k].MTime=0;
	}
	}
	dataP[i].PEquip[j].cool++;
	}
	}
	}
			
}

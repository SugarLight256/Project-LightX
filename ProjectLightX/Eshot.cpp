#include "DxLib.h"
#include "PShot.h"
#include "struct.h"
#include "map.h" 
#include "Weapon.h"

int EMG;

int ESfi,ESfj;

extern struct UNITDATAE_t dataE[UNIT_MAX];
extern struct UNITDATAP_t dataP[UNIT_MAX];

void EShot_Syoki(){

	EMG=LoadGraph("img/shot/MG.png");
	
}

void EShot_Select(int i,int j,int k){
	if(dataE[i].rangeFlag==1){
		switch(dataE[i].type){
		case 1:
			if(dataE[i].EEquip[j].cool >= 60){
				if(dataE[i].EEquip[j].dataES[k].flag != 1){
					dataE[i].EEquip[j].dataES[k].x     = dataE[i].x + 24;
					dataE[i].EEquip[j].dataES[k].y     = dataE[i].y + 5;
					dataE[i].EEquip[j].dataES[k].flag  = 1;
					dataE[i].EEquip[j].cool            = 0;
					dataE[i].EEquip[j].type            = 1;
					dataE[i].EEquip[j].dataES[k].speedX= -6;
					dataE[i].EEquip[j].dataES[k].speedY= 10;
					dataE[i].EEquip[j].dataES[k].type  = 1;
					dataE[i].EEquip[j].dataES[k].Graph =EMG;
					dataE[i].EEquip[j].dataES[k].damage=1;
				}
			}
			break;
		}
	}			
}

void EShot_Mgr(){
	for(int i=0;i<UNIT_MAX;i++){
	if(dataE[i].flag==1){
	for(int j=0;j<EQUIP_MAX;j++){
	for(int k=0;k<SHOT_MAX;k++){

		EShot_Select(i,j,k);
		
		if(dataE[i].EEquip[j].dataES[k].flag==1){
			EWeapon_Mgr(i,j,k);
			
			if(dataE[i].EEquip[j].dataES[k].x < 0 || dataE[i].EEquip[j].dataES[k].x > 1800){
				dataE[i].EEquip[j].dataES[k].flag=0;
			}else if(dataE[i].EEquip[j].dataES[k].y < -20 || dataE[i].EEquip[j].dataES[k].y >= 500){
				dataE[i].EEquip[j].dataES[k].flag =0;
			}
			
		} else {
			dataE[i].EEquip[j].dataES[k].x=2000;
		}	
		
	}
	dataE[i].EEquip[j].cool++;
	}
	}
	}
}

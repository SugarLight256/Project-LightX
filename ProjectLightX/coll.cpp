#include "DxLib.h"
#include "PUnit.h"
#include "EUnit.h"
#include "coll.h"
#include "struct.h"
#include "Source.h"

extern struct UNITDATAP_t dataP[UNIT_MAX];
extern struct UNITDATAE_t dataE[UNIT_MAX];

extern int PyotGraphX;
extern int EyotGraphX;


void PUnit_Coll(){
	int i,j,k,m;
	for(i=0 ; i < UNIT_MAX ; i++){
		if(dataP[i].flag==1){
			for(k=0 ; k < UNIT_MAX ; k++){
			if(dataE[k].flag==1){
			for(j=0 ; j < EQUIP_MAX ; j++){
			for(m=0 ; m < SHOT_MAX ; m++){
				if(dataE[k].EEquip[j].dataES[m].x <= dataP[i].x+PyotGraphX && dataE[k].EEquip[j].dataES[m].x >= dataP[i].x){
					dataE[k].EEquip[j].dataES[m].flag=0;
					dataE[k].EEquip[j].dataES[m].x=2000;
					dataP[i].HP           -=dataE[k].EEquip[j].dataES[m].damage;
					if(dataP[i].HP <= 0){
						dataP[i].flag=0; 
						dataP[i].x=2000;
						dataP[i].rangeFlag=0;
					}
				}
			}
			}
			}
			}
		}
	}
}

void EUnit_Coll(){
	int add;
	int i,j,k,m;
	for(i=0 ; i < UNIT_MAX ; i++){
		if(dataE[i].flag==1){
			for(k=0 ; k < UNIT_MAX ; k++){
			if(dataP[k].flag==1){
			for(j=0 ; j < EQUIP_MAX ; j++){
			for(m=0 ; m < SHOT_MAX ; m++){
				if(dataP[k].PEquip[j].dataPS[m].x <= dataE[i].x+EyotGraphX && dataP[k].PEquip[j].dataPS[m].x >= dataE[i].x){
					if(dataE[i].flag==1){
						dataP[k].PEquip[j].dataPS[m].flag=0;
						dataP[k].PEquip[j].dataPS[m].x   =2000;
						dataE[i].HP           -=dataP[k].PEquip[j].dataPS[m].damage;
						if(dataE[i].HP <= 0){
							Sou_Update(dataE[i].add);
							dataE[i].flag=0;
							dataE[i].x=2000;
							dataE[i].rangeFlag=0;
						}
					}
				}
				if(dataP[k].PEquip[j].dataPS[m].flag==0){
					dataP[k].PEquip[k].dataPS[m].x=2000;
					dataP[k].PEquip[k].dataPS[m].FM=0;	
				}
			}
			}
			}
			}
		}
	}
}
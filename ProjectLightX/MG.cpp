#include "DxLib.h"

void MG_Calc(int i,int j,int k){
		if(dataP[i].PEquip[j].dataPS[k].flag==1){
			dataP[i].PEquip[j].dataPS[k].x += dataP[i].PEquip[j].dataPS[k].speed;
			PShot_Draw(i,j,k);
		}
		if(dataP[i].PEquip[j].dataPS[k].x >= 1800 || dataP[i].PEquip[j].dataPS[k].x <= 0){
			dataP[i].PEquip[j].dataPS[k].flag = 0;
		}
}
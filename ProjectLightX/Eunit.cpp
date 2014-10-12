#include "DxLib.h"
#include "map.h"
#include "struct.h"
#include "EShot.h"
#include "PHP.h"

extern struct UNITDATAP_t dataP[UNIT_MAX];
struct UNITDATAE_t dataE[UNIT_MAX];

int EyotGraph,EikadaGraph;
int EyotGraphX,EyotGraphY,EikadaGraphX,EikadaGraphY;

int EyotCoolTime=0;
int EikadaCoolTime=0;

int Efi;

float Enow;
float EMin;
int Elap;
int EbefX=20000;
int EbefY;

void EUnit_Syoki(){       //読み込み
	int i;
	EyotGraph  =LoadGraph("img/Unit/yot.png");
	EikadaGraph=LoadGraph("img/Unit/ikada.png");
	GetGraphSize(EyotGraph,&EyotGraphX,&EyotGraphY);
	GetGraphSize(EikadaGraph,&EikadaGraphX,&EikadaGraphY);
	for(i=0;i<UNIT_MAX;i++){
		dataE[i].x=2000;
		dataE[i].flag=0;
	}
}

void EUnit_Re(){
	for(int i=0;i<UNIT_MAX;i++){
	for(int j=0;j<EQUIP_MAX;j++){
		dataE[i].x=2000;
		dataE[i].flag=0;
		dataE[i].EEquip[j].cool=0;
		dataE[i].EEquip[j].bull=100;
	}
	}	
}

void EUnit_Select(int i){       //まだ開発初期段階なのでランダム出現ではなく一定速度での出現に固定
	if(dataE[i].flag==0){
		if(EikadaCoolTime>=800){
				dataE[i].type =1;
				dataE[i].flag =1;
				dataE[i].x    =1800;
				dataE[i].y    =215-EyotGraphY;
				dataE[i].w    =EikadaGraphX;
				dataE[i].h    =EikadaGraphY;
				dataE[i].speed=-0.5;
				dataE[i].range=150;
				dataE[i].MAXHP=50;
				dataE[i].HP   =50;
				dataE[i].add  =10;
				EikadaCoolTime=0;
		}
		if(EyotCoolTime>=1100){
				dataE[i].type =2;
				dataE[i].flag =1;
				dataE[i].x    =1800;
				dataE[i].y    =215-EikadaGraphY;
				dataE[i].w    =EyotGraphX;
				dataE[i].h    =EyotGraphY;
				dataE[i].speed=-0.5;
				dataE[i].MAXHP=50;
				dataE[i].HP   =50;
				dataE[i].add  =25;
				dataE[i].range=150;
				EyotCoolTime  =0;
		}
	}
}

void EUnit_Draw(int i){  //種類ごとに画像が変わるので種類ごとに描写
		if(dataE[i].flag==1){
			switch(dataE[i].type){
				case 1:
					EDraw(dataE[i].x,dataE[i].y,EikadaGraph);
					break;
				case 2:
					EDraw(dataE[i].x,dataE[i].y,EyotGraph);
					break;
			}
		}
}

int EUnit_Range(int i){ //索敵範囲
	int j;
	int ret;
	int xl,yl,r;
	for(j=0;j<UNIT_MAX;j++){
		if(dataP[j].flag==1){
			xl = dataE[i].x - dataP[j].x+dataP[j].w;      //索敵範囲計算
			yl = dataE[i].y - dataP[j].y;
			r = xl * xl + yl * yl;
			switch(dataE[i].type){
				case 1:
					if(  r < dataE[i].range * dataE[i].range){
						ret=1;	
						dataE[i].Px=dataP[j].x;
						dataE[i].Py=dataP[j].y;
					}else if(ret!=1){
						ret=0;
					}
					break;
				case 2:
					if(  r < dataE[i].range * dataE[i].range){
						ret=1;
					}else if(ret!=1){
						ret=0;
					}
					break;
				case 3:    //以下追加予定
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
		if((dataE[i].x-250)*(dataE[i].x-250) < dataE[i].range * dataE[i].range){
			ret=1;
		}
	}
	return ret;
}

void EUnit_Calc(int i){       //移動の計算、描写関数実行
	if(dataE[i].flag==1){
		if(dataE[i].rangeFlag!=1){                     
			dataE[i].x=dataE[i].x+dataE[i].speed;
		}else{
			Stop(dataE[i].x);                //マップのスクロールに合わせる
		}
		
		dataE[i].rangeFlag=0;
		EUnit_Draw(i);
		dataE[i].rangeFlag=EUnit_Range(i);
	}
}

void EUnit_HP(int i){
	int EMi=0; 
	EMin=1;
	
	
		if(dataE[i].flag==1){
			HP_Calc(dataE[i].MAXHP/2,dataE[i].x+dataE[i].w/2,dataE[i].y,dataE[i].HP);
			Enow=(float)dataE[i].HP / dataE[i].MAXHP;
			if(Enow <= EMin){
				EMin=Enow;
				EMi=i;
			}
			if(dataE[i].x < EbefX){
				EbefY=dataE[i].y-25;
				EbefX=dataE[i].x;
			}
		}
	HP_Calc(dataE[EMi].MAXHP/2,dataE[EMi].x+dataE[EMi].w/2,dataE[EMi].y,dataE[EMi].HP);
}


void EUnit_Mgr(){
	for(Efi=0;Efi<UNIT_MAX;Efi++){
	
		EUnit_Select(Efi);
	    EUnit_Calc(Efi);
		EUnit_HP(Efi);
		
		if(dataE[Efi].x <= EbefX+2 && dataE[Efi].x >= EbefX-2){
			Elap++;
		}
		
	}     
	EbefX=DrawX(EbefX);
	if(Elap > 1){
		DrawFormatString(EbefX,EbefY,1,"%d",Elap);
	}
	Elap=0;
	EbefX=20000;
	EikadaCoolTime=EikadaCoolTime+1;
	EyotCoolTime=EyotCoolTime+1;
}

#include "DxLib.h"
#include "struct.h"
#include "PUnit.h"
#include "map.h"

extern struct UNITDATAP_t dataP[UNIT_MAX];
extern struct UNITDATAE_t dataE[UNIT_MAX]; 

int color[3];

void PHP_Syoki(){
	
	color[0]=GetColor(100,100,100);
	color[1]=GetColor(194,3,32);
	color[2]=GetColor(55,220,7);
	
}

void HP_Draw(int X,int Y,int X2,int Y2,int type){
	
	DrawBox(X,Y,X2,Y2,color[type],TRUE);
	
}

void HP_Calc(int MAXHP,int x,int y,int HP){
	int RedX,RedY,RedX2,RedY2;
	int GreyX,GreyY,GreyX2,GreyY2;
	int GrnX,GrnY,GrnX2,GrnY2;
	
	
	RedX=x-MAXHP/2;
	RedX=DrawX(RedX);
	RedY=y-10;
	RedX2=RedX+MAXHP;//(MAXHP)+(ç∂í[ÇÃ-2Ç0Ç…Ç∑ÇÈÇΩÇﬂ+2)+(ç∂í[)+(í[Ç¡Ç±è≠Çµ)
	RedY2=RedY+2;
	
	GreyX=RedX-4;
	GreyY=RedY-1;
	GreyX2=RedX2+4;
	GreyY2=RedY2+1;
	
	GrnX=RedX;
	GrnY=RedY;
	GrnX2=RedX+HP/2;
	GrnY2=RedY2;
	
	HP_Draw(GreyX,GreyY,GreyX2,GreyY2,0);
	HP_Draw(RedX,RedY,RedX2,RedY2,1);
	HP_Draw(GrnX,GrnY,GrnX2,GrnY2,2);
}

void PHP_Mgr(){
	
}

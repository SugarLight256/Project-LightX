#include "DxLib.h"
#include "struct.h"
#include "PUnit.h"
#include "map.h"

extern struct UNITDATAE_t dataE[UNIT_MAX];
extern int color[3];

void EHP_Syoki(){
	
}

void EHP_Draw(int X,int Y,int X2,int Y2,int type){
	
	DrawBox(X,Y,X2,Y2,color[type],TRUE);
	
}

void EHP_Calc(int i){
	int MAXHP;
	int RedX,RedY,RedX2,RedY2;
	int GreyX,GreyY,GreyX2,GreyY2;
	int GrnX,GrnY,GrnX2,GrnY2;
	MAXHP=dataE[i].MAXHP/2;
	
	RedX=dataE[i].x+dataE[i].w/2-MAXHP/2;
	RedX=DrawX(RedX);
	RedY=dataE[i].y-10;
	RedX2=RedX+MAXHP;//(MAXHP)-(ç∂í[ÇÃ+2Ç0Ç…Ç∑ÇÈÇΩÇﬂ-2)-(ç∂í[)-(í[Ç¡Ç±è≠Çµ)
	RedY2=RedY+2;
	
	GreyX=RedX-4;
	GreyY=RedY-1;
	GreyX2=RedX2+4;
	GreyY2=RedY2+1;
	
	GrnX=RedX;
	GrnY=RedY;
	GrnX2=RedX+dataE[i].HP/2;
	GrnY2=RedY2;
	
	EHP_Draw(GreyX,GreyY,GreyX2,GreyY2,1);
	EHP_Draw(RedX,RedY,RedX2,RedY2,2);
	EHP_Draw(GrnX,GrnY,GrnX2,GrnY2,3);
}

void EHP_Mgr(){
	
}

#include "DxLib.h"

int Source;
int SouCool;
int SouCoolDefault=40;
int SouLevel=1;
int SouMAX=5000;
float SouBarWari;
float rise=1;

extern int color[3];

void Sou_Syoki(){
	Source=0;	
}

void Sou_Draw(float Bar){

	int Width;
	Width=GetDrawFormatStringWidth("%d/%d",Source,SouMAX);//Source/SouMAX‚Ì•¶Žš•Žæ“¾
	
	DrawBox(350-2,365-2,620+2,380+2,color[0],TRUE); //ŠDF‚Ì“y‘ä•\Ž¦
	DrawBox(350,365,620,380,GetColor(255,255,255),TRUE);//”’‚ÌMAX••\Ž¦
	DrawBox(350,365,Bar*270+350,380,color[2],TRUE);//—Î‚ÅŒ»Ý‚ÌŽ‘Œ¹••\Ž¦	
	DrawFormatString(350+270/2-Width/2,365,123,"%d/%d",Source,SouMAX);
	
}

void Sou_Calc(){
	if(SouCool>=SouCoolDefault){
		if(Source < SouMAX){
			Source += rise;
		}else{
			Source=SouMAX;
		}
		SouCool=0;
	}
	SouCool+=2;
	SouBarWari=(float)Source/SouMAX;
	Sou_Draw(SouBarWari);
	
}

int Sou_Give(){



	return Source;
}	

void Sou_Update(int SouAdd){
	Source+=SouAdd;	
}

void Sou_Mine(){
		SouCoolDefault=SouCoolDefault-int(SouLevel*3);
		Source-=SouLevel*SouLevel*SouLevel*3;
		SouLevel++;
}

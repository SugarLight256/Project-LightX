#include "DxLib.h"
#include "struct.h"
#include "map.h"
#include <math.h>

#define G 9.8067
#define PI 3.14159265358979
#define Y_MAX 2
#define PSHOT. dataP[i].PEquip[j].dataPS[k].
#define PWEP. dataP[i].PEquip[j].
#define ESHOT. dataE[i].EEquip[j].dataES[k].
#define EWEE. dataE[i].EEquip[j].

extern struct UNITDATAE_t dataE[UNIT_MAX];
extern struct UNITDATAP_t dataP[UNIT_MAX];
double t;
double v0=9.0;
double vx,vy;
int time1,time2;
int speedX;
int speedY;
int Mtime;
double kaku;

int Ex,Ey;
int x,y;

void Shot_Draw(int x,int y,int Graph){

	PDraw(x,y,Graph);

}

int MG_Calc(int speedX,int Graph){

	x += speedX;
	Shot_Draw(x , y , Graph);

}

int Can_Speed(int Ex,int Ey){
	
	double a,b,c,d;
	double t1,t2;
	double kaku1,kaku2,kaku;

	
	a= G * Ex*Ex / (2.0 * v0 * v0);
	b= -Ex;
	c= Ey+a;
	d= b*b - 4.0 * a * c;
	
	if(d<0.0){
		d=0.0;
	}
	
	d = sqrt(d);
	
	t1=(-b + d)/(2.0 * a);
	t2=(-b - d)/(2.0 * a);
	
	kaku1 = atan(t1);
	kaku2 = atan(t2)+PI;
	kaku  = Ex>0? kaku1: kaku2;
	
	vx= v0*cos(kaku);
	vy=-v0*sin(kaku);
}

int Can_Calc(int x,int y,int t,int Graph){ 

	x+=vx * t;
	y+=vy * t + G * t*t / 2;	
	
	Shot_Draw(x,y,Graph);
	
	return y;
}

void Mis_Calc(int Graph){
	double ax,ay,bx,by;
	int bure;
	bure=GetRand(2);
	
	if(Mtime < 80){
    	
		bx = cos(kaku);
		by = sin(kaku);
		ax = (Ex - bure) - x;
		ay = (Ey - bure) - y;
		
		kaku += (ax * by - ay * bx < 0.0)? +PI /180*15: -PI/180*15;
	}	
	speedX += (int)(cos(kaku)*30.0);
	speedY += (int)(sin(kaku)*30.0);
	
	x = (x * 100 + speedX)/100;
	y = (y * 100 + speedY)/100;
	
	PDraw(x,y,Graph);
	
	ax=0;
	ay=0;
	bx=0;
	by=0;
}



int PWeapon_Mgr(int i,int j,int k){
	if(dataP[i].PEquip[j].dataPS[k].y <= dataP[i].y-20 || dataP[i].PEquip[j].dataPS[k].FM <= 1){
		Ex=dataP[i].x+24;
		Ey=dataP[i].y-20;
		dataP[i].PEquip[j].dataPS[k].FM++;
	}else{
		Ex=dataP[i].Ex;
		Ey=dataP[i].Ey;
	}	
	
    Mtime  =dataP[i].PEquip[j].dataPS[k].MTime;
	x     =dataP[i].PEquip[j].dataPS[k].x;
	y     =dataP[i].PEquip[j].dataPS[k].y;
	speedX=dataP[i].PEquip[j].dataPS[k].speedX;
	speedY=dataP[i].PEquip[j].dataPS[k].speedY;
	kaku  =dataP[i].PEquip[j].dataPS[k].kaku;
	
	switch(dataP[i].PEquip[j].dataPS[k].type){
	
		case 1:
			MG_Calc(dataP[i].PEquip[j].dataPS[k].speedX,dataP[i].PEquip[j].dataPS[k].Graph);
			break;
			
		case 2:
		//	Can_Speed(Ex,Ey);
		//	x=Can_Calc(x,y,t,Graph);
			break;
			
		case 3:
			Mis_Calc(dataP[i].PEquip[j].dataPS[k].Graph);
			Mtime++;
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
		
		case 9:
			break;
		
		case 10:
			break;
	}
	dataP[i].PEquip[j].dataPS[k].x = x;
	dataP[i].PEquip[j].dataPS[k].y = y;
	dataP[i].PEquip[j].dataPS[k].speedX=speedX;
	dataP[i].PEquip[j].dataPS[k].speedY=speedY;
	dataP[i].PEquip[j].dataPS[k].kaku=kaku;
	dataP[i].PEquip[j].dataPS[k].MTime=Mtime;
	Ex=0;
	Ey=0;
}

int EWeapon_Mgr(int i,int j,int k){

	x = dataE[i].EEquip[j].dataES[k].x;
    y = dataE[i].EEquip[j].dataES[k].y;
	switch(dataE[i].EEquip[j].dataES[k].type){
		case 1:
			MG_Calc(dataE[i].EEquip[j].dataES[k].speedX,dataE[i].EEquip[j].dataES[k].Graph);
			break;
		case 2:
		//	Can_Speed(Ex,Ey);
		//	x=Can_Calc(x,y,t,Graph);
			break;
		case 3:
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
		case 9:
			break;
		case 10:
			break;
	}
	dataE[i].EEquip[j].dataES[k].x = x;
	dataE[i].EEquip[j].dataES[k].y = y;
}
#include <stdio.h>
#include <stdlib.h>
#include "define.h"

class unit{
	private:
		double x;
		double y;
		double vx;
		double vy;
		double waterRange;
		double normalRange;
		double middleX;
		double middleY;
		double damageSizeX;
		double damageSizeY;
		int flag;
		int graph;
		int HP;
		int maxHP;
		int weaponFlag[WEAPON];
	public:
		class weapon{
			private:
				double x;
				double y;
				double angle;
				int flag;
				int type;
				int graph;
				int cool;
				int range;
				int rangeFlag;
				int bull_max;
				int bull;
			public:
		}
		int get_maxHP();
		void set();
		void reset();
		void move();
		void range();
		void HPcalc();
};
		

class bullet{
	private:
		double x;
		double y;
		double vox;
		double voy;
		double vx;
		double vy;
		double middleX;
		double middleY;
		double angle;
		int graph;
		int damage;
		int flag;
		int PorE;
	public:
		void set();
		void reset();
		void move();
		void damageCalc();
};

int unit::get_maxHP(){
	
	return maxHP;
	
}

int Sort_unit_HP(const void *a, const void *b){
	unit SortA=*(unit*)a;
	unit SortB=*(unit*)b;
	if(SortA.get_maxHP()>SortB.get_maxHP()){
		return 1;
	}else{
		return -1;
	}
}


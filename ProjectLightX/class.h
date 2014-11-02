#ifndef _INC_CLASS
#define _INC_CLASS

#define WEAPON 6

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
		int graph;
		int HP;
		int maxHP;
		int weaponFlag[WEAPON];
	public:
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
		int type;
		int damage;
		int flag;
		int PorE;
	public:
		void set();
		void reset();
		void move();
		void damageCalc();
};

#endif
#ifndef DEF_STRUCT_H
#define DEF_STRUCT_H
#define SHOT_MAX 200
#define UNIT_MAX 200
#define WEP_MAX  15
#define EQUIP_MAX 1
#define ITEM_MAX 10
//#define BOX_MAX 30

struct SHOTDATAP_t{//このヘッダーファイルで構造体を宣言
	int MAXBall;
	int Ball;
    int damage;//攻撃力
    int type;//種類
    int x;//x座標
    int y;//y座標
    double speedX;//速さ
	double speedY;
	double kaku;
	int Graph;
	int CanTime;
	int FM;//ミサイルのためのフラグ
	int MTime;
    int flag;//出現状態のフラグ
};

struct SHOTDATAE_t{//このヘッダーファイルで構造体を宣言
	int MAXBall;
	int Ball;
    int damage;//攻撃力
    int type;//種類
    int x;//x座標
    int y;//y座標
    double speedX;//速さ
	double speedY;
	double kaku;
	int Graph;
	int CanTime;
    int flag;//出現状態のフラグ
};

struct PEQUIP_t{
	int x;
	int w;
	int y;
	int h;
	int flag;
	int type;
	int cool;
	int range;
	int rangeFlag;
	int bull;
	double kakudo;
	struct SHOTDATAP_t dataPS[SHOT_MAX];
};

struct EEQUIP_t{
	int x;
	int w;
	int y;
	int h;
	int flag;
	int type;
	int cool;
	int range;
	int rangeFlag;
	int bull;
	double kakudo;
	struct SHOTDATAE_t dataES[SHOT_MAX];
};

struct UNITDATAP_t{
    int type;//種類
    int in_time;//出現時間
	int w;//画像の幅
	int h;//画像の高さ
    double x;//x座標
    double lx;//一フレーム前のX
    double y;//y座標
    double speed;//速さ
    int HP;//HP
	int MAXHP;
    int item;//アイテム
    int range;//索敵範囲
    int flag;//出現状態のフラグ
    int rangeFlag;//索敵範囲内に敵がいるか
	int Ex;
	int Ey;
    int equip;//装備
	int wepCool[WEP_MAX];
	struct PEQUIP_t PEquip[EQUIP_MAX];
};

struct UNITDATAE_t{
    int type;//種類
    int in_time;//出現時間
	int w;//画像の幅
	int h;//画像の高さ
    double x;//x座標
    double lx;//一フレーム前のX
    double y;//y座標
    double speed;//速さ
    int HP;//HP
	int MAXHP;
    int item;//アイテム
	int add;
    int range;//索敵範囲
    int flag;//出現状態のフラグ
    int rangeFlag;//索敵範囲内に敵がいるか
	int Px;
	int Py;
    int equip;//装備
	int wepCool[WEP_MAX];
	struct EEQUIP_t EEquip[EQUIP_MAX];
};

struct  Weapon_t{
        int type;
		int x;
		int y;
};

struct SlotTag_t{
		int x,y;
        char name[32];
        int type;
		int defense;
		int bull;
		int range;
		int Graph;
		int flag;
		Weapon_t wep[WEP_MAX];
};

typedef struct{
        int x;
		int y;
        char name[128];
} docTag_t;

struct ITEMDATA_t{
	char name[64];
	int num;
	int damage;
	int type;
	int place;
};

#endif
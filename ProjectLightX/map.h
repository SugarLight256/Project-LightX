#pragma once
#include "struct.h"

extern struct UNITDATAP_t dataP[UNIT_MAX];

void Map_Syoki();

void camera_calc();

void map_calc();

void Psyoki();

void Esyoki();

void cam_Move();

void Map_Draw();

void PDraw(int x,int y,int Graph);

void EDraw(int x,int y,int Graph);

int Stop(int x);

int DrawX(int x);
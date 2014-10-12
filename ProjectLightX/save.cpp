#include <stdio.h>
#include "doc.h"

extern struct SlotTag_t Box[BOX_MAX];

void BoxSave(){

	FILE *fpw = fopen("Box.dat","wba");
	
	fwrite(&Box,sizeof(Box),1,fpw);
	
	fclose(fpw);

}
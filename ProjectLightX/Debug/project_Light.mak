#-------------------------------------------------------
# BCC Developer 1.2.21
# Copyright (C) 2003 jun_miura@hi-ho.ne.jp
#-------------------------------------------------------
.autodepend
CC=bcc32
RC=brc32
CFLAG=-W  -3 -Od -w- -AT -pc -H- -k -b -v -y  -DDEBUG
OUTDIR=-nDebug
CINCS=
TARGET=Debug\project_Light.exe
SRC1="G:\working\BCC developper\bccdev1221\Daichi\project_Light\enemy.cpp"
OBJ1=Debug\enemy.obj
SRC2="G:\working\BCC developper\bccdev1221\Daichi\project_Light\player.cpp"
OBJ2=Debug\player.obj
SRC3="G:\working\BCC developper\bccdev1221\Daichi\project_Light\map.cpp"
OBJ3=Debug\map.obj
SRC4="G:\working\BCC developper\bccdev1221\Daichi\project_Light\panel.cpp"
OBJ4=Debug\panel.obj
SRC5="G:\working\BCC developper\bccdev1221\Daichi\project_Light\icon.cpp"
OBJ5=Debug\icon.obj
SRC6="G:\working\BCC developper\bccdev1221\Daichi\project_Light\game.cpp"
OBJ6=Debug\game.obj
SRC7="G:\working\BCC developper\bccdev1221\Daichi\project_Light\Pshot.cpp"
OBJ7=Debug\Pshot.obj
SRC8="G:\working\BCC developper\bccdev1221\Daichi\project_Light\Eshot.cpp"
OBJ8=Debug\Eshot.obj
SRC9="G:\working\BCC developper\bccdev1221\Daichi\project_Light\config.cpp"
OBJ9=Debug\config.obj
SRC10="G:\working\BCC developper\bccdev1221\Daichi\project_Light\menu.cpp"
OBJ10=Debug\menu.obj
SRC11="G:\working\BCC developper\bccdev1221\Daichi\project_Light\main.cpp"
OBJ11=Debug\main.obj
SRC12="G:\working\BCC developper\bccdev1221\Daichi\project_Light\gamenMgr.cpp"
OBJ12=Debug\gamenMgr.obj
SRC13="G:\working\BCC developper\bccdev1221\Daichi\project_Light\Unit.cpp"
OBJ13=Debug\Unit.obj
SRC14="G:\working\BCC developper\bccdev1221\Daichi\project_Light\coll.cpp"
OBJ14=Debug\coll.obj

TARGET: $(TARGET)

$(TARGET): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6) $(OBJ7) $(OBJ8) $(OBJ9) $(OBJ10) $(OBJ11) $(OBJ12) $(OBJ13) $(OBJ14)
    $(CC) $(CFLAG) -e$(TARGET) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6) $(OBJ7) $(OBJ8) $(OBJ9) $(OBJ10) $(OBJ11) $(OBJ12) $(OBJ13) $(OBJ14)

$(OBJ1): $(SRC1)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC1)

$(OBJ2): $(SRC2)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC2)

$(OBJ3): $(SRC3)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC3)

$(OBJ4): $(SRC4)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC4)

$(OBJ5): $(SRC5)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC5)

$(OBJ6): $(SRC6)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC6)

$(OBJ7): $(SRC7)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC7)

$(OBJ8): $(SRC8)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC8)

$(OBJ9): $(SRC9)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC9)

$(OBJ10): $(SRC10)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC10)

$(OBJ11): $(SRC11)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC11)

$(OBJ12): $(SRC12)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC12)

$(OBJ13): $(SRC13)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC13)

$(OBJ14): $(SRC14)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC14)

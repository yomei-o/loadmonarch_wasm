// Compose the Progress Window with numbers in its slots, to check the layout.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/host.h"
#include "../src/world.h"
#define W 176
#define H 176
static unsigned char px[H][W];
static const World *gw;
static void blit(int sx,int sy,int bw,int bh,int dx,int dy){
    for(int y=0;y<bh;y++)for(int x=0;x<bw;x++){
        int ax=sx+x,ay=sy+y,tx=dx+x,ty=dy+y;
        if(ax<0||ay<0||ax>=UI_SHEET_W||ay>=UI_SHEET_H)continue;
        if(tx<0||ty<0||tx>=W||ty>=H)continue;
        unsigned char v=gw->ui.pixels[(size_t)ay*UI_SHEET_W+ax];
        if(v!=UI_TRANSPARENT)px[ty][tx]=v;
    }
}
static void number(unsigned value,int right,int y){
    char t[16]; snprintf(t,sizeof t,"%u",value);
    int n=(int)strlen(t);
    for(int i=0;i<n;i++){int d=t[n-1-i]-'0'; blit(d*8,0,8,16,right-(i+1)*8,y);}
}
int main(int argc,char**argv){
    static Host h; FILE*f=fopen("ds7e.zip","rb"); fseek(f,0,SEEK_END); long s=ftell(f);
    fseek(f,0,SEEK_SET); unsigned char*a=malloc(s); fread(a,1,s,f); fclose(f);
    hostUseZip(&h,a,(unsigned)s);
    static World w; char m[256];
    if(!worldLoadStage(&w,&h,"B_003.MAP",m,sizeof m)){puts(m);return 1;}
    gw=&w;
    memset(px,UI_TRANSPARENT,sizeof px);
    blit(0,288,W,H,0,0);
    // the top bar filled to a third, by copying the gradient below it up
    blit(24,288+26,128/3,6,24,16);
    number(4868,80,40);        // funds, by the money bag
    number(17,144,40);         // tax, by the per-cent sign
    number(842,80,104);        // days, by the sun
    number(2158,144,104);      // days left, by the hourglass
    FILE*o=fopen(argc>1?argv[1]:"tests/pw.ppm","wb");
    fprintf(o,"P6\n%d %d\n255\n",W,H);
    for(int y=0;y<H;y++)for(int x=0;x<W;x++){
        unsigned char v=px[y][x];
        const unsigned char*rgb=(v>=0x80&&v<0xb0)?w.ui.palette[v]:w.bank32.palette[v];
        fwrite(rgb,1,3,o);
    }
    fclose(o); puts("ok"); return 0;
}

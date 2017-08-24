#include<reg52.h> 
unsigned int pwm; 
unsigned char flag; 
sbit p10=P1^0;  
void timer0() interrupt 1 using 1  
{   
p10=!p10;  
pwm=20000-pwm;  
TH0=pwm/256;  
TL0=pwm%256;  
flag++;   
if(flag<10)flag++;   
if(flag==10&&p10==0){pwm=1250;flag=11;}//保证回到90度再左转15；
 }   
void timer1() interrupt 3 using 1  
{   
ET1=0;//2ms到关闭定时器1  
ET0=0;  
TR0=0;  
pwm=1750;  
TH0=pwm/256;  
TL0=pwm%256;  
ET0=1;  
TR0=1;  
}   
void int0(void) interrupt 0 using 1 
{   
//判断左转到15，通过传感器判断或者其他信号判断 ，能正好保证刚左转15度，开始延时2ms  
TR1=1;//定时器1开始计数  
}  
void main(void) 
{  
p10=1; 
TMOD=0x11;  pwm=1500;//回90度  
TH0=pwm/256;  TL0=pwm%256;  
TH1=2000/256;  TL1=2000%256;  
EA=1;  
ET0=1;  
ET1=1;  
TR0=1;  
while(1); 
}

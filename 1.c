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
if(flag==10&&p10==0){pwm=1250;flag=11;}//��֤�ص�90������ת15��
 }   
void timer1() interrupt 3 using 1  
{   
ET1=0;//2ms���رն�ʱ��1  
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
//�ж���ת��15��ͨ���������жϻ��������ź��ж� �������ñ�֤����ת15�ȣ���ʼ��ʱ2ms  
TR1=1;//��ʱ��1��ʼ����  
}  
void main(void) 
{  
p10=1; 
TMOD=0x11;  pwm=1500;//��90��  
TH0=pwm/256;  TL0=pwm%256;  
TH1=2000/256;  TL1=2000%256;  
EA=1;  
ET0=1;  
ET1=1;  
TR0=1;  
while(1); 
}

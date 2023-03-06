//Main file: 

#include <lpc213x.h> 
#include "GSM1.c" 
#define bit(x) (1<<x) 
/* ------- PIR --------*/ 
#define PIR (IO1PIN & (1<<24)) 
/* ------- LCD --------*/ 
void lcd_int(void); 
void cmd(unsigned char a); 
void dat(unsigned char b); 
void show(unsigned char *s); 
void lcd_delay(void); 
/* ------- Main --------*/ 
int main() 
{ 
IO0DIR =0XFFF; 
IO1DIR = 0x0; 
lcd_int(); 
cmd(0x80); 
show("checking system "); 
while(1) 
{ 
if(PIR == 1) 
{ 
show("Theft Detection!"); 
show("Engine Stop."); 
theft(); 
} 
else 
{ 
show("Car is safe"); 
} 
} 
}
/* ------- LCD Function --------*/ 
void lcd_int() 
{ 
cmd(0x38); 
cmd(0x0c); 
cmd(0x06); 
cmd(0x01); 
cmd(0x80); 
} 
void cmd(unsigned char a) 
{ 
IO0PIN&=0x00; 
IO0PIN|=(a<<0); 
IO0CLR|=bit(8); //rs=0 IO0CLR|=bit(9); //rw=0 IO0SET|=bit(10); //en=1 delay(10); 
IO0CLR|=bit(10); //en=0 } 
void dat(unsigned char b) 
{ 
IO0PIN&=0x00; 
IO0PIN|=(b<<0); 
IO0SET|=bit(8); //rs=1 IO0CLR|=bit(9); //rw=0 IO0SET|=bit(10); //en=1 delay(10); 
IO0CLR|=bit(10); //en=0 } 
void show(unsigned char *s) 
{ 
while(*s!='\0') 
{ 
dat(*s++); 
} 
}


//GSM file: 

#include "lpc213x.h" 
#include "stdio.h" 
#include "string.h" 
#include "uart0.c" 
void delay(unsigned int time) 
{ 
unsigned int i,j; 
for(i=0;i<time;i++) 
for(j=0;j<5000;j++); 
} 
void GSM_cmd(unsigned char *cmd) //send gsm commands to UART1 
{ 
printf("\n\ncommand: %s",cmd); 
UART1_PutS(cmd); 
delay(100); 
} 
void theft(void) 
{ 
unsigned char * msg = "THEFT DETECTED\r"; 
unsigned char *msg1= "Engine Stop\r"; 
Uart0Init(); //UART0 initialised to display command and responses on terminal //printf("GSM program\n"); 
Uart1_Init(); 
while(1) 
{ 
printf("\n"); 
GSM_cmd("ATD7385301891;\r"); //Call or dial write 10 digit mobile number delay(10000); 
printf("\n"); 
GSM_cmd("ATH0\r"); //disconnect call 
delay(10000); 
printf("\n");
GSM_cmd("AT+CMGF=1\r"); //Send SMS: Select Text mode :1 
// PDU mode :0 
delay(1000); 
printf("\n"); 
GSM_cmd("AT+CMGS=\"7385301891\"\r"); //To send SMS to a 10 digit mobile number delay(9000); 
UART1_PutS(msg); //actually Sends message 
delay(1000); 
UART1_PutS(msg1); //actually Sends message 
delay(1000); 
UART1_PutChar(0x1A); 
GSM_cmd("AT+COPS?\r"); //To know the service provider of SIM inserted delay(3000); 
printf("\n"); 
} 
// return 0; 
} 


//UART0: 

#include <lpc213x.h> 
unsigned char UART0_PutChar(unsigned char Ch) 
{ 
if (Ch == '\n') 
{ 
while (!(U0LSR & 0x20)); 
U0THR = 0x0D; 
} 
while(!(U0LSR & 0x20)); 
return(U0THR = Ch); 
} 
unsigned char UART1_GetChar(void) 
{
while(!(U1LSR & 0x01)); 
return(U1RBR); 
} 
void UART1_isr(void) __irq 
{ 
UART0_PutChar(UART1_GetChar()); VICVectAddr = 0; 
} 
void Uart0Init() 
{ 
PINSEL0 |= 0X05; 
U0FCR = 0X07; 
U0LCR = 0X83; 
U0DLL = 0X62; 
U0DLM = 0; 
U0LCR = 0X03; 
} 
void Uart1_Init() 
{ 
PINSEL0 |= 0x00050000; 
U1FCR = 0X07; 
U1LCR = 0x83; 
U1DLL = 0X62; 
U1DLM = 0; 
U1LCR = 0x03; 
U1IER = 0x01; 
VICVectCntl1 = 0x20 | 7; 
VICVectAddr1 = (unsigned int)UART1_isr; VICIntEnable |= 1<<7; 
} 
unsigned char UART1_PutChar(unsigned char Ch) { 
while(!(U1LSR & 0x20));
if(Ch == '\n') 
Ch = 0x0D; 
U1THR = Ch; 
return Ch; 
} 
void UART1_PutS(unsigned char *Ch) { 
while(*Ch) 
UART1_PutChar(*Ch++);
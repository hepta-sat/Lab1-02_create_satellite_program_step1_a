#include "mbed.h"
DigitalOut condition(LED1);
RawSerial gs(USBTX,USBRX,9600);
Timer sattime;
int main()
{
    gs.printf("From Sat : Nominal Operation\r\n");
    int flag = 0; //condition flag
    float batvol, temp; //voltage, temperature 
    sattime.start();
    for(int i=0;i<50;i++){
        //satellite condition led
        condition = !condition;
        
        //senssing HK data(dummy data)
        batvol = 3.7;
        temp   = 28.5;
        
        //Transmitting HK data to Ground Station(GS)
        gs.printf("HEPTASAT::Condition = %d, Time = %f [s], batvol = %2f [V], temp = %2f [deg C]\r\n",flag,sattime.read(),batvol,temp);
        wait_ms(1000);
    }
    sattime.stop();
    gs.printf("From Sat : End of operation\r\n");
}

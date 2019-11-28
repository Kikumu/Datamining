#include <stdio.h>
#include <stdlib.h>
#include "SystemHeader.h"
#include "LCD_driver.h"
#include "Thermometer_driver.h"
#include "clock_driver.h"


void main() {
    TRISB=0X02;  
    set_time();
    ds1302_init();
    //Button drivers
    
    while(1){
    init();
    lcd_init();    
    init_temp(); 
    get_temp();
    write_char('T');
    write_char('e');
    write_char('m');
    write_char('p');
    write_char(':');
     
    display_temp();
    get_time();
    write_cmd(0x90);
    write_char('D');
    write_char('a');
    write_char('t');
    write_char('e');
    write_char(':');
    write_char(' ');
    
    display_date();
    write_cmd(0x88);
    write_char('T');
    write_char('i');
    write_char('m');
    write_char('e');
    write_char(':');
    display_clock();
    delay_lcd();
    }
    
}


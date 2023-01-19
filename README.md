# LPS25H-stm32-driver

1- include .h file in main.c

2- sensor connect to hi2c1 com. port

3- add init func. in main

      LPS25H_init();
    
4- use pressure data func like this(in loop)

      pressure = read_data_pressure();
      
      
5- use temp data func like this(in loop)

    temp = read_data_temp();

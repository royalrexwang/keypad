#include <project.h>
#include <stdlib.h>
#include <math.h>

uint16 read();
uint16 scan();
int main()
{
    LCD_Char_1_Start();  
    
    while(1){
    uint16 Number = 0;
    uint16 key = 0 ;
    key = scan();
    
    if(key == 13){
            LCD_Char_1_Position (0,0);
            LCD_Char_1_PrintString(" n:");
            while(1){
                key = scan();
                if (key == 1) //If Button 1 is pressed
                {   LCD_Char_1_Position(1,0);
                    LCD_Char_1_PrintString("B 1"); 
                    if (Number==0)Number=1;
                    else Number = Number*10 + 1; //Pressed twice
                    while(1){
                        key = scan();
                        if(key == 0)break;
                    }
                    LCD_Char_1_Position (0,8);
                    LCD_Char_1_PrintNumber(Number);
                    }
                
                 if (key == 5) //If Button 2 is pressed
                {   LCD_Char_1_Position(1,0);
                    LCD_Char_1_PrintString("B 2"); 
                if (Number==0)Number=2;
                else Number = Number*10 + 2; //Pressed twice
                while(1){
                        key = scan();
                        if(key == 0)break;
                    }
                }
                
                 if (key == 9) //If Button 3 is pressed
                {   LCD_Char_1_Position(1,0);
                    LCD_Char_1_PrintString("B 3"); 
                if (Number==0)Number=3;
                else Number = Number*10 + 3; //Pressed twice
                while(1){
                        key = scan();
                        if(key == 0)break;
                    }
                }
              
                if (key == 2) //If Button 4 is pressed
                {   LCD_Char_1_Position(1,0);
                    LCD_Char_1_PrintString("B 4"); 
                if (Number==0)Number=4;
                else Number = Number*10 + 4; //Pressed twice
                while(1){
                        key = scan();
                        if(key == 0)break;
                    }
                }
                
                 if (key == 6) //If Button 5 is pressed
                {   LCD_Char_1_Position(1,0);
                    LCD_Char_1_PrintString("B 5"); 
                if (Number==0)Number=5;
                else Number = Number*10 + 5; //Pressed twice
                while(1){
                        key = scan();
                        if(key == 0)break;
                    }
                }
                
                 if (key == 3) //If Button 6 is pressed
                {   LCD_Char_1_Position(1,0);
                    LCD_Char_1_PrintString("B 6"); 
                if (Number==0) Number=6;
                else Number = Number*10 + 6; //Pressed twice
                while(1){
                        key = scan();
                        if(key == 0)break;
                    }
                }
                
                 if (key == 10) //If Button 7 is pressed
                {   LCD_Char_1_Position(1,0);
                    LCD_Char_1_PrintString("B 7"); 
                if (Number==0)Number=7;
                else Number = Number*10 + 7; //Pressed twice
                while(1){
                        key = scan();
                        if(key == 0)break;
                    }
                }   
                if (key == 7) //If Button 8 is pressed
                {   LCD_Char_1_Position(1,0);
                    LCD_Char_1_PrintString("B 8"); 
                if (Number==0)Number=8;
                else Number = Number*10 + 8; //Pressed twice
                while(1){
                        key = scan();
                        if(key == 0)break;
                    }
                }
                
                if (key == 11) //If Button 9 is pressed
                {   LCD_Char_1_Position(1,0);
                    LCD_Char_1_PrintString("B 9"); 
                if (Number==0)Number=9;
                else Number = Number*10 + 9; //Pressed twice
                while(1){
                        key = scan();
                        if(key == 0)break;
                    }
                }
                if (key == 8) //If Button 0 is pressed
                {   LCD_Char_1_Position(1,0);
                    LCD_Char_1_PrintString("B 0"); 
                if (Number==0) Number=0;
                else Number = Number*10; //Pressed twice
                while(1){
                        key = scan();
                        if(key == 0)break;
                    }
                }
                if (key == 12) //If Button ENTER is pressed
                {   LCD_Char_1_Position(1,0);
                    LCD_Char_1_PrintString("B Enter"); 
                    Number = Number*1;
                    break;
                }
                if(key == 4)
                {   LCD_Char_1_Position(1,0);
                    LCD_Char_1_PrintString("B Detele"); 
                    Number = 0;
                    break;
                }
            LCD_Char_1_Position (0,5);
            LCD_Char_1_PrintNumber(Number);
            }
            
        
    
    LCD_Char_1_Position (0,0);
    LCD_Char_1_PrintNumber(Number);
    
      }  
    }
    return 0;
}

uint16 scan(){
    
    uint16 KeyValue = 0;
   //初始置高电位
    Pin_1_Write(1);
    Pin_2_Write(1);
    Pin_3_Write(1);
    Pin_4_Write(1);
    Pin_5_Write(0);
    Pin_6_Write(0);
    Pin_7_Write(0);
    Pin_8_Write(0);
  if(read() != 240){//列扫描，判断是否被按下
    CyDelay(10);
    Pin_1_Write(1);
    Pin_2_Write(1);
    Pin_3_Write(1);
    Pin_4_Write(1);
    Pin_5_Write(0);
    Pin_6_Write(0);
    Pin_7_Write(0);
    Pin_8_Write(0);
       
    LCD_Char_1_Position (0,12);
    LCD_Char_1_PrintNumber(read());
        if(read() != 240){//00001111--->15
             switch (read()) { 
                case 112: KeyValue = 1;  break;//1110000
                case 176: KeyValue = 2;  break;//10110000
                case 208: KeyValue = 3;  break;//11010000
                case 224: KeyValue = 4;  break;//1110000
                }
        //置高点位
        Pin_1_Write(0);
        Pin_2_Write(0);
        Pin_3_Write(0);
        Pin_4_Write(0);
        Pin_5_Write(1);
        Pin_6_Write(1);
        Pin_7_Write(1);
        Pin_8_Write(1);
        //CyDelay(100);
     
        LCD_Char_1_Position (1,12);
        LCD_Char_1_PrintNumber(read());
        if(read() != 15){
            CyDelay(10);
        switch (read()) {
             case 7: KeyValue = KeyValue;  break;//111
             case 11: KeyValue = KeyValue + 4;  break;//1011
             case 13: KeyValue = KeyValue + 8;  break;//1101
             case 14: KeyValue = KeyValue + 12;  break;//1110
             }
        }
      while (read() != 15);//松手检测
    }
  }
return KeyValue;
}

uint16 read(){
    uint16 read_number;
    read_number = Pin_1_Read()*pow(2,7)+Pin_2_Read()*pow(2,6)+Pin_3_Read()*pow(2,5)+Pin_4_Read()*pow(2,4)+Pin_5_Read()*pow(2,3)+Pin_6_Read()*pow(2,2)+Pin_7_Read()*pow(2,1)+Pin_8_Read();
    return read_number;
}

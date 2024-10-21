#include <Arduino.h>
#include <expressions.h>
#include <SPI.h>
#include <U8g2lib.h>

#include "ScreenManager.h"

#define OLED_CS 5
#define OLED_DC 2
#define OLED_RESET 4

U8G2_SSD1309_128X64_NONAME0_F_4W_HW_SPI u8g2(U8G2_R0, OLED_CS, OLED_DC, OLED_RESET);

#define UP_BUTTON 32
#define BACK_BUTTON 33
#define SELECT_BUTTON 34
#define DOWN_BUTTON 35

ScreenManager screenManager; // Create an instance of ScreenManager
int n=0;

void setup()
{
  pinMode(UP_BUTTON, INPUT);
  pinMode(BACK_BUTTON, INPUT);
  pinMode(SELECT_BUTTON, INPUT);
  pinMode(DOWN_BUTTON, INPUT);

  u8g2.begin();
  screenManager.initialize(); // Initialize your screen manager and load all screens
}

void loop()
{/*
  if(n=1000000){
    
  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_coming_out_1); 
  u8g2.sendBuffer(); 
    
  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_coming_out_2); 
  u8g2.sendBuffer(); 

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_happy); 
  u8g2.sendBuffer(); 
  delay(1500);

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_blinking); 
  u8g2.sendBuffer(); 

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_happy); 
  u8g2.sendBuffer(); 
  delay(2500);
  for(int t = 0; t < 6; t++){
  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_up_looking_1); 
  u8g2.sendBuffer(); 
    
  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_up_looking_2); 
  u8g2.sendBuffer(); 
  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_up_looking_1); 
  u8g2.sendBuffer(); 
    
  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_happy); 
  u8g2.sendBuffer(); 
  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_down_looking_1); 
  u8g2.sendBuffer(); 
    
  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_down_looking_2); 
  u8g2.sendBuffer(); 
  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_down_looking_1); 
  u8g2.sendBuffer(); 

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_happy); 
  u8g2.sendBuffer(); 
  }
  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_happy); 
  u8g2.sendBuffer(); 
  delay(500);

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_bored_but_happy); 
  u8g2.sendBuffer(); 
  delay (1500);
   
  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_blinking); 
  u8g2.sendBuffer(); 

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_bored_but_happy); 
  u8g2.sendBuffer();
  delay(1500);

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_happy); 
  u8g2.sendBuffer(); 
  delay(700);

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_right_looking_1); 
  u8g2.sendBuffer(); 

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_right_looking_2); 
  u8g2.sendBuffer(); 
  delay(800);
    
  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_right_looking_1); 
  u8g2.sendBuffer(); 

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_happy); 
  u8g2.sendBuffer(); 

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_left_looking_1); 
  u8g2.sendBuffer(); 

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_left_looking_2); 
  u8g2.sendBuffer(); 
  delay(800);
    
  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_left_looking_1); 
  u8g2.sendBuffer(); 

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_happy); 
  u8g2.sendBuffer(); 
  delay(1700);

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_bored_but_happy); 
  u8g2.sendBuffer(); 

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_really_bored); 
  u8g2.sendBuffer(); 
  delay(1500);

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_blinking_bored); 
  u8g2.sendBuffer(); 

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_really_bored); 
  u8g2.sendBuffer(); 
  delay(2200);

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_blinking_bored); 
  u8g2.sendBuffer(); 

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_really_bored); 
  u8g2.sendBuffer(); 
  delay(1500);

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_going_out_1); 
  u8g2.sendBuffer(); 

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_going_out_2); 
  u8g2.sendBuffer(); 

  u8g2.clearBuffer();
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_empty ); 
  u8g2.sendBuffer(); // send buffer from RAM to display controller 
   u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_really_bored); 
  u8g2.sendBuffer(); 
  delay(1500);

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_going_out_1); 
  u8g2.sendBuffer(); 

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_going_out_2); 
  u8g2.sendBuffer(); 

  u8g2.clearBuffer();
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_empty ); 
  u8g2.sendBuffer(); // send buffer from RAM to display controller 
   u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_really_bored); 
  u8g2.sendBuffer(); 
  delay(1500);

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_going_out_1); 
  u8g2.sendBuffer(); 

  u8g2.clearBuffer();  
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_going_out_2); 
  u8g2.sendBuffer(); 

  u8g2.clearBuffer();
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_empty ); 
  u8g2.sendBuffer(); // send buffer from RAM to display controller 
  n=0;
  } */
  screenManager.handleInput();              // Handle user input
  screenManager.displayCurrentScreen(u8g2); // Display the current screen
  //n=n+1;
}

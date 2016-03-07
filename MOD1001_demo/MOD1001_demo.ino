/*
Copyright (c) 2016, Embedded Adventures
All rights reserved.
Contact us at source [at] embeddedadventures.com
www.embeddedadventures.com
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
- Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.
- Neither the name of Embedded Adventures nor the names of its contributors
  may be used to endorse or promote products derived from this software
  without specific prior written permission.
 
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
THE POSSIBILITY OF SUCH DAMAGE.
*/

// TMP275 MOD-1001 RTC and Temperature Sensor Arduino test sketch
// Written originally by Embedded Adventures

#include <TMP275.h>
#include <M41T81S.h>
#include <Wire.h>

int sec, mins, hrs, dow, date, month, year, psec;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  while(!Serial) {};
  tmp275.init();
  rtc.init();
  
  //Set the time
  /*rtc.setYear(16);
  rtc.setMonth(3);
  rtc.setDate(7);
  rtc.setDayOfWeek(2);
  rtc.setHours(13);
  rtc.setMinutes(11);
  rtc.setSeconds(10);*/
  
  Serial.println("Welcome to the MOD-1001 (TMP275) RTC and Temp Sensor test sketch!");
  Serial.println("Embedded Adventures (www.embeddedadventures.com)\n");
  tmp275.setResolution(4);
  tmp275.enableShutdownMode(true);
}

//Loop measures temperature in shutdown mode, so a one-shot reading is performed
void loop() {
  updateClock();
  print_serial();
  tempOneShot();
  delay(2000);
}

void tempOneShot() { 
  tmp275.enableOS();
  Serial.print("Temperature, Celsius:\t");
  Serial.println(tmp275.getTemperature());
}


void updateClock() { 
  psec = rtc.getPartSeconds(); 
  sec = rtc.getSeconds();

  mins = rtc.getMinutes();
  hrs = rtc.getHours();
  dow = rtc.getDayOfWeek();
  date = rtc.getDate();
  month = rtc.getMonth();
  year = rtc.getYear();
}

void print_serial() {
  Serial.println("hrs:mins:sec:ms - ");
  Serial.print(hrs);
  Serial.print(":");
  Serial.print(mins);
  Serial.print(":");
  Serial.print(sec);
  Serial.print(":");
  Serial.println(psec);
  Serial.println();
}



/*

Copyright (c) 2015, Embedded Adventures
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

// M41T81S MOD-1005 real-time clock Arduino test sketch
// Written originally by Embedded Adventures

#include <Wire.h>
#include <MOD1005.h>

int sec, mins, hrs, dow, date, month, year, psec, previous;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("Embedded Adventures MOD-1005 real-time clock test sketch");
  Serial.println("Embedded Adventures (embeddedadventures.com)");
  mod1005.init();
  mins = 13;
}

void loop() {
  updateClock();
  print_serial();
  delay(500);
}

void updateClock() { 
  psec = mod1005.getPartSeconds(); 
  sec = mod1005.getSeconds();
  mins = mod1005.getMinutes();
  hrs = mod1005.getHours();
  dow = mod1005.getDayOfWeek();
  date = mod1005.getDate();
  month = mod1005.getMonth();
  year = mod1005.getYear();
}

void print_serial() {
  Serial.println("Showing time - ");
  Serial.print(hrs);
  Serial.print(":");
  Serial.print(mins);
  Serial.print(":");
  Serial.print(sec);
  Serial.print(":");
  Serial.println(psec);
}


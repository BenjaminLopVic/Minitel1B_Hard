////////////////////////////////////////////////////////////////////////
/*
   Portrait - Version du 24 avril 2022 à 00h50
   Copyright 2017-2022 - Eric Sérandour
   
   Attention : Ce programme fonctionne bien sur un ATMega 1284P.
   Sur un microcontrôleur qui dispose de moins de mémoire,
   il pourrait ne pas fonctionner correctement.
   
   Documentation utilisée :
   Spécifications Techniques d'Utilisation du Minitel 1B
   http://543210.free.fr/TV/stum1b.pdf
   
////////////////////////////////////////////////////////////////////////
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program. If not, see <http://www.gnu.org/licenses/>.
   
////////////////////////////////////////////////////////////////////////
  DEBUT DU PROGRAMME (Compile sous Arduino 1.8.15)
*///////////////////////////////////////////////////////////////////////

#include <Minitel1B_Hard.h>  // Voir https://github.com/eserandour/Minitel1B_Hard
// Minitel minitel(Serial);  // Le premier port série matériel de l'ATMega 1284P (RXD0 TXD0).
Minitel minitel(Serial1);    // Le deuxième port série matériel de l'ATMega 1284P (RXD1 TXD1).

////////////////////////////////////////////////////////////////////////

#include <avr/pgmspace.h>
typedef unsigned char PROGMEM prog_uchar;
const int LONGUEUR_TRAME_PORTRAIT = 4802;
const prog_uchar PORTRAIT[] PROGMEM = {0x0C,0x0E,0x1B,0x42,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x27,0x1B,0x46,0x1B,0x56,0x27,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x27,0x1B,0x46,0x1B,0x56,0x27,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x53,0x3F,0x1B,0x43,0x1B,0x53,0x3F,0x1B,0x43,0x1B,0x53,0x2B,0x1B,0x43,0x1B,0x53,0x23,0x1B,0x43,0x1B,0x53,0x67,0x1B,0x46,0x1B,0x53,0x68,0x1B,0x41,0x1B,0x56,0x7C,0x1B,0x41,0x1B,0x55,0x3F,0x1B,0x41,0x1B,0x55,0x6F,0x1B,0x41,0x1B,0x55,0x3F,0x1B,0x41,0x1B,0x51,0x2F,0x1B,0x41,0x1B,0x52,0x3F,0x1B,0x41,0x1B,0x52,0x27,0x1B,0x41,0x1B,0x52,0x2B,0x1B,0x41,0x1B,0x56,0x2F,0x1B,0x41,0x1B,0x56,0x2B,0x1B,0x41,0x1B,0x52,0x2F,0x1B,0x41,0x1B,0x56,0x7F,0x1B,0x45,0x1B,0x56,0x30,0x1B,0x46,0x1B,0x56,0x6B,0x1B,0x46,0x1B,0x56,0x23,0x1B,0x46,0x1B,0x56,0x6B,0x1B,0x46,0x1B,0x56,0x2B,0x1B,0x46,0x1B,0x56,0x6B,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x6B,0x1B,0x46,0x1B,0x56,0x2B,0x1B,0x42,0x1B,0x56,0x2B,0x1B,0x42,0x1B,0x52,0x28,0x1B,0x42,0x1B,0x52,0x6B,0x1B,0x42,0x1B,0x52,0x6B,0x1B,0x46,0x1B,0x56,0x27,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x27,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x53,0x37,0x1B,0x43,0x1B,0x53,0x77,0x1B,0x43,0x1B,0x53,0x33,0x1B,0x43,0x1B,0x53,0x3F,0x1B,0x43,0x1B,0x53,0x3F,0x1B,0x41,0x1B,0x53,0x68,0x1B,0x41,0x1B,0x55,0x37,0x1B,0x45,0x1B,0x52,0x27,0x1B,0x45,0x1B,0x56,0x2B,0x1B,0x45,0x1B,0x53,0x23,0x1B,0x45,0x1B,0x53,0x23,0x1B,0x42,0x1B,0x56,0x23,0x1B,0x42,0x1B,0x56,0x23,0x1B,0x42,0x1B,0x56,0x23,0x1B,0x46,0x1B,0x56,0x60,0x1B,0x42,0x1B,0x56,0x78,0x1B,0x45,0x1B,0x52,0x68,0x1B,0x41,0x1B,0x52,0x28,0x1B,0x41,0x1B,0x52,0x7F,0x1B,0x46,0x1B,0x56,0x30,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x6C,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x6B,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x42,0x1B,0x52,0x28,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x3F,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x23,0x1B,0x46,0x1B,0x56,0x23,0x1B,0x46,0x1B,0x53,0x7F,0x1B,0x43,0x1B,0x53,0x37,0x1B,0x43,0x1B,0x53,0x37,0x1B,0x43,0x1B,0x53,0x77,0x1B,0x43,0x1B,0x53,0x7F,0x1B,0x41,0x1B,0x52,0x68,0x1B,0x45,0x1B,0x52,0x37,0x1B,0x42,0x1B,0x56,0x23,0x1B,0x46,0x1B,0x56,0x3F,0x1B,0x46,0x1B,0x56,0x3F,0x1B,0x46,0x1B,0x53,0x2F,0x1B,0x46,0x1B,0x53,0x2B,0x1B,0x46,0x1B,0x56,0x27,0x1B,0x46,0x1B,0x56,0x2B,0x1B,0x46,0x1B,0x56,0x28,0x1B,0x42,0x1B,0x56,0x28,0x1B,0x42,0x1B,0x52,0x6B,0x1B,0x45,0x1B,0x52,0x68,0x1B,0x41,0x1B,0x55,0x68,0x1B,0x45,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x6F,0x1B,0x46,0x1B,0x56,0x6F,0x1B,0x46,0x1B,0x56,0x28,0x1B,0x46,0x1B,0x56,0x6F,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x7B,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x52,0x6B,0x1B,0x42,0x1B,0x52,0x6B,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x3F,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x3F,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x53,0x7F,0x1B,0x43,0x1B,0x53,0x77,0x1B,0x43,0x1B,0x53,0x7F,0x1B,0x43,0x1B,0x53,0x7C,0x1B,0x43,0x1B,0x53,0x68,0x1B,0x45,0x1B,0x55,0x74,0x1B,0x42,0x1B,0x52,0x37,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x53,0x70,0x1B,0x46,0x1B,0x53,0x78,0x1B,0x46,0x1B,0x56,0x30,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x42,0x1B,0x56,0x78,0x1B,0x42,0x1B,0x52,0x28,0x1B,0x42,0x1B,0x52,0x6B,0x1B,0x41,0x1B,0x55,0x68,0x1B,0x41,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x28,0x1B,0x46,0x1B,0x56,0x20,0x1B,0x46,0x1B,0x56,0x7B,0x1B,0x46,0x1B,0x56,0x28,0x1B,0x46,0x1B,0x56,0x6F,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x28,0x1B,0x46,0x1B,0x56,0x6F,0x1B,0x42,0x1B,0x56,0x6B,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x30,0x1B,0x46,0x1B,0x53,0x77,0x1B,0x43,0x1B,0x53,0x37,0x1B,0x43,0x1B,0x53,0x33,0x1B,0x43,0x1B,0x53,0x77,0x1B,0x46,0x1B,0x53,0x28,0x1B,0x41,0x1B,0x55,0x27,0x1B,0x42,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x42,0x1B,0x56,0x70,0x1B,0x45,0x1B,0x56,0x70,0x1B,0x45,0x1B,0x56,0x70,0x1B,0x45,0x1B,0x56,0x70,0x1B,0x42,0x1B,0x56,0x74,0x1B,0x45,0x1B,0x56,0x70,0x1B,0x41,0x1B,0x56,0x70,0x1B,0x41,0x1B,0x52,0x7C,0x1B,0x41,0x1B,0x52,0x7C,0x1B,0x41,0x1B,0x52,0x70,0x1B,0x45,0x1B,0x55,0x78,0x1B,0x41,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x6B,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x6C,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x6B,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x3F,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x27,0x1B,0x43,0x1B,0x53,0x77,0x1B,0x43,0x1B,0x53,0x7F,0x1B,0x43,0x1B,0x53,0x3C,0x1B,0x43,0x1B,0x53,0x37,0x1B,0x45,0x1B,0x56,0x6F,0x1B,0x42,0x1B,0x52,0x70,0x1B,0x41,0x1B,0x52,0x7C,0x1B,0x41,0x1B,0x55,0x7C,0x1B,0x41,0x1B,0x51,0x7C,0x1B,0x41,0x1B,0x51,0x70,0x1B,0x41,0x1B,0x51,0x77,0x1B,0x42,0x1B,0x56,0x37,0x1B,0x41,0x1B,0x56,0x6B,0x1B,0x44,0x1B,0x51,0x78,0x1B,0x44,0x1B,0x51,0x6C,0x1B,0x44,0x1B,0x51,0x74,0x1B,0x41,0x1B,0x51,0x33,0x1B,0x41,0x1B,0x55,0x37,0x1B,0x41,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x6F,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x46,0x1B,0x56,0x3F,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x3F,0x1B,0x46,0x1B,0x56,0x34,0x1B,0x46,0x1B,0x53,0x7F,0x1B,0x46,0x1B,0x53,0x7F,0x1B,0x43,0x1B,0x53,0x74,0x1B,0x43,0x1B,0x53,0x7F,0x1B,0x46,0x1B,0x53,0x7C,0x1B,0x45,0x1B,0x53,0x68,0x1B,0x45,0x1B,0x52,0x28,0x1B,0x45,0x1B,0x55,0x6B,0x1B,0x41,0x1B,0x55,0x2F,0x1B,0x44,0x1B,0x55,0x2F,0x1B,0x41,0x1B,0x52,0x2F,0x1B,0x41,0x1B,0x52,0x27,0x1B,0x42,0x1B,0x56,0x37,0x1B,0x45,0x1B,0x56,0x68,0x1B,0x41,0x1B,0x55,0x2F,0x1B,0x41,0x1B,0x52,0x27,0x1B,0x41,0x1B,0x52,0x23,0x1B,0x41,0x1B,0x52,0x2F,0x1B,0x41,0x1B,0x52,0x2F,0x1B,0x45,0x1B,0x56,0x77,0x1B,0x45,0x1B,0x56,0x30,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x7B,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x6F,0x1B,0x46,0x1B,0x56,0x6B,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x3C,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x7B,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x34,0x1B,0x46,0x1B,0x53,0x7F,0x1B,0x46,0x1B,0x53,0x30,0x1B,0x43,0x1B,0x53,0x77,0x1B,0x46,0x1B,0x53,0x68,0x1B,0x42,0x1B,0x56,0x78,0x1B,0x42,0x1B,0x56,0x37,0x1B,0x42,0x1B,0x56,0x23,0x1B,0x42,0x1B,0x56,0x23,0x1B,0x42,0x1B,0x56,0x23,0x1B,0x42,0x1B,0x56,0x23,0x1B,0x42,0x1B,0x56,0x2B,0x1B,0x42,0x1B,0x56,0x37,0x1B,0x42,0x1B,0x56,0x28,0x1B,0x45,0x1B,0x52,0x27,0x1B,0x42,0x1B,0x52,0x2F,0x1B,0x42,0x1B,0x56,0x2F,0x1B,0x42,0x1B,0x56,0x63,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x41,0x1B,0x55,0x68,0x1B,0x45,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x27,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x43,0x1B,0x53,0x3F,0x1B,0x43,0x1B,0x53,0x77,0x1B,0x46,0x1B,0x53,0x78,0x1B,0x45,0x1B,0x56,0x6B,0x1B,0x42,0x1B,0x56,0x34,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x46,0x1B,0x56,0x6B,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x56,0x78,0x1B,0x42,0x1B,0x56,0x70,0x1B,0x42,0x1B,0x56,0x70,0x1B,0x45,0x1B,0x52,0x70,0x1B,0x42,0x1B,0x52,0x37,0x1B,0x42,0x1B,0x56,0x70,0x1B,0x42,0x1B,0x56,0x78,0x1B,0x45,0x1B,0x52,0x78,0x1B,0x41,0x1B,0x55,0x68,0x1B,0x42,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x6C,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x6B,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x56,0x78,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x34,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x3F,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x53,0x74,0x1B,0x46,0x1B,0x53,0x70,0x1B,0x46,0x1B,0x53,0x23,0x1B,0x42,0x1B,0x53,0x28,0x1B,0x45,0x1B,0x52,0x6F,0x1B,0x42,0x1B,0x52,0x77,0x1B,0x42,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x28,0x1B,0x45,0x1B,0x56,0x68,0x1B,0x41,0x1B,0x55,0x7C,0x1B,0x41,0x1B,0x55,0x7C,0x1B,0x41,0x1B,0x51,0x7C,0x1B,0x45,0x1B,0x52,0x34,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x45,0x1B,0x52,0x68,0x1B,0x45,0x1B,0x55,0x7C,0x1B,0x41,0x1B,0x55,0x23,0x1B,0x42,0x1B,0x56,0x27,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x42,0x1B,0x56,0x78,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x73,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x3F,0x1B,0x46,0x1B,0x56,0x34,0x1B,0x46,0x1B,0x56,0x30,0x1B,0x46,0x1B,0x56,0x30,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x53,0x7F,0x1B,0x46,0x1B,0x53,0x28,0x1B,0x42,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x52,0x37,0x1B,0x42,0x1B,0x52,0x27,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x73,0x1B,0x42,0x1B,0x56,0x78,0x1B,0x45,0x1B,0x52,0x23,0x1B,0x41,0x1B,0x52,0x23,0x1B,0x41,0x1B,0x52,0x2B,0x1B,0x45,0x1B,0x52,0x37,0x1B,0x42,0x1B,0x52,0x74,0x1B,0x45,0x1B,0x52,0x68,0x1B,0x45,0x1B,0x55,0x6B,0x1B,0x45,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x23,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x42,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x30,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x42,0x1B,0x56,0x20,0x1B,0x42,0x1B,0x52,0x27,0x1B,0x42,0x1B,0x52,0x74,0x1B,0x42,0x1B,0x52,0x70,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x45,0x1B,0x52,0x70,0x1B,0x41,0x1B,0x52,0x70,0x1B,0x45,0x1B,0x52,0x70,0x1B,0x41,0x1B,0x52,0x70,0x1B,0x41,0x1B,0x55,0x70,0x1B,0x41,0x1B,0x55,0x70,0x1B,0x45,0x1B,0x55,0x34,0x1B,0x45,0x1B,0x55,0x68,0x1B,0x45,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x60,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x42,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x46,0x1B,0x56,0x3F,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x45,0x1B,0x56,0x6B,0x1B,0x45,0x1B,0x52,0x74,0x1B,0x45,0x1B,0x52,0x68,0x1B,0x41,0x1B,0x52,0x2C,0x1B,0x41,0x1B,0x52,0x23,0x1B,0x45,0x1B,0x52,0x73,0x1B,0x45,0x1B,0x52,0x23,0x1B,0x45,0x1B,0x52,0x73,0x1B,0x41,0x1B,0x55,0x70,0x1B,0x41,0x1B,0x55,0x23,0x1B,0x41,0x1B,0x55,0x70,0x1B,0x41,0x1B,0x55,0x3C,0x1B,0x42,0x1B,0x56,0x23,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x60,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x60,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x56,0x78,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x60,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x41,0x1B,0x56,0x68,0x1B,0x41,0x1B,0x55,0x30,0x1B,0x41,0x1B,0x55,0x74,0x1B,0x45,0x1B,0x52,0x7C,0x1B,0x45,0x1B,0x55,0x7C,0x1B,0x41,0x1B,0x55,0x2F,0x1B,0x41,0x1B,0x55,0x2F,0x1B,0x41,0x1B,0x55,0x2F,0x1B,0x41,0x1B,0x55,0x2F,0x1B,0x41,0x1B,0x55,0x2F,0x1B,0x41,0x1B,0x51,0x7C,0x1B,0x44,0x1B,0x55,0x7C,0x1B,0x44,0x1B,0x56,0x34,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x46,0x1B,0x56,0x60,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x42,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x46,0x1B,0x56,0x3F,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x46,0x1B,0x56,0x33,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x41,0x1B,0x55,0x78,0x1B,0x44,0x1B,0x51,0x7F,0x1B,0x44,0x1B,0x55,0x74,0x1B,0x41,0x1B,0x55,0x74,0x1B,0x45,0x1B,0x52,0x23,0x1B,0x45,0x1B,0x52,0x70,0x1B,0x45,0x1B,0x52,0x70,0x1B,0x41,0x1B,0x52,0x78,0x1B,0x45,0x1B,0x55,0x74,0x1B,0x41,0x1B,0x55,0x78,0x1B,0x41,0x1B,0x51,0x34,0x1B,0x44,0x1B,0x54,0x68,0x1B,0x44,0x1B,0x51,0x7F,0x1B,0x45,0x1B,0x56,0x30,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x44,0x1B,0x55,0x6B,0x1B,0x44,0x1B,0x54,0x6F,0x1B,0x44,0x1B,0x54,0x30,0x1B,0x44,0x1B,0x51,0x7F,0x1B,0x44,0x1B,0x55,0x7C,0x1B,0x44,0x1B,0x55,0x70,0x1B,0x41,0x1B,0x55,0x7C,0x1B,0x44,0x1B,0x51,0x7C,0x1B,0x44,0x1B,0x51,0x7C,0x1B,0x44,0x1B,0x51,0x34,0x1B,0x41,0x1B,0x51,0x63,0x1B,0x44,0x1B,0x54,0x7C,0x1B,0x44,0x1B,0x54,0x37,0x1B,0x41,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x56,0x78,0x1B,0x42,0x1B,0x56,0x78,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x46,0x1B,0x56,0x30,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x34,0x1B,0x46,0x1B,0x56,0x30,0x1B,0x46,0x1B,0x56,0x30,0x1B,0x46,0x1B,0x56,0x3F,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x45,0x1B,0x56,0x60,0x1B,0x44,0x1B,0x52,0x7C,0x1B,0x44,0x1B,0x51,0x77,0x1B,0x44,0x1B,0x54,0x2B,0x1B,0x44,0x1B,0x54,0x64,0x1B,0x44,0x1B,0x54,0x20,0x1B,0x44,0x1B,0x54,0x2F,0x1B,0x44,0x1B,0x54,0x2F,0x1B,0x44,0x1B,0x54,0x27,0x1B,0x44,0x1B,0x51,0x37,0x1B,0x41,0x1B,0x51,0x78,0x1B,0x44,0x1B,0x51,0x78,0x1B,0x44,0x1B,0x54,0x3F,0x1B,0x44,0x1B,0x51,0x73,0x1B,0x44,0x1B,0x52,0x77,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x68,0x1B,0x42,0x1B,0x56,0x78,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x42,0x1B,0x56,0x34,0x1B,0x46,0x1B,0x56,0x34,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x73,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x60,0x1B,0x41,0x1B,0x56,0x70,0x1B,0x44,0x1B,0x52,0x7C,0x1B,0x44,0x1B,0x51,0x28,0x1B,0x44,0x1B,0x54,0x6F,0x1B,0x44,0x1B,0x54,0x74,0x1B,0x44,0x1B,0x54,0x70,0x1B,0x44,0x1B,0x54,0x2B,0x1B,0x44,0x1B,0x54,0x64,0x1B,0x44,0x1B,0x54,0x70,0x1B,0x44,0x1B,0x54,0x7C,0x1B,0x44,0x1B,0x51,0x74,0x1B,0x44,0x1B,0x51,0x7C,0x1B,0x44,0x1B,0x51,0x37,0x1B,0x44,0x1B,0x55,0x6B,0x1B,0x44,0x1B,0x54,0x7C,0x1B,0x44,0x1B,0x51,0x7F,0x1B,0x45,0x1B,0x56,0x30,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x42,0x1B,0x56,0x78,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x77,0x1B,0x42,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x37,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x46,0x1B,0x56,0x78,0x1B,0x46,0x1B,0x56,0x7F,0x1B,0x45,0x1B,0x56,0x60,0x1B,0x41,0x1B,0x56,0x78,0x1B,0x44,0x1B,0x51,0x7C,0x1B,0x44,0x1B,0x54,0x6F,0x1B,0x44,0x1B,0x54,0x7C,0x1B,0x44,0x1B,0x54,0x6C,0x1B,0x44,0x1B,0x54,0x7B,0x1B,0x44,0x1B,0x54,0x70,0x1B,0x44,0x1B,0x54,0x74,0x1B,0x44,0x1B,0x54,0x70,0x1B,0x44,0x1B,0x54,0x23,0x1B,0x44,0x1B,0x54,0x2F,0x1B,0x44,0x1B,0x54,0x6F,0x1B,0x44,0x1B,0x54,0x30,0x1B,0x44,0x1B,0x51,0x37,0x1B,0x44,0x1B,0x51,0x68,0x1B,0x44,0x1B,0x54,0x24,0x1B,0x44,0x1B,0x54,0x37,0x1B,0x44,0x1B,0x51,0x77,0x1B,0x44,0x1B,0x52,0x7F,0x1B,0x44,0x1B,0x56,0x7C,0x1B,0x41,0x1B,0x56,0x70,0x1B,0x42,0x1B,0x56,0x30,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x74,0x1B,0x42,0x1B,0x52,0x7C,0x1B,0x42,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x46,0x1B,0x56,0x77,0x1B,0x46,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x7C,0x1B,0x45,0x1B,0x56,0x60,0x1B,0x41,0x1B,0x56,0x70,0x1B,0x44,0x1B,0x52,0x7C,0x1B,0x44,0x1B,0x51,0x7C,0x1B,0x44,0x1B,0x51,0x7B,0x1B,0x44,0x1B,0x51,0x2C,0x1B,0x44,0x1B,0x54,0x2F,0x1B,0x44,0x1B,0x54,0x2F,0x1B,0x44,0x1B,0x54,0x6F,0x1B,0x44,0x1B,0x54,0x2B,0x1B,0x44,0x1B,0x54,0x60,0x1B,0x44,0x1B,0x54,0x7C,0x1B,0x44,0x1B,0x54,0x28,0x1B,0x44,0x1B,0x54,0x7C,0x1B,0x44,0x1B,0x54,0x70,0x1B,0x44,0x1B,0x54,0x78,0x1B,0x44,0x1B,0x54,0x74,0x1B,0x44,0x1B,0x51,0x37,0x1B,0x44,0x1B,0x55,0x68,0x1B,0x44,0x1B,0x54,0x70,0x1B,0x44,0x1B,0x54,0x77,0x1B,0x44,0x1B,0x54,0x37,0x1B,0x44,0x1B,0x54,0x7C,0x1B,0x44,0x1B,0x54,0x74,0x1B,0x44,0x1B,0x54,0x7F,0x1B,0x44,0x1B,0x52,0x7F,0x1B,0x41,0x1B,0x52,0x30,0x1B,0x42,0x1B,0x52,0x68,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x77,0x1B,0x42,0x1B,0x52,0x34,0x1B,0x42,0x1B,0x52,0x74,0x1B,0x42,0x1B,0x56,0x70,0x1B,0x42,0x1B,0x56,0x74,0x1B,0x46,0x1B,0x56,0x70,0x1B,0x42,0x1B,0x56,0x60,0x1B,0x41,0x1B,0x56,0x78,0x1B,0x41,0x1B,0x51,0x7C,0x1B,0x44,0x1B,0x51,0x20,0x1B,0x44,0x1B,0x51,0x6B,0x1B,0x44,0x1B,0x54,0x7C,0x1B,0x44,0x1B,0x54,0x70,0x1B,0x44,0x1B,0x54,0x74,0x1B,0x44,0x1B,0x54,0x3F,0x1B,0x44,0x1B,0x54,0x3F,0x1B,0x44,0x1B,0x51,0x78,0x1B,0x44,0x1B,0x51,0x7C,0x1B,0x44,0x1B,0x54,0x20,0x1B,0x44,0x1B,0x54,0x2B,0x1B,0x44,0x1B,0x54,0x64,0x1B,0x44,0x1B,0x54,0x70,0x1B,0x44,0x1B,0x54,0x2B,0x1B,0x44,0x1B,0x54,0x6F,0x1B,0x44,0x1B,0x54,0x37,0x1B,0x44,0x1B,0x51,0x37,0x1B,0x44,0x1B,0x55,0x7C,0x1B,0x44,0x1B,0x54,0x27,0x1B,0x44,0x1B,0x54,0x3F,0x1B,0x44,0x1B,0x54,0x37,0x1B,0x44,0x1B,0x54,0x7F,0x1B,0x44,0x1B,0x54,0x7B,0x1B,0x44,0x1B,0x54,0x6F,0x1B,0x44,0x1B,0x54,0x77,0x1B,0x44,0x1B,0x51,0x7F,0x1B,0x44,0x1B,0x52,0x34,0x1B,0x42,0x1B,0x52,0x60,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x74,0x1B,0x42,0x1B,0x52,0x7C,0x1B,0x42,0x1B,0x52,0x74,0x1B,0x42,0x1B,0x52,0x70,0x1B,0x45,0x1B,0x52,0x60,0x1B,0x41,0x1B,0x52,0x7C,0x1B,0x44,0x1B,0x51,0x7C,0x1B,0x44,0x1B,0x51,0x7C,0x1B,0x44,0x1B,0x51,0x74,0x1B,0x44,0x1B,0x51,0x70,0x1B,0x44,0x1B,0x51,0x7C,0x1B,0x44,0x1B,0x51,0x30,0x1B,0x44,0x1B,0x54,0x6F,0x1B,0x44,0x1B,0x54,0x7F,0x1B,0x44,0x1B,0x54,0x24,0x1B,0x44,0x1B,0x54,0x78,0x1B,0x44,0x1B,0x54,0x6F,0x1B,0x44,0x1B,0x54,0x6C,0x1B,0x44,0x1B,0x54,0x27,0x1B,0x44,0x1B,0x54,0x74,0x1B,0x44,0x1B,0x54,0x63,0x1B,0x44,0x1B,0x54,0x23,0x1B,0x44,0x1B,0x54,0x2F,0x1B,0x44,0x1B,0x54,0x2C,0x1B,0x44,0x1B,0x51,0x37,0x1B,0x44,0x1B,0x51,0x6F,0x1B,0x44,0x1B,0x54,0x7C,0x1B,0x44,0x1B,0x54,0x3F,0x1B,0x44,0x1B,0x54,0x27,0x1B,0x44,0x1B,0x54,0x27,0x1B,0x44,0x1B,0x54,0x33,0x1B,0x44,0x1B,0x54,0x7B,0x1B,0x44,0x1B,0x54,0x2F,0x1B,0x44,0x1B,0x54,0x74,0x1B,0x44,0x1B,0x54,0x34,0x1B,0x44,0x1B,0x51,0x7F,0x1B,0x44,0x1B,0x52,0x74,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x74,0x1B,0x42,0x1B,0x52,0x77,0x1B,0x42,0x1B,0x52,0x77,0x1B,0x41,0x1B,0x52,0x60,0x1B,0x41,0x1B,0x55,0x7C,0x1B,0x41,0x1B,0x51,0x70,0x1B,0x44,0x1B,0x51,0x2B,0x1B,0x44,0x1B,0x54,0x7C,0x1B,0x44,0x1B,0x54,0x38,0x1B,0x44,0x1B,0x54,0x68,0x1B,0x44,0x1B,0x54,0x6C,0x1B,0x44,0x1B,0x54,0x77,0x1B,0x44,0x1B,0x51,0x3F,0x1B,0x44,0x1B,0x54,0x6F,0x1B,0x44,0x1B,0x54,0x78,0x1B,0x44,0x1B,0x54,0x27,0x1B,0x44,0x1B,0x54,0x7F,0x1B,0x44,0x1B,0x54,0x70,0x1B,0x44,0x1B,0x54,0x6F,0x1B,0x44,0x1B,0x54,0x60,0x1B,0x44,0x1B,0x54,0x60,0x1B,0x44,0x1B,0x54,0x6F,0x1B,0x44,0x1B,0x54,0x7C,0x1B,0x44,0x1B,0x54,0x30,0x1B,0x44,0x1B,0x51,0x77,0x1B,0x44,0x1B,0x51,0x68,0x1B,0x44,0x1B,0x54,0x2F,0x1B,0x44,0x1B,0x54,0x37,0x1B,0x44,0x1B,0x54,0x37,0x1B,0x44,0x1B,0x54,0x6F,0x1B,0x44,0x1B,0x54,0x7F,0x1B,0x44,0x1B,0x54,0x24,0x1B,0x44,0x1B,0x54,0x73,0x1B,0x44,0x1B,0x54,0x7C,0x1B,0x44,0x1B,0x54,0x23,0x1B,0x44,0x1B,0x54,0x30,0x1B,0x44,0x1B,0x54,0x7F,0x1B,0x44,0x1B,0x52,0x77,0x1B,0x45,0x1B,0x52,0x30,0x1B,0x45,0x1B,0x52,0x78,0x1B,0x42,0x1B,0x52,0x74,0x1B,0x42,0x1B,0x52,0x74,0x1B,0x41,0x1B,0x52,0x78,0x1B,0x41,0x1B,0x51,0x7C,0x1B,0x44,0x1B,0x51,0x63,0x1B,0x44,0x1B,0x51,0x78,0x1B,0x44,0x1B,0x54,0x78,0x1B,0x44,0x1B,0x54,0x34,0x1B,0x44,0x1B,0x54,0x77,0x1B,0x44,0x1B,0x54,0x74,0x1B,0x44,0x1B,0x54,0x77,0x1B,0x44,0x1B,0x54,0x63,0x1B,0x44,0x1B,0x54,0x6C,0x1B,0x44,0x1B,0x54,0x33,0x1B,0x44,0x1B,0x54,0x77,0x1B,0x44,0x1B,0x54,0x70,0x1B,0x44,0x1B,0x54,0x68,0x1B,0x44,0x1B,0x54,0x37,0x1B,0x44,0x1B,0x54,0x70,0x1B,0x44,0x1B,0x54,0x7B,0x1B,0x44,0x1B,0x54,0x70,0x1B,0x44,0x1B,0x54,0x7F,0x1B,0x44,0x1B,0x54,0x7F,0x1B,0x44,0x1B,0x54,0x27,0x1B,0x44,0x1B,0x54,0x73,0x1B,0x44,0x1B,0x51,0x68,0x1B,0x44,0x1B,0x54,0x60,0x1B,0x44,0x1B,0x54,0x3F,0x1B,0x44,0x1B,0x54,0x7F,0x1B,0x44,0x1B,0x54,0x7F,0x1B,0x44,0x1B,0x54,0x7F,0x1B,0x44,0x1B,0x54,0x7F,0x1B,0x44,0x1B,0x54,0x7C,0x1B,0x44,0x1B,0x54,0x7B,0x1B,0x44,0x1B,0x54,0x33,0x1B,0x44,0x1B,0x54,0x68,0x1B,0x44,0x1B,0x54,0x74,0x1B,0x44,0x1B,0x54,0x7F,0x1B,0x44,0x1B,0x55,0x77,0x1B,0x45,0x1B,0x55,0x30};

////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);  // Port série matériel de l'ATmega à 9600 bauds.
  minitel.changeSpeed(minitel.searchSpeed());
  minitel.smallMode();
  minitel.newScreen();
}

////////////////////////////////////////////////////////////////////////

void loop() {
  // Voir https://github.com/eserandour/Conversion_Videotex_Hex
  for (int i=0; i<LONGUEUR_TRAME_PORTRAIT; i++) {
    minitel.writeByte(pgm_read_byte_near(PORTRAIT + i));
  }
}

////////////////////////////////////////////////////////////////////////

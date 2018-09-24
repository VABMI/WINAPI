


#include <iostream>
#include <windows.h>
#include <mmsystem.h>


using namespace std;

/*
int main()
{
	
	
	PlaySound(TEXT("C:\\Users\\vaxoa\\OneDrive\\Desktop\\as.wav"),NULL,SND_SYNC);
	
	return 0;
}

*/


#include <conio.h>

#include "inc/fmod.h"

FSOUND_SAMPLE* handle;

int main ()
{
   // init FMOD sound system
   FSOUND_Init (44100, 32, 0);

   // load and play mp3
   handle=FSOUND_Sample_Load (0,"C:\\Users\\vaxoa\\OneDrive\\Desktop\\STING  CHEB MAMI - DESERT ROSE.mp3",0, 0, 0);
   FSOUND_PlaySound (0,handle);

   // wait until the users hits a key to end the app
   while (!_kbhit())
   {
   }

   // clean up
   FSOUND_Sample_Free (handle);
   FSOUND_Close();
}
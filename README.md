# This is my readme file, by Duc
Raspberry Pi acoustic sensor project

This project will turn a raspberry Pi 3 into an acoustic sensor
----------------------------------------------------------------------------------------------------------------------------------
GENERAL CONTENTS

  1.Configuration instructions.
  
  2.Installation instructions.
  
  3.Operating instructions.
  
  4.List of files included.
  
  5.Copyright and licensing information.
  
  6.Contact information for the distributor or programer.
  
----------------------------------------------------------------------------------------------------------------------------------

1.Configuration instructions.

  1.1.Hardware configuration
  
A Raspberry Pi3 is recommended. If older version of Pi is used, corresponding configuration might be changed
The Pi is mounted with a USB sound card, and plugged in a microphone.
It is recommended to have Ethernet connection for your Pi.

  1.2.Software configuration

  In oder to set the USB sound card as default audio device, 02 files need to be modified with following step and content
  Step 1 : Use “lsusb” command to check if your USB sound card is mounted
  Step 2 : Use “sudo nano /etc/asound.conf”command and put following content to the file:
pcm.!default { type plug slave { pcm "hw:1,0" } } ctl.!default { type hw card 1 }
Step 3 : Go to your home directory. Use “nano .asoundrc” command and put the same content to the file.
Step 4 : Run alsamixer you should be able to see that USB sound card is the default audio device.
...

If you are using Raspian Jessie, you have to roll back alsa-utils to an early version
...
  
#by Duc

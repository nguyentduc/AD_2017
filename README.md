# This is my readme file, by Duc
  Raspberry Pi acoustic sensor project
  
  This project will turn a raspberry Pi 3 into an acoustic sensor

----------------------------------------------------------------------------------------------------------------------------------

GENERAL CONTENTS

  1.Configuration instructions
  
  2.Installation instructions
  
  3.Operating instructions
  
  4.List of files included
  
  5.Copyright and licensing information
  
  6.Contact information for the distributor or programer
  
----------------------------------------------------------------------------------------------------------------------------------

1.Configuration instructions.

1.1.Hardware configuration
  
A Raspberry Pi3 is recommended. If older version of Pi is used, corresponding configuration might be changed

The Pi is mounted with a USB sound card, and plugged in a microphone.

It is recommended to have Ethernet connection for your Pi.



1.2.Software configuration

In oder to set the USB sound card as default audio device, 02 files need to be modified with following step and content
  
Step 1: Use “lsusb” command to check if your USB sound card is mounted
  
Step 2: Use “sudo nano /etc/asound.conf”command and put following content to the file:
            
            pcm.!default{
                type plug
                slave{
                  pcm "hw:1,0"
                }
              }
              ctl.!default{
                type hw
                card 1
              }
  
Step 3: Go to your home directory. Use “nano .asoundrc” command and put the same content to the file.
  
Step 4: Run alsamixer you should be able to see that USB sound card is the default audio device.

If you are using Raspian Jessie, you have to roll back alsa-utils to an early version.

Step 1: Use sudo nano /etc/apt/sources.list command and add the last line:

            deb http://mirrordirector.raspbian.org/raspbian/ jessie main contrib non-free rpi
            # Uncomment line below then 'apt-get update' to enable 'apt-get source'
            #deb-src http://archive.raspbian.org/raspbian/ jessie main contrib non-free rpi
            deb http://mirrordirector.raspbian.org/raspbian/ wheezy main contrib non-free rpi

Step 2: Run sudo apt-get update

Step 3: Run sudo aptitude versions alsa-utils

Step 4: Run sudo apt-get install alsa-utils=1.0.25-4

Step 5: Reboot (if necessary).



2.Installation instructions

libcurl libary should be installed with following steps

Step 1: Run the command "ls /usr/include/curl" to identify that /usr/include/curl/ folder exists or not.
If the folder doesn’t exist. Run “sudo apt-get update” to update the application list.

Step 2: Run “sudo apt-get install libcurl3” to install the libcurl3.

Step 3: Run “sudo apt-get install libcurl4-openssl-dev” to install the development API of libcurl4.


3.Operating instructions
  
4.List of files included
  
5.Copyright and licensing information
  
6.Contact information for the distributor or programer

#by Duc

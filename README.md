# This is my readme file, by Duc
Raspberry Pi acoustic sensor project

This project will turn a raspberry Pi 3 into an acoustic sensor

1. Configuration

1.1 Hardware configuration

A Raspberry Pi3 is recommended. If older version of Pi is used, corresponding configuration might be changed

The Pi is mounted with a USB sound card, and plugged in a microphone.

It is recommended to have Ethernetconnection for your Pi.

1.2 Software configuration

The USb sound card is set as default audio device. To do so, you need to modify 02 files with 
following content
...

If you are using Raspian Jessie, you have to roll back alsa-utils to an early version
...
  
#by Duc

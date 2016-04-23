# Physionet_ECG_Signal_Display_Qt_Creator

Objective:

Write a piece of software in any language that loads a binary data file (which is an ECG file) and
displays its content, as well as scales, in a resizable window, with the ability to scroll through the signal
using a mouse.

Signal file format (100.dat):

Number of signals: 2 interlaced
Number of samples: 650000

Each sample is represented by a 12-bit two’s complement amplitude. The first sample is obtained from
the 12 least significant bits of the first byte pair (stored least significant byte first). The second sample
is formed from the 4 remaining bits of the first byte pair (which are the 4 high bits of the 12-bit sample)
and the next byte (which contains the remaining 8 bits of the second sample). The process is repeated
for each successive pair of samples
Sampling frequency: 360

The gain for each signal is the 200 ADC units per millivolt and the ADC has 11-bit resolution and an
offset such that its output is 1024 ADC units given an input exactly in the middle of its range. The
baseline is not given explicitly, but may be assumed to be equal to the ADC zero value of 1024.
The first samples acquired has values of 995 and 1011.

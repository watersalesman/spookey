# SpooKey

SpooKey is a simple keylogger using kernel level APIs to gather keystrokes.

Overview
---

The Linux binary uses the `linux/input.h` kernel header to translate events
from devices found in `/dev/input`. It is currently hardcoded to check
`/dev/input/event0`. I will make scan for active keyboards, using a similar
functionality seen in *evtest* when identifying devices.

I will eventually work on a Windows executable using the Windows API.

By default, keypresses are saved, one per line, in a file named `key.log`.
I may make a script (either in C++ or a scripting language) that parses the
keystrokes into something more legible.

This code is still very much a work in progress.

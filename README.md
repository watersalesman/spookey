# SpooKey

SpooKey is a simple keylogger using kernel-level APIs to gather keystrokes.

Overview
---

The Linux binary uses the Linux Input Subsystem kernel API to find keyboards
located in `/dev/input/` and to translate events from those devices. Key
events are saved one per line in a file corresponding to the input device.
E.g., `event0.log` for `/dev/input/event0`.

I will work on running several threads if multiple keyboards are present. I
will also eventually work on a Windows executable using the Windows API. I do
not plan on making a method of exfiltration anytime soon (at least not built in).
For the time being, this will be developed as a module of sorts to be used with
other software.

This code is still very much a work in progress.

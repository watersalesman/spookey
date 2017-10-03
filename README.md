# SpooKey

SpooKey is a multithreaded keylogger written in C++ that uses kernel-level APIs
to capture keystrokes

Overview
---

The Linux binary uses the Linux Input Subsystem kernel API to identify
keyboards located in `/dev/input/` and to translate key events. Threads
will spawn to record each keyboard up to the maximum specified by the
MAX\_THREADS macro in `spookey.cc` (default is 4). Key events are written
to a file corresponding to the input device name. E.g., `event0.log` for
`/dev/input/event0`.

I will also eventually work on a Windows executable using the Windows API. I do
not plan on making a method of exfiltration anytime soon (at least not built in).
For the time being, this will be developed as a module of sorts to be used with
other software.

__This code is still very much a work in progress.__

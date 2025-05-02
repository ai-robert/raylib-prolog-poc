THIS SOFTWARE IS PROVIDED AS-IS AND NO WARRANTIES OF SUITABILITY, SAFETY, OR PERFORMANCE ARE PROVIDED. RUN AT YOUR OWN RISK.

---

This repo is a quick demo to show how I utilized some of raylib_v5.5's functionality from SWI-Prolog using the [SWI-Prolog Foreign Language Interface](https://www.swi-prolog.org/pldoc/man?section=foreign).

It requires SWI-Prolog 9.3.19 or higher, which means you'll want [a development build](https://www.swi-prolog.org/download/devel).

In includes the first and second example from [Raylib's example page](https://www.raylib.com/examples.html), namely the Basic Window and the Basic Screen Manager.

---

I've included the `compile_raylib55_pro_interface` `.bat` and `.ps1` files just to show how I got it compiled on Windows. 
They absolutely NEED to be modified to run on your computer. 
See [the raylib documentation](https://github.com/raysan5/raylib/wiki/Working-on-Windows) for installing raylib on your platform. I used MinGW for windows.



 
I've included my pre-compiled DLL, so in theory on windows you could clone this repo and run the examples
straight from SWI-Prolog. My personal setup is Windows 11, Intel x86_64. 
Of course, for safety purposes you should read all the source code and compile it from scratch, 
but if you found this repo then I assume you're a tech savvy adult 
who knows the risks and can run things at your own risk.

 
@echo off

start "" "..\..\..\tools\textpad\textpad.exe" ram.inc macroses.inc bank7.inc bank6.inc bank5.inc bank4.inc bank3.inc bank2.inc bank1.inc bank0.inc

pause 0

:again

cd nas

echo assemble...

dasm bank0.nas -f3 -obank0.bin
dasm bank0.nas -f3 -l!cd2.lst -obank0.bin >> !err.log

for %%f in (*.nas) do call :dodasm %%f > NUL

dasm hdr.nas -f3 -o!cd2.hdr > NUL
dasm chr.nas -f3 -o!cd2.chr > NUL

goto :build

:dodasm
dasm %1 -f3 -o%~n1.bin
goto :eof

:build
echo build...
copy /b bank0.bin+bank1.bin+bank2.bin+bank3.bin+bank4.bin+bank5.bin+bank6.bin+bank7.bin !cd2.prg > NUL

nesimage j !cd2 > NUL

echo cleanup...
rem for %%f in (*.bin) do del %%f
del !err.log
rem del !cd2.prg
rem del !cd2.chr
del !cd2.hdr

copy /b !cd2.nes ..\!cd2.nes > NUL
cd ..

echo done.
pause 0

goto :again

:eof

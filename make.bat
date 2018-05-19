@echo off

start ..\..\..\tools\textpad\TextPad.exe doc\notes.txt ram.inc macroses.inc bank7.inc bank6.inc bank5.inc bank4.inc bank3.inc bank2.inc bank1.inc bank0.inc

pause 0

:again

del !cd2prev.nes
rename !cd2.nes !cd2prev.nes

cd nas

echo assemble...

dasm bank0.nas -f3 -obank0.bin
dasm bank0.nas -f3 -l!cd2.lst -obank0.bin > !err.log

for %%f in (*.nas) do call :dodasm %%f > NUL

goto :build

:dodasm
dasm %1 -f3 -o%~n1.bin
goto :eof

:build
echo build...

rename hdr.bin !cd2.hdr > NUL
rename chr.bin !cd2.chr > NUL

copy /b bank0.bin+bank1.bin+bank2.bin+bank3.bin+bank4.bin+bank5.bin+bank6.bin+bank7.bin !cd2.prg > NUL

nesimage j !cd2 > NUL

echo cleanup...

for %%f in (*.bin) do del %%f
rem del !err.log
del !cd2.prg
del !cd2.chr
del !cd2.hdr

copy /b !cd2.nes ..\!cd2.nes > NUL

del !cd2.nes

cd ..

echo ===OLD ROM===
g:\dos\m3checksum !cd2prev.nes
echo ===NEW ROM===
g:\dos\m3checksum !cd2.nes

echo done.
pause 0

goto :again

:eof

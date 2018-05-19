@echo off

:again

cd nas

echo assemble...

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
del !cd2.prg
del !cd2.hdr
del !cd2.chr

copy /b !cd2.nes ..\!cd2.nes > NUL
cd ..

echo done.

cd nas

echo assemble...

for f in *.nas; do ./dasm $f -f3 -o"${f%.nas}.bin"; done

echo build...

mv hdr.bin !cd2.hdr
mv chr.bin !cd2.chr

cat bank0.bin bank1.bin bank2.bin bank3.bin bank4.bin bank5.bin bank6.bin bank7.bin > !cd2.prg
cat !cd2.hdr !cd2.prg !cd2.chr > !cd2.nes

echo cleanup...

rm *.bin
rm !cd2.hdr !cd2.prg !cd2.chr

cp !cd2.nes ../!cd2.nes

echo done.

rmdir /s /q "MinGW\fichin"
del /s /q "MinGW\fichin\*"
md "MinGW\lib"
md "MinGW\include"
xcopy "..\..\include" "MinGW\include" /s /i
xcopy "..\..\lib" "MinGW\lib" /s /i
7za.exe a -r fichin_zinjai_addon.zcp autocomp MinGW temp templates
pause
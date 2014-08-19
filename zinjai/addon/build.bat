rmdir /s /q "MinGW\fichin"
del /s /q "MinGW\fichin\*"
del fichin_zinjai_addon.zcp
md "MinGW\lib"
md "MinGW\include"
xcopy "..\..\include" "MinGW\include" /s /i /y
xcopy "..\..\lib" "MinGW\lib" /s /i /y
7za.exe a -r -tzip fichin_zinjai_addon.zcp autocomp MinGW temp templates
pause
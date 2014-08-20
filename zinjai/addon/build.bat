rmdir /s /q "MinGW\fichin"
del /s /q "MinGW\fichin\*"
del fichin_zinjai_addon.zcp
md "MinGW\fichin\lib"
md "MinGW\fichin\include"
xcopy "..\..\include" "MinGW\fichin\include" /s /i /y
xcopy "..\..\lib" "MinGW\fichin\lib" /s /i /y
7za.exe a -r -tzip fichin_zinjai_addon.zcp autocomp MinGW temp templates
pause
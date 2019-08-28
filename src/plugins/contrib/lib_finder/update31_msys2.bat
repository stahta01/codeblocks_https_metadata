@echo off
mkdir ..\..\..\devel31_msys2\share\CodeBlocks\lib_finder > nul 2>&1
mkdir ..\..\..\output31_msys2\share\CodeBlocks\lib_finder > nul 2>&1
copy /Y lib_finder\*.xml ..\..\..\devel31_msys2\share\CodeBlocks\lib_finder > nul 2>&1
copy /Y lib_finder\*.xml ..\..\..\output31_msys2\share\CodeBlocks\lib_finder > nul 2>&1
zip -j9 ..\..\..\devel31_msys2\share\CodeBlocks\lib_finder.zip manifest.xml

@echo off
cls
md ..\..\..\devel31_msys2\share\CodeBlocks\images\wxsmith > nul 2>&1
md ..\..\..\output31_msys2\share\CodeBlocks\images\wxsmith > nul 2>&1
zip ..\..\..\devel31_msys2\share\CodeBlocks\wxsmith.zip manifest.xml
zip ..\..\..\output31_msys2\share\CodeBlocks\wxsmith.zip manifest.xml
copy wxwidgets\icons\*.png ..\..\..\devel31_msys2\share\CodeBlocks\images\wxsmith\ > nul 2>&1
copy wxwidgets\icons\*.png ..\..\..\output31_msys2\share\CodeBlocks\images\wxsmith\ > nul 2>&1
exit 0

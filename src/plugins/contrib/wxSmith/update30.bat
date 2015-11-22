@echo off
cls
md ..\..\..\devel30\share\CodeBlocks\images\wxsmith > nul 2>&1
zip ..\..\..\devel30\share\CodeBlocks\wxsmith.zip manifest.xml
copy wxwidgets\icons\*.png ..\..\..\devel30\share\CodeBlocks\images\wxsmith\ > nul 2>&1
exit 0

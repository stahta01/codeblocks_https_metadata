@echo off
cls
md ..\..\..\devel\share\CodeBlocks\images\wxsmith > nul 2>&1
zip ..\..\..\devel\share\CodeBlocks\wxsmith.zip manifest.xml
copy wxwidgets\icons\*.png ..\..\..\devel\share\CodeBlocks\images\wxsmith\ > nul 2>&1
exit 0

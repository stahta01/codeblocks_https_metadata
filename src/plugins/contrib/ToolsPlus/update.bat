@echo off
md ..\..\..\devel\share\CodeBlocks\images\settings > nul 2>&1
copy .\Resources\*.png ..\..\..\devel\share\CodeBlocks\images\settings\ > nul 2>&1
exit 0

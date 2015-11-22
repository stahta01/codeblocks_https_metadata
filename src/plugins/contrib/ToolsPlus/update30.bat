@echo off
md ..\..\..\devel30\share\CodeBlocks\images\settings > nul 2>&1
copy .\Resources\*.png ..\..\..\devel30\share\CodeBlocks\images\settings\ > nul 2>&1
exit 0

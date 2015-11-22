@echo off
md ..\..\..\devel\share\CodeBlocks\images\ThreadSearch > nul 2>&1
md ..\..\..\devel\share\CodeBlocks\images\ThreadSearch\16x16 > nul 2>&1
md ..\..\..\devel\share\CodeBlocks\images\ThreadSearch\22x22 > nul 2>&1
md ..\..\..\devel\share\CodeBlocks\images\settings > nul 2>&1
copy .\resources\images\*.png ..\..\..\devel\share\CodeBlocks\images\ThreadSearch\ > nul 2>&1
copy .\resources\images\16x16\*.png ..\..\..\devel\share\CodeBlocks\images\ThreadSearch\16x16\ > nul 2>&1
copy .\resources\images\22x22\*.png ..\..\..\devel\share\CodeBlocks\images\ThreadSearch\22x22\ > nul 2>&1
copy .\resources\*.png ..\..\..\devel\share\CodeBlocks\images\settings\ > nul 2>&1
exit 0


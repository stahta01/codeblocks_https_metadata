@echo off
zip -j9 ..\..\..\devel30_64\share\CodeBlocks\codesnippets.zip manifest.xml > nul 2>&1
md ..\..\..\devel30_64\share\CodeBlocks\images\codesnippets > nul 2>&1
copy .\resources\*.png ..\..\..\devel30_64\share\CodeBlocks\images\codesnippets\ > nul 2>&1

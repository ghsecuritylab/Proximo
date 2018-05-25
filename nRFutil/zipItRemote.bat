REM Batch File to run the nRFutil program to encrypt the code in the ../Eclipse/_build directory without having to manually type the commandline commands each time a new firmwarepackage must be made. This batch file can only be run from this folder without changing the paths. Also make sure that the the public and private keys and nrfutil is in this folder.  
start nrfutil.exe pkg generate --hw-version 52 --application-version 1 --application ../Proximo_nRF/Output/Debug/Exe/Proximo.hex --sd-req 0xA8 --key-file ../Bootloader_nRF/private.key proximo_dfu.zip
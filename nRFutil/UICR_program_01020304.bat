REM @ECHO OFF
REM writes at UICR CUSTOMER[0] abcd0102
start /wait /B nrfjprog --eraseuicr
start /wait /B nrfjprog --memwr 0x10001080 --val 0x01020304
REM done
pause
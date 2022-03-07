SET RVCT40INC=C:\Keil\ARM\RV31\INC
SET RVCT40LIB=C:\Keil\ARM\RV31\LIB
SET CPU_TYPE=LPC1768
SET CPU_VENDOR=NXP (founded by Philips)
SET UV2_TARGET=Target 1
SET CPU_CLOCK=0x00000000
"C:\Keil\ARM\BIN40\ArmAsm" --Via "startup_lpc17xx._ia"
"C:\Keil\ARM\BIN40\ArmCC" --Via "system_lpc17xx.__i"
"C:\Keil\ARM\BIN40\ArmCC" --Via "spiadc_uart_lcd.__i"
"C:\Keil\ARM\BIN40\ArmLink" --Via "SPI_1.lnp"
C:\Keil\ARM\BIN40\fromelf.exe "SPI_1.axf" --i32combined --output "SPI_1.hex"

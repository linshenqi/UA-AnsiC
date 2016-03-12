@echo off
set ROOT=%~pd0
set OPENSSL_SOURCEDIR=%ROOT%openssl-1.0.1s
set OPENSSL_INSTALDIR=%ROOT%openssl

if not "%1" == "" goto error

cd /D %OPENSSL_SOURCEDIR%
if errorlevel 1 goto error

perl Configure VC-WIN32 no-asm no-ec --prefix=%OPENSSL_INSTALDIR%
if errorlevel 1 goto error

sed -i "/perl/ s/\\\\/\\//g" ms/do_win64a.bat 
call ms\do_ms
if errorlevel 1 goto error

sed -i "/PERL/ s/\\\\/\\//g; /PERL/ s/\\$@/\$(@:\\\\=\\/)/;" ms/nt*.mak
nmake -f ms\nt.mak clean

nmake -f ms\nt.mak
if errorlevel 1 goto error

nmake -f ms\nt.mak install
if errorlevel 1 goto error

cd ..\Stack
if errorlevel 1 goto error

nmake -f win32_msc.mak clean
if errorlevel 1 goto error

nmake -f win32_msc.mak
if errorlevel 1 goto error

cd ..\AnsiCServer
if errorlevel 1 goto error

nmake -f win32_msc.mak clean
if errorlevel 1 goto error

nmake -f win32_msc.mak
if errorlevel 1 goto error

cd ..
goto done

:error
echo fatal error: cannot continue.
echo this batch has to be called from a
echo 32bit visual studio command shell
echo openssl sources must be at %OPENSSL_SOURCEDIR%
echo perl has to be in the path

:done

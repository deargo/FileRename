@echo off

set dir_curr=%cd%
echo #==================================================================
echo ��ǰĿ¼��%dir_curr%
echo #==================================================================

##��������ʱ�������QTDIRĿ¼��������������
set qt_package_tool_dir=C:\Qt\Qt5.14.1\5.14.1\msvc2017\bin

set /p dir_clear=������Qt�������windeployqt.exeĿ¼������%qt_package_tool_dir%����

if not exist "%dir_clear%" (
    echo �����Ŀ¼�����ڣ�%dir_clear%
    goto bat_ended
)
:end_input

:package_begin

echo ��ʼִ�д��������
echo #==================================================================
%dir_clear%\windeployqt.exe FileRename.exe
echo #==================================================================
echo ���������
dir
:package_ended

:bat_ended
echo #==================================================================
pause
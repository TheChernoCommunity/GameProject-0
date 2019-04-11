$PremakeVersion = "5.0.0-alpha13"
$ZipFile = "premake-$PremakeVersion.zip"

Invoke-WebRequest "https://github.com/premake/premake-core/releases/download/v$PremakeVersion/premake-$PremakeVersion-windows.zip" -OutFile "$ZipFile"
Expand-Archive -Path "$ZipFile" -DestinationPath ".\\"
Remove-Item -Path "$ZipFile" -Recurse

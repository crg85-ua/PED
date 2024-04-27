# Historial de versiones
# 2.0 (17/03/2020): corregido un error que hacía que la práctica no se recompilara para algunos ficheros de prueba

# Si tus ficheros de prueba no comienzan por "tad", cambia "tad*.cpp" por el prefijo de tus ficheros, por ejemplo "prueba*.cpp"
$files = Get-ChildItem -Path "*corrector/pruebadf/TCalendario/tad*.cpp"

foreach ($file in $files) {
    Write-Host "Evaluando $($file.Name)"
    
    Copy-Item -Path $file.FullName -Destination "src/tad.cpp" -Force
    if (Test-Path -Path "./tad.exe") {
        Remove-Item -Path "./tad.exe" -Force
    }
    Invoke-Expression -Command "make"
    Invoke-Expression -Command "./tad.exe > corrector/pruebadf/TCalendario/$($file.Name).out"
    $original = Get-Content "corrector/pruebadf/TCalendario/$($file.Name).out"
    $modified = Get-Content "corrector/pruebadf/TCalendario/$($file.Name).sal"
    $difference = Compare-Object -ReferenceObject $original -DifferenceObject $modified

    if ($difference) {
        Write-Host "ERROR"
        Write-Host "Diferencias encontradas:"
        $difference | ForEach-Object {
            if ($_.SideIndicator -eq '=>') {
                Write-Host "Línea en $($file.Name).sal, pero no en $($file.Name).out: $($_.InputObject)"
            } elseif ($_.SideIndicator -eq '<=') {
                Write-Host "Línea en $($file.Name).out, pero no en $($file.Name).sal: $($_.InputObject)"
            }
        }
    } else {
        Write-Host "OK"
    }
}

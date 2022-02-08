# SameWav
CLI for checking if two .wav files have identical sets of sample frames. For CI, Unit Tests, and anything that requires checking two sets of .wav data. 

## Windows x64 (PowerShell)
Setup
```powershell
Set-ExecutionPolicy -Scope CurrentUser -ExecutionPolicy Unrestricted
.\updateSub.ps1
```
Usage
```powershell
.\builds\SameWav.exe wav0 wav1
```

## Mac x64 (Bash)
Setup
```bash
sh ./updateSub.sh
```
Usage
```bash
./builds/SameWav.app wav0 wav1
```

## Output
- Error logs go to stdout
- Exit code is always 0
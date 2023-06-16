import os

CC      = "gcc"
LD      = "ld"

OUTPUT  = "vlink"

CFLAGS  = "-g -ffreestanding -fno-exceptions -m32 -I ./profan_zlib"
LDFLAGS = "-T link.ld"

OBJDIR  = "build"
SRCDIR  = "src"

DOOMSRC = [e for e in os.listdir(SRCDIR) if e.endswith(".c")]

def execute_command(cmd):
    print(cmd)
    rcode = os.system(cmd)
    if rcode == 0: return
    print(f"Command failed with exit code {rcode}")
    exit(rcode if rcode < 256 else 1)

def compile_file(src, dir = SRCDIR):
    obj = os.path.join(OBJDIR, f"{os.path.splitext(src)[0]}.o")
    cmd = f"{CC} -c {os.path.join(dir, src)} -o {obj} {CFLAGS}"
    execute_command(cmd)
    return obj

def link_files(entry, objs, output = OUTPUT):
    execute_command(f"{LD} {LDFLAGS} -o {output}.pe {entry} {' '.join(objs)} ")
    execute_command(f"objcopy -O binary {output}.pe {output}.bin")

def main():
    execute_command(f"mkdir -p {OBJDIR}")
    objs = [compile_file(src) for src in DOOMSRC]

    entry = compile_file("entry.c", ".")
    link_files(entry, objs)

    execute_command("rm *.pe")

if __name__ == "__main__":
    main()

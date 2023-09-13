# b.py content
import sys
import os
import signal
from miasm.analysis.binary import Container
from miasm.analysis.machine import Machine
from miasm.core.locationdb import LocationDB
import afl 


def main():
    #sys.stdin.seek(0) 
    fdesc = sys.stdin.buffer.read()
    loc_db = LocationDB()

    # The Container will provide a *bin_stream*, bytes source for the disasm engine
    # It will prodive a view from a PE or an ELF.
    cont = Container.from_string(fdesc, loc_db)

    # The Machine, instantiated with the detected architecture, will provide tools
    # (disassembler, etc.) to work with this architecture
    machine = Machine("x86_64")

    # Instantiate a disassembler engine, using the previous bin_stream and its
    # associated location DB. The assembly listing will use the binary symbols
    mdis = machine.dis_engine(cont.bin_stream, loc_db=cont.loc_db)

    # Run a recursive traversal disassembling from the entry point
    # (do not follow sub functions by default)
    addr = cont.entry_point
    asmcfg = mdis.dis_multiblock(addr)

    os._exit(0)

if __name__ == "__main__":
    signal.signal(signal.SIGCHLD, signal.SIG_IGN)  # this should have no effect on the forkserver
    while afl.loop():
        main()

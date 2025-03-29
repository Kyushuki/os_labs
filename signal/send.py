import os, sys, signal

arg = sys.argv

os.kill(int(arg[1]),signal.SIGUSR1)

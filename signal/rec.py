import os, sys, signal, time

mess = "kk"

def handler(signal, frame):
	global mess
	mess = "kuku"

signal.signal(signal.SIGUSR1, handler)

while True:
	print(os.getpid())
	print(mess)
	time.sleep(3)

#!/usr/bin/env python3
import datetime as dt
import subprocess

def main():

    fileName = dt.datetime.now().strftime("%Y%m%d_%H%M")
    print("{}.txt".format(fileName))
    logfile = open("Log/{}.txt".format(fileName), 'w')
    #subprocess.call(['./runtests'])
    output = subprocess.check_output(['./runtests'])
    logfile.write(output.decode("utf-8"))
    logfile.close()

if __name__ == "__main__":
    main()

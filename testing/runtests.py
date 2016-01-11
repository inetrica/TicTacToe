#!/usr/bin/env python3
import datetime as dt
import subprocess

'''
check if any of the tests failed by grepping the Logfile just created,
searching for the phrase "Failed~"
'''
def grepLog(fileName):
    output = subprocess.call(\
            ["grep", "Failed~", "Log/{}.txt".format(fileName)])
    #print(output)

def main():

    fileName = dt.datetime.now().strftime("%Y%m%d_%H%M")
    print("{}.txt".format(fileName))
    logfile = open("Log/{}.txt".format(fileName), 'w')
    #subprocess.call(['./runtests'])
    output = subprocess.check_output(['./runtests'])
    logfile.write(output.decode("utf-8"))
    logfile.close()

    grepLog(fileName)

if __name__ == "__main__":
    main()

import random
import os
import time
import argparse
import csv

def makePerf(n, obj):
    fdata_in = open("temp.in", "w")
    
    for i in range(1,n):
        name = obj.lower() + str(i)
        x0 = random.randint(1, 10)
        y0 = random.randint(1, 10)
        x1 = random.randint(1, 10)
        y1 = random.randint(1, 10)
        fdata_in.write(obj + " {} {} {} {} {}\n".format(
                        name, x0, y0, x1, y1
                    ))
    fdata_in.write("SAVE save.in\n")
    fdata_in.write("EXIT\n")
    fdata_in.close()

def makePerfSave():
    start = time.time()
    os.system("./shapes < temp.in" + " > /dev/null 2>&1")
    return time.time() - start

def makePerfLoad():
    start = time.time()
    os.system("./shapes < load.in" + " > /dev/null 2>&1")
    return time.time() - start

def makePerfs(n, obj):
    makePerf(n,obj)
    return [str(n), str(makePerfSave()), str(makePerfLoad())]

obj = "R"
max_pow = 7
powers = [10**i for i in range(1, max_pow)]

header = ['#Objects', 'Save (ms)', 'Load (ms)']

with open('results.csv', 'wb') as rfile:
    csv_writer = csv.writer(rfile)
    csv_writer.writerow(header)
    for i in powers:
        row = makePerfs(i, obj)
        csv_writer.writerow(row)

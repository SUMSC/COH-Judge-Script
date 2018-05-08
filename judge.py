import math
from math import *
from user.example import *


# Count how many lines in data
def dataCount():
    dataIn = open("data", "r")
    dataCount = len(dataIn.readlines())
    dataIn.close()
    return dataCount


def userRun(dataCount):
    # Redirect data input and user output
    import sys
    dataIn = open("data", "r")
    usrOut = open("out", "w")
    stdInBackup = sys.stdin
    stdOutBackup = sys.stdout
    sys.stdin = dataIn
    sys.stdout = usrOut

    # Run user program
    sol = Solution()
    for i in range(dataCount):
        sol.solve()

    # Restore stdin and stdout
    sys.stdin = stdInBackup
    sys.stdout = stdOutBackup

    # Close the files
    dataIn.close()
    usrOut.close()


def judge():
    # Open user output and answer
    stdAns = open("answer", "r")
    usrAns = open("out", "r")

    # Read in the answer and user output
    stdAnsList = stdAns.readlines()
    usrAnsList = usrAns.readlines()

    # Close the files
    stdAns.close()
    usrAns.close()

    # Compare the files
    corCount = 0
    for i in range(min(len(stdAnsList), len(usrAnsList))):
        if stdAnsList[i] == usrAnsList[i]:
            corCount += 1
        else:
            break

    return math.floor(100 * corCount / len(stdAnsList))


def main():
    userRun(dataCount())
    print("Pass Rate : " + str(judge()) + " % ")


if __name__ == "__main__":
    main()

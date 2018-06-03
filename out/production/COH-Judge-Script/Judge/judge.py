# coding:utf-8

import sys
from math import floor

# 需要判别的脚本所在目录，可修改：
sys.path.append("../Source")

# 导入脚本
from Solution import Solution

# 数据文件所在位置，可修改：
in_file = "../Data/in"
out_file = "../Data/out"
ans_file = "../Data/answer"

def dataCount():
    """
    Count how many lines in the in_file.
    """
    with open(in_file) as dataIn:
        dataCount = len(dataIn.readlines())
    return dataCount


def userRun(dataCount):
    """
    Redirect data input and user output.
    """
    with open(in_file) as dataIn, open(out_file, "w") as usrOut:
        stdOutBackup = sys.stdout
        sys.stdin = dataIn
        sys.stdout = usrOut

        # Run user program
        usrCode = Solution()
        for _ in range(dataCount):
            usrCode.solve()

        # Restore stdin and stdout
        sys.stdout = stdOutBackup


def judge():
    """
    Open user output and answer.
    """
    with open(ans_file) as stdAns, open(out_file) as usrAns:
        stdAnsList = stdAns.readlines()
        usrAnsList = usrAns.readlines()
    
    # Zip two list
    ansZip = zip(stdAnsList, usrAnsList)

    # Count Accept Lines
    corCount = 0
    for i in ansZip:
        if i[0] == i[1]:
            corCount += 1
        else:
            break

    return floor(100 * corCount / len(stdAnsList))


def main():
    userRun(dataCount())
    #print("fuck")
    print(type(judge()))
    print("Pass Rate : {} %".format(judge()))


if __name__ == "__main__":
    main()

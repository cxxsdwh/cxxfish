#!/Library/Frameworks/Python.framework/Versions/3.6/bin/python3

length=14
default=["0","0","0","0","0","0","0","0","0","0:0:0","0:0:0","0","0","0"]

f=open("/Users/chenxiaoxuan/Documents/MATLAB/4/11.txt",'r')
f2=open("/Users/chenxiaoxuan/Documents/MATLAB/4/12.txt",'w')


while True:
    line=f.readline()
    if not line:
        break
    li=line.split("\t")
    for j in range(length):
        if li[j]=="":
            li[j]=default[j]
    f2.write("\t".join(li))
f.close()
f2.close()

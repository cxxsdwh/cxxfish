#!/Library/Frameworks/Python.framework/Versions/3.6/bin/python3
with open("","r") as cg:
    pn=cg.read().split("\n");
f=open("/Users/chenxiaoxuan/Documents/MATLAB/4/11.txt",'r')
f2=open("/Users/chenxiaoxuan/Documents/MATLAB/4/12.txt",'w')

while True:
    line=f.readline()
    if not line:
        break
    li=line.split("\t")
    if li[1] in pn:
        f2.write(line)
f.close()
f2.close()


n=int(input())
for i in range(n,0,-1):
    for j in range(0,n-i,1):
        print(" ",end="")
    for k in range(1,2*i,1):
        if(k==1 or k==2*i-1 or i==n):
            print("*",end="")
        else:
            print(" ",end="")
    print()
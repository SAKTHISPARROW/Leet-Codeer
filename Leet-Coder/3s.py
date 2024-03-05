n=[-1,0,1,2,-1,-4]
res=[]
for i in range(0,len(n)-3):
    for j in range(i+1,len(n)-2):
        for k in range(j+1,len(n)-1):
            sum=n[i]+n[j]+n[k]
            if(sum==0):
                res.append([n[i],n[j],n[k]])
            else:
                continue
print(res)
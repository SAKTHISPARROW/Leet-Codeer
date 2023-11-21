def med(a,b):
    tot=len(a)+len(b)
    half=tot//2
    if len(b)<len(a):
        a,b=b,a
    l,r=0,len(a)-1
    while l<=r:
        i=(l+r)//2
        j=half-i-2
        aleft=a[i] if i>=0 else float("-infinity")
        aright=a[i+1] if (i+1)<len(a) else float("infinity")
        bleft=b[j] if j>=0 else float("-infinity")
        bright=b[j+1] if (j+1)<len(b) else float("infinity")
        if aleft<=bright and bleft<=aright:
            if tot%2:
                return (min(aright,bright))
            else:
                return ((max(aleft,bleft)+min(aright,bright))//2)                                                
        elif aleft>bright:
            r=i-1
        else:
            l=i+1

a=[1,2]
b=[3,4]
print(med(a,b))













#data stream median

def __init__(self):
        self.small,self.large=[],[]
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        heapq.heappush(small,-1*num)
        if(small and large and (-1*self.small[0])>self.large[0]):
            val=-1*heapq.headpop(self.small)
            heapq.headpush(self.large,val)
        if(len(small)>len(large)+1):
            val=-1*heapq.headpop(self.small)
            heapq.headpush(self.large,val)
        if(len(small)+1<len(large)):
            val=-1*heapq.headpop(self.large)
            heapq.headpush(self.small,val)
    }
    
    double findMedian() {
        if(len(small)>len(large)):
            return -1*self.small[0]
        if(len(large)>len(small)):
            return self.large[0]
        return (-1*self.small[0]+self.large[0])
    }
};
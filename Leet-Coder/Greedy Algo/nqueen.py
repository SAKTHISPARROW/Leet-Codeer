n=int(input("Enter the number of queens: "))
col=set()
posdiag=set()
negdiag=set()
res=[]
board=["."*n for i in range(n)]
def nqueen(row):
    if row==n:
        copy=["".join(i) for i in board]
        res.append(copy)
        return
    for i in range(n):
        if i in col or (row+i) in posdiag or (row-i) in negdiag:
            continue
        col.add(i)
        posdiag.add(row+i)
        negdiag.add(row-i)
        board[row][i]="Q"
        nqueen(row+1)
        col.remove(i)
        posdiag.remove(row+i)
        negdiag.remove(row-i)
        board[row][i]="."
nqueen(0)
print(res)



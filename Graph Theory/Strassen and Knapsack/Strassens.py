import numpy as np
import math

def sub_mat(n,A,q):
    if(q==0):
        return A[:n//2,:n//2]
    if(q==1):
        return A[:n//2,n//2:]
    if(q==2):
        return A[n//2:,:n//2]
    if(q==3):
        return A[n//2:,n//2:]
def strassen(n,A,B):
    if n==1:
        return A*B
    else:
        a,b,c,d = sub_mat(n,A,0), sub_mat(n,A,1), sub_mat(n,A,2), sub_mat(n,A,3)
        e,f,g,h = sub_mat(n,B,0), sub_mat(n,B,1), sub_mat(n,B,2), sub_mat(n,B,3)
        
        s1 = strassen(n//2,a, f - h)   
        s2 = strassen(n//2,a + b, h)         
        s3 = strassen(n//2,c + d, e)         
        s4 = strassen(n//2,d, g - e)         
        s5 = strassen(n//2,a + d, e + h)         
        s6 = strassen(n//2,b - d, g + h)   
        s7 = strassen(n//2,a - c, e + f)  
        # m is the quadrant of the final matrix that is formed.
        
        m1 = s5+s4-s2+s6
        m2 = s1+s2
        m3 = s3+s4
        m4 = s1+s5-s3-s7
        
        row1 = np.hstack((m1,m2))
        row2 = np.hstack((m3,m4))
        
        final = np.vstack((row1,row2))
        
        return final

print("Strassen's Multiplication of matrices.")
n = int(input("Enter the order of matrices:"))
while (int(math.log(n,2)) < math.log(n,2)):
    print("Invalid order\nEnter again \n")
    n = int(input("Enter the order of matrices:"))
print("Enter the matrices A and B rowise\n A:")
A, B =[],[]
for i in range(n):
    row = list(map(int,input().split()))
    A.append(row)
print("B:")
for i in range(n):
    row = list(map(int,input().split()))
    B.append(row)
a = np.matrix(A)
b = np.matrix(B)
print("Matrices are \nA:",a,"\nB:",b,"\n")

print("Final result :\n",strassen(n,a,b))
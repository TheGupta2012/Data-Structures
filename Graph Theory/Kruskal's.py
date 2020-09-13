#!/usr/bin/env python
# coding: utf-8

# # Kruskal's MST algorithm.
# 

# In[47]:


import numpy as np
import time as time
import math
import functools

try:
    graph = open("D:/III Semester/Algorithms/Assignment 5/GraphKruskal.txt",'r+')
except:
    print("Could not open the file. Please check name or the path.")

def comp(a,b):
    '''Custom compare function to sort list by weights'''
    return a[2]-b[2]

def kruskal(nodes,edges):
    component = {}
    for i in range(len(adj)):
        component[i] = i
    # the components of the vertices are individual 
    # we have not yet included any of them in the mst.
    print("Initial Component array ",component)
    LIST = []
    i = 0
    w = 0
    while(len(LIST)<nodes-1): 
        edge = edges[i]
        u = edge[0]
        v = edge[1]
        temp = component[v]
        if(component[u]!=component[v]):
            LIST.append(edge)
            w+=edge[2]
            for j in range(nodes):
                if(component[j]==temp):
                    component[j] = component[u]
        print("Updated components :",component)
        print("Current List :",LIST)
        time.sleep(0.6)
        i+=1
    return LIST,w
        
edge_list = []
for row in graph:
    if(len(row)==2):
        nodes = int(row[0])
    else:
        dat = row.split(",")
        u = int(dat[0])
        v = int(dat[1])
        w = int(dat[2])
        edge_list.append((u,v,w))

graph.seek(0)
print("Edge list is :")
for i in edge_list:
    print(i)
print("Total edges :",len(edge_list))


edge_list = sorted(edge_list,key = functools.cmp_to_key(comp) )
print("Sorted edge list :",edge_list)
print("Initiating Kruskal's Algorithm...")
time.sleep(1.5)

MST,weight = kruskal(nodes,edge_list)

print("Final edge list is of MST is :",MST)
print("Weight is :",weight)


# In[ ]:





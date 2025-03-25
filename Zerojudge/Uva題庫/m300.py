#m300. 12347 - Binary Search Tree
class Node:
    def __init__(self,val:int):
        self.val=val
        self.left=None
        self.right=None
    
class Tree:
    def __init__(self,val:int):
        self.root=Node(val)
    
    def insert(self,val:int,cur:Node):
        if val<cur.val:
            if cur.left==None:
                cur.left=Node(val)
            else:
                self.insert(val,cur.left)
        elif val>cur.val:
            if cur.right==None:
                cur.right=Node(val)
            else:
                self.insert(val,cur.right)

    def post_order(self,cur:Node):
        if cur:
            self.post_order(cur.left)
            self.post_order(cur.right)
            print(cur.val)

global tree
first=1

while 1:
    try:
        n=int(input())
        if first:
            tree=Tree(n)
            first=0
        else:
            tree.insert(n,tree.root)
    except:
        tree.post_order(tree.root)
        break
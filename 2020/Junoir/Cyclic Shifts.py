
t = str(input())
s = str(input())


s_list = list(s)

for i in range(len(s)):
    if(s in t or ''.join(s_list) in t):
        print("yes")
        exit()
    else:
        s_list.insert(0, s_list[-1])
        s_list.pop()

print("no")